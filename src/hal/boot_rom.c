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

#include "boot_rom.h"
#include "cfg/cli_cfg.h"

typedef void *(*rom_table_lookup_fn)(uint16_t *table, uint32_t code);

static bool valid = false;
static boot_rom_flash_functions flash_funcs;
static rom_table_lookup_fn rom_table_lookup;

// Convert a 16 bit pointer stored at the given rom address into a 32 bit pointer
#define rom_hword_as_ptr(rom_address) (void *)(uintptr_t)(*(uint16_t *)(uintptr_t)(rom_address))

/*!
 * \brief Lookup a bootrom function by code. This method is forcibly inlined into the caller for FLASH/RAM sensitive code usage
 * \ingroup pico_bootrom
 * \param code the code
 * \return a pointer to the function, or NULL if the code does not match any bootrom function
 */
static void* rom_func_lookup(uint32_t code)
{
    /*
    return rom_table_lookup((uint16_t *)0x14, code); */
    return rom_table_lookup(rom_hword_as_ptr(0x14), code);
}

//! convert two letter code into uint32_t value used by ROM function for lookup.
uint32_t rom_table_code(char c1, char c2)
{
    return (uint32_t)((c2 << 8) | c1);
}

boot_rom_flash_functions* boot_rom_get_flash_functions(void)
{
    if(false == valid)
    {
        return NULL;
    }
#pragma GCC diagnostic ignored "-Wpedantic"
    // warning: ISO C forbids assignment between function pointer and 'void *' [-Wpedantic]
    flash_funcs._connect_internal_flash = rom_func_lookup(rom_table_code('I','F'));
    flash_funcs._flash_exit_xip         = rom_func_lookup(rom_table_code('E','X'));
    flash_funcs._flash_range_erase      = rom_func_lookup(rom_table_code('R','E'));
    flash_funcs.flash_range_program     = rom_func_lookup(rom_table_code('R','P'));
    flash_funcs._flash_flush_cache      = rom_func_lookup(rom_table_code('F','C'));
    flash_funcs._flash_enter_cmd_xip    = rom_func_lookup(rom_table_code('C','X'));
#pragma GCC diagnostic pop


    if( (NULL == flash_funcs._connect_internal_flash)
     || (NULL == flash_funcs._flash_exit_xip)
     || (NULL == flash_funcs._flash_range_erase)
     || (NULL == flash_funcs.flash_range_program)
     || (NULL == flash_funcs._flash_flush_cache)
     || (NULL == flash_funcs._flash_enter_cmd_xip) )
    {
        return NULL;
    }

    return &flash_funcs;
}

void boot_rom_check_if_valid(void)
{
    // RP2040 data sheet:
    // Assuming the three bytes starting at address 0x00000010 are ('M', 'u', 0x01)
    // then the three halfwords starting at offset 0x00000014 are valid.
    uint32_t val = *(uint32_t*)0x10;
    uint32_t magic  = val & 0xff;
    if( 'M' != magic)
    {
        valid = false;
        return;
    }
    magic  = (val >> 8) & 0xff;
    if( 'u' != magic)
    {
        valid = false;
        return;
    }
    magic  = (val >> 16) & 0xff;
    if( 1 != magic)
    {
        valid = false;
        return;
    }
    /*
    uint16_t* rom = (uint16_t *)(0x18);
    uint32_t ptr = *rom;
    rom_table_lookup = (rom_table_lookup_fn) ptr;
    // rom_table_lookup = (rom_table_lookup_fn) *(uint16_t *)(0x18);
    */
#pragma GCC diagnostic ignored "-Wpedantic"
    rom_table_lookup = rom_hword_as_ptr(0x18);
#pragma GCC diagnostic pop
    valid = true;
}

void boot_rom_report(void)
{
    uint32_t val = *(uint32_t*)0x10;
    val = (val >> 24) & 0xff;
    debug_line("boot ROM version : %lu", val);
    if(true == valid)
    {
        debug_line("boot ROM is valid : true");
    }
    else
    {
        debug_line("boot ROM is valid : false");
    }
    debug_line("address of function lookup function :           0x%08lx", (uint32_t)rom_table_lookup);
    debug_line("address of function _connect_internal_flash() : 0x%08lx", (uint32_t)flash_funcs._connect_internal_flash);
    debug_line("address of function _flash_exit_xip() :         0x%08lx", (uint32_t)flash_funcs._flash_exit_xip);
    debug_line("address of function _flash_range_erase() :      0x%08lx", (uint32_t)flash_funcs._flash_range_erase);
    debug_line("address of function flash_range_program() :     0x%08lx", (uint32_t)flash_funcs.flash_range_program);
    debug_line("address of function _flash_flush_cache() :      0x%08lx", (uint32_t)flash_funcs._flash_flush_cache);
    debug_line("address of function _flash_enter_cmd_xip() :    0x%08lx", (uint32_t)flash_funcs._flash_enter_cmd_xip);
}


