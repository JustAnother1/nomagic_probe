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
#ifndef PROBE_API_CLI_H_
#define PROBE_API_CLI_H_

#include <stdint.h>

/** get pointer to command line parameter string.
 *
 * @param parameter_index which parameter is requested
 * @return pointer to a 0 terminated string represented the requested parameter or NULL if no such parameter.
 */
uint8_t* cli_get_parameter(const uint32_t parameter_index);


#endif /* PROBE_API_CLI_H_ */
