#include "munit.h"
#include <stdint.h>
#include <stdbool.h>
#include "../src/probe_api/cli.h"
#include "../src/lib/printf.h"
#include "cli_tests.h"
#include "usb_msc_tests.h"
#include "printf_tests.h"
#include "gdbserver_util_tests.h"
#include "gdbserver_gdbserver_tests.h"


// Creating a test suite is pretty simple.  First, you'll need an
// array of tests:
static MunitTest cli_tests[] = {
  {
    // The name is just a unique human-readable way to identify the
    // test. You can use it to run a specific test if you want, but
    // usually it's mostly decorative.
    (char*) "/cli/init",
    // You probably won't be surprised to learn that the tests are
    // functions.
    test_cli_init,
    // If you want, you can supply a function to set up a fixture.  If
    // you supply NULL, the user_data parameter from munit_suite_main
    // will be used directly.  If, however, you provide a callback
    // here the user_data parameter will be passed to this callback,
    // and the return value from this callback will be passed to the
    // test function.
    //
    // For our example we don't really need a fixture, but lets
    // provide one anyways.
    cli_setup,
    // If you passed a callback for the fixture setup function, you
    // may want to pass a corresponding callback here to reverse the
    // operation.
    NULL,
    // Finally, there is a bitmask for options you can pass here.  You
    // can provide either MUNIT_TEST_OPTION_NONE or 0 here to use the
    // defaults.
    MUNIT_TEST_OPTION_NONE,
    NULL
  },
  // Usually this is written in a much more compact format; all these
  // comments kind of ruin that, though.  Here is how you'll usually
  // see entries written:
  { (char*) "/cli/tick/idle",        test_cli_tick_idle,         cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/echo",        test_cli_tick_echo,         cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/no_echo",     test_cli_tick_no_echo,      cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_r",    test_cli_tick_prompt_r,     cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_n",    test_cli_tick_prompt_n,     cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rn",   test_cli_tick_prompt_rn,    cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nr",   test_cli_tick_prompt_nr,    cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nn",   test_cli_tick_prompt_nn,    cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rr",   test_cli_tick_prompt_rr,    cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rnr",  test_cli_tick_prompt_rnr,   cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nrn",  test_cli_tick_prompt_nrn,   cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_rnrn", test_cli_tick_prompt_rnrn,  cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/prompt_nrnr", test_cli_tick_prompt_nrnr,  cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/cmd_invalid", test_cli_tick_cmd_invalid,  cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cli/tick/cmd_help",    test_cli_tick_cmd_help,     cli_setup,     NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/printf/init",          test_printf_init,           printf_setup,  NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/printf/printf/string", test_printf_printf_str,     printf_setup,  NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/printf/printf/int",    test_printf_printf_int,     printf_setup,  NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/printf/printf/digits", test_printf_printf_digits,  printf_setup,  NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/usb_msc/unit_ready",   test_usb_msc_unit_ready_cb, usb_msc_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/gdbserver/util/hex_to_int",   test_gdbserver_util_hex_to_int, gdbserver_util_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/gdbserver/util/int_to_hex",   test_gdbserver_util_int_to_hex, gdbserver_util_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/gdbserver/gdbserver/empty_packet",   test_gdbserver_empty_packet, gdbserver_gdbserver_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/gdbserver/gdbserver/hex",   test_gdbserver_hex, gdbserver_gdbserver_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/gdbserver/gdbserver/hex_sqish",   test_gdbserver_hex_sqish, gdbserver_gdbserver_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  // To tell the test runner when the array is over, just add a NULL
  // entry at the end. */
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
