
INCLUDE_DIRS    = -Isrc/include \
                  -Isrc/email/Dave/Generated \
                  -Isrc/email/Dave/Model/Common \
                  -Isrc/email/Dave/Generated/ETH_LWIP/lwip/port/include \
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
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/tcp.c \
                    src/email/Dave/Model/APPS/ETH_LWIP/v4_0_10/Templates/lwip/core/tcp_out.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/tcp_in.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/ipv4/ip_addr.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/netif/etharp.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/port/sys_arch.c \
                    src/email/Dave/Generated/SYSTIMER/systimer.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/mem.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/netif.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/raw.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/udp.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/ipv4/icmp.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/ipv4/inet_chksum.c \
                    src/email/Dave/Generated/DIGITAL_IO/digital_io_conf.c \
                    src/email/Dave/Model/APPS/ETH_LWIP/v4_0_10/Templates/lwip/core/timers.c \
                    src/email/Dave/Model/APPS/ETH_LWIP/v4_0_10/Templates/lwip/core/memp.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/pbuf.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/def.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/ipv4/ip.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/port/include/arch/memcpy.c \
                    src/email/Dave/Generated/DAVE.c \
                    src/email/Dave/Generated/CLOCK_XMC4/clock_xmc4.c \
                    src/email/Dave/Generated/ETH_LWIP/eth_lwip.c \
                    src/email/Dave/Generated/DIGITAL_IO/digital_io.c \
                    src/email/Dave/Generated/CLOCK_XMC4/clock_xmc4_conf.c \
                    src/email/Dave/Generated/ETH_LWIP/eth_lwip_conf.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/core/init.c \
                    src/email/Dave/Generated/SYSTIMER/systimer_conf.c \
                    src/email/Dave/Generated/ETH_LWIP/lwip/port/netif/ethernetif.c \
                    src/email/Libraries/XMCLib/src/xmc_gpio.c \
                    src/email/Dave/Generated/ETH_LWIP/xmc_eth_phy_ksz8081rnl.c \
                    src/email/Libraries/XMCLib/src/xmc_eth_mac.c \
                    src/ADC_XMC4500.c \
                    src/main.c


