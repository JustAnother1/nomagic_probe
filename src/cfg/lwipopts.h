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

#ifndef NOMAGIC_PROBE_SRC_CFG_LWIPOPTS_H_
#define NOMAGIC_PROBE_SRC_CFG_LWIPOPTS_H_

// we do not have an Operating System ->  NO_SYS =1
#define NO_SYS                          1
// MEM_ALIGNMENT: should be set to the alignment of the CPU
//    4 byte alignment -> \#define MEM_ALIGNMENT 4
#define MEM_ALIGNMENT                   4
#define ETH_PAD_SIZE                    0
#define ARP_TABLE_SIZE                  4
// disable unused features:
#define LWIP_SOCKET                     0
#define LWIP_NETCONN                    0
#define SYS_LIGHTWEIGHT_PROT            0
#define LWIP_TCPIP_CORE_LOCKING         0
#define LWIP_STATS                      0
#define LWIP_DNS                        0
#define LWIP_IGMP                       0
#define LWIP_DHCP                       0
#define LWIP_IPV6                       0

// active needed features
#define LWIP_SINGLE_NETIF               1
#define LWIP_IPV4                       1
#define LWIP_ARP                        1
#define LWIP_TCP                        1
#define LWIP_UDP                        1
#define LWIP_ICMP                       1

#define LWIP_IP_ACCEPT_UDP_PORT(dst_port) (((dst_port) == PP_NTOHS(67)) || ((dst_port) == PP_NTOHS(68)))

// performance tuning (do not change without extensive testing, optimized for ECM/NCM)
#define TCP_MSS                                (1500 - 20 - 20)    // MTU minus header sizes (best value until now)
#define TCP_SND_BUF                            (8 * TCP_MSS)       //   good tuning
#define TCP_SND_QUEUELEN                       16
#define TCP_SNDQUEUELOWAT                      (TCP_SND_QUEUELEN / 2)
#define MEMP_NUM_TCP_SEG                       32

#define MEM_SIZE                               20000

// DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG

// LWIP_DBG_OFF
// LWIP_DBG_LEVEL_ALL
// LWIP_DBG_LEVEL_WARNING
// LWIP_DBG_LEVEL_SERIOUS
// LWIP_DBG_LEVEL_SEVERE

#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_ALL
#define LWIP_DBG_TYPES_ON               LWIP_DBG_ON


// these settings are either LWIP_DBG_ON  or LWIP_DBG_OFF
/**
 * ETHARP_DEBUG: Enable debugging in etharp.c.
 */
#define ETHARP_DEBUG                    LWIP_DBG_OFF
/**
 * NETIF_DEBUG: Enable debugging in netif.c.
 */
#define NETIF_DEBUG                     LWIP_DBG_OFF
/**
 * PBUF_DEBUG: Enable debugging in pbuf.c.
 */
#define PBUF_DEBUG                      LWIP_DBG_OFF
/**
 * API_LIB_DEBUG: Enable debugging in api_lib.c.
 */
#define API_LIB_DEBUG                   LWIP_DBG_OFF
/**
 * API_MSG_DEBUG: Enable debugging in api_msg.c.
 */
#define API_MSG_DEBUG                   LWIP_DBG_OFF
/**
 * SOCKETS_DEBUG: Enable debugging in sockets.c.
 */
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
/**
 * ICMP_DEBUG: Enable debugging in icmp.c.
 */
#define ICMP_DEBUG                      LWIP_DBG_OFF
/**
 * IGMP_DEBUG: Enable debugging in igmp.c.
 */
#define IGMP_DEBUG                      LWIP_DBG_OFF
/**
 * INET_DEBUG: Enable debugging in inet.c.
 */
#define INET_DEBUG                      LWIP_DBG_OFF
/**
 * IP_DEBUG: Enable debugging for IP.
 */
#define IP_DEBUG                        LWIP_DBG_OFF
/**
 * IP_REASS_DEBUG: Enable debugging in ip_frag.c for both frag & reass.
 */
#define IP_REASS_DEBUG                  LWIP_DBG_OFF
/**
 * RAW_DEBUG: Enable debugging in raw.c.
 */
#define RAW_DEBUG                       LWIP_DBG_OFF
/**
 * MEM_DEBUG: Enable debugging in mem.c.
 */
#define MEM_DEBUG                       LWIP_DBG_OFF
/**
 * MEMP_DEBUG: Enable debugging in memp.c.
 */
#define MEMP_DEBUG                      LWIP_DBG_OFF
/**
 * SYS_DEBUG: Enable debugging in sys.c.
 */
#define SYS_DEBUG                       LWIP_DBG_OFF
/**
 * TIMERS_DEBUG: Enable debugging in timers.c.
 */
#define TIMERS_DEBUG                    LWIP_DBG_OFF
/**
 * TCP_DEBUG: Enable debugging for TCP.
 */
#define TCP_DEBUG                       LWIP_DBG_OFF
/**
 * TCP_INPUT_DEBUG: Enable debugging in tcp_in.c for incoming debug.
 */
#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
/**
 * TCP_FR_DEBUG: Enable debugging in tcp_in.c for fast retransmit.
 */
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
/**
 * TCP_RTO_DEBUG: Enable debugging in TCP for retransmit
 * timeout.
 */
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
/**
 * TCP_CWND_DEBUG: Enable debugging for TCP congestion window.
 */
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
/**
 * TCP_WND_DEBUG: Enable debugging in tcp_in.c for window updating.
 */
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
/**
 * TCP_OUTPUT_DEBUG: Enable debugging in tcp_out.c output functions.
 */
#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
/**
 * TCP_RST_DEBUG: Enable debugging for TCP with the RST message.
 */
#define TCP_RST_DEBUG                   LWIP_DBG_ON
/**
 * TCP_QLEN_DEBUG: Enable debugging for TCP queue lengths.
 */
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
/**
 * UDP_DEBUG: Enable debugging in UDP.
 */
#define UDP_DEBUG                       LWIP_DBG_OFF
/**
 * TCPIP_DEBUG: Enable debugging in tcpip.c.
 */
#define TCPIP_DEBUG                     LWIP_DBG_OFF
/**
 * SLIP_DEBUG: Enable debugging in slipif.c.
 */
#define SLIP_DEBUG                      LWIP_DBG_OFF
/**
 * DHCP_DEBUG: Enable debugging in dhcp.c.
 */
#define DHCP_DEBUG                      LWIP_DBG_OFF
/**
 * AUTOIP_DEBUG: Enable debugging in autoip.c.
 */
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
/**
 * ACD_DEBUG: Enable debugging in acd.c.
 */
#define ACD_DEBUG                       LWIP_DBG_OFF
/**
 * DNS_DEBUG: Enable debugging for DNS.
 */
#define DNS_DEBUG                       LWIP_DBG_OFF
/**
 * IP6_DEBUG: Enable debugging for IPv6.
 */
#define IP6_DEBUG                       LWIP_DBG_OFF
/**
 * DHCP6_DEBUG: Enable debugging in dhcp6.c.
 */
#define DHCP6_DEBUG                     LWIP_DBG_OFF

#endif /* NOMAGIC_PROBE_SRC_CFG_LWIPOPTS_H_ */
