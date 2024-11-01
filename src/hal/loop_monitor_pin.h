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

#ifndef HAL_LOOP_MONITOR_PIN_H_
#define HAL_LOOP_MONITOR_PIN_H_

#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PADS_BANK0.h"
#include "hal/hw/SIO.h"

static inline void loop_monitor_pin_init(void)
{
    SIO->GPIO_OE_CLR = 1ul << 22;
    SIO->GPIO_OUT_CLR = 1ul << 22;
    PADS_BANK0->GPIO22 = 0x00000030;
    IO_BANK0->GPIO22_CTRL = 5;  // 5 == SIO
    SIO->GPIO_OE_SET = 1ul << 22;
}

static inline void loop_monitor_pin_toggle(void)
{
    SIO->GPIO_OUT_XOR = 1 << 22;
}


#endif /* HAL_LOOP_MONITOR_PIN_H_ */
