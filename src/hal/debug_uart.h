#ifndef HAL_DEBUG_UART_H
#define HAL_DEBUG_UART_H

#include <stdio.h>
#include <stdbool.h>
#include "lib/printf.h"

// configure:
#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

#define debug_msg(...)  tfp_printf(__VA_ARGS__)
#define debug_line(...) tfp_printf(__VA_ARGS__); tfp_printf("\r\n")

// initialize:
void debug_uart_initialize(void);
void debug_uart_tick(void);

// send data:
uint32_t debug_uart_send_bytes(uint8_t *data, uint32_t length);
void debug_uart_send_String(char* str);

// get received data:
uint32_t debug_uart_get_num_received_bytes(void);
uint8_t debug_uart_get_next_received_byte(void);
bool debug_uart_get_received_bytes(uint8_t *buf, uint32_t length);

#endif // HAL_DEBUG_UART_H
