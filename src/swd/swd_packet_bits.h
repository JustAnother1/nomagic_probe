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
