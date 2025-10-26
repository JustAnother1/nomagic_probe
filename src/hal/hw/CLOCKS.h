/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_CLOCKS_H
#define HW_CLOCKS_H
/** Interrupt : CLOCKS_IRQ (Vector: 17)  */
/** Memory Block starting at 0x40008000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define CLOCKS_CLK_GPOUT0_CTRL_NUDGE_OFFSET                20u
#define CLOCKS_CLK_GPOUT0_CTRL_NUDGE_MASK                  0x100000u

#define CLOCKS_CLK_GPOUT0_CTRL_PHASE_OFFSET                16u
#define CLOCKS_CLK_GPOUT0_CTRL_PHASE_MASK                  0x30000u

#define CLOCKS_CLK_GPOUT0_CTRL_DC50_OFFSET                 12u
#define CLOCKS_CLK_GPOUT0_CTRL_DC50_MASK                   0x1000u

#define CLOCKS_CLK_GPOUT0_CTRL_ENABLE_OFFSET               11u
#define CLOCKS_CLK_GPOUT0_CTRL_ENABLE_MASK                 0x800u

#define CLOCKS_CLK_GPOUT0_CTRL_KILL_OFFSET                 10u
#define CLOCKS_CLK_GPOUT0_CTRL_KILL_MASK                   0x400u

#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_OFFSET               5u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_MASK                 0x1e0u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_SYS       0u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN0         1u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN1         2u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_USB       3u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_ROSC_CLKSRC          4u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_XOSC_CLKSRC          5u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_SYS              6u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_USB              7u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_ADC              8u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_RTC              9u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_REF              0xau

#define CLOCKS_CLK_GPOUT0_DIV_INT_OFFSET                   8u
#define CLOCKS_CLK_GPOUT0_DIV_INT_MASK                     0xffffff00u

#define CLOCKS_CLK_GPOUT0_DIV_FRAC_OFFSET                  0u
#define CLOCKS_CLK_GPOUT0_DIV_FRAC_MASK                    0xffu

#define CLOCKS_CLK_GPOUT1_CTRL_NUDGE_OFFSET                20u
#define CLOCKS_CLK_GPOUT1_CTRL_NUDGE_MASK                  0x100000u

#define CLOCKS_CLK_GPOUT1_CTRL_PHASE_OFFSET                16u
#define CLOCKS_CLK_GPOUT1_CTRL_PHASE_MASK                  0x30000u

#define CLOCKS_CLK_GPOUT1_CTRL_DC50_OFFSET                 12u
#define CLOCKS_CLK_GPOUT1_CTRL_DC50_MASK                   0x1000u

#define CLOCKS_CLK_GPOUT1_CTRL_ENABLE_OFFSET               11u
#define CLOCKS_CLK_GPOUT1_CTRL_ENABLE_MASK                 0x800u

#define CLOCKS_CLK_GPOUT1_CTRL_KILL_OFFSET                 10u
#define CLOCKS_CLK_GPOUT1_CTRL_KILL_MASK                   0x400u

#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_OFFSET               5u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_MASK                 0x1e0u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_SYS       0u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN0         1u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN1         2u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_USB       3u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_ROSC_CLKSRC          4u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_XOSC_CLKSRC          5u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_SYS              6u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_USB              7u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_ADC              8u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_RTC              9u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_REF              0xau

#define CLOCKS_CLK_GPOUT1_DIV_INT_OFFSET                   8u
#define CLOCKS_CLK_GPOUT1_DIV_INT_MASK                     0xffffff00u

#define CLOCKS_CLK_GPOUT1_DIV_FRAC_OFFSET                  0u
#define CLOCKS_CLK_GPOUT1_DIV_FRAC_MASK                    0xffu

#define CLOCKS_CLK_GPOUT2_CTRL_NUDGE_OFFSET                20u
#define CLOCKS_CLK_GPOUT2_CTRL_NUDGE_MASK                  0x100000u

#define CLOCKS_CLK_GPOUT2_CTRL_PHASE_OFFSET                16u
#define CLOCKS_CLK_GPOUT2_CTRL_PHASE_MASK                  0x30000u

#define CLOCKS_CLK_GPOUT2_CTRL_DC50_OFFSET                 12u
#define CLOCKS_CLK_GPOUT2_CTRL_DC50_MASK                   0x1000u

#define CLOCKS_CLK_GPOUT2_CTRL_ENABLE_OFFSET               11u
#define CLOCKS_CLK_GPOUT2_CTRL_ENABLE_MASK                 0x800u

#define CLOCKS_CLK_GPOUT2_CTRL_KILL_OFFSET                 10u
#define CLOCKS_CLK_GPOUT2_CTRL_KILL_MASK                   0x400u

#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_OFFSET               5u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_MASK                 0x1e0u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_SYS       0u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN0         1u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN1         2u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_USB       3u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_ROSC_CLKSRC_PH       4u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_XOSC_CLKSRC          5u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_SYS              6u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_USB              7u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_ADC              8u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_RTC              9u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_REF              0xau

#define CLOCKS_CLK_GPOUT2_DIV_INT_OFFSET                   8u
#define CLOCKS_CLK_GPOUT2_DIV_INT_MASK                     0xffffff00u

#define CLOCKS_CLK_GPOUT2_DIV_FRAC_OFFSET                  0u
#define CLOCKS_CLK_GPOUT2_DIV_FRAC_MASK                    0xffu

#define CLOCKS_CLK_GPOUT3_CTRL_NUDGE_OFFSET                20u
#define CLOCKS_CLK_GPOUT3_CTRL_NUDGE_MASK                  0x100000u

#define CLOCKS_CLK_GPOUT3_CTRL_PHASE_OFFSET                16u
#define CLOCKS_CLK_GPOUT3_CTRL_PHASE_MASK                  0x30000u

#define CLOCKS_CLK_GPOUT3_CTRL_DC50_OFFSET                 12u
#define CLOCKS_CLK_GPOUT3_CTRL_DC50_MASK                   0x1000u

#define CLOCKS_CLK_GPOUT3_CTRL_ENABLE_OFFSET               11u
#define CLOCKS_CLK_GPOUT3_CTRL_ENABLE_MASK                 0x800u

#define CLOCKS_CLK_GPOUT3_CTRL_KILL_OFFSET                 10u
#define CLOCKS_CLK_GPOUT3_CTRL_KILL_MASK                   0x400u

#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_OFFSET               5u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_MASK                 0x1e0u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_SYS       0u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN0         1u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN1         2u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_USB       3u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_ROSC_CLKSRC_PH       4u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_XOSC_CLKSRC          5u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_SYS              6u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_USB              7u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_ADC              8u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_RTC              9u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_REF              0xau

#define CLOCKS_CLK_GPOUT3_DIV_INT_OFFSET                   8u
#define CLOCKS_CLK_GPOUT3_DIV_INT_MASK                     0xffffff00u

#define CLOCKS_CLK_GPOUT3_DIV_FRAC_OFFSET                  0u
#define CLOCKS_CLK_GPOUT3_DIV_FRAC_MASK                    0xffu

#define CLOCKS_CLK_REF_CTRL_AUXSRC_OFFSET                  5u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_MASK                    0x60u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_PLL_USB          0u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN0            1u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN1            2u

#define CLOCKS_CLK_REF_CTRL_SRC_OFFSET                     0u
#define CLOCKS_CLK_REF_CTRL_SRC_MASK                       3u
#define CLOCKS_CLK_REF_CTRL_SRC_ROSC_CLKSRC_PH             0u
#define CLOCKS_CLK_REF_CTRL_SRC_CLKSRC_CLK_REF_AUX         1u
#define CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC                2u

#define CLOCKS_CLK_REF_DIV_INT_OFFSET                      8u
#define CLOCKS_CLK_REF_DIV_INT_MASK                        0x300u

#define CLOCKS_CLK_SYS_CTRL_AUXSRC_OFFSET                  5u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_MASK                    0xe0u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_SYS          0u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_USB          1u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_ROSC_CLKSRC             2u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_XOSC_CLKSRC             3u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN0            4u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN1            5u

#define CLOCKS_CLK_SYS_CTRL_SRC_OFFSET                     0u
#define CLOCKS_CLK_SYS_CTRL_SRC_MASK                       1u
#define CLOCKS_CLK_SYS_CTRL_SRC_CLK_REF                    0u
#define CLOCKS_CLK_SYS_CTRL_SRC_CLKSRC_CLK_SYS_AUX         1u

#define CLOCKS_CLK_SYS_DIV_INT_OFFSET                      8u
#define CLOCKS_CLK_SYS_DIV_INT_MASK                        0xffffff00u

#define CLOCKS_CLK_SYS_DIV_FRAC_OFFSET                     0u
#define CLOCKS_CLK_SYS_DIV_FRAC_MASK                       0xffu

#define CLOCKS_CLK_PERI_CTRL_ENABLE_OFFSET                 11u
#define CLOCKS_CLK_PERI_CTRL_ENABLE_MASK                   0x800u

#define CLOCKS_CLK_PERI_CTRL_KILL_OFFSET                   10u
#define CLOCKS_CLK_PERI_CTRL_KILL_MASK                     0x400u

#define CLOCKS_CLK_PERI_CTRL_AUXSRC_OFFSET                 5u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_MASK                   0xe0u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS                0u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS         1u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_USB         2u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_ROSC_CLKSRC_PH         3u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC_CLKSRC            4u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN0           5u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN1           6u

#define CLOCKS_CLK_USB_CTRL_NUDGE_OFFSET                   20u
#define CLOCKS_CLK_USB_CTRL_NUDGE_MASK                     0x100000u

#define CLOCKS_CLK_USB_CTRL_PHASE_OFFSET                   16u
#define CLOCKS_CLK_USB_CTRL_PHASE_MASK                     0x30000u

#define CLOCKS_CLK_USB_CTRL_ENABLE_OFFSET                  11u
#define CLOCKS_CLK_USB_CTRL_ENABLE_MASK                    0x800u

#define CLOCKS_CLK_USB_CTRL_KILL_OFFSET                    10u
#define CLOCKS_CLK_USB_CTRL_KILL_MASK                      0x400u

#define CLOCKS_CLK_USB_CTRL_AUXSRC_OFFSET                  5u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_MASK                    0xe0u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_USB          0u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_SYS          1u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_ROSC_CLKSRC_PH          2u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_XOSC_CLKSRC             3u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN0            4u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN1            5u

#define CLOCKS_CLK_USB_DIV_INT_OFFSET                      8u
#define CLOCKS_CLK_USB_DIV_INT_MASK                        0x300u

#define CLOCKS_CLK_ADC_CTRL_NUDGE_OFFSET                   20u
#define CLOCKS_CLK_ADC_CTRL_NUDGE_MASK                     0x100000u

#define CLOCKS_CLK_ADC_CTRL_PHASE_OFFSET                   16u
#define CLOCKS_CLK_ADC_CTRL_PHASE_MASK                     0x30000u

#define CLOCKS_CLK_ADC_CTRL_ENABLE_OFFSET                  11u
#define CLOCKS_CLK_ADC_CTRL_ENABLE_MASK                    0x800u

#define CLOCKS_CLK_ADC_CTRL_KILL_OFFSET                    10u
#define CLOCKS_CLK_ADC_CTRL_KILL_MASK                      0x400u

#define CLOCKS_CLK_ADC_CTRL_AUXSRC_OFFSET                  5u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_MASK                    0xe0u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_USB          0u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_SYS          1u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_ROSC_CLKSRC_PH          2u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_XOSC_CLKSRC             3u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN0            4u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN1            5u

#define CLOCKS_CLK_ADC_DIV_INT_OFFSET                      8u
#define CLOCKS_CLK_ADC_DIV_INT_MASK                        0x300u

#define CLOCKS_CLK_RTC_CTRL_NUDGE_OFFSET                   20u
#define CLOCKS_CLK_RTC_CTRL_NUDGE_MASK                     0x100000u

#define CLOCKS_CLK_RTC_CTRL_PHASE_OFFSET                   16u
#define CLOCKS_CLK_RTC_CTRL_PHASE_MASK                     0x30000u

#define CLOCKS_CLK_RTC_CTRL_ENABLE_OFFSET                  11u
#define CLOCKS_CLK_RTC_CTRL_ENABLE_MASK                    0x800u

#define CLOCKS_CLK_RTC_CTRL_KILL_OFFSET                    10u
#define CLOCKS_CLK_RTC_CTRL_KILL_MASK                      0x400u

#define CLOCKS_CLK_RTC_CTRL_AUXSRC_OFFSET                  5u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_MASK                    0xe0u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_USB          0u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_SYS          1u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_ROSC_CLKSRC_PH          2u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_XOSC_CLKSRC             3u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN0            4u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN1            5u

#define CLOCKS_CLK_RTC_DIV_INT_OFFSET                      8u
#define CLOCKS_CLK_RTC_DIV_INT_MASK                        0xffffff00u

#define CLOCKS_CLK_RTC_DIV_FRAC_OFFSET                     0u
#define CLOCKS_CLK_RTC_DIV_FRAC_MASK                       0xffu

#define CLOCKS_CLK_SYS_RESUS_CTRL_CLEAR_OFFSET             16u
#define CLOCKS_CLK_SYS_RESUS_CTRL_CLEAR_MASK               0x10000u

#define CLOCKS_CLK_SYS_RESUS_CTRL_FRCE_OFFSET              12u
#define CLOCKS_CLK_SYS_RESUS_CTRL_FRCE_MASK                0x1000u

#define CLOCKS_CLK_SYS_RESUS_CTRL_ENABLE_OFFSET            8u
#define CLOCKS_CLK_SYS_RESUS_CTRL_ENABLE_MASK              0x100u

#define CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT_OFFSET           0u
#define CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT_MASK             0xffu

#define CLOCKS_CLK_SYS_RESUS_STATUS_RESUSSED_OFFSET        0u
#define CLOCKS_CLK_SYS_RESUS_STATUS_RESUSSED_MASK          1u

#define CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ_OFFSET              0u
#define CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ_MASK                0xfffffu

#define CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ_OFFSET              0u
#define CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ_MASK                0x1ffffffu

#define CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ_OFFSET              0u
#define CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ_MASK                0x1ffffffu

#define CLOCKS_FC0_DELAY_FC0_DELAY_OFFSET                  0u
#define CLOCKS_FC0_DELAY_FC0_DELAY_MASK                    7u

#define CLOCKS_FC0_INTERVAL_FC0_INTERVAL_OFFSET            0u
#define CLOCKS_FC0_INTERVAL_FC0_INTERVAL_MASK              0xfu

#define CLOCKS_FC0_SRC_FC0_SRC_OFFSET                      0u
#define CLOCKS_FC0_SRC_FC0_SRC_MASK                        0xffu
#define CLOCKS_FC0_SRC_FC0_SRC_NULL                        0u
#define CLOCKS_FC0_SRC_FC0_SRC_PLL_SYS_CLKSRC_PRIMARY      1u
#define CLOCKS_FC0_SRC_FC0_SRC_PLL_USB_CLKSRC_PRIMARY      2u
#define CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC                 3u
#define CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC_PH              4u
#define CLOCKS_FC0_SRC_FC0_SRC_XOSC_CLKSRC                 5u
#define CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN0                6u
#define CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN1                7u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_REF                     8u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_SYS                     9u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_PERI                    0xau
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_USB                     0xbu
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_ADC                     0xcu
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_RTC                     0xdu

#define CLOCKS_FC0_STATUS_DIED_OFFSET                      28u
#define CLOCKS_FC0_STATUS_DIED_MASK                        0x10000000u

#define CLOCKS_FC0_STATUS_FAST_OFFSET                      24u
#define CLOCKS_FC0_STATUS_FAST_MASK                        0x1000000u

#define CLOCKS_FC0_STATUS_SLOW_OFFSET                      20u
#define CLOCKS_FC0_STATUS_SLOW_MASK                        0x100000u

#define CLOCKS_FC0_STATUS_FAIL_OFFSET                      16u
#define CLOCKS_FC0_STATUS_FAIL_MASK                        0x10000u

#define CLOCKS_FC0_STATUS_WAITING_OFFSET                   12u
#define CLOCKS_FC0_STATUS_WAITING_MASK                     0x1000u

#define CLOCKS_FC0_STATUS_RUNNING_OFFSET                   8u
#define CLOCKS_FC0_STATUS_RUNNING_MASK                     0x100u

#define CLOCKS_FC0_STATUS_DONE_OFFSET                      4u
#define CLOCKS_FC0_STATUS_DONE_MASK                        0x10u

#define CLOCKS_FC0_STATUS_PASS_OFFSET                      0u
#define CLOCKS_FC0_STATUS_PASS_MASK                        1u

#define CLOCKS_FC0_RESULT_KHZ_OFFSET                       5u
#define CLOCKS_FC0_RESULT_KHZ_MASK                         0x3fffffe0u

#define CLOCKS_FC0_RESULT_FRAC_OFFSET                      0u
#define CLOCKS_FC0_RESULT_FRAC_MASK                        0x1fu

#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM3_OFFSET               31u
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM3_MASK                 0x80000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM2_OFFSET               30u
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM2_MASK                 0x40000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM1_OFFSET               29u
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM1_MASK                 0x20000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM0_OFFSET               28u
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM0_MASK                 0x10000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SPI1_OFFSET                27u
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI1_MASK                  0x8000000u

#define CLOCKS_WAKE_EN0_CLK_PERI_SPI1_OFFSET               26u
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI1_MASK                 0x4000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SPI0_OFFSET                25u
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI0_MASK                  0x2000000u

#define CLOCKS_WAKE_EN0_CLK_PERI_SPI0_OFFSET               24u
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI0_MASK                 0x1000000u

#define CLOCKS_WAKE_EN0_CLK_SYS_SIO_OFFSET                 23u
#define CLOCKS_WAKE_EN0_CLK_SYS_SIO_MASK                   0x800000u

#define CLOCKS_WAKE_EN0_CLK_SYS_RTC_OFFSET                 22u
#define CLOCKS_WAKE_EN0_CLK_SYS_RTC_MASK                   0x400000u

#define CLOCKS_WAKE_EN0_CLK_RTC_RTC_OFFSET                 21u
#define CLOCKS_WAKE_EN0_CLK_RTC_RTC_MASK                   0x200000u

#define CLOCKS_WAKE_EN0_CLK_SYS_ROSC_OFFSET                20u
#define CLOCKS_WAKE_EN0_CLK_SYS_ROSC_MASK                  0x100000u

#define CLOCKS_WAKE_EN0_CLK_SYS_ROM_OFFSET                 19u
#define CLOCKS_WAKE_EN0_CLK_SYS_ROM_MASK                   0x80000u

#define CLOCKS_WAKE_EN0_CLK_SYS_RESETS_OFFSET              18u
#define CLOCKS_WAKE_EN0_CLK_SYS_RESETS_MASK                0x40000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PWM_OFFSET                 17u
#define CLOCKS_WAKE_EN0_CLK_SYS_PWM_MASK                   0x20000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PSM_OFFSET                 16u
#define CLOCKS_WAKE_EN0_CLK_SYS_PSM_MASK                   0x10000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_USB_OFFSET             15u
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_USB_MASK               0x8000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_SYS_OFFSET             14u
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_SYS_MASK               0x4000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PIO1_OFFSET                13u
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO1_MASK                  0x2000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PIO0_OFFSET                12u
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO0_MASK                  0x1000u

#define CLOCKS_WAKE_EN0_CLK_SYS_PADS_OFFSET                11u
#define CLOCKS_WAKE_EN0_CLK_SYS_PADS_MASK                  0x800u

#define CLOCKS_WAKE_EN0_CLK_SYS_VREG_AND_CHIP_RESET_OFFSET   10u
#define CLOCKS_WAKE_EN0_CLK_SYS_VREG_AND_CHIP_RESET_MASK   0x400u

#define CLOCKS_WAKE_EN0_CLK_SYS_JTAG_OFFSET                9u
#define CLOCKS_WAKE_EN0_CLK_SYS_JTAG_MASK                  0x200u

#define CLOCKS_WAKE_EN0_CLK_SYS_IO_OFFSET                  8u
#define CLOCKS_WAKE_EN0_CLK_SYS_IO_MASK                    0x100u

#define CLOCKS_WAKE_EN0_CLK_SYS_I2C1_OFFSET                7u
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C1_MASK                  0x80u

#define CLOCKS_WAKE_EN0_CLK_SYS_I2C0_OFFSET                6u
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C0_MASK                  0x40u

#define CLOCKS_WAKE_EN0_CLK_SYS_DMA_OFFSET                 5u
#define CLOCKS_WAKE_EN0_CLK_SYS_DMA_MASK                   0x20u

#define CLOCKS_WAKE_EN0_CLK_SYS_BUSFABRIC_OFFSET           4u
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSFABRIC_MASK             0x10u

#define CLOCKS_WAKE_EN0_CLK_SYS_BUSCTRL_OFFSET             3u
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSCTRL_MASK               8u

#define CLOCKS_WAKE_EN0_CLK_SYS_ADC_OFFSET                 2u
#define CLOCKS_WAKE_EN0_CLK_SYS_ADC_MASK                   4u

#define CLOCKS_WAKE_EN0_CLK_ADC_ADC_OFFSET                 1u
#define CLOCKS_WAKE_EN0_CLK_ADC_ADC_MASK                   2u

#define CLOCKS_WAKE_EN0_CLK_SYS_CLOCKS_OFFSET              0u
#define CLOCKS_WAKE_EN0_CLK_SYS_CLOCKS_MASK                1u

#define CLOCKS_WAKE_EN1_CLK_SYS_XOSC_OFFSET                14u
#define CLOCKS_WAKE_EN1_CLK_SYS_XOSC_MASK                  0x4000u

#define CLOCKS_WAKE_EN1_CLK_SYS_XIP_OFFSET                 13u
#define CLOCKS_WAKE_EN1_CLK_SYS_XIP_MASK                   0x2000u

#define CLOCKS_WAKE_EN1_CLK_SYS_WATCHDOG_OFFSET            12u
#define CLOCKS_WAKE_EN1_CLK_SYS_WATCHDOG_MASK              0x1000u

#define CLOCKS_WAKE_EN1_CLK_USB_USBCTRL_OFFSET             11u
#define CLOCKS_WAKE_EN1_CLK_USB_USBCTRL_MASK               0x800u

#define CLOCKS_WAKE_EN1_CLK_SYS_USBCTRL_OFFSET             10u
#define CLOCKS_WAKE_EN1_CLK_SYS_USBCTRL_MASK               0x400u

#define CLOCKS_WAKE_EN1_CLK_SYS_UART1_OFFSET               9u
#define CLOCKS_WAKE_EN1_CLK_SYS_UART1_MASK                 0x200u

#define CLOCKS_WAKE_EN1_CLK_PERI_UART1_OFFSET              8u
#define CLOCKS_WAKE_EN1_CLK_PERI_UART1_MASK                0x100u

#define CLOCKS_WAKE_EN1_CLK_SYS_UART0_OFFSET               7u
#define CLOCKS_WAKE_EN1_CLK_SYS_UART0_MASK                 0x80u

#define CLOCKS_WAKE_EN1_CLK_PERI_UART0_OFFSET              6u
#define CLOCKS_WAKE_EN1_CLK_PERI_UART0_MASK                0x40u

#define CLOCKS_WAKE_EN1_CLK_SYS_TIMER_OFFSET               5u
#define CLOCKS_WAKE_EN1_CLK_SYS_TIMER_MASK                 0x20u

#define CLOCKS_WAKE_EN1_CLK_SYS_TBMAN_OFFSET               4u
#define CLOCKS_WAKE_EN1_CLK_SYS_TBMAN_MASK                 0x10u

#define CLOCKS_WAKE_EN1_CLK_SYS_SYSINFO_OFFSET             3u
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSINFO_MASK               8u

#define CLOCKS_WAKE_EN1_CLK_SYS_SYSCFG_OFFSET              2u
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSCFG_MASK                4u

#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM5_OFFSET               1u
#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM5_MASK                 2u

#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM4_OFFSET               0u
#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM4_MASK                 1u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM3_OFFSET              31u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM3_MASK                0x80000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM2_OFFSET              30u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM2_MASK                0x40000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM1_OFFSET              29u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM1_MASK                0x20000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM0_OFFSET              28u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM0_MASK                0x10000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI1_OFFSET               27u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI1_MASK                 0x8000000u

#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI1_OFFSET              26u
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI1_MASK                0x4000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI0_OFFSET               25u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI0_MASK                 0x2000000u

#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI0_OFFSET              24u
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI0_MASK                0x1000000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_SIO_OFFSET                23u
#define CLOCKS_SLEEP_EN0_CLK_SYS_SIO_MASK                  0x800000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_RTC_OFFSET                22u
#define CLOCKS_SLEEP_EN0_CLK_SYS_RTC_MASK                  0x400000u

#define CLOCKS_SLEEP_EN0_CLK_RTC_RTC_OFFSET                21u
#define CLOCKS_SLEEP_EN0_CLK_RTC_RTC_MASK                  0x200000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_ROSC_OFFSET               20u
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROSC_MASK                 0x100000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_ROM_OFFSET                19u
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROM_MASK                  0x80000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_RESETS_OFFSET             18u
#define CLOCKS_SLEEP_EN0_CLK_SYS_RESETS_MASK               0x40000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PWM_OFFSET                17u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PWM_MASK                  0x20000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PSM_OFFSET                16u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PSM_MASK                  0x10000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_USB_OFFSET            15u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_USB_MASK              0x8000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_SYS_OFFSET            14u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_SYS_MASK              0x4000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO1_OFFSET               13u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO1_MASK                 0x2000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO0_OFFSET               12u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO0_MASK                 0x1000u

#define CLOCKS_SLEEP_EN0_CLK_SYS_PADS_OFFSET               11u
#define CLOCKS_SLEEP_EN0_CLK_SYS_PADS_MASK                 0x800u

#define CLOCKS_SLEEP_EN0_CLK_SYS_VREG_AND_CHIP_RESET_OFFSET   10u
#define CLOCKS_SLEEP_EN0_CLK_SYS_VREG_AND_CHIP_RESET_MASK  0x400u

#define CLOCKS_SLEEP_EN0_CLK_SYS_JTAG_OFFSET               9u
#define CLOCKS_SLEEP_EN0_CLK_SYS_JTAG_MASK                 0x200u

#define CLOCKS_SLEEP_EN0_CLK_SYS_IO_OFFSET                 8u
#define CLOCKS_SLEEP_EN0_CLK_SYS_IO_MASK                   0x100u

#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C1_OFFSET               7u
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C1_MASK                 0x80u

#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C0_OFFSET               6u
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C0_MASK                 0x40u

#define CLOCKS_SLEEP_EN0_CLK_SYS_DMA_OFFSET                5u
#define CLOCKS_SLEEP_EN0_CLK_SYS_DMA_MASK                  0x20u

#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSFABRIC_OFFSET          4u
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSFABRIC_MASK            0x10u

#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSCTRL_OFFSET            3u
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSCTRL_MASK              8u

#define CLOCKS_SLEEP_EN0_CLK_SYS_ADC_OFFSET                2u
#define CLOCKS_SLEEP_EN0_CLK_SYS_ADC_MASK                  4u

#define CLOCKS_SLEEP_EN0_CLK_ADC_ADC_OFFSET                1u
#define CLOCKS_SLEEP_EN0_CLK_ADC_ADC_MASK                  2u

#define CLOCKS_SLEEP_EN0_CLK_SYS_CLOCKS_OFFSET             0u
#define CLOCKS_SLEEP_EN0_CLK_SYS_CLOCKS_MASK               1u

#define CLOCKS_SLEEP_EN1_CLK_SYS_XOSC_OFFSET               14u
#define CLOCKS_SLEEP_EN1_CLK_SYS_XOSC_MASK                 0x4000u

#define CLOCKS_SLEEP_EN1_CLK_SYS_XIP_OFFSET                13u
#define CLOCKS_SLEEP_EN1_CLK_SYS_XIP_MASK                  0x2000u

#define CLOCKS_SLEEP_EN1_CLK_SYS_WATCHDOG_OFFSET           12u
#define CLOCKS_SLEEP_EN1_CLK_SYS_WATCHDOG_MASK             0x1000u

#define CLOCKS_SLEEP_EN1_CLK_USB_USBCTRL_OFFSET            11u
#define CLOCKS_SLEEP_EN1_CLK_USB_USBCTRL_MASK              0x800u

#define CLOCKS_SLEEP_EN1_CLK_SYS_USBCTRL_OFFSET            10u
#define CLOCKS_SLEEP_EN1_CLK_SYS_USBCTRL_MASK              0x400u

#define CLOCKS_SLEEP_EN1_CLK_SYS_UART1_OFFSET              9u
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART1_MASK                0x200u

#define CLOCKS_SLEEP_EN1_CLK_PERI_UART1_OFFSET             8u
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART1_MASK               0x100u

#define CLOCKS_SLEEP_EN1_CLK_SYS_UART0_OFFSET              7u
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART0_MASK                0x80u

#define CLOCKS_SLEEP_EN1_CLK_PERI_UART0_OFFSET             6u
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART0_MASK               0x40u

#define CLOCKS_SLEEP_EN1_CLK_SYS_TIMER_OFFSET              5u
#define CLOCKS_SLEEP_EN1_CLK_SYS_TIMER_MASK                0x20u

#define CLOCKS_SLEEP_EN1_CLK_SYS_TBMAN_OFFSET              4u
#define CLOCKS_SLEEP_EN1_CLK_SYS_TBMAN_MASK                0x10u

#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSINFO_OFFSET            3u
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSINFO_MASK              8u

#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSCFG_OFFSET             2u
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSCFG_MASK               4u

#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM5_OFFSET              1u
#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM5_MASK                2u

#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM4_OFFSET              0u
#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM4_MASK                1u

#define CLOCKS_ENABLED0_CLK_SYS_SRAM3_OFFSET               31u
#define CLOCKS_ENABLED0_CLK_SYS_SRAM3_MASK                 0x80000000u

#define CLOCKS_ENABLED0_CLK_SYS_SRAM2_OFFSET               30u
#define CLOCKS_ENABLED0_CLK_SYS_SRAM2_MASK                 0x40000000u

#define CLOCKS_ENABLED0_CLK_SYS_SRAM1_OFFSET               29u
#define CLOCKS_ENABLED0_CLK_SYS_SRAM1_MASK                 0x20000000u

#define CLOCKS_ENABLED0_CLK_SYS_SRAM0_OFFSET               28u
#define CLOCKS_ENABLED0_CLK_SYS_SRAM0_MASK                 0x10000000u

#define CLOCKS_ENABLED0_CLK_SYS_SPI1_OFFSET                27u
#define CLOCKS_ENABLED0_CLK_SYS_SPI1_MASK                  0x8000000u

#define CLOCKS_ENABLED0_CLK_PERI_SPI1_OFFSET               26u
#define CLOCKS_ENABLED0_CLK_PERI_SPI1_MASK                 0x4000000u

#define CLOCKS_ENABLED0_CLK_SYS_SPI0_OFFSET                25u
#define CLOCKS_ENABLED0_CLK_SYS_SPI0_MASK                  0x2000000u

#define CLOCKS_ENABLED0_CLK_PERI_SPI0_OFFSET               24u
#define CLOCKS_ENABLED0_CLK_PERI_SPI0_MASK                 0x1000000u

#define CLOCKS_ENABLED0_CLK_SYS_SIO_OFFSET                 23u
#define CLOCKS_ENABLED0_CLK_SYS_SIO_MASK                   0x800000u

#define CLOCKS_ENABLED0_CLK_SYS_RTC_OFFSET                 22u
#define CLOCKS_ENABLED0_CLK_SYS_RTC_MASK                   0x400000u

#define CLOCKS_ENABLED0_CLK_RTC_RTC_OFFSET                 21u
#define CLOCKS_ENABLED0_CLK_RTC_RTC_MASK                   0x200000u

#define CLOCKS_ENABLED0_CLK_SYS_ROSC_OFFSET                20u
#define CLOCKS_ENABLED0_CLK_SYS_ROSC_MASK                  0x100000u

#define CLOCKS_ENABLED0_CLK_SYS_ROM_OFFSET                 19u
#define CLOCKS_ENABLED0_CLK_SYS_ROM_MASK                   0x80000u

#define CLOCKS_ENABLED0_CLK_SYS_RESETS_OFFSET              18u
#define CLOCKS_ENABLED0_CLK_SYS_RESETS_MASK                0x40000u

#define CLOCKS_ENABLED0_CLK_SYS_PWM_OFFSET                 17u
#define CLOCKS_ENABLED0_CLK_SYS_PWM_MASK                   0x20000u

#define CLOCKS_ENABLED0_CLK_SYS_PSM_OFFSET                 16u
#define CLOCKS_ENABLED0_CLK_SYS_PSM_MASK                   0x10000u

#define CLOCKS_ENABLED0_CLK_SYS_PLL_USB_OFFSET             15u
#define CLOCKS_ENABLED0_CLK_SYS_PLL_USB_MASK               0x8000u

#define CLOCKS_ENABLED0_CLK_SYS_PLL_SYS_OFFSET             14u
#define CLOCKS_ENABLED0_CLK_SYS_PLL_SYS_MASK               0x4000u

#define CLOCKS_ENABLED0_CLK_SYS_PIO1_OFFSET                13u
#define CLOCKS_ENABLED0_CLK_SYS_PIO1_MASK                  0x2000u

#define CLOCKS_ENABLED0_CLK_SYS_PIO0_OFFSET                12u
#define CLOCKS_ENABLED0_CLK_SYS_PIO0_MASK                  0x1000u

#define CLOCKS_ENABLED0_CLK_SYS_PADS_OFFSET                11u
#define CLOCKS_ENABLED0_CLK_SYS_PADS_MASK                  0x800u

#define CLOCKS_ENABLED0_CLK_SYS_VREG_AND_CHIP_RESET_OFFSET   10u
#define CLOCKS_ENABLED0_CLK_SYS_VREG_AND_CHIP_RESET_MASK   0x400u

#define CLOCKS_ENABLED0_CLK_SYS_JTAG_OFFSET                9u
#define CLOCKS_ENABLED0_CLK_SYS_JTAG_MASK                  0x200u

#define CLOCKS_ENABLED0_CLK_SYS_IO_OFFSET                  8u
#define CLOCKS_ENABLED0_CLK_SYS_IO_MASK                    0x100u

#define CLOCKS_ENABLED0_CLK_SYS_I2C1_OFFSET                7u
#define CLOCKS_ENABLED0_CLK_SYS_I2C1_MASK                  0x80u

#define CLOCKS_ENABLED0_CLK_SYS_I2C0_OFFSET                6u
#define CLOCKS_ENABLED0_CLK_SYS_I2C0_MASK                  0x40u

#define CLOCKS_ENABLED0_CLK_SYS_DMA_OFFSET                 5u
#define CLOCKS_ENABLED0_CLK_SYS_DMA_MASK                   0x20u

#define CLOCKS_ENABLED0_CLK_SYS_BUSFABRIC_OFFSET           4u
#define CLOCKS_ENABLED0_CLK_SYS_BUSFABRIC_MASK             0x10u

#define CLOCKS_ENABLED0_CLK_SYS_BUSCTRL_OFFSET             3u
#define CLOCKS_ENABLED0_CLK_SYS_BUSCTRL_MASK               8u

#define CLOCKS_ENABLED0_CLK_SYS_ADC_OFFSET                 2u
#define CLOCKS_ENABLED0_CLK_SYS_ADC_MASK                   4u

#define CLOCKS_ENABLED0_CLK_ADC_ADC_OFFSET                 1u
#define CLOCKS_ENABLED0_CLK_ADC_ADC_MASK                   2u

#define CLOCKS_ENABLED0_CLK_SYS_CLOCKS_OFFSET              0u
#define CLOCKS_ENABLED0_CLK_SYS_CLOCKS_MASK                1u

#define CLOCKS_ENABLED1_CLK_SYS_XOSC_OFFSET                14u
#define CLOCKS_ENABLED1_CLK_SYS_XOSC_MASK                  0x4000u

#define CLOCKS_ENABLED1_CLK_SYS_XIP_OFFSET                 13u
#define CLOCKS_ENABLED1_CLK_SYS_XIP_MASK                   0x2000u

#define CLOCKS_ENABLED1_CLK_SYS_WATCHDOG_OFFSET            12u
#define CLOCKS_ENABLED1_CLK_SYS_WATCHDOG_MASK              0x1000u

#define CLOCKS_ENABLED1_CLK_USB_USBCTRL_OFFSET             11u
#define CLOCKS_ENABLED1_CLK_USB_USBCTRL_MASK               0x800u

#define CLOCKS_ENABLED1_CLK_SYS_USBCTRL_OFFSET             10u
#define CLOCKS_ENABLED1_CLK_SYS_USBCTRL_MASK               0x400u

#define CLOCKS_ENABLED1_CLK_SYS_UART1_OFFSET               9u
#define CLOCKS_ENABLED1_CLK_SYS_UART1_MASK                 0x200u

#define CLOCKS_ENABLED1_CLK_PERI_UART1_OFFSET              8u
#define CLOCKS_ENABLED1_CLK_PERI_UART1_MASK                0x100u

#define CLOCKS_ENABLED1_CLK_SYS_UART0_OFFSET               7u
#define CLOCKS_ENABLED1_CLK_SYS_UART0_MASK                 0x80u

#define CLOCKS_ENABLED1_CLK_PERI_UART0_OFFSET              6u
#define CLOCKS_ENABLED1_CLK_PERI_UART0_MASK                0x40u

#define CLOCKS_ENABLED1_CLK_SYS_TIMER_OFFSET               5u
#define CLOCKS_ENABLED1_CLK_SYS_TIMER_MASK                 0x20u

#define CLOCKS_ENABLED1_CLK_SYS_TBMAN_OFFSET               4u
#define CLOCKS_ENABLED1_CLK_SYS_TBMAN_MASK                 0x10u

#define CLOCKS_ENABLED1_CLK_SYS_SYSINFO_OFFSET             3u
#define CLOCKS_ENABLED1_CLK_SYS_SYSINFO_MASK               8u

#define CLOCKS_ENABLED1_CLK_SYS_SYSCFG_OFFSET              2u
#define CLOCKS_ENABLED1_CLK_SYS_SYSCFG_MASK                4u

#define CLOCKS_ENABLED1_CLK_SYS_SRAM5_OFFSET               1u
#define CLOCKS_ENABLED1_CLK_SYS_SRAM5_MASK                 2u

#define CLOCKS_ENABLED1_CLK_SYS_SRAM4_OFFSET               0u
#define CLOCKS_ENABLED1_CLK_SYS_SRAM4_MASK                 1u

#define CLOCKS_INTR_CLK_SYS_RESUS_OFFSET                   0u
#define CLOCKS_INTR_CLK_SYS_RESUS_MASK                     1u

#define CLOCKS_INTE_CLK_SYS_RESUS_OFFSET                   0u
#define CLOCKS_INTE_CLK_SYS_RESUS_MASK                     1u

#define CLOCKS_INTF_CLK_SYS_RESUS_OFFSET                   0u
#define CLOCKS_INTF_CLK_SYS_RESUS_MASK                     1u

#define CLOCKS_INTS_CLK_SYS_RESUS_OFFSET                   0u
#define CLOCKS_INTS_CLK_SYS_RESUS_MASK                     1u


typedef struct
{

/** CLK_GPOUT0_CTRL (offset: 0x0)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: DC50
  offset: 12, size: 1, access: read-write
  Enables duty cycle correction for odd divisors
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 4, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_sys
  Value: 1 - clksrc_gpin0
  Value: 2 - clksrc_gpin1
  Value: 3 - clksrc_pll_usb
  Value: 4 - rosc_clksrc
  Value: 5 - xosc_clksrc
  Value: 6 - clk_sys
  Value: 7 - clk_usb
  Value: 8 - clk_adc
  Value: 9 - clk_rtc
  Value: 0xa - clk_ref
*/
volatile uint32_t CLK_GPOUT0_CTRL;

/** CLK_GPOUT0_DIV (offset: 0x4)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_GPOUT0_DIV;

/** CLK_GPOUT0_SELECTED (offset: 0x8)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_GPOUT0_SELECTED;

/** CLK_GPOUT1_CTRL (offset: 0xc)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: DC50
  offset: 12, size: 1, access: read-write
  Enables duty cycle correction for odd divisors
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 4, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_sys
  Value: 1 - clksrc_gpin0
  Value: 2 - clksrc_gpin1
  Value: 3 - clksrc_pll_usb
  Value: 4 - rosc_clksrc
  Value: 5 - xosc_clksrc
  Value: 6 - clk_sys
  Value: 7 - clk_usb
  Value: 8 - clk_adc
  Value: 9 - clk_rtc
  Value: 0xa - clk_ref
*/
volatile uint32_t CLK_GPOUT1_CTRL;

/** CLK_GPOUT1_DIV (offset: 0x10)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_GPOUT1_DIV;

/** CLK_GPOUT1_SELECTED (offset: 0x14)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_GPOUT1_SELECTED;

/** CLK_GPOUT2_CTRL (offset: 0x18)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: DC50
  offset: 12, size: 1, access: read-write
  Enables duty cycle correction for odd divisors
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 4, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_sys
  Value: 1 - clksrc_gpin0
  Value: 2 - clksrc_gpin1
  Value: 3 - clksrc_pll_usb
  Value: 4 - rosc_clksrc_ph
  Value: 5 - xosc_clksrc
  Value: 6 - clk_sys
  Value: 7 - clk_usb
  Value: 8 - clk_adc
  Value: 9 - clk_rtc
  Value: 0xa - clk_ref
*/
volatile uint32_t CLK_GPOUT2_CTRL;

/** CLK_GPOUT2_DIV (offset: 0x1c)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_GPOUT2_DIV;

/** CLK_GPOUT2_SELECTED (offset: 0x20)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_GPOUT2_SELECTED;

/** CLK_GPOUT3_CTRL (offset: 0x24)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: DC50
  offset: 12, size: 1, access: read-write
  Enables duty cycle correction for odd divisors
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 4, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_sys
  Value: 1 - clksrc_gpin0
  Value: 2 - clksrc_gpin1
  Value: 3 - clksrc_pll_usb
  Value: 4 - rosc_clksrc_ph
  Value: 5 - xosc_clksrc
  Value: 6 - clk_sys
  Value: 7 - clk_usb
  Value: 8 - clk_adc
  Value: 9 - clk_rtc
  Value: 0xa - clk_ref
*/
volatile uint32_t CLK_GPOUT3_CTRL;

/** CLK_GPOUT3_DIV (offset: 0x28)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_GPOUT3_DIV;

/** CLK_GPOUT3_SELECTED (offset: 0x2c)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_GPOUT3_SELECTED;

/** CLK_REF_CTRL (offset: 0x30)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AUXSRC
  offset: 5, size: 2, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_usb
  Value: 1 - clksrc_gpin0
  Value: 2 - clksrc_gpin1
  Field: SRC
  offset: 0, size: 2, access: read-write
  Selects the clock source glitchlessly, can be changed on-the-fly
  Enum:
  Value: 0 - rosc_clksrc_ph
  Value: 1 - clksrc_clk_ref_aux
  Value: 2 - xosc_clksrc
*/
volatile uint32_t CLK_REF_CTRL;

/** CLK_REF_DIV (offset: 0x34)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 2, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
*/
volatile uint32_t CLK_REF_DIV;

/** CLK_REF_SELECTED (offset: 0x38)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 The glitchless multiplexer does not switch instantaneously (to avoid glitches), so software should poll this register to wait for the switch to complete. This register contains one decoded bit for each of the clock sources enumerated in the CTRL SRC field. At most one of these bits will be set at any time, indicating that clock is currently present at the output of the glitchless mux. Whilst switching is in progress, this register may briefly show all-0s.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_REF_SELECTED;

/** CLK_SYS_CTRL (offset: 0x3c)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AUXSRC
  offset: 5, size: 3, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_sys
  Value: 1 - clksrc_pll_usb
  Value: 2 - rosc_clksrc
  Value: 3 - xosc_clksrc
  Value: 4 - clksrc_gpin0
  Value: 5 - clksrc_gpin1
  Field: SRC
  offset: 0, size: 1, access: read-write
  Selects the clock source glitchlessly, can be changed on-the-fly
  Enum:
  Value: 0 - clk_ref
  Value: 1 - clksrc_clk_sys_aux
*/
volatile uint32_t CLK_SYS_CTRL;

/** CLK_SYS_DIV (offset: 0x40)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_SYS_DIV;

/** CLK_SYS_SELECTED (offset: 0x44)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 The glitchless multiplexer does not switch instantaneously (to avoid glitches), so software should poll this register to wait for the switch to complete. This register contains one decoded bit for each of the clock sources enumerated in the CTRL SRC field. At most one of these bits will be set at any time, indicating that clock is currently present at the output of the glitchless mux. Whilst switching is in progress, this register may briefly show all-0s.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_SYS_SELECTED;

/** CLK_PERI_CTRL (offset: 0x48)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 3, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clk_sys
  Value: 1 - clksrc_pll_sys
  Value: 2 - clksrc_pll_usb
  Value: 3 - rosc_clksrc_ph
  Value: 4 - xosc_clksrc
  Value: 5 - clksrc_gpin0
  Value: 6 - clksrc_gpin1
*/
volatile uint32_t CLK_PERI_CTRL;
volatile uint32_t reserved0;

/** CLK_PERI_SELECTED (offset: 0x50)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_PERI_SELECTED;

/** CLK_USB_CTRL (offset: 0x54)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 3, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_usb
  Value: 1 - clksrc_pll_sys
  Value: 2 - rosc_clksrc_ph
  Value: 3 - xosc_clksrc
  Value: 4 - clksrc_gpin0
  Value: 5 - clksrc_gpin1
*/
volatile uint32_t CLK_USB_CTRL;

/** CLK_USB_DIV (offset: 0x58)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 2, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
*/
volatile uint32_t CLK_USB_DIV;

/** CLK_USB_SELECTED (offset: 0x5c)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_USB_SELECTED;

/** CLK_ADC_CTRL (offset: 0x60)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 3, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_usb
  Value: 1 - clksrc_pll_sys
  Value: 2 - rosc_clksrc_ph
  Value: 3 - xosc_clksrc
  Value: 4 - clksrc_gpin0
  Value: 5 - clksrc_gpin1
*/
volatile uint32_t CLK_ADC_CTRL;

/** CLK_ADC_DIV (offset: 0x64)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 2, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
*/
volatile uint32_t CLK_ADC_DIV;

/** CLK_ADC_SELECTED (offset: 0x68)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_ADC_SELECTED;

/** CLK_RTC_CTRL (offset: 0x6c)
  Clock control, can be changed on-the-fly (except for auxsrc)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NUDGE
  offset: 20, size: 1, access: read-write
  An edge on this signal shifts the phase of the output by 1 cycle of the input clock

 This can be done at any time
  Field: PHASE
  offset: 16, size: 2, access: read-write
  This delays the enable signal by up to 3 cycles of the input clock

 This must be set before the clock is enabled to have any effect
  Field: ENABLE
  offset: 11, size: 1, access: read-write
  Starts and stops the clock generator cleanly
  Field: KILL
  offset: 10, size: 1, access: read-write
  Asynchronously kills the clock generator
  Field: AUXSRC
  offset: 5, size: 3, access: read-write
  Selects the auxiliary clock source, will glitch when switching
  Enum:
  Value: 0 - clksrc_pll_usb
  Value: 1 - clksrc_pll_sys
  Value: 2 - rosc_clksrc_ph
  Value: 3 - xosc_clksrc
  Value: 4 - clksrc_gpin0
  Value: 5 - clksrc_gpin1
*/
volatile uint32_t CLK_RTC_CTRL;

/** CLK_RTC_DIV (offset: 0x70)
  Clock divisor, can be changed on-the-fly
  access : read-write
  reset value : 0x100
  reset mask : 0x0
  Field: INT
  offset: 8, size: 24, access: read-write
  Integer component of the divisor, 0 -&gt; divide by 2^16
  Field: FRAC
  offset: 0, size: 8, access: read-write
  Fractional component of the divisor
*/
volatile uint32_t CLK_RTC_DIV;

/** CLK_RTC_SELECTED (offset: 0x74)
  Indicates which SRC is currently selected by the glitchless mux (one-hot).

 This slice does not have a glitchless mux (only the AUX_SRC field is present, not SRC) so this register is hardwired to 0x1.
  access : read-only
  reset value : 0x1
  reset mask : 0x0
*/
volatile uint32_t CLK_RTC_SELECTED;

/** CLK_SYS_RESUS_CTRL (offset: 0x78)
  access : read-write
  reset value : 0xFF
  reset mask : 0x0
  Field: CLEAR
  offset: 16, size: 1, access: read-write
  For clearing the resus after the fault that triggered it has been corrected
  Field: FRCE
  offset: 12, size: 1, access: read-write
  Force a resus, for test purposes only
  Field: ENABLE
  offset: 8, size: 1, access: read-write
  Enable resus
  Field: TIMEOUT
  offset: 0, size: 8, access: read-write
  This is expressed as a number of clk_ref cycles

 and must be &gt;= 2x clk_ref_freq/min_clk_tst_freq
*/
volatile uint32_t CLK_SYS_RESUS_CTRL;

/** CLK_SYS_RESUS_STATUS (offset: 0x7c)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RESUSSED
  offset: 0, size: 1, access: read-only
  Clock has been resuscitated, correct the error then send ctrl_clear=1
*/
volatile uint32_t CLK_SYS_RESUS_STATUS;

/** FC0_REF_KHZ (offset: 0x80)
  Reference clock frequency in kHz
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FC0_REF_KHZ
  offset: 0, size: 20, access: read-write
*/
volatile uint32_t FC0_REF_KHZ;

/** FC0_MIN_KHZ (offset: 0x84)
  Minimum pass frequency in kHz. This is optional. Set to 0 if you are not using the pass/fail flags
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FC0_MIN_KHZ
  offset: 0, size: 25, access: read-write
*/
volatile uint32_t FC0_MIN_KHZ;

/** FC0_MAX_KHZ (offset: 0x88)
  Maximum pass frequency in kHz. This is optional. Set to 0x1ffffff if you are not using the pass/fail flags
  access : read-write
  reset value : 0x1FFFFFF
  reset mask : 0x0
  Field: FC0_MAX_KHZ
  offset: 0, size: 25, access: read-write
*/
volatile uint32_t FC0_MAX_KHZ;

/** FC0_DELAY (offset: 0x8c)
  Delays the start of frequency counting to allow the mux to settle

 Delay is measured in multiples of the reference clock period
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: FC0_DELAY
  offset: 0, size: 3, access: read-write
*/
volatile uint32_t FC0_DELAY;

/** FC0_INTERVAL (offset: 0x90)
  The test interval is 0.98us * 2**interval, but let&apos;s call it 1us * 2**interval

 The default gives a test interval of 250us
  access : read-write
  reset value : 0x8
  reset mask : 0x0
  Field: FC0_INTERVAL
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t FC0_INTERVAL;

/** FC0_SRC (offset: 0x94)
  Clock sent to frequency counter, set to 0 when not required

 Writing to this register initiates the frequency count
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FC0_SRC
  offset: 0, size: 8, access: read-write
  Enum:
  Value: 0 - NULL
  Value: 1 - pll_sys_clksrc_primary
  Value: 2 - pll_usb_clksrc_primary
  Value: 3 - rosc_clksrc
  Value: 4 - rosc_clksrc_ph
  Value: 5 - xosc_clksrc
  Value: 6 - clksrc_gpin0
  Value: 7 - clksrc_gpin1
  Value: 8 - clk_ref
  Value: 9 - clk_sys
  Value: 0xa - clk_peri
  Value: 0xb - clk_usb
  Value: 0xc - clk_adc
  Value: 0xd - clk_rtc
*/
volatile uint32_t FC0_SRC;

/** FC0_STATUS (offset: 0x98)
  Frequency counter status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DIED
  offset: 28, size: 1, access: read-only
  Test clock stopped during test
  Field: FAST
  offset: 24, size: 1, access: read-only
  Test clock faster than expected, only valid when status_done=1
  Field: SLOW
  offset: 20, size: 1, access: read-only
  Test clock slower than expected, only valid when status_done=1
  Field: FAIL
  offset: 16, size: 1, access: read-only
  Test failed
  Field: WAITING
  offset: 12, size: 1, access: read-only
  Waiting for test clock to start
  Field: RUNNING
  offset: 8, size: 1, access: read-only
  Test running
  Field: DONE
  offset: 4, size: 1, access: read-only
  Test complete
  Field: PASS
  offset: 0, size: 1, access: read-only
  Test passed
*/
volatile uint32_t FC0_STATUS;

/** FC0_RESULT (offset: 0x9c)
  Result of frequency measurement, only valid when status_done=1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: KHZ
  offset: 5, size: 25, access: read-only
  Field: FRAC
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t FC0_RESULT;

/** WAKE_EN
WAKE_EN[0] (offset: 0xa0)
  enable clock in wake mode
  access : read-write
  reset value : 0xFFFFFFFF
  reset mask : 0x0
  Field: clk_sys_sram3
  offset: 31, size: 1, access: read-write
  Field: clk_sys_sram2
  offset: 30, size: 1, access: read-write
  Field: clk_sys_sram1
  offset: 29, size: 1, access: read-write
  Field: clk_sys_sram0
  offset: 28, size: 1, access: read-write
  Field: clk_sys_spi1
  offset: 27, size: 1, access: read-write
  Field: clk_peri_spi1
  offset: 26, size: 1, access: read-write
  Field: clk_sys_spi0
  offset: 25, size: 1, access: read-write
  Field: clk_peri_spi0
  offset: 24, size: 1, access: read-write
  Field: clk_sys_sio
  offset: 23, size: 1, access: read-write
  Field: clk_sys_rtc
  offset: 22, size: 1, access: read-write
  Field: clk_rtc_rtc
  offset: 21, size: 1, access: read-write
  Field: clk_sys_rosc
  offset: 20, size: 1, access: read-write
  Field: clk_sys_rom
  offset: 19, size: 1, access: read-write
  Field: clk_sys_resets
  offset: 18, size: 1, access: read-write
  Field: clk_sys_pwm
  offset: 17, size: 1, access: read-write
  Field: clk_sys_psm
  offset: 16, size: 1, access: read-write
  Field: clk_sys_pll_usb
  offset: 15, size: 1, access: read-write
  Field: clk_sys_pll_sys
  offset: 14, size: 1, access: read-write
  Field: clk_sys_pio1
  offset: 13, size: 1, access: read-write
  Field: clk_sys_pio0
  offset: 12, size: 1, access: read-write
  Field: clk_sys_pads
  offset: 11, size: 1, access: read-write
  Field: clk_sys_vreg_and_chip_reset
  offset: 10, size: 1, access: read-write
  Field: clk_sys_jtag
  offset: 9, size: 1, access: read-write
  Field: clk_sys_io
  offset: 8, size: 1, access: read-write
  Field: clk_sys_i2c1
  offset: 7, size: 1, access: read-write
  Field: clk_sys_i2c0
  offset: 6, size: 1, access: read-write
  Field: clk_sys_dma
  offset: 5, size: 1, access: read-write
  Field: clk_sys_busfabric
  offset: 4, size: 1, access: read-write
  Field: clk_sys_busctrl
  offset: 3, size: 1, access: read-write
  Field: clk_sys_adc
  offset: 2, size: 1, access: read-write
  Field: clk_adc_adc
  offset: 1, size: 1, access: read-write
  Field: clk_sys_clocks
  offset: 0, size: 1, access: read-write

WAKE_EN[1] (offset: 0xa4)
  enable clock in wake mode
  access : read-write
  reset value : 0x7FFF
  reset mask : 0x0
  Field: clk_sys_xosc
  offset: 14, size: 1, access: read-write
  Field: clk_sys_xip
  offset: 13, size: 1, access: read-write
  Field: clk_sys_watchdog
  offset: 12, size: 1, access: read-write
  Field: clk_usb_usbctrl
  offset: 11, size: 1, access: read-write
  Field: clk_sys_usbctrl
  offset: 10, size: 1, access: read-write
  Field: clk_sys_uart1
  offset: 9, size: 1, access: read-write
  Field: clk_peri_uart1
  offset: 8, size: 1, access: read-write
  Field: clk_sys_uart0
  offset: 7, size: 1, access: read-write
  Field: clk_peri_uart0
  offset: 6, size: 1, access: read-write
  Field: clk_sys_timer
  offset: 5, size: 1, access: read-write
  Field: clk_sys_tbman
  offset: 4, size: 1, access: read-write
  Field: clk_sys_sysinfo
  offset: 3, size: 1, access: read-write
  Field: clk_sys_syscfg
  offset: 2, size: 1, access: read-write
  Field: clk_sys_sram5
  offset: 1, size: 1, access: read-write
  Field: clk_sys_sram4
  offset: 0, size: 1, access: read-write

*/
volatile uint32_t WAKE_EN[2];

/** SLEEP_EN
SLEEP_EN[0] (offset: 0xa8)
  enable clock in sleep mode
  access : read-write
  reset value : 0xFFFFFFFF
  reset mask : 0x0
  Field: clk_sys_sram3
  offset: 31, size: 1, access: read-write
  Field: clk_sys_sram2
  offset: 30, size: 1, access: read-write
  Field: clk_sys_sram1
  offset: 29, size: 1, access: read-write
  Field: clk_sys_sram0
  offset: 28, size: 1, access: read-write
  Field: clk_sys_spi1
  offset: 27, size: 1, access: read-write
  Field: clk_peri_spi1
  offset: 26, size: 1, access: read-write
  Field: clk_sys_spi0
  offset: 25, size: 1, access: read-write
  Field: clk_peri_spi0
  offset: 24, size: 1, access: read-write
  Field: clk_sys_sio
  offset: 23, size: 1, access: read-write
  Field: clk_sys_rtc
  offset: 22, size: 1, access: read-write
  Field: clk_rtc_rtc
  offset: 21, size: 1, access: read-write
  Field: clk_sys_rosc
  offset: 20, size: 1, access: read-write
  Field: clk_sys_rom
  offset: 19, size: 1, access: read-write
  Field: clk_sys_resets
  offset: 18, size: 1, access: read-write
  Field: clk_sys_pwm
  offset: 17, size: 1, access: read-write
  Field: clk_sys_psm
  offset: 16, size: 1, access: read-write
  Field: clk_sys_pll_usb
  offset: 15, size: 1, access: read-write
  Field: clk_sys_pll_sys
  offset: 14, size: 1, access: read-write
  Field: clk_sys_pio1
  offset: 13, size: 1, access: read-write
  Field: clk_sys_pio0
  offset: 12, size: 1, access: read-write
  Field: clk_sys_pads
  offset: 11, size: 1, access: read-write
  Field: clk_sys_vreg_and_chip_reset
  offset: 10, size: 1, access: read-write
  Field: clk_sys_jtag
  offset: 9, size: 1, access: read-write
  Field: clk_sys_io
  offset: 8, size: 1, access: read-write
  Field: clk_sys_i2c1
  offset: 7, size: 1, access: read-write
  Field: clk_sys_i2c0
  offset: 6, size: 1, access: read-write
  Field: clk_sys_dma
  offset: 5, size: 1, access: read-write
  Field: clk_sys_busfabric
  offset: 4, size: 1, access: read-write
  Field: clk_sys_busctrl
  offset: 3, size: 1, access: read-write
  Field: clk_sys_adc
  offset: 2, size: 1, access: read-write
  Field: clk_adc_adc
  offset: 1, size: 1, access: read-write
  Field: clk_sys_clocks
  offset: 0, size: 1, access: read-write

SLEEP_EN[1] (offset: 0xac)
  enable clock in sleep mode
  access : read-write
  reset value : 0x7FFF
  reset mask : 0x0
  Field: clk_sys_xosc
  offset: 14, size: 1, access: read-write
  Field: clk_sys_xip
  offset: 13, size: 1, access: read-write
  Field: clk_sys_watchdog
  offset: 12, size: 1, access: read-write
  Field: clk_usb_usbctrl
  offset: 11, size: 1, access: read-write
  Field: clk_sys_usbctrl
  offset: 10, size: 1, access: read-write
  Field: clk_sys_uart1
  offset: 9, size: 1, access: read-write
  Field: clk_peri_uart1
  offset: 8, size: 1, access: read-write
  Field: clk_sys_uart0
  offset: 7, size: 1, access: read-write
  Field: clk_peri_uart0
  offset: 6, size: 1, access: read-write
  Field: clk_sys_timer
  offset: 5, size: 1, access: read-write
  Field: clk_sys_tbman
  offset: 4, size: 1, access: read-write
  Field: clk_sys_sysinfo
  offset: 3, size: 1, access: read-write
  Field: clk_sys_syscfg
  offset: 2, size: 1, access: read-write
  Field: clk_sys_sram5
  offset: 1, size: 1, access: read-write
  Field: clk_sys_sram4
  offset: 0, size: 1, access: read-write

*/
volatile uint32_t SLEEP_EN[2];

/** ENABLED
ENABLED[0] (offset: 0xb0)
  indicates the state of the clock enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: clk_sys_sram3
  offset: 31, size: 1, access: read-only
  Field: clk_sys_sram2
  offset: 30, size: 1, access: read-only
  Field: clk_sys_sram1
  offset: 29, size: 1, access: read-only
  Field: clk_sys_sram0
  offset: 28, size: 1, access: read-only
  Field: clk_sys_spi1
  offset: 27, size: 1, access: read-only
  Field: clk_peri_spi1
  offset: 26, size: 1, access: read-only
  Field: clk_sys_spi0
  offset: 25, size: 1, access: read-only
  Field: clk_peri_spi0
  offset: 24, size: 1, access: read-only
  Field: clk_sys_sio
  offset: 23, size: 1, access: read-only
  Field: clk_sys_rtc
  offset: 22, size: 1, access: read-only
  Field: clk_rtc_rtc
  offset: 21, size: 1, access: read-only
  Field: clk_sys_rosc
  offset: 20, size: 1, access: read-only
  Field: clk_sys_rom
  offset: 19, size: 1, access: read-only
  Field: clk_sys_resets
  offset: 18, size: 1, access: read-only
  Field: clk_sys_pwm
  offset: 17, size: 1, access: read-only
  Field: clk_sys_psm
  offset: 16, size: 1, access: read-only
  Field: clk_sys_pll_usb
  offset: 15, size: 1, access: read-only
  Field: clk_sys_pll_sys
  offset: 14, size: 1, access: read-only
  Field: clk_sys_pio1
  offset: 13, size: 1, access: read-only
  Field: clk_sys_pio0
  offset: 12, size: 1, access: read-only
  Field: clk_sys_pads
  offset: 11, size: 1, access: read-only
  Field: clk_sys_vreg_and_chip_reset
  offset: 10, size: 1, access: read-only
  Field: clk_sys_jtag
  offset: 9, size: 1, access: read-only
  Field: clk_sys_io
  offset: 8, size: 1, access: read-only
  Field: clk_sys_i2c1
  offset: 7, size: 1, access: read-only
  Field: clk_sys_i2c0
  offset: 6, size: 1, access: read-only
  Field: clk_sys_dma
  offset: 5, size: 1, access: read-only
  Field: clk_sys_busfabric
  offset: 4, size: 1, access: read-only
  Field: clk_sys_busctrl
  offset: 3, size: 1, access: read-only
  Field: clk_sys_adc
  offset: 2, size: 1, access: read-only
  Field: clk_adc_adc
  offset: 1, size: 1, access: read-only
  Field: clk_sys_clocks
  offset: 0, size: 1, access: read-only

ENABLED[1] (offset: 0xb4)
  indicates the state of the clock enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: clk_sys_xosc
  offset: 14, size: 1, access: read-only
  Field: clk_sys_xip
  offset: 13, size: 1, access: read-only
  Field: clk_sys_watchdog
  offset: 12, size: 1, access: read-only
  Field: clk_usb_usbctrl
  offset: 11, size: 1, access: read-only
  Field: clk_sys_usbctrl
  offset: 10, size: 1, access: read-only
  Field: clk_sys_uart1
  offset: 9, size: 1, access: read-only
  Field: clk_peri_uart1
  offset: 8, size: 1, access: read-only
  Field: clk_sys_uart0
  offset: 7, size: 1, access: read-only
  Field: clk_peri_uart0
  offset: 6, size: 1, access: read-only
  Field: clk_sys_timer
  offset: 5, size: 1, access: read-only
  Field: clk_sys_tbman
  offset: 4, size: 1, access: read-only
  Field: clk_sys_sysinfo
  offset: 3, size: 1, access: read-only
  Field: clk_sys_syscfg
  offset: 2, size: 1, access: read-only
  Field: clk_sys_sram5
  offset: 1, size: 1, access: read-only
  Field: clk_sys_sram4
  offset: 0, size: 1, access: read-only

*/
volatile uint32_t ENABLED[2];

/** INTR (offset: 0xb8)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLK_SYS_RESUS
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR;

/** INTE (offset: 0xbc)
  Interrupt Enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLK_SYS_RESUS
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTE;

/** INTF (offset: 0xc0)
  Interrupt Force
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLK_SYS_RESUS
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTF;

/** INTS (offset: 0xc4)
  Interrupt status after masking &amp; forcing
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLK_SYS_RESUS
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTS;
} CLOCKS_type;

#define CLOCKS ((CLOCKS_type *) 0x40008000)

#endif // HW_CLOCKS_H
