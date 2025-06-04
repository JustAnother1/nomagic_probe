TEST_BIN_FOLDER = $(BIN_FOLDER)test/
TST_LFLAGS = -lgcov --coverage
TST_CFLAGS =  -c -Wall -Wextra -g3  
TST_CFLAGS += -fprofile-arcs -ftest-coverage -fprofile-update=atomic
TST_CFLAGS += -Wno-int-to-pointer-cast -Wno-implicit-function-declaration -Wno-format
TST_DDEFS = -DUNIT_TEST=1
TST_DDEFS += -DFEAT_DEBUG_UART
TST_DDEFS += -DFEAT_GDB_SERVER
TST_INCDIRS = tests/
TST_INCDIRS += tests/unity/
TST_INCDIRS += src/
TST_INCDIRS += src/cfg/
TST_INCDIRS += src/tinyusb/src/
TST_INCDIRS += src/probe_api/
TST_INCDIR = $(patsubst %,-I%, $(TST_INCDIRS))

# TESTS
# =====

# FOLDER cfg

#TODO


# FOLDER cli

#cli/cli
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)cli_cli
CLI_CLI_OBJS =                                \
 $(TEST_BIN_FOLDER)cli/cli_tests.o            \
 $(TEST_BIN_FOLDER)src/cli/cli.o              \
 $(TEST_BIN_FOLDER)src/lib/printf.o           \
 $(TEST_BIN_FOLDER)mock/cli/serial_debug.o    \
 $(TEST_BIN_FOLDER)mock/cli/cli_sys_mock.o    \
 $(TEST_BIN_FOLDER)mock/cli/cli_swd_mock.o    \
 $(TEST_BIN_FOLDER)mock/cli/cli_memory_mock.o \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o \
 $(TEST_BIN_FOLDER)mock/hal/watchdog_mock.o   \
 $(TEST_BIN_FOLDER)mock/target/common_mock.o  \
 $(TEST_BIN_FOLDER)mock/atarget_mock.o

# FOLDER file

#file/fake_boot_sector
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)file_fake_boot_sector
FILE_FAKE_BOOT_SECTOR_OBJS =                                 \
 $(TEST_BIN_FOLDER)file/fake_boot_sector_tests.o             \
 $(TEST_BIN_FOLDER)src/file/fake_boot_sector.o

#file/fake_fat
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)file_fake_fat
FILE_FAKE_FAT_OBJS =                                 \
 $(TEST_BIN_FOLDER)file/fake_fat_tests.o             \
 $(TEST_BIN_FOLDER)src/file/fake_fat.o               \
  $(TEST_BIN_FOLDER)mock/file/file_system_mock.o 


# FOLDER gdbserver

#gdbserver/commands
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)gdbserver_commands
GDBSERVER_COMMANDS_OBJS =                                 \
 $(TEST_BIN_FOLDER)gdbserver/commands_tests.o             \
 $(TEST_BIN_FOLDER)src/lib/printf.o                       \
 $(TEST_BIN_FOLDER)src/gdbserver/commands.o               \
 $(TEST_BIN_FOLDER)src/gdbserver/util.o                   \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o             \
 $(TEST_BIN_FOLDER)mock/lib/printf_mock.o                 \
 $(TEST_BIN_FOLDER)mock/gdbserver/gdbserver_mock.o        \
 $(TEST_BIN_FOLDER)mock/gdbserver/threads_mock.o          \
 $(TEST_BIN_FOLDER)mock/gdbserver/cmd_qxfer_mock.o        \
 $(TEST_BIN_FOLDER)mock/gdbserver/cmd_qsupported_mock.o   \
 $(TEST_BIN_FOLDER)mock/gdbserver/monitor_commands_mock.o \
 $(TEST_BIN_FOLDER)mock/target/common_mock.o

#gdbserver/gdbserver
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)gdbserver_gdbserver
GDBSERVER_GDBSERVER_OBJS =                        \
 $(TEST_BIN_FOLDER)gdbserver/gdbserver_tests.o    \
 $(TEST_BIN_FOLDER)src/gdbserver/gdbserver.o      \
 $(TEST_BIN_FOLDER)src/gdbserver/util.o           \
 $(TEST_BIN_FOLDER)src/lib/printf.o               \
  $(TEST_BIN_FOLDER)mock/atarget_mock.o           \
 $(TEST_BIN_FOLDER)mock/gdbserver/serial_gdb.o    \
 $(TEST_BIN_FOLDER)mock/gdbserver/commands_mock.o \
 $(TEST_BIN_FOLDER)mock/target/common_mock.o      \
 $(TEST_BIN_FOLDER)mock/hal/time_base_mock.o      \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o     \
 $(TEST_BIN_FOLDER)mock/lib/printf_mock.o

#gdbserver/util
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)gdbserver_util
GDBSERVER_UTIL_OBJS =                         \
 $(TEST_BIN_FOLDER)gdbserver/util_tests.o     \
 $(TEST_BIN_FOLDER)src/gdbserver/util.o       \
 $(TEST_BIN_FOLDER)src/lib/printf.o           \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o \
 $(TEST_BIN_FOLDER)mock/lib/printf_mock.o

# FOLDER hal

# TODO


# FOLDEER lib

#lib/printf
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)lib_printf
LIB_PRINTF_OBJS =                             \
 $(TEST_BIN_FOLDER)lib/printf_tests.o         \
 $(TEST_BIN_FOLDER)src/lib/printf.o           \
 $(TEST_BIN_FOLDER)mock/lib/printf_mock.o     \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o

# FOLDER lwip

# TODO


# FOLDER swd

# TODO


# FOLDER target

#target/common_actions.c
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)target_common_actions
TARGET_COMMON_ACTIONS_OBJS =                       \
 $(TEST_BIN_FOLDER)target/common_actions_tests.o   \
 $(TEST_BIN_FOLDER)src/target/common_actions.o     \
 $(TEST_BIN_FOLDER)mock/swd/swd_mock.o             \
 $(TEST_BIN_FOLDER)mock/target/target_mock.o       \
 $(TEST_BIN_FOLDER)mock/target/steps_mock.o        \
 $(TEST_BIN_FOLDER)mock/target/common_mock.o       \
 $(TEST_BIN_FOLDER)mock/gdbserver/gdbserver_mock.o \
 $(TEST_BIN_FOLDER)mock/gdbserver/util_mock.o      \
 $(TEST_BIN_FOLDER)src/lib/printf.o                \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o      \
 $(TEST_BIN_FOLDER)mock/lib/printf_mock.o

#target/flash_write_buffer
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)target_flash_write_buffer
FLASH_WRITE_BUFFER_OBJS =                             \
 $(TEST_BIN_FOLDER)target/flash_write_buffer_tests.o  \
 $(TEST_BIN_FOLDER)src/lib/printf.o                   \
 $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o         \
 $(TEST_BIN_FOLDER)src/target/flash_write_buffer.o


# FOLDEER tinyusb

#tinyusb/usb_msc
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)tinyusb_usb_msc
TINYUSB_USB_MSC_OBJS =                           \
 $(TEST_BIN_FOLDER)tinyusb/usb_msc_tests.o       \
 $(TEST_BIN_FOLDER)src/tinyusb/usb_msc.o         \
 $(TEST_BIN_FOLDER)mock/file/file_storage_mock.o \
 $(TEST_BIN_FOLDER)mock/tinyusb/tinyusb_mock.o



TEST_LOGS = $(patsubst %,%.txt, $(TEST_EXECUTEABLES))

FRAMEWORK_OBJS = $(TEST_BIN_FOLDER)unity/unity.o

# for reporting the results
# ! ! ! Important: ` are speciall ! ! !
IGNORES  = `grep -a -s IGNORE $(TEST_BIN_FOLDER)*.txt)`
FAILURES = `grep -a -s FAIL   $(TEST_BIN_FOLDER)*.txt`
PASSED   = `grep -a -s PASS   $(TEST_BIN_FOLDER)*.txt`


# Unit Test framework
$(TEST_BIN_FOLDER)unity/%.o: tests/unity/%.c
	@echo ""
	@echo "=== compiling (unity) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@


# Tests
$(TEST_BIN_FOLDER)%.o: tests/%.c
	@echo ""
	@echo "=== compiling (tests) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@


# source code module to Test
$(TEST_BIN_FOLDER)src/%.o: src/%.c
	@echo ""
	@echo "=== compiling (tested) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@


# Test executeables
# =================

$(TEST_BIN_FOLDER)cli_cli: $(CLI_CLI_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: cli/cli"
	@echo "====================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)cli_cli $(CLI_CLI_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)file_fake_boot_sector: $(FILE_FAKE_BOOT_SECTOR_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: file/fake_boot_sector"
	@echo "==================================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)file_fake_boot_sector $(FILE_FAKE_BOOT_SECTOR_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)file_fake_fat: $(FILE_FAKE_FAT_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: file/fake_fat"
	@echo "==========================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)file_fake_fat $(FILE_FAKE_FAT_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)gdbserver_util: $(GDBSERVER_UTIL_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: gdbserver/util"
	@echo "============================"
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)gdbserver_util $(GDBSERVER_UTIL_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)gdbserver_gdbserver: $(GDBSERVER_GDBSERVER_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: gdbserver/gdbserver"
	@echo "================================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)gdbserver_gdbserver $(GDBSERVER_GDBSERVER_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)gdbserver_commands: $(GDBSERVER_COMMANDS_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: gdbserver/commands"
	@echo "================================"
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)gdbserver_commands $(GDBSERVER_COMMANDS_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)lib_printf: $(LIB_PRINTF_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: lib/printf"
	@echo "========================"
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)lib_printf $(LIB_PRINTF_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)target_common_actions: $(TARGET_COMMON_ACTIONS_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: target/common_actions"
	@echo "==================================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)target_common_actions $(TARGET_COMMON_ACTIONS_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)target_flash_write_buffer: $(FLASH_WRITE_BUFFER_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: target/flash_write_buffer"
	@echo "======================================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)target_flash_write_buffer $(FLASH_WRITE_BUFFER_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)tinyusb_usb_msc: $(TINYUSB_USB_MSC_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: tinyusb/usb_msc"
	@echo "============================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)tinyusb_usb_msc $(TINYUSB_USB_MSC_OBJS) $(FRAMEWORK_OBJS)

# run all tests
$(TEST_BIN_FOLDER)%.txt: $(TEST_BIN_FOLDER)%
	@echo ""
	@echo "=== running test $@"
	-./$< > $@ 2>&1


# report results
test: $(TEST_LOGS)
	@echo ""
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORES)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAILURES)"
	@echo "\nDONE"


# coverage
lcov: $(TEST_LOGS)
	lcov  --directory $(TEST_BIN_FOLDER) -c -o $(TEST_BIN_FOLDER)lcov.info --exclude "*tests/*" --exclude "*/usr/include/*" 
	genhtml -o test_coverage -t "coverage" --num-spaces 4 $(TEST_BIN_FOLDER)lcov.info -o $(TEST_BIN_FOLDER)test_coverage/
	firefox bin/test/test_coverage/index.html
