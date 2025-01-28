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

#ifndef TARGET_H_
#define TARGET_H_

#include <stdint.h>
#include "probe_api/common.h"
#include "probe_api/gdb_monitor_defs.h"

// https://openocd.org/doc/html/General-Commands.html

#define MON_CMD_IDX_HELP                    0
#define MON_CMD_IDX_VERSION                 1
#define MON_CMD_IDX_RESET                   2
#define MON_CMD_IDX_HALT                    3
#define MON_CMD_IDX_REG                     4


static const mon_cmd_typ mon_commands[] = {
        //         1         2                   1         2         3         4         5         6
        //1234567890123456789012345     123456789012345678901234567890123456789012345678901234567890
/* 0 */ {"help",                       "list all available commands"},
/* 1 */ {"version",                    "show version of probe firmware"},
/* 2 */ {"reset",                      "reset target"},
/* 3 */ {"halt",                       "halt target"},
/* 4 */ {"reg",                        "show register content"},
};

void target_init(void);
void target_tick(void);
bool target_is_SWDv2(void);
uint32_t target_get_SWD_core_id(uint32_t core_num); // only required for SWDv2 (TARGETSEL)
uint32_t target_get_SWD_APSel(uint32_t core_num);
#ifdef FEAT_GDB_SERVER
void target_send_file(char* filename, uint32_t offset, uint32_t len);
#endif
Result target_write(uint32_t start_address, uint8_t* data, uint32_t length);

#endif /* TARGET_H_ */
