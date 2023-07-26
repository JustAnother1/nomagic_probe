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

#include "flash.h"


/*
 * XIP Address alias:
 0x10... XIP access, cacheable, allocating - Normal cache operation
 0x11... XIP access, cacheable, non-allocating - Check for hit, don’t update cache on miss
 0x12... XIP access, non-cacheable, allocating - Don’t check for hit, always update cache
 0x13... XIP access, non-cacheable, non-allocating - Bypass cache completely
 0x15... Use XIP cache as SRAM bank, mirrored across entire segment
*/

/*
A typical call sequence for erasing a flash sector from user code would be:
• _connect_internal_flash
• _flash_exit_xip


• _flash_range_erase(addr, 1 << 12, 1 << 16, 0xd8)
• _flash_flush_cache
*/
/* BOOT ROM Version

#include "hal/boot_rom.h"

static boot_rom_flash_functions* flash_funcs = NULL;

void flash_init(void)
{
    flash_funcs = boot_rom_get_flash_functions();
    if(NULL != flash_funcs)
    {
        // flash_funcs->_connect_internal_flash();
        // flash_funcs->_flash_exit_xip();
    }
}

void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
    if(NULL != flash_funcs)
    {
        flash_funcs->flash_range_program(start_address, data, length);
    }
}

//! erases one page (smalles erase possible) that is 4096 bytes.
void flash_erase_page(uint32_t number)
{
    if(NULL != flash_funcs)
    {
        flash_funcs->_flash_range_erase(number*4096, 4096, 0, 0);
    }
}
*/

#include "hal/hw/XIP_CTRL.h"
#include "hal/hw/XIP_SSI.h"
#include "hal/hw/RESETS.h"
#include "cfg/cli_cfg.h"

void flash_init(void)
{

}

void XIP_IRQ(void)
{

}

void flash_write_block(uint32_t start_address, uint8_t* data, uint32_t length)
{
    (void)start_address;
    (void)data;
    (void)length;
}

//! erases one page (smalles erase possible) that is 4096 bytes.
void flash_erase_page(uint32_t number)
{
    (void)number;
}

void flash_read(uint32_t start_address, uint8_t* data, uint32_t length)
{
    (void)start_address;
    (void)data;
    (void)length;
}

void flash_report(void)
{
    // uint32_t i = 0;
    debug_line("QSPI Flash:");
}

/*
    // init
    XIP_CTRL->CTRL = 0xa;
    / *
    RESETS->RESET = 0x240;
    while (0x240 != (0x240 & RESETS->RESET_DONE))
    {
        ;
    }
    * /
    XIP_SSI->SSIENR = 0; // aus
    XIP_SSI->CTRLR0 = 0x1403; // Slave selct togle disabled,
    XIP_SSI->CTRLR1 = 3; // Number of data frames
    XIP_SSI->BAUDR = 10; // TODO

    XIP_SSI->TXFTLR = 0;// TODO
    XIP_SSI->RXFTLR = 0;// TODO
    XIP_SSI->IMR = 0; // TODO
    XIP_SSI->SER = 1; // slave selected
    XIP_SSI->DMACR = 0; // do no use DMA
    XIP_SSI->RX_SAMPLE_DLY = 0; // delay sample due to long lines
    XIP_SSI->SPI_CTRLR0 = 0; //TODO
    XIP_SSI->TXD_DRIVE_EDGE = 0; // TODO
    XIP_SSI->SSIENR = 1; // ein

    XIP_SSI->DR0 = 0x9f;
    XIP_SSI->DR0 = 0;
    XIP_SSI->DR0 = 0;
    XIP_SSI->DR0 = 0;
    while (0 != (4 & XIP_SSI->SR))
    {
        ;
    }
    while (0 != (1 & XIP_SSI->SR))
    {
        ;
    }
    while (0 != (8 & XIP_SSI->SR))
    {
        uint32_t data = XIP_SSI->DR0;
        debug_line("%3ld : 0x%08lx", i, data);
        i++;
    }
    debug_line("End of Data!");
}
*/
