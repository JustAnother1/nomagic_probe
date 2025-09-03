NOMAGIC_SRC_FOLDER = $(NOMAGIC_FOLDER)src/
GITREF = $(shell cd $(NOMAGIC_FOLDER) && git describe --abbrev=40 --dirty --always --tags)

# COMPILER SWITCHES
# =================
# These switches enable or disable functionality

# use BOOT ROM (for flash functions,...)
ifeq ($(USE_BOOT_ROM), yes)
	DDEFS += -DBOOT_ROM_ENABLED=1
endif
# enable USB Mass Storage (Thumb Drive)
ifeq ($(HAS_MSC), yes)
	DDEFS += -DFEAT_USB_MSC
endif

# enable the command line interface for testing
ifeq ($(HAS_CLI), yes)
	DDEFS += -DFEAT_CLI
ifeq ($(HAS_DEBUG_UART), yes)
	DDEFS += -DFEAT_DEBUG_UART
endif

ifeq ($(HAS_DEBUG_CDC), yes)
	DDEFS += -DFEAT_DEBUG_CDC
endif

ifeq ($(HAS_DEBUG_TCP_IP), yes)
	DDEFS += -DFEAT_DEBUG_TCP_IP
	DDEFS += -DCLI_TCP_IP_PORT=4321
endif
endif
# enable the gdb-server
ifeq ($(HAS_GDB_SERVER), yes)
	DDEFS += -DFEAT_GDB_SERVER
endif
# enable the USB network interface
ifeq ($(HAS_NCM), yes)
	DDEFS += -DFEAT_USB_NCM
	LWIP_DIR = $(NOMAGIC_SRC_FOLDER)lwip/
endif
# enable target UART
ifeq ($(HAS_TARGET_UART), yes)
	DDEFS += -DFEAT_TARGET_UART
endif


LKR_SCRIPT = $(NOMAGIC_SRC_FOLDER)hal/RP2040.ld

# Files to compile
# ================

# file handling
ifeq ($(HAS_MSC), yes)
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_mbr.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_boot_sector.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_fat.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_root_folder.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_text_files.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_favicon.c
SRC += $(NOMAGIC_SRC_FOLDER)file/fake_fs.c
SRC += $(NOMAGIC_SRC_FOLDER)file/file_storage.c
SRC += $(NOMAGIC_SRC_FOLDER)file/file_system.c
endif

# gdb server
ifeq ($(HAS_GDB_SERVER), yes)
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/break_watch.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/cmd_qsupported.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/cmd_qxfer.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/commands.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/gdbserver.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/monitor_commands.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/threads.c
SRC += $(NOMAGIC_SRC_FOLDER)gdbserver/util.c
endif

# Hardware abstraction layer
ifeq ($(HAS_DEBUG_UART), yes)
SRC += $(NOMAGIC_SRC_FOLDER)hal/debug_uart.c
endif
ifeq ($(HAS_TARGET_UART), yes)
SRC += $(NOMAGIC_SRC_FOLDER)hal/target_uart.c
endif
SRC += $(NOMAGIC_SRC_FOLDER)hal/startup.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/irq.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/hw_divider.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/watchdog.c
ifeq ($(USE_BOOT_ROM), yes)
SRC += $(NOMAGIC_SRC_FOLDER)hal/boot_rom.c
else
SRC += $(NOMAGIC_SRC_FOLDER)hal/qspi.c
endif
SRC += $(NOMAGIC_SRC_FOLDER)hal/flash.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/time_base.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/random.c
SRC += $(NOMAGIC_SRC_FOLDER)hal/swd_gpio.c

# command line interface (debug - UART0 / USB-CDC)
ifeq ($(HAS_CLI), yes)
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_memory.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_swd.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_sys.c
SRC += $(NOMAGIC_SRC_FOLDER)cli/cli_usb.c
endif

# functions usually available from standard libraries
SRC += $(NOMAGIC_SRC_FOLDER)lib/ctype.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/atoi.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memcmp.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memcpy.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memmove.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/memset.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/printf.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strchr.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strlen.c
SRC += $(NOMAGIC_SRC_FOLDER)lib/strncmp.c

# configuration
ifeq ($(HAS_NCM), yes)
SRC += $(NOMAGIC_SRC_FOLDER)cfg/network_cfg.c
endif
SRC += $(NOMAGIC_SRC_FOLDER)cfg/serial_cfg.c
SRC += $(NOMAGIC_SRC_FOLDER)cfg/swd_cfg.c
SRC += $(NOMAGIC_SRC_FOLDER)cfg/config_file_reader.c
SRC += $(NOMAGIC_SRC_FOLDER)cfg/read_ini.c

# SWD
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_engine.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_protocol.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_packets.c
SRC += $(NOMAGIC_SRC_FOLDER)swd/swd_packet_bits.c

# USB driver
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_descriptors.c

# USB stack (tinyusb
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/tusb.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/device/usbd.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/device/usbd_control.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/common/tusb_fifo.c

# USB serial interface (CDC)
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_cdc.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/class/cdc/cdc_device.c

# USB thumb drive (MSC)
ifeq ($(HAS_MSC), yes)
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/usb_msc.c
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/class/msc/msc_device.c
endif

# lwip + USB Network interface (NCM)
ifeq ($(HAS_NCM), yes)
SRC += $(NOMAGIC_SRC_FOLDER)lwip/lwip.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/dhcp_server.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/tcp_pipe.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/api/err.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/init.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/def.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/dns.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/inet_chksum.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ip.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/mem.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/memp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/netif.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/pbuf.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/raw.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/stats.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/sys.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/altcp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/altcp_alloc.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/altcp_tcp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/tcp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/tcp_in.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/tcp_out.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/timeouts.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/udp.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/acd.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/autoip.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/dhcp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/etharp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/icmp.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/igmp.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/ip4_frag.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/ip4.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv4/ip4_addr.c
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/dhcp6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/ethip6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/icmp6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/inet6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/ip6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/ip6_addr.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/ip6_frag.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/mld6.c 
#SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/core/ipv6/nd6.c
SRC += $(NOMAGIC_SRC_FOLDER)lwip/src/netif/ethernet.c 
SRC += $(NOMAGIC_SRC_FOLDER)tinyusb/src/class/net/ncm_device.c
endif

# target
SRC += $(NOMAGIC_SRC_FOLDER)target/activity.c
SRC += $(NOMAGIC_SRC_FOLDER)target/common.c
SRC += $(NOMAGIC_SRC_FOLDER)target/common_actions.c
SRC += $(NOMAGIC_SRC_FOLDER)target/steps.c
ifeq ($(HAS_TARGET_UART), yes)
SRC += $(NOMAGIC_SRC_FOLDER)target/target_uart_handler.c
endif

# user feedback
SRC += $(NOMAGIC_SRC_FOLDER)led.c

# main
SRC += $(NOMAGIC_SRC_FOLDER)main.c

OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS +=$(NOMAGIC_SRC_FOLDER)
INCDIRS +=$(BIN_FOLDER)
INCDIRS +=$(NOMAGIC_SRC_FOLDER)cfg/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)lib/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)tinyusb/src/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)lwip/
#LWIP_INCLUDE_DIRS
INCDIRS +=$(NOMAGIC_SRC_FOLDER)lwip/src/include/
INCDIRS +=$(NOMAGIC_SRC_FOLDER)lwip/contrib/

INCDIR = $(patsubst %,-I%, $(INCDIRS))


$(BIN_FOLDER)version.h:
	@echo ""
	@echo "create version.h"
	@echo "================"
	@echo -n "#define VERSION \"$(PROBE_NAME)" > $(BIN_FOLDER)version.h
	@cat $(NOMAGIC_FOLDER)version.txt >> $(BIN_FOLDER)version.h
	@echo " $(GITREF)\"" >> $(BIN_FOLDER)version.h
	@cat $(BIN_FOLDER)version.h

$(BIN_FOLDER)$(NOMAGIC_SRC_FOLDER)cli/cli.o: $(NOMAGIC_SRC_FOLDER)cli/cli.c $(BIN_FOLDER)version.h
	@echo ""
	@echo "=== compiling (cli) $@"
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@
	
$(BIN_FOLDER)$(NOMAGIC_SRC_FOLDER)gdbserver/monitor_commands.o: $(NOMAGIC_SRC_FOLDER)gdbserver/monitor_commands.c $(BIN_FOLDER)version.h
	@echo ""
	@echo "=== compiling (monitor commands) $@"
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@

$(BIN_FOLDER)$(NOMAGIC_SRC_FOLDER)lwip/src/%o: $(NOMAGIC_SRC_FOLDER)lwip/src/%c
	@echo ""
	@echo "=== compiling (lwip) $@"
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) -Wno-address -Wno-conversion $(DDEFS) $(INCDIR) $< -o $@