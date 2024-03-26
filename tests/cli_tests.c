#include "cli_tests.h"
#include "mocks.h"
#include "../src/probe_api/cli.h"
#include "../src/lib/printf.h"

void* cli_setup(const MunitParameter params[], void* user_data) {
    (void)params;
    (void)user_data;
    init_printf(NULL, debug_putc);
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    memset(recv_buf, 0, RECEIVE_BUFFER_SIZE);
    memset(send_buf, 0, SEND_BUFFER_SIZE);
    echo_enabled = false;
    cli_init();
    return NULL;
}

MunitResult test_cli_init(const MunitParameter params[], void* user_data) {
    // Objective: init  sends out the welcome string folowed by a prompt
    uint8_t res_buf[37] = {'\r', '\n',
        'M', 'B', 'S', 'P', ' ', 'C', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'L', 'i', 'n', 'e', ' ', 'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e', '\r', '\n',
        '\r', '\n',
        ' ', '$', ' '};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    // cli_init(); <- part of setup
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(36, ==, send_write_pos);
    munit_assert_memory_equal(36, res_buf, send_buf);
    return MUNIT_OK;
}

MunitResult test_cli_tick_idle(const MunitParameter params[], void* user_data) {
    // Objective: tick does nothing if no new bytes have arrived
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    cli_tick();
    munit_assert_uint32(0, ==, recv_read_pos);
    munit_assert_uint32(0, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(0, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_echo(const MunitParameter params[], void* user_data) {
    // Objective: tick echos back a single character
    uint8_t data = 0x42;
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    echo_enabled = true;
    send_bytes_to_cli(&data, 1);
    cli_tick();
    munit_assert_uint32(1, ==, recv_read_pos);
    munit_assert_uint32(1, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(1, ==, send_write_pos);
    munit_assert_uint32(send_buf[0], ==, 0x42);
    return MUNIT_OK;
}

MunitResult test_cli_tick_no_echo(const MunitParameter params[], void* user_data) {
    // Objective: tick echos back a single character
    uint8_t data = 0x42;
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(&data, 1);
    cli_tick();
    munit_assert_uint32(1, ==, recv_read_pos);
    munit_assert_uint32(1, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(0, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_r(const MunitParameter params[], void* user_data) {
    // Objective: \r causes a new prompt
    uint8_t data = '\r';
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(&data, 1);
    cli_tick();
    munit_assert_uint32(1, ==, recv_read_pos);
    munit_assert_uint32(1, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(5, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_n(const MunitParameter params[], void* user_data) {
    // Objective:\n causes a new prompt
    uint8_t data = '\n';
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(&data, 1);
    cli_tick();
    munit_assert_uint32(1, ==, recv_read_pos);
    munit_assert_uint32(1, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(5, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_rn(const MunitParameter params[], void* user_data) {
    // Objective: \r\n causes only one new prompt
    uint8_t data[2] = {'\r', '\n'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 2);
    cli_tick();
    munit_assert_uint32(2, ==, recv_read_pos);
    munit_assert_uint32(2, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(5, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_nr(const MunitParameter params[], void* user_data) {
    // Objective: \n\r causes only one new prompt
    uint8_t data[2] = {'\n', '\r'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 2);
    cli_tick();
    munit_assert_uint32(2, ==, recv_read_pos);
    munit_assert_uint32(2, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(5, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_nn(const MunitParameter params[], void* user_data) {
    // Objective: \n\n causes two new prompts
    uint8_t data[2] = {'\n', '\n'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 2);
    cli_tick();
    munit_assert_uint32(2, ==, recv_read_pos);
    munit_assert_uint32(2, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_rr(const MunitParameter params[], void* user_data) {
    // Objective: \r\r causes two new prompts
    uint8_t data[2] = {'\r', '\r'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 2);
    cli_tick();
    munit_assert_uint32(2, ==, recv_read_pos);
    munit_assert_uint32(2, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_rnr(const MunitParameter params[], void* user_data) {
    // Objective: \r\n\r causes two new prompts
    uint8_t data[3] = {'\r', '\n', '\r'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 3);
    cli_tick();
    munit_assert_uint32(3, ==, recv_read_pos);
    munit_assert_uint32(3, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_nrn(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n causes two new prompts
    uint8_t data[3] = {'\n', '\r', '\n'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 3);
    cli_tick();
    munit_assert_uint32(3, ==, recv_read_pos);
    munit_assert_uint32(3, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_rnrn(const MunitParameter params[], void* user_data) {
    // Objective: \r\n\r\n causes two new prompts
    uint8_t data[4] = {'\r', '\n', '\r', '\n'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 4);
    cli_tick();
    munit_assert_uint32(4, ==, recv_read_pos);
    munit_assert_uint32(4, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_prompt_nrnr(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[4] = {'\n', '\r', '\n', '\r'};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 4);
    cli_tick();
    munit_assert_uint32(4, ==, recv_read_pos);
    munit_assert_uint32(4, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(10, ==, send_write_pos);
    return MUNIT_OK;
}

MunitResult test_cli_tick_cmd_invalid(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'b', 'l', 'a', '\r'};
    uint8_t res_buf[] = {'\r', '\n',
'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', '(', 'b', 'l', 'a', ')', ' ',
'[', ' ', '6', '2', ' ', '6', 'c', ' ', '6', '1', ' ', ']',' ',' ', 't', 'y', 'p', 'e', ' ',
'\'', 'h', 'e', 'l', 'p', '\'', ' ',
'f', 'o', 'r', ' ', 'l', 'i', 's', 't', ' ','o', 'f', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ',
'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\r', '\n',
' ', '$', ' '};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 4);
    cli_tick();
    munit_assert_uint32(4, ==, recv_read_pos);
    munit_assert_uint32(4, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(84, ==, send_write_pos);
    munit_assert_memory_equal(36, res_buf, send_buf);
    return MUNIT_OK;
}

MunitResult test_cli_tick_cmd_help(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'h', 'e', 'l', 'p', '\r'};
    uint8_t res_buf[] = {'\r', '\n',
'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', ' ', ':', '\r', '\n',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'h', 'e', 'l', 'p', ' ', ':', ' ', 'l', 'i', 's', 't', ' ', 'a', 'l', 'l', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\r', '\n',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'i', 'm', 'e', ' ', ':', ' ', 't', 'i', 'm', 'e', ' ', 's', 'i', 'n', 'c', 'e', ' ', 'p', 'o', 'w', 'e', 'r', ' ', 'o', 'n', '\r', '\n',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'e', 's', 't', ' ', ':', ' ', 't', 'e', 's', 't', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', '\r', '\n',
'\r', '\n',' ', '$', ' '};
    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) user_data;
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    send_bytes_to_cli(data, 5);
    cli_tick();
    cli_tick();
    cli_tick();
    cli_tick();
    cli_tick();
    munit_assert_uint32(5, ==, recv_read_pos);
    munit_assert_uint32(5, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(147, ==, send_write_pos);
    // STRNCMP_EQUAL("\r\navailable commands :\r\ntime : time since power on\r\ntest : test command\r\n $ ", (const char*)send_buf, 82);
    munit_assert_memory_equal(78, res_buf, send_buf);
    return MUNIT_OK;
}

