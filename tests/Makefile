# generate unit tests for nomagic_probe project

PROJECT = allTests

CC = gcc
LD = cc
MKDIR_P = mkdir -p

BIN_FOLDER = bin/tests/
SRC_FOLDER = ../src/

# CFLAGS+=-std=c99
CFLAGS+= -Wall -Wextra -g3 -fprofile-arcs -ftest-coverage -Wno-int-to-pointer-cast
# -Werror
LFLAGS = -lgcov --coverage

SRC += cli_tests.c
SRC += mocks.c
SRC += printf_tests.c
SRC += $(SRC_FOLDER)cli/cli.c
SRC += $(SRC_FOLDER)lib/printf.c
SRC += usb_msc_tests.c
SRC += $(SRC_FOLDER)tinyusb/usb_msc.c
SRC += $(SRC_FOLDER)file/file_storage.c
SRC += $(SRC_FOLDER)file/faked_disk.c
SRC += munit.c
SRC += allTests.c


DDEFS += -DUNIT_TEST=1

OBJS = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

INCDIRS += .
INCDIRS += cfg/
INCDIRS += $(SRC_FOLDER)
INCDIRS += $(SRC_FOLDER)tinyusb/src/
INCDIRS += /usr/include/
INCDIR = $(patsubst %,-I%, $(INCDIRS))


.DEFAULT_GOAL = all

# targets
$(BIN_FOLDER)%o: %c
	@echo "=== compiling $@"
	@$(MKDIR_P) $(@D)
	$(CC) -c $(CFLAGS) $(DDEFS) $(INCDIR) $< -o $@

$(PROJECT): $(OBJS)
	@echo ""
	@echo "linking"
	@echo "======="
	$(LD) $(LFLAGS) -o $(PROJECT) $(OBJS)


test: $(PROJECT)
	@echo ""
	@echo "executing tests"
	@echo "==============="
	./$(PROJECT)

lcov: 
	lcov --base-directory . --directory . -c -o bin/lcov.info --exclude "*tests/*"
	#--exclude "*cpputest/*"
	genhtml -o test_coverage -t "coverage" --num-spaces 4 bin/lcov.info -o bin/test_coverage/

clean:
	rm -rf bin/ $(PROJECT)

all: test
	@echo ""

.PHONY: clean all

