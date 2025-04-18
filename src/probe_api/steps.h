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

#ifndef NOMAGIC_PROBE_SRC_TARGET_STEPS_H_
#define NOMAGIC_PROBE_SRC_TARGET_STEPS_H_

#include <stdint.h>
#include "probe_api/result.h"
#include "probe_api/common.h"

#define INTERN_TRANSACTION_ID   0

Result step_connect(bool multi, uint32_t target, uint32_t AP_sel);
Result step_disconnect(void);
Result step_read_ap_reg(uint32_t bank, uint32_t reg);
Result step_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data);
Result step_read_ap(volatile uint32_t* address);
Result step_write_ap(volatile uint32_t* address, uint32_t data);
Result step_get_Result_OK(void);
Result step_get_Result_data(uint32_t* data);

#endif /* NOMAGIC_PROBE_SRC_TARGET_STEPS_H_ */
