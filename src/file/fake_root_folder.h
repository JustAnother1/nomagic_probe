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

#ifndef FILE_FAKE_ROOT_FOLDER_H_
#define FILE_FAKE_ROOT_FOLDER_H_

#include <stdint.h>

int32_t fake_root_folder_read(uint32_t offset, uint8_t* buffer, uint32_t bufsize);
int32_t fake_root_folder_write(uint32_t offset, uint8_t* buffer, uint32_t bufsize);

uint32_t fake_root_folder_get_first_sector_of(char* filename);
uint32_t fake_root_folder_get_size_of(char* filename);

#endif /* FILE_FAKE_ROOT_FOLDER_H_ */
