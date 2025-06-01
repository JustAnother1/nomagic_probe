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
#include <string.h>
#include "tcp_pipe.h"
#include "probe_api/debug_log.h"
#include "lwip/src/include/lwip/ip_addr.h"
#include "lwip/src/include/lwip/err.h"
#include "lwip/src/include/lwip/tcp.h"

// call back functions
static err_t pipe_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t pipe_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static err_t pipe_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

bool tcp_pipe_activate(tcp_pipe_def* pipe)
{
    struct tcp_pcb* my_pcb;
    if(NULL == pipe)
    {
        debug_error("ERROR: could not create TCP Pipe, no definition! !");
        return false;
    }

    my_pcb = tcp_new();
    if(NULL == my_pcb)
    {
        debug_error("ERROR: could not create TCP Pipe handle for %d (no memory?) !", pipe->port);
        return false;
    }

    debug_line("NCM: binding to TCP port %d !", pipe->port);
    if(ERR_OK != tcp_bind(my_pcb, IP_ADDR_ANY, pipe->port))
    {
        debug_error("ERROR: could not bind TCP Pipe to port %d (port in use?) !", pipe->port);
        tcp_close(my_pcb);
        return false;
    }

    my_pcb = tcp_listen_with_backlog(my_pcb, 1);
    if(NULL == my_pcb)
    {
        debug_error("ERROR: could not switch to listen on TCP Pipe handle for %d (no memory?) !", pipe->port);
        tcp_close(my_pcb);
        return false;
    }

    pipe->port_pcb = my_pcb;
    pipe->connection_pcb = NULL;
    pipe->is_connected = false;
    tcp_arg(my_pcb, (void *)pipe);
    tcp_accept(my_pcb, pipe_accept);
    return true;
}

uint32_t tcp_pipe_write(tcp_pipe_def* pipe, const uint8_t * data, const uint16_t length)
{
    err_t res;
    uint16_t available;  // number of bytes the stack can send out (free space in buffer)
    uint16_t bytes_to_send = length;
    if(NULL == pipe->connection_pcb)
    {
        // connection might have been closed just now, so sending this makes no sense anymore.
        return length;
    }
    available = tcp_sndbuf(pipe->connection_pcb);
    if(0 == available)
    {
        // buffer is full we can currently not send anything
        return 0;
    }
    if(length > available)
    {
        // we can not send the complete data all at once, so only send as much as we can.
        bytes_to_send = available;
    }
    // TCP_WRITE_FLAG_COPY : We want the stack to copy the data into his buffer.
    // This way we do not need to keep the data in the callers buffer.
    res = tcp_write(pipe->connection_pcb, (void *)data, bytes_to_send, TCP_WRITE_FLAG_COPY);
    if(ERR_OK == res)
    {
        // we send the data
        return bytes_to_send;
    }
    else
    {
        // sending failed
        return 0;
    }
}

uint32_t tcp_pipe_get_num_received_bytes(tcp_pipe_def* pipe)
{
    if(pipe->recv_read_pos == pipe->recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    if(pipe->recv_read_pos < pipe->recv_write_pos)
    {
        return pipe->recv_write_pos - pipe->recv_read_pos;
    }
    else
    {
        // wrap around
        return (RECEIVE_BUFFER_SIZE - pipe->recv_read_pos) + pipe->recv_write_pos;
    }
}

uint8_t tcp_pipe_get_next_received_byte(tcp_pipe_def* pipe)
{
    uint8_t res;
    if(pipe->recv_read_pos == pipe->recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    res = pipe->recv_buf[pipe->recv_read_pos];
    pipe->recv_read_pos++;
    if(RECEIVE_BUFFER_SIZE == pipe->recv_read_pos)
    {
        pipe->recv_read_pos = 0;
    }
    return res;
}

// call back functions:

static err_t pipe_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
    // new connection arrived
    tcp_pipe_def* pipe = (tcp_pipe_def*)arg;

    if(ERR_OK != err)
    {
        // There was an error when the stack tried to accept the connection
        tcp_close(newpcb);
        return ERR_OK;
    }

    pipe->connection_pcb = newpcb;
    pipe->is_connected = true;
    tcp_sent(newpcb, pipe_sent);
    tcp_recv(newpcb, pipe_recv);
    tcp_accepted(newpcb);
    return ERR_OK;
}

static err_t pipe_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
    // len many bytes have been received(+ Acked) by the host
    tcp_pipe_def* pipe = (tcp_pipe_def*)arg;
    (void) len;
    (void) tpcb;
    (void) pipe;
    // TODO ignore for now?
    return ERR_OK;
}

static err_t pipe_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    tcp_pipe_def* pipe = (tcp_pipe_def*)arg;
    if(ERR_OK != err)
    {
        return err;
    }
    if(NULL == p)
    {
        // host closed the connection
        pipe->is_connected = false;
        pipe->connection_pcb = NULL;
        tcp_close(tpcb);
        return ERR_OK;
    }
    else
    {
        // new data has arrived
        uint32_t available = RECEIVE_BUFFER_SIZE - tcp_pipe_get_num_received_bytes(pipe);
        if(p->len < available)
        {
            uint32_t fit = RECEIVE_BUFFER_SIZE - pipe->recv_write_pos;
            if(p->len < fit)
            {
                memcpy(&(pipe->recv_buf[pipe->recv_write_pos]), p->payload, p->len);
                pipe->recv_write_pos += p->len;
            }
            else
            {
                // wrap around
                uint32_t rest =  p->len - fit;
                memcpy(&(pipe->recv_buf[pipe->recv_write_pos]), p->payload, fit);
                memcpy(&(pipe->recv_buf[0]), (uint8_t *)(p->payload) + fit, rest);
                pipe->recv_write_pos = rest;
            }
            // tell lwIP stack that we have received the data, so that it can forget about it.
            tcp_recved(tpcb, p->len);
            pbuf_free(p);
            return ERR_OK;
        }
        else
        {
            // TODO can I copy only some bytes?
            // not enough space in buffer
            return ERR_MEM;
        }
    }
}

