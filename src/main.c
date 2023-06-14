/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */
#include <hal/debug_uart.h>
#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/SIO.h>
#include <hal/hw/XOSC.h>
#include "cli/cli.h"
#include "time.h"
#include <stdint.h>
#include "tinyusb/usb.h"
#include "tinyusb/src/tusb.h"
#include "led.h"

/*
void error_state(void)
{
    for (;;)
    {
        // uint8_t data = 23;
        SIO->GPIO_OUT_SET = 1 << 25;
        // Delay
        delay_us(10 * 1000);
        SIO->GPIO_OUT_CLR = 1 << 25;
        // Delay
        delay_us(190 * 1000);
    }
}
*/

/* TODO Stack pointer
void main1(void)
{
}
*/

void main(void)
{
    init_time();
    led_init();
    debug_uart_initialize();
    cli_init();
    tusb_init(); // initialize tinyusb stack
    for (;;)
    {
        led_tick();
        cli_tick();
        usb_tick();
    }
}

