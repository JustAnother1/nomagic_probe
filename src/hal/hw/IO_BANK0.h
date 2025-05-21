/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_IO_BANK0_H
#define HW_IO_BANK0_H
/** Interrupt : IO_IRQ_BANK0 (Vector: 13)  */
/** Memory Block starting at 0x40014000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define IO_BANK0_GPIO0_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO0_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO0_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO0_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO0_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO0_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO0_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO0_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO0_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO0_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO0_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO0_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO0_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO0_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO0_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO0_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO0_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO0_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO0_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO0_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO0_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO0_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO0_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO0_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO0_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO0_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO0_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO0_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO0_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO0_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO0_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_JTAG_TCK               0u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_SPI0_RX                1u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_UART0_TX               2u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_I2C0_SDA               3u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PWM_A_0                4u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_SIO_0                  5u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PIO0_0                 6u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PIO1_0                 7u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO1_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO1_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO1_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO1_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO1_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO1_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO1_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO1_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO1_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO1_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO1_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO1_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO1_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO1_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO1_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO1_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO1_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO1_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO1_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO1_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO1_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO1_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO1_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO1_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO1_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO1_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO1_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO1_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO1_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO1_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO1_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_JTAG_TMS               0u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_SPI0_SS_N              1u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_UART0_RX               2u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_I2C0_SCL               3u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PWM_B_0                4u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_SIO_1                  5u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PIO0_1                 6u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PIO1_1                 7u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO2_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO2_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO2_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO2_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO2_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO2_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO2_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO2_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO2_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO2_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO2_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO2_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO2_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO2_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO2_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO2_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO2_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO2_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO2_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO2_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO2_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO2_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO2_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO2_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO2_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO2_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO2_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO2_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO2_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO2_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO2_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_JTAG_TDI               0u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_SPI0_SCLK              1u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_UART0_CTS              2u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_I2C1_SDA               3u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PWM_A_1                4u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_SIO_2                  5u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PIO0_2                 6u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PIO1_2                 7u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_USB_MUXING_VBUS_EN     9u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO3_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO3_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO3_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO3_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO3_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO3_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO3_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO3_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO3_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO3_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO3_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO3_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO3_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO3_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO3_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO3_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO3_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO3_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO3_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO3_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO3_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO3_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO3_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO3_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO3_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO3_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO3_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO3_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO3_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO3_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO3_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_JTAG_TDO               0u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_SPI0_TX                1u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_UART0_RTS              2u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_I2C1_SCL               3u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PWM_B_1                4u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_SIO_3                  5u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PIO0_3                 6u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PIO1_3                 7u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO4_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO4_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO4_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO4_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO4_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO4_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO4_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO4_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO4_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO4_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO4_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO4_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO4_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO4_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO4_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO4_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO4_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO4_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO4_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO4_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO4_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO4_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO4_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO4_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO4_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO4_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO4_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO4_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO4_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO4_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO4_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_SPI0_RX                1u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX               2u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_I2C0_SDA               3u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PWM_A_2                4u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_SIO_4                  5u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PIO0_4                 6u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PIO1_4                 7u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO5_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO5_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO5_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO5_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO5_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO5_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO5_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO5_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO5_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO5_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO5_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO5_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO5_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO5_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO5_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO5_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO5_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO5_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO5_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO5_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO5_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO5_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO5_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO5_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO5_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO5_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO5_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO5_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO5_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO5_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO5_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_SPI0_SS_N              1u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX               2u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_I2C0_SCL               3u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PWM_B_2                4u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_SIO_5                  5u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PIO0_5                 6u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PIO1_5                 7u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_USB_MUXING_VBUS_EN     9u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO6_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO6_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO6_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO6_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO6_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO6_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO6_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO6_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO6_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO6_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO6_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO6_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO6_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO6_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO6_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO6_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO6_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO6_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO6_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO6_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO6_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO6_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO6_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO6_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO6_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO6_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO6_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO6_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO6_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO6_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO6_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_SPI0_SCLK              1u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_UART1_CTS              2u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_I2C1_SDA               3u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PWM_A_3                4u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_SIO_6                  5u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PIO0_6                 6u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PIO1_6                 7u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SOFTCON   8
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO7_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO7_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO7_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO7_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO7_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO7_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO7_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO7_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO7_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO7_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO7_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO7_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO7_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO7_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO7_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO7_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO7_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO7_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO7_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO7_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO7_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO7_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO7_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO7_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO7_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO7_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO7_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO7_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO7_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO7_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO7_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_SPI0_TX                1u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_UART1_RTS              2u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_I2C1_SCL               3u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PWM_B_3                4u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_SIO_7                  5u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PIO0_7                 6u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PIO1_7                 7u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_USB_MUXING_EXTPHY_OE_N   8
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO8_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO8_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO8_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO8_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO8_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO8_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO8_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO8_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO8_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO8_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO8_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO8_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO8_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO8_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO8_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO8_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO8_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO8_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO8_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO8_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO8_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO8_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO8_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO8_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO8_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO8_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO8_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO8_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO8_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO8_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO8_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_SPI1_RX                1u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_UART1_TX               2u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_I2C0_SDA               3u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PWM_A_4                4u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_SIO_8                  5u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PIO0_8                 6u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PIO1_8                 7u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_USB_MUXING_EXTPHY_RCV  8u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_USB_MUXING_VBUS_EN     9u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO9_STATUS_IRQTOPROC_OFFSET             26u
#define IO_BANK0_GPIO9_STATUS_IRQTOPROC_MASK               0x4000000u

#define IO_BANK0_GPIO9_STATUS_IRQFROMPAD_OFFSET            24u
#define IO_BANK0_GPIO9_STATUS_IRQFROMPAD_MASK              0x1000000u

#define IO_BANK0_GPIO9_STATUS_INTOPERI_OFFSET              19u
#define IO_BANK0_GPIO9_STATUS_INTOPERI_MASK                0x80000u

#define IO_BANK0_GPIO9_STATUS_INFROMPAD_OFFSET             17u
#define IO_BANK0_GPIO9_STATUS_INFROMPAD_MASK               0x20000u

#define IO_BANK0_GPIO9_STATUS_OETOPAD_OFFSET               13u
#define IO_BANK0_GPIO9_STATUS_OETOPAD_MASK                 0x2000u

#define IO_BANK0_GPIO9_STATUS_OEFROMPERI_OFFSET            12u
#define IO_BANK0_GPIO9_STATUS_OEFROMPERI_MASK              0x1000u

#define IO_BANK0_GPIO9_STATUS_OUTTOPAD_OFFSET              9u
#define IO_BANK0_GPIO9_STATUS_OUTTOPAD_MASK                0x200u

#define IO_BANK0_GPIO9_STATUS_OUTFROMPERI_OFFSET           8u
#define IO_BANK0_GPIO9_STATUS_OUTFROMPERI_MASK             0x100u

#define IO_BANK0_GPIO9_CTRL_IRQOVER_OFFSET                 28u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_MASK                   0x30000000u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_NORMAL                 0u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_INVERT                 1u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_LOW                    2u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_HIGH                   3u

#define IO_BANK0_GPIO9_CTRL_INOVER_OFFSET                  16u
#define IO_BANK0_GPIO9_CTRL_INOVER_MASK                    0x30000u
#define IO_BANK0_GPIO9_CTRL_INOVER_NORMAL                  0u
#define IO_BANK0_GPIO9_CTRL_INOVER_INVERT                  1u
#define IO_BANK0_GPIO9_CTRL_INOVER_LOW                     2u
#define IO_BANK0_GPIO9_CTRL_INOVER_HIGH                    3u

#define IO_BANK0_GPIO9_CTRL_OEOVER_OFFSET                  12u
#define IO_BANK0_GPIO9_CTRL_OEOVER_MASK                    0x3000u
#define IO_BANK0_GPIO9_CTRL_OEOVER_NORMAL                  0u
#define IO_BANK0_GPIO9_CTRL_OEOVER_INVERT                  1u
#define IO_BANK0_GPIO9_CTRL_OEOVER_DISABLE                 2u
#define IO_BANK0_GPIO9_CTRL_OEOVER_ENABLE                  3u

#define IO_BANK0_GPIO9_CTRL_OUTOVER_OFFSET                 8u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_MASK                   0x300u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_NORMAL                 0u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_INVERT                 1u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_LOW                    2u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_HIGH                   3u

#define IO_BANK0_GPIO9_CTRL_FUNCSEL_OFFSET                 0u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_MASK                   0x1fu
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_SPI1_SS_N              1u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_UART1_RX               2u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_I2C0_SCL               3u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PWM_B_4                4u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_SIO_9                  5u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PIO0_9                 6u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PIO1_9                 7u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VP   8u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_NULL                   0x1fu

#define IO_BANK0_GPIO10_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO10_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO10_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO10_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO10_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO10_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO10_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO10_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO10_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO10_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO10_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO10_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO10_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO10_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO10_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO10_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO10_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO10_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO10_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO10_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO10_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO10_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO10_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO10_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO10_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO10_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO10_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO10_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO10_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO10_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO10_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_SPI1_SCLK             1u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_UART1_CTS             2u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_I2C1_SDA              3u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PWM_A_5               4u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_SIO_10                5u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PIO0_10               6u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PIO1_10               7u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VM  8u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO11_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO11_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO11_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO11_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO11_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO11_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO11_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO11_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO11_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO11_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO11_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO11_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO11_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO11_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO11_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO11_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO11_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO11_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO11_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO11_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO11_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO11_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO11_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO11_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO11_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO11_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO11_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO11_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO11_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO11_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO11_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_SPI1_TX               1u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_UART1_RTS             2u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_I2C1_SCL              3u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PWM_B_5               4u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_SIO_11                5u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PIO0_11               6u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PIO1_11               7u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SUSPND   8
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO12_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO12_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO12_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO12_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO12_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO12_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO12_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO12_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO12_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO12_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO12_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO12_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO12_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO12_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO12_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO12_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO12_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO12_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO12_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO12_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO12_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO12_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO12_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO12_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO12_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO12_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO12_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO12_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO12_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO12_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO12_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_SPI1_RX               1u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_UART0_TX              2u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_I2C0_SDA              3u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PWM_A_6               4u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_SIO_12                5u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PIO0_12               6u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PIO1_12               7u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SPEED   8
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO13_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO13_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO13_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO13_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO13_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO13_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO13_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO13_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO13_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO13_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO13_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO13_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO13_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO13_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO13_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO13_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO13_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO13_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO13_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO13_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO13_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO13_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO13_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO13_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO13_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO13_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO13_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO13_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO13_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO13_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO13_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_SPI1_SS_N             1u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_UART0_RX              2u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_I2C0_SCL              3u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PWM_B_6               4u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_SIO_13                5u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PIO0_13               6u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PIO1_13               7u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VPO   8
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO14_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO14_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO14_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO14_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO14_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO14_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO14_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO14_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO14_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO14_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO14_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO14_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO14_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO14_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO14_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO14_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO14_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO14_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO14_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO14_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO14_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO14_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO14_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO14_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO14_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO14_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO14_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO14_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO14_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO14_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO14_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_SPI1_SCLK             1u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_UART0_CTS             2u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_I2C1_SDA              3u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PWM_A_7               4u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_SIO_14                5u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PIO0_14               6u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PIO1_14               7u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VMO   8
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO15_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO15_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO15_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO15_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO15_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO15_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO15_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO15_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO15_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO15_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO15_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO15_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO15_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO15_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO15_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO15_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO15_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO15_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO15_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO15_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO15_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO15_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO15_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO15_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO15_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO15_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO15_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO15_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO15_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO15_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO15_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_SPI1_TX               1u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_UART0_RTS             2u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_I2C1_SCL              3u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PWM_B_7               4u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_SIO_15                5u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PIO0_15               6u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PIO1_15               7u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_USB_MUXING_DIGITAL_DP   8
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO16_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO16_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO16_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO16_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO16_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO16_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO16_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO16_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO16_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO16_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO16_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO16_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO16_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO16_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO16_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO16_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO16_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO16_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO16_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO16_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO16_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO16_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO16_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO16_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO16_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO16_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO16_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO16_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO16_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO16_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO16_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_SPI0_RX               1u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_UART0_TX              2u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_I2C0_SDA              3u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PWM_A_0               4u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_SIO_16                5u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PIO0_16               6u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PIO1_16               7u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_USB_MUXING_DIGITAL_DM   8
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO17_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO17_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO17_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO17_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO17_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO17_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO17_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO17_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO17_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO17_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO17_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO17_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO17_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO17_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO17_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO17_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO17_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO17_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO17_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO17_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO17_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO17_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO17_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO17_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO17_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO17_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO17_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO17_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO17_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO17_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO17_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_SPI0_SS_N             1u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_UART0_RX              2u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_I2C0_SCL              3u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PWM_B_0               4u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_SIO_17                5u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PIO0_17               6u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PIO1_17               7u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO18_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO18_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO18_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO18_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO18_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO18_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO18_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO18_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO18_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO18_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO18_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO18_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO18_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO18_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO18_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO18_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO18_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO18_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO18_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO18_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO18_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO18_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO18_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO18_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO18_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO18_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO18_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO18_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO18_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO18_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO18_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_SPI0_SCLK             1u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_UART0_CTS             2u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_I2C1_SDA              3u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PWM_A_1               4u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_SIO_18                5u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PIO0_18               6u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PIO1_18               7u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO19_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO19_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO19_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO19_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO19_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO19_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO19_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO19_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO19_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO19_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO19_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO19_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO19_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO19_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO19_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO19_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO19_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO19_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO19_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO19_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO19_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO19_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO19_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO19_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO19_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO19_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO19_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO19_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO19_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO19_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO19_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_SPI0_TX               1u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_UART0_RTS             2u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_I2C1_SCL              3u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PWM_B_1               4u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_SIO_19                5u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PIO0_19               6u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PIO1_19               7u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO20_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO20_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO20_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO20_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO20_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO20_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO20_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO20_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO20_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO20_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO20_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO20_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO20_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO20_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO20_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO20_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO20_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO20_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO20_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO20_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO20_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO20_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO20_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO20_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO20_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO20_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO20_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO20_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO20_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO20_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO20_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_SPI0_RX               1u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_UART1_TX              2u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_I2C0_SDA              3u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PWM_A_2               4u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_SIO_20                5u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PIO0_20               6u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PIO1_20               7u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_CLOCKS_GPIN_0         8u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO21_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO21_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO21_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO21_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO21_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO21_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO21_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO21_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO21_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO21_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO21_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO21_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO21_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO21_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO21_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO21_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO21_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO21_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO21_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO21_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO21_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO21_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO21_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO21_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO21_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO21_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO21_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO21_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO21_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO21_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO21_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_SPI0_SS_N             1u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_UART1_RX              2u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_I2C0_SCL              3u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PWM_B_2               4u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_SIO_21                5u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PIO0_21               6u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PIO1_21               7u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_CLOCKS_GPOUT_0        8u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO22_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO22_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO22_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO22_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO22_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO22_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO22_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO22_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO22_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO22_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO22_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO22_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO22_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO22_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO22_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO22_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO22_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO22_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO22_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO22_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO22_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO22_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO22_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO22_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO22_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO22_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO22_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO22_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO22_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO22_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO22_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_SPI0_SCLK             1u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_UART1_CTS             2u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_I2C1_SDA              3u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PWM_A_3               4u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_SIO_22                5u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PIO0_22               6u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PIO1_22               7u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_CLOCKS_GPIN_1         8u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO23_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO23_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO23_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO23_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO23_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO23_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO23_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO23_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO23_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO23_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO23_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO23_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO23_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO23_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO23_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO23_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO23_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO23_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO23_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO23_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO23_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO23_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO23_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO23_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO23_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO23_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO23_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO23_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO23_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO23_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO23_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_SPI0_TX               1u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_UART1_RTS             2u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_I2C1_SCL              3u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PWM_B_3               4u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_SIO_23                5u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PIO0_23               6u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PIO1_23               7u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_CLOCKS_GPOUT_1        8u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO24_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO24_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO24_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO24_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO24_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO24_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO24_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO24_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO24_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO24_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO24_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO24_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO24_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO24_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO24_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO24_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO24_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO24_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO24_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO24_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO24_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO24_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO24_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO24_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO24_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO24_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO24_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO24_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO24_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO24_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO24_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_SPI1_RX               1u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_UART1_TX              2u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_I2C0_SDA              3u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PWM_A_4               4u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_SIO_24                5u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PIO0_24               6u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PIO1_24               7u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_CLOCKS_GPOUT_2        8u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO25_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO25_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO25_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO25_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO25_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO25_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO25_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO25_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO25_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO25_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO25_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO25_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO25_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO25_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO25_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO25_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO25_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO25_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO25_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO25_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO25_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO25_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO25_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO25_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO25_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO25_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO25_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO25_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO25_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO25_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO25_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_SPI1_SS_N             1u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_UART1_RX              2u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_I2C0_SCL              3u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PWM_B_4               4u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_SIO_25                5u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PIO0_25               6u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PIO1_25               7u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_CLOCKS_GPOUT_3        8u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO26_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO26_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO26_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO26_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO26_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO26_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO26_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO26_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO26_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO26_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO26_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO26_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO26_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO26_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO26_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO26_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO26_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO26_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO26_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO26_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO26_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO26_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO26_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO26_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO26_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO26_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO26_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO26_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO26_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO26_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO26_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_SPI1_SCLK             1u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_UART1_CTS             2u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_I2C1_SDA              3u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PWM_A_5               4u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_SIO_26                5u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PIO0_26               6u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PIO1_26               7u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO27_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO27_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO27_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO27_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO27_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO27_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO27_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO27_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO27_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO27_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO27_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO27_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO27_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO27_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO27_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO27_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO27_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO27_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO27_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO27_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO27_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO27_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO27_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO27_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO27_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO27_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO27_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO27_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO27_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO27_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO27_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_SPI1_TX               1u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_UART1_RTS             2u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_I2C1_SCL              3u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PWM_B_5               4u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_SIO_27                5u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PIO0_27               6u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PIO1_27               7u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT   9
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO28_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO28_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO28_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO28_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO28_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO28_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO28_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO28_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO28_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO28_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO28_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO28_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO28_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO28_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO28_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO28_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO28_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO28_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO28_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO28_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO28_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO28_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO28_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO28_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO28_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO28_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO28_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO28_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO28_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO28_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO28_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_SPI1_RX               1u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_UART0_TX              2u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_I2C0_SDA              3u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PWM_A_6               4u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_SIO_28                5u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PIO0_28               6u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PIO1_28               7u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT   9
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_GPIO29_STATUS_IRQTOPROC_OFFSET            26u
#define IO_BANK0_GPIO29_STATUS_IRQTOPROC_MASK              0x4000000u

#define IO_BANK0_GPIO29_STATUS_IRQFROMPAD_OFFSET           24u
#define IO_BANK0_GPIO29_STATUS_IRQFROMPAD_MASK             0x1000000u

#define IO_BANK0_GPIO29_STATUS_INTOPERI_OFFSET             19u
#define IO_BANK0_GPIO29_STATUS_INTOPERI_MASK               0x80000u

#define IO_BANK0_GPIO29_STATUS_INFROMPAD_OFFSET            17u
#define IO_BANK0_GPIO29_STATUS_INFROMPAD_MASK              0x20000u

#define IO_BANK0_GPIO29_STATUS_OETOPAD_OFFSET              13u
#define IO_BANK0_GPIO29_STATUS_OETOPAD_MASK                0x2000u

#define IO_BANK0_GPIO29_STATUS_OEFROMPERI_OFFSET           12u
#define IO_BANK0_GPIO29_STATUS_OEFROMPERI_MASK             0x1000u

#define IO_BANK0_GPIO29_STATUS_OUTTOPAD_OFFSET             9u
#define IO_BANK0_GPIO29_STATUS_OUTTOPAD_MASK               0x200u

#define IO_BANK0_GPIO29_STATUS_OUTFROMPERI_OFFSET          8u
#define IO_BANK0_GPIO29_STATUS_OUTFROMPERI_MASK            0x100u

#define IO_BANK0_GPIO29_CTRL_IRQOVER_OFFSET                28u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_MASK                  0x30000000u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_NORMAL                0u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_INVERT                1u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_LOW                   2u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_HIGH                  3u

#define IO_BANK0_GPIO29_CTRL_INOVER_OFFSET                 16u
#define IO_BANK0_GPIO29_CTRL_INOVER_MASK                   0x30000u
#define IO_BANK0_GPIO29_CTRL_INOVER_NORMAL                 0u
#define IO_BANK0_GPIO29_CTRL_INOVER_INVERT                 1u
#define IO_BANK0_GPIO29_CTRL_INOVER_LOW                    2u
#define IO_BANK0_GPIO29_CTRL_INOVER_HIGH                   3u

#define IO_BANK0_GPIO29_CTRL_OEOVER_OFFSET                 12u
#define IO_BANK0_GPIO29_CTRL_OEOVER_MASK                   0x3000u
#define IO_BANK0_GPIO29_CTRL_OEOVER_NORMAL                 0u
#define IO_BANK0_GPIO29_CTRL_OEOVER_INVERT                 1u
#define IO_BANK0_GPIO29_CTRL_OEOVER_DISABLE                2u
#define IO_BANK0_GPIO29_CTRL_OEOVER_ENABLE                 3u

#define IO_BANK0_GPIO29_CTRL_OUTOVER_OFFSET                8u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_MASK                  0x300u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_NORMAL                0u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_INVERT                1u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_LOW                   2u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_HIGH                  3u

#define IO_BANK0_GPIO29_CTRL_FUNCSEL_OFFSET                0u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_MASK                  0x1fu
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_SPI1_SS_N             1u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_UART0_RX              2u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_I2C0_SCL              3u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PWM_B_6               4u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_SIO_29                5u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PIO0_29               6u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PIO1_29               7u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_USB_MUXING_VBUS_EN    9u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_NULL                  0x1fu

#define IO_BANK0_INTR0_GPIO7_EDGE_HIGH_OFFSET              31u
#define IO_BANK0_INTR0_GPIO7_EDGE_HIGH_MASK                0x80000000u

#define IO_BANK0_INTR0_GPIO7_EDGE_LOW_OFFSET               30u
#define IO_BANK0_INTR0_GPIO7_EDGE_LOW_MASK                 0x40000000u

#define IO_BANK0_INTR0_GPIO7_LEVEL_HIGH_OFFSET             29u
#define IO_BANK0_INTR0_GPIO7_LEVEL_HIGH_MASK               0x20000000u

#define IO_BANK0_INTR0_GPIO7_LEVEL_LOW_OFFSET              28u
#define IO_BANK0_INTR0_GPIO7_LEVEL_LOW_MASK                0x10000000u

#define IO_BANK0_INTR0_GPIO6_EDGE_HIGH_OFFSET              27u
#define IO_BANK0_INTR0_GPIO6_EDGE_HIGH_MASK                0x8000000u

#define IO_BANK0_INTR0_GPIO6_EDGE_LOW_OFFSET               26u
#define IO_BANK0_INTR0_GPIO6_EDGE_LOW_MASK                 0x4000000u

#define IO_BANK0_INTR0_GPIO6_LEVEL_HIGH_OFFSET             25u
#define IO_BANK0_INTR0_GPIO6_LEVEL_HIGH_MASK               0x2000000u

#define IO_BANK0_INTR0_GPIO6_LEVEL_LOW_OFFSET              24u
#define IO_BANK0_INTR0_GPIO6_LEVEL_LOW_MASK                0x1000000u

#define IO_BANK0_INTR0_GPIO5_EDGE_HIGH_OFFSET              23u
#define IO_BANK0_INTR0_GPIO5_EDGE_HIGH_MASK                0x800000u

#define IO_BANK0_INTR0_GPIO5_EDGE_LOW_OFFSET               22u
#define IO_BANK0_INTR0_GPIO5_EDGE_LOW_MASK                 0x400000u

#define IO_BANK0_INTR0_GPIO5_LEVEL_HIGH_OFFSET             21u
#define IO_BANK0_INTR0_GPIO5_LEVEL_HIGH_MASK               0x200000u

#define IO_BANK0_INTR0_GPIO5_LEVEL_LOW_OFFSET              20u
#define IO_BANK0_INTR0_GPIO5_LEVEL_LOW_MASK                0x100000u

#define IO_BANK0_INTR0_GPIO4_EDGE_HIGH_OFFSET              19u
#define IO_BANK0_INTR0_GPIO4_EDGE_HIGH_MASK                0x80000u

#define IO_BANK0_INTR0_GPIO4_EDGE_LOW_OFFSET               18u
#define IO_BANK0_INTR0_GPIO4_EDGE_LOW_MASK                 0x40000u

#define IO_BANK0_INTR0_GPIO4_LEVEL_HIGH_OFFSET             17u
#define IO_BANK0_INTR0_GPIO4_LEVEL_HIGH_MASK               0x20000u

#define IO_BANK0_INTR0_GPIO4_LEVEL_LOW_OFFSET              16u
#define IO_BANK0_INTR0_GPIO4_LEVEL_LOW_MASK                0x10000u

#define IO_BANK0_INTR0_GPIO3_EDGE_HIGH_OFFSET              15u
#define IO_BANK0_INTR0_GPIO3_EDGE_HIGH_MASK                0x8000u

#define IO_BANK0_INTR0_GPIO3_EDGE_LOW_OFFSET               14u
#define IO_BANK0_INTR0_GPIO3_EDGE_LOW_MASK                 0x4000u

#define IO_BANK0_INTR0_GPIO3_LEVEL_HIGH_OFFSET             13u
#define IO_BANK0_INTR0_GPIO3_LEVEL_HIGH_MASK               0x2000u

#define IO_BANK0_INTR0_GPIO3_LEVEL_LOW_OFFSET              12u
#define IO_BANK0_INTR0_GPIO3_LEVEL_LOW_MASK                0x1000u

#define IO_BANK0_INTR0_GPIO2_EDGE_HIGH_OFFSET              11u
#define IO_BANK0_INTR0_GPIO2_EDGE_HIGH_MASK                0x800u

#define IO_BANK0_INTR0_GPIO2_EDGE_LOW_OFFSET               10u
#define IO_BANK0_INTR0_GPIO2_EDGE_LOW_MASK                 0x400u

#define IO_BANK0_INTR0_GPIO2_LEVEL_HIGH_OFFSET             9u
#define IO_BANK0_INTR0_GPIO2_LEVEL_HIGH_MASK               0x200u

#define IO_BANK0_INTR0_GPIO2_LEVEL_LOW_OFFSET              8u
#define IO_BANK0_INTR0_GPIO2_LEVEL_LOW_MASK                0x100u

#define IO_BANK0_INTR0_GPIO1_EDGE_HIGH_OFFSET              7u
#define IO_BANK0_INTR0_GPIO1_EDGE_HIGH_MASK                0x80u

#define IO_BANK0_INTR0_GPIO1_EDGE_LOW_OFFSET               6u
#define IO_BANK0_INTR0_GPIO1_EDGE_LOW_MASK                 0x40u

#define IO_BANK0_INTR0_GPIO1_LEVEL_HIGH_OFFSET             5u
#define IO_BANK0_INTR0_GPIO1_LEVEL_HIGH_MASK               0x20u

#define IO_BANK0_INTR0_GPIO1_LEVEL_LOW_OFFSET              4u
#define IO_BANK0_INTR0_GPIO1_LEVEL_LOW_MASK                0x10u

#define IO_BANK0_INTR0_GPIO0_EDGE_HIGH_OFFSET              3u
#define IO_BANK0_INTR0_GPIO0_EDGE_HIGH_MASK                8u

#define IO_BANK0_INTR0_GPIO0_EDGE_LOW_OFFSET               2u
#define IO_BANK0_INTR0_GPIO0_EDGE_LOW_MASK                 4u

#define IO_BANK0_INTR0_GPIO0_LEVEL_HIGH_OFFSET             1u
#define IO_BANK0_INTR0_GPIO0_LEVEL_HIGH_MASK               2u

#define IO_BANK0_INTR0_GPIO0_LEVEL_LOW_OFFSET              0u
#define IO_BANK0_INTR0_GPIO0_LEVEL_LOW_MASK                1u

#define IO_BANK0_INTR1_GPIO15_EDGE_HIGH_OFFSET             31u
#define IO_BANK0_INTR1_GPIO15_EDGE_HIGH_MASK               0x80000000u

#define IO_BANK0_INTR1_GPIO15_EDGE_LOW_OFFSET              30u
#define IO_BANK0_INTR1_GPIO15_EDGE_LOW_MASK                0x40000000u

#define IO_BANK0_INTR1_GPIO15_LEVEL_HIGH_OFFSET            29u
#define IO_BANK0_INTR1_GPIO15_LEVEL_HIGH_MASK              0x20000000u

#define IO_BANK0_INTR1_GPIO15_LEVEL_LOW_OFFSET             28u
#define IO_BANK0_INTR1_GPIO15_LEVEL_LOW_MASK               0x10000000u

#define IO_BANK0_INTR1_GPIO14_EDGE_HIGH_OFFSET             27u
#define IO_BANK0_INTR1_GPIO14_EDGE_HIGH_MASK               0x8000000u

#define IO_BANK0_INTR1_GPIO14_EDGE_LOW_OFFSET              26u
#define IO_BANK0_INTR1_GPIO14_EDGE_LOW_MASK                0x4000000u

#define IO_BANK0_INTR1_GPIO14_LEVEL_HIGH_OFFSET            25u
#define IO_BANK0_INTR1_GPIO14_LEVEL_HIGH_MASK              0x2000000u

#define IO_BANK0_INTR1_GPIO14_LEVEL_LOW_OFFSET             24u
#define IO_BANK0_INTR1_GPIO14_LEVEL_LOW_MASK               0x1000000u

#define IO_BANK0_INTR1_GPIO13_EDGE_HIGH_OFFSET             23u
#define IO_BANK0_INTR1_GPIO13_EDGE_HIGH_MASK               0x800000u

#define IO_BANK0_INTR1_GPIO13_EDGE_LOW_OFFSET              22u
#define IO_BANK0_INTR1_GPIO13_EDGE_LOW_MASK                0x400000u

#define IO_BANK0_INTR1_GPIO13_LEVEL_HIGH_OFFSET            21u
#define IO_BANK0_INTR1_GPIO13_LEVEL_HIGH_MASK              0x200000u

#define IO_BANK0_INTR1_GPIO13_LEVEL_LOW_OFFSET             20u
#define IO_BANK0_INTR1_GPIO13_LEVEL_LOW_MASK               0x100000u

#define IO_BANK0_INTR1_GPIO12_EDGE_HIGH_OFFSET             19u
#define IO_BANK0_INTR1_GPIO12_EDGE_HIGH_MASK               0x80000u

#define IO_BANK0_INTR1_GPIO12_EDGE_LOW_OFFSET              18u
#define IO_BANK0_INTR1_GPIO12_EDGE_LOW_MASK                0x40000u

#define IO_BANK0_INTR1_GPIO12_LEVEL_HIGH_OFFSET            17u
#define IO_BANK0_INTR1_GPIO12_LEVEL_HIGH_MASK              0x20000u

#define IO_BANK0_INTR1_GPIO12_LEVEL_LOW_OFFSET             16u
#define IO_BANK0_INTR1_GPIO12_LEVEL_LOW_MASK               0x10000u

#define IO_BANK0_INTR1_GPIO11_EDGE_HIGH_OFFSET             15u
#define IO_BANK0_INTR1_GPIO11_EDGE_HIGH_MASK               0x8000u

#define IO_BANK0_INTR1_GPIO11_EDGE_LOW_OFFSET              14u
#define IO_BANK0_INTR1_GPIO11_EDGE_LOW_MASK                0x4000u

#define IO_BANK0_INTR1_GPIO11_LEVEL_HIGH_OFFSET            13u
#define IO_BANK0_INTR1_GPIO11_LEVEL_HIGH_MASK              0x2000u

#define IO_BANK0_INTR1_GPIO11_LEVEL_LOW_OFFSET             12u
#define IO_BANK0_INTR1_GPIO11_LEVEL_LOW_MASK               0x1000u

#define IO_BANK0_INTR1_GPIO10_EDGE_HIGH_OFFSET             11u
#define IO_BANK0_INTR1_GPIO10_EDGE_HIGH_MASK               0x800u

#define IO_BANK0_INTR1_GPIO10_EDGE_LOW_OFFSET              10u
#define IO_BANK0_INTR1_GPIO10_EDGE_LOW_MASK                0x400u

#define IO_BANK0_INTR1_GPIO10_LEVEL_HIGH_OFFSET            9u
#define IO_BANK0_INTR1_GPIO10_LEVEL_HIGH_MASK              0x200u

#define IO_BANK0_INTR1_GPIO10_LEVEL_LOW_OFFSET             8u
#define IO_BANK0_INTR1_GPIO10_LEVEL_LOW_MASK               0x100u

#define IO_BANK0_INTR1_GPIO9_EDGE_HIGH_OFFSET              7u
#define IO_BANK0_INTR1_GPIO9_EDGE_HIGH_MASK                0x80u

#define IO_BANK0_INTR1_GPIO9_EDGE_LOW_OFFSET               6u
#define IO_BANK0_INTR1_GPIO9_EDGE_LOW_MASK                 0x40u

#define IO_BANK0_INTR1_GPIO9_LEVEL_HIGH_OFFSET             5u
#define IO_BANK0_INTR1_GPIO9_LEVEL_HIGH_MASK               0x20u

#define IO_BANK0_INTR1_GPIO9_LEVEL_LOW_OFFSET              4u
#define IO_BANK0_INTR1_GPIO9_LEVEL_LOW_MASK                0x10u

#define IO_BANK0_INTR1_GPIO8_EDGE_HIGH_OFFSET              3u
#define IO_BANK0_INTR1_GPIO8_EDGE_HIGH_MASK                8u

#define IO_BANK0_INTR1_GPIO8_EDGE_LOW_OFFSET               2u
#define IO_BANK0_INTR1_GPIO8_EDGE_LOW_MASK                 4u

#define IO_BANK0_INTR1_GPIO8_LEVEL_HIGH_OFFSET             1u
#define IO_BANK0_INTR1_GPIO8_LEVEL_HIGH_MASK               2u

#define IO_BANK0_INTR1_GPIO8_LEVEL_LOW_OFFSET              0u
#define IO_BANK0_INTR1_GPIO8_LEVEL_LOW_MASK                1u

#define IO_BANK0_INTR2_GPIO23_EDGE_HIGH_OFFSET             31u
#define IO_BANK0_INTR2_GPIO23_EDGE_HIGH_MASK               0x80000000u

#define IO_BANK0_INTR2_GPIO23_EDGE_LOW_OFFSET              30u
#define IO_BANK0_INTR2_GPIO23_EDGE_LOW_MASK                0x40000000u

#define IO_BANK0_INTR2_GPIO23_LEVEL_HIGH_OFFSET            29u
#define IO_BANK0_INTR2_GPIO23_LEVEL_HIGH_MASK              0x20000000u

#define IO_BANK0_INTR2_GPIO23_LEVEL_LOW_OFFSET             28u
#define IO_BANK0_INTR2_GPIO23_LEVEL_LOW_MASK               0x10000000u

#define IO_BANK0_INTR2_GPIO22_EDGE_HIGH_OFFSET             27u
#define IO_BANK0_INTR2_GPIO22_EDGE_HIGH_MASK               0x8000000u

#define IO_BANK0_INTR2_GPIO22_EDGE_LOW_OFFSET              26u
#define IO_BANK0_INTR2_GPIO22_EDGE_LOW_MASK                0x4000000u

#define IO_BANK0_INTR2_GPIO22_LEVEL_HIGH_OFFSET            25u
#define IO_BANK0_INTR2_GPIO22_LEVEL_HIGH_MASK              0x2000000u

#define IO_BANK0_INTR2_GPIO22_LEVEL_LOW_OFFSET             24u
#define IO_BANK0_INTR2_GPIO22_LEVEL_LOW_MASK               0x1000000u

#define IO_BANK0_INTR2_GPIO21_EDGE_HIGH_OFFSET             23u
#define IO_BANK0_INTR2_GPIO21_EDGE_HIGH_MASK               0x800000u

#define IO_BANK0_INTR2_GPIO21_EDGE_LOW_OFFSET              22u
#define IO_BANK0_INTR2_GPIO21_EDGE_LOW_MASK                0x400000u

#define IO_BANK0_INTR2_GPIO21_LEVEL_HIGH_OFFSET            21u
#define IO_BANK0_INTR2_GPIO21_LEVEL_HIGH_MASK              0x200000u

#define IO_BANK0_INTR2_GPIO21_LEVEL_LOW_OFFSET             20u
#define IO_BANK0_INTR2_GPIO21_LEVEL_LOW_MASK               0x100000u

#define IO_BANK0_INTR2_GPIO20_EDGE_HIGH_OFFSET             19u
#define IO_BANK0_INTR2_GPIO20_EDGE_HIGH_MASK               0x80000u

#define IO_BANK0_INTR2_GPIO20_EDGE_LOW_OFFSET              18u
#define IO_BANK0_INTR2_GPIO20_EDGE_LOW_MASK                0x40000u

#define IO_BANK0_INTR2_GPIO20_LEVEL_HIGH_OFFSET            17u
#define IO_BANK0_INTR2_GPIO20_LEVEL_HIGH_MASK              0x20000u

#define IO_BANK0_INTR2_GPIO20_LEVEL_LOW_OFFSET             16u
#define IO_BANK0_INTR2_GPIO20_LEVEL_LOW_MASK               0x10000u

#define IO_BANK0_INTR2_GPIO19_EDGE_HIGH_OFFSET             15u
#define IO_BANK0_INTR2_GPIO19_EDGE_HIGH_MASK               0x8000u

#define IO_BANK0_INTR2_GPIO19_EDGE_LOW_OFFSET              14u
#define IO_BANK0_INTR2_GPIO19_EDGE_LOW_MASK                0x4000u

#define IO_BANK0_INTR2_GPIO19_LEVEL_HIGH_OFFSET            13u
#define IO_BANK0_INTR2_GPIO19_LEVEL_HIGH_MASK              0x2000u

#define IO_BANK0_INTR2_GPIO19_LEVEL_LOW_OFFSET             12u
#define IO_BANK0_INTR2_GPIO19_LEVEL_LOW_MASK               0x1000u

#define IO_BANK0_INTR2_GPIO18_EDGE_HIGH_OFFSET             11u
#define IO_BANK0_INTR2_GPIO18_EDGE_HIGH_MASK               0x800u

#define IO_BANK0_INTR2_GPIO18_EDGE_LOW_OFFSET              10u
#define IO_BANK0_INTR2_GPIO18_EDGE_LOW_MASK                0x400u

#define IO_BANK0_INTR2_GPIO18_LEVEL_HIGH_OFFSET            9u
#define IO_BANK0_INTR2_GPIO18_LEVEL_HIGH_MASK              0x200u

#define IO_BANK0_INTR2_GPIO18_LEVEL_LOW_OFFSET             8u
#define IO_BANK0_INTR2_GPIO18_LEVEL_LOW_MASK               0x100u

#define IO_BANK0_INTR2_GPIO17_EDGE_HIGH_OFFSET             7u
#define IO_BANK0_INTR2_GPIO17_EDGE_HIGH_MASK               0x80u

#define IO_BANK0_INTR2_GPIO17_EDGE_LOW_OFFSET              6u
#define IO_BANK0_INTR2_GPIO17_EDGE_LOW_MASK                0x40u

#define IO_BANK0_INTR2_GPIO17_LEVEL_HIGH_OFFSET            5u
#define IO_BANK0_INTR2_GPIO17_LEVEL_HIGH_MASK              0x20u

#define IO_BANK0_INTR2_GPIO17_LEVEL_LOW_OFFSET             4u
#define IO_BANK0_INTR2_GPIO17_LEVEL_LOW_MASK               0x10u

#define IO_BANK0_INTR2_GPIO16_EDGE_HIGH_OFFSET             3u
#define IO_BANK0_INTR2_GPIO16_EDGE_HIGH_MASK               8u

#define IO_BANK0_INTR2_GPIO16_EDGE_LOW_OFFSET              2u
#define IO_BANK0_INTR2_GPIO16_EDGE_LOW_MASK                4u

#define IO_BANK0_INTR2_GPIO16_LEVEL_HIGH_OFFSET            1u
#define IO_BANK0_INTR2_GPIO16_LEVEL_HIGH_MASK              2u

#define IO_BANK0_INTR2_GPIO16_LEVEL_LOW_OFFSET             0u
#define IO_BANK0_INTR2_GPIO16_LEVEL_LOW_MASK               1u

#define IO_BANK0_INTR3_GPIO29_EDGE_HIGH_OFFSET             23u
#define IO_BANK0_INTR3_GPIO29_EDGE_HIGH_MASK               0x800000u

#define IO_BANK0_INTR3_GPIO29_EDGE_LOW_OFFSET              22u
#define IO_BANK0_INTR3_GPIO29_EDGE_LOW_MASK                0x400000u

#define IO_BANK0_INTR3_GPIO29_LEVEL_HIGH_OFFSET            21u
#define IO_BANK0_INTR3_GPIO29_LEVEL_HIGH_MASK              0x200000u

#define IO_BANK0_INTR3_GPIO29_LEVEL_LOW_OFFSET             20u
#define IO_BANK0_INTR3_GPIO29_LEVEL_LOW_MASK               0x100000u

#define IO_BANK0_INTR3_GPIO28_EDGE_HIGH_OFFSET             19u
#define IO_BANK0_INTR3_GPIO28_EDGE_HIGH_MASK               0x80000u

#define IO_BANK0_INTR3_GPIO28_EDGE_LOW_OFFSET              18u
#define IO_BANK0_INTR3_GPIO28_EDGE_LOW_MASK                0x40000u

#define IO_BANK0_INTR3_GPIO28_LEVEL_HIGH_OFFSET            17u
#define IO_BANK0_INTR3_GPIO28_LEVEL_HIGH_MASK              0x20000u

#define IO_BANK0_INTR3_GPIO28_LEVEL_LOW_OFFSET             16u
#define IO_BANK0_INTR3_GPIO28_LEVEL_LOW_MASK               0x10000u

#define IO_BANK0_INTR3_GPIO27_EDGE_HIGH_OFFSET             15u
#define IO_BANK0_INTR3_GPIO27_EDGE_HIGH_MASK               0x8000u

#define IO_BANK0_INTR3_GPIO27_EDGE_LOW_OFFSET              14u
#define IO_BANK0_INTR3_GPIO27_EDGE_LOW_MASK                0x4000u

#define IO_BANK0_INTR3_GPIO27_LEVEL_HIGH_OFFSET            13u
#define IO_BANK0_INTR3_GPIO27_LEVEL_HIGH_MASK              0x2000u

#define IO_BANK0_INTR3_GPIO27_LEVEL_LOW_OFFSET             12u
#define IO_BANK0_INTR3_GPIO27_LEVEL_LOW_MASK               0x1000u

#define IO_BANK0_INTR3_GPIO26_EDGE_HIGH_OFFSET             11u
#define IO_BANK0_INTR3_GPIO26_EDGE_HIGH_MASK               0x800u

#define IO_BANK0_INTR3_GPIO26_EDGE_LOW_OFFSET              10u
#define IO_BANK0_INTR3_GPIO26_EDGE_LOW_MASK                0x400u

#define IO_BANK0_INTR3_GPIO26_LEVEL_HIGH_OFFSET            9u
#define IO_BANK0_INTR3_GPIO26_LEVEL_HIGH_MASK              0x200u

#define IO_BANK0_INTR3_GPIO26_LEVEL_LOW_OFFSET             8u
#define IO_BANK0_INTR3_GPIO26_LEVEL_LOW_MASK               0x100u

#define IO_BANK0_INTR3_GPIO25_EDGE_HIGH_OFFSET             7u
#define IO_BANK0_INTR3_GPIO25_EDGE_HIGH_MASK               0x80u

#define IO_BANK0_INTR3_GPIO25_EDGE_LOW_OFFSET              6u
#define IO_BANK0_INTR3_GPIO25_EDGE_LOW_MASK                0x40u

#define IO_BANK0_INTR3_GPIO25_LEVEL_HIGH_OFFSET            5u
#define IO_BANK0_INTR3_GPIO25_LEVEL_HIGH_MASK              0x20u

#define IO_BANK0_INTR3_GPIO25_LEVEL_LOW_OFFSET             4u
#define IO_BANK0_INTR3_GPIO25_LEVEL_LOW_MASK               0x10u

#define IO_BANK0_INTR3_GPIO24_EDGE_HIGH_OFFSET             3u
#define IO_BANK0_INTR3_GPIO24_EDGE_HIGH_MASK               8u

#define IO_BANK0_INTR3_GPIO24_EDGE_LOW_OFFSET              2u
#define IO_BANK0_INTR3_GPIO24_EDGE_LOW_MASK                4u

#define IO_BANK0_INTR3_GPIO24_LEVEL_HIGH_OFFSET            1u
#define IO_BANK0_INTR3_GPIO24_LEVEL_HIGH_MASK              2u

#define IO_BANK0_INTR3_GPIO24_LEVEL_LOW_OFFSET             0u
#define IO_BANK0_INTR3_GPIO24_LEVEL_LOW_MASK               1u

#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_HIGH_OFFSET        31u
#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_HIGH_MASK          0x80000000u

#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_LOW_OFFSET         30u
#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_LOW_MASK           0x40000000u

#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_HIGH_OFFSET       29u
#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_HIGH_MASK         0x20000000u

#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_LOW_OFFSET        28u
#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_LOW_MASK          0x10000000u

#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_HIGH_OFFSET        27u
#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_HIGH_MASK          0x8000000u

#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_LOW_OFFSET         26u
#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_LOW_MASK           0x4000000u

#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_HIGH_OFFSET       25u
#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_HIGH_MASK         0x2000000u

#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_LOW_OFFSET        24u
#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_LOW_MASK          0x1000000u

#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_HIGH_OFFSET        23u
#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_HIGH_MASK          0x800000u

#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_LOW_OFFSET         22u
#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_LOW_MASK           0x400000u

#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_HIGH_OFFSET       21u
#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_HIGH_MASK         0x200000u

#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_LOW_OFFSET        20u
#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_LOW_MASK          0x100000u

#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_HIGH_OFFSET        19u
#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_HIGH_MASK          0x80000u

#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_LOW_OFFSET         18u
#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_LOW_MASK           0x40000u

#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_HIGH_OFFSET       17u
#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_HIGH_MASK         0x20000u

#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_LOW_OFFSET        16u
#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_LOW_MASK          0x10000u

#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_HIGH_OFFSET        15u
#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_HIGH_MASK          0x8000u

#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_LOW_OFFSET         14u
#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_LOW_MASK           0x4000u

#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_HIGH_OFFSET       13u
#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_HIGH_MASK         0x2000u

#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_LOW_OFFSET        12u
#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_LOW_MASK          0x1000u

#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_HIGH_OFFSET        11u
#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_HIGH_MASK          0x800u

#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_LOW_OFFSET         10u
#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_LOW_MASK           0x400u

#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_HIGH_OFFSET       9u
#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_HIGH_MASK         0x200u

#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_LOW_OFFSET        8u
#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_LOW_MASK          0x100u

#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_HIGH_OFFSET        7u
#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_HIGH_MASK          0x80u

#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_LOW_OFFSET         6u
#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_LOW_MASK           0x40u

#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_HIGH_OFFSET       5u
#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_HIGH_MASK         0x20u

#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_LOW_OFFSET        4u
#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_LOW_MASK          0x10u

#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_HIGH_OFFSET        3u
#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_HIGH_MASK          8u

#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_LOW_OFFSET         2u
#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_LOW_MASK           4u

#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_HIGH_OFFSET       1u
#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_HIGH_MASK         2u

#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_LOW_OFFSET        0u
#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_LOW_MASK          1u

#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_HIGH_OFFSET       31u
#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_HIGH_MASK         0x80000000u

#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_LOW_OFFSET        30u
#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_LOW_MASK          0x40000000u

#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_HIGH_OFFSET      29u
#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_HIGH_MASK        0x20000000u

#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_LOW_OFFSET       28u
#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_LOW_MASK         0x10000000u

#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_HIGH_OFFSET       27u
#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_HIGH_MASK         0x8000000u

#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_LOW_OFFSET        26u
#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_LOW_MASK          0x4000000u

#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_HIGH_OFFSET      25u
#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_HIGH_MASK        0x2000000u

#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_LOW_OFFSET       24u
#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_LOW_MASK         0x1000000u

#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_LOW_MASK         1u

#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_HIGH_OFFSET       23u
#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_HIGH_MASK         0x800000u

#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_LOW_OFFSET        22u
#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_LOW_MASK          0x400000u

#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_HIGH_OFFSET      21u
#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_HIGH_MASK        0x200000u

#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_LOW_OFFSET       20u
#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_LOW_MASK         0x100000u

#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_HIGH_OFFSET       19u
#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_HIGH_MASK         0x80000u

#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_LOW_OFFSET        18u
#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_LOW_MASK          0x40000u

#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_HIGH_OFFSET      17u
#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_HIGH_MASK        0x20000u

#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_LOW_OFFSET       16u
#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_LOW_MASK         0x10000u

#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_HIGH_OFFSET       15u
#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_HIGH_MASK         0x8000u

#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_LOW_OFFSET        14u
#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_LOW_MASK          0x4000u

#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_HIGH_OFFSET      13u
#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_HIGH_MASK        0x2000u

#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_LOW_OFFSET       12u
#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_LOW_MASK         0x1000u

#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_HIGH_OFFSET       11u
#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_HIGH_MASK         0x800u

#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_LOW_OFFSET        10u
#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_LOW_MASK          0x400u

#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_HIGH_OFFSET      9u
#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_HIGH_MASK        0x200u

#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_LOW_OFFSET       8u
#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_LOW_MASK         0x100u

#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_HIGH_OFFSET       7u
#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_HIGH_MASK         0x80u

#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_LOW_OFFSET        6u
#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_LOW_MASK          0x40u

#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_HIGH_OFFSET      5u
#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_HIGH_MASK        0x20u

#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_LOW_OFFSET       4u
#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_LOW_MASK         0x10u

#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_HIGH_OFFSET       3u
#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_HIGH_MASK         8u

#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_LOW_OFFSET        2u
#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_LOW_MASK          4u

#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_HIGH_OFFSET      1u
#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_HIGH_MASK        2u

#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_LOW_OFFSET       0u
#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_LOW_MASK         1u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_HIGH_MASK   0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_LOW_OFFSET  30u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_LOW_MASK    0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_HIGH_MASK  0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_LOW_MASK   0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_HIGH_MASK   0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_LOW_OFFSET  26u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_LOW_MASK    0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_HIGH_MASK  0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_LOW_MASK   0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_HIGH_MASK   0x800000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_LOW_OFFSET  22u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_LOW_MASK    0x400000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_HIGH_MASK  0x200000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_LOW_MASK   0x100000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_HIGH_MASK   0x80000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_LOW_OFFSET  18u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_LOW_MASK    0x40000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_HIGH_MASK  0x20000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_LOW_MASK   0x10000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_HIGH_MASK   0x8000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_LOW_OFFSET  14u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_LOW_MASK    0x4000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_HIGH_MASK  0x2000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_LOW_MASK   0x1000u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_HIGH_MASK   0x800u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_LOW_OFFSET  10u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_LOW_MASK    0x400u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_HIGH_MASK  0x200u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_LOW_MASK   0x100u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_LOW_MASK  1u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_LOW_MASK  1u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_HIGH_MASK   0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_LOW_OFFSET  30u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_LOW_MASK    0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_HIGH_MASK  0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_LOW_MASK   0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_HIGH_MASK   0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_LOW_OFFSET  26u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_LOW_MASK    0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_HIGH_MASK  0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_LOW_MASK   0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_HIGH_MASK   0x800000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_LOW_OFFSET  22u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_LOW_MASK    0x400000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_HIGH_MASK  0x200000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_LOW_MASK   0x100000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_HIGH_MASK   0x80000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_LOW_OFFSET  18u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_LOW_MASK    0x40000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_HIGH_MASK  0x20000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_LOW_MASK   0x10000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_HIGH_MASK   0x8000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_LOW_OFFSET  14u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_LOW_MASK    0x4000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_HIGH_MASK  0x2000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_LOW_MASK   0x1000u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_HIGH_MASK   0x800u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_LOW_OFFSET  10u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_LOW_MASK    0x400u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_HIGH_MASK  0x200u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_LOW_MASK   0x100u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_LOW_MASK  1u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_LOW_MASK  1u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_HIGH_MASK   0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_LOW_OFFSET  30u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_LOW_MASK    0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_HIGH_MASK  0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_LOW_MASK   0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_HIGH_MASK   0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_LOW_OFFSET  26u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_LOW_MASK    0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_HIGH_MASK  0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_LOW_MASK   0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_HIGH_MASK   0x800000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_LOW_OFFSET  22u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_LOW_MASK    0x400000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_HIGH_MASK  0x200000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_LOW_MASK   0x100000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_HIGH_MASK   0x80000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_LOW_OFFSET  18u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_LOW_MASK    0x40000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_HIGH_MASK  0x20000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_LOW_MASK   0x10000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_HIGH_MASK   0x8000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_LOW_OFFSET  14u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_LOW_MASK    0x4000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_HIGH_MASK  0x2000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_LOW_MASK   0x1000u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_HIGH_MASK   0x800u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_LOW_OFFSET  10u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_LOW_MASK    0x400u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_HIGH_MASK  0x200u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_LOW_MASK   0x100u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_HIGH_MASK   0x80u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_LOW_OFFSET  6u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_LOW_MASK    0x40u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_HIGH_MASK  0x20u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_LOW_MASK   0x10u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_HIGH_MASK   8u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_LOW_OFFSET  2u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_LOW_MASK    4u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_HIGH_MASK  2u

#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_LOW_MASK   1u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_HIGH_OFFSET   31u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_HIGH_MASK  0x80000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_LOW_OFFSET   30u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_LOW_MASK   0x40000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_HIGH_OFFSET   29u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_HIGH_MASK   0x20000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_LOW_OFFSET   28u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_LOW_MASK  0x10000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_HIGH_OFFSET   27u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_HIGH_MASK  0x8000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_LOW_OFFSET   26u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_LOW_MASK   0x4000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_HIGH_OFFSET   25u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_HIGH_MASK   0x2000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_LOW_OFFSET   24u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_LOW_MASK  0x1000000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_LOW_MASK  1u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_HIGH_OFFSET   23u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_HIGH_MASK  0x800000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_LOW_OFFSET   22u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_LOW_MASK   0x400000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_HIGH_OFFSET   21u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_HIGH_MASK   0x200000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_LOW_OFFSET   20u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_LOW_MASK  0x100000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_HIGH_OFFSET   19u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_HIGH_MASK  0x80000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_LOW_OFFSET   18u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_LOW_MASK   0x40000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_HIGH_OFFSET   17u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_HIGH_MASK   0x20000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_LOW_OFFSET   16u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_LOW_MASK  0x10000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_HIGH_OFFSET   15u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_HIGH_MASK  0x8000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_LOW_OFFSET   14u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_LOW_MASK   0x4000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_HIGH_OFFSET   13u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_HIGH_MASK   0x2000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_LOW_OFFSET   12u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_LOW_MASK  0x1000u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_HIGH_OFFSET   11u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_HIGH_MASK  0x800u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_LOW_OFFSET   10u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_LOW_MASK   0x400u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_HIGH_OFFSET   9u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_HIGH_MASK   0x200u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_LOW_OFFSET   8u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_LOW_MASK  0x100u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_HIGH_OFFSET   7u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_HIGH_MASK  0x80u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_LOW_OFFSET   6u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_LOW_MASK   0x40u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_HIGH_OFFSET   5u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_HIGH_MASK   0x20u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_LOW_OFFSET   4u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_LOW_MASK  0x10u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_HIGH_OFFSET   3u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_HIGH_MASK  8u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_LOW_OFFSET   2u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_LOW_MASK   4u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_HIGH_OFFSET   1u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_HIGH_MASK   2u

#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_LOW_OFFSET   0u
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_LOW_MASK  1u


typedef struct
{

/** GPIO0_STATUS (offset: 0x0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO0_STATUS;

/** GPIO0_CTRL (offset: 0x4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 0 - jtag_tck
  Value: 1 - spi0_rx
  Value: 2 - uart0_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_0
  Value: 5 - sio_0
  Value: 6 - pio0_0
  Value: 7 - pio1_0
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO0_CTRL;

/** GPIO1_STATUS (offset: 0x8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO1_STATUS;

/** GPIO1_CTRL (offset: 0xc)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 0 - jtag_tms
  Value: 1 - spi0_ss_n
  Value: 2 - uart0_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_0
  Value: 5 - sio_1
  Value: 6 - pio0_1
  Value: 7 - pio1_1
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO1_CTRL;

/** GPIO2_STATUS (offset: 0x10)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO2_STATUS;

/** GPIO2_CTRL (offset: 0x14)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 0 - jtag_tdi
  Value: 1 - spi0_sclk
  Value: 2 - uart0_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_1
  Value: 5 - sio_2
  Value: 6 - pio0_2
  Value: 7 - pio1_2
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO2_CTRL;

/** GPIO3_STATUS (offset: 0x18)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO3_STATUS;

/** GPIO3_CTRL (offset: 0x1c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 0 - jtag_tdo
  Value: 1 - spi0_tx
  Value: 2 - uart0_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_1
  Value: 5 - sio_3
  Value: 6 - pio0_3
  Value: 7 - pio1_3
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO3_CTRL;

/** GPIO4_STATUS (offset: 0x20)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO4_STATUS;

/** GPIO4_CTRL (offset: 0x24)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_rx
  Value: 2 - uart1_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_2
  Value: 5 - sio_4
  Value: 6 - pio0_4
  Value: 7 - pio1_4
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO4_CTRL;

/** GPIO5_STATUS (offset: 0x28)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO5_STATUS;

/** GPIO5_CTRL (offset: 0x2c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_ss_n
  Value: 2 - uart1_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_2
  Value: 5 - sio_5
  Value: 6 - pio0_5
  Value: 7 - pio1_5
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO5_CTRL;

/** GPIO6_STATUS (offset: 0x30)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO6_STATUS;

/** GPIO6_CTRL (offset: 0x34)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_sclk
  Value: 2 - uart1_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_3
  Value: 5 - sio_6
  Value: 6 - pio0_6
  Value: 7 - pio1_6
  Value: 8 - usb_muxing_extphy_softcon
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO6_CTRL;

/** GPIO7_STATUS (offset: 0x38)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO7_STATUS;

/** GPIO7_CTRL (offset: 0x3c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_tx
  Value: 2 - uart1_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_3
  Value: 5 - sio_7
  Value: 6 - pio0_7
  Value: 7 - pio1_7
  Value: 8 - usb_muxing_extphy_oe_n
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO7_CTRL;

/** GPIO8_STATUS (offset: 0x40)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO8_STATUS;

/** GPIO8_CTRL (offset: 0x44)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_rx
  Value: 2 - uart1_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_4
  Value: 5 - sio_8
  Value: 6 - pio0_8
  Value: 7 - pio1_8
  Value: 8 - usb_muxing_extphy_rcv
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO8_CTRL;

/** GPIO9_STATUS (offset: 0x48)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO9_STATUS;

/** GPIO9_CTRL (offset: 0x4c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_ss_n
  Value: 2 - uart1_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_4
  Value: 5 - sio_9
  Value: 6 - pio0_9
  Value: 7 - pio1_9
  Value: 8 - usb_muxing_extphy_vp
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO9_CTRL;

/** GPIO10_STATUS (offset: 0x50)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO10_STATUS;

/** GPIO10_CTRL (offset: 0x54)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_sclk
  Value: 2 - uart1_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_5
  Value: 5 - sio_10
  Value: 6 - pio0_10
  Value: 7 - pio1_10
  Value: 8 - usb_muxing_extphy_vm
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO10_CTRL;

/** GPIO11_STATUS (offset: 0x58)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO11_STATUS;

/** GPIO11_CTRL (offset: 0x5c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_tx
  Value: 2 - uart1_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_5
  Value: 5 - sio_11
  Value: 6 - pio0_11
  Value: 7 - pio1_11
  Value: 8 - usb_muxing_extphy_suspnd
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO11_CTRL;

/** GPIO12_STATUS (offset: 0x60)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO12_STATUS;

/** GPIO12_CTRL (offset: 0x64)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_rx
  Value: 2 - uart0_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_6
  Value: 5 - sio_12
  Value: 6 - pio0_12
  Value: 7 - pio1_12
  Value: 8 - usb_muxing_extphy_speed
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO12_CTRL;

/** GPIO13_STATUS (offset: 0x68)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO13_STATUS;

/** GPIO13_CTRL (offset: 0x6c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_ss_n
  Value: 2 - uart0_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_6
  Value: 5 - sio_13
  Value: 6 - pio0_13
  Value: 7 - pio1_13
  Value: 8 - usb_muxing_extphy_vpo
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO13_CTRL;

/** GPIO14_STATUS (offset: 0x70)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO14_STATUS;

/** GPIO14_CTRL (offset: 0x74)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_sclk
  Value: 2 - uart0_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_7
  Value: 5 - sio_14
  Value: 6 - pio0_14
  Value: 7 - pio1_14
  Value: 8 - usb_muxing_extphy_vmo
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO14_CTRL;

/** GPIO15_STATUS (offset: 0x78)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO15_STATUS;

/** GPIO15_CTRL (offset: 0x7c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_tx
  Value: 2 - uart0_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_7
  Value: 5 - sio_15
  Value: 6 - pio0_15
  Value: 7 - pio1_15
  Value: 8 - usb_muxing_digital_dp
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO15_CTRL;

/** GPIO16_STATUS (offset: 0x80)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO16_STATUS;

/** GPIO16_CTRL (offset: 0x84)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_rx
  Value: 2 - uart0_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_0
  Value: 5 - sio_16
  Value: 6 - pio0_16
  Value: 7 - pio1_16
  Value: 8 - usb_muxing_digital_dm
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO16_CTRL;

/** GPIO17_STATUS (offset: 0x88)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO17_STATUS;

/** GPIO17_CTRL (offset: 0x8c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_ss_n
  Value: 2 - uart0_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_0
  Value: 5 - sio_17
  Value: 6 - pio0_17
  Value: 7 - pio1_17
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO17_CTRL;

/** GPIO18_STATUS (offset: 0x90)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO18_STATUS;

/** GPIO18_CTRL (offset: 0x94)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_sclk
  Value: 2 - uart0_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_1
  Value: 5 - sio_18
  Value: 6 - pio0_18
  Value: 7 - pio1_18
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO18_CTRL;

/** GPIO19_STATUS (offset: 0x98)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO19_STATUS;

/** GPIO19_CTRL (offset: 0x9c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_tx
  Value: 2 - uart0_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_1
  Value: 5 - sio_19
  Value: 6 - pio0_19
  Value: 7 - pio1_19
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO19_CTRL;

/** GPIO20_STATUS (offset: 0xa0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO20_STATUS;

/** GPIO20_CTRL (offset: 0xa4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_rx
  Value: 2 - uart1_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_2
  Value: 5 - sio_20
  Value: 6 - pio0_20
  Value: 7 - pio1_20
  Value: 8 - clocks_gpin_0
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO20_CTRL;

/** GPIO21_STATUS (offset: 0xa8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO21_STATUS;

/** GPIO21_CTRL (offset: 0xac)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_ss_n
  Value: 2 - uart1_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_2
  Value: 5 - sio_21
  Value: 6 - pio0_21
  Value: 7 - pio1_21
  Value: 8 - clocks_gpout_0
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO21_CTRL;

/** GPIO22_STATUS (offset: 0xb0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO22_STATUS;

/** GPIO22_CTRL (offset: 0xb4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_sclk
  Value: 2 - uart1_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_3
  Value: 5 - sio_22
  Value: 6 - pio0_22
  Value: 7 - pio1_22
  Value: 8 - clocks_gpin_1
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO22_CTRL;

/** GPIO23_STATUS (offset: 0xb8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO23_STATUS;

/** GPIO23_CTRL (offset: 0xbc)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi0_tx
  Value: 2 - uart1_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_3
  Value: 5 - sio_23
  Value: 6 - pio0_23
  Value: 7 - pio1_23
  Value: 8 - clocks_gpout_1
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO23_CTRL;

/** GPIO24_STATUS (offset: 0xc0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO24_STATUS;

/** GPIO24_CTRL (offset: 0xc4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_rx
  Value: 2 - uart1_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_4
  Value: 5 - sio_24
  Value: 6 - pio0_24
  Value: 7 - pio1_24
  Value: 8 - clocks_gpout_2
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO24_CTRL;

/** GPIO25_STATUS (offset: 0xc8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO25_STATUS;

/** GPIO25_CTRL (offset: 0xcc)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_ss_n
  Value: 2 - uart1_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_4
  Value: 5 - sio_25
  Value: 6 - pio0_25
  Value: 7 - pio1_25
  Value: 8 - clocks_gpout_3
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO25_CTRL;

/** GPIO26_STATUS (offset: 0xd0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO26_STATUS;

/** GPIO26_CTRL (offset: 0xd4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_sclk
  Value: 2 - uart1_cts
  Value: 3 - i2c1_sda
  Value: 4 - pwm_a_5
  Value: 5 - sio_26
  Value: 6 - pio0_26
  Value: 7 - pio1_26
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO26_CTRL;

/** GPIO27_STATUS (offset: 0xd8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO27_STATUS;

/** GPIO27_CTRL (offset: 0xdc)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_tx
  Value: 2 - uart1_rts
  Value: 3 - i2c1_scl
  Value: 4 - pwm_b_5
  Value: 5 - sio_27
  Value: 6 - pio0_27
  Value: 7 - pio1_27
  Value: 9 - usb_muxing_overcurr_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO27_CTRL;

/** GPIO28_STATUS (offset: 0xe0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO28_STATUS;

/** GPIO28_CTRL (offset: 0xe4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_rx
  Value: 2 - uart0_tx
  Value: 3 - i2c0_sda
  Value: 4 - pwm_a_6
  Value: 5 - sio_28
  Value: 6 - pio0_28
  Value: 7 - pio1_28
  Value: 9 - usb_muxing_vbus_detect
  Value: 0x1f - null
*/
volatile uint32_t GPIO28_CTRL;

/** GPIO29_STATUS (offset: 0xe8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO29_STATUS;

/** GPIO29_CTRL (offset: 0xec)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum:
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum:
  Value: 1 - spi1_ss_n
  Value: 2 - uart0_rx
  Value: 3 - i2c0_scl
  Value: 4 - pwm_b_6
  Value: 5 - sio_29
  Value: 6 - pio0_29
  Value: 7 - pio1_29
  Value: 9 - usb_muxing_vbus_en
  Value: 0x1f - null
*/
volatile uint32_t GPIO29_CTRL;

/** INTR0 (offset: 0xf0)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR0;

/** INTR1 (offset: 0xf4)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR1;

/** INTR2 (offset: 0xf8)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR2;

/** INTR3 (offset: 0xfc)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR3;

/** PROC0_INTE0 (offset: 0x100)
  Interrupt Enable for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTE0;

/** PROC0_INTE1 (offset: 0x104)
  Interrupt Enable for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTE1;

/** PROC0_INTE2 (offset: 0x108)
  Interrupt Enable for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTE2;

/** PROC0_INTE3 (offset: 0x10c)
  Interrupt Enable for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTE3;

/** PROC0_INTF0 (offset: 0x110)
  Interrupt Force for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTF0;

/** PROC0_INTF1 (offset: 0x114)
  Interrupt Force for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTF1;

/** PROC0_INTF2 (offset: 0x118)
  Interrupt Force for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTF2;

/** PROC0_INTF3 (offset: 0x11c)
  Interrupt Force for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTF3;

/** PROC0_INTS0 (offset: 0x120)
  Interrupt status after masking &amp; forcing for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC0_INTS0;

/** PROC0_INTS1 (offset: 0x124)
  Interrupt status after masking &amp; forcing for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC0_INTS1;

/** PROC0_INTS2 (offset: 0x128)
  Interrupt status after masking &amp; forcing for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC0_INTS2;

/** PROC0_INTS3 (offset: 0x12c)
  Interrupt status after masking &amp; forcing for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC0_INTS3;

/** PROC1_INTE0 (offset: 0x130)
  Interrupt Enable for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTE0;

/** PROC1_INTE1 (offset: 0x134)
  Interrupt Enable for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTE1;

/** PROC1_INTE2 (offset: 0x138)
  Interrupt Enable for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTE2;

/** PROC1_INTE3 (offset: 0x13c)
  Interrupt Enable for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTE3;

/** PROC1_INTF0 (offset: 0x140)
  Interrupt Force for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTF0;

/** PROC1_INTF1 (offset: 0x144)
  Interrupt Force for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTF1;

/** PROC1_INTF2 (offset: 0x148)
  Interrupt Force for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTF2;

/** PROC1_INTF3 (offset: 0x14c)
  Interrupt Force for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTF3;

/** PROC1_INTS0 (offset: 0x150)
  Interrupt status after masking &amp; forcing for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC1_INTS0;

/** PROC1_INTS1 (offset: 0x154)
  Interrupt status after masking &amp; forcing for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC1_INTS1;

/** PROC1_INTS2 (offset: 0x158)
  Interrupt status after masking &amp; forcing for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC1_INTS2;

/** PROC1_INTS3 (offset: 0x15c)
  Interrupt status after masking &amp; forcing for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC1_INTS3;

/** DORMANT_WAKE_INTE0 (offset: 0x160)
  Interrupt Enable for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTE0;

/** DORMANT_WAKE_INTE1 (offset: 0x164)
  Interrupt Enable for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTE1;

/** DORMANT_WAKE_INTE2 (offset: 0x168)
  Interrupt Enable for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTE2;

/** DORMANT_WAKE_INTE3 (offset: 0x16c)
  Interrupt Enable for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTE3;

/** DORMANT_WAKE_INTF0 (offset: 0x170)
  Interrupt Force for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTF0;

/** DORMANT_WAKE_INTF1 (offset: 0x174)
  Interrupt Force for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTF1;

/** DORMANT_WAKE_INTF2 (offset: 0x178)
  Interrupt Force for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-write
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-write
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-write
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-write
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-write
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-write
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-write
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-write
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTF2;

/** DORMANT_WAKE_INTF3 (offset: 0x17c)
  Interrupt Force for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTF3;

/** DORMANT_WAKE_INTS0 (offset: 0x180)
  Interrupt status after masking &amp; forcing for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO7_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO7_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO7_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO7_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO6_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO6_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO6_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO6_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO5_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO5_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO5_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO5_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO4_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO4_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO4_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO4_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO3_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO3_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO3_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO3_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO2_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO2_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO2_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO2_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO1_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO1_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO1_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO1_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO0_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO0_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO0_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO0_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DORMANT_WAKE_INTS0;

/** DORMANT_WAKE_INTS1 (offset: 0x184)
  Interrupt status after masking &amp; forcing for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO15_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO15_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO15_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO15_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO14_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO14_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO14_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO14_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO13_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO13_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO13_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO13_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO12_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO12_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO12_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO12_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO11_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO11_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO11_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO11_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO10_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO10_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO10_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO10_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO9_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO9_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO9_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO9_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO8_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO8_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO8_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO8_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DORMANT_WAKE_INTS1;

/** DORMANT_WAKE_INTS2 (offset: 0x188)
  Interrupt status after masking &amp; forcing for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO23_EDGE_HIGH
  offset: 31, size: 1, access: read-only
  Field: GPIO23_EDGE_LOW
  offset: 30, size: 1, access: read-only
  Field: GPIO23_LEVEL_HIGH
  offset: 29, size: 1, access: read-only
  Field: GPIO23_LEVEL_LOW
  offset: 28, size: 1, access: read-only
  Field: GPIO22_EDGE_HIGH
  offset: 27, size: 1, access: read-only
  Field: GPIO22_EDGE_LOW
  offset: 26, size: 1, access: read-only
  Field: GPIO22_LEVEL_HIGH
  offset: 25, size: 1, access: read-only
  Field: GPIO22_LEVEL_LOW
  offset: 24, size: 1, access: read-only
  Field: GPIO21_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO21_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO21_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO21_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO20_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO20_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO20_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO20_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO19_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO19_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO19_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO19_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO18_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO18_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO18_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO18_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO17_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO17_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO17_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO17_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO16_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO16_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO16_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO16_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DORMANT_WAKE_INTS2;

/** DORMANT_WAKE_INTS3 (offset: 0x18c)
  Interrupt status after masking &amp; forcing for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO29_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO29_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO29_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO29_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO28_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO28_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO28_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO28_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO27_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO27_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO27_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO27_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO26_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO26_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO26_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO26_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO25_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO25_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO25_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO25_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO24_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO24_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO24_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO24_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DORMANT_WAKE_INTS3;
} IO_BANK0_type;

#define IO_BANK0 ((IO_BANK0_type *) 0x40014000)

#endif // HW_IO_BANK0_H
