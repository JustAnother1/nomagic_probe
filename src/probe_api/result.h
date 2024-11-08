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

#ifndef PROBE_API_RESULT_H_
#define PROBE_API_RESULT_H_

#include <stdint.h>

#define RESULT_OK                   0
// Errors:                    int32_t  / uint32_t
#define ERR_QUEUE_FULL_TRY_AGAIN    -1 // 0xffffffff
#define ERR_WRONG_STATE             -2 // 0xfffffffe
#define ERR_NOT_CONNECTED           -3 // 0xfffffffd
#define ERR_NOT_COMPLETED           -4 // 0xfffffffc
#define ERR_INVALID_TRANSACTION_ID  -5 // 0xfffffffb
#define ERR_TIMEOUT                 -6 // 0xfffffffa
#define ERR_TARGET_ERROR            -7 // 0xfffffff9
#define ERR_INVALID_QUEUE           -8 // 0xfffffff8
#define ERR_WRONG_VALUE             -9 // 0xfffffff7
#define ERR_TOO_LONG               -10 // 0xfffffff6
#define ERR_INVALID_PARAMETER      -11 // 0xfffffff5
#define ERR_ACTION_NULL            -12 // 0xfffffff4

typedef int32_t Result;


#endif /* PROBE_API_RESULT_H_ */
