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

#ifndef NOMAGIC_PROBE_SRC_GDBSERVER_GDB_ERROR_CODES_H_
#define NOMAGIC_PROBE_SRC_GDBSERVER_GDB_ERROR_CODES_H_

#define ERROR_CODE_INVALID_TRANSFERE_REQUEST         "E00"
#define ERROR_CODE_INVALID_MONITOR_COMMAND           "E01"
#define ERROR_CODE_INVALID_PARAMETER_FORMAT_TYPE     "E02"
#define ERROR_CODE_INVALID_PARAMETER_FORMAT_COMMA    "E03"
#define ERROR_CODE_INVALID_PARAMETER_FORMAT_COLON    "E04"
#define ERROR_CODE_INVALID_PARAMETER_VALUE_TOO_SMALL "E05"
#define ERROR_CODE_INVALID_PARAMETER_VALUE           "E06"
#define ERROR_CODE_WRONG_OFFSET                      "E07"
#define ERROR_CODE_INVALID_THREAD_OPERATION          "E08"
#define ERROR_CODE_TOO_LONG                          "E09"
#define ERROR_TARGET_FAILED                          "E10"

#endif /* NOMAGIC_PROBE_SRC_GDBSERVER_GDB_ERROR_CODES_H_ */
