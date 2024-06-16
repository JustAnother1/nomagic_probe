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

#include <stddef.h>
#include "tcp_pipe.h"
#include "probe_api/debug_log.h"
#include "lwip/src/include/lwip/ip_addr.h"
#include "lwip/src/include/lwip/err.h"
#include "lwip/src/include/lwip/tcp.h"

static err_t pipe_accept(void *arg, struct tcp_pcb *newpcb, err_t err);


bool tcp_pipe_activate(tcp_pipe_def* pipe)
{
    struct tcp_pcb* my_pcb;
    if(NULL == pipe)
    {
        debug_line("ERROR: could not create TCP Pipe, no definition! !");
        return false;
    }

    my_pcb = tcp_new();
    if(NULL == my_pcb)
    {
        debug_line("ERROR: could not create TCP Pipe handle for %d (no memory?) !", pipe->port);
        return false;
    }

    if(ERR_OK != tcp_bind(my_pcb, IP_ADDR_ANY, pipe->port))
    {
        debug_line("ERROR: could not bind TCP Pipe to port %d (port in use?) !", pipe->port);
        return false;
    }

    my_pcb = tcp_listen(my_pcb);
    if(NULL == my_pcb)
    {
        debug_line("ERROR: could not switch to listen on TCP Pipe handle for %d (no memory?) !", pipe->port);
        return false;
    }

    pipe->pcb = my_pcb;
    pipe->is_connected = false;
    tcp_arg(my_pcb, (void *)pipe);
    tcp_accept(my_pcb,pipe_accept);
    return true;
}

static err_t pipe_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
    tcp_pipe_def* pipe = (tcp_pipe_def*)arg;
    (void) err;  // TODO ???
    (void) pipe;
    tcp_accepted(newpcb);
    return ERR_OK;
}

