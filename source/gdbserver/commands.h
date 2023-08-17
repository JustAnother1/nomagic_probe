#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdint.h>
#include <stdbool.h>

void commands_init(void);
void commands_execute(char* received, uint32_t length, char* checksum);

#endif /* COMMANDS_H_ */
