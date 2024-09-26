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
#ifndef UTIL_H_
#define UTIL_H_

#include <stdint.h>
#include <stdbool.h>


uint32_t calculateChecksum(char *data, uint32_t length);
void decode_hex_string_to_text(char * hex, uint32_t buf_length, char * buf);
void encode_text_to_hex_string(char * text, uint32_t buf_length, char * buf);
void binary_to_ascii_dump(char * data, uint32_t length);

#endif /* UTIL_H_ */
