#ifndef CLI_CLI_COMMANDS_H_
#define CLI_CLI_COMMANDS_H_

#include "cli_cfg.h"
#include "cli/cli_sys.h"

cmd_typ commands[] = {
        {"time", "time since power on", cmd_time},
};


#endif /* CLI_CLI_COMMANDS_H_ */
