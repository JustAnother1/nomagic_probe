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
#ifndef PROBE_API_GDB_PACKETS_H_
#define PROBE_API_GDB_PACKETS_H_


void reply_packet_prepare(void);
void reply_packet_add(char* data);
void reply_packet_send(void);
void send_error_packet(void);
void send_ack_packet(void);
void send_unknown_command_reply(void);


#endif /* PROBE_API_GDB_PACKETS_H_ */
