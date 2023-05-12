#ifndef CLI_CLI_H_
#define CLI_CLI_H_

#include <stdint.h>
#include <stdbool.h>

void cli_init(void);
void cli_tick(void);
uint8_t* cli_get_parameter(uint32_t parameter_index);

#endif /* CLI_CLI_H_ */
