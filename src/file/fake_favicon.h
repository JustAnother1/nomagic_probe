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

#ifndef FILE_FAKE_FAVICON_H_
#define FILE_FAKE_FAVICON_H_

#include <stdint.h>

// #define FAVICON_16    1
#define FAVICON_32    1

int32_t fake_favicon_ico_file(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize);


#endif /* FILE_FAKE_FAVICON_H_ */
