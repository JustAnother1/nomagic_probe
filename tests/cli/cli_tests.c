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
#include "../src/probe_api/cli.h"
#include "../src/lib/printf.h"
#include "unity.h"
#include "mock/cli/serial_debug.h"
#include "cfg/cli_cfg.h"

extern uint8_t send_buf[TST_SEND_BUFFER_SIZE];

void setUp(void)
{
    init_printf(NULL, serial_debug_putc);
    reset_send_receive_buffers();
    set_echo_enabled(false);
    cli_init();
}

void tearDown(void)
{

}

void test_cli_init(void)
{
    // Objective: cli_init()  sends out the welcome string followed by a prompt
    uint8_t res_buf[] = {'\r', '\n',
            '\r', '\n',
            '\r', '\n',
            '\r', '\n',
            '\r', '\n',
            'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r', 'o', 'b', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'i', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e', '\r', '\n',
        '\r', '\n',
        '$', ' '};
    // cli_init(); <- part of setup
    TEST_ASSERT_EQUAL_UINT32(sizeof(res_buf),get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_MEMORY(res_buf, send_buf, sizeof(res_buf));
}

void test_cli_tick_idle(void)
{
    // Objective: tick does nothing if no new bytes have arrived
    reset_send_receive_buffers();
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_echo(void)
{
    // Objective: tick echos back a single character
    uint8_t data = 0x42;
    reset_send_receive_buffers();
    set_echo_enabled(true);
    send_bytes_to_cli(&data, 1);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_UINT32(1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0x42, send_buf[0]);
}

void test_cli_tick_no_echo(void)
{
    // Objective: tick echos back a single character
    uint8_t data = 0x42;
    reset_send_receive_buffers();
    send_bytes_to_cli(&data, 1);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_r(void)
{
    // Objective: \r causes a new prompt
    uint8_t data = '\r';
    reset_send_receive_buffers();
    send_bytes_to_cli(&data, 1);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(sizeof(PROMPT)-1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_n(void)
{
    // Objective:\n causes a new prompt
    uint8_t data = '\n';
    reset_send_receive_buffers();
    send_bytes_to_cli(&data, 1);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(sizeof(PROMPT)-1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_rn(void)
{
    // Objective: \r\n causes only one new prompt
    uint8_t data[2] = {'\r', '\n'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 2);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(sizeof(PROMPT)-1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_nr(void)
{
    // Objective: \n\r causes only one new prompt
    uint8_t data[2] = {'\n', '\r'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 2);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(sizeof(PROMPT)-1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_nn(void)
{
    // Objective: \n\n causes two new prompts
    uint8_t data[2] = {'\n', '\n'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 2);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_rr(void)
{
    // Objective: \r\r causes two new prompts
    uint8_t data[2] = {'\r', '\r'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 2);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_rnr(void)
{
    // Objective: \r\n\r causes two new prompts
    uint8_t data[3] = {'\r', '\n', '\r'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 3);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_nrn(void)
{
    // Objective: \n\r\n causes two new prompts
    uint8_t data[3] = {'\n', '\r', '\n'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 3);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_rnrn(void)
{
    // Objective: \r\n\r\n causes two new prompts
    uint8_t data[4] = {'\r', '\n', '\r', '\n'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 4);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_prompt_nrnr(void)
{
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[4] = {'\n', '\r', '\n', '\r'};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 4);
    cli_tick();
    TEST_ASSERT_EQUAL_UINT32(2*(sizeof(PROMPT)-1), get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
}

void test_cli_tick_cmd_invalid(void)
{
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'b', 'l', 'a', '\r'};
    uint8_t res_buf[] = {'\r', '\n', '\r', '\n',
'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', '(', 'b', 'l', 'a', ')', ' ',
'[', ' ', '6', '2', ' ', '6', 'c', ' ', '6', '1', ' ', ']',' ', 't', 'y', 'p', 'e', ' ',
'\'', 'h', 'e', 'l', 'p', '\'', ' ',
'f', 'o', 'r', ' ', 'l', 'i', 's', 't', ' ','o', 'f', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ',
'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\r', '\n',
'\r', '\n',
'$', ' ', 0};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 4);
    cli_tick();
    TEST_ASSERT_EQUAL_STRING(res_buf, send_buf);
    TEST_ASSERT_EQUAL_UINT32(sizeof(res_buf)-1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_MEMORY(res_buf, send_buf, sizeof(res_buf)-1);
}

void test_cli_tick_cmd_help(void)
{
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'h', 'e', 'l', 'p', '\r'};
    uint8_t res_buf[] = {'\r', '\n', '\r', '\n',
'n', 'o', 'm', 'a', 'g', 'i', 'c', ' ', 'p', 'r',
'o', 'b', 'e', ' ', 'c', 'l', 'i', ' ', 'v', 'e',
'r', 's', 'i', 'o', 'n', ' ', 'u', 'n', 'i', 't',
' ', 't', 'e', 's', 't', 's', ' ', '0', '.', '0',
'.', 'x', ' ', 'v', '0', '.', '0', '.', 'y', '-',
'z', 'z', 'z','\r', '\n',
'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', ' ', ':', '\r', '\n',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'h', 'e', 'l', 'p', ' ', ':', ' ', 'l', 'i', 's', 't', ' ', 'a', 'l', 'l', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\r', '\n',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'i', 'm', 'e', ' ', ':', ' ', 't', 'i', 'm', 'e', ' ', 's', 'i', 'n', 'c', 'e', ' ', 'p', 'o', 'w', 'e', 'r', ' ', 'o', 'n', '\r', '\n',




' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'e', 's', 't', ' ', ':', ' ', 't', 'e', 's', 't', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', '\r', '\n',
'\r', '\n', '$', ' ', 0};
    reset_send_receive_buffers();
    send_bytes_to_cli(data, 5);
    cli_tick();
    cli_tick();
    cli_tick();
    cli_tick();
    cli_tick();
    // TEST_ASSERT_EQUAL_STRING(res_buf, send_buf);  // now includes time and date
    //TEST_ASSERT_EQUAL_UINT32(sizeof(res_buf) -1, get_num_bytes_in_send_buffer());
    TEST_ASSERT_EQUAL_UINT32(0, get_num_bytes_in_recv_buffer());
    TEST_ASSERT_EQUAL_MEMORY(res_buf, send_buf, 57);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_cli_init);
    RUN_TEST(test_cli_tick_idle);
    RUN_TEST(test_cli_tick_echo);
    RUN_TEST(test_cli_tick_no_echo);
    RUN_TEST(test_cli_tick_prompt_r);
    RUN_TEST(test_cli_tick_prompt_n);
    RUN_TEST(test_cli_tick_prompt_rn);
    RUN_TEST(test_cli_tick_prompt_nr);
    RUN_TEST(test_cli_tick_prompt_nn);
    RUN_TEST(test_cli_tick_prompt_rr);
    RUN_TEST(test_cli_tick_prompt_rnr);
    RUN_TEST(test_cli_tick_prompt_nrn);
    RUN_TEST(test_cli_tick_prompt_rnrn);
    RUN_TEST(test_cli_tick_prompt_nrnr);
    RUN_TEST(test_cli_tick_cmd_invalid);
    RUN_TEST(test_cli_tick_cmd_help);
    return UNITY_END();
}
