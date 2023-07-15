#include "gdbserver.h"
#include "cfg/gdbserver_cfg.h"

#include <stdint.h>
#include <stdbool.h>

#include "commands.h"
#include "util.h"

static uint8_t line_buffer[MAX_LINE_LENGTH];
static uint32_t line_pos;
static uint32_t reply_length;
static uint8_t reply_buffer[MAX_REPLY_LENGTH];


// defines what we have received and have processed
typedef enum parseState {UNKNOWN, IN_PACKET, FOUND_END, CHECKSUM_HIGH, CHECKSUM_LOW} state_typ;


static state_typ state;
static char checksum[2];


void gdbserver_init(void)
{
    state = UNKNOWN;
    line_pos = 0;
    reply_buffer[0] = 0;
    reply_length = 0;
    commands_init();
}

void gdbserver_tick(void)
{
    uint32_t num_bytes_received;

    num_bytes_received = GDBSERVER_NUM_RECEIVED_BYTES();
    while(0 < num_bytes_received)
    {
        uint32_t i;
        for(i = 0; i < num_bytes_received; i++)
        {
            uint8_t data = GDBSERVER_GET_NEXT_RECEIVED_BYTE();
            switch(state)
            {
                case CHECKSUM_LOW:
                case UNKNOWN:
                    // Between packets:
                    if('$' == data)
                    {
                        line_pos = 0;
                        state = IN_PACKET;
                    }
                    else if('+' == data)
                    {
                        // ACK from Host
                        // the last message was successfully received by the host -> nothing to do here
                    }
                    else if('-' == data)
                    {
                        // Transmit error
                        // -> Resent last message
                        GDBSERVER_SEND_BYTES(reply_buffer, reply_length);
                    }
                    else if(0x03 == data)
                    {
                        // BREAK
                        // TODO
                    }
                    else
                    {
                        if(0 != data)
                        {
                            DEBUG_LOG("skipping %s(0x%02x) !\n", (char*)&data, data);
                        }
                    }
                    break;

                case IN_PACKET:
                    if('#' != data)
                    {
                        if(line_pos < (MAX_LINE_LENGTH-1))
                        {
                            line_buffer[line_pos] = data;
                            line_pos++;
                        }
                        else
                        {
                            send_error_packet();
                            line_pos = 0;
                            state = UNKNOWN;
                        }
                    }
                    else
                    {
                        state = FOUND_END;
                    }
                    break;

                case FOUND_END:
                    checksum[0] = data;
                    state = CHECKSUM_HIGH;
                    break;

                case CHECKSUM_HIGH:
                    checksum[1] = data;
                    state = CHECKSUM_LOW;
                    line_buffer[line_pos] = 0;
                    commands_execute((char*)line_buffer, line_pos, (char*)checksum);
                    break;
            }
        }
        num_bytes_received = GDBSERVER_NUM_RECEIVED_BYTES();
    }
    // else no new bytes -> nothing to do
}

void reply_packet_prepare(void)
{
    reply_buffer[0] = '$';
    reply_length = 1;
}

void reply_packet_add(char* data)
{
    uint32_t i;
    uint32_t length = strlen(data);
    for(i = 0; i < length; i++)
    {
        reply_buffer[reply_length+i] = (uint8_t)data[i];
    }
    reply_length = reply_length + length;
}

void reply_packet_send(void)
{
    uint32_t sum;
    char reply_checksum[2];

    sum = calculateChecksum((char*)&reply_buffer[1], reply_length -1);  // checksum does not include the '$'
    int_to_hex(reply_checksum, sum, 2);
    reply_buffer[reply_length] = '#';
    reply_buffer[reply_length + 1] = (uint8_t)reply_checksum[1]; // high nibble
    reply_buffer[reply_length + 2] = (uint8_t)reply_checksum[0]; // low nibble

    GDBSERVER_SEND_BYTES(reply_buffer, reply_length + 3);
}

void send_error_packet(void)
{
    GDBSERVER_SEND_STRING("-");
}

void send_ack_packet(void)
{
    GDBSERVER_SEND_STRING("+");
}

void send_unknown_command_reply(void)
{
    reply_packet_prepare();
    reply_packet_send();
}


