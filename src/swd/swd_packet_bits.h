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
#ifndef SWD_SWD_PACKET_BITS_H_
#define SWD_SWD_PACKET_BITS_H_

#include <stdint.h>
#include "probe_api/result.h"

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

typedef enum {
    LINE_RESET = 0,
    DISCONNECT,
    WRITE,
    READ,
    JTAG_TO_DORMANT,
    DORMANT_TO_SWD,
    SWD_TO_DORMANT,
    // new packets go here
    NUM_PAKETS,  // <- do not use other than array size !
}packet_typ;

typedef struct{
    packet_typ type;
    uint32_t APnotDP;
    uint32_t address;
    uint32_t data;
    uint32_t result_idx;
} packet_definition_typ;

extern volatile uint32_t read_idx;
extern volatile uint32_t write_idx;
extern packet_definition_typ packet_queue[PACKET_QUEUE_SIZE];

void swd_packet_bits_init(void);
void swd_packet_bits_reset_error_condition(void);
bool swd_packet_bits_is_operational(void);
void swd_packet_bits_tick(void);
void swd_packet_bits_set_swdio_idle(void);
uint32_t swd_packet_bits_get_next_data_slot(void);
Result swd_packet_bits_get_data_value(uint32_t idx, uint32_t* data);

// default is false
void swd_packet_bits_set_sticky_overrun(bool value);


#endif /* SWD_SWD_PACKET_BITS_H_ */
