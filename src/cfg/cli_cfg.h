#ifndef CLI_CLI_CFG_H_
#define CLI_CLI_CFG_H_

#include <stdbool.h>
#include <stdint.h>

#include "../hal/debug_uart.h"

typedef bool (*cmd_func_typ)(void);

typedef struct {
    char name[12];
    char help[100];
    cmd_func_typ func;
}cmd_typ;

#define SERIAL_SEND_BYTES             debug_uart_send_bytes
#define SERIAL_NUM_RECEIVED_BYTES     debug_uart_get_num_received_bytes
#define SERIAL_GET_RECEIVED_BYTES     debug_uart_get_received_bytes
#define SERIAL_GET_NEXT_RECEIVED_BYTE debug_uart_get_next_received_byte
#define SERIAL_TICK                   debug_uart_tick

#define MAX_LINE_LENGTH   100
#define MAX_PARAMETERS    10
#define ECHO_ENABLED      true

#define PROMPT "\r\n $ "
#define WELCOME "\r\nMBSP Command Line Interface\r\n"
#define ERROR_LINE_TOO_LONG "\r\n The command is too long! please try again!\r\n"


#endif /* CLI_CLI_CFG_H_ */
