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
#ifndef HAL_TIME_BASE_H_
#define HAL_TIME_BASE_H_

#include <stdint.h>
#include <hal/hw/TIMER.h>

void delay_us(uint32_t usec);

void init_time(void);
uint32_t time_get_ms(void);

static inline uint32_t time_us_32(void)
{
    return TIMER->TIMERAWL;
}

#endif /* HAL_TIME_BASE_H_ */
