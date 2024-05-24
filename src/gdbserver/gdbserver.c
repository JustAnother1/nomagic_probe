/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include "gdbserver.h"
#include "cfg/gdbserver_cfg.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/debug_log.h"
#include "probe_api/result.h"
#include "probe_api/common.h"
#include "commands.h"
#include "util.h"
#include "probe_api/time.h"

#define GDB_BUSY_TIMEOUT_MS      1000

// defines what we have received and have processed
typedef enum parseState {
    UNKNOWN,
    IN_PACKET,
    FOUND_END,
    CHECKSUM_HIGH,
    CHECKSUM_LOW
} state_typ;

static void communicate_with_gdb(void);

static uint8_t line_buffer[MAX_COMMAND_LENGTH];
static uint32_t line_pos;
static uint32_t reply_length;
static uint8_t reply_buffer[MAX_REPLY_LENGTH];
static uint32_t sum;
static state_typ state;
static char checksum[2];
static bool connected;
static bool connection_failed;
static uint32_t retry_counter;
static bool busy_processing_cmd;
static timeout_typ busy_to;


void gdbserver_init(void)
{
    state = UNKNOWN;
    line_pos = 0;
    reply_buffer[0] = 0;
    reply_length = 0;
    connection_failed = false;
    retry_counter = 0;
    connected = false;
    busy_processing_cmd = false;
    commands_init();
}

void gdbserver_tick(void)
{
    if(GDBSERVER_IS_CONNECTED)
    {
        if(false == connected)
        {
            target_connect();
            connected = true;
        }
        communicate_with_gdb();
    }
    else
    {
        if(true == connected)
        {
            target_close_connection();
            connected = false;
        }
    }
}

void reply_packet_prepare(void)
{
    reply_buffer[0] = '$';
    reply_length = 1;
    sum = 0;  // checksum does not include the '$'
    GDBSERVER_SEND_BYTES(reply_buffer, 1);
}

void reply_packet_add(char* data)
{
    uint32_t length = 0;
    while((0 != *data) && (reply_length + length < MAX_REPLY_LENGTH))
    {
        reply_buffer[reply_length + length] = (uint8_t)(*data);
        sum = sum + (uint8_t)(*data);
        length++;
        data++;
    }
    GDBSERVER_SEND_BYTES(&(reply_buffer[reply_length]), length);
    reply_length = reply_length + length;
}

void reply_packet_add_max(char* data, uint32_t length)
{
    uint32_t i;
    memcpy(&(reply_buffer[reply_length]), data, length);
    GDBSERVER_SEND_BYTES(&(reply_buffer[reply_length]), length);
    for(i = 0; i < length; i++)
    {
        sum = sum + (uint8_t)(*data);
        data++;
    }
    reply_length = reply_length + length;
}

void reply_packet_add_hex(uint32_t data, uint32_t digits)
{
    uint32_t i;
    uint32_t report;  // report this many digits
    bool shorten = false; // do not send leading zeros if this is true

    char buf[8];
    if((1 > digits) || (8 < digits))
    {
        // invalid digits value or shorten mode request
        digits = 8;
        shorten = true;
    }
    int_to_hex(buf, data, digits);  // returns value in lsb sequence
    report = digits;
    if(true == shorten)
    {
        // count the number of leading digits
        for(i = 0; i < digits; i++)
        {
            if('0' == buf[digits -1 -i])
            {
                report--;
            }
            else
            {
                break;
            }
        }
    }
    for(i = 0; i < report; i++)
    {
        reply_buffer[reply_length + i] = (uint8_t)(buf[(report - 1) -i]);
        sum = sum + (uint8_t)(buf[(report - 1) -i]);
        GDBSERVER_SEND_BYTES(&(reply_buffer[reply_length + i]), 1);
    }
    reply_length = reply_length + report;
}

void reply_packet_send(void)
{
    char reply_checksum[2];
    // sum = calculateChecksum((char*)&reply_buffer[1], reply_length -1);  // checksum does not include the '$'
    sum = sum & 0xff;
    int_to_hex(reply_checksum, sum, 2);
    if(reply_length + 4 > MAX_REPLY_LENGTH)
    {
        // should never happen -> if it happens increase the MAX_REPLY_LENGTH
        reply_length = MAX_REPLY_LENGTH - 4;
        debug_line("ERROR: reply too long !");
    }
    reply_buffer[reply_length] = '#';
    reply_buffer[reply_length + 1] = (uint8_t)reply_checksum[1]; // high nibble
    reply_buffer[reply_length + 2] = (uint8_t)reply_checksum[0]; // low nibble
    reply_buffer[reply_length + 3]  = 0;
    debug_line("gdbs sending: %s", reply_buffer);
    GDBSERVER_SEND_BYTES(&(reply_buffer[reply_length]), 3);
    gdb_is_not_busy_anymore();
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

void send_part(char* part, uint32_t size, uint32_t offset, uint32_t length)
{
    reply_packet_prepare();
    if(offset + length < size)
    {
        reply_packet_add("m");
    }
    else
    {
        reply_packet_add("l");
    }
    if(offset > size)
    {
        // offset invalid
        reply_packet_prepare();
        reply_packet_add("E 01");
        reply_packet_send();
        return;
    }
    if(offset + length > size)
    {
        length = size - offset;
    }
    reply_packet_add_max(&part[offset], length);
    reply_packet_send();
}

void gdb_is_now_busy(void)
{
    busy_processing_cmd = true;
    start_timeout(&busy_to, GDB_BUSY_TIMEOUT_MS);
}

void gdb_is_not_busy_anymore(void)
{
    busy_processing_cmd = false;
}

static void communicate_with_gdb(void)
{
    uint32_t num_bytes_received;
    if(true == busy_processing_cmd)
    {
        // we are still processing the last command
        // reading the next command does not make sense
        // there will probably be no next command yet
        // and if there were we would not be ready to work on it
        if(true == timeout_expired(&busy_to))
        {
            debug_line("ERROR: timeout !");
            gdb_is_not_busy_anymore();
        }
        return;
    }

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
                    else if('%' == data)
                    {
                        // notification from Host
                        // -> ignore
                        debug_line("ERROR: not implemented !");
                        // TODO Notification is "% data # checksum"
                    }
                    else if('+' == data)
                    {
                        // ACK from Host
                        // the last message was successfully received by the host -> forget what we send last time
                        reply_length = 0;
                    }
                    else if('-' == data)
                    {
                        // host is not happy with what we send -> probably some error on our side
                        // data from last command is still valid -> retry doing it
                        line_buffer[line_pos] = '\0';
                        commands_execute((char*)line_buffer, line_pos, (char*)checksum);
                        /*
                        // Transmit error
                        // -> Resent last message
                        debug_line("resending: %s", reply_buffer);
                        GDBSERVER_SEND_BYTES(reply_buffer, reply_length);
                        */
                    }
                    else if(0x03 == data)
                    {
                        // BREAK
                        // TODO
                        debug_line("ERROR: not implemented !");
                    }
                    else
                    {
                        if(0 != data)
                        {
                            if((32 > data) || (126 < data))
                            {
                                debug_line("skipping 0x%02x !", data);
                            }
                            else
                            {
                                debug_line("skipping %s(0x%02x) !", (char*)&data, data);
                            }
                        }
                    }
                    break;

                case IN_PACKET:
                    if('#' != data)
                    {
                        if(line_pos < (MAX_COMMAND_LENGTH - 1))
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
