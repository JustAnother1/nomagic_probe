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

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "threads.h"
#include "probe_api/gdb_error_codes.h"
#include "probe_api/gdb_packets.h"

typedef enum threadOperationEnum {
    LC_C,
    UC_C,
    LC_G,
    UC_G,
    LC_M,
    UC_M,
    NUM_OPERATIONS
} threadOperationEnum_typ;

int32_t active_thread_for_operation[NUM_OPERATIONS];

void threads_init(void)
{
    uint32_t i;
    for(i = 0; i < NUM_OPERATIONS; i++)
    {
        active_thread_for_operation[i] = 1;
    }
}

void handle_H_command(char* command)
{
    char operation;
    char * thread_id_str;
    // command is something like "Hg0"
    if(NULL == command)
    {
        return;
    }
    command ++;
    operation = *command;
    command ++;
    thread_id_str = command; // possible values are "-1", "0", "1",...
    reply_packet_prepare();
    switch(operation)
    {
    case 'c': active_thread_for_operation[LC_C] = atoi(thread_id_str); break;
    case 'C': active_thread_for_operation[UC_C] = atoi(thread_id_str); break;
    case 'g': active_thread_for_operation[LC_G] = atoi(thread_id_str); break;
    case 'G': active_thread_for_operation[UC_G] = atoi(thread_id_str); break;
    case 'm': active_thread_for_operation[LC_M] = atoi(thread_id_str); break;
    case 'M': active_thread_for_operation[UC_M] = atoi(thread_id_str); break;
    default: // error
        reply_packet_add(ERROR_CODE_INVALID_THREAD_OPERATION);
        reply_packet_send();
        break;
    }
    // was ok
    reply_packet_add("OK");
    reply_packet_send();
}

void handle_qfThreadInfo_command(char* command)
{
    (void) command;
    reply_packet_prepare();
    reply_packet_add("m1"); // bare metal -> only one thread; OS thread aware -> possibly more threads
    reply_packet_send();
}

void handle_qsThreadInfo_command(char* command)
{
    (void) command;
    reply_packet_prepare();
    reply_packet_add("l"); // l = end of list
    reply_packet_send();
}

void handle_qC_command(char* command)
{
    (void) command;
    reply_packet_prepare();
    reply_packet_add("QC1");
    reply_packet_send();
}
