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
#include "cli_sys.h"
#include "time.h"
#include "hal/debug_uart.h"
#include "cli.h"

bool cmd_time(void)
{
    uint32_t now = time_get_ms();
    debug_line("\r\ntime since boot up : %d ms", now);
    return true;  // we are done
}

bool cmd_parameter_raw(void)
{
    uint32_t i = 0;
    uint8_t* c = cli_get_parameter(i);
    while(c != NULL)
    {
        debug_msg("\r\nParameter %d :", i);
        while(*c != 0)
        {
            debug_msg(" %02x", *c);
            c++;
        }
        debug_msg("\r\n");
        i++;
        c = cli_get_parameter(i);
    }
    debug_line("\r\nDone!");
    return true;  // we are done
}


