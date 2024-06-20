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

#ifndef COMMON_H_
#define COMMON_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"
#include "gdbserver/replies.h"
#include "cfg/target_specific_actions.h"

#define MAX_INTERN_VALUES     4
#define MAX_PARAMETER_VALUES  3

typedef enum {
    NOT_CONNECTED,     // No SWD communication, target MCU might not be present at all
    CONNECTING,        // SWD starts communication, transitional state,
                       // should not take long to either go to connected
                       // or fail and go back to not connected
    CONNECTED_HALTED,  // SWD communication active, MCU is not running / no code execution.
    CONNECTED_RUNNING, // SWD communication active, MCU is running / executing code.
    // new status go here
    NUM_TARGET_STATUS, // <- do not use other than array size !
}target_status_typ;

typedef enum {
    SWD_CONNECT,
    SWD_CLOSE_CONNECTION,
#ifdef FEAT_GDB_SERVER
    GDB_CMD_G,
    GDB_CMD_QUESTIONMARK,
    GDB_CMD_WRITE_G,
    GDB_CMD_CONTINUE,
    GDB_CMD_READ_MEMORY,
    GDB_CMD_WRITE_MEMORY,
    GDB_CMD_STEP,
    CHECK_RUNNING,
#endif
    TARGET_SPECIFIC_ACTIONS_ENUM
    // new actions go here
    NUM_ACTIONS,  // <- do not use other than array size !
}action_typ;

typedef struct{
    uint32_t parameter[MAX_PARAMETER_VALUES];
    parameter_typ* gdb_parameter;
    uint32_t* cur_phase;
    uint32_t main_phase;
    uint32_t sub_phase;
    uint32_t intern[MAX_INTERN_VALUES];
    Result result;
    uint32_t read_0;
    action_typ action;
    bool can_run;
    bool is_done;
} action_data_typ;


typedef Result (*action_handler)(action_data_typ * const action, bool first_call);

action_data_typ * book_action_slot(void);
Result add_target_action(action_data_typ * const action);
void target_connect(void);
void target_close_connection(void);

void target_set_status(target_status_typ new_status);
bool common_cmd_target_info(uint32_t loop);


#endif /* COMMON_H_ */
