/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_PWM_H
#define HW_PWM_H
/** Simple PWM */
/** Interrupt : PWM_IRQ_WRAP (Vector: 4)  */
/** Memory Block starting at 0x40050000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PWM_CH0_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH0_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH0_CSR_PH_RET_OFFSET                          6u
#define PWM_CH0_CSR_PH_RET_MASK                            0x40u

#define PWM_CH0_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH0_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH0_CSR_DIVMODE_DIV                            0u
#define PWM_CH0_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH0_CSR_DIVMODE_RISE                           2u
#define PWM_CH0_CSR_DIVMODE_FALL                           3u

#define PWM_CH0_CSR_B_INV_OFFSET                           3u
#define PWM_CH0_CSR_B_INV_MASK                             8u

#define PWM_CH0_CSR_A_INV_OFFSET                           2u
#define PWM_CH0_CSR_A_INV_MASK                             4u

#define PWM_CH0_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH0_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH0_CSR_EN_OFFSET                              0u
#define PWM_CH0_CSR_EN_MASK                                1u

#define PWM_CH0_DIV_INT_OFFSET                             4u
#define PWM_CH0_DIV_INT_MASK                               0xff0u

#define PWM_CH0_DIV_FRAC_OFFSET                            0u
#define PWM_CH0_DIV_FRAC_MASK                              0xfu

#define PWM_CH0_CTR_CH0_CTR_OFFSET                         0u
#define PWM_CH0_CTR_CH0_CTR_MASK                           0xffffu

#define PWM_CH0_CC_B_OFFSET                                16u
#define PWM_CH0_CC_B_MASK                                  0xffff0000u

#define PWM_CH0_CC_A_OFFSET                                0u
#define PWM_CH0_CC_A_MASK                                  0xffffu

#define PWM_CH0_TOP_CH0_TOP_OFFSET                         0u
#define PWM_CH0_TOP_CH0_TOP_MASK                           0xffffu

#define PWM_CH1_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH1_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH1_CSR_PH_RET_OFFSET                          6u
#define PWM_CH1_CSR_PH_RET_MASK                            0x40u

#define PWM_CH1_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH1_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH1_CSR_DIVMODE_DIV                            0u
#define PWM_CH1_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH1_CSR_DIVMODE_RISE                           2u
#define PWM_CH1_CSR_DIVMODE_FALL                           3u

#define PWM_CH1_CSR_B_INV_OFFSET                           3u
#define PWM_CH1_CSR_B_INV_MASK                             8u

#define PWM_CH1_CSR_A_INV_OFFSET                           2u
#define PWM_CH1_CSR_A_INV_MASK                             4u

#define PWM_CH1_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH1_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH1_CSR_EN_OFFSET                              0u
#define PWM_CH1_CSR_EN_MASK                                1u

#define PWM_CH1_DIV_INT_OFFSET                             4u
#define PWM_CH1_DIV_INT_MASK                               0xff0u

#define PWM_CH1_DIV_FRAC_OFFSET                            0u
#define PWM_CH1_DIV_FRAC_MASK                              0xfu

#define PWM_CH1_CTR_CH1_CTR_OFFSET                         0u
#define PWM_CH1_CTR_CH1_CTR_MASK                           0xffffu

#define PWM_CH1_CC_B_OFFSET                                16u
#define PWM_CH1_CC_B_MASK                                  0xffff0000u

#define PWM_CH1_CC_A_OFFSET                                0u
#define PWM_CH1_CC_A_MASK                                  0xffffu

#define PWM_CH1_TOP_CH1_TOP_OFFSET                         0u
#define PWM_CH1_TOP_CH1_TOP_MASK                           0xffffu

#define PWM_CH2_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH2_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH2_CSR_PH_RET_OFFSET                          6u
#define PWM_CH2_CSR_PH_RET_MASK                            0x40u

#define PWM_CH2_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH2_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH2_CSR_DIVMODE_DIV                            0u
#define PWM_CH2_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH2_CSR_DIVMODE_RISE                           2u
#define PWM_CH2_CSR_DIVMODE_FALL                           3u

#define PWM_CH2_CSR_B_INV_OFFSET                           3u
#define PWM_CH2_CSR_B_INV_MASK                             8u

#define PWM_CH2_CSR_A_INV_OFFSET                           2u
#define PWM_CH2_CSR_A_INV_MASK                             4u

#define PWM_CH2_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH2_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH2_CSR_EN_OFFSET                              0u
#define PWM_CH2_CSR_EN_MASK                                1u

#define PWM_CH2_DIV_INT_OFFSET                             4u
#define PWM_CH2_DIV_INT_MASK                               0xff0u

#define PWM_CH2_DIV_FRAC_OFFSET                            0u
#define PWM_CH2_DIV_FRAC_MASK                              0xfu

#define PWM_CH2_CTR_CH2_CTR_OFFSET                         0u
#define PWM_CH2_CTR_CH2_CTR_MASK                           0xffffu

#define PWM_CH2_CC_B_OFFSET                                16u
#define PWM_CH2_CC_B_MASK                                  0xffff0000u

#define PWM_CH2_CC_A_OFFSET                                0u
#define PWM_CH2_CC_A_MASK                                  0xffffu

#define PWM_CH2_TOP_CH2_TOP_OFFSET                         0u
#define PWM_CH2_TOP_CH2_TOP_MASK                           0xffffu

#define PWM_CH3_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH3_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH3_CSR_PH_RET_OFFSET                          6u
#define PWM_CH3_CSR_PH_RET_MASK                            0x40u

#define PWM_CH3_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH3_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH3_CSR_DIVMODE_DIV                            0u
#define PWM_CH3_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH3_CSR_DIVMODE_RISE                           2u
#define PWM_CH3_CSR_DIVMODE_FALL                           3u

#define PWM_CH3_CSR_B_INV_OFFSET                           3u
#define PWM_CH3_CSR_B_INV_MASK                             8u

#define PWM_CH3_CSR_A_INV_OFFSET                           2u
#define PWM_CH3_CSR_A_INV_MASK                             4u

#define PWM_CH3_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH3_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH3_CSR_EN_OFFSET                              0u
#define PWM_CH3_CSR_EN_MASK                                1u

#define PWM_CH3_DIV_INT_OFFSET                             4u
#define PWM_CH3_DIV_INT_MASK                               0xff0u

#define PWM_CH3_DIV_FRAC_OFFSET                            0u
#define PWM_CH3_DIV_FRAC_MASK                              0xfu

#define PWM_CH3_CTR_CH3_CTR_OFFSET                         0u
#define PWM_CH3_CTR_CH3_CTR_MASK                           0xffffu

#define PWM_CH3_CC_B_OFFSET                                16u
#define PWM_CH3_CC_B_MASK                                  0xffff0000u

#define PWM_CH3_CC_A_OFFSET                                0u
#define PWM_CH3_CC_A_MASK                                  0xffffu

#define PWM_CH3_TOP_CH3_TOP_OFFSET                         0u
#define PWM_CH3_TOP_CH3_TOP_MASK                           0xffffu

#define PWM_CH4_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH4_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH4_CSR_PH_RET_OFFSET                          6u
#define PWM_CH4_CSR_PH_RET_MASK                            0x40u

#define PWM_CH4_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH4_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH4_CSR_DIVMODE_DIV                            0u
#define PWM_CH4_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH4_CSR_DIVMODE_RISE                           2u
#define PWM_CH4_CSR_DIVMODE_FALL                           3u

#define PWM_CH4_CSR_B_INV_OFFSET                           3u
#define PWM_CH4_CSR_B_INV_MASK                             8u

#define PWM_CH4_CSR_A_INV_OFFSET                           2u
#define PWM_CH4_CSR_A_INV_MASK                             4u

#define PWM_CH4_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH4_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH4_CSR_EN_OFFSET                              0u
#define PWM_CH4_CSR_EN_MASK                                1u

#define PWM_CH4_DIV_INT_OFFSET                             4u
#define PWM_CH4_DIV_INT_MASK                               0xff0u

#define PWM_CH4_DIV_FRAC_OFFSET                            0u
#define PWM_CH4_DIV_FRAC_MASK                              0xfu

#define PWM_CH4_CTR_CH4_CTR_OFFSET                         0u
#define PWM_CH4_CTR_CH4_CTR_MASK                           0xffffu

#define PWM_CH4_CC_B_OFFSET                                16u
#define PWM_CH4_CC_B_MASK                                  0xffff0000u

#define PWM_CH4_CC_A_OFFSET                                0u
#define PWM_CH4_CC_A_MASK                                  0xffffu

#define PWM_CH4_TOP_CH4_TOP_OFFSET                         0u
#define PWM_CH4_TOP_CH4_TOP_MASK                           0xffffu

#define PWM_CH5_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH5_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH5_CSR_PH_RET_OFFSET                          6u
#define PWM_CH5_CSR_PH_RET_MASK                            0x40u

#define PWM_CH5_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH5_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH5_CSR_DIVMODE_DIV                            0u
#define PWM_CH5_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH5_CSR_DIVMODE_RISE                           2u
#define PWM_CH5_CSR_DIVMODE_FALL                           3u

#define PWM_CH5_CSR_B_INV_OFFSET                           3u
#define PWM_CH5_CSR_B_INV_MASK                             8u

#define PWM_CH5_CSR_A_INV_OFFSET                           2u
#define PWM_CH5_CSR_A_INV_MASK                             4u

#define PWM_CH5_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH5_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH5_CSR_EN_OFFSET                              0u
#define PWM_CH5_CSR_EN_MASK                                1u

#define PWM_CH5_DIV_INT_OFFSET                             4u
#define PWM_CH5_DIV_INT_MASK                               0xff0u

#define PWM_CH5_DIV_FRAC_OFFSET                            0u
#define PWM_CH5_DIV_FRAC_MASK                              0xfu

#define PWM_CH5_CTR_CH5_CTR_OFFSET                         0u
#define PWM_CH5_CTR_CH5_CTR_MASK                           0xffffu

#define PWM_CH5_CC_B_OFFSET                                16u
#define PWM_CH5_CC_B_MASK                                  0xffff0000u

#define PWM_CH5_CC_A_OFFSET                                0u
#define PWM_CH5_CC_A_MASK                                  0xffffu

#define PWM_CH5_TOP_CH5_TOP_OFFSET                         0u
#define PWM_CH5_TOP_CH5_TOP_MASK                           0xffffu

#define PWM_CH6_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH6_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH6_CSR_PH_RET_OFFSET                          6u
#define PWM_CH6_CSR_PH_RET_MASK                            0x40u

#define PWM_CH6_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH6_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH6_CSR_DIVMODE_DIV                            0u
#define PWM_CH6_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH6_CSR_DIVMODE_RISE                           2u
#define PWM_CH6_CSR_DIVMODE_FALL                           3u

#define PWM_CH6_CSR_B_INV_OFFSET                           3u
#define PWM_CH6_CSR_B_INV_MASK                             8u

#define PWM_CH6_CSR_A_INV_OFFSET                           2u
#define PWM_CH6_CSR_A_INV_MASK                             4u

#define PWM_CH6_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH6_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH6_CSR_EN_OFFSET                              0u
#define PWM_CH6_CSR_EN_MASK                                1u

#define PWM_CH6_DIV_INT_OFFSET                             4u
#define PWM_CH6_DIV_INT_MASK                               0xff0u

#define PWM_CH6_DIV_FRAC_OFFSET                            0u
#define PWM_CH6_DIV_FRAC_MASK                              0xfu

#define PWM_CH6_CTR_CH6_CTR_OFFSET                         0u
#define PWM_CH6_CTR_CH6_CTR_MASK                           0xffffu

#define PWM_CH6_CC_B_OFFSET                                16u
#define PWM_CH6_CC_B_MASK                                  0xffff0000u

#define PWM_CH6_CC_A_OFFSET                                0u
#define PWM_CH6_CC_A_MASK                                  0xffffu

#define PWM_CH6_TOP_CH6_TOP_OFFSET                         0u
#define PWM_CH6_TOP_CH6_TOP_MASK                           0xffffu

#define PWM_CH7_CSR_PH_ADV_OFFSET                          7u
#define PWM_CH7_CSR_PH_ADV_MASK                            0x80u

#define PWM_CH7_CSR_PH_RET_OFFSET                          6u
#define PWM_CH7_CSR_PH_RET_MASK                            0x40u

#define PWM_CH7_CSR_DIVMODE_OFFSET                         4u
#define PWM_CH7_CSR_DIVMODE_MASK                           0x30u
#define PWM_CH7_CSR_DIVMODE_DIV                            0u
#define PWM_CH7_CSR_DIVMODE_LEVEL                          1u
#define PWM_CH7_CSR_DIVMODE_RISE                           2u
#define PWM_CH7_CSR_DIVMODE_FALL                           3u

#define PWM_CH7_CSR_B_INV_OFFSET                           3u
#define PWM_CH7_CSR_B_INV_MASK                             8u

#define PWM_CH7_CSR_A_INV_OFFSET                           2u
#define PWM_CH7_CSR_A_INV_MASK                             4u

#define PWM_CH7_CSR_PH_CORRECT_OFFSET                      1u
#define PWM_CH7_CSR_PH_CORRECT_MASK                        2u

#define PWM_CH7_CSR_EN_OFFSET                              0u
#define PWM_CH7_CSR_EN_MASK                                1u

#define PWM_CH7_DIV_INT_OFFSET                             4u
#define PWM_CH7_DIV_INT_MASK                               0xff0u

#define PWM_CH7_DIV_FRAC_OFFSET                            0u
#define PWM_CH7_DIV_FRAC_MASK                              0xfu

#define PWM_CH7_CTR_CH7_CTR_OFFSET                         0u
#define PWM_CH7_CTR_CH7_CTR_MASK                           0xffffu

#define PWM_CH7_CC_B_OFFSET                                16u
#define PWM_CH7_CC_B_MASK                                  0xffff0000u

#define PWM_CH7_CC_A_OFFSET                                0u
#define PWM_CH7_CC_A_MASK                                  0xffffu

#define PWM_CH7_TOP_CH7_TOP_OFFSET                         0u
#define PWM_CH7_TOP_CH7_TOP_MASK                           0xffffu

#define PWM_EN_CH7_OFFSET                                  7u
#define PWM_EN_CH7_MASK                                    0x80u

#define PWM_EN_CH6_OFFSET                                  6u
#define PWM_EN_CH6_MASK                                    0x40u

#define PWM_EN_CH5_OFFSET                                  5u
#define PWM_EN_CH5_MASK                                    0x20u

#define PWM_EN_CH4_OFFSET                                  4u
#define PWM_EN_CH4_MASK                                    0x10u

#define PWM_EN_CH3_OFFSET                                  3u
#define PWM_EN_CH3_MASK                                    8u

#define PWM_EN_CH2_OFFSET                                  2u
#define PWM_EN_CH2_MASK                                    4u

#define PWM_EN_CH1_OFFSET                                  1u
#define PWM_EN_CH1_MASK                                    2u

#define PWM_EN_CH0_OFFSET                                  0u
#define PWM_EN_CH0_MASK                                    1u

#define PWM_INTR_CH7_OFFSET                                7u
#define PWM_INTR_CH7_MASK                                  0x80u

#define PWM_INTR_CH6_OFFSET                                6u
#define PWM_INTR_CH6_MASK                                  0x40u

#define PWM_INTR_CH5_OFFSET                                5u
#define PWM_INTR_CH5_MASK                                  0x20u

#define PWM_INTR_CH4_OFFSET                                4u
#define PWM_INTR_CH4_MASK                                  0x10u

#define PWM_INTR_CH3_OFFSET                                3u
#define PWM_INTR_CH3_MASK                                  8u

#define PWM_INTR_CH2_OFFSET                                2u
#define PWM_INTR_CH2_MASK                                  4u

#define PWM_INTR_CH1_OFFSET                                1u
#define PWM_INTR_CH1_MASK                                  2u

#define PWM_INTR_CH0_OFFSET                                0u
#define PWM_INTR_CH0_MASK                                  1u

#define PWM_INTE_CH7_OFFSET                                7u
#define PWM_INTE_CH7_MASK                                  0x80u

#define PWM_INTE_CH6_OFFSET                                6u
#define PWM_INTE_CH6_MASK                                  0x40u

#define PWM_INTE_CH5_OFFSET                                5u
#define PWM_INTE_CH5_MASK                                  0x20u

#define PWM_INTE_CH4_OFFSET                                4u
#define PWM_INTE_CH4_MASK                                  0x10u

#define PWM_INTE_CH3_OFFSET                                3u
#define PWM_INTE_CH3_MASK                                  8u

#define PWM_INTE_CH2_OFFSET                                2u
#define PWM_INTE_CH2_MASK                                  4u

#define PWM_INTE_CH1_OFFSET                                1u
#define PWM_INTE_CH1_MASK                                  2u

#define PWM_INTE_CH0_OFFSET                                0u
#define PWM_INTE_CH0_MASK                                  1u

#define PWM_INTF_CH7_OFFSET                                7u
#define PWM_INTF_CH7_MASK                                  0x80u

#define PWM_INTF_CH6_OFFSET                                6u
#define PWM_INTF_CH6_MASK                                  0x40u

#define PWM_INTF_CH5_OFFSET                                5u
#define PWM_INTF_CH5_MASK                                  0x20u

#define PWM_INTF_CH4_OFFSET                                4u
#define PWM_INTF_CH4_MASK                                  0x10u

#define PWM_INTF_CH3_OFFSET                                3u
#define PWM_INTF_CH3_MASK                                  8u

#define PWM_INTF_CH2_OFFSET                                2u
#define PWM_INTF_CH2_MASK                                  4u

#define PWM_INTF_CH1_OFFSET                                1u
#define PWM_INTF_CH1_MASK                                  2u

#define PWM_INTF_CH0_OFFSET                                0u
#define PWM_INTF_CH0_MASK                                  1u

#define PWM_INTS_CH7_OFFSET                                7u
#define PWM_INTS_CH7_MASK                                  0x80u

#define PWM_INTS_CH6_OFFSET                                6u
#define PWM_INTS_CH6_MASK                                  0x40u

#define PWM_INTS_CH5_OFFSET                                5u
#define PWM_INTS_CH5_MASK                                  0x20u

#define PWM_INTS_CH4_OFFSET                                4u
#define PWM_INTS_CH4_MASK                                  0x10u

#define PWM_INTS_CH3_OFFSET                                3u
#define PWM_INTS_CH3_MASK                                  8u

#define PWM_INTS_CH2_OFFSET                                2u
#define PWM_INTS_CH2_MASK                                  4u

#define PWM_INTS_CH1_OFFSET                                1u
#define PWM_INTS_CH1_MASK                                  2u

#define PWM_INTS_CH0_OFFSET                                0u
#define PWM_INTS_CH0_MASK                                  1u


typedef struct
{

/** CH0_CSR (offset: 0x0)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH0_CSR;

/** CH0_DIV (offset: 0x4)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH0_DIV;

/** CH0_CTR (offset: 0x8)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH0_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH0_CTR;

/** CH0_CC (offset: 0xc)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH0_CC;

/** CH0_TOP (offset: 0x10)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH0_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH0_TOP;

/** CH1_CSR (offset: 0x14)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH1_CSR;

/** CH1_DIV (offset: 0x18)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH1_DIV;

/** CH1_CTR (offset: 0x1c)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH1_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH1_CTR;

/** CH1_CC (offset: 0x20)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH1_CC;

/** CH1_TOP (offset: 0x24)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH1_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH1_TOP;

/** CH2_CSR (offset: 0x28)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH2_CSR;

/** CH2_DIV (offset: 0x2c)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH2_DIV;

/** CH2_CTR (offset: 0x30)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH2_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH2_CTR;

/** CH2_CC (offset: 0x34)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH2_CC;

/** CH2_TOP (offset: 0x38)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH2_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH2_TOP;

/** CH3_CSR (offset: 0x3c)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH3_CSR;

/** CH3_DIV (offset: 0x40)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH3_DIV;

/** CH3_CTR (offset: 0x44)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH3_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH3_CTR;

/** CH3_CC (offset: 0x48)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH3_CC;

/** CH3_TOP (offset: 0x4c)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH3_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH3_TOP;

/** CH4_CSR (offset: 0x50)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH4_CSR;

/** CH4_DIV (offset: 0x54)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH4_DIV;

/** CH4_CTR (offset: 0x58)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH4_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH4_CTR;

/** CH4_CC (offset: 0x5c)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH4_CC;

/** CH4_TOP (offset: 0x60)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH4_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH4_TOP;

/** CH5_CSR (offset: 0x64)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH5_CSR;

/** CH5_DIV (offset: 0x68)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH5_DIV;

/** CH5_CTR (offset: 0x6c)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH5_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH5_CTR;

/** CH5_CC (offset: 0x70)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH5_CC;

/** CH5_TOP (offset: 0x74)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH5_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH5_TOP;

/** CH6_CSR (offset: 0x78)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH6_CSR;

/** CH6_DIV (offset: 0x7c)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH6_DIV;

/** CH6_CTR (offset: 0x80)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH6_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH6_CTR;

/** CH6_CC (offset: 0x84)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH6_CC;

/** CH6_TOP (offset: 0x88)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH6_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH6_TOP;

/** CH7_CSR (offset: 0x8c)
  Control and status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PH_ADV
  offset: 7, size: 1, access: read-write
  Advance the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running

 at less than full speed (div_int + div_frac / 16 &gt; 1)
  Field: PH_RET
  offset: 6, size: 1, access: read-write
  Retard the phase of the counter by 1 count, while it is running.

 Self-clearing. Write a 1, and poll until low. Counter must be running.
  Field: DIVMODE
  offset: 4, size: 2, access: read-write
  Enum:
  Value: 0 - div : Free-running counting at rate dictated by fractional divider
  Value: 1 - level : Fractional divider operation is gated by the PWM B pin.
  Value: 2 - rise : Counter advances with each rising edge of the PWM B pin.
  Value: 3 - fall : Counter advances with each falling edge of the PWM B pin.
  Field: B_INV
  offset: 3, size: 1, access: read-write
  Invert output B
  Field: A_INV
  offset: 2, size: 1, access: read-write
  Invert output A
  Field: PH_CORRECT
  offset: 1, size: 1, access: read-write
  1: Enable phase-correct modulation. 0: Trailing-edge
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable the PWM channel.
*/
volatile uint32_t CH7_CSR;

/** CH7_DIV (offset: 0x90)
  INT and FRAC form a fixed-point fractional number.

 Counting rate is system clock frequency divided by this number.

 Fractional division uses simple 1st-order sigma-delta.
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: INT
  offset: 4, size: 8, access: read-write
  Field: FRAC
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t CH7_DIV;

/** CH7_CTR (offset: 0x94)
  Direct access to the PWM counter
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7_CTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH7_CTR;

/** CH7_CC (offset: 0x98)
  Counter compare values
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: B
  offset: 16, size: 16, access: read-write
  Field: A
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH7_CC;

/** CH7_TOP (offset: 0x9c)
  Counter wrap value
  access : read-write
  reset value : 0xFFFF
  reset mask : 0x0
  Field: CH7_TOP
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CH7_TOP;

/** EN (offset: 0xa0)
  This register aliases the CSR_EN bits for all channels.

 Writing to this register allows multiple channels to be enabled

 or disabled simultaneously, so they can run in perfect sync.

 For each channel, there is only one physical EN register bit,

 which can be accessed through here or CHx_CSR.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7
  offset: 7, size: 1, access: read-write
  Field: CH6
  offset: 6, size: 1, access: read-write
  Field: CH5
  offset: 5, size: 1, access: read-write
  Field: CH4
  offset: 4, size: 1, access: read-write
  Field: CH3
  offset: 3, size: 1, access: read-write
  Field: CH2
  offset: 2, size: 1, access: read-write
  Field: CH1
  offset: 1, size: 1, access: read-write
  Field: CH0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t EN;

/** INTR (offset: 0xa4)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7
  offset: 7, size: 1, access: read-write
  Field: CH6
  offset: 6, size: 1, access: read-write
  Field: CH5
  offset: 5, size: 1, access: read-write
  Field: CH4
  offset: 4, size: 1, access: read-write
  Field: CH3
  offset: 3, size: 1, access: read-write
  Field: CH2
  offset: 2, size: 1, access: read-write
  Field: CH1
  offset: 1, size: 1, access: read-write
  Field: CH0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTR;

/** INTE (offset: 0xa8)
  Interrupt Enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7
  offset: 7, size: 1, access: read-write
  Field: CH6
  offset: 6, size: 1, access: read-write
  Field: CH5
  offset: 5, size: 1, access: read-write
  Field: CH4
  offset: 4, size: 1, access: read-write
  Field: CH3
  offset: 3, size: 1, access: read-write
  Field: CH2
  offset: 2, size: 1, access: read-write
  Field: CH1
  offset: 1, size: 1, access: read-write
  Field: CH0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTE;

/** INTF (offset: 0xac)
  Interrupt Force
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7
  offset: 7, size: 1, access: read-write
  Field: CH6
  offset: 6, size: 1, access: read-write
  Field: CH5
  offset: 5, size: 1, access: read-write
  Field: CH4
  offset: 4, size: 1, access: read-write
  Field: CH3
  offset: 3, size: 1, access: read-write
  Field: CH2
  offset: 2, size: 1, access: read-write
  Field: CH1
  offset: 1, size: 1, access: read-write
  Field: CH0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTF;

/** INTS (offset: 0xb0)
  Interrupt status after masking &amp; forcing
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7
  offset: 7, size: 1, access: read-only
  Field: CH6
  offset: 6, size: 1, access: read-only
  Field: CH5
  offset: 5, size: 1, access: read-only
  Field: CH4
  offset: 4, size: 1, access: read-only
  Field: CH3
  offset: 3, size: 1, access: read-only
  Field: CH2
  offset: 2, size: 1, access: read-only
  Field: CH1
  offset: 1, size: 1, access: read-only
  Field: CH0
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTS;
} PWM_type;

#define PWM ((PWM_type *) 0x40050000)

#endif // HW_PWM_H
