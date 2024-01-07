# linker flags for nomagic_probe:
# -L = path where to find libtarget.a
# -l =name of lib
LINK_LIBS += -L target/bin -ltarget
# needed so that make knows that it needs the library
LIBS = target/bin/libtarget.a
CLEAN_RM = target/bin/

AR = arm-none-eabi-ar
LIB_FOLDER = target/
LIB_BIN_FOLDER = target/bin/
LIB_SRC_FOLDER = target/src/

LIB_CFLAGS  = -c -ggdb3

LIB_CFLAGS += -O3
# sometimes helps with debugging:
# LIB_CFLAGS += -O0
# LIB_CFLAGS += -save-temps=obj

LIB_CFLAGS += -std=c17
LIB_CFLAGS += -fPIC
#LIB_CFLAGS += -fpic
LIB_CFLAGS += -mcpu=cortex-m0plus -mthumb
LIB_CFLAGS += -ffreestanding -funsigned-char -fno-short-enums
LIB_CFLAGS += -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wconversion 
LIB_CFLAGS += -ffunction-sections -fdata-sections -Wpadded

LIB_DDEFS = -DTARGET_NAME=RP2040 

LIB_INCDIRS +=$(LIB_FOLDER)src/
LIB_INCDIRS +=$(SRC_FOLDER)target_api/
LIB_INCDIRS +=$(SRC_FOLDER)probe_api/
LIB_INCDIR = $(patsubst %,-I%, $(LIB_INCDIRS))

LIB_SRC += $(LIB_SRC_FOLDER)common.c
LIB_SRC += $(LIB_SRC_FOLDER)arm/cortex-m.c
LIB_SRC += $(LIB_SRC_FOLDER)raspberrypi/rp2040.c

LIB_OBJS = $(addprefix $(LIB_BIN_FOLDER),$(LIB_SRC:.c=.o))


$(LIB_BIN_FOLDER)%o: %c
	@echo ""
	@echo "=== compiling (target lib) $@"
	@$(MKDIR_P) $(@D)
	$(CC) -MD -MP -c $(LIB_CFLAGS) $(LIB_DDEFS) $(LIB_INCDIR) $< -o $@

$(LIB_BIN_FOLDER)libtarget.a: $(LIB_OBJS)
	@echo ""
	@echo "create library"
	@echo "=============="
	$(AR) -rcs $(LIB_BIN_FOLDER)libtarget.a $(LIB_OBJS)

