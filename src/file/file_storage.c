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
#include "file_system.h"

uint32_t file_storage_get_block_count(void)
{
    return file_system_block_count();
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
    if(block >= file_system_block_count())
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
        // read from file system
        return file_system_read(block, offset, buffer, bufsize);
    }
}

int32_t  file_storage_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    if(block >= file_system_block_count())
    {
        return -1;  // write outside of disk
    }
    if(block < NUM_FAKED_BLOCKS)
    {
        return faked_write(block, offset, buffer, bufsize);
    }
    else
    {
        return file_system_write(block, offset, buffer, bufsize);
    }
}

