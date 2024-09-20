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

#include <stdint.h>

uint32_t file_storage_get_block_count(void)
{
    return 12;
}

uint16_t file_storage_getblock_size(void)
{
    return 512;
}

int32_t  file_storage_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;

    return -1;
}

int32_t  file_storage_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;

    return -1;
}
