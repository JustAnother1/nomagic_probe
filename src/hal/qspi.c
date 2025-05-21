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
#include "hal/hw/IO_QSPI.h"
#include "hal/hw/PADS_QSPI.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/XIP_CTRL.h"
#include "hal/hw/XIP_SSI.h"
#include "hal/debug_uart.h"
#include "hal/time_base.h"
#include "probe_api/debug_log.h"
#include "hal/qspi.h"
#include "hal/qspi_flash.h"
#include "hal/irq.h"


// Make sure there is never more data in flight than the depth of the RX
// FIFO. Otherwise, when we are interrupted for long periods, hardware
// will overflow the RX FIFO.
#define MAX_IN_FLIGHT (16 - 2) // account for data internal to SSI


static void manual_nCS_deselect(void);
static void manual_nCS_select(void);
static void flash_put_get(const uint8_t *tx, uint8_t *rx, size_t count, size_t rx_skip);
static void flash_put_cmd_addr(uint8_t cmd, uint32_t addr);
static void flash_wait_ready();
static void flash_do_cmd(uint8_t cmd, const uint8_t *tx, uint8_t *rx, size_t count);
static void reset_qspi(void);
static void init_qspi_pads(void);
static void init_qspi_gpio(void);
static void pads_qspi_output_disabled_pull_up(void);
static void pads_qspi_output_disabled_pull_down(void);
static void init_xip_ssi(void);
static void init_xip_ctrl(void);


void qspi_init(void)
{
    uint8_t buf[2];
    buf[0] = 0xff;
    buf[1] = 0xff;

    reset_qspi();
    init_qspi_pads();
    init_qspi_gpio();
    init_xip_ctrl();
    init_xip_ssi();

// make sure we are not in XIP mode (Continuous Read Mode)
// Sequence:
// 1. CSn = 1, IO = 4'h0 (via pull-down to avoid contention), x32 clocks
// 2. CSn = 0, IO = 4'hf (via pull-up to avoid contention), x32 clocks
// 3. CSn = 1 (brief deassertion)
// 4. CSn = 0, MOSI = 1'b1 driven, x16 clocks
//
// Part 4 is the sequence suggested in W25X10CL data sheet.
// Parts 1 and 2 are to improve compatibility with Micron parts

// 1. CSn = 1, IO = 4'h0 (via pull-down to avoid contention), x32 clocks
    // First two 32-clock sequences
    // CSn is held high for the first 32 clocks, then asserted low for next 32
    manual_nCS_deselect();
    pads_qspi_output_disabled_pull_down();
    // Brief delay (~6000 cycles) for pulls to take effect
    delay_us(50);
    flash_put_get(NULL, NULL, 4, 0);  // output is disabled !
    manual_nCS_deselect();
    delay_us(50);
    manual_nCS_select();
    delay_us(50);

// 2. CSn = 0, IO = 4'hf (via pull-up to avoid contention), x32 clocks
    pads_qspi_output_disabled_pull_up();
    // Brief delay (~6000 cycles) for pulls to take effect
    delay_us(50);
    flash_put_get(NULL, NULL, 4, 0); // output is disabled !

// 3. CSn = 1 (brief deassertion)
    manual_nCS_deselect();
    delay_us(50);
    manual_nCS_select();

// 4. CSn = 0, MOSI = 1'b1 driven, x16 clocks
    init_qspi_pads();
    delay_us(50);
    manual_nCS_select();
    flash_put_get(buf, NULL, 2, 0);
    manual_nCS_deselect();
}

static void reset_qspi(void)
{
    uint32_t reset_mask = (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET);

    // power on QSPI
    PSM->FRCE_ON =  PSM->FRCE_ON | (1 << PSM_FRCE_ON_XIP_OFFSET);

    // reset QSPI
    RESETS->RESET = RESETS->RESET | reset_mask;

    RESETS->RESET = RESETS->RESET & ~reset_mask;

    // wait for reset done
    do{
        ;
    } while(reset_mask != (RESETS->RESET_DONE & reset_mask));
}

static void init_qspi_pads(void)
{
    PADS_QSPI->VOLTAGE_SELECT = 0;  // 3.3V
    PADS_QSPI->GPIO_QSPI_SCLK = (1<< PADS_QSPI_GPIO_QSPI_SCLK_IE_OFFSET)         // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_PDE_OFFSET)       // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT_OFFSET)   // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST_OFFSET); // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD0 = (1<< PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET)           // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_PDE_OFFSET)        // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET)    // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD1 = (1<< PADS_QSPI_GPIO_QSPI_SD1_IE_OFFSET)           // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD1_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_PDE_OFFSET)        // Pull down enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SCHMITT_OFFSET)    // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST_OFFSET);  // slew rate fast
// put pull-up on SD2/SD3 as these may be used as WPn/HOLDn
    PADS_QSPI->GPIO_QSPI_SD2 =  (1<< PADS_QSPI_GPIO_QSPI_SD2_IE_OFFSET)          // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD2_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_PUE_OFFSET)        // Pull up enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SCHMITT_OFFSET)    // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SD3 =  (1<< PADS_QSPI_GPIO_QSPI_SD3_IE_OFFSET)          // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD3_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_PUE_OFFSET)        // Pull up enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_SCHMITT_OFFSET)    // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST_OFFSET);  // slew rate fast
    PADS_QSPI->GPIO_QSPI_SS = (1<< PADS_QSPI_GPIO_QSPI_SS_IE_OFFSET)             // Input enable
                              | (PADS_QSPI_GPIO_QSPI_SS_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SS_DRIVE_OFFSET)
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_PUE_OFFSET)         // Pull up enable
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_SCHMITT_OFFSET)     // enable schmitt trigger
                              | (1 << PADS_QSPI_GPIO_QSPI_SS_SLEWFAST_OFFSET);   // slew rate fast
}

static void pads_qspi_output_disabled_pull_up(void)
{
    uint32_t val = (1 < PADS_QSPI_GPIO_QSPI_SD0_OD_OFFSET)            // output disabled
                 | (1<< PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET)           // Input enable
                 | (PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET)
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_PUE_OFFSET)        // Pull up enable
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET)    // enable schmitt trigger
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET);  // slew rate fast

    PADS_QSPI->GPIO_QSPI_SD0 = val;
    PADS_QSPI->GPIO_QSPI_SD1 = val;
    PADS_QSPI->GPIO_QSPI_SD2 = val;
    PADS_QSPI->GPIO_QSPI_SD3 = val;
}

static void pads_qspi_output_disabled_pull_down(void)
{
    uint32_t val = (1 < PADS_QSPI_GPIO_QSPI_SD0_OD_OFFSET)          // output disabled
                 | (1<< PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET)          // Input enable
                 | (PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA << PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET)
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_PDE_OFFSET)        // Pull down enable
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET)    // enable schmitt trigger
                 | (1 << PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET);  // slew rate fast

    PADS_QSPI->GPIO_QSPI_SD0 = val;
    PADS_QSPI->GPIO_QSPI_SD1 = val;
    PADS_QSPI->GPIO_QSPI_SD2 = val;
    PADS_QSPI->GPIO_QSPI_SD3 = val;
}

static void init_qspi_gpio(void)
{
    IO_QSPI->GPIO_QSPI_SCLK_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SS_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD0_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD1_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD2_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD3_CTRL = 0;
    IO_QSPI->INTR = 0xcccccc; // write to clear
    IO_QSPI->PROC0_INTE = 0;
    IO_QSPI->PROC0_INTF = 0;
    IO_QSPI->PROC1_INTE = 0;
    IO_QSPI->PROC1_INTF = 0;
    IO_QSPI->DORMANT_WAKE_INTE = 0;
    IO_QSPI->DORMANT_WAKE_INTF = 0;
}

static void manual_nCS_deselect(void)
{
    // wait for TFE (Transmit FIFO Empty) = 1
    while(XIP_SSI_SR_TFE_MASK != (XIP_SSI->SR & XIP_SSI_SR_TFE_MASK))
    {
        ;
    }
    // wait for busy = idle
    while(XIP_SSI_SR_BUSY_MASK == (XIP_SSI->SR & XIP_SSI_SR_BUSY_MASK))
    {
        ;
    }
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~((uint32_t)IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK))
            | (3 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}

static void manual_nCS_select(void)
{
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~((uint32_t)IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK))
            | (2 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}

static void init_xip_ctrl(void)
{
    XIP_CTRL->CTRL = 0;  // ignore bad memory accesses, keep cache powered
    // XIP_CTRL->FLUSH = (1 << XIP_CTRL_FLUSH_FLUSH_OFFSET);  // flush cache <- not needed, halts CPU
}

static void init_xip_ssi(void)
{
    volatile uint32_t help = 0;
    (void)help;

    // Disable SSI for further configuration
    XIP_SSI->SSIENR = 0;

    XIP_SSI->SER = (1 << XIP_SSI_SER_SER_OFFSET); // slave selected
    XIP_SSI->BAUDR = (QSPI_BAUDRATE_DIVIDOR << XIP_SSI_BAUDR_SCKDV_OFFSET);  // set baud rate
    XIP_SSI->TXFTLR = 0; // TX FIFO threshold
    XIP_SSI->RXFTLR = 0; // RX FIFO threshold
    XIP_SSI->IMR = 0;  // no interrupts masked
    //XIP_SSI->IMR = 0x3f; // all interrupts are masked
    XIP_SSI->DMACR = 0;  // no DMA
    XIP_SSI->DMATDLR = 0; // transmit data watermark level
    XIP_SSI->DMARDLR = 4; // receive data watermark level (data sheet says it should not be changed from 4)
    XIP_SSI->RX_SAMPLE_DLY = (1 << XIP_SSI_RX_SAMPLE_DLY_RSD_OFFSET);  // delay in System clock cycles
    XIP_SSI->TXD_DRIVE_EDGE = 0;

    // Set up the SSI controller for standard SPI mode,i.e. for every byte sent we get one back
    XIP_SSI->CTRLR0 =  //TODO Quad SPI, 32bit
            // SSTE = Slave select toggle enable
            (XIP_SSI_CTRLR0_SPI_FRF_STD << XIP_SSI_CTRLR0_SPI_FRF_OFFSET) | // Standard 1-bit SPI serial frames
            (7 << XIP_SSI_CTRLR0_DFS_32_OFFSET) | // 8 clocks per data frame
            (XIP_SSI_CTRLR0_TMOD_TX_AND_RX << XIP_SSI_CTRLR0_TMOD_OFFSET);  // TX and RX FIFOs are both used for every byte
            // CFS = Control Frame size = Microwire only !
            // SRL = Shift Register loop (test mode)
            // SLV_OE = Slave Output enable
            // SPI MOD = 0 = (SCPOL = 0; SCPH = 0)
            // FRF = 00 = Motorola SPI
            // DFS = invalid (dfs_32 is used) writing has no effect!
    XIP_SSI->CTRLR1 = 0; // NDF = 0 = number of data frames used with Quad SPI // TODO
    XIP_SSI->SPI_CTRLR0 =  // TODO
              (3 << XIP_SSI_SPI_CTRLR0_XIP_CMD_OFFSET) //  SPI Command 0x03 = read
            | (0 << XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_OFFSET)
            | (XIP_SSI_SPI_CTRLR0_INST_L_8B<<XIP_SSI_SPI_CTRLR0_INST_L_OFFSET)
            | (6<<XIP_SSI_SPI_CTRLR0_ADDR_L_OFFSET); // in 4 bit increments -> 24 bit = 6
    help = XIP_SSI->ICR;  // clear all active interrupts
    // Clear sticky errors (clear-on-read)
    help = XIP_SSI->SR;
    help = XIP_SSI->ICR;

    // Re-enable
    XIP_SSI->SSIENR = 1;
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
    size_t tx_count = count;
    size_t rx_count = count;
    while((0 != tx_count) || (0 != rx_skip) || (0 != rx_count))
    {
        // NB order of reads, for pessimism rather than optimism
        uint32_t tx_level = XIP_SSI->TXFLR;
        uint32_t rx_level = XIP_SSI->RXFLR;
        if(   (0 != tx_count)   // we still want to send something
           && ((tx_level + rx_level) < MAX_IN_FLIGHT)) // if the rx bufer will not be filled even if we receive bytes for everything in the send buffer
        {
            if(NULL != tx)
            {
                XIP_SSI->DR0 = *tx; // send a byte
                tx++;
            }
            else
            {
                XIP_SSI->DR0 = 0; // send zero
            }
            --tx_count; // one less byte to send
        }
        if(0 != rx_level) // we received something
        {
            uint8_t rxbyte = (uint8_t)XIP_SSI->DR0; // get the next received byte
            if(0 != rx_skip)
            {
                --rx_skip; // we should skip this byte
            }
            else
            {
                if(NULL != rx) // the user is interested in what we read
                {
                    *rx++ = rxbyte; // then give the use the received byte
                }
                --rx_count; // one less byte that needs to arrive
            }
        }
    }
}

// Convenience wrapper for above
// (And it's hard for the debug host to get the tight timing between
// cmd DR0 write and the remaining data)
static void flash_do_cmd(uint8_t cmd, const uint8_t *tx, uint8_t *rx, size_t count)
{
    manual_nCS_select();
    XIP_SSI->DR0 = cmd;
    flash_put_get(tx, rx, count, 1);
    manual_nCS_deselect();
}

static void flash_put_cmd_addr(uint8_t cmd, uint32_t addr)
{
    manual_nCS_select();
    addr |= cmd << 24;
    for(int i = 0; i < 4; ++i)
    {
        XIP_SSI->DR0 = addr >> 24;
        addr = (addr << 8);
    }
}

// Poll the flash status register until the busy bit (LSB) clears
static void flash_wait_ready()
{
    uint8_t status;
    do
    {
        yield();
        flash_do_cmd(FLASHCMD_READ_STATUS, NULL, &status, 1);
    }while((status & STATUS_REGISTER_BUSY));
}

/// write exactly 256 Bytes
/// Program a 256 byte page at some 256-byte-aligned flash address,
/// from some buffer in memory. Blocks until completion.
void qspi_page_program_256(uint32_t start_address, uint8_t* data)
{
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
    manual_nCS_deselect();
    flash_wait_ready();
}

void qspi_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
    // debug_line("QSPI read");
    if(NULL == data)
    {
        debug_line("ERROR: QSPI read: no data pointer");
        return;
    }
    memset(data, 0x23, length);  // for testing
    // max 16MB are possible
    start_address  =  (start_address & 0xffffff);
    flash_put_cmd_addr(FLASHCMD_READ_DATA, start_address);
    flash_put_get(NULL, data, length, 4);
    manual_nCS_deselect();
}

void qspi_erase_sector(uint32_t number)
{
    flash_do_cmd(FLASHCMD_WRITE_ENABLE, NULL, NULL, 0);
    flash_put_cmd_addr(FLASHCMD_SECTOR_ERASE, (number*4096));
    flash_put_get(NULL, NULL, 0, 4);
    manual_nCS_deselect();
    flash_wait_ready();
}

bool qspi_detect(uint32_t loop)
{
    uint8_t data[12];
    memset(data, 0, sizeof(data));

    switch(loop)
    {
    case 0:
        flash_put_cmd_addr(FLASHCMD_MANUFACTURER_DEVICE_ID, 0);
        flash_put_get(NULL, data, 2, 4);
        manual_nCS_deselect();
        debug_line("Manufacturer      : 0x%02x", data[0]);
        debug_line("Device            : 0x%02x", data[1]);
        break;

    case 1:
        flash_do_cmd(FLASHCMD_READ_JEDEC_ID, NULL, data, 3);
        debug_line("JEDEC ID          : 0x%02x %02x %02x", data[0], data[1], data[2]);
        debug_line("manufacturer      : 0x%02x", data[0]);
        debug_line("memory type       : 0x%02x", data[1]);
        debug_line("capacity          : 0x%02x", data[2]);
        break;

    case 2:
        flash_do_cmd(FLASHCMD_READ_UNIQUE_ID, NULL, data, 12);
        debug_line("unique ID         : 0x%02x %02x %02x %02x %02x %02x %02x %02x",
                   data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11]);
        break;

    case 3:
        flash_do_cmd(FLASHCMD_READ_STATUS, NULL, data, 1);
        debug_line("status register 1 : 0x%02x", data[0]);
        break;

    case 4:
        flash_do_cmd(FLASHCMD_READ_STATUS_2, NULL, data, 1);
        debug_line("status register 2 : 0x%02x", data[0]);
        break;

    case 5:
        flash_do_cmd(FLASHCMD_READ_STATUS_3, NULL, data, 1);
        debug_line("status register 3 : 0x%02x", data[0]);
        break;

    // TODO : read SFDP (FLASHCMD_READ_SFDP) and parse data (256 Bytes)

    default : return true; // we are done
    }
    return false;
}





// void XIP_IRQ(void) __attribute__ ((interrupt ("IRQ")));
/*
static void qspi_transfere(const uint8_t *tx, uint8_t *rx, size_t count);
static void qspi_transfere_no_cmd(const uint8_t *tx, uint8_t *rx, size_t count);
*/

/*


// NVIC_EnableIRQ(XIP_IRQ_NUMBER, XIP_IRQ_PRIORITY);



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
*/

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
