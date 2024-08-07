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

#ifndef NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_DEFS_H_
#define NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_DEFS_H_

#include <stdbool.h>

typedef bool (*mon_func_typ)(const char* cmd);

typedef struct {
    char name[25];
    char help[60];
}mon_cmd_typ;

#endif /* NOMAGIC_PROBE_SRC_PROBE_API_GDB_MONITOR_DEFS_H_ */
