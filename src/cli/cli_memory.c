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
#include <hal/hw/TIMER.h>
#include <stdlib.h>


static uint32_t addr;
static uint32_t num_loops = 0;

bool cmd_memory_display(uint32_t loop)
{
    if(0 == loop)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        num_loops = numBytes/4;
    }
    else
    {
        // max 16 MB (0x1 00 00 00)  starting at 0x 10 00 00 00
        if((addr > 0xfffffff) && (addr < 0x11000000))
        {
            // QSPI Flash
            uint32_t i;
            uint32_t line[4];
            flash_read(addr & 0xffffff, (uint8_t*)line, 16);
            for(i = 0; i < 4; i++)
            {
                debug_msg("Address 0x%08lx : 0x%08lx (%ld)\r\n", addr, line[i], line[i]);
                addr = addr + 4;
                num_loops--;
                if(0 == num_loops)
                {
                    break;
                }
            }
        }
        else
        {
            uint32_t val;
            uint32_t i;
            for(i = 0; i < 4; i++)
            {
                if(0 == num_loops)
                {
                    break;
                }
                val = *((uint32_t*)addr);
                debug_msg("Address 0x%08lx : 0x%08lx (%ld)\r\n", addr, val, val);
                addr = addr + 4;
                num_loops--;
            }
        }
        if(0 == num_loops)
        {
            return true; // we are done
        }
    }
    return false; // we need to do more
}

bool cmd_memory_dump(uint32_t loop)
{
    uint8_t line_buffer[16];
    uint8_t* line;
    uint32_t i;

    if(0 == loop)
    {
        // first call
        uint8_t* addr_str = cli_get_parameter(0);
        uint8_t* numBytes_str = cli_get_parameter(1);
        uint32_t numBytes = (uint32_t)atoi((const char*)numBytes_str);
        addr = (uint32_t)atoi((const char*)addr_str);
        num_loops = numBytes;
    }
    else
    {
        if((addr > 0xfffffff) && (addr < 0x20000000))
        {
            // QSPI Flash
            flash_read(addr & 0xffffff, line_buffer, 16);
            line = line_buffer;
        }
        else
        {
            line = ((uint8_t*)addr);
        }

        debug_msg("Address 0x%08lx :", addr);
        for(i = 0; i < 16; i++)
        {
            if(0 == num_loops)
            {
                break;
            }
            debug_msg(" %02x", line[i]);
            num_loops --;
            addr++;
        }
    }

    debug_msg("\r\n");

    if(0 == num_loops)
    {
        return true; // we are done
    }
    else
    {
        return false; // we need to do more
    }
}

bool cmd_flash_memory_erase(uint32_t loop)
{
    uint32_t diff;
    (void) loop;
    uint8_t* addr_str = cli_get_parameter(0);
    uint32_t address = (uint32_t)atoi((const char*)addr_str);
    diff = TIMER->TIMERAWL;
    flash_erase_page(address);
    diff = TIMER->TIMERAWL - diff;
    debug_line("operation took %lu µs", diff);
    return true; // we are done
}

bool cmd_flash_memory_write(uint32_t loop)
{
    (void) loop;
    uint32_t i;
    uint32_t diff;
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
    diff = TIMER->TIMERAWL;
    flash_write_block(address, data, numBytes);
    diff = TIMER->TIMERAWL - diff;
    debug_line("operation took %lu µs", diff);
    return true; // we are done
}

#ifdef BOOT_ROM_ENABLED
bool cmd_flash_disable_XIP(uint32_t loop)
{
    uint32_t diff;
    (void) loop;
    boot_rom_flash_functions* flash_funcs = NULL;
    diff = TIMER->TIMERAWL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_connect_internal_flash();
        flash_funcs->_flash_exit_xip();
        diff = TIMER->TIMERAWL - diff;
        debug_line("operation took %lu µs", diff);
    }
    return true; // we are done
}

bool cmd_flash_enable_XIP(uint32_t loop)
{
    uint32_t diff;
    (void)loop;
    boot_rom_flash_functions* flash_funcs = NULL;
    diff = TIMER->TIMERAWL;
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        flash_funcs->_flash_flush_cache();
        flash_funcs->_flash_enter_cmd_xip();
        diff = TIMER->TIMERAWL - diff;
        debug_line("operation took %lu µs", diff);
    }
    return true; // we are done
}
#endif
