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

/*
 * parts of this code have been inspired by the RaspberryPi pico-bootrom-rp2040 code.
 * That code is licensed as BSD-3-Clause
 */

#include <string.h>

#include "qspi.h"
#include "startup.h"
#include "hal/hw/IO_QSPI.h"
#include "hal/hw/PADS_QSPI.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/XIP_CTRL.h"
#include "hal/hw/XIP_SSI.h"
#include "hal/debug_uart.h"
#include "hal/time_base.h"
#include "probe_api/debug_log.h"

#define STATUS_REGISTER_BUSY    1

// These are supported by almost any SPI flash
#define FLASHCMD_PAGE_PROGRAM     0x02
#define FLASHCMD_READ_DATA        0x03
#define FLASHCMD_READ_STATUS      0x05
#define FLASHCMD_WRITE_ENABLE     0x06
#define FLASHCMD_SECTOR_ERASE     0x20
#define FLASHCMD_READ_SFDP        0x5a
#define FLASHCMD_READ_JEDEC_ID    0x9f

void XIP_IRQ(void) __attribute__ ((interrupt ("IRQ")));

static void manual_CS_High(void);
static void manual_CS_Low(void);
static void flash_put_get(const uint8_t *tx, uint8_t *rx, size_t count, size_t rx_skip);
static void flash_exit_xip(void);

/*
static void qspi_transfere(const uint8_t *tx, uint8_t *rx, size_t count);
static void qspi_transfere_no_cmd(const uint8_t *tx, uint8_t *rx, size_t count);
*/

// XIP / SSI / QSPI peripheral:
static bool qspi_active;

void qspi_init(void)
{
    uint32_t reset_mask = (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET);
    volatile uint32_t help = 0;
    (void)help;

    // power on QSPI
    PSM->FRCE_ON =  PSM->FRCE_ON | (1 << PSM_FRCE_ON_XIP_OFFSET);

    // reset QSPI
    RESETS->RESET = RESETS->RESET | reset_mask;

    qspi_active = false;

    RESETS->RESET = RESETS->RESET & ~reset_mask;

    // wait for reset done
    do{
        help = (RESETS->RESET_DONE & reset_mask);
    } while(reset_mask != help);

    XIP_SSI->SSIENR = 0;  // disabled

    PADS_QSPI->VOLTAGE_SELECT = 0;  // 3.3V
    PADS_QSPI->GPIO_QSPI_SCLK = (1<< PADS_QSPI_GPIO_QSPI_SCLK_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_PDE_OFFSET)  // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD0 = (1<< PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_PDE_OFFSET)  // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD1 = (1<< PADS_QSPI_GPIO_QSPI_SD1_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD1_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_PDE_OFFSET)  // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD2 =  (1<< PADS_QSPI_GPIO_QSPI_SD2_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD2_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_PDE_OFFSET)  // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SCHMITT_OFFSET)  // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD3 =  (1<< PADS_QSPI_GPIO_QSPI_SD3_IE_OFFSET)  // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4mA << PADS_QSPI_GPIO_QSPI_SD3_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_PDE_OFFSET)  // Pull down enable
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

    // make sure we are not in XIP mode (Continuous Read Mode)
    flash_exit_xip();
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

/*
static void qspi_transfere(const uint8_t *tx, uint8_t *rx, size_t count)
{
    uint32_t i;
    // debug_line("QSPI Transfer: size %u bytes", count);
    XIP_SSI->SSIENR = 0;  // disabled
    XIP_SSI->CTRLR0 = (1 << XIP_SSI_CTRLR0_SSTE_OFFSET)
                      | (XIP_SSI_CTRLR0_SPI_FRF_STD << XIP_SSI_CTRLR0_SPI_FRF_OFFSET)
                      | (7 << XIP_SSI_CTRLR0_DFS_32_OFFSET)  // data frame : n -> n+1 clocks per frame
                      | (7 << XIP_SSI_CTRLR0_CFS_OFFSET)  // control frame : n -> n+1 clocks per frame
                    //   | (1 << XIP_SSI_CTRLR0_SLV_OE_OFFSET)
                      | (XIP_SSI_CTRLR0_TMOD_EEPROM_READ << XIP_SSI_CTRLR0_TMOD_OFFSET)
                      | (0 << XIP_SSI_CTRLR0_SCPOL_OFFSET) // clock polarity
                      | (0 << XIP_SSI_CTRLR0_SCPH_OFFSET)  // clock phase      cpol + cph = SPI Mode
                      | (0 << XIP_SSI_CTRLR0_FRF_OFFSET)   // FRF : frame format
                      | (7 << XIP_SSI_CTRLR0_DFS_OFFSET);  // data frame size
    XIP_SSI->CTRLR1 = count -1; // Number of Data Frames
    XIP_SSI->SPI_CTRLR0 = ((uint32_t)(tx[0] & 0xff) << XIP_SSI_SPI_CTRLR0_XIP_CMD_OFFSET)
                          | (1 << XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN_OFFSET)  // read data strobe enable
                          | (0 << XIP_SSI_SPI_CTRLR0_INST_DDR_EN_OFFSET)  // instruction double data rate enable
                          | (0 << XIP_SSI_SPI_CTRLR0_SPI_DDR_EN_OFFSET)   // SPI double data rate enable
                          | (0 << XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_OFFSET)  // wait cycles between control frame transmit and data frame receive
                          | (XIP_SSI_SPI_CTRLR0_INST_L_8B << XIP_SSI_SPI_CTRLR0_INST_L_OFFSET)  // INST_L : instruction length (0, 4, 8 or 16 bit)
                          | (0 << XIP_SSI_SPI_CTRLR0_ADDR_L_OFFSET)  // ADDR_L : address length (0, 4, 8, 12, 16, 20,...56, 60 bit)
                          | (XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C1A << XIP_SSI_SPI_CTRLR0_TRANS_TYPE_OFFSET); // Transfer Type (1 bit SPI or as defined in FRF)
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
    while(0 != (XIP_SSI_SR_BUSY_MASK & XIP_SSI->SR)) // QSPI is sending
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

static void qspi_transfere_no_cmd(const uint8_t *tx, uint8_t *rx, size_t count)
{
    uint32_t i;
    // debug_line("QSPI Transfer: size %u bytes", count);
    XIP_SSI->SSIENR = 0;  // disabled
    XIP_SSI->CTRLR0 = (1 << XIP_SSI_CTRLR0_SSTE_OFFSET)
                      | (XIP_SSI_CTRLR0_SPI_FRF_STD << XIP_SSI_CTRLR0_SPI_FRF_OFFSET)
                      | (7 << XIP_SSI_CTRLR0_DFS_32_OFFSET)  // data frame : n -> n+1 clocks per frame
                      | (7 << XIP_SSI_CTRLR0_CFS_OFFSET)  // control frame : n -> n+1 clocks per frame
                   //    | (1 << XIP_SSI_CTRLR0_SLV_OE_OFFSET)
                      | (XIP_SSI_CTRLR0_TMOD_TX_AND_RX << XIP_SSI_CTRLR0_TMOD_OFFSET)
                      | (0 << XIP_SSI_CTRLR0_SCPOL_OFFSET) // clock polarity
                      | (0 << XIP_SSI_CTRLR0_SCPH_OFFSET)  // clock phase      cpol + cph = SPI Mode
                      | (0 << XIP_SSI_CTRLR0_FRF_OFFSET)   // FRF : frame format
                      | (7 << XIP_SSI_CTRLR0_DFS_OFFSET);  // data frame size
    XIP_SSI->CTRLR1 = count -1; // Number of Data Frames
    XIP_SSI->SPI_CTRLR0 = (  0 << XIP_SSI_SPI_CTRLR0_XIP_CMD_OFFSET)
                          | (1 << XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN_OFFSET)  // read data strobe enable
                          | (0 << XIP_SSI_SPI_CTRLR0_INST_DDR_EN_OFFSET)  // instruction double data rate enable
                          | (0 << XIP_SSI_SPI_CTRLR0_SPI_DDR_EN_OFFSET)   // SPI double data rate enable
                          | (0 << XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_OFFSET)  // wait cycles between control frame transmit and data frame receive
                          | (XIP_SSI_SPI_CTRLR0_INST_L_8B << XIP_SSI_SPI_CTRLR0_INST_L_OFFSET)  // INST_L : instruction length (0, 4, 8 or 16 bit)
                          | (0 << XIP_SSI_SPI_CTRLR0_ADDR_L_OFFSET)  // ADDR_L : address length (0, 4, 8, 12, 16, 20,...56, 60 bit)
                          | (XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C1A << XIP_SSI_SPI_CTRLR0_TRANS_TYPE_OFFSET); // Transfer Type (1 bit SPI or as defined in FRF)
    XIP_SSI->SSIENR = 1;  // enabled
    qspi_active = true;
    for(i = 0; i < count; i++)
    {
        XIP_SSI->DR0 = (uint32_t)tx[i];
        // XIP_SSI->DR0 = 0x12345678;
    }
    while(0 == ((1 << XIP_SSI_SR_TFE_OFFSET) & XIP_SSI->SR)) // QSPI is sending
    {
        ;
    }
    while(0 != (XIP_SSI_SR_BUSY_MASK & XIP_SSI->SR)) // QSPI is sending
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
    // XIP_SSI->SSIENR = 0;  // disabled
}
*/

bool qspi_is_active(void)
{
    return qspi_active;
}

// Also allow any unbounded loops to check whether the above abort condition
// was asserted, and terminate early
uint32_t flash_was_aborted(void)
{
    // checks logic level of SD1 signal. (Not used in normal SPI mode, only used in Dual and Quad-SPI)
    return IO_QSPI->GPIO_QSPI_SD1_CTRL & IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_MASK;
}


static void manual_CS_High(void)
{
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~((uint32_t)IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK))
            | (3 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}

static void manual_CS_Low(void)
{
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~((uint32_t)IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK))
            | (2 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}


// Put bytes from one buffer, and get bytes into another buffer.
// These can be the same buffer.
// If tx is NULL then send zeroes.
// If rx is NULL then all read data will be dropped.
//
// If rx_skip is nonzero, this many bytes will first be consumed from the FIFO,
// before reading a further count bytes into *rx.
// E.g. if you have written a command+address just before calling this function.
static void flash_put_get(const uint8_t *tx, uint8_t *rx, size_t count, size_t rx_skip)
{
    // Make sure there is never more data in flight than the depth of the RX
    // FIFO. Otherwise, when we are interrupted for long periods, hardware
    // will overflow the RX FIFO.
    const uint32_t max_in_flight = 16 - 2; // account for data internal to SSI
    size_t tx_count = count;
    size_t rx_count = count;
    while (tx_count || rx_skip || rx_count)
    {
        // NB order of reads, for pessimism rather than optimism
        uint32_t tx_level = XIP_SSI->TXFLR;
        uint32_t rx_level = XIP_SSI->RXFLR;
        bool did_something = false; // Expect this to be folded into control flow, not register
        if(tx_count && tx_level + rx_level < max_in_flight)
        {
            XIP_SSI->DR0 = (uint32_t) (tx ? *tx++ : 0);
            --tx_count;
            did_something = true;
        }
        if(rx_level)
        {
            uint8_t rxbyte = (uint8_t)XIP_SSI->DR0;
            did_something = true;
            if (rx_skip)
            {
                --rx_skip;
            }
            else
            {
                if (rx)
                {
                    *rx++ = rxbyte;
                }
                --rx_count;
            }
        }
        if(!did_something && (flash_was_aborted() == 0))
        {
            break;
        }
    }
    manual_CS_High();
}

// Convenience wrapper for above
// (And it's hard for the debug host to get the tight timing between
// cmd DR0 write and the remaining data)
void flash_do_cmd(uint8_t cmd, const uint8_t *tx, uint8_t *rx, size_t count)
{
    manual_CS_Low();
    XIP_SSI->DR0 = cmd;
    flash_put_get(tx, rx, count, 1);
}

// Sequence:
// 1. CSn = 1, IO = 4'h0 (via pulldown to avoid contention), x32 clocks
// 2. CSn = 0, IO = 4'hf (via pullup to avoid contention), x32 clocks
// 3. CSn = 1 (brief deassertion)
// 4. CSn = 0, MOSI = 1'b1 driven, x16 clocks
//
// Part 4 is the sequence suggested in W25X10CL datasheet.
// Parts 1 and 2 are to improve compatibility with Micron parts

static void flash_exit_xip(void)
{
    uint32_t help;
    uint8_t buf[2];
    buf[0] = 0xff;
    buf[1] = 0xff;
    (void)help;

    // Set up the SSI controller for standard SPI mode,i.e. for every byte sent we get one back
    // Disable SSI for further configuration
    XIP_SSI->SSIENR = 0;
    // Clear sticky errors (clear-on-read)
    help = XIP_SSI->SR;
    help = XIP_SSI->ICR;
    // Hopefully-conservative baud rate for boot and programming
    XIP_SSI->BAUDR = 6;
    XIP_SSI->CTRLR0 =
            (XIP_SSI_CTRLR0_SPI_FRF_STD << XIP_SSI_CTRLR0_SPI_FRF_OFFSET) | // Standard 1-bit SPI serial frames
            (7 << XIP_SSI_CTRLR0_DFS_32_OFFSET) | // 8 clocks per data frame
            (XIP_SSI_CTRLR0_TMOD_TX_AND_RX << XIP_SSI_CTRLR0_TMOD_OFFSET);  // TX and RX FIFOs are both used for every byte
    // Slave selected when transfers in progress
    XIP_SSI->SER = 1;
    // Re-enable
    XIP_SSI->SSIENR = 1;

    uint32_t padctrl_save = PADS_QSPI->GPIO_QSPI_SD0;
    uint32_t padctrl_tmp = (padctrl_save & ~((uint32_t)(PADS_QSPI_GPIO_QSPI_SD0_OD_MASK
                                                      | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK
                                                      | PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK)))
                           | PADS_QSPI_GPIO_QSPI_SD0_OD_MASK
                           | PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK;

    // First two 32-clock sequences
    // CSn is held high for the first 32 clocks, then asserted low for next 32
    manual_CS_High();
    for (int i = 0; i < 2; ++i)
    {
        PADS_QSPI->GPIO_QSPI_SD0 = padctrl_tmp;
        PADS_QSPI->GPIO_QSPI_SD1 = padctrl_tmp;
        PADS_QSPI->GPIO_QSPI_SD2 = padctrl_tmp;
        PADS_QSPI->GPIO_QSPI_SD3 = padctrl_tmp;

        // Brief delay (~6000 cyc) for pulls to take effect
        delay_us(1);

        flash_put_get(NULL, NULL, 4, 0);

        padctrl_tmp = (padctrl_tmp & ~((uint32_t)PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK))
                      | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK;

        manual_CS_Low();
    }

    // Restore IO/pad controls, and send 0xff, 0xff. Put pullup on IO2/IO3 as
    // these may be used as WPn/HOLDn at this point, and we are now starting
    // to issue serial commands.

    PADS_QSPI->GPIO_QSPI_SD0 = padctrl_save;
    PADS_QSPI->GPIO_QSPI_SD1 = padctrl_save;
    padctrl_save = (padctrl_save & ~((uint32_t)PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK) )
                   | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK;

    PADS_QSPI->GPIO_QSPI_SD2 = padctrl_save;
    PADS_QSPI->GPIO_QSPI_SD3 = padctrl_save;

    manual_CS_Low();
    flash_put_get(buf, NULL, 2, 0);

    IO_QSPI->GPIO_QSPI_SS_CTRL = 0;
}

// Timing of this one is critical, so do not expose the symbol to debugger etc
static inline void flash_put_cmd_addr(uint8_t cmd, uint32_t addr)
{
    manual_CS_Low();
    addr |= cmd << 24;
    for(int i = 0; i < 4; ++i)
    {
        XIP_SSI->DR0 = addr >> 24;
        addr = (addr << 8);
    }
}

// Poll the flash status register until the busy bit (LSB) clears
static inline void flash_wait_ready()
{
    uint8_t status;
    do
    {
        yield();
        flash_do_cmd(FLASHCMD_READ_STATUS, NULL, &status, 1);
    }while((status & 0x1) && !flash_was_aborted());
}

/// write exactly 256 Bytes
void qspi_page_program_256(uint32_t start_address, uint8_t* data)
{
    // Program a 256 byte page at some 256-byte-aligned flash address,
    // from some buffer in memory. Blocks until completion.

    if(start_address < 0x1000000)
    {
        return;
    }
    if(0 != (start_address & 0xffu))
    {
        return;
    }
    flash_do_cmd(FLASHCMD_WRITE_ENABLE, NULL, NULL, 0);
    flash_put_cmd_addr(FLASHCMD_PAGE_PROGRAM, start_address);
    flash_put_get(data, NULL, 256, 4);
    flash_wait_ready();

    /*
    if((0 == length) || (NULL == data))
    {
        return;
    }
    qspi_wait_for_flash_not_busy();
    // command write enable = 0x06
    // command page program = 0x02
    // falling edge on /CS - write 0x02 - write 24bits(3 bytes) address - write up to 256 bytes as needed - rising edge of /CS

    // quad page program = 0x32
    (void)start_address; // TODO
*/
}

void qspi_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if(start_address < 0x1000000)
    {
        return;
    }
    if(0 != (start_address & 0xffu))
    {
        return;
    }
    if(NULL == data)
    {
        return;
    }
    memset(data, 0x23, length);  // for testing
    flash_put_cmd_addr(FLASHCMD_READ_DATA, start_address);
    flash_put_get(NULL, data, length, 4);
}

void qspi_erase_sector(uint32_t number)
{
    flash_do_cmd(FLASHCMD_WRITE_ENABLE, NULL, NULL, 0);
    flash_put_cmd_addr(FLASHCMD_SECTOR_ERASE, (number*4096));
    flash_put_get(NULL, NULL, 0, 4);
    flash_wait_ready();

    /*
    uint8_t tx_buf[4];
    uint8_t rx_buf[4];
    uint32_t address = number * 4096;
    qspi_wait_for_flash_not_busy();
    // command write enable = 0x06
    // command sector erase = 0x20
    // falling edge on /CS - write 0x20 - write 24bits(3 bytes) address - rising edge of /CS
    tx_buf[0] = 0x20;
    tx_buf[1] = (address & 0xff);
    tx_buf[2] = ((address >>8) & 0xff);
    tx_buf[3] = ((address >>16) & 0xff);
    rx_buf[0] = 0;
    rx_buf[1] = 0;
    rx_buf[2] = 0;
    rx_buf[3] = 0;
    qspi_transfere(tx_buf, rx_buf, 4);
    */
}


