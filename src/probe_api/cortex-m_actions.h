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

#ifndef TARGET_CORTEX_M_ACTIONS_H_
#define TARGET_CORTEX_M_ACTIONS_H_

#include "probe_api/common.h"

bool target_command_halt_cortex_m_cpu(void);
Result handle_cortex_m_halt(action_data_typ* const action);

#endif /* TARGET_CORTEX_M_ACTIONS_H_ */
