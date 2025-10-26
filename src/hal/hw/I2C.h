/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_I2C_H
#define HW_I2C_H
/** DW_apb_i2c address block


 List of configuration constants for the Synopsys I2C hardware (you may see references to these in I2C register header these are *fixed* values, set at hardware design time):


 IC_ULTRA_FAST_MODE ................ 0x0

 IC_UFM_TBUF_CNT_DEFAULT ........... 0x8

 IC_UFM_SCL_LOW_COUNT .............. 0x0008

 IC_UFM_SCL_HIGH_COUNT ............. 0x0006

 IC_TX_TL .......................... 0x0

 IC_TX_CMD_BLOCK ................... 0x1

 IC_HAS_DMA ........................ 0x1

 IC_HAS_ASYNC_FIFO ................. 0x0

 IC_SMBUS_ARP ...................... 0x0

 IC_FIRST_DATA_BYTE_STATUS ......... 0x1

 IC_INTR_IO ........................ 0x1

 IC_MASTER_MODE .................... 0x1

 IC_DEFAULT_ACK_GENERAL_CALL ....... 0x1

 IC_INTR_POL ....................... 0x1

 IC_OPTIONAL_SAR ................... 0x0

 IC_DEFAULT_TAR_SLAVE_ADDR ......... 0x055

 IC_DEFAULT_SLAVE_ADDR ............. 0x055

 IC_DEFAULT_HS_SPKLEN .............. 0x1

 IC_FS_SCL_HIGH_COUNT .............. 0x0006

 IC_HS_SCL_LOW_COUNT ............... 0x0008

 IC_DEVICE_ID_VALUE ................ 0x0

 IC_10BITADDR_MASTER ............... 0x0

 IC_CLK_FREQ_OPTIMIZATION .......... 0x0

 IC_DEFAULT_FS_SPKLEN .............. 0x7

 IC_ADD_ENCODED_PARAMS ............. 0x0

 IC_DEFAULT_SDA_HOLD ............... 0x000001

 IC_DEFAULT_SDA_SETUP .............. 0x64

 IC_AVOID_RX_FIFO_FLUSH_ON_TX_ABRT . 0x0

 IC_CLOCK_PERIOD ................... 100

 IC_EMPTYFIFO_HOLD_MASTER_EN ....... 1

 IC_RESTART_EN ..................... 0x1

 IC_TX_CMD_BLOCK_DEFAULT ........... 0x0

 IC_BUS_CLEAR_FEATURE .............. 0x0

 IC_CAP_LOADING .................... 100

 IC_FS_SCL_LOW_COUNT ............... 0x000d

 APB_DATA_WIDTH .................... 32

 IC_SDA_STUCK_TIMEOUT_DEFAULT ...... 0xffffffff

 IC_SLV_DATA_NACK_ONLY ............. 0x1

 IC_10BITADDR_SLAVE ................ 0x0

 IC_CLK_TYPE ....................... 0x0

 IC_SMBUS_UDID_MSB ................. 0x0

 IC_SMBUS_SUSPEND_ALERT ............ 0x0

 IC_HS_SCL_HIGH_COUNT .............. 0x0006

 IC_SLV_RESTART_DET_EN ............. 0x1

 IC_SMBUS .......................... 0x0

 IC_OPTIONAL_SAR_DEFAULT ........... 0x0

 IC_PERSISTANT_SLV_ADDR_DEFAULT .... 0x0

 IC_USE_COUNTS ..................... 0x0

 IC_RX_BUFFER_DEPTH ................ 16

 IC_SCL_STUCK_TIMEOUT_DEFAULT ...... 0xffffffff

 IC_RX_FULL_HLD_BUS_EN ............. 0x1

 IC_SLAVE_DISABLE .................. 0x1

 IC_RX_TL .......................... 0x0

 IC_DEVICE_ID ...................... 0x0

 IC_HC_COUNT_VALUES ................ 0x0

 I2C_DYNAMIC_TAR_UPDATE ............ 0

 IC_SMBUS_CLK_LOW_MEXT_DEFAULT ..... 0xffffffff

 IC_SMBUS_CLK_LOW_SEXT_DEFAULT ..... 0xffffffff

 IC_HS_MASTER_CODE ................. 0x1

 IC_SMBUS_RST_IDLE_CNT_DEFAULT ..... 0xffff

 IC_SMBUS_UDID_LSB_DEFAULT ......... 0xffffffff

 IC_SS_SCL_HIGH_COUNT .............. 0x0028

 IC_SS_SCL_LOW_COUNT ............... 0x002f

 IC_MAX_SPEED_MODE ................. 0x2

 IC_STAT_FOR_CLK_STRETCH ........... 0x0

 IC_STOP_DET_IF_MASTER_ACTIVE ...... 0x0

 IC_DEFAULT_UFM_SPKLEN ............. 0x1

 IC_TX_BUFFER_DEPTH ................ 16 */
/** Interrupt : I2C0_IRQ (Vector: 23)  */
/** Interrupt : I2C1_IRQ (Vector: 24)  */
/** Memory Block starting at 0x40044000 + 0x0 is 0x100 bytes in size. It is used for registers. Protection: n */
/** Memory Block starting at 0x40048000 + 0x0 is 0x100 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_OFFSET        10u
#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_MASK          0x400u

#define I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL_OFFSET            9u
#define I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL_MASK              0x200u
#define I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL_DISABLED          0u
#define I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL_ENABLED           1u

#define I2C_IC_CON_TX_EMPTY_CTRL_OFFSET                    8u
#define I2C_IC_CON_TX_EMPTY_CTRL_MASK                      0x100u
#define I2C_IC_CON_TX_EMPTY_CTRL_DISABLED                  0u
#define I2C_IC_CON_TX_EMPTY_CTRL_ENABLED                   1u

#define I2C_IC_CON_STOP_DET_IFADDRESSED_OFFSET             7u
#define I2C_IC_CON_STOP_DET_IFADDRESSED_MASK               0x80u
#define I2C_IC_CON_STOP_DET_IFADDRESSED_DISABLED           0u
#define I2C_IC_CON_STOP_DET_IFADDRESSED_ENABLED            1u

#define I2C_IC_CON_IC_SLAVE_DISABLE_OFFSET                 6u
#define I2C_IC_CON_IC_SLAVE_DISABLE_MASK                   0x40u
#define I2C_IC_CON_IC_SLAVE_DISABLE_SLAVE_ENABLED          0u
#define I2C_IC_CON_IC_SLAVE_DISABLE_SLAVE_DISABLED         1u

#define I2C_IC_CON_IC_RESTART_EN_OFFSET                    5u
#define I2C_IC_CON_IC_RESTART_EN_MASK                      0x20u
#define I2C_IC_CON_IC_RESTART_EN_DISABLED                  0u
#define I2C_IC_CON_IC_RESTART_EN_ENABLED                   1u

#define I2C_IC_CON_IC_10BITADDR_MASTER_OFFSET              4u
#define I2C_IC_CON_IC_10BITADDR_MASTER_MASK                0x10u
#define I2C_IC_CON_IC_10BITADDR_MASTER_ADDR_7BITS          0u
#define I2C_IC_CON_IC_10BITADDR_MASTER_ADDR_10BITS         1u

#define I2C_IC_CON_IC_10BITADDR_SLAVE_OFFSET               3u
#define I2C_IC_CON_IC_10BITADDR_SLAVE_MASK                 8u
#define I2C_IC_CON_IC_10BITADDR_SLAVE_ADDR_7BITS           0u
#define I2C_IC_CON_IC_10BITADDR_SLAVE_ADDR_10BITS          1u

#define I2C_IC_CON_SPEED_OFFSET                            1u
#define I2C_IC_CON_SPEED_MASK                              6u
#define I2C_IC_CON_SPEED_STANDARD                          1u
#define I2C_IC_CON_SPEED_FAST                              2u
#define I2C_IC_CON_SPEED_HIGH                              3u

#define I2C_IC_CON_MASTER_MODE_OFFSET                      0u
#define I2C_IC_CON_MASTER_MODE_MASK                        1u
#define I2C_IC_CON_MASTER_MODE_DISABLED                    0u
#define I2C_IC_CON_MASTER_MODE_ENABLED                     1u

#define I2C_IC_TAR_SPECIAL_OFFSET                          11u
#define I2C_IC_TAR_SPECIAL_MASK                            0x800u
#define I2C_IC_TAR_SPECIAL_DISABLED                        0u
#define I2C_IC_TAR_SPECIAL_ENABLED                         1u

#define I2C_IC_TAR_GC_OR_START_OFFSET                      10u
#define I2C_IC_TAR_GC_OR_START_MASK                        0x400u
#define I2C_IC_TAR_GC_OR_START_GENERAL_CALL                0u
#define I2C_IC_TAR_GC_OR_START_START_BYTE                  1u

#define I2C_IC_TAR_IC_TAR_OFFSET                           0u
#define I2C_IC_TAR_IC_TAR_MASK                             0x3ffu

#define I2C_IC_SAR_IC_SAR_OFFSET                           0u
#define I2C_IC_SAR_IC_SAR_MASK                             0x3ffu

#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_OFFSET             11u
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_MASK               0x800u
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_INACTIVE           0u
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_ACTIVE             1u

#define I2C_IC_DATA_CMD_RESTART_OFFSET                     10u
#define I2C_IC_DATA_CMD_RESTART_MASK                       0x400u
#define I2C_IC_DATA_CMD_RESTART_DISABLE                    0u
#define I2C_IC_DATA_CMD_RESTART_ENABLE                     1u

#define I2C_IC_DATA_CMD_STOP_OFFSET                        9u
#define I2C_IC_DATA_CMD_STOP_MASK                          0x200u
#define I2C_IC_DATA_CMD_STOP_DISABLE                       0u
#define I2C_IC_DATA_CMD_STOP_ENABLE                        1u

#define I2C_IC_DATA_CMD_CMD_OFFSET                         8u
#define I2C_IC_DATA_CMD_CMD_MASK                           0x100u
#define I2C_IC_DATA_CMD_CMD_WRITE                          0u
#define I2C_IC_DATA_CMD_CMD_READ                           1u

#define I2C_IC_DATA_CMD_DAT_OFFSET                         0u
#define I2C_IC_DATA_CMD_DAT_MASK                           0xffu

#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_OFFSET           0u
#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_MASK             0xffffu

#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_OFFSET           0u
#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_MASK             0xffffu

#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_OFFSET           0u
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_MASK             0xffffu

#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_OFFSET           0u
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_MASK             0xffffu

#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_OFFSET           13u
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_MASK             0x7ffe000u
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_INACTIVE         0u
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_ACTIVE           1u

#define I2C_IC_INTR_STAT_R_RESTART_DET_OFFSET              12u
#define I2C_IC_INTR_STAT_R_RESTART_DET_MASK                0x1000u
#define I2C_IC_INTR_STAT_R_RESTART_DET_INACTIVE            0u
#define I2C_IC_INTR_STAT_R_RESTART_DET_ACTIVE              1u

#define I2C_IC_INTR_STAT_R_GEN_CALL_OFFSET                 11u
#define I2C_IC_INTR_STAT_R_GEN_CALL_MASK                   0x800u
#define I2C_IC_INTR_STAT_R_GEN_CALL_INACTIVE               0u
#define I2C_IC_INTR_STAT_R_GEN_CALL_ACTIVE                 1u

#define I2C_IC_INTR_STAT_R_START_DET_OFFSET                10u
#define I2C_IC_INTR_STAT_R_START_DET_MASK                  0x400u
#define I2C_IC_INTR_STAT_R_START_DET_INACTIVE              0u
#define I2C_IC_INTR_STAT_R_START_DET_ACTIVE                1u

#define I2C_IC_INTR_STAT_R_STOP_DET_OFFSET                 9u
#define I2C_IC_INTR_STAT_R_STOP_DET_MASK                   0x200u
#define I2C_IC_INTR_STAT_R_STOP_DET_INACTIVE               0u
#define I2C_IC_INTR_STAT_R_STOP_DET_ACTIVE                 1u

#define I2C_IC_INTR_STAT_R_ACTIVITY_OFFSET                 8u
#define I2C_IC_INTR_STAT_R_ACTIVITY_MASK                   0x100u
#define I2C_IC_INTR_STAT_R_ACTIVITY_INACTIVE               0u
#define I2C_IC_INTR_STAT_R_ACTIVITY_ACTIVE                 1u

#define I2C_IC_INTR_STAT_R_RX_DONE_OFFSET                  7u
#define I2C_IC_INTR_STAT_R_RX_DONE_MASK                    0x80u
#define I2C_IC_INTR_STAT_R_RX_DONE_INACTIVE                0u
#define I2C_IC_INTR_STAT_R_RX_DONE_ACTIVE                  1u

#define I2C_IC_INTR_STAT_R_TX_ABRT_OFFSET                  6u
#define I2C_IC_INTR_STAT_R_TX_ABRT_MASK                    0x40u
#define I2C_IC_INTR_STAT_R_TX_ABRT_INACTIVE                0u
#define I2C_IC_INTR_STAT_R_TX_ABRT_ACTIVE                  1u

#define I2C_IC_INTR_STAT_R_RD_REQ_OFFSET                   5u
#define I2C_IC_INTR_STAT_R_RD_REQ_MASK                     0x20u
#define I2C_IC_INTR_STAT_R_RD_REQ_INACTIVE                 0u
#define I2C_IC_INTR_STAT_R_RD_REQ_ACTIVE                   1u

#define I2C_IC_INTR_STAT_R_TX_EMPTY_OFFSET                 4u
#define I2C_IC_INTR_STAT_R_TX_EMPTY_MASK                   0x10u
#define I2C_IC_INTR_STAT_R_TX_EMPTY_INACTIVE               0u
#define I2C_IC_INTR_STAT_R_TX_EMPTY_ACTIVE                 1u

#define I2C_IC_INTR_STAT_R_TX_OVER_OFFSET                  3u
#define I2C_IC_INTR_STAT_R_TX_OVER_MASK                    8u
#define I2C_IC_INTR_STAT_R_TX_OVER_INACTIVE                0u
#define I2C_IC_INTR_STAT_R_TX_OVER_ACTIVE                  1u

#define I2C_IC_INTR_STAT_R_RX_FULL_OFFSET                  2u
#define I2C_IC_INTR_STAT_R_RX_FULL_MASK                    4u
#define I2C_IC_INTR_STAT_R_RX_FULL_INACTIVE                0u
#define I2C_IC_INTR_STAT_R_RX_FULL_ACTIVE                  1u

#define I2C_IC_INTR_STAT_R_RX_OVER_OFFSET                  1u
#define I2C_IC_INTR_STAT_R_RX_OVER_MASK                    2u
#define I2C_IC_INTR_STAT_R_RX_OVER_INACTIVE                0u
#define I2C_IC_INTR_STAT_R_RX_OVER_ACTIVE                  1u

#define I2C_IC_INTR_STAT_R_RX_UNDER_OFFSET                 0u
#define I2C_IC_INTR_STAT_R_RX_UNDER_MASK                   1u
#define I2C_IC_INTR_STAT_R_RX_UNDER_INACTIVE               0u
#define I2C_IC_INTR_STAT_R_RX_UNDER_ACTIVE                 1u

#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_READ_ONLY_OFFSET   13u
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_READ_ONLY_MASK   0x7ffe000u
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_READ_ONLY_ENABLED   0
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_READ_ONLY_DISABLED   1

#define I2C_IC_INTR_MASK_M_RESTART_DET_OFFSET              12u
#define I2C_IC_INTR_MASK_M_RESTART_DET_MASK                0x1000u
#define I2C_IC_INTR_MASK_M_RESTART_DET_ENABLED             0u
#define I2C_IC_INTR_MASK_M_RESTART_DET_DISABLED            1u

#define I2C_IC_INTR_MASK_M_GEN_CALL_OFFSET                 11u
#define I2C_IC_INTR_MASK_M_GEN_CALL_MASK                   0x800u
#define I2C_IC_INTR_MASK_M_GEN_CALL_ENABLED                0u
#define I2C_IC_INTR_MASK_M_GEN_CALL_DISABLED               1u

#define I2C_IC_INTR_MASK_M_START_DET_OFFSET                10u
#define I2C_IC_INTR_MASK_M_START_DET_MASK                  0x400u
#define I2C_IC_INTR_MASK_M_START_DET_ENABLED               0u
#define I2C_IC_INTR_MASK_M_START_DET_DISABLED              1u

#define I2C_IC_INTR_MASK_M_STOP_DET_OFFSET                 9u
#define I2C_IC_INTR_MASK_M_STOP_DET_MASK                   0x200u
#define I2C_IC_INTR_MASK_M_STOP_DET_ENABLED                0u
#define I2C_IC_INTR_MASK_M_STOP_DET_DISABLED               1u

#define I2C_IC_INTR_MASK_M_ACTIVITY_OFFSET                 8u
#define I2C_IC_INTR_MASK_M_ACTIVITY_MASK                   0x100u
#define I2C_IC_INTR_MASK_M_ACTIVITY_ENABLED                0u
#define I2C_IC_INTR_MASK_M_ACTIVITY_DISABLED               1u

#define I2C_IC_INTR_MASK_M_RX_DONE_OFFSET                  7u
#define I2C_IC_INTR_MASK_M_RX_DONE_MASK                    0x80u
#define I2C_IC_INTR_MASK_M_RX_DONE_ENABLED                 0u
#define I2C_IC_INTR_MASK_M_RX_DONE_DISABLED                1u

#define I2C_IC_INTR_MASK_M_TX_ABRT_OFFSET                  6u
#define I2C_IC_INTR_MASK_M_TX_ABRT_MASK                    0x40u
#define I2C_IC_INTR_MASK_M_TX_ABRT_ENABLED                 0u
#define I2C_IC_INTR_MASK_M_TX_ABRT_DISABLED                1u

#define I2C_IC_INTR_MASK_M_RD_REQ_OFFSET                   5u
#define I2C_IC_INTR_MASK_M_RD_REQ_MASK                     0x20u
#define I2C_IC_INTR_MASK_M_RD_REQ_ENABLED                  0u
#define I2C_IC_INTR_MASK_M_RD_REQ_DISABLED                 1u

#define I2C_IC_INTR_MASK_M_TX_EMPTY_OFFSET                 4u
#define I2C_IC_INTR_MASK_M_TX_EMPTY_MASK                   0x10u
#define I2C_IC_INTR_MASK_M_TX_EMPTY_ENABLED                0u
#define I2C_IC_INTR_MASK_M_TX_EMPTY_DISABLED               1u

#define I2C_IC_INTR_MASK_M_TX_OVER_OFFSET                  3u
#define I2C_IC_INTR_MASK_M_TX_OVER_MASK                    8u
#define I2C_IC_INTR_MASK_M_TX_OVER_ENABLED                 0u
#define I2C_IC_INTR_MASK_M_TX_OVER_DISABLED                1u

#define I2C_IC_INTR_MASK_M_RX_FULL_OFFSET                  2u
#define I2C_IC_INTR_MASK_M_RX_FULL_MASK                    4u
#define I2C_IC_INTR_MASK_M_RX_FULL_ENABLED                 0u
#define I2C_IC_INTR_MASK_M_RX_FULL_DISABLED                1u

#define I2C_IC_INTR_MASK_M_RX_OVER_OFFSET                  1u
#define I2C_IC_INTR_MASK_M_RX_OVER_MASK                    2u
#define I2C_IC_INTR_MASK_M_RX_OVER_ENABLED                 0u
#define I2C_IC_INTR_MASK_M_RX_OVER_DISABLED                1u

#define I2C_IC_INTR_MASK_M_RX_UNDER_OFFSET                 0u
#define I2C_IC_INTR_MASK_M_RX_UNDER_MASK                   1u
#define I2C_IC_INTR_MASK_M_RX_UNDER_ENABLED                0u
#define I2C_IC_INTR_MASK_M_RX_UNDER_DISABLED               1u

#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_OFFSET         13u
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_MASK           0x7ffe000u
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_INACTIVE       0u
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_ACTIVE         1u

#define I2C_IC_RAW_INTR_STAT_RESTART_DET_OFFSET            12u
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_MASK              0x1000u
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_INACTIVE          0u
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_ACTIVE            1u

#define I2C_IC_RAW_INTR_STAT_GEN_CALL_OFFSET               11u
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_MASK                 0x800u
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_INACTIVE             0u
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_ACTIVE               1u

#define I2C_IC_RAW_INTR_STAT_START_DET_OFFSET              10u
#define I2C_IC_RAW_INTR_STAT_START_DET_MASK                0x400u
#define I2C_IC_RAW_INTR_STAT_START_DET_INACTIVE            0u
#define I2C_IC_RAW_INTR_STAT_START_DET_ACTIVE              1u

#define I2C_IC_RAW_INTR_STAT_STOP_DET_OFFSET               9u
#define I2C_IC_RAW_INTR_STAT_STOP_DET_MASK                 0x200u
#define I2C_IC_RAW_INTR_STAT_STOP_DET_INACTIVE             0u
#define I2C_IC_RAW_INTR_STAT_STOP_DET_ACTIVE               1u

#define I2C_IC_RAW_INTR_STAT_ACTIVITY_OFFSET               8u
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_MASK                 0x100u
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_INACTIVE             0u
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_ACTIVE               1u

#define I2C_IC_RAW_INTR_STAT_RX_DONE_OFFSET                7u
#define I2C_IC_RAW_INTR_STAT_RX_DONE_MASK                  0x80u
#define I2C_IC_RAW_INTR_STAT_RX_DONE_INACTIVE              0u
#define I2C_IC_RAW_INTR_STAT_RX_DONE_ACTIVE                1u

#define I2C_IC_RAW_INTR_STAT_TX_ABRT_OFFSET                6u
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_MASK                  0x40u
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_INACTIVE              0u
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_ACTIVE                1u

#define I2C_IC_RAW_INTR_STAT_RD_REQ_OFFSET                 5u
#define I2C_IC_RAW_INTR_STAT_RD_REQ_MASK                   0x20u
#define I2C_IC_RAW_INTR_STAT_RD_REQ_INACTIVE               0u
#define I2C_IC_RAW_INTR_STAT_RD_REQ_ACTIVE                 1u

#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_OFFSET               4u
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_MASK                 0x10u
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_INACTIVE             0u
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_ACTIVE               1u

#define I2C_IC_RAW_INTR_STAT_TX_OVER_OFFSET                3u
#define I2C_IC_RAW_INTR_STAT_TX_OVER_MASK                  8u
#define I2C_IC_RAW_INTR_STAT_TX_OVER_INACTIVE              0u
#define I2C_IC_RAW_INTR_STAT_TX_OVER_ACTIVE                1u

#define I2C_IC_RAW_INTR_STAT_RX_FULL_OFFSET                2u
#define I2C_IC_RAW_INTR_STAT_RX_FULL_MASK                  4u
#define I2C_IC_RAW_INTR_STAT_RX_FULL_INACTIVE              0u
#define I2C_IC_RAW_INTR_STAT_RX_FULL_ACTIVE                1u

#define I2C_IC_RAW_INTR_STAT_RX_OVER_OFFSET                1u
#define I2C_IC_RAW_INTR_STAT_RX_OVER_MASK                  2u
#define I2C_IC_RAW_INTR_STAT_RX_OVER_INACTIVE              0u
#define I2C_IC_RAW_INTR_STAT_RX_OVER_ACTIVE                1u

#define I2C_IC_RAW_INTR_STAT_RX_UNDER_OFFSET               0u
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_MASK                 1u
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_INACTIVE             0u
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_ACTIVE               1u

#define I2C_IC_RX_TL_RX_TL_OFFSET                          0u
#define I2C_IC_RX_TL_RX_TL_MASK                            0xffu

#define I2C_IC_TX_TL_TX_TL_OFFSET                          0u
#define I2C_IC_TX_TL_TX_TL_MASK                            0xffu

#define I2C_IC_CLR_INTR_CLR_INTR_OFFSET                    0u
#define I2C_IC_CLR_INTR_CLR_INTR_MASK                      1u

#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_OFFSET            0u
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_MASK              1u

#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_OFFSET              0u
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_MASK                1u

#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_OFFSET              0u
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_MASK                1u

#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_OFFSET                0u
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_MASK                  1u

#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_OFFSET              0u
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_MASK                1u

#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_OFFSET              0u
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_MASK                1u

#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_OFFSET            0u
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_MASK              1u

#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_OFFSET            0u
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_MASK              1u

#define I2C_IC_CLR_START_DET_CLR_START_DET_OFFSET          0u
#define I2C_IC_CLR_START_DET_CLR_START_DET_MASK            1u

#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_OFFSET            0u
#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_MASK              1u

#define I2C_IC_ENABLE_TX_CMD_BLOCK_OFFSET                  2u
#define I2C_IC_ENABLE_TX_CMD_BLOCK_MASK                    4u
#define I2C_IC_ENABLE_TX_CMD_BLOCK_NOT_BLOCKED             0u
#define I2C_IC_ENABLE_TX_CMD_BLOCK_BLOCKED                 1u

#define I2C_IC_ENABLE_ABORT_OFFSET                         1u
#define I2C_IC_ENABLE_ABORT_MASK                           2u
#define I2C_IC_ENABLE_ABORT_DISABLE                        0u
#define I2C_IC_ENABLE_ABORT_ENABLED                        1u

#define I2C_IC_ENABLE_ENABLE_OFFSET                        0u
#define I2C_IC_ENABLE_ENABLE_MASK                          1u
#define I2C_IC_ENABLE_ENABLE_DISABLED                      0u
#define I2C_IC_ENABLE_ENABLE_ENABLED                       1u

#define I2C_IC_STATUS_SLV_ACTIVITY_OFFSET                  6u
#define I2C_IC_STATUS_SLV_ACTIVITY_MASK                    0x40u
#define I2C_IC_STATUS_SLV_ACTIVITY_IDLE                    0u
#define I2C_IC_STATUS_SLV_ACTIVITY_ACTIVE                  1u

#define I2C_IC_STATUS_MST_ACTIVITY_OFFSET                  5u
#define I2C_IC_STATUS_MST_ACTIVITY_MASK                    0x20u
#define I2C_IC_STATUS_MST_ACTIVITY_IDLE                    0u
#define I2C_IC_STATUS_MST_ACTIVITY_ACTIVE                  1u

#define I2C_IC_STATUS_RFF_OFFSET                           4u
#define I2C_IC_STATUS_RFF_MASK                             0x10u
#define I2C_IC_STATUS_RFF_NOT_FULL                         0u
#define I2C_IC_STATUS_RFF_FULL                             1u

#define I2C_IC_STATUS_RFNE_OFFSET                          3u
#define I2C_IC_STATUS_RFNE_MASK                            8u
#define I2C_IC_STATUS_RFNE_EMPTY                           0u
#define I2C_IC_STATUS_RFNE_NOT_EMPTY                       1u

#define I2C_IC_STATUS_TFE_OFFSET                           2u
#define I2C_IC_STATUS_TFE_MASK                             4u
#define I2C_IC_STATUS_TFE_NON_EMPTY                        0u
#define I2C_IC_STATUS_TFE_EMPTY                            1u

#define I2C_IC_STATUS_TFNF_OFFSET                          1u
#define I2C_IC_STATUS_TFNF_MASK                            2u
#define I2C_IC_STATUS_TFNF_FULL                            0u
#define I2C_IC_STATUS_TFNF_NOT_FULL                        1u

#define I2C_IC_STATUS_ACTIVITY_OFFSET                      0u
#define I2C_IC_STATUS_ACTIVITY_MASK                        1u
#define I2C_IC_STATUS_ACTIVITY_INACTIVE                    0u
#define I2C_IC_STATUS_ACTIVITY_ACTIVE                      1u

#define I2C_IC_TXFLR_TXFLR_OFFSET                          0u
#define I2C_IC_TXFLR_TXFLR_MASK                            0x1fu

#define I2C_IC_RXFLR_RXFLR_OFFSET                          0u
#define I2C_IC_RXFLR_RXFLR_MASK                            0x1fu

#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_OFFSET              16u
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_MASK                0xff0000u

#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_OFFSET              0u
#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_MASK                0xffffu

#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_OFFSET          23u
#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_MASK            0xff800000u

#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_OFFSET        16u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_MASK          0x10000u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_OFFSET       15u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_MASK         0x8000u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_OFFSET      14u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_MASK        0x4000u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_OFFSET  13u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_MASK    0x2000u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_OFFSET              12u
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_MASK                0x1000u
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_VOID      0u
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_OFFSET       11u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_MASK         0x800u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_OFFSET   10u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_MASK     0x400u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_OFFSET    9u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_MASK      0x200u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_OFFSET       8u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_MASK         0x100u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_OFFSET     7u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_MASK       0x80u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_OFFSET        6u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_MASK          0x40u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_OFFSET       5u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_MASK         0x20u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_OFFSET      4u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_MASK        0x10u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_OFFSET     3u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_MASK       8u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_VOID   0
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_GENERATED   1

#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_OFFSET    2u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_MASK      4u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_INACTIVE  0u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_ACTIVE    1u

#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_OFFSET    1u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_MASK      2u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_INACTIVE  0u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_ACTIVE    1u

#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_OFFSET    0u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_MASK      1u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_INACTIVE  0u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_ACTIVE    1u

#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_OFFSET              0u
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_MASK                1u
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_DISABLED            0u
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_ENABLED             1u

#define I2C_IC_DMA_CR_TDMAE_OFFSET                         1u
#define I2C_IC_DMA_CR_TDMAE_MASK                           2u
#define I2C_IC_DMA_CR_TDMAE_DISABLED                       0u
#define I2C_IC_DMA_CR_TDMAE_ENABLED                        1u

#define I2C_IC_DMA_CR_RDMAE_OFFSET                         0u
#define I2C_IC_DMA_CR_RDMAE_MASK                           1u
#define I2C_IC_DMA_CR_RDMAE_DISABLED                       0u
#define I2C_IC_DMA_CR_RDMAE_ENABLED                        1u

#define I2C_IC_DMA_TDLR_DMATDL_OFFSET                      0u
#define I2C_IC_DMA_TDLR_DMATDL_MASK                        0xfu

#define I2C_IC_DMA_RDLR_DMARDL_OFFSET                      0u
#define I2C_IC_DMA_RDLR_DMARDL_MASK                        0xfu

#define I2C_IC_SDA_SETUP_SDA_SETUP_OFFSET                  0u
#define I2C_IC_SDA_SETUP_SDA_SETUP_MASK                    0xffu

#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_OFFSET        0u
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_MASK          1u
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_DISABLED      0u
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_ENABLED       1u

#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_OFFSET       2u
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_MASK         4u
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_INACTIVE     0u
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_ACTIVE       1u

#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_OFFSET   1u
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_MASK  2u
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_INACTIVE   0
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_ACTIVE   1

#define I2C_IC_ENABLE_STATUS_IC_EN_OFFSET                  0u
#define I2C_IC_ENABLE_STATUS_IC_EN_MASK                    1u
#define I2C_IC_ENABLE_STATUS_IC_EN_DISABLED                0u
#define I2C_IC_ENABLE_STATUS_IC_EN_ENABLED                 1u

#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_OFFSET               0u
#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_MASK                 0xffu

#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_OFFSET      0u
#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_MASK        1u

#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_OFFSET         16u
#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_MASK           0xff0000u

#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_OFFSET         8u
#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_MASK           0xff00u

#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_OFFSET      7u
#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_MASK        0x80u

#define I2C_IC_COMP_PARAM_1_HAS_DMA_OFFSET                 6u
#define I2C_IC_COMP_PARAM_1_HAS_DMA_MASK                   0x40u

#define I2C_IC_COMP_PARAM_1_INTR_IO_OFFSET                 5u
#define I2C_IC_COMP_PARAM_1_INTR_IO_MASK                   0x20u

#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_OFFSET         4u
#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_MASK           0x10u

#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_OFFSET          2u
#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_MASK            0xcu

#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_OFFSET          0u
#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_MASK            3u

#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_OFFSET         0u
#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_MASK           0xffffffffu

#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_OFFSET               0u
#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_MASK                 0xffffffffu


typedef struct
{

/** IC_CON (offset: 0x0)
  I2C Control Register. This register can be written only when the DW_apb_i2c is disabled, which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 Read/Write Access: - bit 10 is read only. - bit 11 is read only - bit 16 is read only - bit 17 is read only - bits 18 and 19 are read only.
  access : read-write
  reset value : 0x65
  reset mask : 0x0
  Field: STOP_DET_IF_MASTER_ACTIVE
  offset: 10, size: 1, access: read-only
  Master issues the STOP_DET interrupt irrespective of whether master is active or not
  Field: RX_FIFO_FULL_HLD_CTRL
  offset: 9, size: 1, access: read-write
  This bit controls whether DW_apb_i2c should hold the bus when the Rx FIFO is physically full to its RX_BUFFER_DEPTH, as described in the IC_RX_FULL_HLD_BUS_EN parameter.


 Reset value: 0x0.
  Enum:
  Value: 0 - DISABLED : Overflow when RX_FIFO is full
  Value: 1 - ENABLED : Hold bus when RX_FIFO is full
  Field: TX_EMPTY_CTRL
  offset: 8, size: 1, access: read-write
  This bit controls the generation of the TX_EMPTY interrupt, as described in the IC_RAW_INTR_STAT register.


 Reset value: 0x0.
  Enum:
  Value: 0 - DISABLED : Default behaviour of TX_EMPTY interrupt
  Value: 1 - ENABLED : Controlled generation of TX_EMPTY interrupt
  Field: STOP_DET_IFADDRESSED
  offset: 7, size: 1, access: read-write
  In slave mode: - 1&apos;b1: issues the STOP_DET interrupt only when it is addressed. - 1&apos;b0: issues the STOP_DET irrespective of whether it&apos;s addressed or not. Reset value: 0x0


 NOTE: During a general call address, this slave does not issue the STOP_DET interrupt if STOP_DET_IF_ADDRESSED = 1&apos;b1, even if the slave responds to the general call address by generating ACK. The STOP_DET interrupt is generated only when the transmitted address matches the slave address (SAR).
  Enum:
  Value: 0 - DISABLED : slave issues STOP_DET intr always
  Value: 1 - ENABLED : slave issues STOP_DET intr only if addressed
  Field: IC_SLAVE_DISABLE
  offset: 6, size: 1, access: read-write
  This bit controls whether I2C has its slave disabled, which means once the presetn signal is applied, then this bit is set and the slave is disabled.


 If this bit is set (slave is disabled), DW_apb_i2c functions only as a master and does not perform any action that requires a slave.


 NOTE: Software should ensure that if this bit is written with 0, then bit 0 should also be written with a 0.
  Enum:
  Value: 0 - SLAVE_ENABLED : Slave mode is enabled
  Value: 1 - SLAVE_DISABLED : Slave mode is disabled
  Field: IC_RESTART_EN
  offset: 5, size: 1, access: read-write
  Determines whether RESTART conditions may be sent when acting as a master. Some older slaves do not support handling RESTART conditions however, RESTART conditions are used in several DW_apb_i2c operations. When RESTART is disabled, the master is prohibited from performing the following functions: - Sending a START BYTE - Performing any high-speed mode operation - High-speed mode operation - Performing direction changes in combined format mode - Performing a read operation with a 10-bit address By replacing RESTART condition followed by a STOP and a subsequent START condition, split operations are broken down into multiple DW_apb_i2c transfers. If the above operations are performed, it will result in setting bit 6 (TX_ABRT) of the IC_RAW_INTR_STAT register.


 Reset value: ENABLED
  Enum:
  Value: 0 - DISABLED : Master restart disabled
  Value: 1 - ENABLED : Master restart enabled
  Field: IC_10BITADDR_MASTER
  offset: 4, size: 1, access: read-write
  Controls whether the DW_apb_i2c starts its transfers in 7- or 10-bit addressing mode when acting as a master. - 0: 7-bit addressing - 1: 10-bit addressing
  Enum:
  Value: 0 - ADDR_7BITS : Master 7Bit addressing mode
  Value: 1 - ADDR_10BITS : Master 10Bit addressing mode
  Field: IC_10BITADDR_SLAVE
  offset: 3, size: 1, access: read-write
  When acting as a slave, this bit controls whether the DW_apb_i2c responds to 7- or 10-bit addresses. - 0: 7-bit addressing. The DW_apb_i2c ignores transactions that involve 10-bit addressing for 7-bit addressing, only the lower 7 bits of the IC_SAR register are compared. - 1: 10-bit addressing. The DW_apb_i2c responds to only 10-bit addressing transfers that match the full 10 bits of the IC_SAR register.
  Enum:
  Value: 0 - ADDR_7BITS : Slave 7Bit addressing
  Value: 1 - ADDR_10BITS : Slave 10Bit addressing
  Field: SPEED
  offset: 1, size: 2, access: read-write
  These bits control at which speed the DW_apb_i2c operates its setting is relevant only if one is operating the DW_apb_i2c in master mode. Hardware protects against illegal values being programmed by software. These bits must be programmed appropriately for slave mode also, as it is used to capture correct value of spike filter as per the speed mode.


 This register should be programmed only with a value in the range of 1 to IC_MAX_SPEED_MODE otherwise, hardware updates this register with the value of IC_MAX_SPEED_MODE.


 1: standard mode (100 kbit/s)


 2: fast mode (&lt;=400 kbit/s) or fast mode plus (&lt;=1000Kbit/s)


 3: high speed mode (3.4 Mbit/s)


 Note: This field is not applicable when IC_ULTRA_FAST_MODE=1
  Enum:
  Value: 1 - STANDARD : Standard Speed mode of operation
  Value: 2 - FAST : Fast or Fast Plus mode of operation
  Value: 3 - HIGH : High Speed mode of operation
  Field: MASTER_MODE
  offset: 0, size: 1, access: read-write
  This bit controls whether the DW_apb_i2c master is enabled.


 NOTE: Software should ensure that if this bit is written with &apos;1&apos; then bit 6 should also be written with a &apos;1&apos;.
  Enum:
  Value: 0 - DISABLED : Master mode is disabled
  Value: 1 - ENABLED : Master mode is enabled
*/
volatile uint32_t IC_CON;

/** IC_TAR (offset: 0x4)
  I2C Target Address Register


 This register is 12 bits wide, and bits 31:12 are reserved. This register can be written to only when IC_ENABLE[0] is set to 0.


 Note: If the software or application is aware that the DW_apb_i2c is not using the TAR address for the pending commands in the Tx FIFO, then it is possible to update the TAR address even while the Tx FIFO has entries (IC_STATUS[2]= 0). - It is not necessary to perform any write to this register if DW_apb_i2c is enabled as an I2C slave only.
  access : read-write
  reset value : 0x55
  reset mask : 0x0
  Field: SPECIAL
  offset: 11, size: 1, access: read-write
  This bit indicates whether software performs a Device-ID or General Call or START BYTE command. - 0: ignore bit 10 GC_OR_START and use IC_TAR normally - 1: perform special I2C command as specified in Device_ID or GC_OR_START bit Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : Disables programming of GENERAL_CALL or START_BYTE transmission
  Value: 1 - ENABLED : Enables programming of GENERAL_CALL or START_BYTE transmission
  Field: GC_OR_START
  offset: 10, size: 1, access: read-write
  If bit 11 (SPECIAL) is set to 1 and bit 13(Device-ID) is set to 0, then this bit indicates whether a General Call or START byte command is to be performed by the DW_apb_i2c. - 0: General Call Address - after issuing a General Call, only writes may be performed. Attempting to issue a read command results in setting bit 6 (TX_ABRT) of the IC_RAW_INTR_STAT register. The DW_apb_i2c remains in General Call mode until the SPECIAL bit value (bit 11) is cleared. - 1: START BYTE Reset value: 0x0
  Enum:
  Value: 0 - GENERAL_CALL : GENERAL_CALL byte transmission
  Value: 1 - START_BYTE : START byte transmission
  Field: IC_TAR
  offset: 0, size: 10, access: read-write
  This is the target address for any master transaction. When transmitting a General Call, these bits are ignored. To generate a START BYTE, the CPU needs to write only once into these bits.


 If the IC_TAR and IC_SAR are the same, loopback exists but the FIFOs are shared between master and slave, so full loopback is not feasible. Only one direction loopback mode is supported (simplex), not duplex. A master cannot transmit to itself it can transmit to only a slave.
*/
volatile uint32_t IC_TAR;

/** IC_SAR (offset: 0x8)
  I2C Slave Address Register
  access : read-write
  reset value : 0x55
  reset mask : 0x0
  Field: IC_SAR
  offset: 0, size: 10, access: read-write
  The IC_SAR holds the slave address when the I2C is operating as a slave. For 7-bit addressing, only IC_SAR[6:0] is used.


 This register can be written only when the I2C interface is disabled, which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 Note: The default values cannot be any of the reserved address locations: that is, 0x00 to 0x07, or 0x78 to 0x7f. The correct operation of the device is not guaranteed if you program the IC_SAR or IC_TAR to a reserved value. Refer to &lt;&lt;table_I2C_firstbyte_bit_defs&gt;&gt; for a complete list of these reserved values.
*/
volatile uint32_t IC_SAR;
volatile uint32_t reserved0;

/** IC_DATA_CMD (offset: 0x10)
  I2C Rx/Tx Data Buffer and Command Register this is the register the CPU writes to when filling the TX FIFO and the CPU reads from when retrieving bytes from RX FIFO.


 The size of the register changes as follows:


 Write: - 11 bits when IC_EMPTYFIFO_HOLD_MASTER_EN=1 - 9 bits when IC_EMPTYFIFO_HOLD_MASTER_EN=0 Read: - 12 bits when IC_FIRST_DATA_BYTE_STATUS = 1 - 8 bits when IC_FIRST_DATA_BYTE_STATUS = 0 Note: In order for the DW_apb_i2c to continue acknowledging reads, a read command should be written for every byte that is to be received otherwise the DW_apb_i2c will stop acknowledging.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FIRST_DATA_BYTE
  offset: 11, size: 1, access: read-only
  Indicates the first data byte received after the address phase for receive transfer in Master receiver or Slave receiver mode.


 Reset value : 0x0


 NOTE: In case of APB_DATA_WIDTH=8,


 1. The user has to perform two APB Reads to IC_DATA_CMD in order to get status on 11 bit.


 2. In order to read the 11 bit, the user has to perform the first data byte read [7:0] (offset 0x10) and then perform the second read [15:8] (offset 0x11) in order to know the status of 11 bit (whether the data received in previous read is a first data byte or not).


 3. The 11th bit is an optional read field, user can ignore 2nd byte read [15:8] (offset 0x11) if not interested in FIRST_DATA_BYTE status.
  Enum:
  Value: 0 - INACTIVE : Sequential data byte received
  Value: 1 - ACTIVE : Non sequential data byte received
  Field: RESTART
  offset: 10, size: 1, access: read-write
  This bit controls whether a RESTART is issued before the byte is sent or received.


 1 - If IC_RESTART_EN is 1, a RESTART is issued before the data is sent/received (according to the value of CMD), regardless of whether or not the transfer direction is changing from the previous command if IC_RESTART_EN is 0, a STOP followed by a START is issued instead.


 0 - If IC_RESTART_EN is 1, a RESTART is issued only if the transfer direction is changing from the previous command if IC_RESTART_EN is 0, a STOP followed by a START is issued instead.


 Reset value: 0x0
  Enum:
  Value: 0 - DISABLE : Don&apos;t Issue RESTART before this command
  Value: 1 - ENABLE : Issue RESTART before this command
  Field: STOP
  offset: 9, size: 1, access: read-write
  This bit controls whether a STOP is issued after the byte is sent or received.


 - 1 - STOP is issued after this byte, regardless of whether or not the Tx FIFO is empty. If the Tx FIFO is not empty, the master immediately tries to start a new transfer by issuing a START and arbitrating for the bus. - 0 - STOP is not issued after this byte, regardless of whether or not the Tx FIFO is empty. If the Tx FIFO is not empty, the master continues the current transfer by sending/receiving data bytes according to the value of the CMD bit. If the Tx FIFO is empty, the master holds the SCL line low and stalls the bus until a new command is available in the Tx FIFO. Reset value: 0x0
  Enum:
  Value: 0 - DISABLE : Don&apos;t Issue STOP after this command
  Value: 1 - ENABLE : Issue STOP after this command
  Field: CMD
  offset: 8, size: 1, access: read-write
  This bit controls whether a read or a write is performed. This bit does not control the direction when the DW_apb_i2con acts as a slave. It controls only the direction when it acts as a master.


 When a command is entered in the TX FIFO, this bit distinguishes the write and read commands. In slave-receiver mode, this bit is a &apos;don&apos;t care&apos; because writes to this register are not required. In slave-transmitter mode, a &apos;0&apos; indicates that the data in IC_DATA_CMD is to be transmitted.


 When programming this bit, you should remember the following: attempting to perform a read operation after a General Call command has been sent results in a TX_ABRT interrupt (bit 6 of the IC_RAW_INTR_STAT register), unless bit 11 (SPECIAL) in the IC_TAR register has been cleared. If a &apos;1&apos; is written to this bit after receiving a RD_REQ interrupt, then a TX_ABRT interrupt occurs.


 Reset value: 0x0
  Enum:
  Value: 0 - WRITE : Master Write Command
  Value: 1 - READ : Master Read Command
  Field: DAT
  offset: 0, size: 8, access: read-write
  This register contains the data to be transmitted or received on the I2C bus. If you are writing to this register and want to perform a read, bits 7:0 (DAT) are ignored by the DW_apb_i2c. However, when you read this register, these bits return the value of data received on the DW_apb_i2c interface.


 Reset value: 0x0
*/
volatile uint32_t IC_DATA_CMD;

/** IC_SS_SCL_HCNT (offset: 0x14)
  Standard Speed I2C Clock SCL High Count Register
  access : read-write
  reset value : 0x28
  reset mask : 0x0
  Field: IC_SS_SCL_HCNT
  offset: 0, size: 16, access: read-write
  This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. This register sets the SCL clock high-period count for standard speed. For more information, refer to &apos;IC_CLK Frequency Configuration&apos;.


 This register can be written only when the I2C interface is disabled which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 The minimum valid value is 6 hardware prevents values less than this being written, and if attempted results in 6 being set. For designs with APB_DATA_WIDTH = 8, the order of programming is important to ensure the correct operation of the DW_apb_i2c. The lower byte must be programmed first. Then the upper byte is programmed.


 NOTE: This register must not be programmed to a value higher than 65525, because DW_apb_i2c uses a 16-bit counter to flag an I2C bus idle condition when this counter reaches a value of IC_SS_SCL_HCNT + 10.
*/
volatile uint32_t IC_SS_SCL_HCNT;

/** IC_SS_SCL_LCNT (offset: 0x18)
  Standard Speed I2C Clock SCL Low Count Register
  access : read-write
  reset value : 0x2F
  reset mask : 0x0
  Field: IC_SS_SCL_LCNT
  offset: 0, size: 16, access: read-write
  This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. This register sets the SCL clock low period count for standard speed. For more information, refer to &apos;IC_CLK Frequency Configuration&apos;


 This register can be written only when the I2C interface is disabled which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 The minimum valid value is 8 hardware prevents values less than this being written, and if attempted, results in 8 being set. For designs with APB_DATA_WIDTH = 8, the order of programming is important to ensure the correct operation of DW_apb_i2c. The lower byte must be programmed first, and then the upper byte is programmed.
*/
volatile uint32_t IC_SS_SCL_LCNT;

/** IC_FS_SCL_HCNT (offset: 0x1c)
  Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register
  access : read-write
  reset value : 0x6
  reset mask : 0x0
  Field: IC_FS_SCL_HCNT
  offset: 0, size: 16, access: read-write
  This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. This register sets the SCL clock high-period count for fast mode or fast mode plus. It is used in high-speed mode to send the Master Code and START BYTE or General CALL. For more information, refer to &apos;IC_CLK Frequency Configuration&apos;.


 This register goes away and becomes read-only returning 0s if IC_MAX_SPEED_MODE = standard. This register can be written only when the I2C interface is disabled, which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 The minimum valid value is 6 hardware prevents values less than this being written, and if attempted results in 6 being set. For designs with APB_DATA_WIDTH == 8 the order of programming is important to ensure the correct operation of the DW_apb_i2c. The lower byte must be programmed first. Then the upper byte is programmed.
*/
volatile uint32_t IC_FS_SCL_HCNT;

/** IC_FS_SCL_LCNT (offset: 0x20)
  Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register
  access : read-write
  reset value : 0xD
  reset mask : 0x0
  Field: IC_FS_SCL_LCNT
  offset: 0, size: 16, access: read-write
  This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. This register sets the SCL clock low period count for fast speed. It is used in high-speed mode to send the Master Code and START BYTE or General CALL. For more information, refer to &apos;IC_CLK Frequency Configuration&apos;.


 This register goes away and becomes read-only returning 0s if IC_MAX_SPEED_MODE = standard.


 This register can be written only when the I2C interface is disabled, which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect.


 The minimum valid value is 8 hardware prevents values less than this being written, and if attempted results in 8 being set. For designs with APB_DATA_WIDTH = 8 the order of programming is important to ensure the correct operation of the DW_apb_i2c. The lower byte must be programmed first. Then the upper byte is programmed. If the value is less than 8 then the count value gets changed to 8.
*/
volatile uint32_t IC_FS_SCL_LCNT;
volatile uint32_t reserved1[2];

/** IC_INTR_STAT (offset: 0x2c)
  I2C Interrupt Status Register


 Each bit in this register has a corresponding mask bit in the IC_INTR_MASK register. These bits are cleared by reading the matching interrupt clear register. The unmasked raw versions of these bits are available in the IC_RAW_INTR_STAT register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: R_MASTER_ON_HOLD
  offset: 13, size: 14, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_MASTER_ON_HOLD bit.
  
   Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_MASTER_ON_HOLD interrupt is inactive
  Value: 1 - ACTIVE : R_MASTER_ON_HOLD interrupt is active
  Field: R_RESTART_DET
  offset: 12, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RESTART_DET bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_RESTART_DET interrupt is inactive
  Value: 1 - ACTIVE : R_RESTART_DET interrupt is active
  Field: R_GEN_CALL
  offset: 11, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_GEN_CALL bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_GEN_CALL interrupt is inactive
  Value: 1 - ACTIVE : R_GEN_CALL interrupt is active
  Field: R_START_DET
  offset: 10, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_START_DET bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_START_DET interrupt is inactive
  Value: 1 - ACTIVE : R_START_DET interrupt is active
  Field: R_STOP_DET
  offset: 9, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_STOP_DET bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_STOP_DET interrupt is inactive
  Value: 1 - ACTIVE : R_STOP_DET interrupt is active
  Field: R_ACTIVITY
  offset: 8, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_ACTIVITY bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_ACTIVITY interrupt is inactive
  Value: 1 - ACTIVE : R_ACTIVITY interrupt is active
  Field: R_RX_DONE
  offset: 7, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RX_DONE bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_RX_DONE interrupt is inactive
  Value: 1 - ACTIVE : R_RX_DONE interrupt is active
  Field: R_TX_ABRT
  offset: 6, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_TX_ABRT bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_TX_ABRT interrupt is inactive
  Value: 1 - ACTIVE : R_TX_ABRT interrupt is active
  Field: R_RD_REQ
  offset: 5, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RD_REQ bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_RD_REQ interrupt is inactive
  Value: 1 - ACTIVE : R_RD_REQ interrupt is active
  Field: R_TX_EMPTY
  offset: 4, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_TX_EMPTY bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_TX_EMPTY interrupt is inactive
  Value: 1 - ACTIVE : R_TX_EMPTY interrupt is active
  Field: R_TX_OVER
  offset: 3, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_TX_OVER bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_TX_OVER interrupt is inactive
  Value: 1 - ACTIVE : R_TX_OVER interrupt is active
  Field: R_RX_FULL
  offset: 2, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RX_FULL bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_RX_FULL interrupt is inactive
  Value: 1 - ACTIVE : R_RX_FULL interrupt is active
  Field: R_RX_OVER
  offset: 1, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RX_OVER bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : R_RX_OVER interrupt is inactive
  Value: 1 - ACTIVE : R_RX_OVER interrupt is active
  Field: R_RX_UNDER
  offset: 0, size: 1, access: read-only
  See IC_RAW_INTR_STAT for a detailed description of R_RX_UNDER bit.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RX_UNDER interrupt is inactive
  Value: 1 - ACTIVE : RX_UNDER interrupt is active
*/
volatile uint32_t IC_INTR_STAT;

/** IC_INTR_MASK (offset: 0x30)
  I2C Interrupt Mask Register.


 These bits mask their corresponding interrupt status bits. This register is active low a value of 0 masks the interrupt, whereas a value of 1 unmasks the interrupt.
  access : read-write
  reset value : 0x8FF
  reset mask : 0x0
  Field: M_MASTER_ON_HOLD_READ_ONLY
  offset: 13, size: 14, access: read-only
  This M_MASTER_ON_HOLD_read_only bit masks the R_MASTER_ON_HOLD interrupt in IC_INTR_STAT register.
  
   Reset value: 0x0
  Enum:
  Value: 0 - ENABLED : MASTER_ON_HOLD interrupt is masked
  Value: 1 - DISABLED : MASTER_ON_HOLD interrupt is unmasked
  Field: M_RESTART_DET
  offset: 12, size: 1, access: read-write
  This bit masks the R_RESTART_DET interrupt in IC_INTR_STAT register.


 Reset value: 0x0
  Enum:
  Value: 0 - ENABLED : RESTART_DET interrupt is masked
  Value: 1 - DISABLED : RESTART_DET interrupt is unmasked
  Field: M_GEN_CALL
  offset: 11, size: 1, access: read-write
  This bit masks the R_GEN_CALL interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : GEN_CALL interrupt is masked
  Value: 1 - DISABLED : GEN_CALL interrupt is unmasked
  Field: M_START_DET
  offset: 10, size: 1, access: read-write
  This bit masks the R_START_DET interrupt in IC_INTR_STAT register.


 Reset value: 0x0
  Enum:
  Value: 0 - ENABLED : START_DET interrupt is masked
  Value: 1 - DISABLED : START_DET interrupt is unmasked
  Field: M_STOP_DET
  offset: 9, size: 1, access: read-write
  This bit masks the R_STOP_DET interrupt in IC_INTR_STAT register.


 Reset value: 0x0
  Enum:
  Value: 0 - ENABLED : STOP_DET interrupt is masked
  Value: 1 - DISABLED : STOP_DET interrupt is unmasked
  Field: M_ACTIVITY
  offset: 8, size: 1, access: read-write
  This bit masks the R_ACTIVITY interrupt in IC_INTR_STAT register.


 Reset value: 0x0
  Enum:
  Value: 0 - ENABLED : ACTIVITY interrupt is masked
  Value: 1 - DISABLED : ACTIVITY interrupt is unmasked
  Field: M_RX_DONE
  offset: 7, size: 1, access: read-write
  This bit masks the R_RX_DONE interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : RX_DONE interrupt is masked
  Value: 1 - DISABLED : RX_DONE interrupt is unmasked
  Field: M_TX_ABRT
  offset: 6, size: 1, access: read-write
  This bit masks the R_TX_ABRT interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : TX_ABORT interrupt is masked
  Value: 1 - DISABLED : TX_ABORT interrupt is unmasked
  Field: M_RD_REQ
  offset: 5, size: 1, access: read-write
  This bit masks the R_RD_REQ interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : RD_REQ interrupt is masked
  Value: 1 - DISABLED : RD_REQ interrupt is unmasked
  Field: M_TX_EMPTY
  offset: 4, size: 1, access: read-write
  This bit masks the R_TX_EMPTY interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : TX_EMPTY interrupt is masked
  Value: 1 - DISABLED : TX_EMPTY interrupt is unmasked
  Field: M_TX_OVER
  offset: 3, size: 1, access: read-write
  This bit masks the R_TX_OVER interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : TX_OVER interrupt is masked
  Value: 1 - DISABLED : TX_OVER interrupt is unmasked
  Field: M_RX_FULL
  offset: 2, size: 1, access: read-write
  This bit masks the R_RX_FULL interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : RX_FULL interrupt is masked
  Value: 1 - DISABLED : RX_FULL interrupt is unmasked
  Field: M_RX_OVER
  offset: 1, size: 1, access: read-write
  This bit masks the R_RX_OVER interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : RX_OVER interrupt is masked
  Value: 1 - DISABLED : RX_OVER interrupt is unmasked
  Field: M_RX_UNDER
  offset: 0, size: 1, access: read-write
  This bit masks the R_RX_UNDER interrupt in IC_INTR_STAT register.


 Reset value: 0x1
  Enum:
  Value: 0 - ENABLED : RX_UNDER interrupt is masked
  Value: 1 - DISABLED : RX_UNDER interrupt is unmasked
*/
volatile uint32_t IC_INTR_MASK;

/** IC_RAW_INTR_STAT (offset: 0x34)
  I2C Raw Interrupt Status Register


 Unlike the IC_INTR_STAT register, these bits are not masked so they always show the true status of the DW_apb_i2c.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MASTER_ON_HOLD
  offset: 13, size: 14, access: read-only
  Indicates whether master is holding the bus and TX FIFO is empty. Enabled only when I2C_DYNAMIC_TAR_UPDATE=1 and IC_EMPTYFIFO_HOLD_MASTER_EN=1.
  
   Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : MASTER_ON_HOLD interrupt is inactive
  Value: 1 - ACTIVE : MASTER_ON_HOLD interrupt is active
  Field: RESTART_DET
  offset: 12, size: 1, access: read-only
  Indicates whether a RESTART condition has occurred on the I2C interface when DW_apb_i2c is operating in Slave mode and the slave is being addressed. Enabled only when IC_SLV_RESTART_DET_EN=1.


 Note: However, in high-speed mode or during a START BYTE transfer, the RESTART comes before the address field as per the I2C protocol. In this case, the slave is not the addressed slave when the RESTART is issued, therefore DW_apb_i2c does not generate the RESTART_DET interrupt.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RESTART_DET interrupt is inactive
  Value: 1 - ACTIVE : RESTART_DET interrupt is active
  Field: GEN_CALL
  offset: 11, size: 1, access: read-only
  Set only when a General Call address is received and it is acknowledged. It stays set until it is cleared either by disabling DW_apb_i2c or when the CPU reads bit 0 of the IC_CLR_GEN_CALL register. DW_apb_i2c stores the received data in the Rx buffer.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : GEN_CALL interrupt is inactive
  Value: 1 - ACTIVE : GEN_CALL interrupt is active
  Field: START_DET
  offset: 10, size: 1, access: read-only
  Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether DW_apb_i2c is operating in slave or master mode.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : START_DET interrupt is inactive
  Value: 1 - ACTIVE : START_DET interrupt is active
  Field: STOP_DET
  offset: 9, size: 1, access: read-only
  Indicates whether a STOP condition has occurred on the I2C interface regardless of whether DW_apb_i2c is operating in slave or master mode.


 In Slave Mode: - If IC_CON[7]=1&apos;b1 (STOP_DET_IFADDRESSED), the STOP_DET interrupt will be issued only if slave is addressed. Note: During a general call address, this slave does not issue a STOP_DET interrupt if STOP_DET_IF_ADDRESSED=1&apos;b1, even if the slave responds to the general call address by generating ACK. The STOP_DET interrupt is generated only when the transmitted address matches the slave address (SAR). - If IC_CON[7]=1&apos;b0 (STOP_DET_IFADDRESSED), the STOP_DET interrupt is issued irrespective of whether it is being addressed. In Master Mode: - If IC_CON[10]=1&apos;b1 (STOP_DET_IF_MASTER_ACTIVE),the STOP_DET interrupt will be issued only if Master is active. - If IC_CON[10]=1&apos;b0 (STOP_DET_IFADDRESSED),the STOP_DET interrupt will be issued irrespective of whether master is active or not. Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : STOP_DET interrupt is inactive
  Value: 1 - ACTIVE : STOP_DET interrupt is active
  Field: ACTIVITY
  offset: 8, size: 1, access: read-only
  This bit captures DW_apb_i2c activity and stays set until it is cleared. There are four ways to clear it: - Disabling the DW_apb_i2c - Reading the IC_CLR_ACTIVITY register - Reading the IC_CLR_INTR register - System reset Once this bit is set, it stays set unless one of the four methods is used to clear it. Even if the DW_apb_i2c module is idle, this bit remains set until cleared, indicating that there was activity on the bus.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RAW_INTR_ACTIVITY interrupt is inactive
  Value: 1 - ACTIVE : RAW_INTR_ACTIVITY interrupt is active
  Field: RX_DONE
  offset: 7, size: 1, access: read-only
  When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RX_DONE interrupt is inactive
  Value: 1 - ACTIVE : RX_DONE interrupt is active
  Field: TX_ABRT
  offset: 6, size: 1, access: read-only
  This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the intended actions on the contents of the transmit FIFO. This situation can occur both as an I2C master or an I2C slave, and is referred to as a &apos;transmit abort&apos;. When this bit is set to 1, the IC_TX_ABRT_SOURCE register indicates the reason why the transmit abort takes places.


 Note: The DW_apb_i2c flushes/resets/empties the TX_FIFO and RX_FIFO whenever there is a transmit abort caused by any of the events tracked by the IC_TX_ABRT_SOURCE register. The FIFOs remains in this flushed state until the register IC_CLR_TX_ABRT is read. Once this read is performed, the Tx FIFO is then ready to accept more data bytes from the APB interface.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : TX_ABRT interrupt is inactive
  Value: 1 - ACTIVE : TX_ABRT interrupt is active
  Field: RD_REQ
  offset: 5, size: 1, access: read-only
  This bit is set to 1 when DW_apb_i2c is acting as a slave and another I2C master is attempting to read data from DW_apb_i2c. The DW_apb_i2c holds the I2C bus in a wait state (SCL=0) until this interrupt is serviced, which means that the slave has been addressed by a remote master that is asking for data to be transferred. The processor must respond to this interrupt and then write the requested data to the IC_DATA_CMD register. This bit is set to 0 just after the processor reads the IC_CLR_RD_REQ register.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RD_REQ interrupt is inactive
  Value: 1 - ACTIVE : RD_REQ interrupt is active
  Field: TX_EMPTY
  offset: 4, size: 1, access: read-only
  The behavior of the TX_EMPTY interrupt status differs based on the TX_EMPTY_CTRL selection in the IC_CON register. - When TX_EMPTY_CTRL = 0: This bit is set to 1 when the transmit buffer is at or below the threshold value set in the IC_TX_TL register. - When TX_EMPTY_CTRL = 1: This bit is set to 1 when the transmit buffer is at or below the threshold value set in the IC_TX_TL register and the transmission of the address/data from the internal shift register for the most recently popped command is completed. It is automatically cleared by hardware when the buffer level goes above the threshold. When IC_ENABLE[0] is set to 0, the TX FIFO is flushed and held in reset. There the TX FIFO looks like it has no data within it, so this bit is set to 1, provided there is activity in the master or slave state machines. When there is no longer any activity, then with ic_en=0, this bit is set to 0.


 Reset value: 0x0.
  Enum:
  Value: 0 - INACTIVE : TX_EMPTY interrupt is inactive
  Value: 1 - ACTIVE : TX_EMPTY interrupt is active
  Field: TX_OVER
  offset: 3, size: 1, access: read-only
  Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and the processor attempts to issue another I2C command by writing to the IC_DATA_CMD register. When the module is disabled, this bit keeps its level until the master or slave state machines go into idle, and when ic_en goes to 0, this interrupt is cleared.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : TX_OVER interrupt is inactive
  Value: 1 - ACTIVE : TX_OVER interrupt is active
  Field: RX_FULL
  offset: 2, size: 1, access: read-only
  Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register. It is automatically cleared by hardware when buffer level goes below the threshold. If the module is disabled (IC_ENABLE[0]=0), the RX FIFO is flushed and held in reset therefore the RX FIFO is not full. So this bit is cleared once the IC_ENABLE bit 0 is programmed with a 0, regardless of the activity that continues.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RX_FULL interrupt is inactive
  Value: 1 - ACTIVE : RX_FULL interrupt is active
  Field: RX_OVER
  offset: 1, size: 1, access: read-only
  Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an additional byte is received from an external I2C device. The DW_apb_i2c acknowledges this, but any data bytes received after the FIFO is full are lost. If the module is disabled (IC_ENABLE[0]=0), this bit keeps its level until the master or slave state machines go into idle, and when ic_en goes to 0, this interrupt is cleared.


 Note: If bit 9 of the IC_CON register (RX_FIFO_FULL_HLD_CTRL) is programmed to HIGH, then the RX_OVER interrupt never occurs, because the Rx FIFO never overflows.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RX_OVER interrupt is inactive
  Value: 1 - ACTIVE : RX_OVER interrupt is active
  Field: RX_UNDER
  offset: 0, size: 1, access: read-only
  Set if the processor attempts to read the receive buffer when it is empty by reading from the IC_DATA_CMD register. If the module is disabled (IC_ENABLE[0]=0), this bit keeps its level until the master or slave state machines go into idle, and when ic_en goes to 0, this interrupt is cleared.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : RX_UNDER interrupt is inactive
  Value: 1 - ACTIVE : RX_UNDER interrupt is active
*/
volatile uint32_t IC_RAW_INTR_STAT;

/** IC_RX_TL (offset: 0x38)
  I2C Receive FIFO Threshold Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RX_TL
  offset: 0, size: 8, access: read-write
  Receive FIFO Threshold Level.


 Controls the level of entries (or above) that triggers the RX_FULL interrupt (bit 2 in IC_RAW_INTR_STAT register). The valid range is 0-255, with the additional restriction that hardware does not allow this value to be set to a value larger than the depth of the buffer. If an attempt is made to do that, the actual value set will be the maximum depth of the buffer. A value of 0 sets the threshold for 1 entry, and a value of 255 sets the threshold for 256 entries.
*/
volatile uint32_t IC_RX_TL;

/** IC_TX_TL (offset: 0x3c)
  I2C Transmit FIFO Threshold Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TX_TL
  offset: 0, size: 8, access: read-write
  Transmit FIFO Threshold Level.


 Controls the level of entries (or below) that trigger the TX_EMPTY interrupt (bit 4 in IC_RAW_INTR_STAT register). The valid range is 0-255, with the additional restriction that it may not be set to value larger than the depth of the buffer. If an attempt is made to do that, the actual value set will be the maximum depth of the buffer. A value of 0 sets the threshold for 0 entries, and a value of 255 sets the threshold for 255 entries.
*/
volatile uint32_t IC_TX_TL;

/** IC_CLR_INTR (offset: 0x40)
  Clear Combined and Individual Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_INTR
  offset: 0, size: 1, access: read-only
  Read this register to clear the combined interrupt, all individual interrupts, and the IC_TX_ABRT_SOURCE register. This bit does not clear hardware clearable interrupts but software clearable interrupts. Refer to Bit 9 of the IC_TX_ABRT_SOURCE register for an exception to clearing IC_TX_ABRT_SOURCE.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_INTR;

/** IC_CLR_RX_UNDER (offset: 0x44)
  Clear RX_UNDER Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_RX_UNDER
  offset: 0, size: 1, access: read-only
  Read this register to clear the RX_UNDER interrupt (bit 0) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_RX_UNDER;

/** IC_CLR_RX_OVER (offset: 0x48)
  Clear RX_OVER Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_RX_OVER
  offset: 0, size: 1, access: read-only
  Read this register to clear the RX_OVER interrupt (bit 1) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_RX_OVER;

/** IC_CLR_TX_OVER (offset: 0x4c)
  Clear TX_OVER Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_TX_OVER
  offset: 0, size: 1, access: read-only
  Read this register to clear the TX_OVER interrupt (bit 3) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_TX_OVER;

/** IC_CLR_RD_REQ (offset: 0x50)
  Clear RD_REQ Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_RD_REQ
  offset: 0, size: 1, access: read-only
  Read this register to clear the RD_REQ interrupt (bit 5) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_RD_REQ;

/** IC_CLR_TX_ABRT (offset: 0x54)
  Clear TX_ABRT Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_TX_ABRT
  offset: 0, size: 1, access: read-only
  Read this register to clear the TX_ABRT interrupt (bit 6) of the IC_RAW_INTR_STAT register, and the IC_TX_ABRT_SOURCE register. This also releases the TX FIFO from the flushed/reset state, allowing more writes to the TX FIFO. Refer to Bit 9 of the IC_TX_ABRT_SOURCE register for an exception to clearing IC_TX_ABRT_SOURCE.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_TX_ABRT;

/** IC_CLR_RX_DONE (offset: 0x58)
  Clear RX_DONE Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_RX_DONE
  offset: 0, size: 1, access: read-only
  Read this register to clear the RX_DONE interrupt (bit 7) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_RX_DONE;

/** IC_CLR_ACTIVITY (offset: 0x5c)
  Clear ACTIVITY Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_ACTIVITY
  offset: 0, size: 1, access: read-only
  Reading this register clears the ACTIVITY interrupt if the I2C is not active anymore. If the I2C module is still active on the bus, the ACTIVITY interrupt bit continues to be set. It is automatically cleared by hardware if the module is disabled and if there is no further activity on the bus. The value read from this register to get status of the ACTIVITY interrupt (bit 8) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_ACTIVITY;

/** IC_CLR_STOP_DET (offset: 0x60)
  Clear STOP_DET Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_STOP_DET
  offset: 0, size: 1, access: read-only
  Read this register to clear the STOP_DET interrupt (bit 9) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_STOP_DET;

/** IC_CLR_START_DET (offset: 0x64)
  Clear START_DET Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_START_DET
  offset: 0, size: 1, access: read-only
  Read this register to clear the START_DET interrupt (bit 10) of the IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_START_DET;

/** IC_CLR_GEN_CALL (offset: 0x68)
  Clear GEN_CALL Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_GEN_CALL
  offset: 0, size: 1, access: read-only
  Read this register to clear the GEN_CALL interrupt (bit 11) of IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_GEN_CALL;

/** IC_ENABLE (offset: 0x6c)
  I2C Enable Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TX_CMD_BLOCK
  offset: 2, size: 1, access: read-write
  In Master mode: - 1&apos;b1: Blocks the transmission of data on I2C bus even if Tx FIFO has data to transmit. - 1&apos;b0: The transmission of data starts on I2C bus automatically, as soon as the first data is available in the Tx FIFO. Note: To block the execution of Master commands, set the TX_CMD_BLOCK bit only when Tx FIFO is empty (IC_STATUS[2]==1) and Master is in Idle state (IC_STATUS[5] == 0). Any further commands put in the Tx FIFO are not executed until TX_CMD_BLOCK bit is unset. Reset value: IC_TX_CMD_BLOCK_DEFAULT
  Enum:
  Value: 0 - NOT_BLOCKED : Tx Command execution not blocked
  Value: 1 - BLOCKED : Tx Command execution blocked
  Field: ABORT
  offset: 1, size: 1, access: read-write
  When set, the controller initiates the transfer abort. - 0: ABORT not initiated or ABORT done - 1: ABORT operation in progress The software can abort the I2C transfer in master mode by setting this bit. The software can set this bit only when ENABLE is already set otherwise, the controller ignores any write to ABORT bit. The software cannot clear the ABORT bit once set. In response to an ABORT, the controller issues a STOP and flushes the Tx FIFO after completing the current transfer, then sets the TX_ABORT interrupt after the abort operation. The ABORT bit is cleared automatically after the abort operation.


 For a detailed description on how to abort I2C transfers, refer to &apos;Aborting I2C Transfers&apos;.


 Reset value: 0x0
  Enum:
  Value: 0 - DISABLE : ABORT operation not in progress
  Value: 1 - ENABLED : ABORT operation in progress
  Field: ENABLE
  offset: 0, size: 1, access: read-write
  Controls whether the DW_apb_i2c is enabled. - 0: Disables DW_apb_i2c (TX and RX FIFOs are held in an erased state) - 1: Enables DW_apb_i2c Software can disable DW_apb_i2c while it is active. However, it is important that care be taken to ensure that DW_apb_i2c is disabled properly. A recommended procedure is described in &apos;Disabling DW_apb_i2c&apos;.


 When DW_apb_i2c is disabled, the following occurs: - The TX FIFO and RX FIFO get flushed. - Status bits in the IC_INTR_STAT register are still active until DW_apb_i2c goes into IDLE state. If the module is transmitting, it stops as well as deletes the contents of the transmit buffer after the current transfer is complete. If the module is receiving, the DW_apb_i2c stops the current transfer at the end of the current byte and does not acknowledge the transfer.


 In systems with asynchronous pclk and ic_clk when IC_CLK_TYPE parameter set to asynchronous (1), there is a two ic_clk delay when enabling or disabling the DW_apb_i2c. For a detailed description on how to disable DW_apb_i2c, refer to &apos;Disabling DW_apb_i2c&apos;


 Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : I2C is disabled
  Value: 1 - ENABLED : I2C is enabled
*/
volatile uint32_t IC_ENABLE;

/** IC_STATUS (offset: 0x70)
  I2C Status Register


 This is a read-only register used to indicate the current transfer status and FIFO status. The status register may be read at any time. None of the bits in this register request an interrupt.


 When the I2C is disabled by writing 0 in bit 0 of the IC_ENABLE register: - Bits 1 and 2 are set to 1 - Bits 3 and 10 are set to 0 When the master or slave state machines goes to idle and ic_en=0: - Bits 5 and 6 are set to 0
  access : read-write
  reset value : 0x6
  reset mask : 0x0
  Field: SLV_ACTIVITY
  offset: 6, size: 1, access: read-only
  Slave FSM Activity Status. When the Slave Finite State Machine (FSM) is not in the IDLE state, this bit is set. - 0: Slave FSM is in IDLE state so the Slave part of DW_apb_i2c is not Active - 1: Slave FSM is not in IDLE state so the Slave part of DW_apb_i2c is Active Reset value: 0x0
  Enum:
  Value: 0 - IDLE : Slave is idle
  Value: 1 - ACTIVE : Slave not idle
  Field: MST_ACTIVITY
  offset: 5, size: 1, access: read-only
  Master FSM Activity Status. When the Master Finite State Machine (FSM) is not in the IDLE state, this bit is set. - 0: Master FSM is in IDLE state so the Master part of DW_apb_i2c is not Active - 1: Master FSM is not in IDLE state so the Master part of DW_apb_i2c is Active Note: IC_STATUS[0]-that is, ACTIVITY bit-is the OR of SLV_ACTIVITY and MST_ACTIVITY bits.


 Reset value: 0x0
  Enum:
  Value: 0 - IDLE : Master is idle
  Value: 1 - ACTIVE : Master not idle
  Field: RFF
  offset: 4, size: 1, access: read-only
  Receive FIFO Completely Full. When the receive FIFO is completely full, this bit is set. When the receive FIFO contains one or more empty location, this bit is cleared. - 0: Receive FIFO is not full - 1: Receive FIFO is full Reset value: 0x0
  Enum:
  Value: 0 - NOT_FULL : Rx FIFO not full
  Value: 1 - FULL : Rx FIFO is full
  Field: RFNE
  offset: 3, size: 1, access: read-only
  Receive FIFO Not Empty. This bit is set when the receive FIFO contains one or more entries it is cleared when the receive FIFO is empty. - 0: Receive FIFO is empty - 1: Receive FIFO is not empty Reset value: 0x0
  Enum:
  Value: 0 - EMPTY : Rx FIFO is empty
  Value: 1 - NOT_EMPTY : Rx FIFO not empty
  Field: TFE
  offset: 2, size: 1, access: read-only
  Transmit FIFO Completely Empty. When the transmit FIFO is completely empty, this bit is set. When it contains one or more valid entries, this bit is cleared. This bit field does not request an interrupt. - 0: Transmit FIFO is not empty - 1: Transmit FIFO is empty Reset value: 0x1
  Enum:
  Value: 0 - NON_EMPTY : Tx FIFO not empty
  Value: 1 - EMPTY : Tx FIFO is empty
  Field: TFNF
  offset: 1, size: 1, access: read-only
  Transmit FIFO Not Full. Set when the transmit FIFO contains one or more empty locations, and is cleared when the FIFO is full. - 0: Transmit FIFO is full - 1: Transmit FIFO is not full Reset value: 0x1
  Enum:
  Value: 0 - FULL : Tx FIFO is full
  Value: 1 - NOT_FULL : Tx FIFO not full
  Field: ACTIVITY
  offset: 0, size: 1, access: read-only
  I2C Activity Status. Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : I2C is idle
  Value: 1 - ACTIVE : I2C is active
*/
volatile uint32_t IC_STATUS;

/** IC_TXFLR (offset: 0x74)
  I2C Transmit FIFO Level Register This register contains the number of valid data entries in the transmit FIFO buffer. It is cleared whenever: - The I2C is disabled - There is a transmit abort - that is, TX_ABRT bit is set in the IC_RAW_INTR_STAT register - The slave bulk transmit mode is aborted The register increments whenever data is placed into the transmit FIFO and decrements when data is taken from the transmit FIFO.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXFLR
  offset: 0, size: 5, access: read-only
  Transmit FIFO Level. Contains the number of valid data entries in the transmit FIFO.


 Reset value: 0x0
*/
volatile uint32_t IC_TXFLR;

/** IC_RXFLR (offset: 0x78)
  I2C Receive FIFO Level Register This register contains the number of valid data entries in the receive FIFO buffer. It is cleared whenever: - The I2C is disabled - Whenever there is a transmit abort caused by any of the events tracked in IC_TX_ABRT_SOURCE The register increments whenever data is placed into the receive FIFO and decrements when data is taken from the receive FIFO.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RXFLR
  offset: 0, size: 5, access: read-only
  Receive FIFO Level. Contains the number of valid data entries in the receive FIFO.


 Reset value: 0x0
*/
volatile uint32_t IC_RXFLR;

/** IC_SDA_HOLD (offset: 0x7c)
  I2C SDA Hold Time Length Register


 The bits [15:0] of this register are used to control the hold time of SDA during transmit in both slave and master mode (after SCL goes from HIGH to LOW).


 The bits [23:16] of this register are used to extend the SDA transition (if any) whenever SCL is HIGH in the receiver in either master or slave mode.


 Writes to this register succeed only when IC_ENABLE[0]=0.


 The values in this register are in units of ic_clk period. The value programmed in IC_SDA_TX_HOLD must be greater than the minimum hold time in each mode (one cycle in master mode, seven cycles in slave mode) for the value to be implemented.


 The programmed SDA hold time during transmit (IC_SDA_TX_HOLD) cannot exceed at any time the duration of the low part of scl. Therefore the programmed value cannot be larger than N_SCL_LOW-2, where N_SCL_LOW is the duration of the low part of the scl period measured in ic_clk cycles.
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: IC_SDA_RX_HOLD
  offset: 16, size: 8, access: read-write
  Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a receiver.


 Reset value: IC_DEFAULT_SDA_HOLD[23:16].
  Field: IC_SDA_TX_HOLD
  offset: 0, size: 16, access: read-write
  Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a transmitter.


 Reset value: IC_DEFAULT_SDA_HOLD[15:0].
*/
volatile uint32_t IC_SDA_HOLD;

/** IC_TX_ABRT_SOURCE (offset: 0x80)
  I2C Transmit Abort Source Register


 This register has 32 bits that indicate the source of the TX_ABRT bit. Except for Bit 9, this register is cleared whenever the IC_CLR_TX_ABRT register or the IC_CLR_INTR register is read. To clear Bit 9, the source of the ABRT_SBYTE_NORSTRT must be fixed first RESTART must be enabled (IC_CON[5]=1), the SPECIAL bit must be cleared (IC_TAR[11]), or the GC_OR_START bit must be cleared (IC_TAR[10]).


 Once the source of the ABRT_SBYTE_NORSTRT is fixed, then this bit can be cleared in the same manner as other bits in this register. If the source of the ABRT_SBYTE_NORSTRT is not fixed before attempting to clear this bit, Bit 9 clears for one cycle and is then re-asserted.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TX_FLUSH_CNT
  offset: 23, size: 9, access: read-only
  This field indicates the number of Tx FIFO Data Commands which are flushed due to TX_ABRT interrupt. It is cleared whenever I2C is disabled.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Slave-Transmitter
  Field: ABRT_USER_ABRT
  offset: 16, size: 1, access: read-only
  This is a master-mode-only bit. Master has detected the transfer abort (IC_ENABLE[1])


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter
  Enum:
  Value: 0 - ABRT_USER_ABRT_VOID : Transfer abort detected by master- scenario not present
  Value: 1 - ABRT_USER_ABRT_GENERATED : Transfer abort detected by master
  Field: ABRT_SLVRD_INTX
  offset: 15, size: 1, access: read-only
  1: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user writes a 1 in CMD (bit 8) of IC_DATA_CMD register.


 Reset value: 0x0


 Role of DW_apb_i2c: Slave-Transmitter
  Enum:
  Value: 0 - ABRT_SLVRD_INTX_VOID : Slave trying to transmit to remote master in read mode- scenario not present
  Value: 1 - ABRT_SLVRD_INTX_GENERATED : Slave trying to transmit to remote master in read mode
  Field: ABRT_SLV_ARBLOST
  offset: 14, size: 1, access: read-only
  This field indicates that a Slave has lost the bus while transmitting data to a remote master. IC_TX_ABRT_SOURCE[12] is set at the same time. Note: Even though the slave never &apos;owns&apos; the bus, something could go wrong on the bus. This is a fail safe check. For instance, during a data transmission at the low-to-high transition of SCL, if what is on the data bus is not what is supposed to be transmitted, then DW_apb_i2c no longer own the bus.


 Reset value: 0x0


 Role of DW_apb_i2c: Slave-Transmitter
  Enum:
  Value: 0 - ABRT_SLV_ARBLOST_VOID : Slave lost arbitration to remote master- scenario not present
  Value: 1 - ABRT_SLV_ARBLOST_GENERATED : Slave lost arbitration to remote master
  Field: ABRT_SLVFLUSH_TXFIFO
  offset: 13, size: 1, access: read-only
  This field specifies that the Slave has received a read command and some data exists in the TX FIFO, so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO.


 Reset value: 0x0


 Role of DW_apb_i2c: Slave-Transmitter
  Enum:
  Value: 0 - ABRT_SLVFLUSH_TXFIFO_VOID : Slave flushes existing data in TX-FIFO upon getting read command- scenario not present
  Value: 1 - ABRT_SLVFLUSH_TXFIFO_GENERATED : Slave flushes existing data in TX-FIFO upon getting read command
  Field: ARB_LOST
  offset: 12, size: 1, access: read-only
  This field specifies that the Master has lost arbitration, or if IC_TX_ABRT_SOURCE[14] is also set, then the slave transmitter has lost arbitration.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Slave-Transmitter
  Enum:
  Value: 0 - ABRT_LOST_VOID : Master or Slave-Transmitter lost arbitration- scenario not present
  Value: 1 - ABRT_LOST_GENERATED : Master or Slave-Transmitter lost arbitration
  Field: ABRT_MASTER_DIS
  offset: 11, size: 1, access: read-only
  This field indicates that the User tries to initiate a Master operation with the Master mode disabled.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Master-Receiver
  Enum:
  Value: 0 - ABRT_MASTER_DIS_VOID : User initiating master operation when MASTER disabled- scenario not present
  Value: 1 - ABRT_MASTER_DIS_GENERATED : User initiating master operation when MASTER disabled
  Field: ABRT_10B_RD_NORSTRT
  offset: 10, size: 1, access: read-only
  This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the master sends a read command in 10-bit addressing mode.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Receiver
  Enum:
  Value: 0 - ABRT_10B_RD_VOID : Master not trying to read in 10Bit addressing mode when RESTART disabled
  Value: 1 - ABRT_10B_RD_GENERATED : Master trying to read in 10Bit addressing mode when RESTART disabled
  Field: ABRT_SBYTE_NORSTRT
  offset: 9, size: 1, access: read-only
  To clear Bit 9, the source of the ABRT_SBYTE_NORSTRT must be fixed first restart must be enabled (IC_CON[5]=1), the SPECIAL bit must be cleared (IC_TAR[11]), or the GC_OR_START bit must be cleared (IC_TAR[10]). Once the source of the ABRT_SBYTE_NORSTRT is fixed, then this bit can be cleared in the same manner as other bits in this register. If the source of the ABRT_SBYTE_NORSTRT is not fixed before attempting to clear this bit, bit 9 clears for one cycle and then gets reasserted. When this field is set to 1, the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the user is trying to send a START Byte.


 Reset value: 0x0


 Role of DW_apb_i2c: Master
  Enum:
  Value: 0 - ABRT_SBYTE_NORSTRT_VOID : User trying to send START byte when RESTART disabled- scenario not present
  Value: 1 - ABRT_SBYTE_NORSTRT_GENERATED : User trying to send START byte when RESTART disabled
  Field: ABRT_HS_NORSTRT
  offset: 8, size: 1, access: read-only
  This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the user is trying to use the master to transfer data in High Speed mode.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Master-Receiver
  Enum:
  Value: 0 - ABRT_HS_NORSTRT_VOID : User trying to switch Master to HS mode when RESTART disabled- scenario not present
  Value: 1 - ABRT_HS_NORSTRT_GENERATED : User trying to switch Master to HS mode when RESTART disabled
  Field: ABRT_SBYTE_ACKDET
  offset: 7, size: 1, access: read-only
  This field indicates that the Master has sent a START Byte and the START Byte was acknowledged (wrong behavior).


 Reset value: 0x0


 Role of DW_apb_i2c: Master
  Enum:
  Value: 0 - ABRT_SBYTE_ACKDET_VOID : ACK detected for START byte- scenario not present
  Value: 1 - ABRT_SBYTE_ACKDET_GENERATED : ACK detected for START byte
  Field: ABRT_HS_ACKDET
  offset: 6, size: 1, access: read-only
  This field indicates that the Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior).


 Reset value: 0x0


 Role of DW_apb_i2c: Master
  Enum:
  Value: 0 - ABRT_HS_ACK_VOID : HS Master code ACKed in HS Mode- scenario not present
  Value: 1 - ABRT_HS_ACK_GENERATED : HS Master code ACKed in HS Mode
  Field: ABRT_GCALL_READ
  offset: 5, size: 1, access: read-only
  This field indicates that DW_apb_i2c in the master mode has sent a General Call but the user programmed the byte following the General Call to be a read from the bus (IC_DATA_CMD[9] is set to 1).


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter
  Enum:
  Value: 0 - ABRT_GCALL_READ_VOID : GCALL is followed by read from bus-scenario not present
  Value: 1 - ABRT_GCALL_READ_GENERATED : GCALL is followed by read from bus
  Field: ABRT_GCALL_NOACK
  offset: 4, size: 1, access: read-only
  This field indicates that DW_apb_i2c in master mode has sent a General Call and no slave on the bus acknowledged the General Call.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter
  Enum:
  Value: 0 - ABRT_GCALL_NOACK_VOID : GCALL not ACKed by any slave-scenario not present
  Value: 1 - ABRT_GCALL_NOACK_GENERATED : GCALL not ACKed by any slave
  Field: ABRT_TXDATA_NOACK
  offset: 3, size: 1, access: read-only
  This field indicates the master-mode only bit. When the master receives an acknowledgement for the address, but when it sends data byte(s) following the address, it did not receive an acknowledge from the remote slave(s).


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter
  Enum:
  Value: 0 - ABRT_TXDATA_NOACK_VOID : Transmitted data non-ACKed by addressed slave-scenario not present
  Value: 1 - ABRT_TXDATA_NOACK_GENERATED : Transmitted data not ACKed by addressed slave
  Field: ABRT_10ADDR2_NOACK
  offset: 2, size: 1, access: read-only
  This field indicates that the Master is in 10-bit address mode and that the second address byte of the 10-bit address was not acknowledged by any slave.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Master-Receiver
  Enum:
  Value: 0 - INACTIVE : This abort is not generated
  Value: 1 - ACTIVE : Byte 2 of 10Bit Address not ACKed by any slave
  Field: ABRT_10ADDR1_NOACK
  offset: 1, size: 1, access: read-only
  This field indicates that the Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Master-Receiver
  Enum:
  Value: 0 - INACTIVE : This abort is not generated
  Value: 1 - ACTIVE : Byte 1 of 10Bit Address not ACKed by any slave
  Field: ABRT_7B_ADDR_NOACK
  offset: 0, size: 1, access: read-only
  This field indicates that the Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave.


 Reset value: 0x0


 Role of DW_apb_i2c: Master-Transmitter or Master-Receiver
  Enum:
  Value: 0 - INACTIVE : This abort is not generated
  Value: 1 - ACTIVE : This abort is generated because of NOACK for 7-bit address
*/
volatile uint32_t IC_TX_ABRT_SOURCE;

/** IC_SLV_DATA_NACK_ONLY (offset: 0x84)
  Generate Slave Data NACK Register


 The register is used to generate a NACK for the data part of a transfer when DW_apb_i2c is acting as a slave-receiver. This register only exists when the IC_SLV_DATA_NACK_ONLY parameter is set to 1. When this parameter disabled, this register does not exist and writing to the register&apos;s address has no effect.


 A write can occur on this register if both of the following conditions are met: - DW_apb_i2c is disabled (IC_ENABLE[0] = 0) - Slave part is inactive (IC_STATUS[6] = 0) Note: The IC_STATUS[6] is a register read-back location for the internal slv_activity signal the user should poll this before writing the ic_slv_data_nack_only bit.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NACK
  offset: 0, size: 1, access: read-write
  Generate NACK. This NACK generation only occurs when DW_apb_i2c is a slave-receiver. If this register is set to a value of 1, it can only generate a NACK after a data byte is received hence, the data transfer is aborted and the data received is not pushed to the receive buffer.


 When the register is set to a value of 0, it generates NACK/ACK, depending on normal criteria. - 1: generate NACK after data byte received - 0: generate NACK/ACK normally Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : Slave receiver generates NACK normally
  Value: 1 - ENABLED : Slave receiver generates NACK upon data reception only
*/
volatile uint32_t IC_SLV_DATA_NACK_ONLY;

/** IC_DMA_CR (offset: 0x88)
  DMA Control Register


 The register is used to enable the DMA Controller interface operation. There is a separate bit for transmit and receive. This can be programmed regardless of the state of IC_ENABLE.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TDMAE
  offset: 1, size: 1, access: read-write
  Transmit DMA Enable. This bit enables/disables the transmit FIFO DMA channel. Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : transmit FIFO DMA channel disabled
  Value: 1 - ENABLED : Transmit FIFO DMA channel enabled
  Field: RDMAE
  offset: 0, size: 1, access: read-write
  Receive DMA Enable. This bit enables/disables the receive FIFO DMA channel. Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : Receive FIFO DMA channel disabled
  Value: 1 - ENABLED : Receive FIFO DMA channel enabled
*/
volatile uint32_t IC_DMA_CR;

/** IC_DMA_TDLR (offset: 0x8c)
  DMA Transmit Data Level Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMATDL
  offset: 0, size: 4, access: read-write
  Transmit Data Level. This bit field controls the level at which a DMA request is made by the transmit logic. It is equal to the watermark level that is, the dma_tx_req signal is generated when the number of valid data entries in the transmit FIFO is equal to or below this field value, and TDMAE = 1.


 Reset value: 0x0
*/
volatile uint32_t IC_DMA_TDLR;

/** IC_DMA_RDLR (offset: 0x90)
  I2C Receive Data Level Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMARDL
  offset: 0, size: 4, access: read-write
  Receive Data Level. This bit field controls the level at which a DMA request is made by the receive logic. The watermark level = DMARDL+1 that is, dma_rx_req is generated when the number of valid data entries in the receive FIFO is equal to or more than this field value + 1, and RDMAE =1. For instance, when DMARDL is 0, then dma_rx_req is asserted when 1 or more data entries are present in the receive FIFO.


 Reset value: 0x0
*/
volatile uint32_t IC_DMA_RDLR;

/** IC_SDA_SETUP (offset: 0x94)
  I2C SDA Setup Register


 This register controls the amount of time delay (in terms of number of ic_clk clock periods) introduced in the rising edge of SCL - relative to SDA changing - when DW_apb_i2c services a read request in a slave-transmitter operation. The relevant I2C requirement is tSU:DAT (note 4) as detailed in the I2C Bus Specification. This register must be programmed with a value equal to or greater than 2.


 Writes to this register succeed only when IC_ENABLE[0] = 0.


 Note: The length of setup time is calculated using [(IC_SDA_SETUP - 1) * (ic_clk_period)], so if the user requires 10 ic_clk periods of setup time, they should program a value of 11. The IC_SDA_SETUP register is only used by the DW_apb_i2c when operating as a slave transmitter.
  access : read-write
  reset value : 0x64
  reset mask : 0x0
  Field: SDA_SETUP
  offset: 0, size: 8, access: read-write
  SDA Setup. It is recommended that if the required delay is 1000ns, then for an ic_clk frequency of 10 MHz, IC_SDA_SETUP should be programmed to a value of 11. IC_SDA_SETUP must be programmed with a minimum value of 2.
*/
volatile uint32_t IC_SDA_SETUP;

/** IC_ACK_GENERAL_CALL (offset: 0x98)
  I2C ACK General Call Register


 The register controls whether DW_apb_i2c responds with a ACK or NACK when it receives an I2C General Call address.


 This register is applicable only when the DW_apb_i2c is in slave mode.
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: ACK_GEN_CALL
  offset: 0, size: 1, access: read-write
  ACK General Call. When set to 1, DW_apb_i2c responds with a ACK (by asserting ic_data_oe) when it receives a General Call. Otherwise, DW_apb_i2c responds with a NACK (by negating ic_data_oe).
  Enum:
  Value: 0 - DISABLED : Generate NACK for a General Call
  Value: 1 - ENABLED : Generate ACK for a General Call
*/
volatile uint32_t IC_ACK_GENERAL_CALL;

/** IC_ENABLE_STATUS (offset: 0x9c)
  I2C Enable Status Register


 The register is used to report the DW_apb_i2c hardware status when the IC_ENABLE[0] register is set from 1 to 0 that is, when DW_apb_i2c is disabled.


 If IC_ENABLE[0] has been set to 1, bits 2:1 are forced to 0, and bit 0 is forced to 1.


 If IC_ENABLE[0] has been set to 0, bits 2:1 is only be valid as soon as bit 0 is read as &apos;0&apos;.


 Note: When IC_ENABLE[0] has been set to 0, a delay occurs for bit 0 to be read as 0 because disabling the DW_apb_i2c depends on I2C bus activities.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SLV_RX_DATA_LOST
  offset: 2, size: 1, access: read-only
  Slave Received Data Lost. This bit indicates if a Slave-Receiver operation has been aborted with at least one data byte received from an I2C transfer due to the setting bit 0 of IC_ENABLE from 1 to 0. When read as 1, DW_apb_i2c is deemed to have been actively engaged in an aborted I2C transfer (with matching address) and the data phase of the I2C transfer has been entered, even though a data byte has been responded with a NACK.


 Note: If the remote I2C master terminates the transfer with a STOP condition before the DW_apb_i2c has a chance to NACK a transfer, and IC_ENABLE[0] has been set to 0, then this bit is also set to 1.


 When read as 0, DW_apb_i2c is deemed to have been disabled without being actively involved in the data phase of a Slave-Receiver transfer.


 Note: The CPU can safely read this bit when IC_EN (bit 0) is read as 0.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : Slave RX Data is not lost
  Value: 1 - ACTIVE : Slave RX Data is lost
  Field: SLV_DISABLED_WHILE_BUSY
  offset: 1, size: 1, access: read-only
  Slave Disabled While Busy (Transmit, Receive). This bit indicates if a potential or active Slave operation has been aborted due to the setting bit 0 of the IC_ENABLE register from 1 to 0. This bit is set when the CPU writes a 0 to the IC_ENABLE register while:


 (a) DW_apb_i2c is receiving the address byte of the Slave-Transmitter operation from a remote master 


 OR,


 (b) address and data bytes of the Slave-Receiver operation from a remote master.


 When read as 1, DW_apb_i2c is deemed to have forced a NACK during any part of an I2C transfer, irrespective of whether the I2C address matches the slave address set in DW_apb_i2c (IC_SAR register) OR if the transfer is completed before IC_ENABLE is set to 0 but has not taken effect.


 Note: If the remote I2C master terminates the transfer with a STOP condition before the DW_apb_i2c has a chance to NACK a transfer, and IC_ENABLE[0] has been set to 0, then this bit will also be set to 1.


 When read as 0, DW_apb_i2c is deemed to have been disabled when there is master activity, or when the I2C bus is idle.


 Note: The CPU can safely read this bit when IC_EN (bit 0) is read as 0.


 Reset value: 0x0
  Enum:
  Value: 0 - INACTIVE : Slave is disabled when it is idle
  Value: 1 - ACTIVE : Slave is disabled when it is active
  Field: IC_EN
  offset: 0, size: 1, access: read-only
  ic_en Status. This bit always reflects the value driven on the output port ic_en. - When read as 1, DW_apb_i2c is deemed to be in an enabled state. - When read as 0, DW_apb_i2c is deemed completely inactive. Note: The CPU can safely read this bit anytime. When this bit is read as 0, the CPU can safely read SLV_RX_DATA_LOST (bit 2) and SLV_DISABLED_WHILE_BUSY (bit 1).


 Reset value: 0x0
  Enum:
  Value: 0 - DISABLED : I2C disabled
  Value: 1 - ENABLED : I2C enabled
*/
volatile uint32_t IC_ENABLE_STATUS;

/** IC_FS_SPKLEN (offset: 0xa0)
  I2C SS, FS or FM+ spike suppression limit


 This register is used to store the duration, measured in ic_clk cycles, of the longest spike that is filtered out by the spike suppression logic when the component is operating in SS, FS or FM+ modes. The relevant I2C requirement is tSP (table 4) as detailed in the I2C Bus Specification. This register must be programmed with a minimum value of 1.
  access : read-write
  reset value : 0x7
  reset mask : 0x0
  Field: IC_FS_SPKLEN
  offset: 0, size: 8, access: read-write
  This register must be set before any I2C bus transaction can take place to ensure stable operation. This register sets the duration, measured in ic_clk cycles, of the longest spike in the SCL or SDA lines that will be filtered out by the spike suppression logic. This register can be written only when the I2C interface is disabled which corresponds to the IC_ENABLE[0] register being set to 0. Writes at other times have no effect. The minimum valid value is 1 hardware prevents values less than this being written, and if attempted results in 1 being set. or more information, refer to &apos;Spike Suppression&apos;.
*/
volatile uint32_t IC_FS_SPKLEN;
volatile uint32_t reserved2;

/** IC_CLR_RESTART_DET (offset: 0xa8)
  Clear RESTART_DET Interrupt Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLR_RESTART_DET
  offset: 0, size: 1, access: read-only
  Read this register to clear the RESTART_DET interrupt (bit 12) of IC_RAW_INTR_STAT register.


 Reset value: 0x0
*/
volatile uint32_t IC_CLR_RESTART_DET;
volatile uint32_t reserved3[18];

/** IC_COMP_PARAM_1 (offset: 0xf4)
  Component Parameter Register 1


 Note This register is not implemented and therefore reads as 0. If it was implemented it would be a constant read-only register that contains encoded information about the component&apos;s parameter settings. Fields shown below are the settings for those parameters
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TX_BUFFER_DEPTH
  offset: 16, size: 8, access: read-only
  TX Buffer Depth = 16
  Field: RX_BUFFER_DEPTH
  offset: 8, size: 8, access: read-only
  RX Buffer Depth = 16
  Field: ADD_ENCODED_PARAMS
  offset: 7, size: 1, access: read-only
  Encoded parameters not visible
  Field: HAS_DMA
  offset: 6, size: 1, access: read-only
  DMA handshaking signals are enabled
  Field: INTR_IO
  offset: 5, size: 1, access: read-only
  COMBINED Interrupt outputs
  Field: HC_COUNT_VALUES
  offset: 4, size: 1, access: read-only
  Programmable count values for each mode.
  Field: MAX_SPEED_MODE
  offset: 2, size: 2, access: read-only
  MAX SPEED MODE = FAST MODE
  Field: APB_DATA_WIDTH
  offset: 0, size: 2, access: read-only
  APB data bus width is 32 bits
*/
volatile uint32_t IC_COMP_PARAM_1;

/** IC_COMP_VERSION (offset: 0xf8)
  I2C Component Version Register
  access : read-write
  reset value : 0x3230312A
  reset mask : 0x0
  Field: IC_COMP_VERSION
  offset: 0, size: 32, access: read-only
*/
volatile uint32_t IC_COMP_VERSION;

/** IC_COMP_TYPE (offset: 0xfc)
  I2C Component Type Register
  access : read-write
  reset value : 0x44570140
  reset mask : 0x0
  Field: IC_COMP_TYPE
  offset: 0, size: 32, access: read-only
  Designware Component Type number = 0x44_57_01_40. This assigned unique hex value is constant and is derived from the two ASCII letters &apos;DW&apos; followed by a 16-bit unsigned number.
*/
volatile uint32_t IC_COMP_TYPE;
} I2C_type;

#define I2C0 ((I2C_type *) 0x40044000)
#define I2C1 ((I2C_type *) 0x40048000)

#endif // HW_I2C_H
