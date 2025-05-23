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
#if (defined FEAT_DEBUG_UART)
#include "hal/debug_uart.h"
#endif

// comparing against < 0xffffffff is always true
// -> we want to avoid 0xffffffff as end time of timeout
#define MAX_SAFE_COUNT        0xfffffff0

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

void yield(void)
{
    // TODO move to main,c
    // make this the normal loop
    // have each function/thread have a busy/not enabled flag
    // once called from yield first is to check the flag and return immidiatedly
    // if yield called from a task then set this task to not execute
    // this way if one task is blocked all other tasks will get called.
#if (defined FEAT_DEBUG_UART)
    debug_uart_tick(); // to keep the UART alive if this takes some time
#endif
}
