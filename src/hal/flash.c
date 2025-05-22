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

/*
 * parts of this code have been inspired by the RaspberryPi pico-bootrom-rp2040 code.
 * That code is licensed as BSD-3-Clause
 */

#include "hal/time_base.h"
#include "hal/debug_uart.h"
#include "flash.h"
#include "cfg/cli_cfg.h"
#include "cfg/cli_cfg.h"
#include <string.h>
#include "probe_api/debug_log.h"


#ifdef BOOT_ROM_ENABLED

#include "hal/boot_rom.h"
#include "hal/hw/XIP_SSI.h"

/*
 * XIP Address alias:
 0x10... XIP access, cacheable, allocating - Normal cache operation
 0x11... XIP access, cacheable, non-allocating - Check for hit, don’t update cache on miss
 0x12... XIP access, non-cacheable, allocating - Don’t check for hit, always update cache
 0x13... XIP access, non-cacheable, non-allocating - Bypass cache completely
 0x15... Use XIP cache as SRAM bank, mirrored across entire segment
*/


/*
A typical call sequence for erasing a flash sector from user code would be:
• _connect_internal_flash
• _flash_exit_xip


• _flash_range_erase(addr, 1 << 12, 1 << 16, 0xd8)
• _flash_flush_cache
*/

static boot_rom_flash_functions* flash_funcs = NULL;

#else

#include "qspi.h"

#endif


void flash_init(void)
{
#ifdef BOOT_ROM_ENABLED
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        while(0 != (1& XIP_SSI->SR))
        {
            ;
        }
        flash_funcs->_connect_internal_flash();
        flash_funcs->_flash_exit_xip();
    }
    else
    {
        debug_line("Flash: get boot ROM functions failed !");
    }
#else
    qspi_init();
#endif
}


void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
#ifdef BOOT_ROM_ENABLED
    if(NULL != flash_funcs)
    {
        // data sheet says:
        // [start_address] must be aligned to a 256-byte boundary, and [length] must be a multiple of 256
        if((0 == (start_address & 0xff)) && (0 == (length & 0xff)))
        {
            // debug_line("Flash: writing 256 bytes @0x%08lx !", start_address);
            while(0 != (1& XIP_SSI->SR))
            {
                yield();
            }
            flash_funcs->flash_range_program(start_address, data, length);
            yield();
            flash_funcs->_flash_flush_cache();
            yield();
        }
        else
        {
            debug_line("Flash: parameters invalid !");
            if(0 != (start_address && 0xff))
            {
                debug_line("Flash: start address(0x%08lx)[0x%08x] must be aligned to 256 !", start_address, (start_address && 0xff));
            }
            if(0 != (length & 0xff))
            {
                debug_line("Flash: length must be multiple of 256 !");
            }
        }
    }
    else
    {
        debug_line("Flash: get boot ROM functions failed !");
    }
#else

    if(0 == (start_address & 0xff))
    {
        uint32_t goal = start_address + length;
        while(start_address < goal)
        {
            qspi_page_program_256(start_address, data);
            start_address += 256;
            data += 256;
        }
    }
    else
    {
        debug_line("Flash: start address(0x%08lx)[0x%08x] must be aligned to 256 !", start_address, (start_address && 0xff));
    }

    /*  TODO
    if(256 < length + (start_address & 0xff))
    {
        if(0 != (start_address & 0xff))
        {
            uint32_t part_length = 256 - (start_address & 0xff);
            qspi_page_program(start_address, data, part_length);
            length = length - part_length;
            yield();
        }
        while(0 < length)
        {
            uint32_t part_length = 256;
            if(length < part_length)
            {
                part_length = length;
            }
            qspi_page_program(start_address, data, part_length);
            length = length - part_length;
            yield();
        }
    }
    else
    {
        qspi_page_program(start_address, data, length);
    }
    */


#endif
}


//! erases one page (smallest erase possible) that is 4096 bytes.
void flash_erase_page(uint32_t number)
{
#ifdef BOOT_ROM_ENABLED
    if(NULL != flash_funcs)
    {
        while(0 != (1& XIP_SSI->SR))
        {
            yield();
        }
        flash_funcs->_flash_range_erase(number*4096, 4096, 0, 0);
        yield();
        flash_funcs->_flash_flush_cache();
        yield();
    }
    else
    {
        debug_line("Flash: get boot ROM functions failed !");
    }
#else
    /// erase (set to 0xff) a sector (4096 Bytes)
    qspi_erase_sector(number);
#endif
}

void flash_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if((0 == length) || (NULL == data))
    {
        return;
    }
#ifdef BOOT_ROM_ENABLED
    if(NULL == flash_funcs)
    {
        debug_line("Flash: get boot ROM functions failed !");
    }
    // XIP ON
    while(0 != (1& XIP_SSI->SR))
    {
        yield();
    }
    flash_funcs->_flash_flush_cache();
    yield();
    flash_funcs->_flash_enter_cmd_xip();
    yield();

    memcpy(data, (void*)(0x13000000 + (0xffffff & start_address)), length);

    // XIP off
    while(0 != (1& XIP_SSI->SR))
    {
        yield();
    }
    flash_funcs->_connect_internal_flash();
    yield();
    flash_funcs->_flash_exit_xip();
    yield();

#else
    // command read data = 0x03
    // falling edge on /CS - write 0x03 - write 24bits(3 bytes) address - read as many bytes as needed - rising edge of /CS

    // fast read quad output = 0x6b
    // falling edge on /CS - write 0x6b - write 24bits(3 bytes) address - read and ignore 8 bits - read as many bytes as needed - rising edge of /CS
    qspi_read(start_address, data, length);
#endif
}


bool flash_report(uint32_t loop)
{
    switch(loop)
    {
#ifdef BOOT_ROM_ENABLED
    case 0: cli_line("using BOOT ROM functions !"); break;
    case 1:
        if(NULL == flash_funcs)
        {
            cli_line("ERROR: failed to read BOOT ROM functions !"); break;
        }
        else
        {
            cli_line("BOOT ROM functions have been discovered !"); break;
        }
        break;
#else

#endif
        default : return true;
    }
    return false;
}

