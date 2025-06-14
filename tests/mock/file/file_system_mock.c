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
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

void file_system_init(void)
{

}

bool file_system_report(const uint32_t loop)
{
    (void) loop;
    return false;
}

uint32_t file_system_block_count(void)
{
    return 0;
}

// returns the number of bytes read or a negative number to indicate an error
int32_t file_system_read(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    (void) offset;
    if(NULL == buffer)
    {
        return 0;
    }
    memset(buffer, 0xff, bufsize);
    return bufsize;
}

// returns the number of bytes read or a negative number to indicate an error
int32_t file_system_write(const uint32_t offset, uint8_t* buffer, const uint32_t bufsize)
{
    (void) offset;
    if(NULL == buffer)
    {
        return 0;
    }
    return bufsize;
}

void file_system_format(void)
{

}
