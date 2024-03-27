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
#ifndef PROBE_API_DEBUG_LOG_H_
#define PROBE_API_DEBUG_LOG_H_

#include <stdio.h>

#ifdef UNIT_TEST
#define debug_msg(...)  my_printf(__VA_ARGS__)
#define debug_line(...) my_printf(__VA_ARGS__); my_printf("\r\n")
#else
#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
#define debug_msg(...)  printf(__VA_ARGS__)
#define debug_line(...) printf(__VA_ARGS__); printf("\r\n")
#else
#define debug_msg(...)
#define debug_line(...)
#endif // (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
#endif // UNIT_TEST

#endif /* PROBE_API_DEBUG_LOG_H_ */
