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
#include "file_system.h"
#include "fake_fs.h"

uint32_t file_storage_get_block_count(void)
{
    return file_system_block_count();
}

uint16_t file_storage_getblock_size(void)
{
    return BLOCK_SIZE;
}

int32_t  file_storage_read(const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t start = offset;
    uint32_t abs_offset;
    uint32_t block_num = block;
    // debug_line("read: block:%ld, offset: %ld, size: %ld", block, offset, bufsize);
    while(start >= BLOCK_SIZE)
    {
        start = start - BLOCK_SIZE;
        block_num++;
    }
    if(block_num >= file_system_block_count())
    {
        return -1;  // read outside of disk
    }
    abs_offset = (block_num * BLOCK_SIZE) + start;
    return fake_fs_read(abs_offset, buffer, bufsize);
}

int32_t  file_storage_write(const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    uint32_t start = offset;
    uint32_t abs_offset;
    uint32_t block_num = block;
    while(start >= BLOCK_SIZE)
    {
        start = start - BLOCK_SIZE;
        block_num++;
    }
    if(block_num >= file_system_block_count())
    {
        return -1;  // write outside of disk
    }
    abs_offset = (block_num * BLOCK_SIZE) + offset;
    return fake_fs_write(abs_offset, buffer, bufsize);
}
