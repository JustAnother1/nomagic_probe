#include "cli.h"
#include "cli_cfg.h"
#include "cli_commands.h"
#include <stdint.h>
#include <string.h>

static uint8_t line_buffer[MAX_LINE_LENGTH];
static uint32_t line_pos;
static uint32_t parse_pos;
static uint32_t parameter_pos;
static bool last_was_n;
static bool last_was_r;
static bool found_end;
static bool still_executing;
static cmd_func_typ cur_func;
static char* parameters[MAX_PARAMETERS];

static void parse(void);
static void execute(void);


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
    parse_pos = 0;
    parameter_pos = 0;
    found_end = false;
    still_executing = false;
    cur_func = NULL;
    SERIAL_SEND_STRING(WELCOME);
    SERIAL_SEND_STRING(PROMPT);
}

void cli_tick(void)
{
    uint32_t num_bytes_received;
    // if a command is still executing then do that
    if(true == still_executing)
    {
        if(NULL != cur_func)
        {
            bool done = cur_func();
            if(false == done)
            {
                return;
            }
        }
        // finished executing the command
        line_pos = 0;
        parse_pos = 0;
        parameter_pos = 0;
        found_end = false;
        still_executing = false;
        cur_func = NULL;
        SERIAL_SEND_STRING(PROMPT);
    }

    // now we can check if new data arrived
    num_bytes_received = SERIAL_NUM_RECEIVED_BYTES();
    if(0 < num_bytes_received)
    {
        uint32_t i;
        for(i = 0; i < num_bytes_received; i++)
        {
            if(line_pos < MAX_LINE_LENGTH)
            {
                uint8_t data = SERIAL_GET_NEXT_RECEIVED_BYTE();
                if(ECHO_ENABLED)
                {
                    SERIAL_SEND_BYTES(&data, 1);
                }
                line_buffer[line_pos] = data;
                line_pos++;
                if(('\r' == data) || ('\n' == data))
                {
                    parse();
                }
            }
            else
            {
                SERIAL_SEND_STRING(ERROR_LINE_TOO_LONG);
                line_pos = 0;
            }
        }
    }
    // else no new bytes -> nothing to do
}

char* cli_get_parameter(uint32_t parameter_index)
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

static void parse()
{
    uint32_t i;
    for(i = parse_pos; i < line_pos; i++)
    {
        switch(line_buffer[i])
        {
        case ' ' :  line_buffer[i] = 0;
                    last_was_n = false;
                    last_was_r = false;
                    found_end = true;
                    break;

        case '\r' : line_buffer[i] = 0;
                    if(true == last_was_n)
                    {
                        if(true == last_was_r)
                        {
                            // \r\n\r -> next prompt
                            execute();
                            last_was_n = false;
                        }
                        // else no prompt as \n\r
                    }
                    else
                    {
                        execute();
                    }
                    last_was_r = true;
                    break;

        case '\n' : line_buffer[i] = 0;
                    if(true == last_was_r)
                    {
                        if(true == last_was_n)
                        {
                            // \r\n\r -> next prompt
                            execute();
                            last_was_r = false;
                        }
                        // else no prompt as \r\n
                    }
                    else
                    {
                        execute();
                    }
                    last_was_n = true;
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
                    break;
        }
    }
}

static void execute(void)
{
    if(0 != strlen(line_buffer))
    {
        if(0 == strcmp("help", line_buffer))
        {
            // help command
            uint32_t i;
            SERIAL_SEND_STRING("\r\navailable commands :\r\n");
            for(i = 0; i < sizeof(commands)/sizeof(cmd_typ); i++)
            {
                SERIAL_SEND_STRING(commands[i].name);
                SERIAL_SEND_STRING(" : ");
                SERIAL_SEND_STRING(commands[i].help);
                SERIAL_SEND_STRING("\r\n");
            }
        }
        else
        {
            uint32_t i;
            bool found = false;
            for(i = 0; i < sizeof(commands)/sizeof(cmd_typ); i++)
            {
                if(0 == strcmp(commands[i].name, line_buffer))
                {
                    found = true;
                    break;
                }
                // else continue searching
            }
            if(false == found)
            {
                SERIAL_SEND_STRING("\r\nInvalid command (");
                SERIAL_SEND_STRING(line_buffer);
                SERIAL_SEND_STRING(") type 'help' for list of available commands.\r\n");
            }
            else
            {
                // found the command
                if(NULL != commands[i].func)
                {
                    bool done = commands[i].func();
                    if(false == done)
                    {
                        still_executing = true;
                        cur_func = commands[i].func;
                        return;
                    }
                    // else command has finished
                }
                // else ERROR implementation is missing !
            }
        }
    }
    // else user pressed enter twice -> just a new prompt

    // finished executing the command
    line_pos = 0;
    parse_pos = 0;
    parameter_pos = 0;
    found_end = false;
    still_executing = false;
    cur_func = NULL;
    SERIAL_SEND_STRING(PROMPT);
}


