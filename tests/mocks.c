#include "mocks.h"
#include "../src/probe_api/result.h"
#include "../src/target_api/target_actions.h"
#include <stdio.h>

uint8_t recv_buf[TST_RECEIVE_BUFFER_SIZE];
uint8_t send_buf[TST_SEND_BUFFER_SIZE];
uint32_t recv_read_pos;
uint32_t recv_write_pos;
uint32_t send_read_pos;
uint32_t send_write_pos;

uint32_t file_system_start = 50000;

bool echo_enabled;

void mock_tick(void)
{
    // nothing to do
}


void reset_send_receive_buffers(void)
{
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;
    memset(recv_buf, 0, TST_RECEIVE_BUFFER_SIZE);
    memset(send_buf, 0, TST_SEND_BUFFER_SIZE);
}

bool mock_echo(void)
{
    return echo_enabled;
}

void set_echo_enabled(bool val)
{
    echo_enabled = val;
}

uint32_t get_num_bytes_in_recv_buffer(void)
{
    if(recv_write_pos == recv_read_pos)
    {
        return 0;
    }
    else if(recv_write_pos > recv_read_pos)
    {
        return recv_write_pos - recv_read_pos;
    }
    else
    {
        return recv_write_pos + (TST_RECEIVE_BUFFER_SIZE - recv_read_pos);
    }
}

uint32_t get_num_bytes_in_send_buffer(void)
{
    if(send_write_pos == send_read_pos)
    {
        return 0;
    }
    else if(send_write_pos > send_read_pos)
    {
        return send_write_pos - send_read_pos;
    }
    else
    {
        return send_write_pos + (TST_RECEIVE_BUFFER_SIZE - send_read_pos);
    }
}


uint32_t mock_send_bytes(uint8_t *data, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (TST_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = data[i];
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
    return i;
}

void mock_send_String(char* str)
{
    while(*str != 0) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (TST_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = *str;
            str++;
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

uint8_t mock_get_next_received_byte(void) {
    uint8_t res;
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    res = recv_buf[recv_read_pos];
    recv_read_pos++;
    if(TST_RECEIVE_BUFFER_SIZE == recv_read_pos) {
        recv_read_pos = 0;
    }
    return res;
}

uint32_t mock_get_num_received_bytes(void)
{
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    if (recv_read_pos < recv_write_pos) {
        return recv_write_pos - recv_read_pos;
    } else {
        // wrap around
        return(TST_RECEIVE_BUFFER_SIZE - recv_read_pos) + recv_write_pos;
    }
}

bool mock_get_received_bytes(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    if (length < mock_get_num_received_bytes()) {
        return false;
    }
    for (i = 0; i < length; i++) {
        buf[i] = mock_get_next_received_byte();
    }
    return true;
}

void send_bytes_to_cli(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = recv_write_pos;
        next_write++;
        if (TST_SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != recv_read_pos) {
            recv_buf[recv_write_pos] = buf[i];
            recv_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
}

bool mock_is_connected(void)
{
    return true;
}

void debug_putc(void* p, char c)
{
    (void) p; // not used
    mock_send_bytes((uint8_t *)&c, 1);
}

void div_and_mod(uint32_t divident, uint32_t divisor, uint32_t* quotient, uint32_t* remainder)
{
    *remainder = divident%divisor;
    *quotient = divident/divisor;
}

bool tud_msc_set_sense(uint8_t lun, uint8_t sense_key, uint8_t add_sense_code, uint8_t add_sense_qualifier)
{
  (void) lun;
  (void) sense_key;
  (void) add_sense_code;
  (void) add_sense_qualifier;
  return true;
}

bool watchdog_report(uint32_t loop)
{
    (void) loop;
    // nothing to do here
    return true;
}

void watchdog_feed(void)
{
    // nothing to do here
}

uint32_t file_storage_get_block_count(void)
{
    return 12;
}
uint16_t file_storage_getblock_size(void)
{
    return 512;
}

int32_t  file_storage_read(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;

    return -1;
}
int32_t  file_storage_write(uint32_t block, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    (void)block;
    (void)offset;
    (void)buffer;
    (void)bufsize;

    return -1;
}

void target_init(void)
{
    // nothing to do here
}
void target_connect(void)
{

}

void target_close_connection(void)
{

}

void target_reply_g(void)
{
    // nothing to do here
}

void target_reply_questionmark(void)
{

}

void target_reply_write_g(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
}

void target_reply_continue(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
}

void target_reply_read_memory(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
}

void target_reply_write_memory(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
}

void target_reply_step(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
}

void debug_line(const char *fmt, ...)
{
    (void) fmt;
    // nothing to do here
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void) filename;
    (void) offset;
    (void) len;
    /*
    reply_packet_prepare();
    reply_packet_add("E00");
    reply_packet_send();
    */
}

void dump_buffer_ascii(char* buffer, uint32_t length)
{
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        switch(buffer[i])
        {
        case '\r': printf("\\r"); break;
        case '\n': printf("\\n\n"); break;
        default: printf("%c", buffer[i]); break;
        }
    }
}
