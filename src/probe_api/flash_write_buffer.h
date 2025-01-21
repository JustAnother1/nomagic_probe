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

#ifndef FLASH_WRITE_BUFFER_H_
#define FLASH_WRITE_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>
#include "probe_api/result.h"

void flash_write_buffer_init(uint32_t block_size_bytes);
// new data arrived from gdb
Result flash_write_buffer_add_data(uint32_t start_address, uint32_t length, uint8_t* data);

// is there enough contiguous data in the buffer to write length bytes?
bool flash_write_buffer_has_data_block(void);
// get address of next byte available
uint32_t flash_write_buffer_get_write_address(void);
// get next bytes to write
uint8_t* flash_write_buffer_get_data_block(void);
// those number of bytes have been written and can now be removed from the buffer
void flash_write_buffer_remove_block(void);
// get the number of bytes that can be written in one go  that are not the last segment. if only one segment then return 0.
uint32_t flash_write_buffer_get_length_available_no_waiting(void);
// get the number of bytes still in the buffer that can be written in one go
uint32_t flash_write_buffer_get_length_available_waiting(void);

#endif /* FLASH_WRITE_BUFFER_H_ */
