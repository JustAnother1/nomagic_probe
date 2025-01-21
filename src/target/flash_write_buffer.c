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

#include <stddef.h>
#include <string.h>
#include "flash_write_buffer.h"

static uint32_t block_size;
static uint32_t num_blocks;
static uint32_t first_invalid_idx;
static uint8_t write_buffer[2048]; // the stored bytes to write
static uint32_t gdb_start_address;
static uint32_t gdb_length;
static uint32_t buffer_start_address;
static uint32_t write_idx;
static uint32_t read_idx;
static uint32_t section_end_idx;
static uint32_t next_section_address;

void flash_write_buffer_init(uint32_t block_size_bytes)
{
    block_size = block_size_bytes;
    memset(write_buffer, 0x23, sizeof(write_buffer));
    num_blocks = sizeof(write_buffer)/block_size;
    first_invalid_idx = num_blocks * block_size;
    gdb_length = 0;
    gdb_start_address = 0;
    buffer_start_address = 0;
    write_idx = 0;
    read_idx = 0;
    section_end_idx = 0;
    next_section_address = 0;
}

// new data arrived from gdb
// length can be more than 256 bytes !
Result flash_write_buffer_add_data(uint32_t start_address, uint32_t length, uint8_t* data)
{
    if((0 == length) || (NULL == data))
    {
        return ERR_INVALID_PARAMETER;
    }
    if((gdb_length == length) && (gdb_start_address == start_address))
    {
        // we already know this data
        return RESULT_OK;
    }
    // does the address match?
    if(0 != buffer_start_address)
    {
        if(start_address == buffer_start_address + write_idx)
        {
            // matches !
        }
        else
        {
            // new section !
            // -> move write index to next block beginning
            uint32_t idx = 0;
            while(idx < write_idx)
            {
                idx = idx + block_size;
            }
            idx = idx + block_size;
            section_end_idx = write_idx;
            write_idx = idx;
            if(first_invalid_idx == write_idx)
            {
                write_idx = 0;
            }
            next_section_address = start_address;
        }
    }
    else
    {
        // first data since init
        buffer_start_address = start_address - write_idx;
    }
    // does it fit?
    if(write_idx + length >= first_invalid_idx)
    {
        // wrap around?
        uint32_t overlap = write_idx + length - first_invalid_idx;
        if(overlap < read_idx)
        {
            // ok
            memcpy(&write_buffer[write_idx], data, length - overlap);
            memcpy(&write_buffer[0], &data[length - overlap], overlap);
            write_idx = overlap;
        }
        else
        {
            return ERR_TOO_LONG;
        }
    }
    else
    {
        memcpy(&write_buffer[write_idx], data, length);
        write_idx = write_idx + length;
    }

    // done with this data
    gdb_length = length;
    gdb_start_address = start_address;

    return RESULT_OK;
}

bool flash_write_buffer_has_data_block(void)
{
    if(read_idx == write_idx)
    {
        // buffer empty
        return false;
    }
    else
    {
        if(0 == section_end_idx)
        {
            if(write_idx > read_idx)
            {
                // no wrap around
                if(read_idx + block_size <= write_idx)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                // wrap around
                if(read_idx + block_size <= first_invalid_idx)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            // only check read_idx to section_end_idx
            if(section_end_idx > read_idx)
            {
                // no wrap around
                if(read_idx + block_size <= section_end_idx)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                // wrap around
                if(read_idx + block_size <= first_invalid_idx)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}

// get address of next byte available
uint32_t flash_write_buffer_get_write_address(void)
{
    return buffer_start_address + read_idx;
}

// get next bytes to write
uint8_t* flash_write_buffer_get_data_block(void)
{
    if(read_idx == write_idx)
    {
        return NULL;
    }
    else
    {
        return &write_buffer[read_idx];
    }
}

// those number of bytes have been written and can now be removed from the buffer
void flash_write_buffer_remove_block(void)
{
    if(0 != section_end_idx)
    {
        if((read_idx < section_end_idx) && (read_idx + block_size > section_end_idx))
        {
            section_end_idx = 0;
            read_idx = read_idx + block_size;
            if(first_invalid_idx == read_idx)
            {
                buffer_start_address = buffer_start_address + first_invalid_idx;
                read_idx = 0;
            }
            return;
        }
    }
    if(read_idx != write_idx)
    {
        if((write_idx > read_idx) && (write_idx < read_idx + block_size))
        {
            // partial write -> skip the missing bytes
            write_idx = read_idx + block_size;
            if(first_invalid_idx == write_idx)
            {
                write_idx = 0;
            }
        }
        read_idx = read_idx + block_size;
        if(first_invalid_idx == read_idx)
        {
            buffer_start_address = buffer_start_address + first_invalid_idx;
            read_idx = 0;
        }
    }
    // else buffer is empty
}

uint32_t flash_write_buffer_get_length_available_no_waiting(void)
{
    if(0 != section_end_idx)
    {
        // TODO
    }
    return 0;
}

uint32_t flash_write_buffer_get_length_available_waiting(void)
{
    if(write_idx > read_idx)
    {
        // no wrap around
        return write_idx - read_idx;
    }
    else if(read_idx == write_idx)
    {
        // buffer empty
        return 0;
    }
    else
    {
        // wrap around
        return ((first_invalid_idx - read_idx -1) + write_idx);
    }
    return false;
}
