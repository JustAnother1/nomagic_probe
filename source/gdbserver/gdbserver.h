#ifndef GDBSERVER_H_
#define GDBSERVER_H_

#include <stdint.h>
#include <stdbool.h>

void gdbserver_init(void);
void gdbserver_tick(void);

void reply_packet_prepare(void);
void reply_packet_add(char* data);
void reply_packet_send(void);
void send_error_packet(void);
void send_ack_packet(void);
void send_unknown_command_reply(void);

#endif /* GDBSERVER_H_ */
