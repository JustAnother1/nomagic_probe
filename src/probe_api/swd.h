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
#ifndef PROBE_API_SWD_H_
#define PROBE_API_SWD_H_

#include <stdint.h>
#include <stdbool.h>
#include "result.h"

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
/** prints all available information on the debug UART.
 *
 * @param which the information to report. (counting up until this returns true)
 * @return true = everything printed; false = more information available.
 */
bool swd_info(uint32_t which);
#endif

// configuration
/** set the value of APSEL.
 * There could be more than one (Memory) Access Port. Therefore the address of the AP to use needs to be set.
 * The available APs can be scanned.
 * @param val the value of APSEL to use. (in most cases probably =0)
 */
void swd_protocol_set_AP_sel(uint32_t val);

// SWD actions:
/** open a connection to the target chip.
 *
 * @param multi false = SWDv1; true = SWDv2 (multi drop system)
 * @param target value to be used on TARGETSEL command to DP.
 * @param AP_sel the address of the Access Port to use.
 * @return ERR_QUEUE_FULL_TRY_AGAIN or a transaction id.
 */
Result swd_connect(bool multi, uint32_t target, uint32_t AP_sel);

/** is the connection to the target chip established?
 *
 * @return true = connection to target chip is open; false = no SWD communication happening.
 */
bool swd_is_connected(void);

/** scan the SWD Interface of the target chip.
 * This tries to read all available information about the chip.
 * This can be helpful when trying t get a new chip supported.
 *
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_scan(void);

/** read a certain memory position from the target chip memory.
 *
 * @param addr the address in the targets address space.
 * @return ERR_QUEUE_FULL_TRY_AGAIN or a transaction id.
 */
Result swd_read_ap(uint32_t addr);

/** write something into the target chip memory.
 *
 * @param addr address in target chip memory area.
 * @param data the data to write
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_write_ap(uint32_t addr, uint32_t data);

/** try to receive some data.
 * If one received a transaction id from another function then the result of that function _must_ be read (to free the queue).
 * @param transaction the transaction id
 * @param data where to write the received data
 * @return ERR_INVALID_TRANSACTION_ID, ERR_WRONG_STATE, ERR_NOT_COMPLETED or RESULT_OK
 */
Result swd_get_result(Result transaction, uint32_t* data);

#endif /* PROBE_API_SWD_H_ */
