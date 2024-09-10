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

#include "mocks.h"
#include "../src/probe_api/common.h"
#include "../src/probe_api/result.h"
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

void target_monitor_command(uint32_t which, char* command)
{
    (void)command;
    (void)which;
}

bool add_action(action_typ act)
{
	(void)act;
    return true;
}

bool add_action_with_parameter(action_typ act, parameter_typ* parsed_parameter)
{
	(void)act;
	(void)parsed_parameter;
    return true;
}
