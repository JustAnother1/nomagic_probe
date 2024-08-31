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

#ifndef CFG_TARGET_SPECIFIC_ACTIONS_H_
#define CFG_TARGET_SPECIFIC_ACTIONS_H_

#define TARGET_SPECIFIC_ACTIONS_ENUM \
    GDB_CMD_MON_HALT,                \
    GDB_CMD_MON_RESET_INIT,          \
    GDB_MONITOR_REG,

#define TARGET_SPECIFIC_ACTION_HANDLERS                     \
    handle_monitor_halt,       /* GDB_CMD_MON_HALT */       \
    handle_monitor_reset_init, /* GDB_CMD_MON_RESET_INIT */ \
    handle_monitor_reg,        /* GDB_MONITOR_REG, */

#define TARGET_SPECIFIC_ACTION_NAMES \
    "monitor_halt",                  \
    "monitor_reset_init",            \
    "monitor_reg",


#endif /* CFG_TARGET_SPECIFIC_ACTIONS_H_ */
