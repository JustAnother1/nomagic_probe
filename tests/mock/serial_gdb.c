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

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "serial_gdb.h"
#include "../src/cfg/serial_cfg.h"

static uint8_t recv_buf[TST_GDB_RECEIVE_BUFFER_SIZE];
uint8_t gdb_send_buf[TST_GDB_SEND_BUFFER_SIZE];
static uint32_t recv_read_pos;
static uint32_t recv_write_pos;
static uint32_t send_read_pos;
static uint32_t send_write_pos;
static bool result_serial_gdb_is_connected = false;


void gdb_reset_send_receive_buffers(void)
{
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    memset(recv_buf, 0, TST_GDB_RECEIVE_BUFFER_SIZE);
    memset(gdb_send_buf, 0, TST_GDB_SEND_BUFFER_SIZE);
}

uint32_t gdb_get_num_bytes_in_recv_buffer(void)
{
    if(recv_write_pos == recv_read_pos)
    {
        return 0;
    }
    else if(recv_write_pos > recv_read_pos)
    {
        return recv_write_pos - recv_read_pos;
    }
    else
    {
        return recv_write_pos + (TST_GDB_RECEIVE_BUFFER_SIZE - recv_read_pos);
    }
}

void gdb_dump_send_buffer(void)
{
    uint32_t pos = send_read_pos;
    printf("send buffer: [");
    while(send_write_pos != pos)
    {
        printf("%c", gdb_send_buf[pos]);
        pos++;
        if(TST_GDB_SEND_BUFFER_SIZE == pos)
        {
            pos = 0;
        }
    }
    printf("]\r\n");
}

uint32_t gdb_get_num_bytes_in_send_buffer(void)
{
    if(send_write_pos == send_read_pos)
    {
        return 0;
    }
    else if(send_write_pos > send_read_pos)
    {
        return send_write_pos - send_read_pos;
    }
    else
    {
        return send_write_pos + (TST_GDB_RECEIVE_BUFFER_SIZE - send_read_pos);
    }
}

bool gdb_mock_get_received_bytes(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    if (length < serial_gdb_get_num_received_bytes()) {
        return false;
    }
    for (i = 0; i < length; i++) {
        buf[i] = serial_gdb_get_next_received_byte();
    }
    return true;
}

void gdb_send_bytes_to_cli(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = recv_write_pos;
        next_write++;
        if (TST_GDB_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != recv_read_pos) {
            recv_buf[recv_write_pos] = buf[i];
            recv_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

void gdb_dump_buffer_ascii(char* buffer, uint32_t length)
{
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        switch(buffer[i])
        {
        case '\r': printf("\\r"); break;
        case '\n': printf("\\n\n"); break;
        default: printf("%c", buffer[i]); break;
        }
    }
}

void serial_gdb_send_string(char * str)
{
    while(*str != 0) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (TST_GDB_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            gdb_send_buf[send_write_pos] = *str;
            str++;
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

void serial_gdb_send_bytes(const uint8_t * data, const uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (TST_GDB_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            gdb_send_buf[send_write_pos] = data[i];
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

uint32_t serial_gdb_get_num_received_bytes(void)
{
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    if (recv_read_pos < recv_write_pos) {
        return recv_write_pos - recv_read_pos;
    } else {
        // wrap around
        return(TST_GDB_RECEIVE_BUFFER_SIZE - recv_read_pos) + recv_write_pos;
    }
}

uint8_t serial_gdb_get_next_received_byte(void)
{
    uint8_t res;
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    res = recv_buf[recv_read_pos];
    recv_read_pos++;
    if(TST_GDB_RECEIVE_BUFFER_SIZE == recv_read_pos) {
        recv_read_pos = 0;
    }
    return res;
}

void serial_gdb_putc(void* p, char c)
{
    (void) p; // not used
    serial_gdb_send_bytes((uint8_t *)&c, 1);
}

void mock_set_serial_gdb_is_connected(bool val)
{
    result_serial_gdb_is_connected = val;
}

bool serial_gdb_is_connected(void)
{
    return result_serial_gdb_is_connected;
}

void serial_gdb_flush(void)
{

}
