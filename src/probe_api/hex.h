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


#ifndef PROBE_API_HEX_H_
#define PROBE_API_HEX_H_


uint32_t hex_to_int(char* hex, uint32_t num_digits);
void int_to_hex(char* hex, uint32_t value, uint32_t num_digits);
void byte_to_hex(char* hex, uint32_t value);


#endif /* PROBE_API_HEX_H_ */
