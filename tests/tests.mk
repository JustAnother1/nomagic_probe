TEST_BIN_FOLDER = $(BIN_FOLDER)test/
TST_LFLAGS = -lgcov --coverage
TST_CFLAGS =  -c -Wall -Wextra -g3 -fprofile-arcs -ftest-coverage -Wno-int-to-pointer-cast -Wno-implicit-function-declaration -Wno-format
TST_DDEFS = -DUNIT_TEST=1
TST_DDEFS += -DFEAT_DEBUG_UART
TST_DDEFS += -DFEAT_GDB_SERVER
TST_INCDIRS = tests/
TST_INCDIRS += src/
TST_INCDIRS += src/cfg/
TST_INCDIRS += src/tinyusb/src/
TST_INCDIR = $(patsubst %,-I%, $(TST_INCDIRS))


#gdbserver/util
TEST_EXECUTEABLES = $(TEST_BIN_FOLDER)gdbserver_util
GDBSERVER_UTIL_OBJS = $(TEST_BIN_FOLDER)gdbserver/util_tests.o 
GDBSERVER_UTIL_OBJS += $(TEST_BIN_FOLDER)src/gdbserver/util.o
GDBSERVER_UTIL_OBJS += $(TEST_BIN_FOLDER)mock/lib/printf_mock.o

#gdbserver/gdbserver
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)gdbserver_gdbserver
GDBSERVER_GDBSERVER_OBJS = $(TEST_BIN_FOLDER)gdbserver/gdbserver_tests.o 
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)src/gdbserver/gdbserver.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)src/gdbserver/util.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/serial_gdb.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/commands_mock.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)mock/target/common_mock.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)mock/hal/time_base_mock.o
GDBSERVER_GDBSERVER_OBJS += $(TEST_BIN_FOLDER)mock/lib/printf_mock.o

#gdbserver/commands
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)gdbserver_commands
GDBSERVER_COMMANDS_OBJS = $(TEST_BIN_FOLDER)gdbserver/commands_tests.o 
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)src/gdbserver/commands.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)src/gdbserver/util.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/lib/printf_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/gdbserver_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/threads_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/cmd_qxfer_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/cmd_qsupported_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/gdbserver/monitor_commands_mock.o
GDBSERVER_COMMANDS_OBJS += $(TEST_BIN_FOLDER)mock/target/common_mock.o

#tinyusb/usb_msc
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)tinyusb_usb_msc
TINYUSB_USB_MSC_OBJS = $(TEST_BIN_FOLDER)tinyusb/usb_msc_tests.o 
TINYUSB_USB_MSC_OBJS += $(TEST_BIN_FOLDER)src/tinyusb/usb_msc.o
TINYUSB_USB_MSC_OBJS += $(TEST_BIN_FOLDER)mock/file/file_storage_mock.o
TINYUSB_USB_MSC_OBJS += $(TEST_BIN_FOLDER)mock/tinyusb/tinyusb_mock.o

#lib/printf
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)lib_printf
LIB_PRINTF_OBJS = $(TEST_BIN_FOLDER)lib/printf_tests.o
LIB_PRINTF_OBJS += $(TEST_BIN_FOLDER)src/lib/printf.o
LIB_PRINTF_OBJS += $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o

#cli/cli
TEST_EXECUTEABLES += $(TEST_BIN_FOLDER)cli_cli
CLI_CLI_OBJS = $(TEST_BIN_FOLDER)cli/cli_tests.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)src/cli/cli.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)src/lib/printf.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/cli/serial_debug.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/cli/cli_sys_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/cli/cli_swd_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/cli/cli_memory_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/hal/hw_divider_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/hal/watchdog_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/target/common_mock.o
CLI_CLI_OBJS += $(TEST_BIN_FOLDER)mock/atarget_mock.o

TEST_LOGS = $(patsubst %,%.txt, $(TEST_EXECUTEABLES))

FRAMEWORK_OBJS = $(TEST_BIN_FOLDER)unity.o

# for reporting the results
# ! ! ! Important: ` are speciall ! ! !
IGNORES = `grep -a -s IGNORE $(TEST_BIN_FOLDER)*.txt)`
FAILURES = `grep -a -s FAIL $(TEST_BIN_FOLDER)*.txt`
PASSED = `grep -a -s PASS $(TEST_BIN_FOLDER)*.txt`

# Unit Test framework
$(TEST_BIN_FOLDER)unity.o: tests/unity.c
	@echo ""
	@echo "=== compiling (tests) $@"
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
	@echo "=== compiling (tests) $@"
	@$(MKDIR_P) $(@D)
	$(TST_CC) $(TST_CFLAGS) $(TST_DDEFS) $(TST_INCDIR) $< -o $@

# Test executeables
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
	@echo "================================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)gdbserver_commands $(GDBSERVER_COMMANDS_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)tinyusb_usb_msc: $(TINYUSB_USB_MSC_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: tinyusb/usb_msc"
	@echo "============================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)tinyusb_usb_msc $(TINYUSB_USB_MSC_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)lib_printf: $(LIB_PRINTF_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: lib/printf"
	@echo "============================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)lib_printf $(LIB_PRINTF_OBJS) $(FRAMEWORK_OBJS)

$(TEST_BIN_FOLDER)cli_cli: $(CLI_CLI_OBJS) $(FRAMEWORK_OBJS)
	@echo ""
	@echo "linking test: cli/cli"
	@echo "============================="
	$(TST_LD) $(TST_LFLAGS) -o $(TEST_BIN_FOLDER)cli_cli $(CLI_CLI_OBJS) $(FRAMEWORK_OBJS)


# run all tests
$(TEST_BIN_FOLDER)%.txt: $(TEST_BIN_FOLDER)%
	@echo ""
	@echo "=== running test $@"
	-./$< > $@ 2>&1

# report results
test: $(TEST_LOGS)
	@echo ""
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORES)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAILURES)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

# coverage
lcov: $(TEST_LOGS)
	lcov  --directory $(TEST_BIN_FOLDER) -c -o $(TEST_BIN_FOLDER)lcov.info --exclude "*tests/*" --exclude "*/usr/include/*" 
	genhtml -o test_coverage -t "coverage" --num-spaces 4 $(TEST_BIN_FOLDER)lcov.info -o $(TEST_BIN_FOLDER)test_coverage/

