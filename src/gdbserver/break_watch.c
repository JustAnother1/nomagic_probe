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
#include <string.h>
#include "break_watch.h"
#include "probe_api/debug_log.h"
#include "probe_api/gdb_packets.h"

void handle_lowercase_zed(char* received, uint32_t length)
{
    // received[0] = 'z'
    // received[1] = 0..4
    // received[2] = ','
    // received[3] = address
    if(4 > length)
    {
        send_unknown_command_reply();
        return;
    }
    // else:
    char* split_pos = strchr(&(received[3]), ',');
    if(NULL == split_pos)
    {
        // no kind provided
    }
    switch(received[1])
    {
    case '0': // software breakpoint
    case '1': // hardware breakpoint
    case '2': // watchpoint (write address)
    case '3': // watchpoint (read address)
    case '4': // watchpoint (access address)
    default:
        debug_error("ERROR: gdb %s command not implemented !", received);
        send_unknown_command_reply();
        break;
    }
}

void handle_upercase_zed(char* received, uint32_t length)
{
    // received[0] = 'Z'
    if(1 == length)
    {
        send_unknown_command_reply();
        return;
    }
    // else:
    switch(received[1])
    {
    case '0': // software breakpoint
    case '1': // hardware breakpoint
    case '2': // watchpoint (write address)
    case '3': // watchpoint (read address)
    case '4': // watchpoint (access address)
    default:
        debug_error("ERROR: gdb %s command not implemented !", received);
        send_unknown_command_reply();
        break;
    }
}
