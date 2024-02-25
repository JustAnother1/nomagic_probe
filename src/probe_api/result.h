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


#define RESULT_OK                   0
// Errors:
#define ERR_QUEUE_FULL_TRY_AGAIN   -1
#define ERR_WRONG_STATE            -2
#define ERR_NOT_CONNECTED          -3
#define ERR_NOT_COMPLETED          -4
#define ERR_INVALID_TRANSACTION_ID -5
#define ERR_TIMEOUT                -6
#define ERR_TARGET_ERROR           -7
#define ERR_INVALID_QUEUE          -8
#define ERR_WRONG_VALUE            -9


typedef int32_t Result;


#endif /* PROBE_API_RESULT_H_ */
