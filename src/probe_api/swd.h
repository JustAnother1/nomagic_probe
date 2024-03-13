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

// AP Addresses:
// CSW
#define AP_BANK_CSW      0x0
#define AP_REGISTER_CSW  0x0
// TAR
#define AP_BANK_TAR      0x0
#define AP_REGISTER_TAR  0x4
// DRW
#define AP_BANK_DRW      0x0
#define AP_REGISTER_DRW  0xc
// BD0
#define AP_BANK_BD0      0x1
#define AP_REGISTER_BD0  0x0
// BD1
#define AP_BANK_BD1      0x1
#define AP_REGISTER_BD1  0x4
// BD2
#define AP_BANK_BD2      0x1
#define AP_REGISTER_BD2  0x8
// BD3
#define AP_BANK_BD3      0x1
#define AP_REGISTER_BD3  0xc
// MBT
#define AP_BANK_MBT      0x2
#define AP_REGISTER_MBT  0x0
// T0RT
#define AP_BANK_T0RT     0x3
#define AP_REGISTER_T0RT 0x0
// CFG1
#define AP_BANK_CFG1     0xe
#define AP_REGISTER_CFG1 0x0
// CFG
#define AP_BANK_CFG      0xf
#define AP_REGISTER_CFG  0x4
// BASE
#define AP_BANK_BASE     0xf
#define AP_REGISTER_BASE 0x8
// IDR
#define AP_BANK_IDR      0xf  // 0xdf
#define AP_REGISTER_IDR  0xc

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
/** prints all available information on the debug UART.
 *
 * @param which the information to report. (counting up until this returns true)
 * @return true = everything printed; false = more information available.
 */
bool swd_info(uint32_t which);
#endif

void swd_init(void);
void swd_tick(void);

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

/** read a register inside the target Access port.
 *
 * @param bank the bank in the AP.
 * @param reg the register in the AP.
 * @return ERR_QUEUE_FULL_TRY_AGAIN or a transaction id.
 */
Result swd_read_ap_reg(uint32_t bank, uint32_t reg);

/** write a register inside the target Access port.
 *
 * @param bank the bank in the AP.
 * @param reg the register in the AP.
 * @param data the data to write
 * @return ERR_QUEUE_FULL_TRY_AGAIN or RESULT_OK
 */
Result swd_write_ap_reg(uint32_t bank, uint32_t reg, uint32_t data);

/** try to receive some data.
 * If one received a transaction id from another function then the result of that function _must_ be read (to free the queue).
 * @param transaction the transaction id
 * @param data where to write the received data
 * @return ERR_INVALID_TRANSACTION_ID, ERR_WRONG_STATE, ERR_NOT_COMPLETED or RESULT_OK
 */
Result swd_get_result(Result transaction, uint32_t* data);

/** resets the SWD stack and removes all error indicator.
 *  Call this before you call swd_connect() to start fresh.
 */
void swd_reset_error_condition(void);

#endif /* PROBE_API_SWD_H_ */
