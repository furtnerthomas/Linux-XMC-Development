
INCLUDE_DIRS    = -Isrc/Libraries/CMSIS/Include \
                  -Isrc/Libraries/CMSIS/Infineon/XMC4500_series/Include \
                  -I/home/thomas/opt/xPacks/@xpack-dev-tools/arm-none-eabi-gcc/9.3.1-1.2.1/.content/arm-none-eabi/include/ \
                  -Isrc/Libraries/XMCLib/inc \
                  -Isrc/Libraries/cmsis_rtos_rtx/INC \
                  -Isrc/Libraries/lwip/include \
                  -Isrc/Libraries/lwip/include/ipv4 \
                  -Isrc/Libraries/lwip/port/cmsis-rtos/include \
                  -Isrc/Libraries/lwip/port/cmsis-rtos/netif

ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS       = $(INCLUDE_DIRS) -std=c99 -Wall -O0 -g -gdwarf-2 \
                                  -DXMC4500_F144x1024 -D__CORTEX_M4 \
                                  -D__FPU_PRESENT -D__CMSIS_RTOS \
                                  -mthumb \
                                  -march=armv7-m \
                                  --specs=nosys.specs \
                                  -Wl,--gc-sections

CC              = arm-none-eabi-gcc
CCAS            = arm-none-eabi-gcc -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -D__CORTEX_M4
AM_LDFLAGS      = -g -O0 -Tsrc/linker_script.ld 


bin_PROGRAMS = main.bin

main_bin_SOURCES =  src/Startup/system_XMC4500.c \
                    src/Startup/startup_XMC4500.S \
                    src/Libraries/cmsis_rtos_rtx/SRC/GCC/SVC_Table.S \
                    src/Libraries/cmsis_rtos_rtx/SRC/GCC/HAL_CM4.s \
                    src/main.c \
                    xmc_eth_phy_ksz8031rnl.c \
                    src/httpserver/httpserver-netconn.c \
					src/Libraries/XMCLib/src/xmc_ebu.c \
					src/Libraries/XMCLib/src/xmc4_flash.c \
					src/Libraries/XMCLib/src/xmc_i2s.c \
					src/Libraries/XMCLib/src/xmc_hrpwm.c \
					src/Libraries/XMCLib/src/xmc_dac.c \
					src/Libraries/XMCLib/src/xmc_eth_mac.c \
					src/Libraries/XMCLib/src/xmc_rtc.c \
					src/Libraries/XMCLib/src/xmc_ecat.c \
					src/Libraries/XMCLib/src/xmc_sdmmc.c \
					src/Libraries/XMCLib/src/xmc_can.c \
					src/Libraries/XMCLib/src/xmc4_eru.c \
					src/Libraries/XMCLib/src/xmc_gpio.c \
					src/Libraries/XMCLib/src/xmc_fce.c \
					src/Libraries/XMCLib/src/xmc_eru.c \
					src/Libraries/XMCLib/src/xmc_uart.c \
src/Libraries/XMCLib/src/xmc_common.c \
src/Libraries/XMCLib/src/xmc_dsd.c \
src/Libraries/XMCLib/src/xmc_i2c.c \
src/Libraries/XMCLib/src/xmc_vadc.c \
src/Libraries/XMCLib/src/xmc_ledts.c \
src/Libraries/XMCLib/src/xmc_dma.c \
src/Libraries/XMCLib/src/xmc_ccu8.c \
src/Libraries/XMCLib/src/xmc4_rtc.c \
src/Libraries/XMCLib/src/xmc_ccu4.c \
src/Libraries/XMCLib/src/xmc_posif.c \
src/Libraries/XMCLib/src/xmc4_scu.c \
src/Libraries/XMCLib/src/xmc_spi.c \
src/Libraries/XMCLib/src/xmc_wdt.c \
src/Libraries/XMCLib/src/xmc4_gpio.c \
src/Libraries/XMCLib/src/xmc_usbd.c \
src/Libraries/XMCLib/src/xmc_usic.c \
src/Libraries/cmsis_rtos_rtx/SRC/HAL_CM.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_Mailbox.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_Semaphore.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_Timer.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_Memory.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_CMSIS.c \
src/Libraries/cmsis_rtos_rtx/SRC/rt_Task.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_Event.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_List.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_MemBox.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_Robin.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_Mutex.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_System.c \
./src/Libraries/cmsis_rtos_rtx/SRC/rt_Time.c \
./src/Libraries/cmsis_rtos_rtx/RTX_Conf_CM.c \
./src/Libraries/lwip/api/netbuf.c \
./src/Libraries/lwip/api/netdb.c \
./src/Libraries/lwip/api/api_msg.c \
./src/Libraries/lwip/api/err.c \
./src/Libraries/lwip/api/sockets.c \
./src/Libraries/lwip/api/api_lib.c \
./src/Libraries/lwip/api/tcpip.c \
./src/Libraries/lwip/api/netifapi.c \
./src/Libraries/lwip/netif/ppp/md5.c \
./src/Libraries/lwip/netif/ppp/chpms.c \
./src/Libraries/lwip/netif/ppp/fsm.c \
./src/Libraries/lwip/netif/ppp/randm.c \
./src/Libraries/lwip/netif/ppp/lcp.c \
./src/Libraries/lwip/netif/ppp/magic.c \
./src/Libraries/lwip/netif/ppp/ipcp.c \
./src/Libraries/lwip/netif/ppp/pap.c \
./src/Libraries/lwip/netif/ppp/ppp_oe.c \
./src/Libraries/lwip/netif/ppp/auth.c \
./src/Libraries/lwip/netif/ppp/ppp.c \
./src/Libraries/lwip/netif/ppp/vj.c \
./src/Libraries/lwip/netif/ppp/chap.c \
./src/Libraries/lwip/netif/slipif.c \
./src/Libraries/lwip/netif/etharp.c \
./src/Libraries/lwip/core/memp.c \
./src/Libraries/lwip/core/timers.c \
./src/Libraries/lwip/core/raw.c \
./src/Libraries/lwip/core/udp.c \
./src/Libraries/lwip/core/mem.c \
./src/Libraries/lwip/core/pbuf.c \
./src/Libraries/lwip/core/dns.c \
./src/Libraries/lwip/core/stats.c \
./src/Libraries/lwip/core/tcp.c \
./src/Libraries/lwip/core/ipv4/icmp.c \
./src/Libraries/lwip/core/ipv4/ip.c \
./src/Libraries/lwip/core/ipv4/autoip.c \
./src/Libraries/lwip/core/ipv4/inet.c \
./src/Libraries/lwip/core/ipv4/ip_addr.c \
./src/Libraries/lwip/core/ipv4/inet_chksum.c \
./src/Libraries/lwip/core/ipv4/ip_frag.c \
./src/Libraries/lwip/core/ipv4/igmp.c \
./src/Libraries/lwip/core/tcp_in.c \
./src/Libraries/lwip/core/init.c \
./src/Libraries/lwip/core/sys.c \
./src/Libraries/lwip/core/netif.c \
./src/Libraries/lwip/core/tcp_out.c \
./src/Libraries/lwip/core/def.c \
./src/Libraries/lwip/core/dhcp.c \
./src/Libraries/lwip/core/snmp/mib2.c \
./src/Libraries/lwip/core/snmp/asn1_enc.c \
./src/Libraries/lwip/core/snmp/msg_in.c \
./src/Libraries/lwip/core/snmp/asn1_dec.c \
./src/Libraries/lwip/core/snmp/mib_structs.c \
./src/Libraries/lwip/core/snmp/msg_out.c \
./src/Libraries/lwip/port/cmsis-rtos/netif/ethernetif.c \
./src/Libraries/lwip/port/cmsis-rtos/sys_arch.c \
./src/Libraries/Newlib/syscalls.c


