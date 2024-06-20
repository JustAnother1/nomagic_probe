#include "mocks.h"
#include "../src/probe_api/result.h"
#include "../src/gdbserver/replies.h"
#include "../src/probe_api/time.h"
#include <stdio.h>

uint32_t file_system_start = 50000;

void mock_tick(void)
{
    // nothing to do
}

bool mock_is_connected(void)
{
    return true;
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

bool target_reply_g(void)
{
    return false;
}

bool target_reply_questionmark(void)
{
    return false;
}

bool target_reply_write_g(parameter_typ* parsed_parameter)
{
    (void)parsed_parameter;
    return false;
}

bool target_reply_continue(void)
{
    return false;
}

bool target_reply_read_memory(parameter_typ* parsed_parameter)
{
    (void)parsed_parameter;
    return false;
}

bool target_reply_write_memory(parameter_typ* parsed_parameter)
{
    (void)parsed_parameter;
    return false;
}

bool target_reply_step(parameter_typ* parsed_parameter)
{
    (void)parsed_parameter;
    return false;
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

void start_timeout(timeout_typ* to, const uint32_t time_ms)
{
    (void) to;
    (void) time_ms;
}

bool timeout_expired(timeout_typ* to)
{
    (void) to;
    return false;
}
