#ifndef GDBSERVER_CFG_H_
#define GDBSERVER_CFG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hal/debug_uart.h"
#include "tinyusb/usb_cdc.h"

#define MAX_LINE_LENGTH    500
#define MAX_REPLY_LENGTH   100

#define DEBUG_LOG                        debug_msg
#define GDBSERVER_SEND_STRING            usb_cdc_send_string
#define GDBSERVER_SEND_BYTES             usb_cdc_send_bytes
#define GDBSERVER_NUM_RECEIVED_BYTES     usb_cdc_get_num_received_bytes
#define GDBSERVER_GET_NEXT_RECEIVED_BYTE usb_cdc_get_next_received_byte

#endif /* GDBSERVER_CFG_H_ */
