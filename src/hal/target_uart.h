/*
  automatically created hal/target_uart.h
*/



#ifndef HAL_target_uart_H_
#define HAL_target_uart_H_

#include <stdbool.h>
#include <stdint.h>

void target_uart_init(uint32_t baud_rate);
void target_uart_tick(void);
void target_uart_flush(void);
void target_uart_send_bytes(const uint8_t *data, const uint32_t length);
void target_uart_send_string(char* str);
void target_uart_putc(void* p, char c);
uint32_t target_uart_get_num_received_bytes(void);
uint8_t target_uart_get_next_received_byte(void);
bool target_uart_get_received_bytes(uint8_t *buf, const uint32_t length);

#endif /* HAL_target_uart_H_ */

