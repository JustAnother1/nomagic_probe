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
#include <string.h>
#include "probe_api/cli.h"
#include "cli_priv.h"
#include "cfg/cli_cfg.h"
#include "cfg/cli_commands.h"
#include "cfg/serial_cfg.h"
#include "hal/watchdog.h"
#include "probe_api/debug_log.h"
#include "version.h"

#define NUM_COMMANDS  (sizeof(commands)/sizeof(cmd_typ))

static uint8_t line_buffer[MAX_LINE_LENGTH];
static uint32_t line_pos;
static uint32_t parameter_pos;
static uint32_t num_calls;
static bool last_was_n;
static bool last_was_r;
static bool found_end;
static bool still_executing;
static cmd_func_typ cur_func;
static uint8_t* parameters[MAX_PARAMETERS];

static void parse(void);
static void execute(const char* line);


void cli_init(void)
{
    uint32_t i;
    for(i = 0; i < MAX_PARAMETERS; i++)
    {
        parameters[i] = NULL;
    }
    last_was_n = false;
    last_was_r = false;
    line_pos = 0;
    parameter_pos = 0;
    num_calls = 0;
    found_end = false;
    still_executing = false;
    cur_func = NULL;
    cli_welcome();
}

void cli_welcome(void)
{
    uint32_t loop = 0;
    bool res = false;
    cli_msg(WELCOME);
    do{
        res = watchdog_report(loop);
        loop++;
    } while (false == res);
    cli_msg(PROMPT);
}

void cli_tick(void)
{
    uint32_t num_bytes_received;

    // if a command is still executing then do that
    if(true == still_executing)
    {
        if(NULL != cur_func)
        {
            bool done = cur_func(num_calls);
            num_calls++;
            if(false == done)
            {
                return;
            }
        }
        // finished executing the command
        {
        uint32_t i;
        for(i = 0; i < MAX_PARAMETERS; i++)
        {
            parameters[i] = NULL;
        }
        }
        line_pos = 0;
        parameter_pos = 0;
        num_calls = 0;
        found_end = false;
        still_executing = false;
        cur_func = NULL;
        cli_msg(PROMPT);
    }

    // now we can check if new data arrived

    num_bytes_received = serial_debug_get_num_received_bytes();
    if(0 < num_bytes_received)
    {
        uint32_t i;
        for(i = 0; i < num_bytes_received; i++)
        {
            if(line_pos < MAX_LINE_LENGTH)
            {
                uint8_t data = serial_debug_get_next_received_byte();
                if(ECHO_ENABLED)
                {
                    serial_debug_send_bytes(&data, 1);
                }
                // TODO filter out more stuff:
                // up arrow = 0x1B 0x5B 0x41
                if(0x08 == data)
                {
                    // backspace
                    if(line_pos > 0)
                    {
                        line_pos--;
                    }
                }
                else
                {
                    // store the received character
                    line_buffer[line_pos] = data;
                    line_pos++;

                    // was that the end of an command?
                    if(('\r' == data) || ('\n' == data))
                    {
                        parse();
                    }
                }
            }
            else
            {
                cli_msg(ERROR_LINE_TOO_LONG);
                line_pos = 0;
            }
        }
    }
    // else no new bytes -> nothing to do
}

uint8_t* cli_get_parameter(const uint32_t parameter_index)
{
    if(parameter_index < MAX_PARAMETERS)
    {
        return parameters[parameter_index];
    }
    else
    {
        return NULL;
    }
}

static void parse(void)
{
    bool at_start = true;
    uint8_t* line = line_buffer;
    uint32_t i;
    for(i = 0; i < line_pos; i++)
    {
        switch(line_buffer[i])
        {
        case ' ' :  if(false == at_start)
                    {
                        line_buffer[i] = 0;
                        last_was_n = false;
                        last_was_r = false;
                        found_end = true;
                    }
                    else
                    {
                        // white space at beginning -> ignore
                        line = &line_buffer[i + 1];
                    }
                    break;

        case '\r' : line_buffer[i] = 0;
                    if(true == last_was_n)
                    {
                        if(true == last_was_r)
                        {
                            // \r\n\r -> next prompt
                            execute((char*)line);
                            last_was_n = false;
                        }
                        // else no prompt as \n\r
                    }
                    else
                    {
                        execute((char*)line);
                    }
                    last_was_r = true;
                    at_start = false;
                    break;

        case '\n' : line_buffer[i] = 0;
                    if(true == last_was_r)
                    {
                        if(true == last_was_n)
                        {
                            // \r\n\r -> next prompt
                            execute((char*)line);
                            last_was_r = false;
                        }
                        // else no prompt as \r\n
                    }
                    else
                    {
                        execute((char*)line);
                    }
                    last_was_n = true;
                    at_start = false;
                    break;

        default:    last_was_n = false;
                    last_was_r = false;
                    if(true == found_end)
                    {
                        // this is the start of the next parameter
                        if(parameter_pos < MAX_PARAMETERS)
                        {
                            parameters[parameter_pos] = &line_buffer[i];
                        }
                        found_end = false;
                        parameter_pos++;
                    }
                    at_start = false;
                    break;
        }
    }
}

static void execute(const char* line)
{
    uint32_t len = strlen(line);
    if(0 != len)
    {
        uint32_t i;
        bool found = false;
        cli_line("\r\n");
        if(len > (MAX_LINE_LENGTH -1))
        {
            len = MAX_LINE_LENGTH -1;
        }
        for(i = 0; i < NUM_COMMANDS; i++)
        {
            if(len >= strlen(commands[i].name))
            {
                if(0 == strncmp(commands[i].name, line, len))
                {
                    found = true;
                    break;
                }
                // else continue searching
            }
            // else input to short to be this command
        }
        if((false == found) || (i >= NUM_COMMANDS))
        {
            uint8_t* c = (uint8_t*)line;
            cli_msg("Invalid command (%s) [", line);
            while(*c != 0)
            {
                cli_msg(" %02x", *c);
                c++;
            }
            cli_line(" ] type 'help' for list of available commands");
        }
        else
        {
            // found the command
            num_calls = 0;
            if(NULL != commands[i].func)
            {
                bool done = commands[i].func(num_calls);
                if((false == done) && (i < NUM_COMMANDS))
                {
                    num_calls++;
                    still_executing = true;
                    cur_func = commands[i].func;
                    return;
                }
                // else command has finished
            }
            // else ERROR implementation is missing !
        }
    }
    // else user pressed enter twice -> just a new prompt

    // finished executing the command
    {
        uint32_t i;
        for(i = 0; i < MAX_PARAMETERS; i++)
        {
            parameters[i] = NULL;
        }
    }
    line_pos = 0;
    parameter_pos = 0;
    found_end = false;
    still_executing = false;
    cur_func = NULL;
    cli_msg(PROMPT);
}

bool cmd_help(const uint32_t loop)
{
    // help command
    if(0 == loop)
    {
        cli_line("nomagic probe cli version %s", VERSION);
        cli_line("available commands :");
    }
    if(loop < NUM_COMMANDS)
    {
        cli_line("%15s : %s", commands[loop].name, commands[loop].help);
    }
    else
    {
        return true;
    }
    return false;
}

