#ifndef TESTS_MOCKS_H_
#define TESTS_MOCKS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

#define CALL_IDX_TARGET_CONNECT  0
#define CALL_IDX_TARGET_CLOSE_CONNECTION 1
#define NUM_CALL_COUNTER   5


void mock_set_serial_gdb_is_connected(bool val);

void mock_reset_call_counts(void);
uint32_t mock_get_call_counter_of(uint32_t idx);

#endif /* TESTS_MOCKS_H_ */
