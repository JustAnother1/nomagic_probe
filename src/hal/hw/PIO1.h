/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_PIO1_H
#define HW_PIO1_H
/** Programmable IO block */
/** Interrupt : PIO1_IRQ_0 (Vector: 9)  */
/** Interrupt : PIO1_IRQ_1 (Vector: 10)  */
/** Memory Block starting at 0x50300000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PIO1_CTRL_CLKDIV_RESTART_OFFSET                    8u
#define PIO1_CTRL_CLKDIV_RESTART_MASK                      0xf00u

#define PIO1_CTRL_SM_RESTART_OFFSET                        4u
#define PIO1_CTRL_SM_RESTART_MASK                          0xf0u

#define PIO1_CTRL_SM_ENABLE_OFFSET                         0u
#define PIO1_CTRL_SM_ENABLE_MASK                           0xfu

#define PIO1_FSTAT_TXEMPTY_OFFSET                          24u
#define PIO1_FSTAT_TXEMPTY_MASK                            0xf000000u

#define PIO1_FSTAT_TXFULL_OFFSET                           16u
#define PIO1_FSTAT_TXFULL_MASK                             0xf0000u

#define PIO1_FSTAT_RXEMPTY_OFFSET                          8u
#define PIO1_FSTAT_RXEMPTY_MASK                            0xf00u

#define PIO1_FSTAT_RXFULL_OFFSET                           0u
#define PIO1_FSTAT_RXFULL_MASK                             0xfu

#define PIO1_FDEBUG_TXSTALL_OFFSET                         24u
#define PIO1_FDEBUG_TXSTALL_MASK                           0xf000000u

#define PIO1_FDEBUG_TXOVER_OFFSET                          16u
#define PIO1_FDEBUG_TXOVER_MASK                            0xf0000u

#define PIO1_FDEBUG_RXUNDER_OFFSET                         8u
#define PIO1_FDEBUG_RXUNDER_MASK                           0xf00u

#define PIO1_FDEBUG_RXSTALL_OFFSET                         0u
#define PIO1_FDEBUG_RXSTALL_MASK                           0xfu

#define PIO1_FLEVEL_RX3_OFFSET                             28u
#define PIO1_FLEVEL_RX3_MASK                               0xf0000000u

#define PIO1_FLEVEL_TX3_OFFSET                             24u
#define PIO1_FLEVEL_TX3_MASK                               0xf000000u

#define PIO1_FLEVEL_RX2_OFFSET                             20u
#define PIO1_FLEVEL_RX2_MASK                               0xf00000u

#define PIO1_FLEVEL_TX2_OFFSET                             16u
#define PIO1_FLEVEL_TX2_MASK                               0xf0000u

#define PIO1_FLEVEL_RX1_OFFSET                             12u
#define PIO1_FLEVEL_RX1_MASK                               0xf000u

#define PIO1_FLEVEL_TX1_OFFSET                             8u
#define PIO1_FLEVEL_TX1_MASK                               0xf00u

#define PIO1_FLEVEL_RX0_OFFSET                             4u
#define PIO1_FLEVEL_RX0_MASK                               0xf0u

#define PIO1_FLEVEL_TX0_OFFSET                             0u
#define PIO1_FLEVEL_TX0_MASK                               0xfu

#define PIO1_IRQ_IRQ_OFFSET                                0u
#define PIO1_IRQ_IRQ_MASK                                  0xffu

#define PIO1_IRQ_FORCE_IRQ_FORCE_OFFSET                    0u
#define PIO1_IRQ_FORCE_IRQ_FORCE_MASK                      0xffu

#define PIO1_DBG_CFGINFO_IMEM_SIZE_OFFSET                  16u
#define PIO1_DBG_CFGINFO_IMEM_SIZE_MASK                    0x3f0000u

#define PIO1_DBG_CFGINFO_SM_COUNT_OFFSET                   8u
#define PIO1_DBG_CFGINFO_SM_COUNT_MASK                     0xf00u

#define PIO1_DBG_CFGINFO_FIFO_DEPTH_OFFSET                 0u
#define PIO1_DBG_CFGINFO_FIFO_DEPTH_MASK                   0x3fu

#define PIO1_INSTR_MEM0_INSTR_MEM0_OFFSET                  0u
#define PIO1_INSTR_MEM0_INSTR_MEM0_MASK                    0xffffu

#define PIO1_INSTR_MEM1_INSTR_MEM1_OFFSET                  0u
#define PIO1_INSTR_MEM1_INSTR_MEM1_MASK                    0xffffu

#define PIO1_INSTR_MEM2_INSTR_MEM2_OFFSET                  0u
#define PIO1_INSTR_MEM2_INSTR_MEM2_MASK                    0xffffu

#define PIO1_INSTR_MEM3_INSTR_MEM3_OFFSET                  0u
#define PIO1_INSTR_MEM3_INSTR_MEM3_MASK                    0xffffu

#define PIO1_INSTR_MEM4_INSTR_MEM4_OFFSET                  0u
#define PIO1_INSTR_MEM4_INSTR_MEM4_MASK                    0xffffu

#define PIO1_INSTR_MEM5_INSTR_MEM5_OFFSET                  0u
#define PIO1_INSTR_MEM5_INSTR_MEM5_MASK                    0xffffu

#define PIO1_INSTR_MEM6_INSTR_MEM6_OFFSET                  0u
#define PIO1_INSTR_MEM6_INSTR_MEM6_MASK                    0xffffu

#define PIO1_INSTR_MEM7_INSTR_MEM7_OFFSET                  0u
#define PIO1_INSTR_MEM7_INSTR_MEM7_MASK                    0xffffu

#define PIO1_INSTR_MEM8_INSTR_MEM8_OFFSET                  0u
#define PIO1_INSTR_MEM8_INSTR_MEM8_MASK                    0xffffu

#define PIO1_INSTR_MEM9_INSTR_MEM9_OFFSET                  0u
#define PIO1_INSTR_MEM9_INSTR_MEM9_MASK                    0xffffu

#define PIO1_INSTR_MEM10_INSTR_MEM10_OFFSET                0u
#define PIO1_INSTR_MEM10_INSTR_MEM10_MASK                  0xffffu

#define PIO1_INSTR_MEM11_INSTR_MEM11_OFFSET                0u
#define PIO1_INSTR_MEM11_INSTR_MEM11_MASK                  0xffffu

#define PIO1_INSTR_MEM12_INSTR_MEM12_OFFSET                0u
#define PIO1_INSTR_MEM12_INSTR_MEM12_MASK                  0xffffu

#define PIO1_INSTR_MEM13_INSTR_MEM13_OFFSET                0u
#define PIO1_INSTR_MEM13_INSTR_MEM13_MASK                  0xffffu

#define PIO1_INSTR_MEM14_INSTR_MEM14_OFFSET                0u
#define PIO1_INSTR_MEM14_INSTR_MEM14_MASK                  0xffffu

#define PIO1_INSTR_MEM15_INSTR_MEM15_OFFSET                0u
#define PIO1_INSTR_MEM15_INSTR_MEM15_MASK                  0xffffu

#define PIO1_INSTR_MEM16_INSTR_MEM16_OFFSET                0u
#define PIO1_INSTR_MEM16_INSTR_MEM16_MASK                  0xffffu

#define PIO1_INSTR_MEM17_INSTR_MEM17_OFFSET                0u
#define PIO1_INSTR_MEM17_INSTR_MEM17_MASK                  0xffffu

#define PIO1_INSTR_MEM18_INSTR_MEM18_OFFSET                0u
#define PIO1_INSTR_MEM18_INSTR_MEM18_MASK                  0xffffu

#define PIO1_INSTR_MEM19_INSTR_MEM19_OFFSET                0u
#define PIO1_INSTR_MEM19_INSTR_MEM19_MASK                  0xffffu

#define PIO1_INSTR_MEM20_INSTR_MEM20_OFFSET                0u
#define PIO1_INSTR_MEM20_INSTR_MEM20_MASK                  0xffffu

#define PIO1_INSTR_MEM21_INSTR_MEM21_OFFSET                0u
#define PIO1_INSTR_MEM21_INSTR_MEM21_MASK                  0xffffu

#define PIO1_INSTR_MEM22_INSTR_MEM22_OFFSET                0u
#define PIO1_INSTR_MEM22_INSTR_MEM22_MASK                  0xffffu

#define PIO1_INSTR_MEM23_INSTR_MEM23_OFFSET                0u
#define PIO1_INSTR_MEM23_INSTR_MEM23_MASK                  0xffffu

#define PIO1_INSTR_MEM24_INSTR_MEM24_OFFSET                0u
#define PIO1_INSTR_MEM24_INSTR_MEM24_MASK                  0xffffu

#define PIO1_INSTR_MEM25_INSTR_MEM25_OFFSET                0u
#define PIO1_INSTR_MEM25_INSTR_MEM25_MASK                  0xffffu

#define PIO1_INSTR_MEM26_INSTR_MEM26_OFFSET                0u
#define PIO1_INSTR_MEM26_INSTR_MEM26_MASK                  0xffffu

#define PIO1_INSTR_MEM27_INSTR_MEM27_OFFSET                0u
#define PIO1_INSTR_MEM27_INSTR_MEM27_MASK                  0xffffu

#define PIO1_INSTR_MEM28_INSTR_MEM28_OFFSET                0u
#define PIO1_INSTR_MEM28_INSTR_MEM28_MASK                  0xffffu

#define PIO1_INSTR_MEM29_INSTR_MEM29_OFFSET                0u
#define PIO1_INSTR_MEM29_INSTR_MEM29_MASK                  0xffffu

#define PIO1_INSTR_MEM30_INSTR_MEM30_OFFSET                0u
#define PIO1_INSTR_MEM30_INSTR_MEM30_MASK                  0xffffu

#define PIO1_INSTR_MEM31_INSTR_MEM31_OFFSET                0u
#define PIO1_INSTR_MEM31_INSTR_MEM31_MASK                  0xffffu

#define PIO1_SM0_CLKDIV_INT_OFFSET                         16u
#define PIO1_SM0_CLKDIV_INT_MASK                           0xffff0000u

#define PIO1_SM0_CLKDIV_FRAC_OFFSET                        8u
#define PIO1_SM0_CLKDIV_FRAC_MASK                          0xff00u

#define PIO1_SM0_EXECCTRL_EXEC_STALLED_OFFSET              31u
#define PIO1_SM0_EXECCTRL_EXEC_STALLED_MASK                0x80000000u

#define PIO1_SM0_EXECCTRL_SIDE_EN_OFFSET                   30u
#define PIO1_SM0_EXECCTRL_SIDE_EN_MASK                     0x40000000u

#define PIO1_SM0_EXECCTRL_SIDE_PINDIR_OFFSET               29u
#define PIO1_SM0_EXECCTRL_SIDE_PINDIR_MASK                 0x20000000u

#define PIO1_SM0_EXECCTRL_JMP_PIN_OFFSET                   24u
#define PIO1_SM0_EXECCTRL_JMP_PIN_MASK                     0x1f000000u

#define PIO1_SM0_EXECCTRL_OUT_EN_SEL_OFFSET                19u
#define PIO1_SM0_EXECCTRL_OUT_EN_SEL_MASK                  0xf80000u

#define PIO1_SM0_EXECCTRL_INLINE_OUT_EN_OFFSET             18u
#define PIO1_SM0_EXECCTRL_INLINE_OUT_EN_MASK               0x40000u

#define PIO1_SM0_EXECCTRL_OUT_STICKY_OFFSET                17u
#define PIO1_SM0_EXECCTRL_OUT_STICKY_MASK                  0x20000u

#define PIO1_SM0_EXECCTRL_WRAP_TOP_OFFSET                  12u
#define PIO1_SM0_EXECCTRL_WRAP_TOP_MASK                    0x1f000u

#define PIO1_SM0_EXECCTRL_WRAP_BOTTOM_OFFSET               7u
#define PIO1_SM0_EXECCTRL_WRAP_BOTTOM_MASK                 0xf80u

#define PIO1_SM0_EXECCTRL_STATUS_SEL_OFFSET                4u
#define PIO1_SM0_EXECCTRL_STATUS_SEL_MASK                  0x10u
#define PIO1_SM0_EXECCTRL_STATUS_SEL_TXLEVEL               0u
#define PIO1_SM0_EXECCTRL_STATUS_SEL_RXLEVEL               1u

#define PIO1_SM0_EXECCTRL_STATUS_N_OFFSET                  0u
#define PIO1_SM0_EXECCTRL_STATUS_N_MASK                    0xfu

#define PIO1_SM0_SHIFTCTRL_FJOIN_RX_OFFSET                 31u
#define PIO1_SM0_SHIFTCTRL_FJOIN_RX_MASK                   0x80000000u

#define PIO1_SM0_SHIFTCTRL_FJOIN_TX_OFFSET                 30u
#define PIO1_SM0_SHIFTCTRL_FJOIN_TX_MASK                   0x40000000u

#define PIO1_SM0_SHIFTCTRL_PULL_THRESH_OFFSET              25u
#define PIO1_SM0_SHIFTCTRL_PULL_THRESH_MASK                0x3e000000u

#define PIO1_SM0_SHIFTCTRL_PUSH_THRESH_OFFSET              20u
#define PIO1_SM0_SHIFTCTRL_PUSH_THRESH_MASK                0x1f00000u

#define PIO1_SM0_SHIFTCTRL_OUT_SHIFTDIR_OFFSET             19u
#define PIO1_SM0_SHIFTCTRL_OUT_SHIFTDIR_MASK               0x80000u

#define PIO1_SM0_SHIFTCTRL_IN_SHIFTDIR_OFFSET              18u
#define PIO1_SM0_SHIFTCTRL_IN_SHIFTDIR_MASK                0x40000u

#define PIO1_SM0_SHIFTCTRL_AUTOPULL_OFFSET                 17u
#define PIO1_SM0_SHIFTCTRL_AUTOPULL_MASK                   0x20000u

#define PIO1_SM0_SHIFTCTRL_AUTOPUSH_OFFSET                 16u
#define PIO1_SM0_SHIFTCTRL_AUTOPUSH_MASK                   0x10000u

#define PIO1_SM0_ADDR_SM0_ADDR_OFFSET                      0u
#define PIO1_SM0_ADDR_SM0_ADDR_MASK                        0x1fu

#define PIO1_SM0_INSTR_SM0_INSTR_OFFSET                    0u
#define PIO1_SM0_INSTR_SM0_INSTR_MASK                      0xffffu

#define PIO1_SM0_PINCTRL_SIDESET_COUNT_OFFSET              29u
#define PIO1_SM0_PINCTRL_SIDESET_COUNT_MASK                0xe0000000u

#define PIO1_SM0_PINCTRL_SET_COUNT_OFFSET                  26u
#define PIO1_SM0_PINCTRL_SET_COUNT_MASK                    0x1c000000u

#define PIO1_SM0_PINCTRL_OUT_COUNT_OFFSET                  20u
#define PIO1_SM0_PINCTRL_OUT_COUNT_MASK                    0x3f00000u

#define PIO1_SM0_PINCTRL_IN_BASE_OFFSET                    15u
#define PIO1_SM0_PINCTRL_IN_BASE_MASK                      0xf8000u

#define PIO1_SM0_PINCTRL_SIDESET_BASE_OFFSET               10u
#define PIO1_SM0_PINCTRL_SIDESET_BASE_MASK                 0x7c00u

#define PIO1_SM0_PINCTRL_SET_BASE_OFFSET                   5u
#define PIO1_SM0_PINCTRL_SET_BASE_MASK                     0x3e0u

#define PIO1_SM0_PINCTRL_OUT_BASE_OFFSET                   0u
#define PIO1_SM0_PINCTRL_OUT_BASE_MASK                     0x1fu

#define PIO1_SM1_CLKDIV_INT_OFFSET                         16u
#define PIO1_SM1_CLKDIV_INT_MASK                           0xffff0000u

#define PIO1_SM1_CLKDIV_FRAC_OFFSET                        8u
#define PIO1_SM1_CLKDIV_FRAC_MASK                          0xff00u

#define PIO1_SM1_EXECCTRL_EXEC_STALLED_OFFSET              31u
#define PIO1_SM1_EXECCTRL_EXEC_STALLED_MASK                0x80000000u

#define PIO1_SM1_EXECCTRL_SIDE_EN_OFFSET                   30u
#define PIO1_SM1_EXECCTRL_SIDE_EN_MASK                     0x40000000u

#define PIO1_SM1_EXECCTRL_SIDE_PINDIR_OFFSET               29u
#define PIO1_SM1_EXECCTRL_SIDE_PINDIR_MASK                 0x20000000u

#define PIO1_SM1_EXECCTRL_JMP_PIN_OFFSET                   24u
#define PIO1_SM1_EXECCTRL_JMP_PIN_MASK                     0x1f000000u

#define PIO1_SM1_EXECCTRL_OUT_EN_SEL_OFFSET                19u
#define PIO1_SM1_EXECCTRL_OUT_EN_SEL_MASK                  0xf80000u

#define PIO1_SM1_EXECCTRL_INLINE_OUT_EN_OFFSET             18u
#define PIO1_SM1_EXECCTRL_INLINE_OUT_EN_MASK               0x40000u

#define PIO1_SM1_EXECCTRL_OUT_STICKY_OFFSET                17u
#define PIO1_SM1_EXECCTRL_OUT_STICKY_MASK                  0x20000u

#define PIO1_SM1_EXECCTRL_WRAP_TOP_OFFSET                  12u
#define PIO1_SM1_EXECCTRL_WRAP_TOP_MASK                    0x1f000u

#define PIO1_SM1_EXECCTRL_WRAP_BOTTOM_OFFSET               7u
#define PIO1_SM1_EXECCTRL_WRAP_BOTTOM_MASK                 0xf80u

#define PIO1_SM1_EXECCTRL_STATUS_SEL_OFFSET                4u
#define PIO1_SM1_EXECCTRL_STATUS_SEL_MASK                  0x10u
#define PIO1_SM1_EXECCTRL_STATUS_SEL_TXLEVEL               0u
#define PIO1_SM1_EXECCTRL_STATUS_SEL_RXLEVEL               1u

#define PIO1_SM1_EXECCTRL_STATUS_N_OFFSET                  0u
#define PIO1_SM1_EXECCTRL_STATUS_N_MASK                    0xfu

#define PIO1_SM1_SHIFTCTRL_FJOIN_RX_OFFSET                 31u
#define PIO1_SM1_SHIFTCTRL_FJOIN_RX_MASK                   0x80000000u

#define PIO1_SM1_SHIFTCTRL_FJOIN_TX_OFFSET                 30u
#define PIO1_SM1_SHIFTCTRL_FJOIN_TX_MASK                   0x40000000u

#define PIO1_SM1_SHIFTCTRL_PULL_THRESH_OFFSET              25u
#define PIO1_SM1_SHIFTCTRL_PULL_THRESH_MASK                0x3e000000u

#define PIO1_SM1_SHIFTCTRL_PUSH_THRESH_OFFSET              20u
#define PIO1_SM1_SHIFTCTRL_PUSH_THRESH_MASK                0x1f00000u

#define PIO1_SM1_SHIFTCTRL_OUT_SHIFTDIR_OFFSET             19u
#define PIO1_SM1_SHIFTCTRL_OUT_SHIFTDIR_MASK               0x80000u

#define PIO1_SM1_SHIFTCTRL_IN_SHIFTDIR_OFFSET              18u
#define PIO1_SM1_SHIFTCTRL_IN_SHIFTDIR_MASK                0x40000u

#define PIO1_SM1_SHIFTCTRL_AUTOPULL_OFFSET                 17u
#define PIO1_SM1_SHIFTCTRL_AUTOPULL_MASK                   0x20000u

#define PIO1_SM1_SHIFTCTRL_AUTOPUSH_OFFSET                 16u
#define PIO1_SM1_SHIFTCTRL_AUTOPUSH_MASK                   0x10000u

#define PIO1_SM1_ADDR_SM1_ADDR_OFFSET                      0u
#define PIO1_SM1_ADDR_SM1_ADDR_MASK                        0x1fu

#define PIO1_SM1_INSTR_SM1_INSTR_OFFSET                    0u
#define PIO1_SM1_INSTR_SM1_INSTR_MASK                      0xffffu

#define PIO1_SM1_PINCTRL_SIDESET_COUNT_OFFSET              29u
#define PIO1_SM1_PINCTRL_SIDESET_COUNT_MASK                0xe0000000u

#define PIO1_SM1_PINCTRL_SET_COUNT_OFFSET                  26u
#define PIO1_SM1_PINCTRL_SET_COUNT_MASK                    0x1c000000u

#define PIO1_SM1_PINCTRL_OUT_COUNT_OFFSET                  20u
#define PIO1_SM1_PINCTRL_OUT_COUNT_MASK                    0x3f00000u

#define PIO1_SM1_PINCTRL_IN_BASE_OFFSET                    15u
#define PIO1_SM1_PINCTRL_IN_BASE_MASK                      0xf8000u

#define PIO1_SM1_PINCTRL_SIDESET_BASE_OFFSET               10u
#define PIO1_SM1_PINCTRL_SIDESET_BASE_MASK                 0x7c00u

#define PIO1_SM1_PINCTRL_SET_BASE_OFFSET                   5u
#define PIO1_SM1_PINCTRL_SET_BASE_MASK                     0x3e0u

#define PIO1_SM1_PINCTRL_OUT_BASE_OFFSET                   0u
#define PIO1_SM1_PINCTRL_OUT_BASE_MASK                     0x1fu

#define PIO1_SM2_CLKDIV_INT_OFFSET                         16u
#define PIO1_SM2_CLKDIV_INT_MASK                           0xffff0000u

#define PIO1_SM2_CLKDIV_FRAC_OFFSET                        8u
#define PIO1_SM2_CLKDIV_FRAC_MASK                          0xff00u

#define PIO1_SM2_EXECCTRL_EXEC_STALLED_OFFSET              31u
#define PIO1_SM2_EXECCTRL_EXEC_STALLED_MASK                0x80000000u

#define PIO1_SM2_EXECCTRL_SIDE_EN_OFFSET                   30u
#define PIO1_SM2_EXECCTRL_SIDE_EN_MASK                     0x40000000u

#define PIO1_SM2_EXECCTRL_SIDE_PINDIR_OFFSET               29u
#define PIO1_SM2_EXECCTRL_SIDE_PINDIR_MASK                 0x20000000u

#define PIO1_SM2_EXECCTRL_JMP_PIN_OFFSET                   24u
#define PIO1_SM2_EXECCTRL_JMP_PIN_MASK                     0x1f000000u

#define PIO1_SM2_EXECCTRL_OUT_EN_SEL_OFFSET                19u
#define PIO1_SM2_EXECCTRL_OUT_EN_SEL_MASK                  0xf80000u

#define PIO1_SM2_EXECCTRL_INLINE_OUT_EN_OFFSET             18u
#define PIO1_SM2_EXECCTRL_INLINE_OUT_EN_MASK               0x40000u

#define PIO1_SM2_EXECCTRL_OUT_STICKY_OFFSET                17u
#define PIO1_SM2_EXECCTRL_OUT_STICKY_MASK                  0x20000u

#define PIO1_SM2_EXECCTRL_WRAP_TOP_OFFSET                  12u
#define PIO1_SM2_EXECCTRL_WRAP_TOP_MASK                    0x1f000u

#define PIO1_SM2_EXECCTRL_WRAP_BOTTOM_OFFSET               7u
#define PIO1_SM2_EXECCTRL_WRAP_BOTTOM_MASK                 0xf80u

#define PIO1_SM2_EXECCTRL_STATUS_SEL_OFFSET                4u
#define PIO1_SM2_EXECCTRL_STATUS_SEL_MASK                  0x10u
#define PIO1_SM2_EXECCTRL_STATUS_SEL_TXLEVEL               0u
#define PIO1_SM2_EXECCTRL_STATUS_SEL_RXLEVEL               1u

#define PIO1_SM2_EXECCTRL_STATUS_N_OFFSET                  0u
#define PIO1_SM2_EXECCTRL_STATUS_N_MASK                    0xfu

#define PIO1_SM2_SHIFTCTRL_FJOIN_RX_OFFSET                 31u
#define PIO1_SM2_SHIFTCTRL_FJOIN_RX_MASK                   0x80000000u

#define PIO1_SM2_SHIFTCTRL_FJOIN_TX_OFFSET                 30u
#define PIO1_SM2_SHIFTCTRL_FJOIN_TX_MASK                   0x40000000u

#define PIO1_SM2_SHIFTCTRL_PULL_THRESH_OFFSET              25u
#define PIO1_SM2_SHIFTCTRL_PULL_THRESH_MASK                0x3e000000u

#define PIO1_SM2_SHIFTCTRL_PUSH_THRESH_OFFSET              20u
#define PIO1_SM2_SHIFTCTRL_PUSH_THRESH_MASK                0x1f00000u

#define PIO1_SM2_SHIFTCTRL_OUT_SHIFTDIR_OFFSET             19u
#define PIO1_SM2_SHIFTCTRL_OUT_SHIFTDIR_MASK               0x80000u

#define PIO1_SM2_SHIFTCTRL_IN_SHIFTDIR_OFFSET              18u
#define PIO1_SM2_SHIFTCTRL_IN_SHIFTDIR_MASK                0x40000u

#define PIO1_SM2_SHIFTCTRL_AUTOPULL_OFFSET                 17u
#define PIO1_SM2_SHIFTCTRL_AUTOPULL_MASK                   0x20000u

#define PIO1_SM2_SHIFTCTRL_AUTOPUSH_OFFSET                 16u
#define PIO1_SM2_SHIFTCTRL_AUTOPUSH_MASK                   0x10000u

#define PIO1_SM2_ADDR_SM2_ADDR_OFFSET                      0u
#define PIO1_SM2_ADDR_SM2_ADDR_MASK                        0x1fu

#define PIO1_SM2_INSTR_SM2_INSTR_OFFSET                    0u
#define PIO1_SM2_INSTR_SM2_INSTR_MASK                      0xffffu

#define PIO1_SM2_PINCTRL_SIDESET_COUNT_OFFSET              29u
#define PIO1_SM2_PINCTRL_SIDESET_COUNT_MASK                0xe0000000u

#define PIO1_SM2_PINCTRL_SET_COUNT_OFFSET                  26u
#define PIO1_SM2_PINCTRL_SET_COUNT_MASK                    0x1c000000u

#define PIO1_SM2_PINCTRL_OUT_COUNT_OFFSET                  20u
#define PIO1_SM2_PINCTRL_OUT_COUNT_MASK                    0x3f00000u

#define PIO1_SM2_PINCTRL_IN_BASE_OFFSET                    15u
#define PIO1_SM2_PINCTRL_IN_BASE_MASK                      0xf8000u

#define PIO1_SM2_PINCTRL_SIDESET_BASE_OFFSET               10u
#define PIO1_SM2_PINCTRL_SIDESET_BASE_MASK                 0x7c00u

#define PIO1_SM2_PINCTRL_SET_BASE_OFFSET                   5u
#define PIO1_SM2_PINCTRL_SET_BASE_MASK                     0x3e0u

#define PIO1_SM2_PINCTRL_OUT_BASE_OFFSET                   0u
#define PIO1_SM2_PINCTRL_OUT_BASE_MASK                     0x1fu

#define PIO1_SM3_CLKDIV_INT_OFFSET                         16u
#define PIO1_SM3_CLKDIV_INT_MASK                           0xffff0000u

#define PIO1_SM3_CLKDIV_FRAC_OFFSET                        8u
#define PIO1_SM3_CLKDIV_FRAC_MASK                          0xff00u

#define PIO1_SM3_EXECCTRL_EXEC_STALLED_OFFSET              31u
#define PIO1_SM3_EXECCTRL_EXEC_STALLED_MASK                0x80000000u

#define PIO1_SM3_EXECCTRL_SIDE_EN_OFFSET                   30u
#define PIO1_SM3_EXECCTRL_SIDE_EN_MASK                     0x40000000u

#define PIO1_SM3_EXECCTRL_SIDE_PINDIR_OFFSET               29u
#define PIO1_SM3_EXECCTRL_SIDE_PINDIR_MASK                 0x20000000u

#define PIO1_SM3_EXECCTRL_JMP_PIN_OFFSET                   24u
#define PIO1_SM3_EXECCTRL_JMP_PIN_MASK                     0x1f000000u

#define PIO1_SM3_EXECCTRL_OUT_EN_SEL_OFFSET                19u
#define PIO1_SM3_EXECCTRL_OUT_EN_SEL_MASK                  0xf80000u

#define PIO1_SM3_EXECCTRL_INLINE_OUT_EN_OFFSET             18u
#define PIO1_SM3_EXECCTRL_INLINE_OUT_EN_MASK               0x40000u

#define PIO1_SM3_EXECCTRL_OUT_STICKY_OFFSET                17u
#define PIO1_SM3_EXECCTRL_OUT_STICKY_MASK                  0x20000u

#define PIO1_SM3_EXECCTRL_WRAP_TOP_OFFSET                  12u
#define PIO1_SM3_EXECCTRL_WRAP_TOP_MASK                    0x1f000u

#define PIO1_SM3_EXECCTRL_WRAP_BOTTOM_OFFSET               7u
#define PIO1_SM3_EXECCTRL_WRAP_BOTTOM_MASK                 0xf80u

#define PIO1_SM3_EXECCTRL_STATUS_SEL_OFFSET                4u
#define PIO1_SM3_EXECCTRL_STATUS_SEL_MASK                  0x10u
#define PIO1_SM3_EXECCTRL_STATUS_SEL_TXLEVEL               0u
#define PIO1_SM3_EXECCTRL_STATUS_SEL_RXLEVEL               1u

#define PIO1_SM3_EXECCTRL_STATUS_N_OFFSET                  0u
#define PIO1_SM3_EXECCTRL_STATUS_N_MASK                    0xfu

#define PIO1_SM3_SHIFTCTRL_FJOIN_RX_OFFSET                 31u
#define PIO1_SM3_SHIFTCTRL_FJOIN_RX_MASK                   0x80000000u

#define PIO1_SM3_SHIFTCTRL_FJOIN_TX_OFFSET                 30u
#define PIO1_SM3_SHIFTCTRL_FJOIN_TX_MASK                   0x40000000u

#define PIO1_SM3_SHIFTCTRL_PULL_THRESH_OFFSET              25u
#define PIO1_SM3_SHIFTCTRL_PULL_THRESH_MASK                0x3e000000u

#define PIO1_SM3_SHIFTCTRL_PUSH_THRESH_OFFSET              20u
#define PIO1_SM3_SHIFTCTRL_PUSH_THRESH_MASK                0x1f00000u

#define PIO1_SM3_SHIFTCTRL_OUT_SHIFTDIR_OFFSET             19u
#define PIO1_SM3_SHIFTCTRL_OUT_SHIFTDIR_MASK               0x80000u

#define PIO1_SM3_SHIFTCTRL_IN_SHIFTDIR_OFFSET              18u
#define PIO1_SM3_SHIFTCTRL_IN_SHIFTDIR_MASK                0x40000u

#define PIO1_SM3_SHIFTCTRL_AUTOPULL_OFFSET                 17u
#define PIO1_SM3_SHIFTCTRL_AUTOPULL_MASK                   0x20000u

#define PIO1_SM3_SHIFTCTRL_AUTOPUSH_OFFSET                 16u
#define PIO1_SM3_SHIFTCTRL_AUTOPUSH_MASK                   0x10000u

#define PIO1_SM3_ADDR_SM3_ADDR_OFFSET                      0u
#define PIO1_SM3_ADDR_SM3_ADDR_MASK                        0x1fu

#define PIO1_SM3_INSTR_SM3_INSTR_OFFSET                    0u
#define PIO1_SM3_INSTR_SM3_INSTR_MASK                      0xffffu

#define PIO1_SM3_PINCTRL_SIDESET_COUNT_OFFSET              29u
#define PIO1_SM3_PINCTRL_SIDESET_COUNT_MASK                0xe0000000u

#define PIO1_SM3_PINCTRL_SET_COUNT_OFFSET                  26u
#define PIO1_SM3_PINCTRL_SET_COUNT_MASK                    0x1c000000u

#define PIO1_SM3_PINCTRL_OUT_COUNT_OFFSET                  20u
#define PIO1_SM3_PINCTRL_OUT_COUNT_MASK                    0x3f00000u

#define PIO1_SM3_PINCTRL_IN_BASE_OFFSET                    15u
#define PIO1_SM3_PINCTRL_IN_BASE_MASK                      0xf8000u

#define PIO1_SM3_PINCTRL_SIDESET_BASE_OFFSET               10u
#define PIO1_SM3_PINCTRL_SIDESET_BASE_MASK                 0x7c00u

#define PIO1_SM3_PINCTRL_SET_BASE_OFFSET                   5u
#define PIO1_SM3_PINCTRL_SET_BASE_MASK                     0x3e0u

#define PIO1_SM3_PINCTRL_OUT_BASE_OFFSET                   0u
#define PIO1_SM3_PINCTRL_OUT_BASE_MASK                     0x1fu

#define PIO1_INTR_SM3_OFFSET                               11u
#define PIO1_INTR_SM3_MASK                                 0x800u

#define PIO1_INTR_SM2_OFFSET                               10u
#define PIO1_INTR_SM2_MASK                                 0x400u

#define PIO1_INTR_SM1_OFFSET                               9u
#define PIO1_INTR_SM1_MASK                                 0x200u

#define PIO1_INTR_SM0_OFFSET                               8u
#define PIO1_INTR_SM0_MASK                                 0x100u

#define PIO1_INTR_SM3_TXNFULL_OFFSET                       7u
#define PIO1_INTR_SM3_TXNFULL_MASK                         0x80u

#define PIO1_INTR_SM2_TXNFULL_OFFSET                       6u
#define PIO1_INTR_SM2_TXNFULL_MASK                         0x40u

#define PIO1_INTR_SM1_TXNFULL_OFFSET                       5u
#define PIO1_INTR_SM1_TXNFULL_MASK                         0x20u

#define PIO1_INTR_SM0_TXNFULL_OFFSET                       4u
#define PIO1_INTR_SM0_TXNFULL_MASK                         0x10u

#define PIO1_INTR_SM3_RXNEMPTY_OFFSET                      3u
#define PIO1_INTR_SM3_RXNEMPTY_MASK                        8u

#define PIO1_INTR_SM2_RXNEMPTY_OFFSET                      2u
#define PIO1_INTR_SM2_RXNEMPTY_MASK                        4u

#define PIO1_INTR_SM1_RXNEMPTY_OFFSET                      1u
#define PIO1_INTR_SM1_RXNEMPTY_MASK                        2u

#define PIO1_INTR_SM0_RXNEMPTY_OFFSET                      0u
#define PIO1_INTR_SM0_RXNEMPTY_MASK                        1u

#define PIO1_IRQ0_INTE_SM3_OFFSET                          11u
#define PIO1_IRQ0_INTE_SM3_MASK                            0x800u

#define PIO1_IRQ0_INTE_SM2_OFFSET                          10u
#define PIO1_IRQ0_INTE_SM2_MASK                            0x400u

#define PIO1_IRQ0_INTE_SM1_OFFSET                          9u
#define PIO1_IRQ0_INTE_SM1_MASK                            0x200u

#define PIO1_IRQ0_INTE_SM0_OFFSET                          8u
#define PIO1_IRQ0_INTE_SM0_MASK                            0x100u

#define PIO1_IRQ0_INTE_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ0_INTE_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ0_INTE_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ0_INTE_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ0_INTE_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ0_INTE_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ0_INTE_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ0_INTE_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ0_INTE_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ0_INTE_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ0_INTE_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ0_INTE_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ0_INTE_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ0_INTE_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ0_INTE_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ0_INTE_SM0_RXNEMPTY_MASK                   1u

#define PIO1_IRQ0_INTF_SM3_OFFSET                          11u
#define PIO1_IRQ0_INTF_SM3_MASK                            0x800u

#define PIO1_IRQ0_INTF_SM2_OFFSET                          10u
#define PIO1_IRQ0_INTF_SM2_MASK                            0x400u

#define PIO1_IRQ0_INTF_SM1_OFFSET                          9u
#define PIO1_IRQ0_INTF_SM1_MASK                            0x200u

#define PIO1_IRQ0_INTF_SM0_OFFSET                          8u
#define PIO1_IRQ0_INTF_SM0_MASK                            0x100u

#define PIO1_IRQ0_INTF_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ0_INTF_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ0_INTF_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ0_INTF_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ0_INTF_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ0_INTF_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ0_INTF_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ0_INTF_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ0_INTF_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ0_INTF_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ0_INTF_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ0_INTF_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ0_INTF_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ0_INTF_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ0_INTF_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ0_INTF_SM0_RXNEMPTY_MASK                   1u

#define PIO1_IRQ0_INTS_SM3_OFFSET                          11u
#define PIO1_IRQ0_INTS_SM3_MASK                            0x800u

#define PIO1_IRQ0_INTS_SM2_OFFSET                          10u
#define PIO1_IRQ0_INTS_SM2_MASK                            0x400u

#define PIO1_IRQ0_INTS_SM1_OFFSET                          9u
#define PIO1_IRQ0_INTS_SM1_MASK                            0x200u

#define PIO1_IRQ0_INTS_SM0_OFFSET                          8u
#define PIO1_IRQ0_INTS_SM0_MASK                            0x100u

#define PIO1_IRQ0_INTS_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ0_INTS_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ0_INTS_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ0_INTS_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ0_INTS_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ0_INTS_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ0_INTS_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ0_INTS_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ0_INTS_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ0_INTS_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ0_INTS_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ0_INTS_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ0_INTS_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ0_INTS_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ0_INTS_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ0_INTS_SM0_RXNEMPTY_MASK                   1u

#define PIO1_IRQ1_INTE_SM3_OFFSET                          11u
#define PIO1_IRQ1_INTE_SM3_MASK                            0x800u

#define PIO1_IRQ1_INTE_SM2_OFFSET                          10u
#define PIO1_IRQ1_INTE_SM2_MASK                            0x400u

#define PIO1_IRQ1_INTE_SM1_OFFSET                          9u
#define PIO1_IRQ1_INTE_SM1_MASK                            0x200u

#define PIO1_IRQ1_INTE_SM0_OFFSET                          8u
#define PIO1_IRQ1_INTE_SM0_MASK                            0x100u

#define PIO1_IRQ1_INTE_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ1_INTE_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ1_INTE_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ1_INTE_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ1_INTE_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ1_INTE_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ1_INTE_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ1_INTE_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ1_INTE_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ1_INTE_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ1_INTE_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ1_INTE_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ1_INTE_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ1_INTE_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ1_INTE_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ1_INTE_SM0_RXNEMPTY_MASK                   1u

#define PIO1_IRQ1_INTF_SM3_OFFSET                          11u
#define PIO1_IRQ1_INTF_SM3_MASK                            0x800u

#define PIO1_IRQ1_INTF_SM2_OFFSET                          10u
#define PIO1_IRQ1_INTF_SM2_MASK                            0x400u

#define PIO1_IRQ1_INTF_SM1_OFFSET                          9u
#define PIO1_IRQ1_INTF_SM1_MASK                            0x200u

#define PIO1_IRQ1_INTF_SM0_OFFSET                          8u
#define PIO1_IRQ1_INTF_SM0_MASK                            0x100u

#define PIO1_IRQ1_INTF_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ1_INTF_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ1_INTF_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ1_INTF_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ1_INTF_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ1_INTF_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ1_INTF_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ1_INTF_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ1_INTF_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ1_INTF_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ1_INTF_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ1_INTF_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ1_INTF_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ1_INTF_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ1_INTF_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ1_INTF_SM0_RXNEMPTY_MASK                   1u

#define PIO1_IRQ1_INTS_SM3_OFFSET                          11u
#define PIO1_IRQ1_INTS_SM3_MASK                            0x800u

#define PIO1_IRQ1_INTS_SM2_OFFSET                          10u
#define PIO1_IRQ1_INTS_SM2_MASK                            0x400u

#define PIO1_IRQ1_INTS_SM1_OFFSET                          9u
#define PIO1_IRQ1_INTS_SM1_MASK                            0x200u

#define PIO1_IRQ1_INTS_SM0_OFFSET                          8u
#define PIO1_IRQ1_INTS_SM0_MASK                            0x100u

#define PIO1_IRQ1_INTS_SM3_TXNFULL_OFFSET                  7u
#define PIO1_IRQ1_INTS_SM3_TXNFULL_MASK                    0x80u

#define PIO1_IRQ1_INTS_SM2_TXNFULL_OFFSET                  6u
#define PIO1_IRQ1_INTS_SM2_TXNFULL_MASK                    0x40u

#define PIO1_IRQ1_INTS_SM1_TXNFULL_OFFSET                  5u
#define PIO1_IRQ1_INTS_SM1_TXNFULL_MASK                    0x20u

#define PIO1_IRQ1_INTS_SM0_TXNFULL_OFFSET                  4u
#define PIO1_IRQ1_INTS_SM0_TXNFULL_MASK                    0x10u

#define PIO1_IRQ1_INTS_SM3_RXNEMPTY_OFFSET                 3u
#define PIO1_IRQ1_INTS_SM3_RXNEMPTY_MASK                   8u

#define PIO1_IRQ1_INTS_SM2_RXNEMPTY_OFFSET                 2u
#define PIO1_IRQ1_INTS_SM2_RXNEMPTY_MASK                   4u

#define PIO1_IRQ1_INTS_SM1_RXNEMPTY_OFFSET                 1u
#define PIO1_IRQ1_INTS_SM1_RXNEMPTY_MASK                   2u

#define PIO1_IRQ1_INTS_SM0_RXNEMPTY_OFFSET                 0u
#define PIO1_IRQ1_INTS_SM0_RXNEMPTY_MASK                   1u


typedef struct
{

/** CTRL (offset: 0x0)
  PIO control register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLKDIV_RESTART
  offset: 8, size: 4, access: read-write
  Restart a state machine&apos;s clock divider from an initial phase of 0. Clock dividers are free-running, so once started, their output (including fractional jitter) is completely determined by the integer/fractional divisor configured in SMx_CLKDIV. This means that, if multiple clock dividers with the same divisor are restarted simultaneously, by writing multiple 1 bits to this field, the execution clocks of those state machines will run in precise lockstep.


 Note that setting/clearing SM_ENABLE does not stop the clock divider from running, so once multiple state machines&apos; clocks are synchronised, it is safe to disable/reenable a state machine, whilst keeping the clock dividers in sync.


 Note also that CLKDIV_RESTART can be written to whilst the state machine is running, and this is useful to resynchronise clock dividers after the divisors (SMx_CLKDIV) have been changed on-the-fly.
  Field: SM_RESTART
  offset: 4, size: 4, access: read-write
  Write 1 to instantly clear internal SM state which may be otherwise difficult to access and will affect future execution.


 Specifically, the following are cleared: input and output shift counters the contents of the input shift register the delay counter the waiting-on-IRQ state any stalled instruction written to SMx_INSTR or run by OUT/MOV EXEC any pin write left asserted due to OUT_STICKY.
  Field: SM_ENABLE
  offset: 0, size: 4, access: read-write
  Enable/disable each of the four state machines by writing 1/0 to each of these four bits. When disabled, a state machine will cease executing instructions, except those written directly to SMx_INSTR by the system. Multiple bits can be set/cleared at once to run/halt multiple state machines simultaneously.
*/
volatile uint32_t CTRL;

/** FSTAT (offset: 0x4)
  FIFO status register
  access : read-write
  reset value : 0xF000F00
  reset mask : 0x0
  Field: TXEMPTY
  offset: 24, size: 4, access: read-only
  State machine TX FIFO is empty
  Field: TXFULL
  offset: 16, size: 4, access: read-only
  State machine TX FIFO is full
  Field: RXEMPTY
  offset: 8, size: 4, access: read-only
  State machine RX FIFO is empty
  Field: RXFULL
  offset: 0, size: 4, access: read-only
  State machine RX FIFO is full
*/
volatile uint32_t FSTAT;

/** FDEBUG (offset: 0x8)
  FIFO debug register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXSTALL
  offset: 24, size: 4, access: read-write
  State machine has stalled on empty TX FIFO during a blocking PULL, or an OUT with autopull enabled. Write 1 to clear.
  Field: TXOVER
  offset: 16, size: 4, access: read-write
  TX FIFO overflow (i.e. write-on-full by the system) has occurred. Write 1 to clear. Note that write-on-full does not alter the state or contents of the FIFO in any way, but the data that the system attempted to write is dropped, so if this flag is set, your software has quite likely dropped some data on the floor.
  Field: RXUNDER
  offset: 8, size: 4, access: read-write
  RX FIFO underflow (i.e. read-on-empty by the system) has occurred. Write 1 to clear. Note that read-on-empty does not perturb the state of the FIFO in any way, but the data returned by reading from an empty FIFO is undefined, so this flag generally only becomes set due to some kind of software error.
  Field: RXSTALL
  offset: 0, size: 4, access: read-write
  State machine has stalled on full RX FIFO during a blocking PUSH, or an IN with autopush enabled. This flag is also set when a nonblocking PUSH to a full FIFO took place, in which case the state machine has dropped data. Write 1 to clear.
*/
volatile uint32_t FDEBUG;

/** FLEVEL (offset: 0xc)
  FIFO levels
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RX3
  offset: 28, size: 4, access: read-only
  Field: TX3
  offset: 24, size: 4, access: read-only
  Field: RX2
  offset: 20, size: 4, access: read-only
  Field: TX2
  offset: 16, size: 4, access: read-only
  Field: RX1
  offset: 12, size: 4, access: read-only
  Field: TX1
  offset: 8, size: 4, access: read-only
  Field: RX0
  offset: 4, size: 4, access: read-only
  Field: TX0
  offset: 0, size: 4, access: read-only
*/
volatile uint32_t FLEVEL;

/** TXF0 (offset: 0x10)
  Direct write access to the TX FIFO for this state machine. Each write pushes one word to the FIFO. Attempting to write to a full FIFO has no effect on the FIFO state or contents, and sets the sticky FDEBUG_TXOVER error flag for this FIFO.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TXF0;

/** TXF1 (offset: 0x14)
  Direct write access to the TX FIFO for this state machine. Each write pushes one word to the FIFO. Attempting to write to a full FIFO has no effect on the FIFO state or contents, and sets the sticky FDEBUG_TXOVER error flag for this FIFO.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TXF1;

/** TXF2 (offset: 0x18)
  Direct write access to the TX FIFO for this state machine. Each write pushes one word to the FIFO. Attempting to write to a full FIFO has no effect on the FIFO state or contents, and sets the sticky FDEBUG_TXOVER error flag for this FIFO.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TXF2;

/** TXF3 (offset: 0x1c)
  Direct write access to the TX FIFO for this state machine. Each write pushes one word to the FIFO. Attempting to write to a full FIFO has no effect on the FIFO state or contents, and sets the sticky FDEBUG_TXOVER error flag for this FIFO.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TXF3;

/** RXF0 (offset: 0x20)
  Direct read access to the RX FIFO for this state machine. Each read pops one word from the FIFO. Attempting to read from an empty FIFO has no effect on the FIFO state, and sets the sticky FDEBUG_RXUNDER error flag for this FIFO. The data returned to the system on a read from an empty FIFO is undefined.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t RXF0;

/** RXF1 (offset: 0x24)
  Direct read access to the RX FIFO for this state machine. Each read pops one word from the FIFO. Attempting to read from an empty FIFO has no effect on the FIFO state, and sets the sticky FDEBUG_RXUNDER error flag for this FIFO. The data returned to the system on a read from an empty FIFO is undefined.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t RXF1;

/** RXF2 (offset: 0x28)
  Direct read access to the RX FIFO for this state machine. Each read pops one word from the FIFO. Attempting to read from an empty FIFO has no effect on the FIFO state, and sets the sticky FDEBUG_RXUNDER error flag for this FIFO. The data returned to the system on a read from an empty FIFO is undefined.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t RXF2;

/** RXF3 (offset: 0x2c)
  Direct read access to the RX FIFO for this state machine. Each read pops one word from the FIFO. Attempting to read from an empty FIFO has no effect on the FIFO state, and sets the sticky FDEBUG_RXUNDER error flag for this FIFO. The data returned to the system on a read from an empty FIFO is undefined.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t RXF3;

/** IRQ (offset: 0x30)
  State machine IRQ flags register. Write 1 to clear. There are 8 state machine IRQ flags, which can be set, cleared, and waited on by the state machines. There&apos;s no fixed association between flags and state machines -- any state machine can use any flag.


 Any of the 8 flags can be used for timing synchronisation between state machines, using IRQ and WAIT instructions. The lower four of these flags are also routed out to system-level interrupt requests, alongside FIFO status interrupts -- see e.g. IRQ0_INTE.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQ
  offset: 0, size: 8, access: read-write
*/
volatile uint32_t IRQ;

/** IRQ_FORCE (offset: 0x34)
  Writing a 1 to each of these bits will forcibly assert the corresponding IRQ. Note this is different to the INTF register: writing here affects PIO internal state. INTF just asserts the processor-facing IRQ signal for testing ISRs, and is not visible to the state machines.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQ_FORCE
  offset: 0, size: 8, access: write-only
*/
volatile uint32_t IRQ_FORCE;

/** INPUT_SYNC_BYPASS (offset: 0x38)
  There is a 2-flipflop synchronizer on each GPIO input, which protects PIO logic from metastabilities. This increases input delay, and for fast synchronous IO (e.g. SPI) these synchronizers may need to be bypassed. Each bit in this register corresponds to one GPIO.

 0 -&gt; input is synchronized (default)

 1 -&gt; synchronizer is bypassed

 If in doubt, leave this register as all zeroes.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INPUT_SYNC_BYPASS;

/** DBG_PADOUT (offset: 0x3c)
  Read to sample the pad output values PIO is currently driving to the GPIOs. On RP2040 there are 30 GPIOs, so the two most significant bits are hardwired to 0.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DBG_PADOUT;

/** DBG_PADOE (offset: 0x40)
  Read to sample the pad output enables (direction) PIO is currently driving to the GPIOs. On RP2040 there are 30 GPIOs, so the two most significant bits are hardwired to 0.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DBG_PADOE;

/** DBG_CFGINFO (offset: 0x44)
  The PIO hardware has some free parameters that may vary between chip products.

 These should be provided in the chip datasheet, but are also exposed here.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IMEM_SIZE
  offset: 16, size: 6, access: read-only
  The size of the instruction memory, measured in units of one instruction
  Field: SM_COUNT
  offset: 8, size: 4, access: read-only
  The number of state machines this PIO instance is equipped with.
  Field: FIFO_DEPTH
  offset: 0, size: 6, access: read-only
  The depth of the state machine TX/RX FIFOs, measured in words.

 Joining fifos via SHIFTCTRL_FJOIN gives one FIFO with double

 this depth.
*/
volatile uint32_t DBG_CFGINFO;

/** INSTR_MEM0 (offset: 0x48)
  Write-only access to instruction memory location 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM0
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM0;

/** INSTR_MEM1 (offset: 0x4c)
  Write-only access to instruction memory location 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM1
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM1;

/** INSTR_MEM2 (offset: 0x50)
  Write-only access to instruction memory location 2
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM2
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM2;

/** INSTR_MEM3 (offset: 0x54)
  Write-only access to instruction memory location 3
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM3
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM3;

/** INSTR_MEM4 (offset: 0x58)
  Write-only access to instruction memory location 4
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM4
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM4;

/** INSTR_MEM5 (offset: 0x5c)
  Write-only access to instruction memory location 5
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM5
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM5;

/** INSTR_MEM6 (offset: 0x60)
  Write-only access to instruction memory location 6
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM6
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM6;

/** INSTR_MEM7 (offset: 0x64)
  Write-only access to instruction memory location 7
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM7
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM7;

/** INSTR_MEM8 (offset: 0x68)
  Write-only access to instruction memory location 8
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM8
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM8;

/** INSTR_MEM9 (offset: 0x6c)
  Write-only access to instruction memory location 9
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM9
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM9;

/** INSTR_MEM10 (offset: 0x70)
  Write-only access to instruction memory location 10
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM10
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM10;

/** INSTR_MEM11 (offset: 0x74)
  Write-only access to instruction memory location 11
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM11
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM11;

/** INSTR_MEM12 (offset: 0x78)
  Write-only access to instruction memory location 12
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM12
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM12;

/** INSTR_MEM13 (offset: 0x7c)
  Write-only access to instruction memory location 13
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM13
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM13;

/** INSTR_MEM14 (offset: 0x80)
  Write-only access to instruction memory location 14
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM14
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM14;

/** INSTR_MEM15 (offset: 0x84)
  Write-only access to instruction memory location 15
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM15
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM15;

/** INSTR_MEM16 (offset: 0x88)
  Write-only access to instruction memory location 16
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM16
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM16;

/** INSTR_MEM17 (offset: 0x8c)
  Write-only access to instruction memory location 17
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM17
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM17;

/** INSTR_MEM18 (offset: 0x90)
  Write-only access to instruction memory location 18
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM18
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM18;

/** INSTR_MEM19 (offset: 0x94)
  Write-only access to instruction memory location 19
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM19
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM19;

/** INSTR_MEM20 (offset: 0x98)
  Write-only access to instruction memory location 20
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM20
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM20;

/** INSTR_MEM21 (offset: 0x9c)
  Write-only access to instruction memory location 21
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM21
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM21;

/** INSTR_MEM22 (offset: 0xa0)
  Write-only access to instruction memory location 22
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM22
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM22;

/** INSTR_MEM23 (offset: 0xa4)
  Write-only access to instruction memory location 23
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM23
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM23;

/** INSTR_MEM24 (offset: 0xa8)
  Write-only access to instruction memory location 24
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM24
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM24;

/** INSTR_MEM25 (offset: 0xac)
  Write-only access to instruction memory location 25
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM25
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM25;

/** INSTR_MEM26 (offset: 0xb0)
  Write-only access to instruction memory location 26
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM26
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM26;

/** INSTR_MEM27 (offset: 0xb4)
  Write-only access to instruction memory location 27
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM27
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM27;

/** INSTR_MEM28 (offset: 0xb8)
  Write-only access to instruction memory location 28
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM28
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM28;

/** INSTR_MEM29 (offset: 0xbc)
  Write-only access to instruction memory location 29
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM29
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM29;

/** INSTR_MEM30 (offset: 0xc0)
  Write-only access to instruction memory location 30
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM30
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM30;

/** INSTR_MEM31 (offset: 0xc4)
  Write-only access to instruction memory location 31
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INSTR_MEM31
  offset: 0, size: 16, access: write-only
*/
volatile uint32_t INSTR_MEM31;

/** SM0_CLKDIV (offset: 0xc8)
  Clock divisor register for state machine 0

 Frequency = clock freq / (CLKDIV_INT + CLKDIV_FRAC / 256)
  access : read-write
  reset value : 0x10000
  reset mask : 0x0
  Field: INT
  offset: 16, size: 16, access: read-write
  Effective frequency is sysclk/(int + frac/256).

 Value of 0 is interpreted as 65536. If INT is 0, FRAC must also be 0.
  Field: FRAC
  offset: 8, size: 8, access: read-write
  Fractional part of clock divisor
*/
volatile uint32_t SM0_CLKDIV;

/** SM0_EXECCTRL (offset: 0xcc)
  Execution/behavioural settings for state machine 0
  access : read-write
  reset value : 0x1F000
  reset mask : 0x0
  Field: EXEC_STALLED
  offset: 31, size: 1, access: read-only
  If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. Will clear to 0 once this instruction completes.
  Field: SIDE_EN
  offset: 30, size: 1, access: read-write
  If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. This allows instructions to perform side-set optionally, rather than on every instruction, but the maximum possible side-set width is reduced from 5 to 4. Note that the value of PINCTRL_SIDESET_COUNT is inclusive of this enable bit.
  Field: SIDE_PINDIR
  offset: 29, size: 1, access: read-write
  If 1, side-set data is asserted to pin directions, instead of pin values
  Field: JMP_PIN
  offset: 24, size: 5, access: read-write
  The GPIO number to use as condition for JMP PIN. Unaffected by input mapping.
  Field: OUT_EN_SEL
  offset: 19, size: 5, access: read-write
  Which data bit to use for inline OUT enable
  Field: INLINE_OUT_EN
  offset: 18, size: 1, access: read-write
  If 1, use a bit of OUT data as an auxiliary write enable

 When used in conjunction with OUT_STICKY, writes with an enable of 0 will

 deassert the latest pin write. This can create useful masking/override behaviour

 due to the priority ordering of state machine pin writes (SM0 &lt; SM1 &lt; ...)
  Field: OUT_STICKY
  offset: 17, size: 1, access: read-write
  Continuously assert the most recent OUT/SET to the pins
  Field: WRAP_TOP
  offset: 12, size: 5, access: read-write
  After reaching this address, execution is wrapped to wrap_bottom.

 If the instruction is a jump, and the jump condition is true, the jump takes priority.
  Field: WRAP_BOTTOM
  offset: 7, size: 5, access: read-write
  After reaching wrap_top, execution is wrapped to this address.
  Field: STATUS_SEL
  offset: 4, size: 1, access: read-write
  Comparison used for the MOV x, STATUS instruction.
  Enum:
  Value: 0 - TXLEVEL : All-ones if TX FIFO level &lt; N, otherwise all-zeroes
  Value: 1 - RXLEVEL : All-ones if RX FIFO level &lt; N, otherwise all-zeroes
  Field: STATUS_N
  offset: 0, size: 4, access: read-write
  Comparison level for the MOV x, STATUS instruction
*/
volatile uint32_t SM0_EXECCTRL;

/** SM0_SHIFTCTRL (offset: 0xd0)
  Control behaviour of the input/output shift registers for state machine 0
  access : read-write
  reset value : 0xC0000
  reset mask : 0x0
  Field: FJOIN_RX
  offset: 31, size: 1, access: read-write
  When 1, RX FIFO steals the TX FIFO&apos;s storage, and becomes twice as deep.

 TX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: FJOIN_TX
  offset: 30, size: 1, access: read-write
  When 1, TX FIFO steals the RX FIFO&apos;s storage, and becomes twice as deep.

 RX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: PULL_THRESH
  offset: 25, size: 5, access: read-write
  Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place.

 Write 0 for value of 32.
  Field: PUSH_THRESH
  offset: 20, size: 5, access: read-write
  Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place.

 Write 0 for value of 32.
  Field: OUT_SHIFTDIR
  offset: 19, size: 1, access: read-write
  1 = shift out of output shift register to right. 0 = to left.
  Field: IN_SHIFTDIR
  offset: 18, size: 1, access: read-write
  1 = shift input shift register to right (data enters from left). 0 = to left.
  Field: AUTOPULL
  offset: 17, size: 1, access: read-write
  Pull automatically when the output shift register is emptied, i.e. on or following an OUT instruction which causes the output shift counter to reach or exceed PULL_THRESH.
  Field: AUTOPUSH
  offset: 16, size: 1, access: read-write
  Push automatically when the input shift register is filled, i.e. on an IN instruction which causes the input shift counter to reach or exceed PUSH_THRESH.
*/
volatile uint32_t SM0_SHIFTCTRL;

/** SM0_ADDR (offset: 0xd4)
  Current instruction address of state machine 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM0_ADDR
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t SM0_ADDR;

/** SM0_INSTR (offset: 0xd8)
  Read to see the instruction currently addressed by state machine 0&apos;s program counter

 Write to execute an instruction immediately (including jumps) and then resume execution.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM0_INSTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t SM0_INSTR;

/** SM0_PINCTRL (offset: 0xdc)
  State machine pin control
  access : read-write
  reset value : 0x14000000
  reset mask : 0x0
  Field: SIDESET_COUNT
  offset: 29, size: 3, access: read-write
  The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay).
  Field: SET_COUNT
  offset: 26, size: 3, access: read-write
  The number of pins asserted by a SET. In the range 0 to 5 inclusive.
  Field: OUT_COUNT
  offset: 20, size: 6, access: read-write
  The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. In the range 0 to 32 inclusive.
  Field: IN_BASE
  offset: 15, size: 5, access: read-write
  The pin which is mapped to the least-significant bit of a state machine&apos;s IN data bus. Higher-numbered pins are mapped to consecutively more-significant data bits, with a modulo of 32 applied to pin number.
  Field: SIDESET_BASE
  offset: 10, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction&apos;s side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. The least-significant bit of the side-set portion is the bit written to this pin, with more-significant bits written to higher-numbered pins.
  Field: SET_BASE
  offset: 5, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. The data written to this pin is the least-significant bit of the SET data.
  Field: OUT_BASE
  offset: 0, size: 5, access: read-write
  The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. The data written to this pin will always be the least-significant bit of the OUT or MOV data.
*/
volatile uint32_t SM0_PINCTRL;

/** SM1_CLKDIV (offset: 0xe0)
  Clock divisor register for state machine 1

 Frequency = clock freq / (CLKDIV_INT + CLKDIV_FRAC / 256)
  access : read-write
  reset value : 0x10000
  reset mask : 0x0
  Field: INT
  offset: 16, size: 16, access: read-write
  Effective frequency is sysclk/(int + frac/256).

 Value of 0 is interpreted as 65536. If INT is 0, FRAC must also be 0.
  Field: FRAC
  offset: 8, size: 8, access: read-write
  Fractional part of clock divisor
*/
volatile uint32_t SM1_CLKDIV;

/** SM1_EXECCTRL (offset: 0xe4)
  Execution/behavioural settings for state machine 1
  access : read-write
  reset value : 0x1F000
  reset mask : 0x0
  Field: EXEC_STALLED
  offset: 31, size: 1, access: read-only
  If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. Will clear to 0 once this instruction completes.
  Field: SIDE_EN
  offset: 30, size: 1, access: read-write
  If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. This allows instructions to perform side-set optionally, rather than on every instruction, but the maximum possible side-set width is reduced from 5 to 4. Note that the value of PINCTRL_SIDESET_COUNT is inclusive of this enable bit.
  Field: SIDE_PINDIR
  offset: 29, size: 1, access: read-write
  If 1, side-set data is asserted to pin directions, instead of pin values
  Field: JMP_PIN
  offset: 24, size: 5, access: read-write
  The GPIO number to use as condition for JMP PIN. Unaffected by input mapping.
  Field: OUT_EN_SEL
  offset: 19, size: 5, access: read-write
  Which data bit to use for inline OUT enable
  Field: INLINE_OUT_EN
  offset: 18, size: 1, access: read-write
  If 1, use a bit of OUT data as an auxiliary write enable

 When used in conjunction with OUT_STICKY, writes with an enable of 0 will

 deassert the latest pin write. This can create useful masking/override behaviour

 due to the priority ordering of state machine pin writes (SM0 &lt; SM1 &lt; ...)
  Field: OUT_STICKY
  offset: 17, size: 1, access: read-write
  Continuously assert the most recent OUT/SET to the pins
  Field: WRAP_TOP
  offset: 12, size: 5, access: read-write
  After reaching this address, execution is wrapped to wrap_bottom.

 If the instruction is a jump, and the jump condition is true, the jump takes priority.
  Field: WRAP_BOTTOM
  offset: 7, size: 5, access: read-write
  After reaching wrap_top, execution is wrapped to this address.
  Field: STATUS_SEL
  offset: 4, size: 1, access: read-write
  Comparison used for the MOV x, STATUS instruction.
  Enum:
  Value: 0 - TXLEVEL : All-ones if TX FIFO level &lt; N, otherwise all-zeroes
  Value: 1 - RXLEVEL : All-ones if RX FIFO level &lt; N, otherwise all-zeroes
  Field: STATUS_N
  offset: 0, size: 4, access: read-write
  Comparison level for the MOV x, STATUS instruction
*/
volatile uint32_t SM1_EXECCTRL;

/** SM1_SHIFTCTRL (offset: 0xe8)
  Control behaviour of the input/output shift registers for state machine 1
  access : read-write
  reset value : 0xC0000
  reset mask : 0x0
  Field: FJOIN_RX
  offset: 31, size: 1, access: read-write
  When 1, RX FIFO steals the TX FIFO&apos;s storage, and becomes twice as deep.

 TX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: FJOIN_TX
  offset: 30, size: 1, access: read-write
  When 1, TX FIFO steals the RX FIFO&apos;s storage, and becomes twice as deep.

 RX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: PULL_THRESH
  offset: 25, size: 5, access: read-write
  Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place.

 Write 0 for value of 32.
  Field: PUSH_THRESH
  offset: 20, size: 5, access: read-write
  Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place.

 Write 0 for value of 32.
  Field: OUT_SHIFTDIR
  offset: 19, size: 1, access: read-write
  1 = shift out of output shift register to right. 0 = to left.
  Field: IN_SHIFTDIR
  offset: 18, size: 1, access: read-write
  1 = shift input shift register to right (data enters from left). 0 = to left.
  Field: AUTOPULL
  offset: 17, size: 1, access: read-write
  Pull automatically when the output shift register is emptied, i.e. on or following an OUT instruction which causes the output shift counter to reach or exceed PULL_THRESH.
  Field: AUTOPUSH
  offset: 16, size: 1, access: read-write
  Push automatically when the input shift register is filled, i.e. on an IN instruction which causes the input shift counter to reach or exceed PUSH_THRESH.
*/
volatile uint32_t SM1_SHIFTCTRL;

/** SM1_ADDR (offset: 0xec)
  Current instruction address of state machine 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM1_ADDR
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t SM1_ADDR;

/** SM1_INSTR (offset: 0xf0)
  Read to see the instruction currently addressed by state machine 1&apos;s program counter

 Write to execute an instruction immediately (including jumps) and then resume execution.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM1_INSTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t SM1_INSTR;

/** SM1_PINCTRL (offset: 0xf4)
  State machine pin control
  access : read-write
  reset value : 0x14000000
  reset mask : 0x0
  Field: SIDESET_COUNT
  offset: 29, size: 3, access: read-write
  The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay).
  Field: SET_COUNT
  offset: 26, size: 3, access: read-write
  The number of pins asserted by a SET. In the range 0 to 5 inclusive.
  Field: OUT_COUNT
  offset: 20, size: 6, access: read-write
  The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. In the range 0 to 32 inclusive.
  Field: IN_BASE
  offset: 15, size: 5, access: read-write
  The pin which is mapped to the least-significant bit of a state machine&apos;s IN data bus. Higher-numbered pins are mapped to consecutively more-significant data bits, with a modulo of 32 applied to pin number.
  Field: SIDESET_BASE
  offset: 10, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction&apos;s side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. The least-significant bit of the side-set portion is the bit written to this pin, with more-significant bits written to higher-numbered pins.
  Field: SET_BASE
  offset: 5, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. The data written to this pin is the least-significant bit of the SET data.
  Field: OUT_BASE
  offset: 0, size: 5, access: read-write
  The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. The data written to this pin will always be the least-significant bit of the OUT or MOV data.
*/
volatile uint32_t SM1_PINCTRL;

/** SM2_CLKDIV (offset: 0xf8)
  Clock divisor register for state machine 2

 Frequency = clock freq / (CLKDIV_INT + CLKDIV_FRAC / 256)
  access : read-write
  reset value : 0x10000
  reset mask : 0x0
  Field: INT
  offset: 16, size: 16, access: read-write
  Effective frequency is sysclk/(int + frac/256).

 Value of 0 is interpreted as 65536. If INT is 0, FRAC must also be 0.
  Field: FRAC
  offset: 8, size: 8, access: read-write
  Fractional part of clock divisor
*/
volatile uint32_t SM2_CLKDIV;

/** SM2_EXECCTRL (offset: 0xfc)
  Execution/behavioural settings for state machine 2
  access : read-write
  reset value : 0x1F000
  reset mask : 0x0
  Field: EXEC_STALLED
  offset: 31, size: 1, access: read-only
  If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. Will clear to 0 once this instruction completes.
  Field: SIDE_EN
  offset: 30, size: 1, access: read-write
  If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. This allows instructions to perform side-set optionally, rather than on every instruction, but the maximum possible side-set width is reduced from 5 to 4. Note that the value of PINCTRL_SIDESET_COUNT is inclusive of this enable bit.
  Field: SIDE_PINDIR
  offset: 29, size: 1, access: read-write
  If 1, side-set data is asserted to pin directions, instead of pin values
  Field: JMP_PIN
  offset: 24, size: 5, access: read-write
  The GPIO number to use as condition for JMP PIN. Unaffected by input mapping.
  Field: OUT_EN_SEL
  offset: 19, size: 5, access: read-write
  Which data bit to use for inline OUT enable
  Field: INLINE_OUT_EN
  offset: 18, size: 1, access: read-write
  If 1, use a bit of OUT data as an auxiliary write enable

 When used in conjunction with OUT_STICKY, writes with an enable of 0 will

 deassert the latest pin write. This can create useful masking/override behaviour

 due to the priority ordering of state machine pin writes (SM0 &lt; SM1 &lt; ...)
  Field: OUT_STICKY
  offset: 17, size: 1, access: read-write
  Continuously assert the most recent OUT/SET to the pins
  Field: WRAP_TOP
  offset: 12, size: 5, access: read-write
  After reaching this address, execution is wrapped to wrap_bottom.

 If the instruction is a jump, and the jump condition is true, the jump takes priority.
  Field: WRAP_BOTTOM
  offset: 7, size: 5, access: read-write
  After reaching wrap_top, execution is wrapped to this address.
  Field: STATUS_SEL
  offset: 4, size: 1, access: read-write
  Comparison used for the MOV x, STATUS instruction.
  Enum:
  Value: 0 - TXLEVEL : All-ones if TX FIFO level &lt; N, otherwise all-zeroes
  Value: 1 - RXLEVEL : All-ones if RX FIFO level &lt; N, otherwise all-zeroes
  Field: STATUS_N
  offset: 0, size: 4, access: read-write
  Comparison level for the MOV x, STATUS instruction
*/
volatile uint32_t SM2_EXECCTRL;

/** SM2_SHIFTCTRL (offset: 0x100)
  Control behaviour of the input/output shift registers for state machine 2
  access : read-write
  reset value : 0xC0000
  reset mask : 0x0
  Field: FJOIN_RX
  offset: 31, size: 1, access: read-write
  When 1, RX FIFO steals the TX FIFO&apos;s storage, and becomes twice as deep.

 TX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: FJOIN_TX
  offset: 30, size: 1, access: read-write
  When 1, TX FIFO steals the RX FIFO&apos;s storage, and becomes twice as deep.

 RX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: PULL_THRESH
  offset: 25, size: 5, access: read-write
  Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place.

 Write 0 for value of 32.
  Field: PUSH_THRESH
  offset: 20, size: 5, access: read-write
  Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place.

 Write 0 for value of 32.
  Field: OUT_SHIFTDIR
  offset: 19, size: 1, access: read-write
  1 = shift out of output shift register to right. 0 = to left.
  Field: IN_SHIFTDIR
  offset: 18, size: 1, access: read-write
  1 = shift input shift register to right (data enters from left). 0 = to left.
  Field: AUTOPULL
  offset: 17, size: 1, access: read-write
  Pull automatically when the output shift register is emptied, i.e. on or following an OUT instruction which causes the output shift counter to reach or exceed PULL_THRESH.
  Field: AUTOPUSH
  offset: 16, size: 1, access: read-write
  Push automatically when the input shift register is filled, i.e. on an IN instruction which causes the input shift counter to reach or exceed PUSH_THRESH.
*/
volatile uint32_t SM2_SHIFTCTRL;

/** SM2_ADDR (offset: 0x104)
  Current instruction address of state machine 2
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM2_ADDR
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t SM2_ADDR;

/** SM2_INSTR (offset: 0x108)
  Read to see the instruction currently addressed by state machine 2&apos;s program counter

 Write to execute an instruction immediately (including jumps) and then resume execution.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM2_INSTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t SM2_INSTR;

/** SM2_PINCTRL (offset: 0x10c)
  State machine pin control
  access : read-write
  reset value : 0x14000000
  reset mask : 0x0
  Field: SIDESET_COUNT
  offset: 29, size: 3, access: read-write
  The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay).
  Field: SET_COUNT
  offset: 26, size: 3, access: read-write
  The number of pins asserted by a SET. In the range 0 to 5 inclusive.
  Field: OUT_COUNT
  offset: 20, size: 6, access: read-write
  The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. In the range 0 to 32 inclusive.
  Field: IN_BASE
  offset: 15, size: 5, access: read-write
  The pin which is mapped to the least-significant bit of a state machine&apos;s IN data bus. Higher-numbered pins are mapped to consecutively more-significant data bits, with a modulo of 32 applied to pin number.
  Field: SIDESET_BASE
  offset: 10, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction&apos;s side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. The least-significant bit of the side-set portion is the bit written to this pin, with more-significant bits written to higher-numbered pins.
  Field: SET_BASE
  offset: 5, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. The data written to this pin is the least-significant bit of the SET data.
  Field: OUT_BASE
  offset: 0, size: 5, access: read-write
  The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. The data written to this pin will always be the least-significant bit of the OUT or MOV data.
*/
volatile uint32_t SM2_PINCTRL;

/** SM3_CLKDIV (offset: 0x110)
  Clock divisor register for state machine 3

 Frequency = clock freq / (CLKDIV_INT + CLKDIV_FRAC / 256)
  access : read-write
  reset value : 0x10000
  reset mask : 0x0
  Field: INT
  offset: 16, size: 16, access: read-write
  Effective frequency is sysclk/(int + frac/256).

 Value of 0 is interpreted as 65536. If INT is 0, FRAC must also be 0.
  Field: FRAC
  offset: 8, size: 8, access: read-write
  Fractional part of clock divisor
*/
volatile uint32_t SM3_CLKDIV;

/** SM3_EXECCTRL (offset: 0x114)
  Execution/behavioural settings for state machine 3
  access : read-write
  reset value : 0x1F000
  reset mask : 0x0
  Field: EXEC_STALLED
  offset: 31, size: 1, access: read-only
  If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. Will clear to 0 once this instruction completes.
  Field: SIDE_EN
  offset: 30, size: 1, access: read-write
  If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. This allows instructions to perform side-set optionally, rather than on every instruction, but the maximum possible side-set width is reduced from 5 to 4. Note that the value of PINCTRL_SIDESET_COUNT is inclusive of this enable bit.
  Field: SIDE_PINDIR
  offset: 29, size: 1, access: read-write
  If 1, side-set data is asserted to pin directions, instead of pin values
  Field: JMP_PIN
  offset: 24, size: 5, access: read-write
  The GPIO number to use as condition for JMP PIN. Unaffected by input mapping.
  Field: OUT_EN_SEL
  offset: 19, size: 5, access: read-write
  Which data bit to use for inline OUT enable
  Field: INLINE_OUT_EN
  offset: 18, size: 1, access: read-write
  If 1, use a bit of OUT data as an auxiliary write enable

 When used in conjunction with OUT_STICKY, writes with an enable of 0 will

 deassert the latest pin write. This can create useful masking/override behaviour

 due to the priority ordering of state machine pin writes (SM0 &lt; SM1 &lt; ...)
  Field: OUT_STICKY
  offset: 17, size: 1, access: read-write
  Continuously assert the most recent OUT/SET to the pins
  Field: WRAP_TOP
  offset: 12, size: 5, access: read-write
  After reaching this address, execution is wrapped to wrap_bottom.

 If the instruction is a jump, and the jump condition is true, the jump takes priority.
  Field: WRAP_BOTTOM
  offset: 7, size: 5, access: read-write
  After reaching wrap_top, execution is wrapped to this address.
  Field: STATUS_SEL
  offset: 4, size: 1, access: read-write
  Comparison used for the MOV x, STATUS instruction.
  Enum:
  Value: 0 - TXLEVEL : All-ones if TX FIFO level &lt; N, otherwise all-zeroes
  Value: 1 - RXLEVEL : All-ones if RX FIFO level &lt; N, otherwise all-zeroes
  Field: STATUS_N
  offset: 0, size: 4, access: read-write
  Comparison level for the MOV x, STATUS instruction
*/
volatile uint32_t SM3_EXECCTRL;

/** SM3_SHIFTCTRL (offset: 0x118)
  Control behaviour of the input/output shift registers for state machine 3
  access : read-write
  reset value : 0xC0000
  reset mask : 0x0
  Field: FJOIN_RX
  offset: 31, size: 1, access: read-write
  When 1, RX FIFO steals the TX FIFO&apos;s storage, and becomes twice as deep.

 TX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: FJOIN_TX
  offset: 30, size: 1, access: read-write
  When 1, TX FIFO steals the RX FIFO&apos;s storage, and becomes twice as deep.

 RX FIFO is disabled as a result (always reads as both full and empty).

 FIFOs are flushed when this bit is changed.
  Field: PULL_THRESH
  offset: 25, size: 5, access: read-write
  Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place.

 Write 0 for value of 32.
  Field: PUSH_THRESH
  offset: 20, size: 5, access: read-write
  Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place.

 Write 0 for value of 32.
  Field: OUT_SHIFTDIR
  offset: 19, size: 1, access: read-write
  1 = shift out of output shift register to right. 0 = to left.
  Field: IN_SHIFTDIR
  offset: 18, size: 1, access: read-write
  1 = shift input shift register to right (data enters from left). 0 = to left.
  Field: AUTOPULL
  offset: 17, size: 1, access: read-write
  Pull automatically when the output shift register is emptied, i.e. on or following an OUT instruction which causes the output shift counter to reach or exceed PULL_THRESH.
  Field: AUTOPUSH
  offset: 16, size: 1, access: read-write
  Push automatically when the input shift register is filled, i.e. on an IN instruction which causes the input shift counter to reach or exceed PUSH_THRESH.
*/
volatile uint32_t SM3_SHIFTCTRL;

/** SM3_ADDR (offset: 0x11c)
  Current instruction address of state machine 3
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3_ADDR
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t SM3_ADDR;

/** SM3_INSTR (offset: 0x120)
  Read to see the instruction currently addressed by state machine 3&apos;s program counter

 Write to execute an instruction immediately (including jumps) and then resume execution.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3_INSTR
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t SM3_INSTR;

/** SM3_PINCTRL (offset: 0x124)
  State machine pin control
  access : read-write
  reset value : 0x14000000
  reset mask : 0x0
  Field: SIDESET_COUNT
  offset: 29, size: 3, access: read-write
  The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay).
  Field: SET_COUNT
  offset: 26, size: 3, access: read-write
  The number of pins asserted by a SET. In the range 0 to 5 inclusive.
  Field: OUT_COUNT
  offset: 20, size: 6, access: read-write
  The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. In the range 0 to 32 inclusive.
  Field: IN_BASE
  offset: 15, size: 5, access: read-write
  The pin which is mapped to the least-significant bit of a state machine&apos;s IN data bus. Higher-numbered pins are mapped to consecutively more-significant data bits, with a modulo of 32 applied to pin number.
  Field: SIDESET_BASE
  offset: 10, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction&apos;s side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. The least-significant bit of the side-set portion is the bit written to this pin, with more-significant bits written to higher-numbered pins.
  Field: SET_BASE
  offset: 5, size: 5, access: read-write
  The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. The data written to this pin is the least-significant bit of the SET data.
  Field: OUT_BASE
  offset: 0, size: 5, access: read-write
  The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. The data written to this pin will always be the least-significant bit of the OUT or MOV data.
*/
volatile uint32_t SM3_PINCTRL;

/** INTR (offset: 0x128)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-only
  Field: SM2
  offset: 10, size: 1, access: read-only
  Field: SM1
  offset: 9, size: 1, access: read-only
  Field: SM0
  offset: 8, size: 1, access: read-only
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-only
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-only
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-only
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-only
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-only
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-only
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-only
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR;

/** IRQ0_INTE (offset: 0x12c)
  Interrupt Enable for irq0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-write
  Field: SM2
  offset: 10, size: 1, access: read-write
  Field: SM1
  offset: 9, size: 1, access: read-write
  Field: SM0
  offset: 8, size: 1, access: read-write
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-write
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-write
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-write
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-write
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-write
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-write
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-write
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t IRQ0_INTE;

/** IRQ0_INTF (offset: 0x130)
  Interrupt Force for irq0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-write
  Field: SM2
  offset: 10, size: 1, access: read-write
  Field: SM1
  offset: 9, size: 1, access: read-write
  Field: SM0
  offset: 8, size: 1, access: read-write
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-write
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-write
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-write
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-write
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-write
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-write
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-write
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t IRQ0_INTF;

/** IRQ0_INTS (offset: 0x134)
  Interrupt status after masking &amp; forcing for irq0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-only
  Field: SM2
  offset: 10, size: 1, access: read-only
  Field: SM1
  offset: 9, size: 1, access: read-only
  Field: SM0
  offset: 8, size: 1, access: read-only
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-only
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-only
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-only
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-only
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-only
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-only
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-only
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t IRQ0_INTS;

/** IRQ1_INTE (offset: 0x138)
  Interrupt Enable for irq1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-write
  Field: SM2
  offset: 10, size: 1, access: read-write
  Field: SM1
  offset: 9, size: 1, access: read-write
  Field: SM0
  offset: 8, size: 1, access: read-write
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-write
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-write
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-write
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-write
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-write
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-write
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-write
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t IRQ1_INTE;

/** IRQ1_INTF (offset: 0x13c)
  Interrupt Force for irq1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-write
  Field: SM2
  offset: 10, size: 1, access: read-write
  Field: SM1
  offset: 9, size: 1, access: read-write
  Field: SM0
  offset: 8, size: 1, access: read-write
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-write
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-write
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-write
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-write
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-write
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-write
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-write
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t IRQ1_INTF;

/** IRQ1_INTS (offset: 0x140)
  Interrupt status after masking &amp; forcing for irq1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SM3
  offset: 11, size: 1, access: read-only
  Field: SM2
  offset: 10, size: 1, access: read-only
  Field: SM1
  offset: 9, size: 1, access: read-only
  Field: SM0
  offset: 8, size: 1, access: read-only
  Field: SM3_TXNFULL
  offset: 7, size: 1, access: read-only
  Field: SM2_TXNFULL
  offset: 6, size: 1, access: read-only
  Field: SM1_TXNFULL
  offset: 5, size: 1, access: read-only
  Field: SM0_TXNFULL
  offset: 4, size: 1, access: read-only
  Field: SM3_RXNEMPTY
  offset: 3, size: 1, access: read-only
  Field: SM2_RXNEMPTY
  offset: 2, size: 1, access: read-only
  Field: SM1_RXNEMPTY
  offset: 1, size: 1, access: read-only
  Field: SM0_RXNEMPTY
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t IRQ1_INTS;
} PIO1_type;

#define PIO1 ((PIO1_type *) 0x50300000)

#endif // HW_PIO1_H
