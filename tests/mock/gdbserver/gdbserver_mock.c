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

#define MAX_REPLIES           10
#define MAX_REPLY_LENGTH      2000

static bool busy;
static uint32_t reply_idx;
static uint32_t reply_pos;
static uint8_t reply_buffer[MAX_REPLIES][MAX_REPLY_LENGTH];

void mock_gdbserver_reset_replies(void)
{
    reply_idx = 0;
    reply_pos = 0;
    memset(reply_buffer, 0, sizeof(reply_buffer));
}

uint32_t mock_gdbserver_get_num_send_replies(void)
{
    return reply_idx;
}

char* mock_gdbserver_get_reply(uint32_t idx)
{
    return &reply_buffer[idx][0];
}

void reply_packet_prepare(void)
{
    reply_buffer[reply_idx][0] = '(';
    reply_pos = 1;
}

void reply_packet_add(char* data)
{
    while(0 != *data)
    {
        reply_buffer[reply_idx][reply_pos] = *data;
        reply_pos++;
        data++;
    }
}
void reply_packet_add_max(char* data, uint32_t length)
{
    uint32_t i = 0;
    while((0 != *data) && (i < length))
    {
        reply_buffer[reply_idx][reply_pos] = *data;
        reply_pos++;
        data++;
        i++;
    }
}

void reply_packet_add_hex(uint32_t data, uint32_t digits)
{
    (void) data;
    (void) digits;
}

void reply_packet_send(void)
{
    reply_buffer[reply_idx][reply_pos] = ')';
    reply_idx++;
}

void send_error_packet(void)
{
    reply_buffer[reply_idx][0] = '-';
    reply_idx++;
}

void send_ack_packet(void)
{
    reply_buffer[reply_idx][0] = '+';
    reply_idx++;
}

void send_unknown_command_reply(void)
{
    reply_buffer[reply_idx][0] = '(';
    reply_buffer[reply_idx][0] = ')';
    reply_idx++;
}

void gdb_is_now_busy(void)
{
    busy = true;
}

void gdb_is_not_busy_anymore(void)
{
    busy = false;
}

bool is_gdb_busy(void)
{
    return busy;
}

void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length)
{
    (void) part;
    (void) size;
    (void) offset;
    (void) length;
}
