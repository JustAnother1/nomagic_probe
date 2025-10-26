/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_PPB_H
#define HW_PPB_H
/** Memory Block starting at 0xE0000000 + 0x0 is 0x10000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PPB_SYST_CSR_COUNTFLAG_OFFSET                      16u
#define PPB_SYST_CSR_COUNTFLAG_MASK                        0x10000u

#define PPB_SYST_CSR_CLKSOURCE_OFFSET                      2u
#define PPB_SYST_CSR_CLKSOURCE_MASK                        4u

#define PPB_SYST_CSR_TICKINT_OFFSET                        1u
#define PPB_SYST_CSR_TICKINT_MASK                          2u

#define PPB_SYST_CSR_ENABLE_OFFSET                         0u
#define PPB_SYST_CSR_ENABLE_MASK                           1u

#define PPB_SYST_RVR_RELOAD_OFFSET                         0u
#define PPB_SYST_RVR_RELOAD_MASK                           0xffffffu

#define PPB_SYST_CVR_CURRENT_OFFSET                        0u
#define PPB_SYST_CVR_CURRENT_MASK                          0xffffffu

#define PPB_SYST_CALIB_NOREF_OFFSET                        31u
#define PPB_SYST_CALIB_NOREF_MASK                          0x80000000u

#define PPB_SYST_CALIB_SKEW_OFFSET                         30u
#define PPB_SYST_CALIB_SKEW_MASK                           0x40000000u

#define PPB_SYST_CALIB_TENMS_OFFSET                        0u
#define PPB_SYST_CALIB_TENMS_MASK                          0xffffffu

#define PPB_NVIC_ISER_SETENA_OFFSET                        0u
#define PPB_NVIC_ISER_SETENA_MASK                          0xffffffffu

#define PPB_NVIC_ICER_CLRENA_OFFSET                        0u
#define PPB_NVIC_ICER_CLRENA_MASK                          0xffffffffu

#define PPB_NVIC_ISPR_SETPEND_OFFSET                       0u
#define PPB_NVIC_ISPR_SETPEND_MASK                         0xffffffffu

#define PPB_NVIC_ICPR_CLRPEND_OFFSET                       0u
#define PPB_NVIC_ICPR_CLRPEND_MASK                         0xffffffffu

#define PPB_NVIC_IPR0_IP_3_OFFSET                          30u
#define PPB_NVIC_IPR0_IP_3_MASK                            0xc0000000u

#define PPB_NVIC_IPR0_IP_2_OFFSET                          22u
#define PPB_NVIC_IPR0_IP_2_MASK                            0xc00000u

#define PPB_NVIC_IPR0_IP_1_OFFSET                          14u
#define PPB_NVIC_IPR0_IP_1_MASK                            0xc000u

#define PPB_NVIC_IPR0_IP_0_OFFSET                          6u
#define PPB_NVIC_IPR0_IP_0_MASK                            0xc0u

#define PPB_NVIC_IPR1_IP_7_OFFSET                          30u
#define PPB_NVIC_IPR1_IP_7_MASK                            0xc0000000u

#define PPB_NVIC_IPR1_IP_6_OFFSET                          22u
#define PPB_NVIC_IPR1_IP_6_MASK                            0xc00000u

#define PPB_NVIC_IPR1_IP_5_OFFSET                          14u
#define PPB_NVIC_IPR1_IP_5_MASK                            0xc000u

#define PPB_NVIC_IPR1_IP_4_OFFSET                          6u
#define PPB_NVIC_IPR1_IP_4_MASK                            0xc0u

#define PPB_NVIC_IPR2_IP_11_OFFSET                         30u
#define PPB_NVIC_IPR2_IP_11_MASK                           0xc0000000u

#define PPB_NVIC_IPR2_IP_10_OFFSET                         22u
#define PPB_NVIC_IPR2_IP_10_MASK                           0xc00000u

#define PPB_NVIC_IPR2_IP_9_OFFSET                          14u
#define PPB_NVIC_IPR2_IP_9_MASK                            0xc000u

#define PPB_NVIC_IPR2_IP_8_OFFSET                          6u
#define PPB_NVIC_IPR2_IP_8_MASK                            0xc0u

#define PPB_NVIC_IPR3_IP_15_OFFSET                         30u
#define PPB_NVIC_IPR3_IP_15_MASK                           0xc0000000u

#define PPB_NVIC_IPR3_IP_14_OFFSET                         22u
#define PPB_NVIC_IPR3_IP_14_MASK                           0xc00000u

#define PPB_NVIC_IPR3_IP_13_OFFSET                         14u
#define PPB_NVIC_IPR3_IP_13_MASK                           0xc000u

#define PPB_NVIC_IPR3_IP_12_OFFSET                         6u
#define PPB_NVIC_IPR3_IP_12_MASK                           0xc0u

#define PPB_NVIC_IPR4_IP_19_OFFSET                         30u
#define PPB_NVIC_IPR4_IP_19_MASK                           0xc0000000u

#define PPB_NVIC_IPR4_IP_18_OFFSET                         22u
#define PPB_NVIC_IPR4_IP_18_MASK                           0xc00000u

#define PPB_NVIC_IPR4_IP_17_OFFSET                         14u
#define PPB_NVIC_IPR4_IP_17_MASK                           0xc000u

#define PPB_NVIC_IPR4_IP_16_OFFSET                         6u
#define PPB_NVIC_IPR4_IP_16_MASK                           0xc0u

#define PPB_NVIC_IPR5_IP_23_OFFSET                         30u
#define PPB_NVIC_IPR5_IP_23_MASK                           0xc0000000u

#define PPB_NVIC_IPR5_IP_22_OFFSET                         22u
#define PPB_NVIC_IPR5_IP_22_MASK                           0xc00000u

#define PPB_NVIC_IPR5_IP_21_OFFSET                         14u
#define PPB_NVIC_IPR5_IP_21_MASK                           0xc000u

#define PPB_NVIC_IPR5_IP_20_OFFSET                         6u
#define PPB_NVIC_IPR5_IP_20_MASK                           0xc0u

#define PPB_NVIC_IPR6_IP_27_OFFSET                         30u
#define PPB_NVIC_IPR6_IP_27_MASK                           0xc0000000u

#define PPB_NVIC_IPR6_IP_26_OFFSET                         22u
#define PPB_NVIC_IPR6_IP_26_MASK                           0xc00000u

#define PPB_NVIC_IPR6_IP_25_OFFSET                         14u
#define PPB_NVIC_IPR6_IP_25_MASK                           0xc000u

#define PPB_NVIC_IPR6_IP_24_OFFSET                         6u
#define PPB_NVIC_IPR6_IP_24_MASK                           0xc0u

#define PPB_NVIC_IPR7_IP_31_OFFSET                         30u
#define PPB_NVIC_IPR7_IP_31_MASK                           0xc0000000u

#define PPB_NVIC_IPR7_IP_30_OFFSET                         22u
#define PPB_NVIC_IPR7_IP_30_MASK                           0xc00000u

#define PPB_NVIC_IPR7_IP_29_OFFSET                         14u
#define PPB_NVIC_IPR7_IP_29_MASK                           0xc000u

#define PPB_NVIC_IPR7_IP_28_OFFSET                         6u
#define PPB_NVIC_IPR7_IP_28_MASK                           0xc0u

#define PPB_CPUID_IMPLEMENTER_OFFSET                       24u
#define PPB_CPUID_IMPLEMENTER_MASK                         0xff000000u

#define PPB_CPUID_VARIANT_OFFSET                           20u
#define PPB_CPUID_VARIANT_MASK                             0xf00000u

#define PPB_CPUID_ARCHITECTURE_OFFSET                      16u
#define PPB_CPUID_ARCHITECTURE_MASK                        0xf0000u

#define PPB_CPUID_PARTNO_OFFSET                            4u
#define PPB_CPUID_PARTNO_MASK                              0xfff0u

#define PPB_CPUID_REVISION_OFFSET                          0u
#define PPB_CPUID_REVISION_MASK                            0xfu

#define PPB_ICSR_NMIPENDSET_OFFSET                         31u
#define PPB_ICSR_NMIPENDSET_MASK                           0x80000000u

#define PPB_ICSR_PENDSVSET_OFFSET                          28u
#define PPB_ICSR_PENDSVSET_MASK                            0x10000000u

#define PPB_ICSR_PENDSVCLR_OFFSET                          27u
#define PPB_ICSR_PENDSVCLR_MASK                            0x8000000u

#define PPB_ICSR_PENDSTSET_OFFSET                          26u
#define PPB_ICSR_PENDSTSET_MASK                            0x4000000u

#define PPB_ICSR_PENDSTCLR_OFFSET                          25u
#define PPB_ICSR_PENDSTCLR_MASK                            0x2000000u

#define PPB_ICSR_ISRPREEMPT_OFFSET                         23u
#define PPB_ICSR_ISRPREEMPT_MASK                           0x800000u

#define PPB_ICSR_ISRPENDING_OFFSET                         22u
#define PPB_ICSR_ISRPENDING_MASK                           0x400000u

#define PPB_ICSR_VECTPENDING_OFFSET                        12u
#define PPB_ICSR_VECTPENDING_MASK                          0x1ff000u

#define PPB_ICSR_VECTACTIVE_OFFSET                         0u
#define PPB_ICSR_VECTACTIVE_MASK                           0x1ffu

#define PPB_VTOR_TBLOFF_OFFSET                             8u
#define PPB_VTOR_TBLOFF_MASK                               0xffffff00u

#define PPB_AIRCR_VECTKEY_OFFSET                           16u
#define PPB_AIRCR_VECTKEY_MASK                             0xffff0000u

#define PPB_AIRCR_ENDIANESS_OFFSET                         15u
#define PPB_AIRCR_ENDIANESS_MASK                           0x8000u

#define PPB_AIRCR_SYSRESETREQ_OFFSET                       2u
#define PPB_AIRCR_SYSRESETREQ_MASK                         4u

#define PPB_AIRCR_VECTCLRACTIVE_OFFSET                     1u
#define PPB_AIRCR_VECTCLRACTIVE_MASK                       2u

#define PPB_SCR_SEVONPEND_OFFSET                           4u
#define PPB_SCR_SEVONPEND_MASK                             0x10u

#define PPB_SCR_SLEEPDEEP_OFFSET                           2u
#define PPB_SCR_SLEEPDEEP_MASK                             4u

#define PPB_SCR_SLEEPONEXIT_OFFSET                         1u
#define PPB_SCR_SLEEPONEXIT_MASK                           2u

#define PPB_CCR_STKALIGN_OFFSET                            9u
#define PPB_CCR_STKALIGN_MASK                              0x200u

#define PPB_CCR_UNALIGN_TRP_OFFSET                         3u
#define PPB_CCR_UNALIGN_TRP_MASK                           8u

#define PPB_SHPR2_PRI_11_OFFSET                            30u
#define PPB_SHPR2_PRI_11_MASK                              0xc0000000u

#define PPB_SHPR3_PRI_15_OFFSET                            30u
#define PPB_SHPR3_PRI_15_MASK                              0xc0000000u

#define PPB_SHPR3_PRI_14_OFFSET                            22u
#define PPB_SHPR3_PRI_14_MASK                              0xc00000u

#define PPB_SHCSR_SVCALLPENDED_OFFSET                      15u
#define PPB_SHCSR_SVCALLPENDED_MASK                        0x8000u

#define PPB_MPU_TYPE_IREGION_OFFSET                        16u
#define PPB_MPU_TYPE_IREGION_MASK                          0xff0000u

#define PPB_MPU_TYPE_DREGION_OFFSET                        8u
#define PPB_MPU_TYPE_DREGION_MASK                          0xff00u

#define PPB_MPU_TYPE_SEPARATE_OFFSET                       0u
#define PPB_MPU_TYPE_SEPARATE_MASK                         1u

#define PPB_MPU_CTRL_PRIVDEFENA_OFFSET                     2u
#define PPB_MPU_CTRL_PRIVDEFENA_MASK                       4u

#define PPB_MPU_CTRL_HFNMIENA_OFFSET                       1u
#define PPB_MPU_CTRL_HFNMIENA_MASK                         2u

#define PPB_MPU_CTRL_ENABLE_OFFSET                         0u
#define PPB_MPU_CTRL_ENABLE_MASK                           1u

#define PPB_MPU_RNR_REGION_OFFSET                          0u
#define PPB_MPU_RNR_REGION_MASK                            0xfu

#define PPB_MPU_RBAR_ADDR_OFFSET                           8u
#define PPB_MPU_RBAR_ADDR_MASK                             0xffffff00u

#define PPB_MPU_RBAR_VALID_OFFSET                          4u
#define PPB_MPU_RBAR_VALID_MASK                            0x10u

#define PPB_MPU_RBAR_REGION_OFFSET                         0u
#define PPB_MPU_RBAR_REGION_MASK                           0xfu

#define PPB_MPU_RASR_ATTRS_OFFSET                          16u
#define PPB_MPU_RASR_ATTRS_MASK                            0xffff0000u

#define PPB_MPU_RASR_SRD_OFFSET                            8u
#define PPB_MPU_RASR_SRD_MASK                              0xff00u

#define PPB_MPU_RASR_SIZE_OFFSET                           1u
#define PPB_MPU_RASR_SIZE_MASK                             0x3eu

#define PPB_MPU_RASR_ENABLE_OFFSET                         0u
#define PPB_MPU_RASR_ENABLE_MASK                           1u


typedef struct
{
volatile uint32_t reserved0[14340];

/** SYST_CSR (offset: 0xe010)
  Use the SysTick Control and Status Register to enable the SysTick features.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: COUNTFLAG
  offset: 16, size: 1, access: read-only
  Returns 1 if timer counted to 0 since last time this was read. Clears on read by application or debugger.
  Field: CLKSOURCE
  offset: 2, size: 1, access: read-write
  SysTick clock source. Always reads as one if SYST_CALIB reports NOREF.

 Selects the SysTick timer clock source:

 0 = External reference clock.

 1 = Processor clock.
  Field: TICKINT
  offset: 1, size: 1, access: read-write
  Enables SysTick exception request:

 0 = Counting down to zero does not assert the SysTick exception request.

 1 = Counting down to zero to asserts the SysTick exception request.
  Field: ENABLE
  offset: 0, size: 1, access: read-write
  Enable SysTick counter:

 0 = Counter disabled.

 1 = Counter enabled.
*/
volatile uint32_t SYST_CSR;

/** SYST_RVR (offset: 0xe014)
  Use the SysTick Reload Value Register to specify the start value to load into the current value register when the counter reaches 0. It can be any value between 0 and 0x00FFFFFF. A start value of 0 is possible, but has no effect because the SysTick interrupt and COUNTFLAG are activated when counting from 1 to 0. The reset value of this register is UNKNOWN.

 To generate a multi-shot timer with a period of N processor clock cycles, use a RELOAD value of N-1. For example, if the SysTick interrupt is required every 100 clock pulses, set RELOAD to 99.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RELOAD
  offset: 0, size: 24, access: read-write
  Value to load into the SysTick Current Value Register when the counter reaches 0.
*/
volatile uint32_t SYST_RVR;

/** SYST_CVR (offset: 0xe018)
  Use the SysTick Current Value Register to find the current value in the register. The reset value of this register is UNKNOWN.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CURRENT
  offset: 0, size: 24, access: read-write
  Reads return the current value of the SysTick counter. This register is write-clear. Writing to it with any value clears the register to 0. Clearing this register also clears the COUNTFLAG bit of the SysTick Control and Status Register.
*/
volatile uint32_t SYST_CVR;

/** SYST_CALIB (offset: 0xe01c)
  Use the SysTick Calibration Value Register to enable software to scale to any required speed using divide and multiply.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NOREF
  offset: 31, size: 1, access: read-only
  If reads as 1, the Reference clock is not provided - the CLKSOURCE bit of the SysTick Control and Status register will be forced to 1 and cannot be cleared to 0.
  Field: SKEW
  offset: 30, size: 1, access: read-only
  If reads as 1, the calibration value for 10ms is inexact (due to clock frequency).
  Field: TENMS
  offset: 0, size: 24, access: read-only
  An optional Reload value to be used for 10ms (100Hz) timing, subject to system clock skew errors. If the value reads as 0, the calibration value is not known.
*/
volatile uint32_t SYST_CALIB;
volatile uint32_t reserved1[56];

/** NVIC_ISER (offset: 0xe100)
  Use the Interrupt Set-Enable Register to enable interrupts and determine which interrupts are currently enabled.

 If a pending interrupt is enabled, the NVIC activates the interrupt based on its priority. If an interrupt is not enabled, asserting its interrupt signal changes the interrupt state to pending, but the NVIC never activates the interrupt, regardless of its priority.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SETENA
  offset: 0, size: 32, access: read-write
  Interrupt set-enable bits.

 Write:

 0 = No effect.

 1 = Enable interrupt.

 Read:

 0 = Interrupt disabled.

 1 = Interrupt enabled.
*/
volatile uint32_t NVIC_ISER;
volatile uint32_t reserved2[31];

/** NVIC_ICER (offset: 0xe180)
  Use the Interrupt Clear-Enable Registers to disable interrupts and determine which interrupts are currently enabled.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLRENA
  offset: 0, size: 32, access: read-write
  Interrupt clear-enable bits.

 Write:

 0 = No effect.

 1 = Disable interrupt.

 Read:

 0 = Interrupt disabled.

 1 = Interrupt enabled.
*/
volatile uint32_t NVIC_ICER;
volatile uint32_t reserved3[31];

/** NVIC_ISPR (offset: 0xe200)
  The NVIC_ISPR forces interrupts into the pending state, and shows which interrupts are pending.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SETPEND
  offset: 0, size: 32, access: read-write
  Interrupt set-pending bits.

 Write:

 0 = No effect.

 1 = Changes interrupt state to pending.

 Read:

 0 = Interrupt is not pending.

 1 = Interrupt is pending.

 Note: Writing 1 to the NVIC_ISPR bit corresponding to:

 An interrupt that is pending has no effect.

 A disabled interrupt sets the state of that interrupt to pending.
*/
volatile uint32_t NVIC_ISPR;
volatile uint32_t reserved4[31];

/** NVIC_ICPR (offset: 0xe280)
  Use the Interrupt Clear-Pending Register to clear pending interrupts and determine which interrupts are currently pending.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLRPEND
  offset: 0, size: 32, access: read-write
  Interrupt clear-pending bits.

 Write:

 0 = No effect.

 1 = Removes pending state and interrupt.

 Read:

 0 = Interrupt is not pending.

 1 = Interrupt is pending.
*/
volatile uint32_t NVIC_ICPR;
volatile uint32_t reserved5[95];

/** NVIC_IPR
NVIC_IPR[0] (offset: 0xe400)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.

 Note: Writing 1 to an NVIC_ICPR bit does not affect the active state of the corresponding interrupt.

 These registers are only word-accessible
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_3
  offset: 30, size: 2, access: read-write
  Priority of interrupt 3
  Field: IP_2
  offset: 22, size: 2, access: read-write
  Priority of interrupt 2
  Field: IP_1
  offset: 14, size: 2, access: read-write
  Priority of interrupt 1
  Field: IP_0
  offset: 6, size: 2, access: read-write
  Priority of interrupt 0

NVIC_IPR[1] (offset: 0xe404)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_7
  offset: 30, size: 2, access: read-write
  Priority of interrupt 7
  Field: IP_6
  offset: 22, size: 2, access: read-write
  Priority of interrupt 6
  Field: IP_5
  offset: 14, size: 2, access: read-write
  Priority of interrupt 5
  Field: IP_4
  offset: 6, size: 2, access: read-write
  Priority of interrupt 4

NVIC_IPR[2] (offset: 0xe408)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_11
  offset: 30, size: 2, access: read-write
  Priority of interrupt 11
  Field: IP_10
  offset: 22, size: 2, access: read-write
  Priority of interrupt 10
  Field: IP_9
  offset: 14, size: 2, access: read-write
  Priority of interrupt 9
  Field: IP_8
  offset: 6, size: 2, access: read-write
  Priority of interrupt 8

NVIC_IPR[3] (offset: 0xe40c)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_15
  offset: 30, size: 2, access: read-write
  Priority of interrupt 15
  Field: IP_14
  offset: 22, size: 2, access: read-write
  Priority of interrupt 14
  Field: IP_13
  offset: 14, size: 2, access: read-write
  Priority of interrupt 13
  Field: IP_12
  offset: 6, size: 2, access: read-write
  Priority of interrupt 12

NVIC_IPR[4] (offset: 0xe410)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_19
  offset: 30, size: 2, access: read-write
  Priority of interrupt 19
  Field: IP_18
  offset: 22, size: 2, access: read-write
  Priority of interrupt 18
  Field: IP_17
  offset: 14, size: 2, access: read-write
  Priority of interrupt 17
  Field: IP_16
  offset: 6, size: 2, access: read-write
  Priority of interrupt 16

NVIC_IPR[5] (offset: 0xe414)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_23
  offset: 30, size: 2, access: read-write
  Priority of interrupt 23
  Field: IP_22
  offset: 22, size: 2, access: read-write
  Priority of interrupt 22
  Field: IP_21
  offset: 14, size: 2, access: read-write
  Priority of interrupt 21
  Field: IP_20
  offset: 6, size: 2, access: read-write
  Priority of interrupt 20

NVIC_IPR[6] (offset: 0xe418)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_27
  offset: 30, size: 2, access: read-write
  Priority of interrupt 27
  Field: IP_26
  offset: 22, size: 2, access: read-write
  Priority of interrupt 26
  Field: IP_25
  offset: 14, size: 2, access: read-write
  Priority of interrupt 25
  Field: IP_24
  offset: 6, size: 2, access: read-write
  Priority of interrupt 24

NVIC_IPR[7] (offset: 0xe41c)
  Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. 0 is the highest priority, and 3 is the lowest.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IP_31
  offset: 30, size: 2, access: read-write
  Priority of interrupt 31
  Field: IP_30
  offset: 22, size: 2, access: read-write
  Priority of interrupt 30
  Field: IP_29
  offset: 14, size: 2, access: read-write
  Priority of interrupt 29
  Field: IP_28
  offset: 6, size: 2, access: read-write
  Priority of interrupt 28

*/
volatile uint32_t NVIC_IPR[8];
volatile uint32_t reserved6[568];

/** CPUID (offset: 0xed00)
  Read the CPU ID Base Register to determine: the ID number of the processor core, the version number of the processor core, the implementation details of the processor core.
  access : read-write
  reset value : 0x410CC601
  reset mask : 0x0
  Field: IMPLEMENTER
  offset: 24, size: 8, access: read-only
  Implementor code: 0x41 = ARM
  Field: VARIANT
  offset: 20, size: 4, access: read-only
  Major revision number n in the rnpm revision status:

 0x0 = Revision 0.
  Field: ARCHITECTURE
  offset: 16, size: 4, access: read-only
  Constant that defines the architecture of the processor:

 0xC = ARMv6-M architecture.
  Field: PARTNO
  offset: 4, size: 12, access: read-only
  Number of processor within family: 0xC60 = Cortex-M0+
  Field: REVISION
  offset: 0, size: 4, access: read-only
  Minor revision number m in the rnpm revision status:

 0x1 = Patch 1.
*/
volatile uint32_t CPUID;

/** ICSR (offset: 0xed04)
  Use the Interrupt Control State Register to set a pending Non-Maskable Interrupt (NMI), set or clear a pending PendSV, set or clear a pending SysTick, check for pending exceptions, check the vector number of the highest priority pended exception, check the vector number of the active exception.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NMIPENDSET
  offset: 31, size: 1, access: read-write
  Setting this bit will activate an NMI. Since NMI is the highest priority exception, it will activate as soon as it is registered.

 NMI set-pending bit.

 Write:

 0 = No effect.

 1 = Changes NMI exception state to pending.

 Read:

 0 = NMI exception is not pending.

 1 = NMI exception is pending.

 Because NMI is the highest-priority exception, normally the processor enters the NMI

 exception handler as soon as it detects a write of 1 to this bit. Entering the handler then clears

 this bit to 0. This means a read of this bit by the NMI exception handler returns 1 only if the

 NMI signal is reasserted while the processor is executing that handler.
  Field: PENDSVSET
  offset: 28, size: 1, access: read-write
  PendSV set-pending bit.

 Write:

 0 = No effect.

 1 = Changes PendSV exception state to pending.

 Read:

 0 = PendSV exception is not pending.

 1 = PendSV exception is pending.

 Writing 1 to this bit is the only way to set the PendSV exception state to pending.
  Field: PENDSVCLR
  offset: 27, size: 1, access: read-write
  PendSV clear-pending bit.

 Write:

 0 = No effect.

 1 = Removes the pending state from the PendSV exception.
  Field: PENDSTSET
  offset: 26, size: 1, access: read-write
  SysTick exception set-pending bit.

 Write:

 0 = No effect.

 1 = Changes SysTick exception state to pending.

 Read:

 0 = SysTick exception is not pending.

 1 = SysTick exception is pending.
  Field: PENDSTCLR
  offset: 25, size: 1, access: read-write
  SysTick exception clear-pending bit.

 Write:

 0 = No effect.

 1 = Removes the pending state from the SysTick exception.

 This bit is WO. On a register read its value is Unknown.
  Field: ISRPREEMPT
  offset: 23, size: 1, access: read-only
  The system can only access this bit when the core is halted. It indicates that a pending interrupt is to be taken in the next running cycle. If C_MASKINTS is clear in the Debug Halting Control and Status Register, the interrupt is serviced.
  Field: ISRPENDING
  offset: 22, size: 1, access: read-only
  External interrupt pending flag
  Field: VECTPENDING
  offset: 12, size: 9, access: read-only
  Indicates the exception number for the highest priority pending exception: 0 = no pending exceptions. Non zero = The pending state includes the effect of memory-mapped enable and mask registers. It does not include the PRIMASK special-purpose register qualifier.
  Field: VECTACTIVE
  offset: 0, size: 9, access: read-only
  Active exception number field. Reset clears the VECTACTIVE field.
*/
volatile uint32_t ICSR;

/** VTOR (offset: 0xed08)
  The VTOR holds the vector table offset address.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TBLOFF
  offset: 8, size: 24, access: read-write
  Bits [31:8] of the indicate the vector table offset address.
*/
volatile uint32_t VTOR;

/** AIRCR (offset: 0xed0c)
  Use the Application Interrupt and Reset Control Register to: determine data endianness, clear all active state information from debug halt mode, request a system reset.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: VECTKEY
  offset: 16, size: 16, access: read-write
  Register key:

 Reads as Unknown

 On writes, write 0x05FA to VECTKEY, otherwise the write is ignored.
  Field: ENDIANESS
  offset: 15, size: 1, access: read-only
  Data endianness implemented:

 0 = Little-endian.
  Field: SYSRESETREQ
  offset: 2, size: 1, access: read-write
  Writing 1 to this bit causes the SYSRESETREQ signal to the outer system to be asserted to request a reset. The intention is to force a large system reset of all major components except for debug. The C_HALT bit in the DHCSR is cleared as a result of the system reset requested. The debugger does not lose contact with the device.
  Field: VECTCLRACTIVE
  offset: 1, size: 1, access: read-write
  Clears all active state information for fixed and configurable exceptions. This bit: is self-clearing, can only be set by the DAP when the core is halted. When set: clears all active exception status of the processor, forces a return to Thread mode, forces an IPSR of 0. A debugger must re-initialize the stack.
*/
volatile uint32_t AIRCR;

/** SCR (offset: 0xed10)
  System Control Register. Use the System Control Register for power-management functions: signal to the system when the processor can enter a low power state, control how the processor enters and exits low power states.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SEVONPEND
  offset: 4, size: 1, access: read-write
  Send Event on Pending bit:

 0 = Only enabled interrupts or events can wakeup the processor, disabled interrupts are excluded.

 1 = Enabled events and all interrupts, including disabled interrupts, can wakeup the processor.

 When an event or interrupt becomes pending, the event signal wakes up the processor from WFE. If the

 processor is not waiting for an event, the event is registered and affects the next WFE.

 The processor also wakes up on execution of an SEV instruction or an external event.
  Field: SLEEPDEEP
  offset: 2, size: 1, access: read-write
  Controls whether the processor uses sleep or deep sleep as its low power mode:

 0 = Sleep.

 1 = Deep sleep.
  Field: SLEEPONEXIT
  offset: 1, size: 1, access: read-write
  Indicates sleep-on-exit when returning from Handler mode to Thread mode:

 0 = Do not sleep when returning to Thread mode.

 1 = Enter sleep, or deep sleep, on return from an ISR to Thread mode.

 Setting this bit to 1 enables an interrupt driven application to avoid returning to an empty main application.
*/
volatile uint32_t SCR;

/** CCR (offset: 0xed14)
  The Configuration and Control Register permanently enables stack alignment and causes unaligned accesses to result in a Hard Fault.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: STKALIGN
  offset: 9, size: 1, access: read-only
  Always reads as one, indicates 8-byte stack alignment on exception entry. On exception entry, the processor uses bit[9] of the stacked PSR to indicate the stack alignment. On return from the exception it uses this stacked bit to restore the correct stack alignment.
  Field: UNALIGN_TRP
  offset: 3, size: 1, access: read-only
  Always reads as one, indicates that all unaligned accesses generate a HardFault.
*/
volatile uint32_t CCR;
volatile uint32_t reserved7;

/** SHPR2 (offset: 0xed1c)
  System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Use the System Handler Priority Register 2 to set the priority of SVCall.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PRI_11
  offset: 30, size: 2, access: read-write
  Priority of system handler 11, SVCall
*/
volatile uint32_t SHPR2;

/** SHPR3 (offset: 0xed20)
  System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Use the System Handler Priority Register 3 to set the priority of PendSV and SysTick.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PRI_15
  offset: 30, size: 2, access: read-write
  Priority of system handler 15, SysTick
  Field: PRI_14
  offset: 22, size: 2, access: read-write
  Priority of system handler 14, PendSV
*/
volatile uint32_t SHPR3;

/** SHCSR (offset: 0xed24)
  Use the System Handler Control and State Register to determine or clear the pending status of SVCall.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SVCALLPENDED
  offset: 15, size: 1, access: read-write
  Reads as 1 if SVCall is Pending. Write 1 to set pending SVCall, write 0 to clear pending SVCall.
*/
volatile uint32_t SHCSR;
volatile uint32_t reserved8[26];

/** MPU_TYPE (offset: 0xed90)
  Read the MPU Type Register to determine if the processor implements an MPU, and how many regions the MPU supports.
  access : read-write
  reset value : 0x800
  reset mask : 0x0
  Field: IREGION
  offset: 16, size: 8, access: read-only
  Instruction region. Reads as zero as ARMv6-M only supports a unified MPU.
  Field: DREGION
  offset: 8, size: 8, access: read-only
  Number of regions supported by the MPU.
  Field: SEPARATE
  offset: 0, size: 1, access: read-only
  Indicates support for separate instruction and data address maps. Reads as 0 as ARMv6-M only supports a unified MPU.
*/
volatile uint32_t MPU_TYPE;

/** MPU_CTRL (offset: 0xed94)
  Use the MPU Control Register to enable and disable the MPU, and to control whether the default memory map is enabled as a background region for privileged accesses, and whether the MPU is enabled for HardFaults and NMIs.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PRIVDEFENA
  offset: 2, size: 1, access: read-write
  Controls whether the default memory map is enabled as a background region for privileged accesses. This bit is ignored when ENABLE is clear.

 0 = If the MPU is enabled, disables use of the default memory map. Any memory access to a location not

 covered by any enabled region causes a fault.

 1 = If the MPU is enabled, enables use of the default memory map as a background region for privileged software accesses.

 When enabled, the background region acts as if it is region number -1. Any region that is defined and enabled has priority over this default map.
  Field: HFNMIENA
  offset: 1, size: 1, access: read-write
  Controls the use of the MPU for HardFaults and NMIs. Setting this bit when ENABLE is clear results in UNPREDICTABLE behaviour.

 When the MPU is enabled:

 0 = MPU is disabled during HardFault and NMI handlers, regardless of the value of the ENABLE bit.

 1 = the MPU is enabled during HardFault and NMI handlers.
  Field: ENABLE
  offset: 0, size: 1, access: read-write
  Enables the MPU. If the MPU is disabled, privileged and unprivileged accesses use the default memory map.

 0 = MPU disabled.

 1 = MPU enabled.
*/
volatile uint32_t MPU_CTRL;

/** MPU_RNR (offset: 0xed98)
  Use the MPU Region Number Register to select the region currently accessed by MPU_RBAR and MPU_RASR.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: REGION
  offset: 0, size: 4, access: read-write
  Indicates the MPU region referenced by the MPU_RBAR and MPU_RASR registers.

 The MPU supports 8 memory regions, so the permitted values of this field are 0-7.
*/
volatile uint32_t MPU_RNR;

/** MPU_RBAR (offset: 0xed9c)
  Read the MPU Region Base Address Register to determine the base address of the region identified by MPU_RNR. Write to update the base address of said region or that of a specified region, with whose number MPU_RNR will also be updated.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ADDR
  offset: 8, size: 24, access: read-write
  Base address of the region.
  Field: VALID
  offset: 4, size: 1, access: read-write
  On writes, indicates whether the write must update the base address of the region identified by the REGION field, updating the MPU_RNR to indicate this new region.

 Write:

 0 = MPU_RNR not changed, and the processor:

 Updates the base address for the region specified in the MPU_RNR.

 Ignores the value of the REGION field.

 1 = The processor:

 Updates the value of the MPU_RNR to the value of the REGION field.

 Updates the base address for the region specified in the REGION field.

 Always reads as zero.
  Field: REGION
  offset: 0, size: 4, access: read-write
  On writes, specifies the number of the region whose base address to update provided VALID is set written as 1. On reads, returns bits [3:0] of MPU_RNR.
*/
volatile uint32_t MPU_RBAR;

/** MPU_RASR (offset: 0xeda0)
  Use the MPU Region Attribute and Size Register to define the size, access behaviour and memory type of the region identified by MPU_RNR, and enable that region.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ATTRS
  offset: 16, size: 16, access: read-write
  The MPU Region Attribute field. Use to define the region attribute control.

 28 = XN: Instruction access disable bit:

 0 = Instruction fetches enabled.

 1 = Instruction fetches disabled.

 26:24 = AP: Access permission field

 18 = S: Shareable bit

 17 = C: Cacheable bit

 16 = B: Bufferable bit
  Field: SRD
  offset: 8, size: 8, access: read-write
  Subregion Disable. For regions of 256 bytes or larger, each bit of this field controls whether one of the eight equal subregions is enabled.
  Field: SIZE
  offset: 1, size: 5, access: read-write
  Indicates the region size. Region size in bytes = 2^(SIZE+1). The minimum permitted value is 7 (b00111) = 256Bytes
  Field: ENABLE
  offset: 0, size: 1, access: read-write
  Enables the region.
*/
volatile uint32_t MPU_RASR;
} PPB_type;

#define PPB ((PPB_type *) 0xE0000000)

#endif // HW_PPB_H
