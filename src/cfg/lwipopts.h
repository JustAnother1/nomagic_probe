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
#define ETH_PAD_SIZE                    2
// disable unused features:
#define LWIP_SOCKET                     0
#define LWIP_NETCONN                    0
#define SYS_LIGHTWEIGHT_PROT            0
#define LWIP_TCPIP_CORE_LOCKING         0
#define LWIP_STATS                      0

#endif /* NOMAGIC_PROBE_SRC_CFG_LWIPOPTS_H_ */
