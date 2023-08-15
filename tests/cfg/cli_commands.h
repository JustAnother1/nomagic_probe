#ifndef CLI_CLI_COMMANDS_H_
#define CLI_CLI_COMMANDS_H_

#include "cli_cfg.h"

cmd_typ commands[] = {
        //         11             1         2         3         4         5         6
        //12345678901    123456789012345678901234567890123456789012345678901234567890
        {"help",        "list all available commands", cmd_help},
        {"time",        "time since power on", NULL},
        {"test",        "test command", NULL},
};


#endif /* CLI_CLI_COMMANDS_H_ */
