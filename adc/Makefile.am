
INCLUDE_DIRS    = -Isrc/include \
                  -I../../../opt/cmsis-packs/Infineon/XMC4000_DFP/2.13.0/Device/XMClib/inc \
                  -I../../../opt/cmsis-packs/Infineon/XMC4000_DFP/2.13.0/Device/XMC4500_series/Include

ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS       = $(INCLUDE_DIRS) -std=c99 -Wall -O0 -g  \
                                  -DXMC4500_F100x1024 -DUC_ID \
                                  -mthumb \
                                  -march=armv7-m \
                                  --specs=nosys.specs \
                                  -Wl,--gc-sections

CFLAGS = -g -gdwarf-2 -O0

CC              = arm-none-eabi-gcc
CCAS            = arm-none-eabi-gcc
AM_LDFLAGS      = -g -O0 -Tsrc/linker_script.ld


bin_PROGRAMS = main.bin

main_bin_SOURCES =  src/Startup/system_XMC4500.c \
                    src/Startup/startup_XMC4500.S \
                    ../../../opt/cmsis-packs/Infineon/XMC4000_DFP/2.13.0/Device/XMClib/src/xmc4_gpio.c \
                    ../../../opt/cmsis-packs/Infineon/XMC4000_DFP/2.13.0/Device/XMClib/src/xmc4_scu.c \
                    ../../../opt/cmsis-packs/Infineon/XMC4000_DFP/2.13.0/Device/XMClib/src/xmc_vadc.c \
                    src/ADC_XMC4500.c \
                    src/main.c


