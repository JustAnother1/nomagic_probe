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

#ifndef NOMAGIC_PROBE_SRC_CLI_CLI_COMMON_TARGET_H_
#define NOMAGIC_PROBE_SRC_CLI_CLI_COMMON_TARGET_H_

#include <stdbool.h>
#include <stdint.h>

bool cmd_target_trace(uint32_t loop);
bool common_action_info(uint32_t loop);

#endif /* NOMAGIC_PROBE_SRC_CLI_CLI_COMMON_TARGET_H_ */
