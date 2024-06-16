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

typedef struct {
    struct tcp_pcb * pcb;
    uint16_t port;
    bool is_connected;
} tcp_pipe_def;

bool tcp_pipe_activate(tcp_pipe_def* pipe);

#endif /* NOMAGIC_PROBE_SRC_LWIP_TCP_PIPE_H_ */
