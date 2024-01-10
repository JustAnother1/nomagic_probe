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

#ifndef ARM_CORTEX_M_H_
#define ARM_CORTEX_M_H_

#include "result.h"

#define TARGET_XML_CONTENT  \
"<?xml version=\"1.0\"?>\r\n" \
"<!DOCTYPE target SYSTEM \"gdb-target.dtd\">\r\n" \
"<target version=\"1.0\">\r\n" \
"<architecture>arm</architecture>\r\n" \
"<feature name=\"org.gnu.gdb.arm.m-profile\">\r\n" \
"<reg name=\"r0\" bitsize=\"32\" regnum=\"0\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r1\" bitsize=\"32\" regnum=\"1\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r2\" bitsize=\"32\" regnum=\"2\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r3\" bitsize=\"32\" regnum=\"3\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r4\" bitsize=\"32\" regnum=\"4\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r5\" bitsize=\"32\" regnum=\"5\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r6\" bitsize=\"32\" regnum=\"6\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r7\" bitsize=\"32\" regnum=\"7\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r8\" bitsize=\"32\" regnum=\"8\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r9\" bitsize=\"32\" regnum=\"9\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r10\" bitsize=\"32\" regnum=\"10\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r11\" bitsize=\"32\" regnum=\"11\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"r12\" bitsize=\"32\" regnum=\"12\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"sp\" bitsize=\"32\" regnum=\"13\" save-restore=\"yes\" type=\"data_ptr\" group=\"general\"/>\r\n" \
"<reg name=\"lr\" bitsize=\"32\" regnum=\"14\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"<reg name=\"pc\" bitsize=\"32\" regnum=\"15\" save-restore=\"yes\" type=\"code_ptr\" group=\"general\"/>\r\n" \
"<reg name=\"xPSR\" bitsize=\"32\" regnum=\"16\" save-restore=\"yes\" type=\"int\" group=\"general\"/>\r\n" \
"</feature>\r\n" \
"<feature name=\"org.gnu.gdb.arm.m-system\">\r\n" \
"<reg name=\"msp\" bitsize=\"32\" regnum=\"17\" save-restore=\"yes\" type=\"data_ptr\" group=\"system\"/>\r\n" \
"<reg name=\"psp\" bitsize=\"32\" regnum=\"18\" save-restore=\"yes\" type=\"data_ptr\" group=\"system\"/>\r\n" \
"<reg name=\"primask\" bitsize=\"1\" regnum=\"20\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"basepri\" bitsize=\"8\" regnum=\"21\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"faultmask\" bitsize=\"1\" regnum=\"22\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"<reg name=\"control\" bitsize=\"3\" regnum=\"23\" save-restore=\"yes\" type=\"int8\" group=\"system\"/>\r\n" \
"</feature>\r\n" \
"</target>\r\n"


#define THREADS_CONTENT  \
"<?xml version=\"1.0\"?>\r\n" \
"<threads>\r\n" \
"</threads>\r\n"

Result cotex_m_add_general_registers(Result phase);

#endif /* ARM_CORTEX_M_H_ */
