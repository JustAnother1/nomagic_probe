#ifndef TESTS_CLI_TESTS_H_
#define TESTS_CLI_TESTS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

void* cli_setup(const MunitParameter params[], void* user_data);
MunitResult test_cli_init(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_idle(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_echo(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_no_echo(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_r(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_n(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_rn(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_nr(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_nn(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_rr(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_rnr(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_nrn(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_rnrn(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_prompt_nrnr(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_cmd_invalid(const MunitParameter params[], void* user_data);
MunitResult test_cli_tick_cmd_help(const MunitParameter params[], void* user_data);

#endif /* TESTS_CLI_TESTS_H_ */
