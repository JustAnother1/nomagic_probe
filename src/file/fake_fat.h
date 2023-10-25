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

#ifndef FILE_FAKE_FAT_H_
#define FILE_FAKE_FAT_H_

#include <stdint.h>

int32_t fake_fat_read(uint32_t offset, uint8_t* buffer, uint32_t bufsize);
int32_t fake_fat_write(uint32_t offset, uint8_t* buffer, uint32_t bufsize);

#endif /* FILE_FAKE_FAT_H_ */