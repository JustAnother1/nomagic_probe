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
#ifndef SWD_RESULT_QUEUE_H_
#define SWD_RESULT_QUEUE_H_

#include <stdint.h>
#include "probe_api/result.h"

#define COMMAND_QUEUE       0
#define PACKET_QUEUE        1
#define NUM_QUEUE           2

#define MAX_QUEUE_ENTRIES   10

void result_queue_init(void);

/** get the next free transaction ID.
 *
 * @param queue_id command or Packet queue
 * @param data [OUT] transaction id will be in range 1..MAX_QUEUE_ENTRIES
 * @return Result (RESULT_OK, ERR_QUEUE_FULL_TRY_AGAIN)
 */
Result result_queue_get_next_transaction_id(uint32_t queue_id, uint32_t* data);
Result result_queue_add_result_of(uint32_t queue_id, uint32_t transaction, uint32_t data);
Result result_queue_get_result(uint32_t queue_id, Result transaction, uint32_t* data);
void result_queue_free_result(uint32_t queue_id, uint32_t transaction);

#endif /* SWD_RESULT_QUEUE_H_ */
