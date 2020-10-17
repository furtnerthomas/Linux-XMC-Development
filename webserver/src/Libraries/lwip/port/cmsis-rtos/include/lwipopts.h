#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define NO_SYS                  0
#define LWIP_SOCKET             1
#define LWIP_NETCONN            1
#define SYS_LIGHTWEIGHT_PROT    1

#define MEM_ALIGNMENT           4

#define TCPIP_MBOX_SIZE         4
#define TCPIP_THREAD_STACKSIZE  1024
#define DEFAULT_THREAD_STACKSIZE 1024

#define MEM_SIZE                14 * 1024

#define PBUF_POOL_SIZE          10
#define PBUF_POOL_BUFSIZE       1536

#define LWIP_UDP                1
#define LWIP_TCP                1
#define TCP_MSS                 1460
#define TCP_WND                 (2 * TCP_MSS)
#define TCP_SND_BUF             (2 * TCP_MSS)

#define LWIP_STATS 0

#define CHECKSUM_GEN_IP         0
#define CHECKSUM_GEN_UDP        0
#define CHECKSUM_GEN_TCP        0
#define CHECKSUM_GEN_ICMP       0
#define CHECKSUM_CHECK_IP       0
#define CHECKSUM_CHECK_UDP      0
#define CHECKSUM_CHECK_TCP      0


#ifdef __cplusplus
}
#endif
#endif /* __LWIPOPTS_H__ */

