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
#include "cfg/serial_cfg.h"
#include "commands.h"
#include "gdbserver.h"
#include "probe_api/common.h"
#include "probe_api/debug_log.h"
#include "probe_api/gdb_error_codes.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/result.h"
#include "probe_api/time.h"
#include "probe_api/util.h"


#define GDB_BUSY_TIMEOUT_MS      5000
#define CLEAN_END_LENGTH         10

// defines what we have received and have processed
typedef enum parseState {
    UNKNOWN,
    IN_PACKET,
    FOUND_END,
    CHECKSUM_HIGH,
    CHECKSUM_LOW
} state_typ;

static void communicate_with_gdb(void);
static void add_clean_end(void);

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
    if(true == serial_gdb_is_connected())
    {
        if(false == connected)
        {
            gdbserver_connect();
        }
        communicate_with_gdb();
    }
    else
    {
        if(true == connected)
        {
            gdbserver_disconnect();
        }
    }
}

void gdbserver_connect(void)
{
    target_connect();
    connected = true;
}

void gdbserver_disconnect(void)
{
    target_close_connection();
    connected = false;
    // reset settings from this session so that next session is the same as the first session
    commands_init();
}


void reply_packet_prepare(void)
{
    reply_buffer[0] = '$';
    reply_length = 1;
    sum = 0;  // checksum does not include the '$'
    serial_gdb_send_bytes(reply_buffer, 1);
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
    if( ! (reply_length + length < MAX_REPLY_LENGTH))
    {
        debug_error("ERROR: add: reply too long !");
    }
    serial_gdb_send_bytes(&(reply_buffer[reply_length]), length);
    reply_length = reply_length + length;
}

void reply_packet_add_max(char* data, uint32_t length)
{
    uint32_t i;

    if(reply_length + length < MAX_REPLY_LENGTH)
    {
        memcpy(&(reply_buffer[reply_length]), data, length);
        serial_gdb_send_bytes(&(reply_buffer[reply_length]), length);
        for(i = 0; i < length; i++)
        {
            sum = sum + (uint8_t)(*data);
            data++;
        }
        reply_length = reply_length + length;
    }
    else
    {
        debug_error("ERROR: add max: reply too long !");
    }
}

bool reply_packet_add_hex(uint32_t data, uint32_t digits)
{
    uint32_t i;
    uint32_t report;  // report this many digits
    bool shorten = false; // do not send leading zeros if this is true

    char buf[8];
    if((1 > digits) || (8 < digits))
    {
        // invalid digits value or shorten mode request
        digits = 2;
        if(0xff < data)
        {
            digits = 4;
        }
        if(0xffff < data)
        {
            digits = 6;
        }
        if(0xffffff < data)
        {
            digits = 8;
        }
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
    if(reply_length + report < MAX_REPLY_LENGTH)
    {
        for(i = 0; i < report; i++)
        {
            reply_buffer[reply_length + i] = (uint8_t)(buf[(report - 1) -i]);
            sum = sum + (uint8_t)(buf[(report - 1) -i]);
            serial_gdb_send_bytes(&(reply_buffer[reply_length + i]), 1);
        }
        reply_length = reply_length + report;
        return true;
    }
    else
    {
        debug_line("ERROR: add hex: reply too long !");
        return false;
    }
}

void reply_packet_send(void)
{
    char reply_checksum[2];
    // sum = calculateChecksum((char*)&reply_buffer[1], reply_length -1);  // checksum does not include the '$'
    sum = sum & 0xff;
    byte_to_hex(reply_checksum, sum);
    if(reply_length + 4 > MAX_REPLY_LENGTH)
    {
        // should never happen -> if it happens increase the MAX_REPLY_LENGTH
        reply_length = MAX_REPLY_LENGTH - 4;
        debug_error("ERROR: reply too long !");
    }
    reply_buffer[reply_length] = '#';
    reply_buffer[reply_length + 1] = (uint8_t)reply_checksum[0]; // high nibble
    reply_buffer[reply_length + 2] = (uint8_t)reply_checksum[1]; // low nibble
    reply_buffer[reply_length + 3]  = 0;

    if(reply_length < 50)
    {
        debug_line("gdbs sending: %s", reply_buffer);
    }
    else
    {
        char buf[30];
        memcpy(buf, reply_buffer, sizeof(buf));
        binary_to_ascii_dump(buf, sizeof(buf));
        buf[29] = 0;
        debug_line("gdbs sending: %s ... (something really long)", buf);
    }
    serial_gdb_send_bytes(&(reply_buffer[reply_length]), 3);
    serial_gdb_flush();
}

void send_error_packet(void)
{
    serial_gdb_send_string("-");
}

void send_ack_packet(void)
{
    serial_gdb_send_string("+");
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
        reply_packet_add(ERROR_CODE_WRONG_OFFSET);
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

bool is_gdb_busy(void)
{
    return busy_processing_cmd;
}

bool gdbs_info(const uint32_t loop)
{
    switch(loop)
    {
    case 0:
        if(true == busy_processing_cmd)
        {
            cli_line("gdb-server is busy !");
        }
        else
        {
            cli_line("gdb-server is not busy.");
        }
        break;

    case 1:
        if(true == connected)
        {
            cli_line("gdb-server is connected to gdb.");
        }
        else
        {
            cli_line("gdb-server is not connected.");
        }
        break;

    case 2:
        switch(state)
        {
        default:
        case UNKNOWN:       cli_line("state is unknown.");        break;
        case IN_PACKET:     cli_line("state is 'in packet'.");    break;
        case FOUND_END:     cli_line("state is 'found end'.");    break;
        case CHECKSUM_HIGH: cli_line("state is checksum(high)."); break;
        case CHECKSUM_LOW:  cli_line("state is checksum(low).");  break;
        }
        break;

    case 3:
        cli_line("line_pos : %ld", line_pos);
        break;

    case 4:
        cli_line("reply_length : %ld", reply_length);
        break;

    case 5:
    {
        uint32_t i;
        uint32_t max = 40;
        if(reply_length < max)
        {
            max = reply_length;
        }
        cli_msg("reply_buffer[");
        for(i = 0; i < max; i++)
        {
            cli_msg(" %02x", reply_buffer[i]);
        }
        cli_line(" ]");
    }
        break;

    case 6:
    {
        uint32_t i;
        uint32_t max = 40;
        if(line_pos < max)
        {
            max = line_pos;
        }
        cli_msg("line_buffer[");
        for(i = 0; i < max; i++)
        {
            if((line_buffer[i] > 31) && (line_buffer[i] < 127))
            {
                cli_msg(" %2c", line_buffer[i]);
            }
            else
            {
                cli_msg(" %02x", line_buffer[i]);
            }
        }
        cli_line(" ]");
    }
        break;

    default: return true;// we are done
    }
    return false;
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
            debug_error("ERROR: gdb-server command timeout !");
            gdb_is_not_busy_anymore();
        }
        return;
    }

    num_bytes_received = serial_gdb_get_num_received_bytes();

    while(0 < num_bytes_received)
    {
        uint32_t i;
        // debug_line("gdb-server received %ld bytes !", num_bytes_received);
        for(i = 0; i < num_bytes_received; i++)
        {
            uint8_t data = serial_gdb_get_next_received_byte();
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
                        debug_error("ERROR: notification not implemented !");
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
                        add_clean_end();
                        commands_execute((char*)line_buffer, line_pos, (char*)checksum);
                        /*
                        // Transmit error
                        // -> Resent last message
                        debug_line("resending: %s", reply_buffer);
                        serial_gdb_send_bytes(reply_buffer, reply_length);
                        serial_gdb_flush();
                        */
                    }
                    else if(0x03 == data)
                    {
                        // BREAK
                        // is optional. Application is the GDB user pressed CTRL-C.
                        debug_error("INFO: break not implemented !");
                    }
                    else
                    {
                        if(0 != data)
                        {
                            if((32 > data) || (126 < data))
                            {
                                debug_error("skipping 0x%02x !", data);
                            }
                            else
                            {
                                debug_error("skipping %s(0x%02x) !", (char*)&data, data);
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
                    add_clean_end();
                    commands_execute((char*)line_buffer, line_pos, (char*)checksum);
                    break;
            }
        }
        num_bytes_received = serial_gdb_get_num_received_bytes();
    }
    // else no new bytes -> nothing to do
}

static void add_clean_end(void)
{
    // line_buffer[line_pos] = 0;    <- single 0 might not be enough if skipped in parsing
    uint32_t i;
    uint32_t len = CLEAN_END_LENGTH;
    if(line_pos + CLEAN_END_LENGTH >= MAX_COMMAND_LENGTH)
    {
        len = MAX_COMMAND_LENGTH - line_pos;
    }

    for(i = 0; i < len; i++)
    {
        line_buffer[line_pos + i] = 0;
    }
}
