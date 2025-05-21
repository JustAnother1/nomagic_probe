/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_DMA_H
#define HW_DMA_H
/** DMA with separate read and write masters */
/** Interrupt : DMA_IRQ_0 (Vector: 11)  */
/** Interrupt : DMA_IRQ_1 (Vector: 12)  */
/** Memory Block starting at 0x50000000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define DMA_CH0_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH0_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH0_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH0_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH0_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH0_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH0_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH0_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH0_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH0_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH0_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH0_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH0_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH0_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH0_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH0_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH0_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH0_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH0_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH0_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH0_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH0_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH0_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH0_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH0_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH0_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH0_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH0_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH0_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH0_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH0_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH1_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH1_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH1_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH1_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH1_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH1_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH1_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH1_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH1_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH1_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH1_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH1_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH1_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH1_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH1_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH1_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH1_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH1_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH1_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH1_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH1_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH1_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH1_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH1_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH1_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH1_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH1_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH1_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH1_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH1_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH1_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH2_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH2_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH2_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH2_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH2_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH2_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH2_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH2_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH2_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH2_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH2_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH2_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH2_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH2_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH2_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH2_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH2_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH2_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH2_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH2_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH2_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH2_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH2_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH2_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH2_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH2_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH2_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH2_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH2_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH2_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH2_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH3_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH3_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH3_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH3_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH3_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH3_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH3_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH3_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH3_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH3_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH3_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH3_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH3_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH3_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH3_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH3_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH3_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH3_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH3_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH3_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH3_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH3_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH3_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH3_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH3_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH3_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH3_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH3_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH3_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH3_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH3_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH4_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH4_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH4_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH4_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH4_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH4_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH4_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH4_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH4_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH4_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH4_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH4_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH4_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH4_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH4_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH4_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH4_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH4_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH4_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH4_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH4_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH4_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH4_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH4_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH4_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH4_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH4_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH4_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH4_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH4_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH4_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH5_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH5_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH5_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH5_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH5_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH5_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH5_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH5_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH5_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH5_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH5_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH5_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH5_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH5_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH5_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH5_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH5_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH5_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH5_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH5_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH5_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH5_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH5_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH5_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH5_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH5_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH5_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH5_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH5_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH5_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH5_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH6_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH6_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH6_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH6_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH6_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH6_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH6_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH6_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH6_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH6_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH6_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH6_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH6_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH6_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH6_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH6_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH6_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH6_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH6_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH6_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH6_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH6_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH6_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH6_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH6_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH6_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH6_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH6_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH6_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH6_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH6_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH7_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH7_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH7_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH7_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH7_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH7_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH7_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH7_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH7_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH7_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH7_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH7_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH7_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH7_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH7_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH7_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH7_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH7_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH7_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH7_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH7_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH7_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH7_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH7_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH7_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH7_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH7_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH7_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH7_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH7_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH7_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH8_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH8_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH8_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH8_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH8_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH8_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH8_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH8_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH8_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH8_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH8_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH8_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH8_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH8_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH8_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH8_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH8_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH8_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH8_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH8_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH8_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH8_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH8_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH8_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH8_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH8_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH8_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH8_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH8_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH8_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH8_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH9_CTRL_TRIG_AHB_ERROR_OFFSET                 31u
#define DMA_CH9_CTRL_TRIG_AHB_ERROR_MASK                   0x80000000u

#define DMA_CH9_CTRL_TRIG_READ_ERROR_OFFSET                30u
#define DMA_CH9_CTRL_TRIG_READ_ERROR_MASK                  0x40000000u

#define DMA_CH9_CTRL_TRIG_WRITE_ERROR_OFFSET               29u
#define DMA_CH9_CTRL_TRIG_WRITE_ERROR_MASK                 0x20000000u

#define DMA_CH9_CTRL_TRIG_BUSY_OFFSET                      24u
#define DMA_CH9_CTRL_TRIG_BUSY_MASK                        0x1000000u

#define DMA_CH9_CTRL_TRIG_SNIFF_EN_OFFSET                  23u
#define DMA_CH9_CTRL_TRIG_SNIFF_EN_MASK                    0x800000u

#define DMA_CH9_CTRL_TRIG_BSWAP_OFFSET                     22u
#define DMA_CH9_CTRL_TRIG_BSWAP_MASK                       0x400000u

#define DMA_CH9_CTRL_TRIG_IRQ_QUIET_OFFSET                 21u
#define DMA_CH9_CTRL_TRIG_IRQ_QUIET_MASK                   0x200000u

#define DMA_CH9_CTRL_TRIG_TREQ_SEL_OFFSET                  15u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_MASK                    0x1f8000u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER0                  0x3bu
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER1                  0x3cu
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER2                  0x3du
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER3                  0x3eu
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PERMANENT               0x3fu

#define DMA_CH9_CTRL_TRIG_CHAIN_TO_OFFSET                  11u
#define DMA_CH9_CTRL_TRIG_CHAIN_TO_MASK                    0x7800u

#define DMA_CH9_CTRL_TRIG_RING_SEL_OFFSET                  10u
#define DMA_CH9_CTRL_TRIG_RING_SEL_MASK                    0x400u

#define DMA_CH9_CTRL_TRIG_RING_SIZE_OFFSET                 6u
#define DMA_CH9_CTRL_TRIG_RING_SIZE_MASK                   0x3c0u
#define DMA_CH9_CTRL_TRIG_RING_SIZE_RING_NONE              0u

#define DMA_CH9_CTRL_TRIG_INCR_WRITE_OFFSET                5u
#define DMA_CH9_CTRL_TRIG_INCR_WRITE_MASK                  0x20u

#define DMA_CH9_CTRL_TRIG_INCR_READ_OFFSET                 4u
#define DMA_CH9_CTRL_TRIG_INCR_READ_MASK                   0x10u

#define DMA_CH9_CTRL_TRIG_DATA_SIZE_OFFSET                 2u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_MASK                   0xcu
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_BYTE              0u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD          1u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_WORD              2u

#define DMA_CH9_CTRL_TRIG_HIGH_PRIORITY_OFFSET             1u
#define DMA_CH9_CTRL_TRIG_HIGH_PRIORITY_MASK               2u

#define DMA_CH9_CTRL_TRIG_EN_OFFSET                        0u
#define DMA_CH9_CTRL_TRIG_EN_MASK                          1u

#define DMA_CH10_CTRL_TRIG_AHB_ERROR_OFFSET                31u
#define DMA_CH10_CTRL_TRIG_AHB_ERROR_MASK                  0x80000000u

#define DMA_CH10_CTRL_TRIG_READ_ERROR_OFFSET               30u
#define DMA_CH10_CTRL_TRIG_READ_ERROR_MASK                 0x40000000u

#define DMA_CH10_CTRL_TRIG_WRITE_ERROR_OFFSET              29u
#define DMA_CH10_CTRL_TRIG_WRITE_ERROR_MASK                0x20000000u

#define DMA_CH10_CTRL_TRIG_BUSY_OFFSET                     24u
#define DMA_CH10_CTRL_TRIG_BUSY_MASK                       0x1000000u

#define DMA_CH10_CTRL_TRIG_SNIFF_EN_OFFSET                 23u
#define DMA_CH10_CTRL_TRIG_SNIFF_EN_MASK                   0x800000u

#define DMA_CH10_CTRL_TRIG_BSWAP_OFFSET                    22u
#define DMA_CH10_CTRL_TRIG_BSWAP_MASK                      0x400000u

#define DMA_CH10_CTRL_TRIG_IRQ_QUIET_OFFSET                21u
#define DMA_CH10_CTRL_TRIG_IRQ_QUIET_MASK                  0x200000u

#define DMA_CH10_CTRL_TRIG_TREQ_SEL_OFFSET                 15u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_MASK                   0x1f8000u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER0                 0x3bu
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER1                 0x3cu
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER2                 0x3du
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER3                 0x3eu
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PERMANENT              0x3fu

#define DMA_CH10_CTRL_TRIG_CHAIN_TO_OFFSET                 11u
#define DMA_CH10_CTRL_TRIG_CHAIN_TO_MASK                   0x7800u

#define DMA_CH10_CTRL_TRIG_RING_SEL_OFFSET                 10u
#define DMA_CH10_CTRL_TRIG_RING_SEL_MASK                   0x400u

#define DMA_CH10_CTRL_TRIG_RING_SIZE_OFFSET                6u
#define DMA_CH10_CTRL_TRIG_RING_SIZE_MASK                  0x3c0u
#define DMA_CH10_CTRL_TRIG_RING_SIZE_RING_NONE             0u

#define DMA_CH10_CTRL_TRIG_INCR_WRITE_OFFSET               5u
#define DMA_CH10_CTRL_TRIG_INCR_WRITE_MASK                 0x20u

#define DMA_CH10_CTRL_TRIG_INCR_READ_OFFSET                4u
#define DMA_CH10_CTRL_TRIG_INCR_READ_MASK                  0x10u

#define DMA_CH10_CTRL_TRIG_DATA_SIZE_OFFSET                2u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_MASK                  0xcu
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_BYTE             0u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD         1u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_WORD             2u

#define DMA_CH10_CTRL_TRIG_HIGH_PRIORITY_OFFSET            1u
#define DMA_CH10_CTRL_TRIG_HIGH_PRIORITY_MASK              2u

#define DMA_CH10_CTRL_TRIG_EN_OFFSET                       0u
#define DMA_CH10_CTRL_TRIG_EN_MASK                         1u

#define DMA_CH11_CTRL_TRIG_AHB_ERROR_OFFSET                31u
#define DMA_CH11_CTRL_TRIG_AHB_ERROR_MASK                  0x80000000u

#define DMA_CH11_CTRL_TRIG_READ_ERROR_OFFSET               30u
#define DMA_CH11_CTRL_TRIG_READ_ERROR_MASK                 0x40000000u

#define DMA_CH11_CTRL_TRIG_WRITE_ERROR_OFFSET              29u
#define DMA_CH11_CTRL_TRIG_WRITE_ERROR_MASK                0x20000000u

#define DMA_CH11_CTRL_TRIG_BUSY_OFFSET                     24u
#define DMA_CH11_CTRL_TRIG_BUSY_MASK                       0x1000000u

#define DMA_CH11_CTRL_TRIG_SNIFF_EN_OFFSET                 23u
#define DMA_CH11_CTRL_TRIG_SNIFF_EN_MASK                   0x800000u

#define DMA_CH11_CTRL_TRIG_BSWAP_OFFSET                    22u
#define DMA_CH11_CTRL_TRIG_BSWAP_MASK                      0x400000u

#define DMA_CH11_CTRL_TRIG_IRQ_QUIET_OFFSET                21u
#define DMA_CH11_CTRL_TRIG_IRQ_QUIET_MASK                  0x200000u

#define DMA_CH11_CTRL_TRIG_TREQ_SEL_OFFSET                 15u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_MASK                   0x1f8000u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER0                 0x3bu
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER1                 0x3cu
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER2                 0x3du
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER3                 0x3eu
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PERMANENT              0x3fu

#define DMA_CH11_CTRL_TRIG_CHAIN_TO_OFFSET                 11u
#define DMA_CH11_CTRL_TRIG_CHAIN_TO_MASK                   0x7800u

#define DMA_CH11_CTRL_TRIG_RING_SEL_OFFSET                 10u
#define DMA_CH11_CTRL_TRIG_RING_SEL_MASK                   0x400u

#define DMA_CH11_CTRL_TRIG_RING_SIZE_OFFSET                6u
#define DMA_CH11_CTRL_TRIG_RING_SIZE_MASK                  0x3c0u
#define DMA_CH11_CTRL_TRIG_RING_SIZE_RING_NONE             0u

#define DMA_CH11_CTRL_TRIG_INCR_WRITE_OFFSET               5u
#define DMA_CH11_CTRL_TRIG_INCR_WRITE_MASK                 0x20u

#define DMA_CH11_CTRL_TRIG_INCR_READ_OFFSET                4u
#define DMA_CH11_CTRL_TRIG_INCR_READ_MASK                  0x10u

#define DMA_CH11_CTRL_TRIG_DATA_SIZE_OFFSET                2u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_MASK                  0xcu
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_BYTE             0u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD         1u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_WORD             2u

#define DMA_CH11_CTRL_TRIG_HIGH_PRIORITY_OFFSET            1u
#define DMA_CH11_CTRL_TRIG_HIGH_PRIORITY_MASK              2u

#define DMA_CH11_CTRL_TRIG_EN_OFFSET                       0u
#define DMA_CH11_CTRL_TRIG_EN_MASK                         1u

#define DMA_INTR_INTR_OFFSET                               0u
#define DMA_INTR_INTR_MASK                                 0xffffu

#define DMA_INTE0_INTE0_OFFSET                             0u
#define DMA_INTE0_INTE0_MASK                               0xffffu

#define DMA_INTF0_INTF0_OFFSET                             0u
#define DMA_INTF0_INTF0_MASK                               0xffffu

#define DMA_INTS0_INTS0_OFFSET                             0u
#define DMA_INTS0_INTS0_MASK                               0xffffu

#define DMA_INTE1_INTE1_OFFSET                             0u
#define DMA_INTE1_INTE1_MASK                               0xffffu

#define DMA_INTF1_INTF1_OFFSET                             0u
#define DMA_INTF1_INTF1_MASK                               0xffffu

#define DMA_INTS1_INTS1_OFFSET                             0u
#define DMA_INTS1_INTS1_MASK                               0xffffu

#define DMA_TIMER0_X_OFFSET                                16u
#define DMA_TIMER0_X_MASK                                  0xffff0000u

#define DMA_TIMER0_Y_OFFSET                                0u
#define DMA_TIMER0_Y_MASK                                  0xffffu

#define DMA_TIMER1_X_OFFSET                                16u
#define DMA_TIMER1_X_MASK                                  0xffff0000u

#define DMA_TIMER1_Y_OFFSET                                0u
#define DMA_TIMER1_Y_MASK                                  0xffffu

#define DMA_TIMER2_X_OFFSET                                16u
#define DMA_TIMER2_X_MASK                                  0xffff0000u

#define DMA_TIMER2_Y_OFFSET                                0u
#define DMA_TIMER2_Y_MASK                                  0xffffu

#define DMA_TIMER3_X_OFFSET                                16u
#define DMA_TIMER3_X_MASK                                  0xffff0000u

#define DMA_TIMER3_Y_OFFSET                                0u
#define DMA_TIMER3_Y_MASK                                  0xffffu

#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER_OFFSET   0u
#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER_MASK     0xffffu

#define DMA_SNIFF_CTRL_OUT_INV_OFFSET                      11u
#define DMA_SNIFF_CTRL_OUT_INV_MASK                        0x800u

#define DMA_SNIFF_CTRL_OUT_REV_OFFSET                      10u
#define DMA_SNIFF_CTRL_OUT_REV_MASK                        0x400u

#define DMA_SNIFF_CTRL_BSWAP_OFFSET                        9u
#define DMA_SNIFF_CTRL_BSWAP_MASK                          0x200u

#define DMA_SNIFF_CTRL_CALC_OFFSET                         5u
#define DMA_SNIFF_CTRL_CALC_MASK                           0x1e0u
#define DMA_SNIFF_CTRL_CALC_CRC32                          0u
#define DMA_SNIFF_CTRL_CALC_CRC32R                         1u
#define DMA_SNIFF_CTRL_CALC_CRC16                          2u
#define DMA_SNIFF_CTRL_CALC_CRC16R                         3u
#define DMA_SNIFF_CTRL_CALC_EVEN                           0xeu
#define DMA_SNIFF_CTRL_CALC_SUM                            0xfu

#define DMA_SNIFF_CTRL_DMACH_OFFSET                        1u
#define DMA_SNIFF_CTRL_DMACH_MASK                          0x1eu

#define DMA_SNIFF_CTRL_EN_OFFSET                           0u
#define DMA_SNIFF_CTRL_EN_MASK                             1u

#define DMA_FIFO_LEVELS_RAF_LVL_OFFSET                     16u
#define DMA_FIFO_LEVELS_RAF_LVL_MASK                       0xff0000u

#define DMA_FIFO_LEVELS_WAF_LVL_OFFSET                     8u
#define DMA_FIFO_LEVELS_WAF_LVL_MASK                       0xff00u

#define DMA_FIFO_LEVELS_TDF_LVL_OFFSET                     0u
#define DMA_FIFO_LEVELS_TDF_LVL_MASK                       0xffu

#define DMA_CHAN_ABORT_CHAN_ABORT_OFFSET                   0u
#define DMA_CHAN_ABORT_CHAN_ABORT_MASK                     0xffffu

#define DMA_N_CHANNELS_N_CHANNELS_OFFSET                   0u
#define DMA_N_CHANNELS_N_CHANNELS_MASK                     0x1fu

#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ_OFFSET           0u
#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ_OFFSET           0u
#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ_OFFSET           0u
#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ_OFFSET           0u
#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ_OFFSET           0u
#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ_OFFSET           0u
#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ_OFFSET           0u
#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ_OFFSET           0u
#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ_OFFSET           0u
#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ_OFFSET           0u
#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ_MASK             0x3fu

#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ_OFFSET         0u
#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ_MASK           0x3fu

#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ_OFFSET         0u
#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ_MASK           0x3fu


typedef struct
{

/** CH0_READ_ADDR (offset: 0x0)
  DMA Channel 0 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_READ_ADDR;

/** CH0_WRITE_ADDR (offset: 0x4)
  DMA Channel 0 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_WRITE_ADDR;

/** CH0_TRANS_COUNT (offset: 0x8)
  DMA Channel 0 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_TRANS_COUNT;

/** CH0_CTRL_TRIG (offset: 0xc)
  DMA Channel 0 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH0_CTRL_TRIG;

/** CH0_AL1_CTRL (offset: 0x10)
  Alias for channel 0 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL1_CTRL;

/** CH0_AL1_READ_ADDR (offset: 0x14)
  Alias for channel 0 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL1_READ_ADDR;

/** CH0_AL1_WRITE_ADDR (offset: 0x18)
  Alias for channel 0 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL1_WRITE_ADDR;

/** CH0_AL1_TRANS_COUNT_TRIG (offset: 0x1c)
  Alias for channel 0 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL1_TRANS_COUNT_TRIG;

/** CH0_AL2_CTRL (offset: 0x20)
  Alias for channel 0 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL2_CTRL;

/** CH0_AL2_TRANS_COUNT (offset: 0x24)
  Alias for channel 0 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL2_TRANS_COUNT;

/** CH0_AL2_READ_ADDR (offset: 0x28)
  Alias for channel 0 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL2_READ_ADDR;

/** CH0_AL2_WRITE_ADDR_TRIG (offset: 0x2c)
  Alias for channel 0 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL2_WRITE_ADDR_TRIG;

/** CH0_AL3_CTRL (offset: 0x30)
  Alias for channel 0 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL3_CTRL;

/** CH0_AL3_WRITE_ADDR (offset: 0x34)
  Alias for channel 0 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL3_WRITE_ADDR;

/** CH0_AL3_TRANS_COUNT (offset: 0x38)
  Alias for channel 0 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL3_TRANS_COUNT;

/** CH0_AL3_READ_ADDR_TRIG (offset: 0x3c)
  Alias for channel 0 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_AL3_READ_ADDR_TRIG;

/** CH1_READ_ADDR (offset: 0x40)
  DMA Channel 1 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_READ_ADDR;

/** CH1_WRITE_ADDR (offset: 0x44)
  DMA Channel 1 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_WRITE_ADDR;

/** CH1_TRANS_COUNT (offset: 0x48)
  DMA Channel 1 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_TRANS_COUNT;

/** CH1_CTRL_TRIG (offset: 0x4c)
  DMA Channel 1 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH1_CTRL_TRIG;

/** CH1_AL1_CTRL (offset: 0x50)
  Alias for channel 1 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL1_CTRL;

/** CH1_AL1_READ_ADDR (offset: 0x54)
  Alias for channel 1 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL1_READ_ADDR;

/** CH1_AL1_WRITE_ADDR (offset: 0x58)
  Alias for channel 1 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL1_WRITE_ADDR;

/** CH1_AL1_TRANS_COUNT_TRIG (offset: 0x5c)
  Alias for channel 1 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL1_TRANS_COUNT_TRIG;

/** CH1_AL2_CTRL (offset: 0x60)
  Alias for channel 1 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL2_CTRL;

/** CH1_AL2_TRANS_COUNT (offset: 0x64)
  Alias for channel 1 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL2_TRANS_COUNT;

/** CH1_AL2_READ_ADDR (offset: 0x68)
  Alias for channel 1 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL2_READ_ADDR;

/** CH1_AL2_WRITE_ADDR_TRIG (offset: 0x6c)
  Alias for channel 1 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL2_WRITE_ADDR_TRIG;

/** CH1_AL3_CTRL (offset: 0x70)
  Alias for channel 1 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL3_CTRL;

/** CH1_AL3_WRITE_ADDR (offset: 0x74)
  Alias for channel 1 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL3_WRITE_ADDR;

/** CH1_AL3_TRANS_COUNT (offset: 0x78)
  Alias for channel 1 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL3_TRANS_COUNT;

/** CH1_AL3_READ_ADDR_TRIG (offset: 0x7c)
  Alias for channel 1 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_AL3_READ_ADDR_TRIG;

/** CH2_READ_ADDR (offset: 0x80)
  DMA Channel 2 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_READ_ADDR;

/** CH2_WRITE_ADDR (offset: 0x84)
  DMA Channel 2 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_WRITE_ADDR;

/** CH2_TRANS_COUNT (offset: 0x88)
  DMA Channel 2 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_TRANS_COUNT;

/** CH2_CTRL_TRIG (offset: 0x8c)
  DMA Channel 2 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH2_CTRL_TRIG;

/** CH2_AL1_CTRL (offset: 0x90)
  Alias for channel 2 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL1_CTRL;

/** CH2_AL1_READ_ADDR (offset: 0x94)
  Alias for channel 2 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL1_READ_ADDR;

/** CH2_AL1_WRITE_ADDR (offset: 0x98)
  Alias for channel 2 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL1_WRITE_ADDR;

/** CH2_AL1_TRANS_COUNT_TRIG (offset: 0x9c)
  Alias for channel 2 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL1_TRANS_COUNT_TRIG;

/** CH2_AL2_CTRL (offset: 0xa0)
  Alias for channel 2 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL2_CTRL;

/** CH2_AL2_TRANS_COUNT (offset: 0xa4)
  Alias for channel 2 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL2_TRANS_COUNT;

/** CH2_AL2_READ_ADDR (offset: 0xa8)
  Alias for channel 2 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL2_READ_ADDR;

/** CH2_AL2_WRITE_ADDR_TRIG (offset: 0xac)
  Alias for channel 2 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL2_WRITE_ADDR_TRIG;

/** CH2_AL3_CTRL (offset: 0xb0)
  Alias for channel 2 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL3_CTRL;

/** CH2_AL3_WRITE_ADDR (offset: 0xb4)
  Alias for channel 2 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL3_WRITE_ADDR;

/** CH2_AL3_TRANS_COUNT (offset: 0xb8)
  Alias for channel 2 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL3_TRANS_COUNT;

/** CH2_AL3_READ_ADDR_TRIG (offset: 0xbc)
  Alias for channel 2 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_AL3_READ_ADDR_TRIG;

/** CH3_READ_ADDR (offset: 0xc0)
  DMA Channel 3 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_READ_ADDR;

/** CH3_WRITE_ADDR (offset: 0xc4)
  DMA Channel 3 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_WRITE_ADDR;

/** CH3_TRANS_COUNT (offset: 0xc8)
  DMA Channel 3 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_TRANS_COUNT;

/** CH3_CTRL_TRIG (offset: 0xcc)
  DMA Channel 3 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH3_CTRL_TRIG;

/** CH3_AL1_CTRL (offset: 0xd0)
  Alias for channel 3 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL1_CTRL;

/** CH3_AL1_READ_ADDR (offset: 0xd4)
  Alias for channel 3 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL1_READ_ADDR;

/** CH3_AL1_WRITE_ADDR (offset: 0xd8)
  Alias for channel 3 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL1_WRITE_ADDR;

/** CH3_AL1_TRANS_COUNT_TRIG (offset: 0xdc)
  Alias for channel 3 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL1_TRANS_COUNT_TRIG;

/** CH3_AL2_CTRL (offset: 0xe0)
  Alias for channel 3 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL2_CTRL;

/** CH3_AL2_TRANS_COUNT (offset: 0xe4)
  Alias for channel 3 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL2_TRANS_COUNT;

/** CH3_AL2_READ_ADDR (offset: 0xe8)
  Alias for channel 3 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL2_READ_ADDR;

/** CH3_AL2_WRITE_ADDR_TRIG (offset: 0xec)
  Alias for channel 3 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL2_WRITE_ADDR_TRIG;

/** CH3_AL3_CTRL (offset: 0xf0)
  Alias for channel 3 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL3_CTRL;

/** CH3_AL3_WRITE_ADDR (offset: 0xf4)
  Alias for channel 3 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL3_WRITE_ADDR;

/** CH3_AL3_TRANS_COUNT (offset: 0xf8)
  Alias for channel 3 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL3_TRANS_COUNT;

/** CH3_AL3_READ_ADDR_TRIG (offset: 0xfc)
  Alias for channel 3 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_AL3_READ_ADDR_TRIG;

/** CH4_READ_ADDR (offset: 0x100)
  DMA Channel 4 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_READ_ADDR;

/** CH4_WRITE_ADDR (offset: 0x104)
  DMA Channel 4 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_WRITE_ADDR;

/** CH4_TRANS_COUNT (offset: 0x108)
  DMA Channel 4 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_TRANS_COUNT;

/** CH4_CTRL_TRIG (offset: 0x10c)
  DMA Channel 4 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH4_CTRL_TRIG;

/** CH4_AL1_CTRL (offset: 0x110)
  Alias for channel 4 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL1_CTRL;

/** CH4_AL1_READ_ADDR (offset: 0x114)
  Alias for channel 4 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL1_READ_ADDR;

/** CH4_AL1_WRITE_ADDR (offset: 0x118)
  Alias for channel 4 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL1_WRITE_ADDR;

/** CH4_AL1_TRANS_COUNT_TRIG (offset: 0x11c)
  Alias for channel 4 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL1_TRANS_COUNT_TRIG;

/** CH4_AL2_CTRL (offset: 0x120)
  Alias for channel 4 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL2_CTRL;

/** CH4_AL2_TRANS_COUNT (offset: 0x124)
  Alias for channel 4 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL2_TRANS_COUNT;

/** CH4_AL2_READ_ADDR (offset: 0x128)
  Alias for channel 4 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL2_READ_ADDR;

/** CH4_AL2_WRITE_ADDR_TRIG (offset: 0x12c)
  Alias for channel 4 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL2_WRITE_ADDR_TRIG;

/** CH4_AL3_CTRL (offset: 0x130)
  Alias for channel 4 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL3_CTRL;

/** CH4_AL3_WRITE_ADDR (offset: 0x134)
  Alias for channel 4 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL3_WRITE_ADDR;

/** CH4_AL3_TRANS_COUNT (offset: 0x138)
  Alias for channel 4 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL3_TRANS_COUNT;

/** CH4_AL3_READ_ADDR_TRIG (offset: 0x13c)
  Alias for channel 4 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_AL3_READ_ADDR_TRIG;

/** CH5_READ_ADDR (offset: 0x140)
  DMA Channel 5 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_READ_ADDR;

/** CH5_WRITE_ADDR (offset: 0x144)
  DMA Channel 5 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_WRITE_ADDR;

/** CH5_TRANS_COUNT (offset: 0x148)
  DMA Channel 5 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_TRANS_COUNT;

/** CH5_CTRL_TRIG (offset: 0x14c)
  DMA Channel 5 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH5_CTRL_TRIG;

/** CH5_AL1_CTRL (offset: 0x150)
  Alias for channel 5 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL1_CTRL;

/** CH5_AL1_READ_ADDR (offset: 0x154)
  Alias for channel 5 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL1_READ_ADDR;

/** CH5_AL1_WRITE_ADDR (offset: 0x158)
  Alias for channel 5 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL1_WRITE_ADDR;

/** CH5_AL1_TRANS_COUNT_TRIG (offset: 0x15c)
  Alias for channel 5 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL1_TRANS_COUNT_TRIG;

/** CH5_AL2_CTRL (offset: 0x160)
  Alias for channel 5 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL2_CTRL;

/** CH5_AL2_TRANS_COUNT (offset: 0x164)
  Alias for channel 5 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL2_TRANS_COUNT;

/** CH5_AL2_READ_ADDR (offset: 0x168)
  Alias for channel 5 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL2_READ_ADDR;

/** CH5_AL2_WRITE_ADDR_TRIG (offset: 0x16c)
  Alias for channel 5 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL2_WRITE_ADDR_TRIG;

/** CH5_AL3_CTRL (offset: 0x170)
  Alias for channel 5 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL3_CTRL;

/** CH5_AL3_WRITE_ADDR (offset: 0x174)
  Alias for channel 5 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL3_WRITE_ADDR;

/** CH5_AL3_TRANS_COUNT (offset: 0x178)
  Alias for channel 5 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL3_TRANS_COUNT;

/** CH5_AL3_READ_ADDR_TRIG (offset: 0x17c)
  Alias for channel 5 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_AL3_READ_ADDR_TRIG;

/** CH6_READ_ADDR (offset: 0x180)
  DMA Channel 6 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_READ_ADDR;

/** CH6_WRITE_ADDR (offset: 0x184)
  DMA Channel 6 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_WRITE_ADDR;

/** CH6_TRANS_COUNT (offset: 0x188)
  DMA Channel 6 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_TRANS_COUNT;

/** CH6_CTRL_TRIG (offset: 0x18c)
  DMA Channel 6 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH6_CTRL_TRIG;

/** CH6_AL1_CTRL (offset: 0x190)
  Alias for channel 6 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL1_CTRL;

/** CH6_AL1_READ_ADDR (offset: 0x194)
  Alias for channel 6 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL1_READ_ADDR;

/** CH6_AL1_WRITE_ADDR (offset: 0x198)
  Alias for channel 6 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL1_WRITE_ADDR;

/** CH6_AL1_TRANS_COUNT_TRIG (offset: 0x19c)
  Alias for channel 6 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL1_TRANS_COUNT_TRIG;

/** CH6_AL2_CTRL (offset: 0x1a0)
  Alias for channel 6 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL2_CTRL;

/** CH6_AL2_TRANS_COUNT (offset: 0x1a4)
  Alias for channel 6 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL2_TRANS_COUNT;

/** CH6_AL2_READ_ADDR (offset: 0x1a8)
  Alias for channel 6 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL2_READ_ADDR;

/** CH6_AL2_WRITE_ADDR_TRIG (offset: 0x1ac)
  Alias for channel 6 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL2_WRITE_ADDR_TRIG;

/** CH6_AL3_CTRL (offset: 0x1b0)
  Alias for channel 6 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL3_CTRL;

/** CH6_AL3_WRITE_ADDR (offset: 0x1b4)
  Alias for channel 6 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL3_WRITE_ADDR;

/** CH6_AL3_TRANS_COUNT (offset: 0x1b8)
  Alias for channel 6 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL3_TRANS_COUNT;

/** CH6_AL3_READ_ADDR_TRIG (offset: 0x1bc)
  Alias for channel 6 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_AL3_READ_ADDR_TRIG;

/** CH7_READ_ADDR (offset: 0x1c0)
  DMA Channel 7 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_READ_ADDR;

/** CH7_WRITE_ADDR (offset: 0x1c4)
  DMA Channel 7 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_WRITE_ADDR;

/** CH7_TRANS_COUNT (offset: 0x1c8)
  DMA Channel 7 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_TRANS_COUNT;

/** CH7_CTRL_TRIG (offset: 0x1cc)
  DMA Channel 7 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH7_CTRL_TRIG;

/** CH7_AL1_CTRL (offset: 0x1d0)
  Alias for channel 7 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL1_CTRL;

/** CH7_AL1_READ_ADDR (offset: 0x1d4)
  Alias for channel 7 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL1_READ_ADDR;

/** CH7_AL1_WRITE_ADDR (offset: 0x1d8)
  Alias for channel 7 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL1_WRITE_ADDR;

/** CH7_AL1_TRANS_COUNT_TRIG (offset: 0x1dc)
  Alias for channel 7 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL1_TRANS_COUNT_TRIG;

/** CH7_AL2_CTRL (offset: 0x1e0)
  Alias for channel 7 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL2_CTRL;

/** CH7_AL2_TRANS_COUNT (offset: 0x1e4)
  Alias for channel 7 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL2_TRANS_COUNT;

/** CH7_AL2_READ_ADDR (offset: 0x1e8)
  Alias for channel 7 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL2_READ_ADDR;

/** CH7_AL2_WRITE_ADDR_TRIG (offset: 0x1ec)
  Alias for channel 7 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL2_WRITE_ADDR_TRIG;

/** CH7_AL3_CTRL (offset: 0x1f0)
  Alias for channel 7 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL3_CTRL;

/** CH7_AL3_WRITE_ADDR (offset: 0x1f4)
  Alias for channel 7 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL3_WRITE_ADDR;

/** CH7_AL3_TRANS_COUNT (offset: 0x1f8)
  Alias for channel 7 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL3_TRANS_COUNT;

/** CH7_AL3_READ_ADDR_TRIG (offset: 0x1fc)
  Alias for channel 7 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_AL3_READ_ADDR_TRIG;

/** CH8_READ_ADDR (offset: 0x200)
  DMA Channel 8 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_READ_ADDR;

/** CH8_WRITE_ADDR (offset: 0x204)
  DMA Channel 8 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_WRITE_ADDR;

/** CH8_TRANS_COUNT (offset: 0x208)
  DMA Channel 8 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_TRANS_COUNT;

/** CH8_CTRL_TRIG (offset: 0x20c)
  DMA Channel 8 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH8_CTRL_TRIG;

/** CH8_AL1_CTRL (offset: 0x210)
  Alias for channel 8 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL1_CTRL;

/** CH8_AL1_READ_ADDR (offset: 0x214)
  Alias for channel 8 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL1_READ_ADDR;

/** CH8_AL1_WRITE_ADDR (offset: 0x218)
  Alias for channel 8 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL1_WRITE_ADDR;

/** CH8_AL1_TRANS_COUNT_TRIG (offset: 0x21c)
  Alias for channel 8 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL1_TRANS_COUNT_TRIG;

/** CH8_AL2_CTRL (offset: 0x220)
  Alias for channel 8 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL2_CTRL;

/** CH8_AL2_TRANS_COUNT (offset: 0x224)
  Alias for channel 8 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL2_TRANS_COUNT;

/** CH8_AL2_READ_ADDR (offset: 0x228)
  Alias for channel 8 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL2_READ_ADDR;

/** CH8_AL2_WRITE_ADDR_TRIG (offset: 0x22c)
  Alias for channel 8 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL2_WRITE_ADDR_TRIG;

/** CH8_AL3_CTRL (offset: 0x230)
  Alias for channel 8 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL3_CTRL;

/** CH8_AL3_WRITE_ADDR (offset: 0x234)
  Alias for channel 8 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL3_WRITE_ADDR;

/** CH8_AL3_TRANS_COUNT (offset: 0x238)
  Alias for channel 8 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL3_TRANS_COUNT;

/** CH8_AL3_READ_ADDR_TRIG (offset: 0x23c)
  Alias for channel 8 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_AL3_READ_ADDR_TRIG;

/** CH9_READ_ADDR (offset: 0x240)
  DMA Channel 9 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_READ_ADDR;

/** CH9_WRITE_ADDR (offset: 0x244)
  DMA Channel 9 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_WRITE_ADDR;

/** CH9_TRANS_COUNT (offset: 0x248)
  DMA Channel 9 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_TRANS_COUNT;

/** CH9_CTRL_TRIG (offset: 0x24c)
  DMA Channel 9 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH9_CTRL_TRIG;

/** CH9_AL1_CTRL (offset: 0x250)
  Alias for channel 9 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL1_CTRL;

/** CH9_AL1_READ_ADDR (offset: 0x254)
  Alias for channel 9 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL1_READ_ADDR;

/** CH9_AL1_WRITE_ADDR (offset: 0x258)
  Alias for channel 9 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL1_WRITE_ADDR;

/** CH9_AL1_TRANS_COUNT_TRIG (offset: 0x25c)
  Alias for channel 9 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL1_TRANS_COUNT_TRIG;

/** CH9_AL2_CTRL (offset: 0x260)
  Alias for channel 9 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL2_CTRL;

/** CH9_AL2_TRANS_COUNT (offset: 0x264)
  Alias for channel 9 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL2_TRANS_COUNT;

/** CH9_AL2_READ_ADDR (offset: 0x268)
  Alias for channel 9 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL2_READ_ADDR;

/** CH9_AL2_WRITE_ADDR_TRIG (offset: 0x26c)
  Alias for channel 9 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL2_WRITE_ADDR_TRIG;

/** CH9_AL3_CTRL (offset: 0x270)
  Alias for channel 9 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL3_CTRL;

/** CH9_AL3_WRITE_ADDR (offset: 0x274)
  Alias for channel 9 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL3_WRITE_ADDR;

/** CH9_AL3_TRANS_COUNT (offset: 0x278)
  Alias for channel 9 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL3_TRANS_COUNT;

/** CH9_AL3_READ_ADDR_TRIG (offset: 0x27c)
  Alias for channel 9 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_AL3_READ_ADDR_TRIG;

/** CH10_READ_ADDR (offset: 0x280)
  DMA Channel 10 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_READ_ADDR;

/** CH10_WRITE_ADDR (offset: 0x284)
  DMA Channel 10 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_WRITE_ADDR;

/** CH10_TRANS_COUNT (offset: 0x288)
  DMA Channel 10 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_TRANS_COUNT;

/** CH10_CTRL_TRIG (offset: 0x28c)
  DMA Channel 10 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH10_CTRL_TRIG;

/** CH10_AL1_CTRL (offset: 0x290)
  Alias for channel 10 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL1_CTRL;

/** CH10_AL1_READ_ADDR (offset: 0x294)
  Alias for channel 10 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL1_READ_ADDR;

/** CH10_AL1_WRITE_ADDR (offset: 0x298)
  Alias for channel 10 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL1_WRITE_ADDR;

/** CH10_AL1_TRANS_COUNT_TRIG (offset: 0x29c)
  Alias for channel 10 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL1_TRANS_COUNT_TRIG;

/** CH10_AL2_CTRL (offset: 0x2a0)
  Alias for channel 10 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL2_CTRL;

/** CH10_AL2_TRANS_COUNT (offset: 0x2a4)
  Alias for channel 10 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL2_TRANS_COUNT;

/** CH10_AL2_READ_ADDR (offset: 0x2a8)
  Alias for channel 10 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL2_READ_ADDR;

/** CH10_AL2_WRITE_ADDR_TRIG (offset: 0x2ac)
  Alias for channel 10 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL2_WRITE_ADDR_TRIG;

/** CH10_AL3_CTRL (offset: 0x2b0)
  Alias for channel 10 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL3_CTRL;

/** CH10_AL3_WRITE_ADDR (offset: 0x2b4)
  Alias for channel 10 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL3_WRITE_ADDR;

/** CH10_AL3_TRANS_COUNT (offset: 0x2b8)
  Alias for channel 10 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL3_TRANS_COUNT;

/** CH10_AL3_READ_ADDR_TRIG (offset: 0x2bc)
  Alias for channel 10 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_AL3_READ_ADDR_TRIG;

/** CH11_READ_ADDR (offset: 0x2c0)
  DMA Channel 11 Read Address pointer

 This register updates automatically each time a read completes. The current value is the next address to be read by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_READ_ADDR;

/** CH11_WRITE_ADDR (offset: 0x2c4)
  DMA Channel 11 Write Address pointer

 This register updates automatically each time a write completes. The current value is the next address to be written by this channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_WRITE_ADDR;

/** CH11_TRANS_COUNT (offset: 0x2c8)
  DMA Channel 11 Transfer Count

 Program the number of bus transfers a channel will perform before halting. Note that, if transfers are larger than one byte in size, this is not equal to the number of bytes transferred (see CTRL_DATA_SIZE).


 When the channel is active, reading this register shows the number of transfers remaining, updating automatically each time a write transfer completes.


 Writing this register sets the RELOAD value for the transfer counter. Each time this channel is triggered, the RELOAD value is copied into the live transfer counter. The channel can be started multiple times, and will perform the same number of transfers each time, as programmed by most recent write.


 The RELOAD value can be observed at CHx_DBG_TCR. If TRANS_COUNT is used as a trigger, the written value is used immediately as the length of the new transfer sequence, as well as being written to RELOAD.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_TRANS_COUNT;

/** CH11_CTRL_TRIG (offset: 0x2cc)
  DMA Channel 11 Control and Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: AHB_ERROR
  offset: 31, size: 1, access: read-only
  Logical OR of the READ_ERROR and WRITE_ERROR flags. The channel halts when it encounters any bus error, and always raises its channel IRQ flag.
  Field: READ_ERROR
  offset: 30, size: 1, access: read-write
  If 1, the channel received a read bus error. Write one to clear.

 READ_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 3 transfers later)
  Field: WRITE_ERROR
  offset: 29, size: 1, access: read-write
  If 1, the channel received a write bus error. Write one to clear.

 WRITE_ADDR shows the approximate address where the bus error was encountered (will not to be earlier, or more than 5 transfers later)
  Field: BUSY
  offset: 24, size: 1, access: read-only
  This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. Clearing EN while BUSY is high pauses the channel, and BUSY will stay high while paused.


 To terminate a sequence early (and clear the BUSY flag), see CHAN_ABORT.
  Field: SNIFF_EN
  offset: 23, size: 1, access: read-write
  If 1, this channel&apos;s data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. This only applies if the sniff hardware is enabled, and has this channel selected.


 This allows checksum to be enabled or disabled on a per-control- block basis.
  Field: BSWAP
  offset: 22, size: 1, access: read-write
  Apply byte-swap transformation to DMA data.

 For byte data, this has no effect. For halfword data, the two bytes of each halfword are swapped. For word data, the four bytes of each word are swapped to reverse order.
  Field: IRQ_QUIET
  offset: 21, size: 1, access: read-write
  In QUIET mode, the channel does not generate IRQs at the end of every transfer block. Instead, an IRQ is raised when NULL is written to a trigger register, indicating the end of a control block chain.


 This reduces the number of interrupts to be serviced by the CPU when transferring a DMA chain of many small control blocks.
  Field: TREQ_SEL
  offset: 15, size: 6, access: read-write
  Select a Transfer Request signal.

 The channel uses the transfer request signal to pace its data transfer rate. Sources for TREQ signals are internal (TIMERS) or external (DREQ, a Data Request from the system).

 0x0 to 0x3a -&gt; select DREQ n as TREQ
  Enum:
  Value: 0x3b - TIMER0 : Select Timer 0 as TREQ
  Value: 0x3c - TIMER1 : Select Timer 1 as TREQ
  Value: 0x3d - TIMER2 : Select Timer 2 as TREQ (Optional)
  Value: 0x3e - TIMER3 : Select Timer 3 as TREQ (Optional)
  Value: 0x3f - PERMANENT : Permanent request, for unpaced transfers.
  Field: CHAIN_TO
  offset: 11, size: 4, access: read-write
  When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_.
  Field: RING_SEL
  offset: 10, size: 1, access: read-write
  Select whether RING_SIZE applies to read or write addresses.

 If 0, read addresses are wrapped on a (1 &lt;&lt; RING_SIZE) boundary. If 1, write addresses are wrapped.
  Field: RING_SIZE
  offset: 6, size: 4, access: read-write
  Size of address wrap region. If 0, don&apos;t wrap. For values n &gt; 0, only the lower n bits of the address will change. This wraps the address on a (1 &lt;&lt; n) byte boundary, facilitating access to naturally-aligned ring buffers.


 Ring sizes between 2 and 32768 bytes are possible. This can apply to either read or write addresses, based on value of RING_SEL.
  Enum:
  Value: 0 - RING_NONE
  Field: INCR_WRITE
  offset: 5, size: 1, access: read-write
  If 1, the write address increments with each transfer. If 0, each write is directed to the same, initial address.


 Generally this should be disabled for memory-to-peripheral transfers.
  Field: INCR_READ
  offset: 4, size: 1, access: read-write
  If 1, the read address increments with each transfer. If 0, each read is directed to the same, initial address.


 Generally this should be disabled for peripheral-to-memory transfers.
  Field: DATA_SIZE
  offset: 2, size: 2, access: read-write
  Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer.
  Enum:
  Value: 0 - SIZE_BYTE
  Value: 1 - SIZE_HALFWORD
  Value: 2 - SIZE_WORD
  Field: HIGH_PRIORITY
  offset: 1, size: 1, access: read-write
  HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels.


 This only affects the order in which the DMA schedules channels. The DMA&apos;s bus priority is not changed. If the DMA is not saturated then a low priority channel will see no loss of throughput.
  Field: EN
  offset: 0, size: 1, access: read-write
  DMA Channel Enable.

 When 1, the channel will respond to triggering events, which will cause it to become BUSY and start transferring data. When 0, the channel will ignore triggers, stop issuing transfers, and pause the current transfer sequence (i.e. BUSY will remain high if already high)
*/
volatile uint32_t CH11_CTRL_TRIG;

/** CH11_AL1_CTRL (offset: 0x2d0)
  Alias for channel 11 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL1_CTRL;

/** CH11_AL1_READ_ADDR (offset: 0x2d4)
  Alias for channel 11 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL1_READ_ADDR;

/** CH11_AL1_WRITE_ADDR (offset: 0x2d8)
  Alias for channel 11 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL1_WRITE_ADDR;

/** CH11_AL1_TRANS_COUNT_TRIG (offset: 0x2dc)
  Alias for channel 11 TRANS_COUNT register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL1_TRANS_COUNT_TRIG;

/** CH11_AL2_CTRL (offset: 0x2e0)
  Alias for channel 11 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL2_CTRL;

/** CH11_AL2_TRANS_COUNT (offset: 0x2e4)
  Alias for channel 11 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL2_TRANS_COUNT;

/** CH11_AL2_READ_ADDR (offset: 0x2e8)
  Alias for channel 11 READ_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL2_READ_ADDR;

/** CH11_AL2_WRITE_ADDR_TRIG (offset: 0x2ec)
  Alias for channel 11 WRITE_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL2_WRITE_ADDR_TRIG;

/** CH11_AL3_CTRL (offset: 0x2f0)
  Alias for channel 11 CTRL register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL3_CTRL;

/** CH11_AL3_WRITE_ADDR (offset: 0x2f4)
  Alias for channel 11 WRITE_ADDR register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL3_WRITE_ADDR;

/** CH11_AL3_TRANS_COUNT (offset: 0x2f8)
  Alias for channel 11 TRANS_COUNT register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL3_TRANS_COUNT;

/** CH11_AL3_READ_ADDR_TRIG (offset: 0x2fc)
  Alias for channel 11 READ_ADDR register

 This is a trigger register (0xc). Writing a nonzero value will

 reload the channel counter and start the channel.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_AL3_READ_ADDR_TRIG;
volatile uint32_t reserved0[64];

/** INTR (offset: 0x400)
  Interrupt Status (raw)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTR
  offset: 0, size: 16, access: read-only
  Raw interrupt status for DMA Channels 0..15. Bit n corresponds to channel n. Ignores any masking or forcing. Channel interrupts can be cleared by writing a bit mask to INTR, INTS0 or INTS1.


 Channel interrupts can be routed to either of two system-level IRQs based on INTE0 and INTE1.


 This can be used vector different channel interrupts to different ISRs: this might be done to allow NVIC IRQ preemption for more time-critical channels, or to spread IRQ load across different cores.


 It is also valid to ignore this behaviour and just use INTE0/INTS0/IRQ 0.
*/
volatile uint32_t INTR;

/** INTE0 (offset: 0x404)
  Interrupt Enables for IRQ 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTE0
  offset: 0, size: 16, access: read-write
  Set bit n to pass interrupts from channel n to DMA IRQ 0.
*/
volatile uint32_t INTE0;

/** INTF0 (offset: 0x408)
  Force Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTF0
  offset: 0, size: 16, access: read-write
  Write 1s to force the corresponding bits in INTE0. The interrupt remains asserted until INTF0 is cleared.
*/
volatile uint32_t INTF0;

/** INTS0 (offset: 0x40c)
  Interrupt Status for IRQ 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTS0
  offset: 0, size: 16, access: read-write
  Indicates active channel interrupt requests which are currently causing IRQ 0 to be asserted.

 Channel interrupts can be cleared by writing a bit mask here.
*/
volatile uint32_t INTS0;
volatile uint32_t reserved1;

/** INTE1 (offset: 0x414)
  Interrupt Enables for IRQ 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTE1
  offset: 0, size: 16, access: read-write
  Set bit n to pass interrupts from channel n to DMA IRQ 1.
*/
volatile uint32_t INTE1;

/** INTF1 (offset: 0x418)
  Force Interrupts for IRQ 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTF1
  offset: 0, size: 16, access: read-write
  Write 1s to force the corresponding bits in INTE0. The interrupt remains asserted until INTF0 is cleared.
*/
volatile uint32_t INTF1;

/** INTS1 (offset: 0x41c)
  Interrupt Status (masked) for IRQ 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTS1
  offset: 0, size: 16, access: read-write
  Indicates active channel interrupt requests which are currently causing IRQ 1 to be asserted.

 Channel interrupts can be cleared by writing a bit mask here.
*/
volatile uint32_t INTS1;

/** TIMER0 (offset: 0x420)
  Pacing (X/Y) Fractional Timer

 The pacing timer produces TREQ assertions at a rate set by ((X/Y) * sys_clk). This equation is evaluated every sys_clk cycles and therefore can only generate TREQs at a rate of 1 per sys_clk (i.e. permanent TREQ) or less.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: X
  offset: 16, size: 16, access: read-write
  Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer.
  Field: Y
  offset: 0, size: 16, access: read-write
  Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer.
*/
volatile uint32_t TIMER0;

/** TIMER1 (offset: 0x424)
  Pacing (X/Y) Fractional Timer

 The pacing timer produces TREQ assertions at a rate set by ((X/Y) * sys_clk). This equation is evaluated every sys_clk cycles and therefore can only generate TREQs at a rate of 1 per sys_clk (i.e. permanent TREQ) or less.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: X
  offset: 16, size: 16, access: read-write
  Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer.
  Field: Y
  offset: 0, size: 16, access: read-write
  Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer.
*/
volatile uint32_t TIMER1;

/** TIMER2 (offset: 0x428)
  Pacing (X/Y) Fractional Timer

 The pacing timer produces TREQ assertions at a rate set by ((X/Y) * sys_clk). This equation is evaluated every sys_clk cycles and therefore can only generate TREQs at a rate of 1 per sys_clk (i.e. permanent TREQ) or less.
  reset value : 0x0
  reset mask : 0x0
  Field: X
  offset: 16, size: 16, access: read-write
  Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer.
  Field: Y
  offset: 0, size: 16, access: read-write
  Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer.
*/
volatile uint32_t TIMER2;

/** TIMER3 (offset: 0x42c)
  Pacing (X/Y) Fractional Timer

 The pacing timer produces TREQ assertions at a rate set by ((X/Y) * sys_clk). This equation is evaluated every sys_clk cycles and therefore can only generate TREQs at a rate of 1 per sys_clk (i.e. permanent TREQ) or less.
  reset value : 0x0
  reset mask : 0x0
  Field: X
  offset: 16, size: 16, access: read-write
  Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer.
  Field: Y
  offset: 0, size: 16, access: read-write
  Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer.
*/
volatile uint32_t TIMER3;

/** MULTI_CHAN_TRIGGER (offset: 0x430)
  Trigger one or more channels simultaneously
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MULTI_CHAN_TRIGGER
  offset: 0, size: 16, access: read-write
  Each bit in this register corresponds to a DMA channel. Writing a 1 to the relevant bit is the same as writing to that channel&apos;s trigger register the channel will start if it is currently enabled and not already busy.
*/
volatile uint32_t MULTI_CHAN_TRIGGER;

/** SNIFF_CTRL (offset: 0x434)
  Sniffer Control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OUT_INV
  offset: 11, size: 1, access: read-write
  If set, the result appears inverted (bitwise complement) when read. This does not affect the way the checksum is calculated the result is transformed on-the-fly between the result register and the bus.
  Field: OUT_REV
  offset: 10, size: 1, access: read-write
  If set, the result appears bit-reversed when read. This does not affect the way the checksum is calculated the result is transformed on-the-fly between the result register and the bus.
  Field: BSWAP
  offset: 9, size: 1, access: read-write
  Locally perform a byte reverse on the sniffed data, before feeding into checksum.


 Note that the sniff hardware is downstream of the DMA channel byteswap performed in the read master: if channel CTRL_BSWAP and SNIFF_CTRL_BSWAP are both enabled, their effects cancel from the sniffer&apos;s point of view.
  Field: CALC
  offset: 5, size: 4, access: read-write
  Enum:
  Value: 0 - CRC32 : Calculate a CRC-32 (IEEE802.3 polynomial)
  Value: 1 - CRC32R : Calculate a CRC-32 (IEEE802.3 polynomial) with bit reversed data
  Value: 2 - CRC16 : Calculate a CRC-16-CCITT
  Value: 3 - CRC16R : Calculate a CRC-16-CCITT with bit reversed data
  Value: 0xe - EVEN : XOR reduction over all data. == 1 if the total 1 population count is odd.
  Value: 0xf - SUM : Calculate a simple 32-bit checksum (addition with a 32 bit accumulator)
  Field: DMACH
  offset: 1, size: 4, access: read-write
  DMA channel for Sniffer to observe
  Field: EN
  offset: 0, size: 1, access: read-write
  Enable sniffer
*/
volatile uint32_t SNIFF_CTRL;

/** SNIFF_DATA (offset: 0x438)
  Data accumulator for sniff hardware

 Write an initial seed value here before starting a DMA transfer on the channel indicated by SNIFF_CTRL_DMACH. The hardware will update this register each time it observes a read from the indicated channel. Once the channel completes, the final result can be read from this register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SNIFF_DATA;
volatile uint32_t reserved2;

/** FIFO_LEVELS (offset: 0x440)
  Debug RAF, WAF, TDF levels
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RAF_LVL
  offset: 16, size: 8, access: read-only
  Current Read-Address-FIFO fill level
  Field: WAF_LVL
  offset: 8, size: 8, access: read-only
  Current Write-Address-FIFO fill level
  Field: TDF_LVL
  offset: 0, size: 8, access: read-only
  Current Transfer-Data-FIFO fill level
*/
volatile uint32_t FIFO_LEVELS;

/** CHAN_ABORT (offset: 0x444)
  Abort an in-progress transfer sequence on one or more channels
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CHAN_ABORT
  offset: 0, size: 16, access: read-write
  Each bit corresponds to a channel. Writing a 1 aborts whatever transfer sequence is in progress on that channel. The bit will remain high until any in-flight transfers have been flushed through the address and data FIFOs.


 After writing, this register must be polled until it returns all-zero. Until this point, it is unsafe to restart the channel.
*/
volatile uint32_t CHAN_ABORT;

/** N_CHANNELS (offset: 0x448)
  The number of channels this DMA instance is equipped with. This DMA supports up to 16 hardware channels, but can be configured with as few as one, to minimise silicon area.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: N_CHANNELS
  offset: 0, size: 5, access: read-only
*/
volatile uint32_t N_CHANNELS;
volatile uint32_t reserved3[237];

/** CH0_DBG_CTDREQ (offset: 0x800)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH0_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH0_DBG_CTDREQ;

/** CH0_DBG_TCR (offset: 0x804)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH0_DBG_TCR;
volatile uint32_t reserved4[14];

/** CH1_DBG_CTDREQ (offset: 0x840)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH1_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH1_DBG_CTDREQ;

/** CH1_DBG_TCR (offset: 0x844)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH1_DBG_TCR;
volatile uint32_t reserved5[14];

/** CH2_DBG_CTDREQ (offset: 0x880)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH2_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH2_DBG_CTDREQ;

/** CH2_DBG_TCR (offset: 0x884)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH2_DBG_TCR;
volatile uint32_t reserved6[14];

/** CH3_DBG_CTDREQ (offset: 0x8c0)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH3_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH3_DBG_CTDREQ;

/** CH3_DBG_TCR (offset: 0x8c4)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH3_DBG_TCR;
volatile uint32_t reserved7[14];

/** CH4_DBG_CTDREQ (offset: 0x900)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH4_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH4_DBG_CTDREQ;

/** CH4_DBG_TCR (offset: 0x904)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH4_DBG_TCR;
volatile uint32_t reserved8[14];

/** CH5_DBG_CTDREQ (offset: 0x940)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH5_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH5_DBG_CTDREQ;

/** CH5_DBG_TCR (offset: 0x944)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH5_DBG_TCR;
volatile uint32_t reserved9[14];

/** CH6_DBG_CTDREQ (offset: 0x980)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH6_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH6_DBG_CTDREQ;

/** CH6_DBG_TCR (offset: 0x984)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH6_DBG_TCR;
volatile uint32_t reserved10[14];

/** CH7_DBG_CTDREQ (offset: 0x9c0)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH7_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH7_DBG_CTDREQ;

/** CH7_DBG_TCR (offset: 0x9c4)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH7_DBG_TCR;
volatile uint32_t reserved11[14];

/** CH8_DBG_CTDREQ (offset: 0xa00)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH8_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH8_DBG_CTDREQ;

/** CH8_DBG_TCR (offset: 0xa04)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH8_DBG_TCR;
volatile uint32_t reserved12[14];

/** CH9_DBG_CTDREQ (offset: 0xa40)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH9_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH9_DBG_CTDREQ;

/** CH9_DBG_TCR (offset: 0xa44)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH9_DBG_TCR;
volatile uint32_t reserved13[14];

/** CH10_DBG_CTDREQ (offset: 0xa80)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH10_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH10_DBG_CTDREQ;

/** CH10_DBG_TCR (offset: 0xa84)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH10_DBG_TCR;
volatile uint32_t reserved14[14];

/** CH11_DBG_CTDREQ (offset: 0xac0)
  Read: get channel DREQ counter (i.e. how many accesses the DMA expects it can perform on the peripheral without overflow/underflow. Write any value: clears the counter, and cause channel to re-initiate DREQ handshake.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CH11_DBG_CTDREQ
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t CH11_DBG_CTDREQ;

/** CH11_DBG_TCR (offset: 0xac4)
  Read to get channel TRANS_COUNT reload value, i.e. the length of the next transfer
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CH11_DBG_TCR;
} DMA_type;

#define DMA ((DMA_type *) 0x50000000)

#endif // HW_DMA_H
