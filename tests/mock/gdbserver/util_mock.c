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

#include "probe_api/util.h"

uint32_t calculateChecksum(char *data, uint32_t length)
{
    (void) data;
    (void) length;
    return 0;
}

void decode_hex_string_to_text(char * hex, uint32_t buf_length, char * buf)
{
    (void) hex;
    (void) buf_length;
    (void) buf;
}

void encode_text_to_hex_string(char * text, uint32_t buf_length, char * buf)
{
    (void) text;
    (void) buf_length;
    (void) buf;
}

void binary_to_ascii_dump(char * data, uint32_t length)
{
    (void) data;
    (void) length;
}

void int_to_hex(char* hex, uint32_t value, uint32_t num_digits)
{
    (void) hex;
    (void) value;
    (void) num_digits;
}
