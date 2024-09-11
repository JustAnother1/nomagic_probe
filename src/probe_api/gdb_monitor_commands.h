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

#ifndef NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_COMMANDS_H_
#define NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_COMMANDS_H_

#include "target.h"

#define NUM_MON_COMMANDS  (sizeof(mon_commands)/sizeof(mon_cmd_typ))

void target_monitor_command(uint32_t which, char* command);
void mon_cmd_help(char* command);
void mon_cmd_version(void);
void mon_cmd_halt(char* command);
void mon_cmd_reset(char* command);
void mon_cmd_reg(char* command);

#endif /* NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_COMMANDS_H_ */
