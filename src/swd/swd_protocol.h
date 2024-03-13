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
#ifndef SRC_SWD_SWD_PROTOCOL_H_
#define SRC_SWD_SWD_PROTOCOL_H_

#include <stdint.h>
#include <stdbool.h>
#include "swd_engine.h"
#include "probe_api/result.h"

void swd_protocol_init(void);
void swd_protocol_tick(void);

/** connects to the debug port in the target over SWD.
 *
 * @param first_call if true then start from the beginning, else continue unfinished task.
 * @param cmd contains the parameters for the connection
 * @return RESULT_OK if finished successfully else ERR_NOT_COMPLETED, or an error code.
 */
Result connect_handler(command_typ* cmd, bool first_call);

/** reads a value from the memory space of the target.
 *
 * @param first_call if true then start from the beginning, else continue unfinished task.
 * @param cmd contains the parameters for the connection
 * @return RESULT_OK if finished successfully else ERR_NOT_COMPLETED, or an error code.
 */
Result read_handler(command_typ* cmd, bool first_call);

/** writes a value to the memory space of the target.
 *
 * @param first_call if true then start from the beginning, else continue unfinished task.
 * @param cmd contains the parameters for the connection
 * @return RESULT_OK if finished successfully else ERR_NOT_COMPLETED, or an error code.
 */
Result write_handler(command_typ* cmd, bool first_call);

/** reads a value to the Access Port Register.
 *
 * @param first_call if true then start from the beginning, else continue unfinished task.
 * @param cmd contains the parameters for the connection
 * @return RESULT_OK if finished successfully else ERR_NOT_COMPLETED, or an error code.
 */
Result read_reg_handler(command_typ* cmd, bool first_call);

/** writes a value to the Access Port Register.
 *
 * @param first_call if true then start from the beginning, else continue unfinished task.
 * @param cmd contains the parameters for the connection
 * @return RESULT_OK if finished successfully else ERR_NOT_COMPLETED, or an error code.
 */
Result write_reg_handler(command_typ* cmd, bool first_call);

#endif /* SRC_SWD_SWD_PROTOCOL_H_ */
