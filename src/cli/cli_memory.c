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

#include "cli_memory.h"
#include "cli.h"
#include "cli_cfg.h"

#include <stdlib.h>


static uint32_t addr;
static uint32_t loops = 0;

bool cmd_memory_display(void)
{
    if(0 == loops)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        loops = numBytes/4;
    }
    else
    {
        loops--;
    }
    uint32_t val = *((uint32_t*)addr);
    debug_msg("Address 0x%08lx : 0x%08lx (%ld)\r\n", addr, val, val);
    addr = addr + 4;
    if(0 == loops)
    {
        return true; // we are done
    }
    else
    {
        return false; // we need to do more
    }
}





