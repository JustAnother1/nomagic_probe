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

#include "gdbserver_gdbserver_tests.h"
#include "../src/gdbserver/gdbserver.h"
#include "mocks.h"
// #include "mock/serial_debug.h"
#include "mock/serial_gdb.h"

extern uint8_t gdb_send_buf[TST_GDB_SEND_BUFFER_SIZE];

void* gdbserver_gdbserver_setup(const MunitParameter params[], void* user_data)
{
    (void)params;
    (void)user_data;

    gdb_reset_send_receive_buffers();

    gdbserver_init();
    return NULL;
}


MunitResult test_gdbserver_empty_packet(const MunitParameter params[], void* user_data)
{
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    reply_packet_prepare();  // adds "$"
    reply_packet_send();   // adds "#xx

    munit_assert_uint32(4, ==, gdb_get_num_bytes_in_send_buffer());
    munit_assert_uint32(0, ==, gdb_get_num_bytes_in_recv_buffer());
    // printf("\n%s\n", send_buf);
    munit_assert_uint32(gdb_send_buf[0], ==, '$');
    munit_assert_uint32(gdb_send_buf[1], ==, '#');
    munit_assert_uint32(gdb_send_buf[2], ==, '0');
    munit_assert_uint32(gdb_send_buf[3], ==, '0');

    return MUNIT_OK;
}

// void reply_packet_add_hex(uint32_t data, uint32_t digits);
MunitResult test_gdbserver_hex(const MunitParameter params[], void* user_data)
{
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    reply_packet_prepare();  // adds "$"
    reply_packet_add_hex(42, 2); // adds "2a"
    reply_packet_send();   // adds "#xx

    // printf("\n%s\n", send_buf);
    munit_assert_uint32(6, ==, gdb_get_num_bytes_in_send_buffer());
    munit_assert_uint32(0, ==, gdb_get_num_bytes_in_recv_buffer());
    munit_assert_uint32(gdb_send_buf[0], ==, '$');
    munit_assert_uint32(gdb_send_buf[1], ==, '2');
    munit_assert_uint32(gdb_send_buf[2], ==, 'a');
    munit_assert_uint32(gdb_send_buf[3], ==, '#');
    munit_assert_uint32(gdb_send_buf[4], ==, '9');
    munit_assert_uint32(gdb_send_buf[5], ==, '3');

    return MUNIT_OK;
}

MunitResult test_gdbserver_hex_sqish(const MunitParameter params[], void* user_data)
{
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;

    reply_packet_prepare();  // adds "$"
    reply_packet_add_hex(500, 0); // adds "1f4"
    reply_packet_send();   // adds "#xx

    // printf("\n%s\n", send_buf);
    munit_assert_uint32(7, ==, gdb_get_num_bytes_in_send_buffer());
    munit_assert_uint32(0, ==, gdb_get_num_bytes_in_recv_buffer());
    munit_assert_uint32(gdb_send_buf[0], ==, '$');
    munit_assert_uint32(gdb_send_buf[1], ==, '1');
    munit_assert_uint32(gdb_send_buf[2], ==, 'f');
    munit_assert_uint32(gdb_send_buf[3], ==, '4');
    munit_assert_uint32(gdb_send_buf[4], ==, '#');
    munit_assert_uint32(gdb_send_buf[5], ==, 'c');
    munit_assert_uint32(gdb_send_buf[6], ==, 'b');

    return MUNIT_OK;
}
