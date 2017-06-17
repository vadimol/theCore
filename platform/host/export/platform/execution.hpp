//! \file
//! \brief Module aggregates routines that are control execution flow on the host platform.
//!
#ifndef THE_CORE_HOST_PLATFORM_EXECUTION_HPP_
#define THE_CORE_HOST_PLATFORM_EXECUTION_HPP_

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

namespace ecl
{

//! \brief Aborts execution of currently running code. Never return.
static inline void abort()
{
    abort();
}

//! \brief Gets core clock speed.
//! \return Current clock speed. Unreliable on host platform.
static inline uint64_t clk_spd()
{
    return 1000; // Pretend that there is a 1 kHz clock.
}

//! \brief Gets current clock count.
//! \return Current clock count.
static inline uint64_t clk()
{
    // Host platform is unreliable in terms of clock speed, so just return
    // seconds since epoch here. See also ecl::clk_spd()
    return time(NULL) * 1000;
}

//! \brief Does busy waiting for specified amount of time.
//! \param[in] ms The time in milliseconds to wait
static inline void spin_wait(uint32_t ms)
{
    // Host platform is unreliable in terms of clock speed.
    // This is a roughly approximation.
    clock_t start = clock() / (CLOCKS_PER_SEC / 1000);

    while ((uint32_t)(clock() / (CLOCKS_PER_SEC / 1000) - start) < ms) {}

    return;
}

} // namespace ecl

#endif // THE_CORE_HOST_PLATFORM_EXECUTION_HPP_
