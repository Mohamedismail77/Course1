#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
TARGET = c1m2
CPPFLAGs = -E -S
# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
OBJS = $(SOURCES:.c=.o)
# Compiler Flags and Defines
	ifeq ($(PLATFORM) ,HOST)
		CC = gcc
		SOURCES = main.c memory.c
		INCLUDES = -I ../include/CMSIS -I ../include/common
		LDFLAGS = -Wl,-Map=$(TARGET).map
		CFLAGS = -std=c99 -Wall -Werror -O0 -g -D$(PLATFORM) $(INCLUDES)
	else
		CC = arm-none-eabi-gcc
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
		CFLAGS = -std=c99 -Wall -Werror -O0 -g -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) -D$(PLATFORM) $(INCLUDES)
	endif

%.i:$(SOURCES)
	$(CC) $(CFLAGS) $(CPPFLAGs) $< -o $@

%.o:$(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) $< -o $@

%.asm:$(SOURCES)
	$(CC) $(CFLAGS)  $(CPPFLAGs) $< -o $@ 

$(TARGET).out:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:
	rm -f *.o $(TARGET).out $(TARGET).map *.i *.asm


