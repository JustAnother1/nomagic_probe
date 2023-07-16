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
#ifndef CLI_CLI_SYS_H_
#define CLI_CLI_SYS_H_

#include "cfg/cli_cfg.h"

bool cmd_die(void);
bool cmd_hil_test(void);
bool cmd_info(void);
bool cmd_parameter_raw(void);
bool cmd_time(void);

#endif /* CLI_CLI_SYS_H_ */
