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

#ifndef FILE_FILE_STORAGE_H_
#define FILE_FILE_STORAGE_H_

#include <stdint.h>

// this is the API used by the USB mass storage device

#define BLOCK_SIZE        512

uint32_t file_storage_get_block_count(void);
uint16_t file_storage_getblock_size(void);
int32_t  file_storage_read(const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);
int32_t  file_storage_write(const uint32_t block, const uint32_t offset, uint8_t* buffer, const uint32_t bufsize);

#endif /* FILE_FILE_STORAGE_H_ */
