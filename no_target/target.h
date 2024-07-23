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

static const mon_cmd_typ mon_commands[] = {
        //         11             1         2         3         4         5         6
        //12345678901    123456789012345678901234567890123456789012345678901234567890
        {"help",        "list all available commands"}
};

bool target_is_SWDv2(void);
uint32_t target_get_SWD_core_id(uint32_t core_num); // only required for SWDv2 (TARGETSEL)
uint32_t target_get_SWD_APSel(uint32_t core_num);
#ifdef FEAT_GDB_SERVER
void target_send_file(char* filename, uint32_t offset, uint32_t len);
void target_monitor_command(uint32_t which, char* command);
#endif

#endif /* TARGET_H_ */
