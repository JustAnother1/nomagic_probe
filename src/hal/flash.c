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

#include "flash.h"
#include "hal/boot_rom.h"

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
        // flash_funcs->_connect_internal_flash();
        // flash_funcs->_flash_exit_xip();
    }
}

void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if(NULL != flash_funcs)
    {
        flash_funcs->flash_range_program(start_address, data, length);
    }
}

//! erases one page (smalles erase possible) that is 4096 bytes.
void flash_erase_page(uint32_t number)
{
    if(NULL != flash_funcs)
    {
        flash_funcs->_flash_range_erase(number*4096, 4096, 0, 0);
    }
}


