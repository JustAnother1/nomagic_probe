#ifndef TESTS_MOCKS_H_
#define TESTS_MOCKS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

uint8_t mock_get_next_received_byte(void);

// convenience functions
void send_bytes_to_cli(uint8_t *buf, uint32_t length);
void debug_putc(void* p, char c);

extern uint8_t recv_buf[RECEIVE_BUFFER_SIZE];
extern uint8_t send_buf[SEND_BUFFER_SIZE];
extern uint32_t recv_read_pos;
extern uint32_t recv_write_pos;
extern uint32_t send_read_pos;
extern uint32_t send_write_pos;
extern bool echo_enabled;


#endif /* TESTS_MOCKS_H_ */
