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

bool cmd_die(const uint32_t loop);
bool cmd_hil_test(const uint32_t loop);
bool cmd_info(const uint32_t loop);
bool cmd_log(const uint32_t loop);
bool cmd_parameter_raw(const uint32_t loop);
bool cmd_time(const uint32_t loop);

#endif /* CLI_CLI_SYS_H_ */
