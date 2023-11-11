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
#ifndef SRC_SWD_SWD_GPIO_H_
#define SRC_SWD_SWD_GPIO_H_

#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/SIO.h>
#include <hal/time_base.h>

// GPIO:
// Run = /Reset
#define PIN_RUN          6
#define PADS_GPIO_RUN    GPIO6
#define IO_RUN           GPIO6_CTRL

// SWDIO
#define PIN_SWDIO        3
#define PADS_GPIO_SWDIO  GPIO3
#define IO_SWDIO         GPIO3_CTRL

// SWCLK
#define PIN_SWCLK        2
#define PADS_GPIO_SWCLK  GPIO2
#define IO_SWCLK         GPIO2_CTRL

// SWDIR
#define PIN_SWDIR        1
#define PADS_GPIO_SWDIR  GPIO1
#define IO_SWDIR         GPIO1_CTRL

extern uint32_t swd_freq_delay;


void swd_gpio_init(void);

// RUN == /RESET
static inline void activate_Reset(void)
{
    SIO->GPIO_OUT_CLR = 1 << PIN_RUN;
}

static inline void activate_Run(void)
{
    SIO->GPIO_OUT_SET = 1 << PIN_RUN;
}

// SWCLK
static inline void set_SWCLK_High(void)
{
    SIO->GPIO_OUT_SET = 1 << PIN_SWCLK;
}

static inline void set_SWCLK_Low(void)
{
    SIO->GPIO_OUT_CLR = 1 << PIN_SWCLK;
}

// SWDIO
static inline void switch_SWDIO_to_Output(void)
{
    // SWDIO
    SIO->GPIO_OE_SET = 1ul << PIN_SWDIO;
    PADS_BANK0->PADS_GPIO_SWDIO = (PADS_BANK0_GPIO0_DRIVE_2mA << PADS_BANK0_GPIO0_DRIVE_OFFSET)
                                | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                                | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                                | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET)
                                ;
    // SWDIR
    SIO->GPIO_OUT_SET = 1 << PIN_SWDIR; // SWDIR = High
}

static inline void switch_SWDIO_to_Input(void)
{
    //SWDIO
    SIO->GPIO_OE_CLR = 1ul << PIN_SWDIO;
    PADS_BANK0->PADS_GPIO_SWDIO = (1 << PADS_BANK0_GPIO0_IE_OFFSET)  // input enabled
                                | (0 << PADS_BANK0_GPIO0_PUE_OFFSET) // pull up
                                | (0 << PADS_BANK0_GPIO0_PDE_OFFSET) // pull down
                                | (1 << PADS_BANK0_GPIO0_SLEWFAST_OFFSET)
                                ;
    //SWDIR
    SIO->GPIO_OUT_CLR = 1 << PIN_SWDIR;  // SWDIR = Low
}

static inline void set_SWDIO_High(void)
{
    SIO->GPIO_OUT_SET = 1 << PIN_SWDIO;
}

static inline void set_SWDIO_Low(void)
{
    SIO->GPIO_OUT_CLR = 1 << PIN_SWDIO;
}

static inline uint32_t read_SWDIO(void)
{
    if(0 == (SIO->GPIO_IN & (1 << PIN_SWDIO)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

static inline void quarter_clock_delay(void)
{
    delay_us(swd_freq_delay);

/*
    volatile uint32_t cnt = swd_freq_delay;
    while (cnt > 0) {
        cnt--;
    }
*/

    // __asm__ __volatile__ ("nop");

}

#endif /* SRC_SWD_SWD_GPIO_H_ */
