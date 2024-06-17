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

#ifndef NOMAGIC_PROBE_SRC_LWIP_TCP_PIPE_H_
#define NOMAGIC_PROBE_SRC_LWIP_TCP_PIPE_H_

#include <stdbool.h>
#include <stdint.h>

#define RECEIVE_BUFFER_SIZE   300

typedef struct {
    struct tcp_pcb * port_pcb;
    struct tcp_pcb * connection_pcb;
    uint16_t port;
    bool is_connected;
    uint8_t recv_buf[RECEIVE_BUFFER_SIZE];
    volatile uint32_t recv_read_pos;
    volatile uint32_t recv_write_pos;
} tcp_pipe_def;

bool tcp_pipe_activate(tcp_pipe_def* pipe);
uint32_t tcp_pipe_write(tcp_pipe_def* pipe, const uint8_t * data, const uint16_t length);
uint32_t tcp_pipe_get_num_received_bytes(tcp_pipe_def* pipe);
uint8_t tcp_pipe_get_next_received_byte(tcp_pipe_def* pipe);

#endif /* NOMAGIC_PROBE_SRC_LWIP_TCP_PIPE_H_ */
