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
#ifndef SRC_PACKETS_H_
#define SRC_PACKETS_H_

#include <stdint.h>
#include <stdbool.h>
#include "probe_api/result.h"

void swd_packets_init(void);

/** sends a line reset signal.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_packet_line_reset(void);

/** sends the disconnect signal.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_packet_disconnect(void);

/** sends a SWD write packet.
 *
 * @param APnotDP Address Port or Debug Port (AP = 1; DP = 0)
 * @param address A[2], A[3] (A[0] = A[1] = 0)
 * @param data  bits to write
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_packet_write(uint32_t APnotDP, uint32_t address, uint32_t data);

/** sends a SWD read packet.
 *
 * @param APnotDP Address Port or Debug Port (AP = 1; DP = 0)
 * @param address A[2], A[3] (A[0] = A[1] = 0)
 * @return ERR_QUEUE_FULL_TRY_AGAIN, ERR_INVALID_QUEUE or transaction id.
 */
Result swd_packet_read(uint32_t APnotDP, uint32_t address);

/** read the data received by the read packet.
 *
 * @param transaction transaction id as returned by @swd_packet_read()
 * @param data [OUT] the bits read
 * @return ERR_INVALID_TRANSACTION_ID, ERR_NOT_COMPLETED, ERR_WRONG_STATE, ERR_TARGET_ERROR or RESULT_OK
 */
Result swd_packet_get_result(Result transaction, uint32_t* data);

/** sends the JTAG to Dormant bit sequence.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result jtag_to_dormant_state_sequence(void);

/** sends the Dormant to SWD bit sequence.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result leave_dormant_state_to_swd_sequence(void);

/** sends the SWD to Dormant bit sequence.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_to_dormant_state_sequence(void);

#endif /* SRC_PACKETS_H_ */
