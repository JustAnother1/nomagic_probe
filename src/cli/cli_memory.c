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

bool cmd_memory_dump(void)
{
    uint32_t i = 0;
    uint32_t val = 0;
    uint32_t pos = 0;
    uint32_t bytes_to_dump = 16;

    if(0 == loops)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        loops = numBytes;
    }

    if(loops < bytes_to_dump)
    {
        bytes_to_dump = loops;
        loops = 0;
    }
    else
    {
        loops = loops - bytes_to_dump;
    }
    debug_msg("Address 0x%08lx :", addr);

    for(i = 0; i < bytes_to_dump; i++)
    {
        if(0 == pos)
        {
            val = *((uint32_t*)addr);
            addr = addr + 4;
        }
        switch(pos)
        {
        case 0: debug_msg(" %02lx",  val     & 0xff); break;
        case 1: debug_msg(" %02lx", (val>>8) & 0xff); break;
        case 2: debug_msg(" %02lx", (val>>16)& 0xff); break;
        case 3: debug_msg(" %02lx", (val>>24)& 0xff); break;
        }
        pos++;
        if(pos > 3)
        {
            pos = 0;
        }
    }
    debug_msg("\r\n");

    if(0 == loops)
    {
        return true; // we are done
    }
    else
    {
        return false; // we need to do more
    }
}

/*
 * XIP Address alias:
 0x10... XIP access, cacheable, allocating - Normal cache operation
 0x11... XIP access, cacheable, non-allocating - Check for hit, don’t update cache on miss
 0x12... XIP access, non-cacheable, allocating - Don’t check for hit, always update cache
 0x13... XIP access, non-cacheable, non-allocating - Bypass cache completely
 0x15... Use XIP cache as SRAM bank, mirrored across entire segment
*/



