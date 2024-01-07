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

// ACK
#define ACK_PROTOCOL_ERROR_0   0 // on wire: line not driven -> read as low
#define ACK_OK                 1 // on wire: 1 0 0
#define ACK_WAIT               2 // on wire: 0 1 0
#define ACK_FAULT              4 // on wire: 0 0 1
#define ACK_PROTOCOL_ERROR_1   7 // on wire: line not driven -> read as high
#define ERROR_PARITY           8

// If the  ACK_PROTOCOL_ERROR_0 or ACK_PROTOCOL_ERROR_1 occur twice then a line reset  + read IDCODE is needed.

#define AP  1
#define DP  0

// DP addresses:
// A0 = 0,  A1 = 0
#define ADDR_DPIDR     0  // A3 = 0, A2 = 0
#define ADDR_DPIDR1    0  // A3 = 0, A2 = 0
#define ADDR_BASEPTR0  0  // A3 = 0, A2 = 0
#define ADDR_BASEPTR1  0  // A3 = 0, A2 = 0
#define ADDR_ABORT     0  // A3 = 0, A2 = 0
#define ADDR_CTRL_STAT 4  // A3 = 0, A2 = 1
#define ADDR_DLCR      4  // A3 = 0, A2 = 1
#define ADDR_DLPIDR    4  // A3 = 0, A2 = 1
#define ADDR_EVENTSTAT 4  // A3 = 0, A2 = 1
#define ADDR_SELECT1   4  // A3 = 0, A2 = 1
#define ADDR_TARGETID  4  // A3 = 0, A2 = 1
#define ADDR_SELECT    8  // A3 = 1, A2 = 0
#define ADDR_RESEND    8  // A3 = 1, A2 = 0
#define ADDR_RDBUFF    12 // A3 = 1, A2 = 1
#define ADDR_TARGETSEL 12 // A3 = 1, A2 = 1

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

#define PACKET_QUEUE_SIZE   20

void swd_packets_init(void);
// default is false
void swd_packets_set_sticky_overrun(bool value);
void swd_packets_set_swdio_idle(void);
void swd_packets_tick(void);

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
 * @return ERR_INVALID_TRANSACTION_ID, ERR_NOT_YET_AVAILABLE, ERR_WRONG_STATE or RESULT_OK
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
