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

/** System Handler Control and State Register
 * Controls and provides the status of system handlers.
 *
 * bit 15 : SVCALLPENDED: 0= SVCall is not pending; 1= SVCall is pending.
 */

#define SHCSR_SVCALLPENDED_MASK   0x8000
#define SHCSR_SVCALLPENDED_OFFSET 15

#define SHCSR                     ((uint32_t*)0xe000ed24)

/** Debug Fault Status Register
 * Provides the top level reason why a debug event has occurred
 *
 * bit 4: EXTERNAL: 1= EDBGRQ debug event
 * bit 3: VCATCH:   1= vector catch debug event
 * bit 2: DWTTRAP:  1= debug event generated by watch-point
 * bit 1: BKPT:     1= breakpoint event
 * bit 0: HALTED:   1= halt request (Halt or Step)
 *
 */

#define DFSR_EXTERNAL_MASK        0x10
#define DFSR_EXTERNAL_OFFSET      4

#define DFSR_VCATCH_MASK          8
#define DFSR_VCATCH_OFFSET        3

#define DFSR_DWTRAP_MASK          4
#define DFSR_DWTRAP_OFFSET        2

#define DFSR_BKPT_MASK            2
#define DFSR_BKPT_OFFSET          1

#define DFSR_HALTED_MASK          1
#define DFSR_HALTED_OFFSET        0

#define DFSR                      ((uint32_t*)0xe000ed30)

/** Debug Halting Control and Status Register
 * Controls halting debug.
 *
 * write only:
 * bit 31-16: DBGKEY must be 0xa05f to enable write access.
 *
 * read only:
 * bit 25: S_RESET_ST:  0= no reset since last DHCSR read                   1= at least one reset since last DHCSR read.
 * bit 24: S_RETIRE_ST: 0= no instruction executed since last DHCSR read;   1= at least one instruction executed since last DHCSR read.
 * bit 19: S_LOCKUP:    0= not locked up;                                   1= processor is locked up due to unrecoverable exception.
 * bit 18: S_SLEEP:     0= not sleeping;                                    1= sleeping
 * bit 17: S_HALT:      0= not in debug state;                              1= in Debug state.
 * bit 16: S_REGRDY:    0= There has been an incomplete write to the DCRDR; 1= The transfer to or from the DCRDR is complete.
 *
 * read and write:
 * bit 3: C_MASKINTS: 0= do not mask;                       1= Mask PendSV, SysTick and external configurable interrupts.
 * bit 2: C_STEP:     0= single stepping disabled;          1= single stepping enabled.
 * bit 1: C_HALT:     0= Request a halted processor to run; 1= Request a running processor to halt.
 * bit 0: C_DEBUGEN:  0= Halting debug disabled;            1= Halting debug enabled.
 *
 */

#define DHCSR_S_RESET_ST_MASK     0x2000000
#define DHCSR_S_RESET_ST_OFFSET   25

#define DHCSR_S_RETIRE_ST_MASK    0x1000000
#define DHCSR_S_RETIRE_ST_OFFSET  24

#define DHCSR_S_LOCKUP_MASK       0x80000
#define DHCSR_S_LOCKUP_OFFSET     19

#define DHCSR_S_SLEEP_MASK        0x40000
#define DHCSR_S_SLEEP_OFFSET      18

#define DHCSR_S_HALT_MASK         0x20000
#define DHCSR_S_HALT_OFFSET       17

#define DHCSR_S_REGRDY_MASK       0x10000
#define DHCSR_S_REGRDY_OFFSET     16

#define DHCSR_C_MASKINTS_MASK     8
#define DHCSR_C_MASKINTS_OFFSET   3

#define DHCSR_C_STEP_MASK         4
#define DHCSR_C_STEP_OFFSET       2

#define DHCSR_C_HALT_MASK         2
#define DHCSR_C_HALT_OFFSET       1

#define DHCSR_C_DEBUGEN_MASK      1
#define DHCSR_C_DEBUGEN_OFFSET    0

#define DHCSR                     ((uint32_t*)0xe000edf0)

#define DBGKEY                    0xa05f0000

/** Debug Core Register Selector Register
 *  bits 31..17 = reserved
 *  bit 16      = REGWnR (0 = read, 1 = write)
 *  bits 15..5  = reserved
 *  bits 4..0   = REGSEL specifies the register to transfer:
 *
 *  0 0 0 0 0  : R0
 *  0 0 0 0 1  : R1
 *  0 0 0 1 0  : R2
 *  0 0 0 1 1  : R3
 *  0 0 1 0 0  : R4
 *  0 0 1 0 1  : R5
 *  0 0 1 1 0  : R6
 *  0 0 1 1 1  : R7
 *  0 1 0 0 0  : R8
 *  0 1 0 0 1  : R9
 *  0 1 0 1 0  : R10
 *  0 1 0 1 1  : R11
 *  0 1 1 0 0  : R12
 *  0 1 1 0 1  : SP (current stack pointer)
 *  0 1 1 1 0  : LR
 *  0 1 1 1 1  : Debug Return Address (first instruction to be executed on exit from Debug state)
 *  1 0 0 0 0  : xPSR
 *  1 0 0 0 1  : MSP (Main Stack Pointer)
 *  1 0 0 1 0  : PSP (Process Stack Pointer)
 *  1 0 0 1 1  : reserved
 *  1 0 1 0 0  : CONTROL / PRIMASK
 *  1 0 1 0 1  : reserved
 *   . . . .   : reserved
 *  1 1 1 1 1  : reserved
 */

#define DCRSR_REGWNR_MASK         0x10000
#define DCRSR_REGWNR_OFFSET       16

#define DCRSR_REGSEL_MASK         0x1f
#define DCRSR_REGSEL_OFFSET       0

#define DCRSR_REGSEL_R0           0
#define DCRSR_REGSEL_R1           1
#define DCRSR_REGSEL_R2           2
#define DCRSR_REGSEL_R3           3
#define DCRSR_REGSEL_R4           4
#define DCRSR_REGSEL_R5           5
#define DCRSR_REGSEL_R6           6
#define DCRSR_REGSEL_R7           7
#define DCRSR_REGSEL_R8           8
#define DCRSR_REGSEL_R9           9
#define DCRSR_REGSEL_R10          10
#define DCRSR_REGSEL_R11          11
#define DCRSR_REGSEL_R12          12
#define DCRSR_REGSEL_SP           13
#define DCRSR_REGSEL_LR           14
#define DCRSR_REGSEL_DRA          15
#define DCRSR_REGSEL_XPSR         16
#define DCRSR_REGSEL_MSP          17
#define DCRSR_REGSEL_PSP          18
#define DCRSR_REGSEL_PRIMASK      20

#define DCRSR                     ((uint32_t*)0xe000edf4)

/** Debug Core Register Data Register
 *
 */
#define DCRDR                     ((uint32_t*)0xe000edf8)

/** Debug Exception and Monitor Control Register
 * Manages vector catch behavior and enables the DWT.
 *
 * bit 24: DWTENA:       0= DWT disabled;                 1= DWT enabled.
 * bit 10: VC_HARDERR:   0= haling on HardFault disabled; 1= halting on HardFault enabled.
 * bit 0:  VC_CORERESET: 0= Reset Vector Catch disabled;  1= Reset Vector Catch enabled.
 */

#define DEMCR_DWTENA_MASK         0x1000000
#define DEMCR_DWTENA_OFFSET       24
#define DEMCR_VC_HARDERR_MASK     0x400
#define DEMCR_VC_HARDERR_OFFSET   10
#define DEMCR_VC_CORERESET_MASK   0x1f
#define DEMCR_VC_CORERESET_OFFSET 0
#define DEMCR                     ((uint32_t*)0xe000edfc)

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
    "<thread id=\"1\" core=\"0\" name=\"main\">\r\n" \
        "main thread\r\n" \
    "</thread>\r\n" \
"</threads>\r\n"

#endif /* ARM_CORTEX_M_H_ */
