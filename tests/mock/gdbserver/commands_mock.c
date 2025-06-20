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
#include "gdbserver/commands.h"
#include "commands_mock.h"
#include "cfg/serial_cfg.h"

#define MAX_NUM_COMMANDS   10

static uint32_t num_calls[NUM_COMMANDS_CALL_COUNTER];

static uint32_t cmd_idx;
static char commands[MAX_NUM_COMMANDS][MAX_COMMAND_LENGTH + 5];
static uint32_t cmd_lengths[MAX_NUM_COMMANDS];

config_typ gdb_cfg;

void mock_commands_reset_call_counts(void)
{
    uint32_t i;
    for(i = 0; i < NUM_COMMANDS_CALL_COUNTER; i++)
    {
        num_calls[i] = 0;
    }
}

uint32_t mock_commands_get_call_counter_of(uint32_t idx)
{
    return num_calls[idx];
}

void mock_commands_reset_commands(void)
{
    memset(commands, 0, sizeof(commands));
    cmd_idx = 0;
}

uint32_t mock_commands_get_num_received_commands(void)
{
    return cmd_idx;
}

char* mock_commands_get_command(uint32_t idx)
{
    return &commands[idx][0];
}

uint32_t mock_commands_get_length(uint32_t idx)
{
    return cmd_lengths[idx];
}



void commands_init(void)
{
    num_calls[CALL_IDX_COMMANDS_INIT]++;
}

void commands_execute(char* received, uint32_t length)
{
    num_calls[CALL_IDX_COMMANDS_EXECUTE]++;
    cmd_lengths[cmd_idx] = length;
    if(NULL == received)
    {
        commands[cmd_idx][0] = 'N';
    }
    else
    {
        for(uint32_t i = 0; i < length; i++)
        {
            commands[cmd_idx][i] = *received;
            received++;
        }
    }
    cmd_idx++;
}
