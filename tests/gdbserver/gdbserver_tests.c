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
#include <string.h>
#include "gdbserver/gdbserver.h"

#include "../mock/target/common_mock.h"
#include "unity.h"
#include "mock/gdbserver/serial_gdb.h"
#include "mock/gdbserver/commands_mock.h"


extern uint8_t gdb_send_buf[TST_GDB_SEND_BUFFER_SIZE];

static void getChecksumFor(char* data, uint32_t length, char* hex);

void setUp(void)
{
    // reset test environment
    gdb_reset_send_receive_buffers();
    mock_target_reset_call_counts();
    mock_commands_reset_call_counts();
    mock_commands_reset_commands();

    // initialize code under test
    gdbserver_init();
}

void tearDown(void)
{

}

static void getChecksumFor(char* data, uint32_t length, char* hex)
{
    uint32_t sum = 0;
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        sum = sum + (uint8_t)(data[i]);  // unsigned !
    }
    hex++;
    for(i = 0; i < 2; i++)
    {
        switch(sum&0xf)
        {
        case  0: *hex = '0'; break;
        case  1: *hex = '1'; break;
        case  2: *hex = '2'; break;
        case  3: *hex = '3'; break;
        case  4: *hex = '4'; break;
        case  5: *hex = '5'; break;
        case  6: *hex = '6'; break;
        case  7: *hex = '7'; break;
        case  8: *hex = '8'; break;
        case  9: *hex = '9'; break;
        case 10: *hex = 'a'; break;
        case 11: *hex = 'b'; break;
        case 12: *hex = 'c'; break;
        case 13: *hex = 'd'; break;
        case 14: *hex = 'e'; break;
        case 15: *hex = 'f'; break;
        }
        sum = (sum>>4);
        hex--;
    }
}

void test_gdbserver_empty_packet(void)
{
    reply_packet_prepare();  // adds "$"
    reply_packet_send();   // adds "#xx

    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(4, gdb_get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, gdb_get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_STRING ("$#00", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());
}

// void reply_packet_add_hex(uint32_t data, uint32_t digits);
void test_gdbserver_hex(void)
{
    reply_packet_prepare();  // adds "$"
    reply_packet_add_hex(42, 2); // adds "2a"
    reply_packet_send();   // adds "#xx

    // printf("\n%s\n", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(6, gdb_get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, gdb_get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_STRING ("$2a#93", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());
}

void test_gdbserver_hex_sqish(void)
{

    reply_packet_prepare();  // adds "$"
    reply_packet_add_hex(500, 0); // adds "1f4"
    reply_packet_send();   // adds "#xx

    // printf("\n%s\n", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(8, gdb_get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, gdb_get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_STRING ("$f401#fb", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());
}

// void gdbserver_tick(void)
void test_gdbserver_tick_connected(void)
{
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());
    mock_set_serial_gdb_is_connected(false);
    gdbserver_tick();
    TEST_ASSERT_EQUAL_UINT32(0, mock_get_call_counter_of(CALL_IDX_TARGET_CONNECT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_get_call_counter_of(CALL_IDX_TARGET_CLOSE_CONNECTION));
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());

    mock_set_serial_gdb_is_connected(true);
    gdbserver_tick();
    TEST_ASSERT_EQUAL_UINT32(1, mock_get_call_counter_of(CALL_IDX_TARGET_CONNECT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_get_call_counter_of(CALL_IDX_TARGET_CLOSE_CONNECTION));
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());

    mock_set_serial_gdb_is_connected(false);
    gdbserver_tick();
    TEST_ASSERT_EQUAL_UINT32(1, mock_get_call_counter_of(CALL_IDX_TARGET_CONNECT));
    TEST_ASSERT_EQUAL_UINT32(1, mock_get_call_counter_of(CALL_IDX_TARGET_CLOSE_CONNECTION));
    TEST_ASSERT_EQUAL_UINT32(2, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_num_received_commands());

}

void test_gdbserver_tick_simple_commands(void)
{
    uint8_t buf[100];
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    // send:    +$vMustReplyEmpty#3a
    // receive: +$#00

    // send:    +$QStartNoAckMode#b0
    // receive: +$OK#9a

    // send:    +$!#21
    // receive: $OK#9a
    sprintf((char*)buf, "+$vMustReplyEmpty#3a+$QStartNoAckMode#b0+$!#21");
    gdb_send_bytes_to_cli(buf, strlen((char *)buf));
    mock_set_serial_gdb_is_connected(true);
    gdbserver_tick();
    // TEST_ASSERT_EQUAL_UINT32(0, gdb_get_num_bytes_in_recv_buffer());
    // TEST_ASSERT_EQUAL_UINT32(18, gdb_get_num_bytes_in_send_buffer());
    // TEST_ASSERT_EQUAL_STRING ("+$#00+$OK#)a$OK#9a", gdb_send_buf);
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(3, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(3, mock_commands_get_num_received_commands());
    TEST_ASSERT_EQUAL_STRING ("vMustReplyEmpty", mock_commands_get_command(0));
    TEST_ASSERT_EQUAL_STRING ("QStartNoAckMode", mock_commands_get_command(1));
    TEST_ASSERT_EQUAL_STRING ("!", mock_commands_get_command(2));
}

void test_gdbserver_tick_FlashWrite(void)
{
    uint8_t buf[] = {
            '$','v','F','l','a','s','h','W','r','i','t','e',':','1','0','0','0','0','0','0','0',':',

            // 512 bytes data to write

             0x00, 0xb5, 0x32, 0x4b, 0x21, 0x20, 0x58, 0x60,
             0x98, 0x68, 0x02, 0x21, 0x88, 0x43, 0x98, 0x60,
             0xd8, 0x60, 0x18, 0x61, 0x58, 0x61, 0x2e, 0x4b,
             0x00, 0x21, 0x99, 0x60, 0x02, 0x21, 0x59, 0x61,
             0x01, 0x21, 0xf0, 0x22, 0x99, 0x50, 0x2b, 0x49,
             0x19, 0x60, 0x01, 0x21, 0x99, 0x60, 0x35, 0x20,
             0x00, 0xf0, 0x44, 0xf8, 0x02, 0x22, 0x90, 0x42,
             0x14, 0xd0, 0x06, 0x21, 0x19, 0x66, 0x00, 0xf0,
             0x34, 0xf8, 0x19, 0x6e, 0x01, 0x21, 0x19, 0x66,
             0x00, 0x20, 0x18, 0x66, 0x1a, 0x66, 0x00, 0xf0,
             0x2c, 0xf8, 0x19, 0x6e, 0x19, 0x6e, 0x19, 0x6e,
             0x05, 0x20, 0x00, 0xf0, 0x2f, 0xf8, 0x01, 0x21,
             0x08, 0x42, 0xf9, 0xd1, 0x00, 0x21, 0x99, 0x60,
             0x1b, 0x49, 0x19, 0x60, 0x00, 0x21, 0x59, 0x60,
             0x1a, 0x49, 0x1b, 0x48, 0x01, 0x60, 0x01, 0x21,
             0x99, 0x60, 0xeb, 0x21, 0x19, 0x66, 0xa0, 0x21,
             0x19, 0x66, 0x00, 0xf0, 0x12, 0xf8, 0x00, 0x21,
             0x99, 0x60, 0x16, 0x49, 0x14, 0x48, 0x01, 0x60,
             0x01, 0x21, 0x99, 0x60, 0x01, 0xbc, 0x00, 0x28,
             0x00, 0xd0, 0x00, 0x47, 0x12, 0x48, 0x13, 0x49,
             0x08, 0x60, 0x03, 0xc8, 0x80, 0xf3, 0x08, 0x88,
             0x08, 0x47, 0x03, 0xb5, 0x99, 0x6a, 0x04, 0x20,
             0x01, 0x42, 0xfb, 0xd0, 0x01, 0x20, 0x01, 0x42,
             0xf8, 0xd1, 0x03, 0xbd, 0x02, 0xb5, 0x18, 0x66,
             0x18, 0x66, 0xff, 0xf7, 0xf2, 0xff, 0x18, 0x6e,
             0x18, 0x6e, 0x02, 0xbd, 0x00, 0x00, 0x02, 0x40,
             0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0x00,
             0x00, 0x03, 0x5f, 0x00, 0x21, 0x22, 0x00, 0x00,
             0xf4, 0x00, 0x00, 0x18, 0x22, 0x20, 0x00, 0xa0,
             0x00, 0x01, 0x00, 0x10, 0x08, 0xed, 0x00, 0xe0,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x74, 0xb2, 0x4e, 0x7a,
             0xfc, 0x1f, 0x04, 0x20, 0x35, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,
             0x01, 0x02, 0x00, 0x10, 0x01, 0x02, 0x00, 0x10,

            '#', '7', '9'
    };

    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(0, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    gdb_send_bytes_to_cli(buf, sizeof(buf));
    mock_set_serial_gdb_is_connected(true);
    gdbserver_tick();
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_INIT));
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_call_counter_of(CALL_IDX_COMMANDS_EXECUTE));
    TEST_ASSERT_EQUAL_UINT32(1, mock_commands_get_num_received_commands());
    TEST_ASSERT_EQUAL_STRING ("vFlashWrite:10000000:", mock_commands_get_command(0));
    TEST_ASSERT_EQUAL_UINT32(533, mock_commands_get_length(0));
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_gdbserver_empty_packet);
    RUN_TEST(test_gdbserver_hex);
    RUN_TEST(test_gdbserver_hex_sqish);
    RUN_TEST(test_gdbserver_tick_connected);
    RUN_TEST(test_gdbserver_tick_simple_commands);
    RUN_TEST(test_gdbserver_tick_FlashWrite);
    return UNITY_END();
}

