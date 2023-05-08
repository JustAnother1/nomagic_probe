PROJECT = nomagic_probe

# tools
CP = arm-none-eabi-objcopy
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
SIZE = size
MKDIR_P = mkdir -p
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
DIS = $(CP) -S
OBJDUMP = arm-none-eabi-objdump

BIN_FOLDER = bin/
SRC_FOLDER = src/

SOURCE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))

LKR_SCRIPT = $(SRC_FOLDER)hal/RP2040.ld


CFLAGS = -c  -O3 -g -mcpu=cortex-m0plus -mthumb
LFLAGS = -nostartfiles -specs=nano.specs -specs=nosys.specs -Wl,-Map=$(BIN_FOLDER)app.map -g -T$(LKR_SCRIPT)
# -fno-common -ffreestanding



# OBJS =  hal/console_uart.o hal/startup.o main.o cli/cli.o cli/cli_sys.o time.o
SRC += $(SRC_FOLDER)hal/console_uart.c
SRC += $(SRC_FOLDER)hal/startup.c
SRC += $(SRC_FOLDER)cli/cli.c
SRC += $(SRC_FOLDER)cli/cli_sys.c
SRC += $(SRC_FOLDER)time.c
SRC += $(SRC_FOLDER)main.c

OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS +=$(SRC_FOLDER)
#INCDIRS +=$(SRC_FOLDER)hal
INCDIR = $(patsubst %,-I%, $(INCDIRS))

# make config
VPATH = $(SOURCE_DIR)
.DEFAULT_GOAL = all


# targets

$(BIN_FOLDER)$(PROJECT).elf: $(OBJS)
	@echo ""
	@echo "linking"
	@echo "======="
	$(LD) $(LFLAGS) -o $(BIN_FOLDER)$(PROJECT).elf $(OBJS)

%hex: %elf
	$(HEX) $< $@

%bin: %elf
	$(BIN) $< $@

%txt: %elf
	$(DIS) $< $@ > $@

flash: $(PROJECT).elf
	openocd -f board/pico-debug.cfg -c "$(PROJECT).elf verify reset exit"

$(BIN_FOLDER)$(PROJECT).uf2: $(BIN_FOLDER)$(PROJECT).elf
	elf2uf2 -f 0xe48bff56 -p 256 -i $(BIN_FOLDER)$(PROJECT).elf

all: $(BIN_FOLDER)$(PROJECT).uf2
	@echo ""
	@echo "size"
	@echo "===="
	$(SIZE) $(BIN_FOLDER)$(PROJECT).elf

	
$(BIN_FOLDER)%o: %c
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

list:
	@echo " READ -> $(BIN_FOLDER)$(PROJECT).rd"
	@arm-none-eabi-readelf -Wall $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).rd
	@echo " LIST -> $(BIN_FOLDER)$(PROJECT).lst"
	@$(OBJDUMP) -axdDSstr $(BIN_FOLDER)$(PROJECT).elf > $(BIN_FOLDER)$(PROJECT).lst
#$(OBJDUMP) -h -S -z $< > $@

clean:
	@rm -rf $(BIN_FOLDER) app.map

.PHONY: clean flash all list

