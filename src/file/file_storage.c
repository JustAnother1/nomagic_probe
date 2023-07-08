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

#include "file_storage.h"
#include "faked_disk.h"
#include "cfg/cli_cfg.h"


#define BLOCK_COUNT 2048
/*
 * XIP Address alias:
 0x10... XIP access, cacheable, allocating - Normal cache operation
 0x11... XIP access, cacheable, non-allocating - Check for hit, don’t update cache on miss
 0x12... XIP access, non-cacheable, allocating - Don’t check for hit, always update cache
 0x13... XIP access, non-cacheable, non-allocating - Bypass cache completely
 0x15... Use XIP cache as SRAM bank, mirrored across entire segment
*/

#define DATA_FLASH_BASE_ADDRESS (0x13000000 + MAX_FIRMWARE_SIZE)


static void flash_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);


uint32_t file_storage_get_block_count(void)
{
    return BLOCK_COUNT;
}

uint16_t file_storage_getblock_size(void)
{
    return BLOCK_SIZE;
}

int32_t  file_storage_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    // debug_line("read: block:%ld, offset: %ld, size: %ld", block, offset, bufsize);
    while(offset >= BLOCK_SIZE)
    {
        offset = offset - BLOCK_SIZE;
        block++;
    }
    if(block >= BLOCK_COUNT)
    {
        return -1;  // read outside of disk
    }
    if(block < NUM_FAKED_BLOCKS)
    {
        // read faked
        return faked_read(block, offset, buffer, bufsize);
    }
    else
    {
        // read flash data
        memcpy(buffer,
               (void*)(DATA_FLASH_BASE_ADDRESS + ((block - NUM_FAKED_BLOCKS) * BLOCK_SIZE) + offset),
               (size_t)bufsize);
        return (int32_t)bufsize;
    }
}

int32_t  file_storage_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    if(block >= BLOCK_COUNT)
    {
        return -1;  // write outside of disk
    }
    if(block < NUM_FAKED_BLOCKS)
    {
        return faked_write(block, offset, buffer, bufsize);
    }
    else
    {
        // write flash sector
        flash_write(block - NUM_FAKED_BLOCKS, offset, buffer, bufsize);
        return (int32_t)bufsize;
    }
}

static void flash_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;
    // TODO flash_range_erase() flash_range_program() FLASH_PAGE_SIZE
}
