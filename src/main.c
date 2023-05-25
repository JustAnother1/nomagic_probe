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

void error_state(void)
{
    for (;;) {
        // uint8_t data = 23;
        SIO->GPIO_OUT_SET = 1 << 25;
        // Delay
        delay_us(10 * 1000);
        SIO->GPIO_OUT_CLR = 1 << 25;
        // Delay
        delay_us(190 * 1000);
    }
}

/* TODO Stack pointer
void main1(void) {
    RESETS->RESET = RESETS->RESET & ~0x00000020; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | 0x00000400; // make sure that SIO is powered on
    SIO->GPIO_OE_CLR = 1ul << 25;
    SIO->GPIO_OUT_CLR = 1ul << 25;
    PADS_BANK0->GPIO25 = 0x00000030;
    IO_BANK0->GPIO25_CTRL = 5;
    SIO->GPIO_OE_SET = 1ul << 25;
    init_time();

    // console_uart_initialize();
    for (;;) {
        // uint8_t data = 23;
        SIO->GPIO_OUT_SET = 1 << 25;
        // Delay
        delay_us((10 / 1 * 60) * 1000);
        SIO->GPIO_OUT_CLR = 1 << 25;
        // Delay
        delay_us((10 / 1 * (100 - 60)) * 1000);
        // console_uart_send_bytes(&data, 1);
    }
}
*/

void main(void) {
    RESETS->RESET = RESETS->RESET & ~0x00000020lu; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | 0x00000400; // make sure that SIO is powered on
    SIO->GPIO_OE_CLR = 1ul << 25;
    SIO->GPIO_OUT_CLR = 1ul << 25;
    PADS_BANK0->GPIO25 = 0x00000030;
    IO_BANK0->GPIO25_CTRL = 5;
    SIO->GPIO_OE_SET = 1ul << 25;
    init_time();
    debug_uart_initialize();
    cli_init();
    usb_init();
    for (;;) {
        cli_tick();
        usb_tick();
    }
}

