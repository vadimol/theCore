//! \file
//! \brief Module aggregates routines that are control execution flow of the MCU.
//!
#ifndef THE_CORE_EXECUTION_HPP_
#define THE_CORE_EXECUTION_HPP_

// Order matters
#include <stm32_device.hpp>
#include <arch/execution.hpp>

namespace ecl {

static inline void spin_wait(uint32_t ms)
{
    ecl::arch_spin_wait(ms);
}

} //namespace ecl
// TODO #213 add RTC support

#endif // THE_CORE_EXECUTION_HPP_
