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

#ifndef NOMAGIC_PROBE_SRC_LWIP_ARCH_CC_H_
#define NOMAGIC_PROBE_SRC_LWIP_ARCH_CC_H_

#include "hal/startup.h"
#include "hal/random.h"

#define LWIP_NO_CTYPE_H  1
#define LWIP_ERR_T       int32_t

// TODO

#define LWIP_CONST_CAST(target_type, val) ((target_type)val)

/** Define random number generator function of your system */
#define LWIP_RAND() ((u32_t)rosc_rand())

/** Platform specific diagnostic output.<br>
 * Note the default implementation pulls in printf, which may
 * in turn pull in a lot of standard library code. In resource-constrained
 * systems, this should be defined to something less resource-consuming.
 */
#define LWIP_PLATFORM_DIAG(x) do {printf x;} while(0)


/** Platform specific assertion handling.<br>
 * Note the default implementation pulls in printf, fflush and abort, which may
 * in turn pull in a lot of standard library code. In resource-constrained
 * systems, this should be defined to something less resource-consuming.
 */
#define LWIP_PLATFORM_ASSERT(x) do {printf("Assertion \"%s\" failed at line %d in %s\n", \
                                     x, __LINE__, __FILE__); error_state();} while(0)

#endif /* NOMAGIC_PROBE_SRC_LWIP_ARCH_CC_H_ */
