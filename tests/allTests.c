#include "munit.h"
#include <stdint.h>
#include <stdbool.h>
#include "../src/cli/cli.h"
#include "../src/lib/printf.h"


#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

uint8_t mock_get_next_received_byte(void);

// convenience functions
void send_bytes_to_cli(uint8_t *buf, uint32_t length);

uint8_t recv_buf[RECEIVE_BUFFER_SIZE];
uint8_t send_buf[SEND_BUFFER_SIZE];
uint32_t recv_read_pos;
uint32_t recv_write_pos;
uint32_t send_read_pos;
uint32_t send_write_pos;
bool echo_enabled;

void mock_tick(void)
{
    // nothing to do
}

bool mock_echo(void)
{
    return echo_enabled;
}

uint32_t mock_send_bytes(uint8_t *data, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = data[i];
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
    return i;
}

void mock_send_String(char* str)
{
    while(*str != 0) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = *str;
            str++;
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

uint8_t mock_get_next_received_byte(void) {
    uint8_t res;
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    res = recv_buf[recv_read_pos];
    recv_read_pos++;
    if (RECEIVE_BUFFER_SIZE == recv_read_pos) {
        recv_read_pos = 0;
    }
    return res;
}

uint32_t mock_get_num_received_bytes(void)
{
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    if (recv_read_pos < recv_write_pos) {
        return recv_write_pos - recv_read_pos;
    } else {
        // wrap around
        return (RECEIVE_BUFFER_SIZE - recv_read_pos) + recv_write_pos;
    }
}

bool mock_get_received_bytes(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    if (length < mock_get_num_received_bytes()) {
        return false;
    }
    for (i = 0; i < length; i++) {
        buf[i] = mock_get_next_received_byte();
    }
    return true;
}

void send_bytes_to_cli(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = recv_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write) {
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

static void debug_putc(void* p, char c)
{
    (void) p; // not used
    mock_send_bytes((uint8_t *)&c, 1);
}

static void* setup(const MunitParameter params[], void* user_data) {
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

static MunitResult test_init(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_idle(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_echo(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_no_echo(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_r(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_n(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_rn(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_nr(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_nn(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_rr(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_rnr(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_nrn(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_rnrn(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_prompt_nrnr(const MunitParameter params[], void* user_data) {
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

static MunitResult test_tick_cmd_invalid(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'b', 'l', 'a', '\r'};
    uint8_t res_buf[] = {'\r', '\n',
'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', '(', 'b', 'l', 'a', ')', ' ',
't', 'y', 'p', 'e', ' ', '\'', 'h', 'e', 'l', 'p', '\'', ' ', 'f', 'o', 'r', ' ', 'l', 'i', 's', 't', ' ',
'o', 'f', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '.',
        '\r', '\n',
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
    munit_assert_uint32(74, ==, send_write_pos);
    munit_assert_memory_equal(36, res_buf, send_buf);
    return MUNIT_OK;
}

static MunitResult test_tick_cmd_help(const MunitParameter params[], void* user_data) {
    // Objective: \n\r\n\r causes only two new prompts
    uint8_t data[] = {'h', 'e', 'l', 'p', '\r'};
    uint8_t res_buf[] = {'\r', '\n',
'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', ' ', ':', '\r', '\n',
't', 'i', 'm', 'e', ' ', ':', ' ', 't', 'i', 'm', 'e', ' ', 's', 'i', 'n', 'c', 'e', ' ', 'p', 'o', 'w', 'e', 'r', ' ', 'o', 'n', '\r', '\n',
't', 'e', 's', 't', ' ', ':', ' ', 't', 'e', 's', 't', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', '\r', '\n',
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
    munit_assert_uint32(5, ==, recv_read_pos);
    munit_assert_uint32(5, ==, recv_write_pos);
    munit_assert_uint32(0, ==, send_read_pos);
    munit_assert_uint32(78, ==, send_write_pos);
    // STRNCMP_EQUAL("\r\navailable commands :\r\ntime : time since power on\r\ntest : test command\r\n $ ", (const char*)send_buf, 82);
    munit_assert_memory_equal(78, res_buf, send_buf);
    return MUNIT_OK;
}


/* Creating a test suite is pretty simple.  First, you'll need an
 * array of tests: */
static MunitTest cli_tests[] = {
  {
    /* The name is just a unique human-readable way to identify the
     * test. You can use it to run a specific test if you want, but
     * usually it's mostly decorative. */
    (char*) "/cli/init",
    /* You probably won't be surprised to learn that the tests are
     * functions. */
    test_init,
    /* If you want, you can supply a function to set up a fixture.  If
     * you supply NULL, the user_data parameter from munit_suite_main
     * will be used directly.  If, however, you provide a callback
     * here the user_data parameter will be passed to this callback,
     * and the return value from this callback will be passed to the
     * test function.
     *
     * For our example we don't really need a fixture, but lets
     * provide one anyways. */
    setup,
    /* If you passed a callback for the fixture setup function, you
     * may want to pass a corresponding callback here to reverse the
     * operation. */
    NULL,
    /* Finally, there is a bitmask for options you can pass here.  You
     * can provide either MUNIT_TEST_OPTION_NONE or 0 here to use the
     * defaults. */
    MUNIT_TEST_OPTION_NONE,
    NULL
  },
  /* Usually this is written in a much more compact format; all these
   * comments kind of ruin that, though.  Here is how you'll usually
   * see entries written: */
  { (char*) "/cli/tick/idle",        test_tick_idle,        setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/echo",        test_tick_echo,        setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/no_echo",     test_tick_no_echo,     setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_r",    test_tick_prompt_r,    setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_n",    test_tick_prompt_n,    setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rn",   test_tick_prompt_rn,   setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nr",   test_tick_prompt_nr,   setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nn",   test_tick_prompt_nn,   setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rr",   test_tick_prompt_rr,   setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rnr",  test_tick_prompt_rnr,  setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nrn",  test_tick_prompt_nrn,  setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rnrn", test_tick_prompt_rnrn, setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nrnr", test_tick_prompt_nrnr, setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/cmd_invalid", test_tick_cmd_invalid, setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/cmd_help",    test_tick_cmd_help,    setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },


  /* To tell the test runner when the array is over, just add a NULL
   * entry at the end. */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* If you wanted to have your test suite run other test suites you
 * could declare an array of them.  Of course each sub-suite can
 * contain more suites, etc. */
/* static const MunitSuite other_suites[] = { */
/*   { "/second", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }, */
/*   { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE } */
/* }; */

/* Now we'll actually declare the test suite.  You could do this in
 * the main function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
  /* This string will be prepended to all test names in this suite;
   * for example, "/example/rand" will become "/µnit/example/rand".
   * Note that, while it doesn't really matter for the top-level
   * suite, NULL signal the end of an array of tests; you should use
   * an empty string ("") instead. */
  (char*) "",
  /* The first parameter is the array of test suites. */
  cli_tests,
  /* In addition to containing test cases, suites can contain other
   * test suites.  This isn't necessary in this example, but it can be
   * a great help to projects with lots of tests by making it easier
   * to spread the tests across many files.  This is where you would
   * put "other_suites" (which is commented out above). */
  NULL,
  /* An interesting feature of µnit is that it supports automatically
   * running multiple iterations of the tests.  This is usually only
   * interesting if you make use of the PRNG to randomize your tests
   * cases a bit, or if you are doing performance testing and want to
   * average multiple runs.  0 is an alias for 1. */
  1,
  /* Just like MUNIT_TEST_OPTION_NONE, you can provide
   * MUNIT_SUITE_OPTION_NONE or 0 to use the default settings. */
  MUNIT_SUITE_OPTION_NONE
};

/* This is only necessary for EXIT_SUCCESS and EXIT_FAILURE, which you
 * *should* be using but probably aren't (no, zero and non-zero don't
 * always mean success and failure).  I guess my point is that nothing
 * about µnit requires it. */
#include <stdlib.h>

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  /* Finally, we'll actually run our test suite!  That second argument
   * is the user_data parameter which will be passed either to the
   * test or (if provided) the fixture setup function. */
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
