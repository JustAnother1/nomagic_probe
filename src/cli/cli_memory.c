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
#include "hal/flash.h"
#include "hal/boot_rom.h"
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

bool cmd_flash_memory_erase(void)
{
    uint8_t* addr_str = cli_get_parameter(0);
    uint32_t address = (uint32_t)atoi((const char*)addr_str);
    flash_erase_page(address);
    return true; // we are done
}

bool cmd_flash_memory_write(void)
{
    uint32_t i;
    uint8_t data[256];
    uint8_t* addr_str = cli_get_parameter(0);
    uint8_t* numBytes_str = cli_get_parameter(1);
    uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
    uint32_t address = (uint32_t)atoi((const char*)addr_str);

    // limit length
    if(numBytes > 256)
    {
        numBytes = 256;
    }

    // initialize data
    for(i = 0; i < numBytes; i++)
    {
        data[i] = (uint8_t)(i & 0xff);
    }

    debug_line("writing to address: 0x%lx", address);
    debug_line("writing %lu bytes", numBytes);
    // write data
    flash_write_block(address, data, numBytes);

    return true; // we are done
}

bool cmd_flash_disable_XIP(void)
{
    boot_rom_flash_functions* flash_funcs = NULL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_connect_internal_flash();
        flash_funcs->_flash_exit_xip();
    }
    return true; // we are done
}

bool cmd_flash_enable_XIP(void)
{
    boot_rom_flash_functions* flash_funcs = NULL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_flash_flush_cache();
        flash_funcs->_flash_enter_cmd_xip();
    }
    return true; // we are done
}
