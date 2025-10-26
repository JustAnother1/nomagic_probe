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

#ifndef HAL_RESET_PIN_H_
#define HAL_RESET_PIN_H_

#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PADS_BANK0.h"
#include "hal/hw/SIO.h"

static inline void reset_pin_init(void)
{
    SIO->GPIO_OE_CLR = 1ul << 6;
    SIO->GPIO_OUT_CLR = 1ul << 6;
    PADS_BANK0->GPIO[6] = 0x00000030;
    IO_BANK0->GPIO22_CTRL = 5;  // 5 == SIO
    SIO->GPIO_OE_SET = 1ul << 6;
}

static inline void reset_pin_active(void)
{
    SIO->GPIO_OUT_SET = 1 << 6;
}

static inline void reset_pin_inactive(void)
{
    SIO->GPIO_OUT_CLR = 1 << 6;
}



#endif /* HAL_RESET_PIN_H_ */
