#ifndef GDBSERVER_CFG_H_
#define GDBSERVER_CFG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH    500
#define MAX_REPLY_LENGTH      1000

#define GDBSERVER_SEND_STRING            mock_send_String
#define GDBSERVER_SEND_BYTES             mock_send_bytes
#define GDBSERVER_NUM_RECEIVED_BYTES     mock_get_num_received_bytes
#define GDBSERVER_GET_NEXT_RECEIVED_BYTE mock_get_next_received_byte

#endif /* GDBSERVER_CFG_H_ */
