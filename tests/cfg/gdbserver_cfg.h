#ifndef GDBSERVER_CFG_H_
#define GDBSERVER_CFG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH    500
#define MAX_REPLY_LENGTH      1000


bool mock_is_connected(void);

#endif /* GDBSERVER_CFG_H_ */
