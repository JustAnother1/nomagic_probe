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
#include "hal/hw/PPB.h"
#include "hal/time_base.h"

volatile uint32_t ms_since_boot;

void delay_us(uint32_t usec) {
    while (usec != 0) {
        volatile uint32_t cnt = 11;
        while (cnt > 0) {
            cnt--;
        }
        usec--;
    }
}

void SysTick_Handler(void) {
    ms_since_boot++;
}

void init_time(void)
{
    ms_since_boot = 0;
    PPB->SYST_CSR = 0x7;  // SysTick on
    PPB->SYST_RVR = 125000;  // reload value
}

uint32_t time_get_ms(void)
{
    return ms_since_boot;
}

