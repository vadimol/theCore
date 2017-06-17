// Header contains target-specific interfaces.

#ifndef EXAMPLE_LED_TARGET_HPP_
#define EXAMPLE_LED_TARGET_HPP_

#include <aux/usart_bus.hpp>
#include <platform/gpio_device.hpp>
#include <stm32f4xx_gpio.h>


// Initializes pins
void gpio_init();

// User button
using led_green = ecl::gpio<ecl::gpio_port::d, ecl::gpio_num::pin12>;
using led_orange = ecl::gpio<ecl::gpio_port::d, ecl::gpio_num::pin13>;
using led_red = ecl::gpio<ecl::gpio_port::d, ecl::gpio_num::pin14>;
using led_blue = ecl::gpio<ecl::gpio_port::d, ecl::gpio_num::pin15>;

#endif // EXAMPLE_LED_TARGET_HPP_