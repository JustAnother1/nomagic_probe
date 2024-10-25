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
#include "cfg/target_specific_actions.h"

#define MAX_INTERN_VALUES          4
#define MAX_PARAMETER_VALUES       3
#define MAX_MEMORY_POSITIONS       20
#define MAX_BINARY_SIZE_BYTES      1024

#define MONITOR_RESET_TYPE_RUN     1
#define MONITOR_RESET_TYPE_INIT    2
#define MONITOR_RESET_TYPE_HALT    3

typedef struct {
    uint32_t value;
    bool has_value;
    uint8_t padding[3];
} mem_val_typ;

// the parameter can accommodate different values.
// For that the type gives the kind of value in the parameter and the data then
// contains that parameter.
// !!! Reading a data element from the wrong type will give a wrong result!!!
// the following types are supported:

#define HAS_VALUE             1
// has_value contains:
//  uint32_t value; <- the value of the parameter (an address or index,..)
//  bool valid;     <- the value variable is only valid if this is true.
//                     if this is false then no parameter value was given.

#define ADDRESS_LENGTH        2
// address_length contains:
//  uint32_t address; <- the address
//  uint32_t length;  <- the length

#define ADDRESS_MEMORY        3
// address_length contains:
//  uint32_t address; <- the address
//  mem_val_typ memory[MAX_MEMORY_POSITIONS]; <- for every memory location a value
//                                               or has_value = false to signal that it is missing

#define ADDRESS_LENGTH_MEMORY 4
// address_length contains:
//  uint32_t address; <- the address
//  uint32_t length;  <- the length
//  mem_val_typ memory[MAX_MEMORY_POSITIONS]; <- for every memory location a value
//                                               or has_value = false to signal that it is missing

#define MEMORY                5
// memory contains:
//  mem_val_typ memory[MAX_MEMORY_POSITIONS]; <- for every memory location a value
//                                               or has_value = false to signal that it is missing

#define ADDRESS_BINARY        6
// address_length contains:
//  uint32_t address; <- the address
//  uint32_t data_length; <- number of bytes in data[]
//  uint32_t data[MAX_BINARY_SIZE]; <- the data bytes (4 byte aligned)



typedef struct {
    uint32_t type;
    union{
        struct {
            uint32_t value;
            bool valid;
        } has_value;

        struct {
            uint32_t address;
            uint32_t length;
        } address_length;

        struct {
            uint32_t address;
            mem_val_typ memory[MAX_MEMORY_POSITIONS];
        } address_memory;

        struct {
            uint32_t address;
            uint32_t length;
            mem_val_typ memory[MAX_MEMORY_POSITIONS];
        } address_length_memory;

        struct {
            mem_val_typ memory[MAX_MEMORY_POSITIONS];
        } memory;

        struct {
            uint32_t address;
            uint32_t data_length;
            uint32_t data[MAX_BINARY_SIZE_BYTES/4];
        } address_binary;

    };
} parameter_typ;

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
    GDB_CMD_VFLASH_DONE,
    GDB_CMD_VFLASH_ERASE,
    GDB_CMD_VFLASH_WRITE,
#endif
    TARGET_SPECIFIC_ACTIONS_ENUM
    // new actions go here
    NUM_ACTIONS,  // <- do not use other than array size !
}action_typ;

typedef struct{
    uint32_t parameter[MAX_PARAMETER_VALUES];
    parameter_typ gdb_parameter;
    uint32_t cur_phase;
    uint32_t intern[MAX_INTERN_VALUES];
    uint32_t read_0;
    action_typ action;
    bool can_run;
    bool first_call;
} action_data_typ;


typedef Result (*action_handler)(action_data_typ * const action);

void common_target_init(void);
void common_target_tick(void);

Result add_target_action(action_data_typ * const action);
bool add_action(action_typ act);
bool add_action_with_parameter(action_typ act, parameter_typ* parsed_parameter);
void target_connect(void);
void target_close_connection(void);

void target_set_status(target_status_typ new_status);
bool common_cmd_target_info(uint32_t loop);


#endif /* COMMON_H_ */
