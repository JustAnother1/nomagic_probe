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

#ifndef NOMAGIC_PROBE_SRC_PROBE_API_ACTIVITY_H_
#define NOMAGIC_PROBE_SRC_PROBE_API_ACTIVITY_H_

#include <stdint.h>
#include "probe_api/common.h"
#include "probe_api/result.h"

#define ACTIVITY_DONE   0

typedef struct {
    uint32_t phase;
    bool first_call;
} activity_data_typ;

Result act_read_register(activity_data_typ* const state, volatile uint32_t* address, uint32_t* read_value);

#endif /* NOMAGIC_PROBE_SRC_PROBE_API_ACTIVITY_H_ */
