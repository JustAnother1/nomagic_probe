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

#include <stddef.h>

#include "hal/hw/PPB.h"
#include "hal/time_base.h"
#include "probe_api/time.h"

// comparing against < 0xffffffff is always true
// -> we want to avoid 0xffffffff as end time of timeout
#define MAX_SAFE_COUNT        0xfffffff0

volatile uint32_t ms_since_boot;

void delay_us(uint32_t usec)
{
    uint32_t loops = usec;
    while(loops != 0)
    {
        volatile uint32_t cnt = 11;
        while (cnt > 0)
        {
            cnt--;
        }
        loops--;
    }
}

void SysTick_Handler(void)
{
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

void start_timeout(timeout_typ* to, const uint32_t time_ms)
{
    if(NULL != to)
    {
        uint32_t start_time = time_get_ms();
        to->timeout_time = start_time + time_ms;
        if(to->timeout_time > MAX_SAFE_COUNT)
        {
            // an end time of 0xffffffff would not work as all values are always < 0xffffffff
            uint32_t remainder = 100 - (MAX_SAFE_COUNT - start_time);
            to->timeout_time = 2 + remainder;
            to->wait_for_wrap_around = true;
        }
        else if(to->timeout_time < start_time)
        {
            // wrap around
            to->wait_for_wrap_around = true;
        }
        else
        {
            to->wait_for_wrap_around = false;
        }
    }
    // else there is nothing we can do,...
}

bool timeout_expired(timeout_typ* to)
{
    if(NULL != to)
    {
        // check timeout
        uint32_t cur_time = time_get_ms();
        if(true == to->wait_for_wrap_around)
        {
            if(10 > cur_time)
            {
                // wrap around happened
                to->wait_for_wrap_around = false;
            }
            // else continue waiting
            return false;
        }
        else
        {
            if(cur_time > to->timeout_time)
            {
                // Timeout !!!
                return true;
            }
            else
            {
                // not a timeout, yet.
                return false;
            }
        }
    }
    else
    {
        // if we do not get data then that timeout expired!
        return true;
    }
}
