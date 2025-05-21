/*
  automatically created hal/debug_uart.h
*/


#ifndef HAL_debug_uart_H_
#define HAL_debug_uart_H_

#include <stdbool.h>
#include <stdint.h>

void debug_uart_init(uint32_t baud_rate);
void debug_uart_tick(void);
void debug_uart_flush(void);
void debug_uart_send_bytes(const uint8_t *data, const uint32_t length);
void debug_uart_send_string(char* str);
void debug_uart_putc(void* p, char c);
uint32_t debug_uart_get_num_received_bytes(void);
uint8_t debug_uart_get_next_received_byte(void);
bool debug_uart_get_received_bytes(uint8_t *buf, const uint32_t length);

#endif /* HAL_debug_uart_H_ */

