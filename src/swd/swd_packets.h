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
#define AP_BANK_IDR      0xf  // 0xdf
#define AP_REGISTER_IDR  0xc


void swd_packets_init(void);
// default is false
void swd_packet_set_sticky_overrun(bool value);
void swd_packet_line_reset(void);
void swd_packet_disconnect(void);
// AP = 1; DP = 0
uint32_t swd_packet_write(uint32_t APnotDP, uint32_t address, uint32_t data);
// AP = 1; DP = 0
uint32_t swd_packet_read(uint32_t APnotDP, uint32_t address, uint32_t* data);
void swd_packet_set_swdio_idle(void);

#endif /* SRC_PACKETS_H_ */
