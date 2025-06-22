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
#include <hal/swd_gpio.h>
#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PADS_BANK0.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"

uint32_t swd_freq_delay;

void swd_gpio_init(void)
{
    RESETS->RESET = RESETS->RESET & ~0x00000020lu; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | 0x00000400; // make sure that SIO is powered on

    swd_freq_delay = 5;  // TODO make configurable
    // with for()nop :
    // 0 -> more than 5 MHz
    // 1 = 2,35 MHz

// Pin:  RUN
    // RUN = /RESET (Output, High)  High = not in Reset
    PADS_BANK0->PADS_GPIO_RUN = (PADS_BANK0_GPIO0_DRIVE_2MA << PADS_BANK0_GPIO0_DRIVE_OFFSET)
                              | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                              | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                              | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET);
    IO_BANK0->IO_RUN = 5;  // 5 = SIO
    SIO->GPIO_OUT_SET = 1ul << PIN_RUN; // Output High
    SIO->GPIO_OE_SET = 1ul << PIN_RUN;  // Set direction to output

// Pin:  SWDIO
    // SWDIO (Output, High) Target is supposed to have a 100k pull up. Having SWDIO on high when idle saves a tiny bit of power
    PADS_BANK0->PADS_GPIO_SWDIO = (PADS_BANK0_GPIO0_DRIVE_2MA << PADS_BANK0_GPIO0_DRIVE_OFFSET)
                                | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                                | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                                | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET)
                                ;
    IO_BANK0->IO_SWDIO = 5;  // 5 = SIO
    SIO->GPIO_OUT_SET = 1 << PIN_SWDIO;  // Output High
    SIO->GPIO_OE_SET = 1ul << PIN_SWDIO; // Set direction to output

// Pin:  SWCLK
    // SWCLK (Output, Low)
    PADS_BANK0->PADS_GPIO_SWCLK = (PADS_BANK0_GPIO0_DRIVE_2MA << PADS_BANK0_GPIO0_DRIVE_OFFSET)
                                | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                                | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                                | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET);
    IO_BANK0->IO_SWCLK = 5;  // 5 = SIO
    SIO->GPIO_OUT_CLR = 1ul << PIN_SWCLK; // Output Low
    SIO->GPIO_OE_SET = 1ul << PIN_SWCLK;  // Set direction to output

// Pin:  SWDIR
    // SWDIR (Output, High)
    PADS_BANK0->PADS_GPIO_SWDIR = (PADS_BANK0_GPIO0_DRIVE_2MA << PADS_BANK0_GPIO0_DRIVE_OFFSET)
                                | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                                | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                                | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET);
    IO_BANK0->IO_SWDIR = 5;  // 5 = SIO
    SIO->GPIO_OUT_SET = 1 << PIN_SWDIR;  // Output High High = Output; Low = Input
    SIO->GPIO_OE_SET = 1ul << PIN_SWDIR; // Set direction to output
}
