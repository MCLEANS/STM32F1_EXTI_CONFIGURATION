

# list of source files
#CXX SOURCE_FILES
CXX_SOURCES = main.cpp
CXX_SOURCES += EXTI.cpp

#C SOURCE FILES
#SOURCES  = main.c
SOURCES  += ./dependencies/system_stm32f10x.c
SOURCES += ./dependencies/stm32f10x_it.c
SOURCES += ./startup/startup_stm32f10x_md.s

# name for output binary files
PROJECT = main

# compiler, objcopy (should be in PATH)
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy

# path to st-flash (or should be specified in PATH)
ST_FLASH = st-flash

# specify compiler flags
CFLAGS  = -g -O2 -Wall
CFLAGS += -T  stm32_flash.ld -specs=nano.specs -specs=nosys.specs
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m3 -mthumb-interwork
CFLAGS += -mfloat-abi=soft -mfpu=fpv4-sp-d16
CFLAGS += -DSTM32F10X_MD 
CFLAGS += -Wl,--gc-sections
CFLAGS += -I ./Includes
CFLAGS += -I .

all: $(PROJECT).elf

# compile
$(PROJECT).elf: $(CXX_SOURCES)
	$(CXX) $(CFLAGS) $(CXX_SOURCES) $(SOURCES) -o $@
	$(OBJCOPY) -O ihex $(PROJECT).elf $(PROJECT).hex
	$(OBJCOPY) -O binary $(PROJECT).elf $(PROJECT).bin

# remove binary files
clean:
	rm -f *.o *.elf *.hex *.bin

# flash
flash:
	sudo $(ST_FLASH) write $(PROJECT).bin 0x8000000
