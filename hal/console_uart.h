#ifndef HAL_CONSOLE_UART_H
#define HAL_CONSOLE_UART_H

#include <stdio.h>
#include <stdbool.h>

// configure:
#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

// initialize:
void console_uart_initialize(void);

// send data:
uint32_t console_uart_send_bytes(uint8_t *data, uint32_t length);
void console_uart_send_String(char* str);

// get received data:
uint32_t console_uart_get_num_received_bytes(void);
uint8_t console_uart_get_next_received_byte(void);
bool console_uart_get_received_bytes(uint8_t *buf, uint32_t length);

#endif // HAL_CONSOLE_UART_H
