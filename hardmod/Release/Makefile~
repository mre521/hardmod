SHELL := sh
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
LIB_AS_ARGS :=
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
HEX_FLASH_FILE_PATH :=
HEX_FLASH_FILE_PATH_AS_ARGS :=
HEX_EEPROM_FILE_PATH :=
HEX_EEPROM_FILE_PATH_AS_ARGS :=
LSS_FILE_PATH :=
LSS_FILE_PATH_AS_ARGS :=
MAP_FILE_PATH :=
MAP_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../format.c \
../hardmod.c


PREPROCESSING_SRCS += 


ASM_SRCS += 

SONG += song.h

OBJS +=  \
format.o \
hardmod.o


OBJS_AS_ARGS +=  \
format.o \
hardmod.o


C_DEPS +=  \
format.d \
hardmod.d


C_DEPS_AS_ARGS +=  \
format.d \
hardmod.d


OUTPUT_FILE_PATH +=hardmod.elf

OUTPUT_FILE_PATH_AS_ARGS +=hardmod.elf

HEX_FLASH_FILE_PATH =hardmod.hex

HEX_FLASH_FILE_PATH_AS_ARGS +=hardmod.hex

HEX_EEPROM_FILE_PATH +=hardmod.eep

HEX_EEPROM_FILE_PATH_AS_ARGS +=hardmod.eep

LSS_FILE_PATH +=hardmod.lss

LSS_FILE_PATH_AS_ARGS +=hardmod.lss

MAP_FILE_PATH =hardmod.map

MAP_FILE_PATH_AS_ARGS =hardmod.map

LIB_AS_ARGS +=libhardmod.a

ADDITIONAL_DEPENDENCIES:= $(HEX_FLASH_FILE_PATH) $(LSS_FILE_PATH) $(HEX_EEPROM_FILE_PATH) size

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR/GNU C Compiler





./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(QUOTE)$(AVR_APP_PATH)avr-gcc$(QUOTE) -funsigned-bitfields -DF_CPU=16000000L  -O3 -fdata-sections -ffunction-sections -fpack-struct -fshort-enums -Wall -c -mmcu=atmega328p   -MD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<

./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR/GNU CPP Compiler
	$(QUOTE)$(AVR_APP_PATH)avr-g++$(QUOTE)   -MD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<



# AVR/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(SONG) $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

# AVR/GNU C/C++ Linker
$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU C/C++ Linker
	$(QUOTE)$(AVR_APP_PATH)avr-gcc$(QUOTE)  -mmcu=atmega328p  -Wl,-Map=$(MAP_FILE_PATH_AS_ARGS) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@


$(HEX_FLASH_FILE_PATH): $(OUTPUT_FILE_PATH)
	$(QUOTE)$(AVR_APP_PATH)avr-objcopy$(QUOTE) -O ihex -R .eeprom -R .fuse -R .lock -R .signature  $(QUOTE)$<$(QUOTE) $(QUOTE)$@$(QUOTE)
	$(QUOTE)$(AVR_APP_PATH)avr-objcopy$(QUOTE) -O binary -R .eeprom -R .fuse -R .lock -R .signature  $(QUOTE)$<$(QUOTE) $(QUOTE)$@.bin$(QUOTE)

$(HEX_EEPROM_FILE_PATH): $(OUTPUT_FILE_PATH)
	-$(QUOTE)$(AVR_APP_PATH)avr-objcopy$(QUOTE) -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex $(QUOTE)$<$(QUOTE) $(QUOTE)$@$(QUOTE) || exit 0

$(LSS_FILE_PATH): $(OUTPUT_FILE_PATH)
	$(QUOTE)$(AVR_APP_PATH)avr-objdump$(QUOTE) -h -S $(QUOTE)$<$(QUOTE) > $(QUOTE)$@$(QUOTE)

size: $(OUTPUT_FILE_PATH)
	@$(QUOTE)$(AVR_APP_PATH)avr-size$(QUOTE) -C --mcu=atmega328p $(OUTPUT_FILE_PATH_AS_ARGS)

# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) $(LIB_AS_ARGS)  $(HEX_FLASH_FILE_PATH_AS_ARGS) $(HEX_EEPROM_FILE_PATH_AS_ARGS) $(LSS_FILE_PATH_AS_ARGS) $(MAP_FILE_PATH_AS_ARGS)

program: all
	avrdude -patmega328p -carduino -P/dev/ttyACM1 -D -Uflash:w:$(QUOTE)$(HEX_FLASH_FILE_PATH)$(QUOTE)

$(SONG):
	../avrmodconvert -i ../song.mod -o ../song.bin
	../bin2h ../song.bin ../song.h -id=songdata


