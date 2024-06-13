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
#include <string.h>

#include "cfg/network_cfg.h"
#include "dhcp_server.h"
#include "lwip/src/include/lwip/arch.h"
#include "lwip/src/include/lwip/udp.h"
#include "lwip/src/include/lwip/ip_addr.h"
#include "probe_api/debug_log.h"


#define DHCP_SERVER_PORT   67
#define DHCP_CLIENT_PORT   68

#define OP_REQUEST     1
#define OP_REPLY       2
#define HTYPE_ETHERNET 1

#define OPTION_MSG_TYPE_DISCOVER 1
#define OPTION_MSG_TYPE_OFFER    2
#define OPTION_MSG_TYPE_REQUEST  3
#define OPTION_MSG_TYPE_DECLINE  4
#define OPTION_MSG_TYPE_ACK      5
#define OPTION_MSG_TYPE_NAK      6
#define OPTION_MSG_TYPE_RELEASE  7
#define OPTION_MSG_TYPE_CONFIRM  8


typedef struct PACK_STRUCT_STRUCT {  // see RFC 2131  Dynamic Host Configuration Protocol
    uint8_t  op;         // message op code
    uint8_t  htype;      // hardware address type
    uint8_t  hlen;       // hardware address length
    uint8_t  hops;       // client sets to zero
    uint32_t xid;        // transaction id
    uint16_t secs;       // seconds since start of process (filled in by client)
    uint16_t flags;      // broadcast
    uint32_t ciaddr;     // client IP address
    uint32_t yiaddr;     // "your" client IP address
    uint32_t siaddr;     // IP address of next server
    uint32_t giaddr;     // relay agent IP address
    uint8_t  chaddr[16]; // client hardware address
    uint8_t  sname[64];  // optional server host name
    uint8_t  file[128];  // boot file name
}dhcp_packet_typ;

static void recieve_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);
static uint32_t get_message_type_from_options(uint8_t * option_data, uint32_t option_length);
static uint32_t get_requested_ip_from_options(uint8_t * option_data, uint32_t option_length);


static struct udp_pcb *  udp_server_handle;
static struct udp_pcb *  udp_client_handle;
static struct pbuf *     reply;
static dhcp_packet_typ * reply_payload;
static uint8_t *         reply_options_ptr;

// for options see RFC 2132 DHCP Options and BOOTP Vendor Extensions
// options tart with an option code followed by the length(number of bytes that follow)
static uint8_t option_magic_cookie[] = {0x63, 0x82 ,0x53, 0x63}; // see RFC 1497 BOOTP Extensions
static uint8_t option_server_identifier[] = {54, 4, 0, 0, 0, 0}; // fill in probe IP from network configuration
static uint8_t option_message_type[] = {53, 1, 2};
static uint32_t offset_message_type;
static uint8_t option_lease_time[] = {51, 4, 0, 1, 0x51, 0x80}; // in seconds : 24*60*60 = 86400 = 0x1 51 80
static uint8_t option_subnet_mask[] = {1, 4, 255, 255, 255, 0};
static uint8_t option_end[] = {255};

#define REPLY_OPTIONS_LENGTH  (sizeof(option_magic_cookie) + \
                               sizeof(option_message_type) + \
                               sizeof(option_lease_time) + \
                               sizeof(option_subnet_mask) + \
                               sizeof(option_server_identifier) + \
                               sizeof(option_end) )

bool dhcp_server_init(void)
{
    uint32_t idx = 0;
    udp_server_handle = udp_new();
    if(NULL == udp_server_handle)
    {
        debug_line("ERROR: could not create DHCP server UDP handle (no memory?) !");
        return false;
    }

    if(ERR_OK != udp_bind(udp_server_handle, IP_ADDR_ANY, DHCP_SERVER_PORT))
    {
        debug_line("ERROR: could not bind DHCP server UDP handle !");
        return false;
    }

    udp_client_handle = udp_new();
    if(NULL == udp_client_handle)
    {
        debug_line("ERROR: could not create DHCP client UDP handle (no memory?) !");
        return false;
    }

    udp_recv(udp_server_handle, recieve_cb, NULL);

    reply = pbuf_alloc(PBUF_RAW, sizeof(dhcp_packet_typ) + REPLY_OPTIONS_LENGTH, PBUF_RAM);
    if(NULL == reply)
    {
        debug_line("ERROR: could not allocate DHCP reply packet (no memory?) !");
        return false;
    }
    // probe-IP from network configuration
    option_server_identifier[2] = (uint8_t)(net_cfg.probe_ip.addr) & 0xff;
    option_server_identifier[3] = (uint8_t)(net_cfg.probe_ip.addr>>8) & 0xff;
    option_server_identifier[4] = (uint8_t)(net_cfg.probe_ip.addr>>16) & 0xff;
    option_server_identifier[5] = (uint8_t)(net_cfg.probe_ip.addr>>24) & 0xff;

    reply_payload = (dhcp_packet_typ *) reply->payload;
    memset(reply_payload, 0, sizeof(dhcp_packet_typ));
    reply_payload->op = OP_REPLY;
    reply_payload->htype = HTYPE_ETHERNET;
    reply_payload->hlen = 6; // MAC address is 6 bytes long
    // options:
    reply_options_ptr = (uint8_t *)(reply->payload) + sizeof(dhcp_packet_typ);
    // magic cookie (4)
    memcpy(&(reply_options_ptr[idx]), option_magic_cookie, sizeof(option_magic_cookie));
    idx += sizeof(option_magic_cookie);
    // message type (3)
    memcpy(&(reply_options_ptr[idx]), option_message_type, sizeof(option_message_type));
    offset_message_type = idx + 2;
    idx += sizeof(option_message_type);
    // lease time (6)
    memcpy(&(reply_options_ptr[idx]), option_lease_time, sizeof(option_lease_time));
    idx += sizeof(option_lease_time);
    // sub net mask (6)
    memcpy(&(reply_options_ptr[idx]), option_subnet_mask, sizeof(option_subnet_mask));
    idx += sizeof(option_subnet_mask);
    // server identifier (6)
    memcpy(&(reply_options_ptr[idx]), option_server_identifier, sizeof(option_server_identifier));
    idx += sizeof(option_server_identifier);
    // end (1)
    memcpy(&(reply_options_ptr[idx]), option_end, sizeof(option_end));
    // idx += sizeof(option_end);

    debug_line("DHCP server started !");
    return true;
}

static void recieve_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
    uint32_t msg_type;
    uint32_t ciaddr;
    dhcp_packet_typ * request_payload = (dhcp_packet_typ *) p->payload;
    // arg is the user parameter that we do not use and set NULL
    (void) arg;
    // addr is source address = 0.0.0.0
    (void) addr;
    // port is source port = 68
    (void) port;
    // pcb is the description of this UDP channel (source IP, targetIP, ports,...
    (void) pcb;

    // find message type in received options
    msg_type = get_message_type_from_options(
                    (uint8_t *)(p->payload) + sizeof(dhcp_packet_typ),
                    p->len - sizeof(dhcp_packet_typ) );

    // debug_line("DHCP: received message type %ld!", msg_type);

    switch(msg_type)
    {
    case OPTION_MSG_TYPE_DISCOVER:
        // send offer
        reply_options_ptr[offset_message_type] = OPTION_MSG_TYPE_OFFER;
        reply_payload->yiaddr = net_cfg.host_pc_ip.addr;
        break;

    case OPTION_MSG_TYPE_REQUEST:
    {
        uint32_t requested_ip = get_requested_ip_from_options(
                                    (uint8_t *)(p->payload) + sizeof(dhcp_packet_typ),
                                    p->len - sizeof(dhcp_packet_typ) );
        if(requested_ip == net_cfg.host_pc_ip.addr)
        {
            // send ack
            reply_options_ptr[offset_message_type] = OPTION_MSG_TYPE_ACK;
            reply_payload->yiaddr = net_cfg.host_pc_ip.addr;
        }
        else
        {
            // send nack
            reply_options_ptr[offset_message_type] = OPTION_MSG_TYPE_NAK;
        }
    }
        break;

    default:
        // we can ignore this.
        return;
    }

    // prepare reply
    reply_payload->secs = 0;
    memcpy(reply_payload->chaddr, request_payload->chaddr, 16);
    memcpy(&(reply_payload->xid), &(request_payload->xid), 4);
    memcpy(&ciaddr, &(request_payload->ciaddr), 4);
    if(0 != ciaddr)
    {
        udp_client_handle->remote_ip.addr = ciaddr;
    }
    else
    {
        if(0!= request_payload->flags)
        {
            udp_client_handle->remote_ip.addr = net_cfg.host_pc_ip.addr;
        }
        else
        {
            udp_client_handle->remote_ip.addr = IPADDR_BROADCAST;
        }
    }

    // send reply
    if(ERR_OK != udp_connect(udp_client_handle, &(udp_client_handle->remote_ip), DHCP_CLIENT_PORT))
    {
        debug_line("ERROR: could not connect to DHCP client !");
        udp_disconnect(udp_client_handle);
        return;
    }
    if(ERR_OK != udp_send(udp_client_handle, reply))
    {
        debug_line("ERROR: could not reply to DHCP client !");
    }
    udp_disconnect(udp_client_handle);
}

static uint32_t get_message_type_from_options(uint8_t * option_data, uint32_t option_length)
{
    uint32_t idx = 4; // skip magic cookie

    if(NULL == option_data)
    {
        return 0;
    }
    while(idx < option_length - 2)
    {
        switch(option_data[idx])
        {
        case 53: // found it
            return option_data[idx + 2];

        case 255 : // end option
            // we did not find it and reached the end of the options
            return 0;

        default: // some other option
            // increment idx by the length of the option + 2 (type + length bytes)
            idx = idx + option_data[idx + 1] + 2;
            break;
        }
    }
    return 0;
}

static uint32_t get_requested_ip_from_options(uint8_t * option_data, uint32_t option_length)
{
    uint32_t idx = 4; // skip magic cookie
    uint32_t res = 0;
    if(NULL == option_data)
    {
        return 0;
    }
    while(idx < option_length - 5)
    {
        switch(option_data[idx])
        {
        case 50: // found it
            res =        option_data[idx + 2];
            res = res + (option_data[idx + 3] << 8);
            res = res + (option_data[idx + 4] << 16);
            res = res + (option_data[idx + 5] << 24);
            return res;

        case 255 : // end option
            // we did not find it and reached the end of the options
            return 0;

        default: // some other option
            // increment idx by the length of the option + 2 (type + length bytes)
            idx = idx + option_data[idx + 1] + 2;
            break;
        }
    }
    return 0;
}
