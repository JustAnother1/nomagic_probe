#ifndef TESTS_MOCKS_H_
#define TESTS_MOCKS_H_

#include "munit.h"
#include <stdint.h>
#include <stdbool.h>

#define TST_RECEIVE_BUFFER_SIZE      100
#define TST_SEND_BUFFER_SIZE         500

uint8_t mock_get_next_received_byte(void);

// convenience functions
void send_bytes_to_cli(uint8_t *buf, uint32_t length);
void debug_putc(void* p, char c);
void reset_send_receive_buffers(void);
uint32_t get_num_bytes_in_recv_buffer(void);
uint32_t get_num_bytes_in_send_buffer(void);
void set_echo_enabled(bool val);
void dump_buffer_ascii(char* buffer, uint32_t length);
void dump_send_buffer(void);

#endif /* TESTS_MOCKS_H_ */
