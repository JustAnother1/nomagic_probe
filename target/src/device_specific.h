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

#ifndef DEVICE_SPECIFIC_H_
#define DEVICE_SPECIFIC_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"
#include "nomagic/walk.h"
#include "target_actions.h"

typedef enum {
    SWD_CONNECT,
    SWD_CLOSE_CONNECTION,
    GDB_CMD_G,
    GDB_CMD_QUESTIONMARK,
    GDB_CMD_WRITE_G,
    GDB_CMD_CONTINUE,
    GDB_CMD_READ_MEMORY,
    GDB_CMD_WRITE_MEMORY,
    GDB_CMD_STEP,
    // new actions go here
    NUM_ACTIONS,  // <- do not use other than array size !
}action_typ;

typedef struct{
    uint32_t phase;
    uint32_t intern_0;
    uint32_t par_i_0;
    walk_data_typ* walk;
    parameter_typ* parameter;
    action_typ action;
    uint8_t padding[3];
} action_data_typ;

typedef Result (*action_handler)(action_data_typ* action, bool first_call);

Result handle_target_reply_g(action_data_typ* action, bool first_call);
Result handle_target_reply_write_g(action_data_typ* action, bool first_call);
Result handle_target_connect(action_data_typ* action, bool first_call);
Result handle_target_close_connection(action_data_typ* action, bool first_call);

#endif /* DEVICE_SPECIFIC_H_ */
