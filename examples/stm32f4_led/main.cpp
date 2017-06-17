#include "target.hpp"

#include <ecl/iostream.hpp>
#include <common/execution.hpp>

using ecl::cout;
using ecl::endl;


extern "C"
void board_init()
{
    gpio_init();
}


int main()
{
    ecl::cout << "Hello, Embedded Led World!" << ecl::endl;

    while (1) {
        ecl::spin_wait(500);
        led_green::toggle();
    }
}