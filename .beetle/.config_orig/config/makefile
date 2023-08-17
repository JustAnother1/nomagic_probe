################################################################################
#                                                                              #
#                      MAKEFILE FOR EMBEETLE PROJECTS                          #
#                                                                              #
################################################################################
# COPYRIGHT (c) 2021 Johan Cockx                                               #
# This software component is licensed by Embeetle under the MIT license. Con-  #
# sult the license text at the bottom of this file.                            #
#                                                                              #
# Acknowledgements: inspiration for this makefile came from many sources,      #
# including:                                                                   #
#                                                                              #
# - Recursive Make Considered Harmful                                          #
#   https://accu.org/journals/overload/14/71/miller_2004/                      #
#                                                                              #
# - https://make.mad-scientist.net/papers/rules-of-makefiles                   #
#                                                                              #
# - http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/  #
#                                                                              #
#------------------------------------------------------------------------------#
#                           HOW TO RUN THIS MAKEFILE                           #
#------------------------------------------------------------------------------#
# This makefile is invoked by Embeetle IDE, when you click one of the makefile #
# targets in the top-toolbar, eg. 'clean', 'build', 'flash'.                   #
#                                                                              #
# You can invoke this makefile also manually in a console ('cmd' on Windows,   #
# 'sh' on Linux). First navigate to the toplevel project folder:               #
#   $ cd C:/beetle_projects/my_project                                         #
#                                                                              #
# Then invoke the makefile with following arguments:                           #
#   $ make build                                                               #
#       -C build                                                               #
#       -f ../config/makefile                                                  #
#       "TOOLPREFIX=C:/my_tools/gnu_arm_toolchain_9.2.1/bin/arm-none-eabi-"    #
#       "FLASHTOOL=C:/my_tools/openocd_0.10.0_dev01138_32b/bin/openocd.exe"    #
#                                                                              #
# The arguments TOOLPREFIX and FLASHTOOL are absolute paths to the compiler    #
# toolchain (ARM, RISCV, ...) and the flash tool (OpenOCD, avrdude, ...) res-  #
# pectively. You should provide them if they're not available on your PATH en- #
# vironment variable.                                                          #
#                                                                              #
# In some situations, you'll also have to provide a FLASH_PORT argument, like: #
#    $ make flash                                                              #
#       -C build                                                               #
#       -f ../config/makefile                                                  #
#       "TOOLPREFIX=C:/my_tools/gnu_avr_toolchain_7.3.0_32b/bin/avr-"          #
#       FLASH_PORT=COM5                                                        #
#                                                                              #
# If you're unsure how to invoke this makefile manually, just run it once in   #
# Embeetle IDE and observe the command that Embeetle invokes. Copy-paste the   #
# command into your console.                                                   #
#                                                                              #
#------------------------------------------------------------------------------#
#                                    NOTES                                     #
#------------------------------------------------------------------------------#
# - Embeetle IDE always provides the absolute paths to the tools when running  #
#   this makefile. That way, you don't need to modify your PATH environment    #
#   variable to use Embeetle. On Windows, it also helps to avoid registry      #
#   problems, as explained in ADDENDUM 2 at the bottom.                        #
#                                                                              #
# - In the folder where this makefile is stored (usually the 'config' folder   #
#   of your project), there should be a 'dashboard.mk' and 'filetree.mk' file  #
#   as well. These two files are generated by Embeetle and get included into   #
#   this makefile.                                                             #
#                                                                              #
#------------------------------------------------------------------------------#
#                               MORE INFORMATION                               #
#------------------------------------------------------------------------------#
# Consult the Embeetle website for more info about this makefile:              #
# https://embeetle.com/#embeetle-ide/manual/build/embeetle-makefiles/main-makefile #
#                                                                              #
################################################################################


# DEFAULT TARGET
# ==============
#
# If no target is specified on the command line,  make builds the first target
# of the makefile. By convention,  this is usually called 'default'.
default: build

# The eventual goal of the build target is to create all the binaries: .bin,
# .elf and .hex. Potentially also the EEPROM file .eep. To create all these
# files, we just need to add them as dependencies/prerequisites to the phony
# build target.  Note: The variable BINARIES gets defined in 'dashboard.mk'.
.PHONY: build
build: print_build $(BINARIES) show_size


# HOST OS SPECIFIC COMMANDS
# =========================
#
# In addition to build and flash tools, this makefile makes use of commands to
# create and delete directories and files in the build directory. Depending on
# the situation, it needs to use Unix-style commands (rm, mkdir, touch) or
# Windows-style commands (del, mkdir, type).
#
# The magic below attempts to guess the commands to be used.  It has been tested
# in different configurations both on Windows and on Linux.  If it doesn't work
# for you, feel free to fix it and/or send us the details of your environment,
# so that we can improve it.
#
# The commands to be used depend on the host OS (the OS in which you are running
# Embeetle).  On Windows, they also depend on how 'make' was compiled (for
# native Windows or for MSYS or WSL) and on the command shell from which 'make'
# is started ('cmd' or a ported linux-style shell).  On Linux and other variants
# of Unix, 'make' always uses the Bourne shell 'sh'.  On Windows, it is usually
# 'cmd', the native Microsoft command shell.  However, Unix shells and commands
# have also been ported to Windows in environments like MSYS or WSL; when 'make'
# is executed from one of these, it will again use the Bourne shell.
#
# This makefile has been tested with GNU make on different flavors of Linux, as
# well as on Windows from the 'cmd' shell, 'powershell' and an MSYS shell, both
# with 'make' compiled natively and with make compiled for MSYS, and with or
# without sh.exe on PATH. All tested combinations work.
ifeq ($(SHELL),sh.exe)
  SHELLSTYLE=cmd
  RM = $(if $(1),del /f /q $(subst /,\,$(1)))
  define REMOVE_ALL =
  for /d %%p in (*) do rmdir /s /q "%%p"
  for %%p in (*) do del /q "%%p"
  endef
  MKDIR = dir $(subst /,\,$(1)) >nul 2>nul || mkdir $(subst /,\,$(1)) >nul 2>nul || mkdir $(subst /,\,$(1))
  TOUCH = type NUL >>
else
  SHELLSTYLE=sh
  SYSBIN = $(dir $(wildcard /bin/rm))
  RM = $(SYSBIN)rm -f $(1)
  REMOVE_ALL = $(SYSBIN)rm -rf * .[!.]* ..?*
  MKDIR = $(SYSBIN)mkdir -p $(1)
  TOUCH = $(SYSBIN)touch
endif

# DASHBOARD.MK
# ============
#
# Embeetle generates a file dashboard.mk in the same directory as the makefile
# itself.  It defines the variables that depend on the user's choices in the
# dashboard. It must be included for the Embeetle dashboard mechanism to work.
# If you don't include it, it is your responsibility to define these values.
#
# The following variables defined in 'dashboard.mk' are used in this makefile:
#
#     - SOURCE_DIR         : The location of the directory containing the source
#                            files; see "shadow building" below. This can be an
#                            absolute or a relative(*) path and must end in '/'.
#                            Any spaces in the path must be preceded by a triple
#                            backslash '\\\ '.
#
#     - ELF_FILE           : Relative(*) path to .elf file.
#
#     - TOOLPREFIX         : A fallback value like 'arm-none-eabi-' in case this
#                            makefile is invoked without giving an absolute path
#                            to TOOLPREFIX in the commandline.
#
#     - TARGET_COMMONFLAGS : Flags for C++, C and assembly compilation and
#                            linking
#
#     - TARGET_CFLAGS      : C compilation flags.
#
#     - TARGET_CXXFLAGS    : C++ compilation flags.
#
#     - TARGET_SFLAGS      : Assembler flags.
#
#     - TARGET_LDFLAGS     : Linker flags.
#
#     - TOOLCHAIN_LDLIBS   : Libraries from the toolchain that should be pro-
#                            vided to the linker. For example '-lgcc'
#
# (*) Note: all relative paths are relative with respect to the build folder.
#
# In addition, dashboard.mk defines rules to create .bin and .hex files from the
# .elf file, and a 'flash' target to flash the .elf, .bin or .hex file to the
# microcontroller. Creation of .bin and .hex files and the flashing procedure
# are very target-specific, so these rules cannot be added to this generic
# makefile.  Flashing is usually achieved through a combination of GDB and
# OpenOCD. Some MCUs require more specific tools like 'avrdude', 'esptool', ...

include $(dir $(firstword $(MAKEFILE_LIST)))dashboard.mk

# Make sure that 'dashboard.mk' defines the right version variable. This make-
# file is version 7, so 'dashboard.mk' must be compatible.
ifneq ($(EMBEETLE_MAKEFILE_INTERFACE_VERSION),7)
  $(error 'dashboard.mk' is not compatible with this makefile)
endif


# COMPILATION RULES
# =================
#
# To allow source files in external library folders to be built locally in the
# project, compilation rules are defined in a function called compilation-rules.
# This function is evaluated once for the project itself and once for each
# external library folder containing source files.  It fixes the build subfolder
# to be used for each source tree.
#
# The compilation-rules function takes two arguments.  The first argument is the
# path of the folder in which object files should be stored, relative to the
# build folder.  The second argument is the path of the folder containing the
# corresponding source files. Both paths must end in '/' or be empty, and spaces
# must be quoted by preceding them with a triple backslash.

define compilation-rules
$(1)%.c.o: $(2)%.c
	$$(c-rule)

$(1)%.cpp.o: $(2)%.cpp
	$$(cxx-rule)

$(1)%.cxx.o: $(2)%.cxx
	$$(cxx-rule)

$(1)%.c++.o: $(2)%.c++
	$$(cxx-rule)

$(1)%.cc.o: $(2)%.cc
	$$(cxx-rule)

$(1)%.C.o: $(2)%.C
	$$(cxx-rule)

$(1)%.s.o: $(2)%.s
	$$(asm-rule)

$(1)%.asm.o: $(2)%.asm
	$$(asm-rule)

$(1)%.S.o: $(2)%.S
	$$(asm-rule)

endef

define c-rule
$(info )
$(info )
$(info Compile: $<)
$(CC) $(CFLAGS) '$<' -o $@ -c
endef

define cxx-rule
$(info )
$(info )
$(info Compile: $<)
$(CXX) $(CXXFLAGS) '$<' -o $@ -c
endef

define asm-rule
$(info )
$(info )
$(info Compile: $<)
$(CC) $(SFLAGS) '$<' -o $@ -c
endef

# Compile source files from the project itself into object files in the
# subdirectory 'project' of the build folder.
$(eval $(call compilation-rules,project/,$(SOURCE_DIR)))

# Cancel implicit rules
.SUFFIXES:


# FILETREE.MK
# ===========
#
# Embeetle generates a file filetree.mk in the same directory as the makefile
# itself.  It defines the variables that depend on the user's choices in
# Embeetle's filetree. It must be included for the Embeetle filetree mechanism
# to work. If you don't include it, it is your responsibility to define these
# values. For more info, check this webpage:
# https://embeetle.com/#embeetle-ide/manual/build/source-file-selection
#
# 'filetree.mk' defines the following variables:
#
#     - OFILES   : List of object files to be linked into the project.
#                  Each of these object files will be compiled from a
#                  corresponding source file (C, C++ or assembly) in the project
#                  folder or in an external folder.
#
#     - CXX_OFILES: The subset of OFILES that is compiled from C++ files.
#                   A project with at least one C++ file needs a different
#                   rule for linking (see further).
#
#     - C_OFILES:   The subset of OFILES that is compiled from C files. Not
#                   used.
#
#     - S_OFILES:   The subset of OFILES that is compiled from assembly files.
#                   Not used.
#
#     - HDIR_FLAGS: List of include directory options for the preprocessor.
#                   These options are used to located header files includes by
#                   the project's source files.
#
#     - PROJECT_LDLIBS: List of linker flags and archive files to be linked
#                   into the project's executable
#
# In addition,  filetree.mk instantiates compilation rules for source files
# from any external library folders used by the project.  For example,  for an
# external library /etc/libs/foo,  it may contain this line:
#      $(eval $(call compilation-rules,ext.foo/,/etc/libs/foo/))

include $(dir $(firstword $(MAKEFILE_LIST)))filetree.mk

# Make sure that 'filetree.mk' defines the right version variable. This makefile
# is version 7, so 'filetree.mk' must be compatible.
ifneq ($(EMBEETLE_MAKEFILE_INTERFACE_VERSION),7)
  $(error 'filetree.mk' is not compatible with this makefile)
endif

# SHADOW BUILDING
# ===============
#
# This makefile supports 'shadow building', i.e. building the project in another
# directory than the projects top directory. Shadow building has several
# advantages:
#
#  - build artifacts are cleanly separated from source files
#
#  - the 'clean' target can simply delete all files in the build directory
#
#  - it is possible to simultanuously build different configurations from the
#    same set of source files
#
# Potential disadvantages of shadow building are:
#
#  - shadow building needs a way to find the source files, as they are not
#    located in the build directory
#
#  - when starting 'make' from the command line, the makefile to be used must
#    be explicitly specified
#
# For shadow building, SOURCE_DIR should contain the path of the directory
# containing the project's source files. It can be relative to the build folder
# or absolute, and should end with '/'. Any spaces in the path must be preceded
# by a triple backslash. If SOURCE_DIR is not defined, shadow building is not
# possible. If you want to build in the source directory,  you will also have
# to remove the test for shadow building below.
#
# In Embeetle, source files are located in the project's top directory, and
# SOURCE_DIR is defined accordingly in dashboard.mk.  When building outside
# Embeetle, you can override SOURCE_DIR on the command line using:
#    $ make SOURCE_DIR=/path/to/project ...
#

# Check that we are using shadow building. If you want to allow building in the
# source directory, comment or remove the check below.
ifeq ($(abspath $(SOURCE_DIR)),$(abspath .))
  $(info Please use shadow building:)
  $(info create a new directory and build there using)
  $(info $   $(MAKE) SOURCE_DIR=$(abspath .) -f $(abspath $(firstword $(MAKEFILE_LIST))))
  $(error Attempt to build in the source directory)
else
  # Protect against shadow building in non-build directories, to avoid deleting
  # source files during `make clean`. Shadow building is only allowed in an
  # empty directory and in a directory containing a .build file.  In an empty
  # directory, a .build file is automatically created.  If you don't want this
  # protection, comment or remove the check below.
  ifeq ($(wildcard * .[^.]* ..?*),)
    $(shell $(TOUCH) .build)
  endif
  ifeq ($(wildcard .build),)
    $(info Build directory not empty and .build file not found)
    $(info Build directory is $(abspath .))
    $(info Create an empty .build file if you really want to build here)
    $(error Attempt to build in a non-empty non-build directory)
  endif

  # If the source directory has subdirectories, create the same subdirectories
  # in the build directory, so that the object file for a source file in a
  # subdirectory can be created in the corresponding subdirectory of the build
  # directory.
  #
  # The list of subdirectories to create is automatically derived from the list
  # of object files OFILES (normally defined in filetree.mk - see further).
  SUBDIRS = $(sort $(dir $(OFILES)))
  .PHONY: subdirs
  subdirs: $(SUBDIRS)
  $(OFILES): | subdirs
  %/: ; $(call MKDIR, $@)
endif


# AUTOMATIC DEPENDENCY TRACKING
# =============================
#
# Dependency (.d) files are generated by the preprocessor with the -MMD flag.
# These files give make the necessary information to decide which files to
# recompile when a header files changes.
#
# -MF makes sure that the dependency file is generated next to the object file.
#
# -MP adds a target with no dependencies for each header file, so that make
#     will not complain when you remove a header file that is still mentioned in
#     a dependency file.
#
# -MQ sets the name of the target file in the dependency file,  to make sure
#     that it matches the object file.

DEPFLAGS = -MMD -MF $(@:.o=.d) -MP -MQ $@
include $(wildcard $(OFILES:.o=.d))


# COMPILERS
# =========
#
# Define the compilers to be used for compilation. We'll use cross compilers
# for the target microcontroller. These typically have the same command names as
# a native gcc compiler, with a prefix (e.g. arm-none-eabi- for ARM
# cross-compilers).
#
# Note: A cross compiler is a compiler that runs on one machine (e.g. a Windows
#       desktop) to compile code for another type of machine (e.g. your
#       microcontroller).
#
# The TOOLPREFIX variable can be given a value on the command line. If not, the
# default value given in 'dashboard.mk' is used. In Embeetle, we use an absolute
# path for TOOLPREFIX. See ADDENDUM 2 at the bottom of this file for why we do
# that.
#
# We use the C and C++ compilers(*), as well as the 'objcopy' and 'size'
# commands. The C compiler is also used for assembly code. For linking,  we use
# the C++ compiler if there are any C++ files in the project,  and the C compiler
# otherwise. The C++ compiler will link in the C++ standard libraries. CXX_OFILES
# is defined in filetree.mk.
#
# (*) Strictly speaking,  'gcc' and 'g++' are not compilers but "driver
#     programs",  programs that call the compiler and other tools as appropriate
#     for the arguments you give them.

CC      = "$(TOOLPREFIX)gcc"
CXX     = "$(TOOLPREFIX)g++"
LD      = $(if $(CXX_OFILES),$(CXX),$(CC))
OBJCOPY = "$(TOOLPREFIX)objcopy"
OBJSIZE = "$(TOOLPREFIX)size"
GDB     = "$(TOOLPREFIX)gdb"


# COMPILATION FLAGS
# =================
#
# COMMONFLAGS
# -----------
#
# Common flags for C/C++ and assembly compilations and linking.
#
#     $(TARGET_COMMONFLAGS) CPU specific compilation flags, defined in
#                           dashboard.mk
#
#     -Og                   The optimization level of choice for the standard
#                           edit-compile-debug cycle, offering a reasonable
#                           level of optimization while maintaining fast
#                           compilation and a good debugging experience.  It is
#                           a better choice than -O0 for producing debuggable
#                           code because some compiler passes that collect debug
#                           information are disabled at -O0.
#
#     -g3                   Maximize debug information.
#
#     -MMD                  Tell preprocessor to generate dependency (.d) files
#                           that will help make to determine what files to re-
#                           compile after a change in a header file.
#
#     -fmessage-length=0    Try to format error messages so that they fit on li-
#                           nes of about n characters. If n=0, they'll be prin-
#                           ted on a single line.
#
#     -ffunction-sections   Generate a separate ELF section for each function in
#                           the source file. The unused section elimination fea-
#                           ture of the linker can then remove unused functions
#                           at link time.
#
#     -fdata-sections       Enable the generation of one ELF section for each
#                           variable in the source file.
#
#     -Wno-comment          Do not warn when /* appears in the middle of a /* */
#                           comment.
#
#     -Wno-unused-function  Do not warn for a static function that is declared
#                           but not defined, or a non\-inline static function
#                           that is unused.
#
# ABOUT WARNINGS:
#     The flags -Wall and -Wextra make sure that most potential problems are
#     reported as warnings. We did not add these flags by default because they
#     trigger a lot of warnings in third party code in many sample projects, and
#     we don't have the resources to fix all of them. However, we do recommend
#     to add these flags for your own projects.
#
#     The flag -Werror turns all these warnings into errors. To avoid acciden-
#     tally missing an important warning, add this flag and edit your source
#     code until no warnings are reported. For even more warnings, see
#     https://kristerw.blogspot.com/2017/09/useful-gcc-warning-options-not-enabled.html
COMMONFLAGS = \
  $(TARGET_COMMONFLAGS) \
  -Og \
  -g3 \
  -fmessage-length=0 \
  -ffunction-sections \
  -fdata-sections \
  -Wno-comment \
  -Wno-unused-function \

# CFLAGS
# ------
#
# C compilation flags.
#
#     -Werror-implicit-function-declaration    Give a warning (or error) when-
#                                              ever a function is used before
#                                              being declared.
#
# Note: The variable TARGET_CFLAGS gets defined in 'dashboard.mk'.
CFLAGS = $(COMMONFLAGS) $(DEPFLAGS) $(TARGET_CFLAGS) $(HDIR_FLAGS) \
  -Werror-implicit-function-declaration \

# CXXFLAGS
# --------
#
# C++ compilation flags.
# Note: The variable TARGET_CXXFLAGS gets defined in 'dashboard.mk'.
CXXFLAGS = $(COMMONFLAGS) $(DEPFLAGS) $(TARGET_CXXFLAGS) $(HDIR_FLAGS)

# SFLAGS
# ------
#
# Assembly specific compilation flags.
# Note: The variable TARGET_SFLAGS gets defined in 'dashboard.mk'.
SFLAGS = $(COMMONFLAGS) $(DEPFLAGS) $(TARGET_SFLAGS) $(HDIR_FLAGS)

# LDFLAGS
# --------
#
# Linker flags.
# Note: The variable TARGET_LDFLAGS gets defined in 'dashboard.mk'.
#
#     -Wl,-Map=output.map    Pass "-Map output.map" flag to linker,
#                            request output.map generation.
#
#     -Wl,--gc-sections      Pass "--gc-sections" flag to linker,
#                            garbage collect unused sections.
LDFLAGS = \
  -Wl,-Map=output.map \
  -Wl,--gc-sections \
  $(COMMONFLAGS) \
  $(TARGET_LDFLAGS) \

# DEPENDENCIES FOR THE FINAL .ELF FILE
# ====================================
#
# If you included Embeetle's 'filetree.mk' file in this makefile, then the
# object file list OFILES has been defined. Otherwise, you have to define it
# yourself.
#
# The dependency on 'filetree.mk' below makes sure that the elf file is relinked
# when the source file lists have changed, even if no source files changed. Feel
# free to remove it if you do not want that behavior.
#
$(ELF_FILE): $(dir $(firstword $(MAKEFILE_LIST)))filetree.mk $(OFILES)

# RULES TO BUILD THE ELF FILES AND EXTRACT INFORMATION FROM IT
# ============================================================
#
# The rules to build the .bin and .hex files from the .elf, can be
# dependent on the target microcontroller. Therefore, we've moved them
# to the 'dashboard.mk' file.

%.elf:
	$(info )
	$(info )
	$(info )
	$(info Link program into $@)
	$(LD) $(LDFLAGS) -o $@ $(filter %.o %.a %.so,$^) $(PROJECT_LDLIBS) $(TOOLCHAIN_LDLIBS)

.PHONY: show_size
show_size: $(ELF_FILE:.elf=.size)

%.size: %.elf
	$(info )
	$(info )
	$(info Preparing: $@)
	$(OBJSIZE) $<

# CLEAN
# =====
#
# Remove files generated during the build process. For a shadow build, all files
# can be safely removed.  For a build in (a parent directory of) the source
# directory, remove files selectively to avoid removing source files.

.PHONY: clean
clean: print_clean
ifeq ($(filter $(realpath .)/,$(realpath $(SOURCE_DIR))/),)
	$(REMOVE_ALL)
else
	$(call RM,$(wildcard $(patsubst %,%*.o %*.d,$(SUBDIRS)) *.elf *.size *.bin))
endif

# ASCII ART
# =========
#
# We provide some nice ascii-art, to be printed for each target.

LPAREN :=(
RPAREN :=)

.PHONY: print_clean
print_clean:
	$(info)
	$(info)
	$(info # ----------------------------------------------------------)
	$(info #        __         **************)
	$(info #      __\ \___     * make clean *)
	$(info #      \ _ _ _ \    **************)
	$(info #       \_`_`_`_\ )
	$(info # )
	$(info #  Operating system:    $(OS))
	$(info #  Shell:               $(SHELL))
	$(info #  Shell style:         $(SHELLSTYLE))
	$(info #  Source folder:       $(abspath $(SOURCE_DIR)))
	$(info #  Build folder:        $(abspath .))
	$(info # ----------------------------------------------------------)

.PHONY: print_build
print_build:
	$(info)
	$(info # ----------------------------------------------------------------)
	$(info #             $(RPAREN)\     **************)
	$(info #   $(LPAREN) =_=_=_=<| |    * make build *)
	$(info #             $(RPAREN)$(LPAREN)     **************)
	$(info #             "" )
	$(info # )
	$(info #  Operating system:    $(OS))
	$(info #  Shell:               $(SHELL))
	$(info #  Shell style:         $(SHELLSTYLE))
	$(info #  Source folder:       $(abspath $(SOURCE_DIR)))
	$(info #  Build folder:        $(abspath .))
	$(info #  Binary output:       $(BINARIES))
	$(info # ----------------------------------------------------------------)

.PHONY: print_flash
print_flash:
	$(info)
	$(info)
	$(info # ----------------------------------------------------------)
	$(info #        __         **************)
	$(info #       / /_        * make flash *)
	$(info #      /_  /        **************)
	$(info #        /` )
	$(info #       ` )
	$(info #  Operating system:    $(OS))
	$(info #  Shell:               $(SHELL))
	$(info #  Shell style:         $(SHELLSTYLE))
	$(info #  Source folder:       $(abspath $(SOURCE_DIR)))
	$(info #  Build folder:        $(abspath .))
	$(info # ----------------------------------------------------------)

.PHONY: print_flash_bootloader
print_flash_bootloader:
	$(info)
	$(info)
	$(info # ----------------------------------------------------------)
	$(info #        /\         *************************)
	$(info #       $(LPAREN)  $(RPAREN)        * make flash_bootloader *)
	$(info #       $(LPAREN)  $(RPAREN)        *************************)
	$(info #      /|/\|\ )
	$(info #     /_||||_\ )
	$(info #  Operating system:    $(OS))
	$(info #  Shell:               $(SHELL))
	$(info #  Shell style:         $(SHELLSTYLE))
	$(info #  Source folder:       $(abspath $(SOURCE_DIR)))
	$(info #  Build folder:        $(abspath .))
	$(info # ----------------------------------------------------------)


# ADDENDUM 1. MIT LICENSE
# =======================
# Copyright 2020 Johan Cockx
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is furn-
# ished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# ADDENDUM 2. WHY WE USE ABSOLUTE PATHS FOR THE COMPILERS
# =======================================================
# Please note that we use absolute(!) paths to refer to the compilers. Normally,
# it would be sufficient to add the absolute paths just once to the PATH
# environment variable and call the compiler by its name from then forward.
# Unfortunately, on Windows this causes the error 'CreateProcess: No such file
# or directory'. Apparently this is because of a missing registry key, one that
# gets written to the registry when you install the compiler through the
# official installer. That registry key then points to the location of the
# installation. We strongly dislike this approach, because:
#
#       - We don't like messing with your registry.
#
#       - The location of your compiler must be stored in two places: the
#         registry and the PATH environment variable. If you move the compiler,
#         you should change both of them. Most often, people forget to adapt the
#         registry key and disaster strikes...
#
# Therefore, we see no other option than calling the compilers by their absolute
# path. To do that practically, we glue the TOOLCHAIN variable to the compiler
# name.