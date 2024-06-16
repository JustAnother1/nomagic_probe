#ifndef CLI_CLI_CFG_H_
#define CLI_CLI_CFG_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../src/lib/printf.h"

void mock_tick(void);
bool mock_echo(void);
uint32_t mock_send_bytes(uint8_t *data, uint32_t length);
void mock_send_String(char* str);
uint32_t mock_get_num_received_bytes(void);
bool mock_get_received_bytes(uint8_t *buf, uint32_t length);
uint8_t mock_get_next_received_byte(void);

#define MAX_LINE_LENGTH   100
#define MAX_PARAMETERS    10
#define ECHO_ENABLED      mock_echo()

#define PROMPT "\r\n $ "
#define WELCOME "\r\nMBSP Command Line Interface\r\n"
#define ERROR_LINE_TOO_LONG "\r\n The command is too long! please try again!\r\n"

typedef bool (*cmd_func_typ)(uint32_t loop);

typedef struct {
    char name[10];
    char help[100];
    cmd_func_typ func;
}cmd_typ;

#endif /* CLI_CLI_CFG_H_ */
