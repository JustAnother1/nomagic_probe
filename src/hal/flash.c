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

#include <hal/time_base.h>
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

void flash_init(void)
{
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
        debug_line("Flash: get boot rom functions failed !");
    }
}
#else

#include "qspi.h"

#define STATUS_REGISTER_BUSY    1

static void read_status_register(void);
static void command_write_enable(void);
static void read_data(uint32_t start_address, uint8_t* data, uint32_t length);
static void page_program(uint32_t start_address, uint8_t* data, uint32_t length);
/// erase (set to 0xff) a sector (4096 Bytes)
static void sector_erase(uint32_t number);

// QSPI Flash:
static uint32_t status_register;
static uint8_t tx_buf[4];
static uint8_t rx_buf[4];

void flash_init(void)
{
    qspi_init();
    // make sure we are not in XIP mode (Continuous Read Mode)
    qspi_reset_flash();
    status_register = STATUS_REGISTER_BUSY;  // worst case assumption it is busy
}


static void read_status_register(void)
{
    status_register = 0;
    // command Read Status Register = 0x05
    // normal SPI mode
    // /CS falling edge - write 0x05 - read 8bit - rising edge on /CS
    tx_buf[0] = 0x05;
    tx_buf[1] = 0x23; // TODO for test only

    rx_buf[0] = 0;
    rx_buf[1] = 0;
    rx_buf[2] = 0;
    rx_buf[3] = 0;

    qspi_transfere_no_cmd(tx_buf, rx_buf, 2);
    status_register = rx_buf[1];
}


static void command_write_enable(void)
{
    while(0 != (0x01 & status_register)) // Flash might be busy
    {
        read_status_register();
    }
    // command write enable = 0x06
    status_register = STATUS_REGISTER_BUSY;
}


static void read_data(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if((0 == length) || (NULL == data))
    {
        return;
    }
    while(0 != (0x01 & status_register)) // Flash might be busy
    {
        read_status_register();
    }
    // command read data = 0x03
    // falling edge on /CS - write 0x03 - write 24bits(3 bytes) address - read as many bytes as needed - rising edge of /CS

    // fast read quad output = 0x6b
    // falling edge on /CS - write 0x6b - write 24bits(3 bytes) address - read and ignore 8 bits - read as many bytes as needed - rising edge of /CS
    (void)start_address; // TODO

    status_register = STATUS_REGISTER_BUSY;
}


/// write up to 256 Bytes
static void page_program(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if((0 == length) || (NULL == data))
    {
        return;
    }
    while(0 != (0x01 & status_register)) // Flash might be busy
    {
        read_status_register();
    }
    command_write_enable();
    // command page program = 0x02
    // falling edge on /CS - write 0x02 - write 24bits(3 bytes) address - write up to 256 bytes as needed - rising edge of /CS

    // quad page program = 0x32

    (void)start_address; // TODO

    status_register = STATUS_REGISTER_BUSY;
}


/// erase (set to 0xff) a sector (4096 Bytes)
static void sector_erase(uint32_t number)
{
    uint32_t address = number * 4096;
    while(0 != (0x01 & status_register)) // Flash might be busy
    {
        read_status_register();
    }
    command_write_enable();
    // command sector erase = 0x20
    // falling edge on /CS - write 0x20 - write 24bits(3 bytes) address - rising edge of /CS
    tx_buf[0] = 0x20;
    tx_buf[1] = (address & 0xff);
    tx_buf[2] = ((address >>8) & 0xff);
    tx_buf[3] = ((address >>16) & 0xff);
    rx_buf[0] = 0;
    rx_buf[1] = 0;
    rx_buf[2] = 0;
    rx_buf[3] = 0;
    qspi_transfere(tx_buf, rx_buf, 4);

    status_register = STATUS_REGISTER_BUSY;
}
#endif


void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
#ifdef BOOT_ROM_ENABLED
    if(NULL == flash_funcs)
    {
        flash_funcs = boot_rom_get_flash_functions();
    }
    if(NULL != flash_funcs)
    {
        // data sheet says:
        // [start_address] must be aligned to a 256-byte boundary, and [length] must be a multiple of 256
        if((0 == (start_address & 0xff)) && (0 == (length & 0xff)))
        {
            // debug_line("Flash: writing 256 bytes @0x%08lx !", start_address);
            while(0 != (1& XIP_SSI->SR))
            {
                ;
            }
            flash_funcs->flash_range_program(start_address, data, length);
            flash_funcs->_flash_flush_cache();
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
        debug_line("Flash: get boot rom functions failed !");
    }
#else
    if(256 < length + (start_address & 0xff))
    {
        if(0 != (start_address & 0xff))
        {
            uint32_t part_length = 256 - (start_address & 0xff);
            page_program(start_address, data, part_length);
            length = length - part_length;
        }
        while(0 < length)
        {
            uint32_t part_length = 256;
            if(length < part_length)
            {
                part_length = length;
            }
            page_program(start_address, data, part_length);
            length = length - part_length;
        }
    }
    else
    {
        page_program(start_address, data, length);
    }
#endif
}


//! erases one page (smallest erase possible) that is 4096 bytes.
void flash_erase_page(uint32_t number)
{
#ifdef BOOT_ROM_ENABLED
    if(NULL == flash_funcs)
    {
        flash_funcs = boot_rom_get_flash_functions();
    }
    if(NULL != flash_funcs)
    {
        while(0 != (1& XIP_SSI->SR))
        {
            ;
        }
        flash_funcs->_flash_range_erase(number*4096, 4096, 0, 0);
        flash_funcs->_flash_flush_cache();
    }
    else
    {
        debug_line("Flash: get boot rom functions failed !");
    }
#else
    sector_erase(number);
#endif
}

void flash_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
#ifdef BOOT_ROM_ENABLED
    if(NULL == flash_funcs)
    {
        flash_funcs = boot_rom_get_flash_functions();
    }
    // XIP ON
    if(NULL != flash_funcs)
    {
        while(0 != (1& XIP_SSI->SR))
        {
            ;
        }
        flash_funcs->_flash_flush_cache();
        flash_funcs->_flash_enter_cmd_xip();
    }
    else
    {
        debug_line("Flash: get boot rom functions failed !");
    }
    memcpy(data, (void*)(0x13000000 + (0xffffff & start_address)), length);
    // XIP off
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
        debug_line("Flash: get boot rom functions failed !");
    }
#else
    read_data(start_address, data, length);
#endif
}


void flash_report(void)
{
#ifdef BOOT_ROM_ENABLED
    debug_line("using BOOT ROM functions !");
#else
    read_status_register();
    if(0 != (STATUS_REGISTER_BUSY & status_register))
    {
        debug_line("Flash state: busy");
    }
    else
    {
        debug_line("Flash state: idle");
    }
    debug_line("status register: 0x%08lx (%ld)", status_register, status_register);
#endif
}

void flash_reset(void)
{
#ifdef BOOT_ROM_ENABLED
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
        debug_line("Flash: get boot rom functions failed !");
    }
#else
    qspi_reset_flash();
#endif
}

