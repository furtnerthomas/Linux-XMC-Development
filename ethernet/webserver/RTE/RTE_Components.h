
/*
 * Auto generated Run-Time-Environment Component Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'HTTP_Server' 
 * Target:  'XMC4500 RelaxKit' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "XMC4500.h"

#define RTE_CMSIS_RTOS                  /* CMSIS-RTOS */
        #define RTE_CMSIS_RTOS_RTX              /* CMSIS-RTOS Keil RTX */
#define RTE_DEVICE
#define RTE_DEVICE_STARTUP
#define RTE_DEVICE_XMCLIB_GPIO
#define RTE_DEVICE_XMCLIB_SCU
#define RTE_Drivers_ETH_MAC
#define RTE_Drivers_PHY_KSZ8031        /* Driver PHY KSZ8031 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_IPv4                /* Network IPv4 Stack */
          #define RTE_Network_IPv6                /* Network IPv6 Stack */
          #define RTE_Network_Release             /* Network Release Version */
#define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */
#define RTE_Network_Socket_TCP          /* Network Socket TCP */
#define RTE_Network_Socket_UDP          /* Network Socket UDP */
#define RTE_Network_Web_Server_RO       /* Network Web Server with Read-only Web Resources */

#endif /* RTE_COMPONENTS_H */
