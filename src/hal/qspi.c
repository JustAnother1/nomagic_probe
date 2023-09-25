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


#include "qspi.h"
#include "startup.h"
#include "hal/hw/IO_QSPI.h"
#include "hal/hw/PADS_QSPI.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/XIP_CTRL.h"
#include "hal/hw/XIP_SSI.h"
#include "hal/debug_uart.h"

void XIP_IRQ(void) __attribute__ ((interrupt ("IRQ")));

// XIP / SSI / QSPI peripheral:
static bool qspi_active;

void qspi_init(void)
{
    volatile uint32_t help = 0;
    (void)help;
/*
    // reset QSPI
    RESETS->RESET = RESETS->RESET | (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET);
    PSM->FRCE_OFF =  PSM->FRCE_OFF | (1 << PSM_FRCE_OFF_XIP_OFFSET);

    qspi_active = false;

    // power on QSPI
    PSM->FRCE_OFF =  PSM->FRCE_OFF & ~(uint32_t)(1 << PSM_FRCE_OFF_XIP_OFFSET);
    PSM->FRCE_ON =  PSM->FRCE_ON | (1 << PSM_FRCE_ON_XIP_OFFSET);
    RESETS->RESET = RESETS->RESET &~(uint32_t)( (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET));
*/
    XIP_SSI->SSIENR = 0;  // disabled

    PADS_QSPI->VOLTAGE_SELECT = 0;  // 3.3V
    PADS_QSPI->GPIO_QSPI_SCLK = (1<< PADS_QSPI_GPIO_QSPI_SCLK_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_PDE_OFFSET)  // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD0 = (1<< PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD1 = (1<< PADS_QSPI_GPIO_QSPI_SD1_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD1_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD2 =  (1<< PADS_QSPI_GPIO_QSPI_SD2_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD2_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD3 =  (1<< PADS_QSPI_GPIO_QSPI_SD3_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD3_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SS = (1<< PADS_QSPI_GPIO_QSPI_SS_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SS_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SS_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_PUE_OFFSET)  // Pull up enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_SLEWFAST_OFFSET);  // slew rate fast
    IO_QSPI->INTR = 0xffffffff; // write to clear
    IO_QSPI->PROC0_INTE = 0;
    IO_QSPI->PROC0_INTF = 0;
    IO_QSPI->PROC1_INTE = 0;
    IO_QSPI->PROC1_INTF = 0;
    IO_QSPI->GPIO_QSPI_SCLK_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD0_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD1_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD2_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD3_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SS_CTRL = 0;

    XIP_CTRL->CTRL = (1 << XIP_CTRL_CTRL_ERR_BADWRITE_OFFSET);  // detect bad memory accesses, disable cache
    XIP_CTRL->FLUSH = (1 << XIP_CTRL_FLUSH_FLUSH_OFFSET);  // flush cache

    XIP_SSI->SER = (1 << XIP_SSI_SER_SER_OFFSET); // slave selected
    XIP_SSI->BAUDR = (QSPI_BAUDRATE_DIVIDOR << XIP_SSI_BAUDR_SCKDV_OFFSET);  // set baud rate
    XIP_SSI->TXFTLR = 0;
    XIP_SSI->RXFTLR = 0;
    XIP_SSI->TXFLR = 0;
    XIP_SSI->RXFLR = 0;
    XIP_SSI->IMR = 0x3f; // all interrupts are masked
    help = XIP_SSI->ICR;  // clear all active interrupts
    XIP_SSI->DMACR = 0;  // no DMA
    XIP_SSI->DMATDLR = 0;
    XIP_SSI->DMARDLR = 0;
    XIP_SSI->RX_SAMPLE_DLY = (1 << XIP_SSI_RX_SAMPLE_DLY_RSD_OFFSET);  // delay in System clock cycles
    XIP_SSI->TXD_DRIVE_EDGE = 0;

    XIP_SSI->CTRLR0 = 0; // 0x1070000;
    XIP_SSI->CTRLR1 = 0;
    XIP_SSI->SPI_CTRLR0 = 0;

    help = XIP_SSI->SR; // read to clear
    help = XIP_SSI->ICR; // read to clear

    XIP_SSI->SER = (1 << XIP_SSI_SER_SER_OFFSET); // slave selected
    // XIP_SSI->SSIENR = 1;  // enabled
    // XIP_SSI->IMR = 0x3f;  // disable all IRQs
    // NVIC_EnableIRQ(XIP_IRQ_NUMBER, XIP_IRQ_PRIORITY);
}

void XIP_IRQ(void)
{
    uint32_t read;
    (void)read;
    uint32_t irq = XIP_SSI->ISR;
    if(0 != (irq & (1 << XIP_SSI_ISR_TXEIS_OFFSET)))
    {
        // Transmit FIFO empty
        debug_line("QSPI: Transmit FIFO empty!");
        // nothing more to send -> disable
        XIP_SSI->SSIENR = 0;
        qspi_active = false;
    }
    if(0 != (irq & (1 << XIP_SSI_ISR_TXOIS_OFFSET)))
    {
        // Transmit FIFO overflow
        debug_line("QSPI: Transmit FIFO overflow!");
        read = XIP_SSI->TXOICR;
    }
    if(0 != (irq & (1 << XIP_SSI_ISR_RXUIS_OFFSET)))
    {
        // Receive FIFO underflow
        debug_line("QSPI: Receive FIFO underflow!");
        read = XIP_SSI->RXUICR;
    }
    if(0 != (irq & (1 << XIP_SSI_ISR_RXOIS_OFFSET)))
    {
        // Receive FIFO overflow
        debug_line("QSPI: Receive FIFO overflow!");
        read = XIP_SSI->TXOICR;
    }
    if(0 != (irq & (1 << XIP_SSI_ISR_RXFIS_OFFSET)))
    {
        // Receive FIFO full
        debug_line("QSPI: Receive FIFO full!");
    }
    if(0 != (irq & (1 << XIP_SSI_ISR_MSTIS_OFFSET)))
    {
        // Multi-master contention interrupt status
        debug_line("QSPI: Multi-master contention!");
        read = XIP_SSI->MSTICR;
    }
    read = XIP_SSI->ICR;
}

void qspi_transfere(const uint8_t *tx, uint8_t *rx, size_t count)
{
    uint32_t i;
    XIP_SSI->SSIENR = 0;  // disabled
    XIP_SSI->CTRLR0 = (1 << XIP_SSI_CTRLR0_SSTE_OFFSET)
                    //  | (7 << XIP_SSI_CTRLR0_DFS_32_OFFSET)  // data frame : n -> n+1 clocks per frame
                      | (7 << XIP_SSI_CTRLR0_CFS_OFFSET)  // control frame : n -> n+1 clocks per frame
                      | (1 << XIP_SSI_CTRLR0_SLV_OE_OFFSET)
                      | ((count -1) << XIP_SSI_CTRLR0_DFS_OFFSET);
    XIP_SSI->CTRLR1 = count -1; // Number of Data Frames
    XIP_SSI->SPI_CTRLR0 = ((uint32_t)(tx[0] & 0xff) << XIP_SSI_SPI_CTRLR0_XIP_CMD_OFFSET)
                          | (1 << XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN_OFFSET)
                          | (XIP_SSI_SPI_CTRLR0_INST_L_8B << XIP_SSI_SPI_CTRLR0_INST_L_OFFSET);
    XIP_SSI->SSIENR = 1;  // enabled
    qspi_active = true;
    for(i = 1; i < count; i++)
    {
        XIP_SSI->DR0 = (uint32_t)tx[i];
    }
    while(0 == ((1 << XIP_SSI_SR_TFE_OFFSET) & XIP_SSI->SR)) // QSPI is sending
    {
        ;
    }
    if(NULL != rx)
    {
        for(i = 0; i < count; i++)
        {
            rx[i] = (uint8_t)XIP_SSI->DR0;
        }
    }
}
