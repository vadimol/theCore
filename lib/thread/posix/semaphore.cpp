#include <ecl/thread/semaphore.hpp>

ecl::semaphore::semaphore()
        :m_mutex{}
        ,m_cond{}
        ,m_cnt{0}
{
}

void ecl::semaphore::signal()
{
    std::unique_lock <std::mutex> lock(m_mutex);
    m_cnt++;
    lock.unlock();
    m_cond.notify_one();
}

bool ecl::semaphore::try_wait()
{
    std::unique_lock <std::mutex> lock(m_mutex);

    if (m_cnt) {
        m_cnt--;
        return true;
    }

    return false;
}

void ecl::semaphore::wait()
{
    std::unique_lock <std::mutex> lock(m_mutex);
    m_cond.wait(lock, [&] { return m_cnt.load(); });
    m_cnt--;
}

//------------------------------------------------------------------------------

ecl::binary_semaphore::binary_semaphore()
        :m_mutex{}
        ,m_cond{}
        ,m_flag{false}
{
}

void ecl::binary_semaphore::signal()
{
    std::unique_lock <std::mutex> lock(m_mutex);
    m_flag = true;
    lock.unlock();
    m_cond.notify_one();
}

bool ecl::binary_semaphore::try_wait()
{
    std::unique_lock <std::mutex> lock(m_mutex);

    auto rc = m_flag ? true : false;
    m_flag = false;
    return rc;
}

void ecl::binary_semaphore::wait()
{
    std::unique_lock <std::mutex> lock(m_mutex);
    m_cond.wait(lock, [&] { return m_flag.load(); });
    m_flag = false;
}
