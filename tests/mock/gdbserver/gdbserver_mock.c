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

#include <stdint.h>
#include <stdbool.h>

void reply_packet_prepare(void)
{

}

void reply_packet_add(char* data)
{
    (void) data;
}
void reply_packet_add_max(char* data, uint32_t length)
{
    (void) data;
    (void) length;
}

void reply_packet_add_hex(uint32_t data, uint32_t digits)
{
    (void) data;
    (void) digits;
}

void reply_packet_send(void)
{

}

void send_error_packet(void)
{

}

void send_ack_packet(void)
{

}

void send_unknown_command_reply(void)
{

}

void gdb_is_now_busy(void)
{

}

void gdb_is_not_busy_anymore(void)
{

}

bool is_gdb_busy(void)
{
    return false;
}

void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length)
{
    (void) part;
    (void) size;
    (void) offset;
    (void) length;
}
