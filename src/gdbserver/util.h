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
uint32_t hex_to_int(char* hex, uint32_t num_digits);
void int_to_hex(char* hex, uint32_t value, uint32_t num_digits);


#endif /* UTIL_H_ */
