#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "hal/hw/IO_QSPI.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/XIP_SSI.h"
#include "hal/hw/XIP_CTRL.h"
#include "hal/hw/PADS_QSPI.h"

// Register address offsets for atomic RMW aliases
#define REG_ALIAS_RW_BITS  (0x0u << 12u)
#define REG_ALIAS_XOR_BITS (0x1u << 12u)
#define REG_ALIAS_SET_BITS (0x2u << 12u)
#define REG_ALIAS_CLR_BITS (0x3u << 12u)

#define IO_QSPI_BASE   0x40018000
#define XIP_SSI_BASE   0x18000000
#define RESETS_BASE    0x4000c000
#define PADS_QSPI_BASE 0x40020000
#define XIP_CTRL_BASE  0x14000000

#define RESETS_RESET_IO_QSPI_BITS     0x00000040
#define RESETS_RESET_PADS_QSPI_BITS   0x00000200

// Register address offsets for atomic RMW aliases
#define REG_ALIAS_RW_BITS  (0x0u << 12u)
#define REG_ALIAS_XOR_BITS (0x1u << 12u)
#define REG_ALIAS_SET_BITS (0x2u << 12u)
#define REG_ALIAS_CLR_BITS (0x3u << 12u)

// =============================================================================
// Register    : IO_QSPI_GPIO_QSPI_SS_CTRL
// Description : GPIO control including function select and overrides.
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OFFSET 0x0000000c
#define IO_QSPI_GPIO_QSPI_SS_CTRL_BITS   0x3003331f
#define IO_QSPI_GPIO_QSPI_SS_CTRL_RESET  0x0000001f

// -----------------------------------------------------------------------------
// Field       : IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER
// Description : 0x0 -> drive output from peripheral signal selected by funcsel
//               0x1 -> drive output from inverse of peripheral signal selected
//               by funcsel
//               0x2 -> drive output low
//               0x3 -> drive output high
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_RESET        0x0
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_BITS         0x00000300
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MSB          9
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_LSB          8
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_ACCESS       "RW"
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_VALUE_NORMAL 0x0
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_VALUE_INVERT 0x1
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_VALUE_LOW    0x2
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_VALUE_HIGH   0x3

// -----------------------------------------------------------------------------
// Field       : SSI_CTRLR0_SPI_FRF
// Description : SPI frame format
//               0x0 -> Standard 1-bit SPI frame format; 1 bit per SCK,
//               full-duplex
//               0x1 -> Dual-SPI frame format; two bits per SCK, half-duplex
//               0x2 -> Quad-SPI frame format; four bits per SCK, half-duplex
#define SSI_CTRLR0_SPI_FRF_RESET      0x0
#define SSI_CTRLR0_SPI_FRF_BITS       0x00600000
#define SSI_CTRLR0_SPI_FRF_MSB        22
#define SSI_CTRLR0_SPI_FRF_LSB        21
#define SSI_CTRLR0_SPI_FRF_ACCESS     "RW"
#define SSI_CTRLR0_SPI_FRF_VALUE_STD  0x0
#define SSI_CTRLR0_SPI_FRF_VALUE_DUAL 0x1
#define SSI_CTRLR0_SPI_FRF_VALUE_QUAD 0x2

// -----------------------------------------------------------------------------
// Field       : SSI_CTRLR0_DFS_32
// Description : Data frame size in 32b transfer mode
//               Value of n -> n+1 clocks per frame.
#define SSI_CTRLR0_DFS_32_RESET  0x00
#define SSI_CTRLR0_DFS_32_BITS   0x001f0000
#define SSI_CTRLR0_DFS_32_MSB    20
#define SSI_CTRLR0_DFS_32_LSB    16
#define SSI_CTRLR0_DFS_32_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : SSI_CTRLR0_TMOD
// Description : Transfer mode
//               0x0 -> Both transmit and receive
//               0x1 -> Transmit only (not for FRF == 0, standard SPI mode)
//               0x2 -> Receive only (not for FRF == 0, standard SPI mode)
//               0x3 -> EEPROM read mode (TX then RX; RX starts after control
//               data TX'd)
#define SSI_CTRLR0_TMOD_RESET             0x0
#define SSI_CTRLR0_TMOD_BITS              0x00000300
#define SSI_CTRLR0_TMOD_MSB               9
#define SSI_CTRLR0_TMOD_LSB               8
#define SSI_CTRLR0_TMOD_ACCESS            "RW"
#define SSI_CTRLR0_TMOD_VALUE_TX_AND_RX   0x0
#define SSI_CTRLR0_TMOD_VALUE_TX_ONLY     0x1
#define SSI_CTRLR0_TMOD_VALUE_RX_ONLY     0x2
#define SSI_CTRLR0_TMOD_VALUE_EEPROM_READ 0x3

// =============================================================================
// Register    : PADS_QSPI_GPIO_QSPI_SD0
// Description : Pad control register
#define PADS_QSPI_GPIO_QSPI_SD0_OFFSET 0x00000008
#define PADS_QSPI_GPIO_QSPI_SD0_BITS   0x000000ff
#define PADS_QSPI_GPIO_QSPI_SD0_RESET  0x00000052

// -----------------------------------------------------------------------------
// Field       : PADS_QSPI_GPIO_QSPI_SD0_OD
// Description : Output disable. Has priority over output enable from
//               peripherals
#define PADS_QSPI_GPIO_QSPI_SD0_OD_RESET  0x0
#define PADS_QSPI_GPIO_QSPI_SD0_OD_BITS   0x00000080
#define PADS_QSPI_GPIO_QSPI_SD0_OD_MSB    7
#define PADS_QSPI_GPIO_QSPI_SD0_OD_LSB    7
#define PADS_QSPI_GPIO_QSPI_SD0_OD_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : PADS_QSPI_GPIO_QSPI_SD0_PUE
// Description : Pull up enable
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_RESET  0x0
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_BITS   0x00000008
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_MSB    3
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_LSB    3
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : PADS_QSPI_GPIO_QSPI_SD0_PDE
// Description : Pull down enable
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_RESET  0x0
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_BITS   0x00000004
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_MSB    2
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_LSB    2
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_ACCESS "RW"

// =============================================================================
// Register    : IO_QSPI_GPIO_QSPI_SD1_CTRL
// Description : GPIO control including function select and overrides.
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OFFSET 0x0000001c
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_BITS   0x3003331f
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_RESET  0x0000001f

// -----------------------------------------------------------------------------
// Field       : IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER
// Description : 0x0 -> don't invert the peri input
//               0x1 -> invert the peri input
//               0x2 -> drive peri input low
//               0x3 -> drive peri input high
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_RESET        0x0
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_BITS         0x00030000
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_MSB          17
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_LSB          16
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_ACCESS       "RW"
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_VALUE_NORMAL 0x0
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_VALUE_INVERT 0x1
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_VALUE_LOW    0x2
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_VALUE_HIGH   0x3

// -----------------------------------------------------------------------------
// Field       : XIP_CTRL_EN
// Description : When 1, enable the cache. When the cache is disabled, all XIP
//               accesses
//               will go straight to the flash, without querying the cache. When
//               enabled,
//               cacheable XIP accesses will query the cache, and the flash will
//               not be accessed if the tag matches and the valid bit is set.
//
//               If the cache is enabled, cache-as-SRAM accesses have no effect
//               on the
//               cache data RAM, and will produce a bus error response.
#define XIP_CTRL_EN_RESET  0x1
#define XIP_CTRL_EN_BITS   0x00000001
#define XIP_CTRL_EN_MSB    0
#define XIP_CTRL_EN_LSB    0
#define XIP_CTRL_EN_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : SSI_SPI_CTRLR0_XIP_CMD
// Description : SPI Command to send in XIP mode (INST_L = 8-bit) or to append
//               to Address (INST_L = 0-bit)
#define SSI_SPI_CTRLR0_XIP_CMD_RESET  0x03
#define SSI_SPI_CTRLR0_XIP_CMD_BITS   0xff000000
#define SSI_SPI_CTRLR0_XIP_CMD_MSB    31
#define SSI_SPI_CTRLR0_XIP_CMD_LSB    24
#define SSI_SPI_CTRLR0_XIP_CMD_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : SSI_SPI_CTRLR0_INST_L
// Description : Instruction length (0/4/8/16b)
//               0x0 -> No instruction
//               0x1 -> 4-bit instruction
//               0x2 -> 8-bit instruction
//               0x3 -> 16-bit instruction
#define SSI_SPI_CTRLR0_INST_L_RESET      0x0
#define SSI_SPI_CTRLR0_INST_L_BITS       0x00000300
#define SSI_SPI_CTRLR0_INST_L_MSB        9
#define SSI_SPI_CTRLR0_INST_L_LSB        8
#define SSI_SPI_CTRLR0_INST_L_ACCESS     "RW"
#define SSI_SPI_CTRLR0_INST_L_VALUE_NONE 0x0
#define SSI_SPI_CTRLR0_INST_L_VALUE_4B   0x1
#define SSI_SPI_CTRLR0_INST_L_VALUE_8B   0x2
#define SSI_SPI_CTRLR0_INST_L_VALUE_16B  0x3

// -----------------------------------------------------------------------------
// Field       : SSI_SPI_CTRLR0_ADDR_L
// Description : Address length (0b-60b in 4b increments)
#define SSI_SPI_CTRLR0_ADDR_L_RESET  0x0
#define SSI_SPI_CTRLR0_ADDR_L_BITS   0x0000003c
#define SSI_SPI_CTRLR0_ADDR_L_MSB    5
#define SSI_SPI_CTRLR0_ADDR_L_LSB    2
#define SSI_SPI_CTRLR0_ADDR_L_ACCESS "RW"

// -----------------------------------------------------------------------------
// Field       : SSI_SPI_CTRLR0_TRANS_TYPE
// Description : Address and instruction transfer format
//               0x0 -> Command and address both in standard SPI frame format
//               0x1 -> Command in standard SPI format, address in format
//               specified by FRF
//               0x2 -> Command and address both in format specified by FRF
//               (e.g. Dual-SPI)
#define SSI_SPI_CTRLR0_TRANS_TYPE_RESET      0x0
#define SSI_SPI_CTRLR0_TRANS_TYPE_BITS       0x00000003
#define SSI_SPI_CTRLR0_TRANS_TYPE_MSB        1
#define SSI_SPI_CTRLR0_TRANS_TYPE_LSB        0
#define SSI_SPI_CTRLR0_TRANS_TYPE_ACCESS     "RW"
#define SSI_SPI_CTRLR0_TRANS_TYPE_VALUE_1C1A 0x0
#define SSI_SPI_CTRLR0_TRANS_TYPE_VALUE_1C2A 0x1
#define SSI_SPI_CTRLR0_TRANS_TYPE_VALUE_2C2A 0x2






typedef volatile uint32_t io_rw_32;
typedef const volatile uint32_t io_ro_32;
typedef volatile uint32_t io_wo_32;
typedef volatile uint16_t io_rw_16;
typedef const volatile uint16_t io_ro_16;
typedef volatile uint16_t io_wo_16;
typedef volatile uint8_t io_rw_8;
typedef const volatile uint8_t io_ro_8;
typedef volatile uint8_t io_wo_8;

typedef volatile uint8_t *const ioptr;
typedef ioptr const const_ioptr;

/*
typedef struct {
    io_rw_32 ctrlr0;
    io_rw_32 ctrlr1;
    io_rw_32 ssienr;
    io_rw_32 mwcr;
    io_rw_32 ser;
    io_rw_32 baudr;
    io_rw_32 txftlr;
    io_rw_32 rxftlr;
    io_rw_32 txflr;
    io_rw_32 rxflr;
    io_rw_32 sr;
    io_rw_32 imr;
    io_rw_32 isr;
    io_rw_32 risr;
    io_rw_32 txoicr;
    io_rw_32 rxoicr;
    io_rw_32 rxuicr;
    io_rw_32 msticr;
    io_rw_32 icr;
    io_rw_32 dmacr;
    io_rw_32 dmatdlr;
    io_rw_32 dmardlr;
    io_rw_32 idr;
    io_rw_32 ssi_version_id;
    io_rw_32 dr0;
    uint32_t _pad[(0xf0 - 0x60) / 4 - 1];
    io_rw_32 rx_sample_dly;
    io_rw_32 spi_ctrlr0;
    io_rw_32 txd_drive_edge;
} ssi_hw_t; */

// #define ssi_hw ((ssi_hw_t *const)XIP_SSI_BASE)

/*
typedef struct {
    io_rw_32 ctrl;
    io_rw_32 flush;
    io_rw_32 stat;
    io_rw_32 ctr_hit;
    io_rw_32 ctr_acc;
    io_rw_32 stream_addr;
    io_rw_32 stream_ctr;
    io_rw_32 stream_fifo;
} xip_ctrl_hw_t; */

#define XIP_STAT_FIFO_FULL     0x4u
#define XIP_STAT_FIFO_EMPTY    0x2u
#define XIP_STAT_FLUSH_RDY     0x1u

// #define xip_ctrl_hw ((xip_ctrl_hw_t *const)XIP_CTRL_BASE)


// Annoyingly, structs give much better code generation, as they re-use the base
// pointer rather than doing a PC-relative load for each constant pointer.

// static ssi_hw_t *const ssi = (ssi_hw_t *) XIP_SSI_BASE;

typedef enum {
    OUTOVER_NORMAL = 0,
    OUTOVER_INVERT,
    OUTOVER_LOW,
    OUTOVER_HIGH
} outover_t;

// These are supported by almost any SPI flash
#define FLASHCMD_PAGE_PROGRAM     0x02
#define FLASHCMD_READ_DATA        0x03
#define FLASHCMD_READ_STATUS      0x05
#define FLASHCMD_WRITE_ENABLE     0x06
#define FLASHCMD_SECTOR_ERASE     0x20
#define FLASHCMD_READ_SFDP        0x5a
#define FLASHCMD_READ_JEDEC_ID    0x9f



static void manual_CS_High(void)
{
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK)
            | (3 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}

static void manual_CS_Low(void)
{
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK)
            | (2 << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}






















/*
.global reset_unreset_block_wait_noinline
.type reset_unreset_block_wait_noinline,%function
.thumb_func
reset_unreset_block_wait_noinline:
    ldr r1, =RESETS_BASE + REG_ALIAS_SET_BITS
    str r0, [r1]
    // fall thru

.global unreset_block_wait_noinline
.type unreset_block_wait_noinline,%function
.thumb_func
unreset_block_wait_noinline:
    ldr r1, =RESETS_BASE
    ldr r2, =RESETS_BASE + REG_ALIAS_CLR_BITS
    str r0, [r2]
1:
    ldr r2, [r1, #RESETS_RESET_DONE_OFFSET]
    bic r0, r2
    bne 1b
    bx lr
*/

// Connect the XIP controller to the flash pads
void connect_internal_flash()
{// F
    // Use hard reset to force IO and pad controls to known state (don't touch
    // IO_BANK0 as that does not affect XIP signals)

    // reset QSPI
    RESETS->RESET = RESETS->RESET | (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET);


    RESETS->RESET = RESETS->RESET &~(uint32_t)( (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET));

    // wait for reset done
    while(                            (1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET)
          != (RESETS->RESET_DONE & (~((1 << RESETS_RESET_IO_QSPI_OFFSET) | (1 << RESETS_RESET_PADS_QSPI_OFFSET)))) )
    {
        ;
    }

    // Then mux XIP block onto internal QSPI flash pads
    IO_QSPI->GPIO_QSPI_SCLK_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SS_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD0_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD1_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD2_CTRL = 0;
    IO_QSPI->GPIO_QSPI_SD3_CTRL = 0;
}


















































// Put bytes from one buffer, and get bytes into another buffer.
// These can be the same buffer.
// If tx is NULL then send zeroes.
// If rx is NULL then all read data will be dropped.
//
// If rx_skip is nonzero, this many bytes will first be consumed from the FIFO,
// before reading a further count bytes into *rx.
// E.g. if you have written a command+address just before calling this function.
void flash_put_get(const uint8_t *tx, uint8_t *rx, size_t count, size_t rx_skip)
{
    // Make sure there is never more data in flight than the depth of the RX
    // FIFO. Otherwise, when we are interrupted for long periods, hardware
    // will overflow the RX FIFO.
    const uint max_in_flight = 16 - 2; // account for data internal to SSI
    size_t tx_count = count;
    size_t rx_count = count;
    while (tx_count || rx_skip || rx_count)
    {
        // NB order of reads, for pessimism rather than optimism
        uint32_t tx_level = XIP_SSI->TXFLR;
        uint32_t rx_level = XIP_SSI->RXFLR;
        bool did_something = false; // Expect this to be folded into control flow, not register
        if (tx_count && tx_level + rx_level < max_in_flight)
        {
            XIP_SSI->DR0 = (uint32_t) (tx ? *tx++ : 0);
            --tx_count;
            did_something = true;
        }
        if (rx_level)
        {
            uint8_t rxbyte = XIP_SSI->DR0;
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
        // APB load costs 4 cycles, so only do it on idle loops (our budget is 48 cyc/byte)
        if(!did_something && (flash_was_aborted() == 0))
        {
            break;
        }
    }
    manual_CS_High();
}


// Flash code may be heavily interrupted (e.g. if we are running USB MSC
// handlers concurrently with flash programming) so we control the CS pin
// manually
/*
static void flash_cs_force(outover_t over)
{// F
    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK)
            | (over << IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_OFFSET);
}
*/
// Sequence:
// 1. CSn = 1, IO = 4'h0 (via pulldown to avoid contention), x32 clocks
// 2. CSn = 0, IO = 4'hf (via pullup to avoid contention), x32 clocks
// 3. CSn = 1 (brief deassertion)
// 4. CSn = 0, MOSI = 1'b1 driven, x16 clocks
//
// Part 4 is the sequence suggested in W25X10CL datasheet.
// Parts 1 and 2 are to improve compatibility with Micron parts

void flash_exit_xip()
{
    volatile uint32_t help;
    uint8_t buf[2];
    buf[0] = 0xff;
    buf[1] = 0xff;

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
    uint32_t padctrl_tmp = (padctrl_save
                            & ~(PADS_QSPI_GPIO_QSPI_SD0_OD_MASK | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK |
                                    PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK)
                           ) | PADS_QSPI_GPIO_QSPI_SD0_OD_MASK | PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK;

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

        padctrl_tmp = (padctrl_tmp
                       & ~PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK)
                      | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK;

        manual_CS_Low();
    }

    // Restore IO/pad controls, and send 0xff, 0xff. Put pullup on IO2/IO3 as
    // these may be used as WPn/HOLDn at this point, and we are now starting
    // to issue serial commands.

    PADS_QSPI->GPIO_QSPI_SD0 = padctrl_save;
    PADS_QSPI->GPIO_QSPI_SD1 = padctrl_save;
    padctrl_save = (padctrl_save
        & ~PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK
    ) | PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK;
    PADS_QSPI->GPIO_QSPI_SD2 = padctrl_save;
    PADS_QSPI->GPIO_QSPI_SD3 = padctrl_save;

    manual_CS_Low();
    flash_put_get(buf, NULL, 2, 0);

    IO_QSPI->GPIO_QSPI_SS_CTRL = 0;
}















































// Also allow any unbounded loops to check whether the above abort condition
// was asserted, and terminate early
uint32_t flash_was_aborted(void)
{
    return IO_QSPI->GPIO_QSPI_SD1_CTRL & IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_MASK;
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

// Poll the flash status register until the busy bit (LSB) clears
static inline void flash_wait_ready()
{
    uint8_t stat;
    do {
        flash_do_cmd(FLASHCMD_READ_STATUS, NULL, &stat, 1);
    } while (stat & 0x1 && !flash_was_aborted());
}

// Timing of this one is critical, so do not expose the symbol to debugger etc
static inline void flash_put_cmd_addr(uint8_t cmd, uint32_t addr)
{
    manual_CS_Low();
    addr |= cmd << 24;
    for (int i = 0; i < 4; ++i)
    {
        XIP_SSI->DR0 = addr >> 24;
        addr <<= 8;
    }
}

// Set the WEL bit (needed before any program/erase operation)
static void flash_enable_write()
{
    flash_do_cmd(FLASHCMD_WRITE_ENABLE, NULL, NULL, 0);
}

// Use some other command, supplied by user e.g. a block erase or a chip erase.
// Despite the name, the user is not erased by this function.
void flash_user_erase(uint32_t addr, uint8_t cmd)
{
    assert(addr < 0x1000000);
    flash_enable_write();
    flash_put_cmd_addr(cmd, addr);
    flash_put_get(NULL, NULL, 0, 4);
    flash_wait_ready();
}

// Use a standard 20h 4k erase command:
void flash_sector_erase(uint32_t addr)
{
    flash_user_erase(addr, FLASHCMD_SECTOR_ERASE);
}


// block_size must be a power of 2.
// Generally block_size > 4k, and block_cmd is some command which erases a block
// of this size. This accelerates erase speed.
// To use sector-erase only, set block_size to some value larger than flash,
// e.g. 1ul << 31.
// To override the default 20h erase cmd, set block_size == 4k.
void flash_range_erase(uint32_t addr, size_t count, uint32_t block_size, uint8_t block_cmd)
{
    uint32_t goal = addr + count;
    while (addr < goal && !flash_was_aborted())
    {
        if (!(addr & (block_size - 1)) && goal - addr >= block_size)
        {
            flash_user_erase(addr, block_cmd);
            addr += block_size;
        }
        else
        {
            flash_sector_erase(addr);
            addr += 1ul << 12;
        }
    }
}




















































// Set the WEL bit (needed before any program/erase operation)
static void flash_enable_write()
{
    flash_do_cmd(FLASHCMD_WRITE_ENABLE, NULL, NULL, 0);
}

// Program a 256 byte page at some 256-byte-aligned flash address,
// from some buffer in memory. Blocks until completion.
void flash_page_program(uint32_t addr, const uint8_t *data)
{
    assert(addr < 0x1000000);
    assert(!(addr & 0xffu));
    flash_enable_write();
    flash_put_cmd_addr(FLASHCMD_PAGE_PROGRAM, addr);
    flash_put_get(data, NULL, 256, 4);
    flash_wait_ready();
}

// Program a range of flash with some data from memory.
// Size is rounded up to nearest 256 bytes.
void flash_range_program(uint32_t addr, const uint8_t *data, size_t count)
{
    assert(!(addr & 0xffu));
    uint32_t goal = addr + count;
    while (addr < goal && !flash_was_aborted())
    {
        flash_page_program(addr, data);
        addr += 256;
        data += 256;
    }
}






















































// This is a hook for steps to be taken in between programming the flash and
// doing cached XIP reads from the flash. Called by the bootrom before
// entering flash second stage, and called by the debugger after flash
// programming.
void flash_flush_cache()
{
    XIP_CTRL->FLUSH = 1;
    while(0 == XIP_CTRL->STAT & 1)
    {
        ;
    }
    // Enable the cache
    (XIP_CTRL->CTRL + REG_ALIAS_SET_BITS) = 1;

    IO_QSPI->GPIO_QSPI_SS_CTRL = (IO_QSPI->GPIO_QSPI_SS_CTRL & ~IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_MASK);
}
























































// Put the SSI into a mode where XIP accesses translate to standard
// serial 03h read commands. The flash remains in its default serial command
// state, so will still respond to other commands.
void flash_enter_cmd_xip()
{
    XIP_SSI->SSIENR = 0;

    XIP_SSI->CTRLR0 = 0x200300; // 0 << 21 Standard 1-bit SPI serial frames; 31 << 16 32 clocks per data frame; 3 << 8 Send instr + addr, receive data
    /*
    ssi->ctrlr0 =
            (SSI_CTRLR0_SPI_FRF_VALUE_STD << SSI_CTRLR0_SPI_FRF_LSB) |  // Standard 1-bit SPI serial frames
            (31 << SSI_CTRLR0_DFS_32_LSB) |                             // 32 clocks per data frame
            (SSI_CTRLR0_TMOD_VALUE_EEPROM_READ << SSI_CTRLR0_TMOD_LSB); // Send instr + addr, receive data
    */

    XIP_SSI->SPI_CTRLR0 = 0x3000218; // 3 << 24 Standard 03h read; 2 << 8 8-bit instruction prefix 6 << 2 24-bit addressing for 03h commands; 0 << 0 Command and address both in serial format
    /*
    ssi->spi_ctrlr0 =
            (FLASHCMD_READ_DATA << SSI_SPI_CTRLR0_XIP_CMD_LSB) | // Standard 03h read
            (2u << SSI_SPI_CTRLR0_INST_L_LSB) |    // 8-bit instruction prefix
            (6u << SSI_SPI_CTRLR0_ADDR_L_LSB) |    // 24-bit addressing for 03h commands
            (SSI_SPI_CTRLR0_TRANS_TYPE_VALUE_1C1A  // Command and address both in serial format
                    << SSI_SPI_CTRLR0_TRANS_TYPE_LSB);
*/
    XIP_SSI->SSIENR = 1;
}

