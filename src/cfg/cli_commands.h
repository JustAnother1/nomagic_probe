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
#ifndef CLI_CLI_COMMANDS_H_
#define CLI_CLI_COMMANDS_H_

#include "cli_cfg.h"
#include "cli/cli_swd.h"
#include "cli/cli_sys.h"
#include "cli/cli_memory.h"
#include "cli/cli_common_target.h"
#include "cfg/target_cli_commands.h"


cmd_typ commands[] = {
        //         11             1         2         3         4         5         6
        //12345678901    123456789012345678901234567890123456789012345678901234567890
        {"help",        "list all available commands", cmd_help},
        {"time",        "time since power on", cmd_time},
        {"param_dump",  "prints the parameters as hex", cmd_parameter_raw},
        {"target_info", "display target specific status information", cmd_target_info},
        {"action_info", "list implemented actions", common_action_info},
        {"at",          "show action trace", cmd_target_trace},
        {"md",          "display memory", cmd_memory_dump},
        {"mdr",         "display memory as registers", cmd_memory_display},
        {"hil",         "hardware in the loop tests", cmd_hil_test},
        {"die",         "test the watch dog", cmd_die},
        {"info",        "low level firmware information", cmd_info},
        {"fl_write",    "write to flash memory <address> <length>", cmd_flash_memory_write},
        {"fl_erase",    "erase one flash memory sector <index>", cmd_flash_memory_erase},
#ifdef BOOT_ROM_ENABLED
        {"xip_off",     "disable XIP on FLash", cmd_flash_disable_XIP},
        {"xip_on",      "enable XIP on FLash", cmd_flash_enable_XIP},
#else
        {"fl_init",      "initialize QSPI interface for FLash", cmd_flash_init},
        {"fl_detect",    "detect the QSPI FLash", cmd_flash_detect},
#endif
        {"swd_open",    "open a connection on the SWD interface", cmd_swd_connect},
        {"swd_rm",      "read target memory address <address> <length>", cmd_swd_read_memory},
        {"swd_wm",      "write to target memory address <address> <value>", cmd_swd_write_memory},
#ifdef FEAT_USB_MSC
        {"cat",         "dump the content of the file <filename>", cmd_file_dump},
        {"ls",          "list all files in the file system", cmd_file_ls},
        {"fs_format",   "format the file system.", cmd_file_format},
#endif
        TARGET_CLI_COMMANDS
};


#endif /* CLI_CLI_COMMANDS_H_ */
