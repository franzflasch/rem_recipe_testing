#include <stdint.h>
#include <OMM_machine_common.h>
#include <gpio_common.h>
#include <foo.h>
#include <bar.h>
#include <stdio.h>


int __attribute__((weak)) main (void)
{
	uint8_t gpio_val = 0;
	gpio_controller_t *gpio;

	OMM_machine_t *machine = machine_setup();

	gpio = OMM_get_pdev_by_name(machine, "gpio_0");

	foo();
	bar();

    while (1)
    {
    	gpio_val ^= 1 << 0;
    	GPIO_set(gpio, 0, gpio_val);
    	GPIO_set(gpio, 1, !gpio_val);
    	OMM_busy_delay(1500);
    }
}
