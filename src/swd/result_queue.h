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

typedef enum {
    COMMAND_QUEUE = 0,
    PACKET_QUEUE,
    // new queues go here
    NUM_QUEUE,  // <- do not use other than array size !
}result_queue_typ;


#define MAX_QUEUE_ENTRIES   10

void result_queue_init(void);

/** get the next free transaction ID.
 *
 * @param queue_id command or Packet queue
 * @param data [OUT] transaction id will be in range 1..MAX_QUEUE_ENTRIES
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result result_queue_get_next_transaction_id(result_queue_typ queue_id, uint32_t* data);

/** set the result value of a transaction.
 *
 * @param queue_id command or Packet queue
 * @param transaction transaction id of the result (range 1..MAX_QUEUE_ENTRIES)
 * @param data value of result.
 * @return ERR_INVALID_TRANSACTION_ID, ERR_WRONG_STATE or RESULT_OK
 */
Result result_queue_add_result_of(result_queue_typ queue_id, uint32_t transaction, uint32_t data);

/** get the result value of a transaction.
 *
 * @param queue_id command or Packet queue
 * @param transaction id of the transaction. (range 1..MAX_QUEUE_ENTRIES)
 * @param data [OUT] result value of the transaction.
 * @return ERR_INVALID_TRANSACTION_ID, ERR_WRONG_STATE, ERR_NOT_COMPLETED or RESULT_OK
 */
Result result_queue_get_result(result_queue_typ queue_id, Result transaction, uint32_t* data);

/** remove one transaction from queue.
 *
 * @param queue_id command or Packet queue
 * @param transaction transaction id that will be removed. (range 1..MAX_QUEUE_ENTRIES)
 */
void result_queue_free_result(result_queue_typ queue_id, uint32_t transaction);

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
void result_queue_print_status(result_queue_typ queue_id);
#endif

#endif /* SWD_RESULT_QUEUE_H_ */
