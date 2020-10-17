/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#include "lwip/opt.h"

#include "lwip/def.h"
#include "lwip/sys.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include <lwip/stats.h>
#include <lwip/snmp.h>
#include "netif/etharp.h"
#include "netif/ppp_oe.h"

#include "xmc_gpio.h"
#include "xmc_eth_mac.h"
#include "xmc_eth_phy.h"
#include <string.h>

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

#define RXD1     P2_3
#define RXD0     P2_2
#define RXER     P2_4
#define CLK_RMII P15_8
#define TX_EN    P2_5
#define TXD1     P2_9
#define TXD0     P2_8
#define CRS_DV   P15_9
#define MDIO     P2_0
#define MDC      P2_7

#define PHY_ADDR 0

#define XMC_ETH_MAC_NUM_RX_BUF (4)
#define XMC_ETH_MAC_NUM_TX_BUF (4)

/* MAC ADDRESS*/
#define MAC_ADDR0   0x00
#define MAC_ADDR1   0x00
#define MAC_ADDR2   0x45
#define MAC_ADDR3   0x19
#define MAC_ADDR4   0x03
#define MAC_ADDR5   0x00
#define MAC_ADDR    ((uint64_t)MAC_ADDR0 | \
                     ((uint64_t)MAC_ADDR1 << 8) | \
                     ((uint64_t)MAC_ADDR2 << 16) | \
                     ((uint64_t)MAC_ADDR3 << 24) | \
                     ((uint64_t)MAC_ADDR4 << 32) | \
                     ((uint64_t)MAC_ADDR5 << 40))


__attribute__((aligned(4))) XMC_ETH_MAC_DMA_DESC_t rx_desc[XMC_ETH_MAC_NUM_RX_BUF] __attribute__((section ("ETH_RAM")));
__attribute__((aligned(4))) XMC_ETH_MAC_DMA_DESC_t tx_desc[XMC_ETH_MAC_NUM_TX_BUF] __attribute__((section ("ETH_RAM")));
__attribute__((aligned(4))) uint8_t rx_buf[XMC_ETH_MAC_NUM_RX_BUF][XMC_ETH_MAC_BUF_SIZE] __attribute__((section ("ETH_RAM")));
__attribute__((aligned(4))) uint8_t tx_buf[XMC_ETH_MAC_NUM_TX_BUF][XMC_ETH_MAC_BUF_SIZE] __attribute__((section ("ETH_RAM")));

XMC_ETH_PHY_CONFIG_t eth_phy_config =
{
  .interface = XMC_ETH_LINK_INTERFACE_RMII,
  .enable_auto_negotiate = true
};

XMC_ETH_MAC_t eth_mac =
{
  .regs = ETH0,
  .address = MAC_ADDR,
  .rx_desc = rx_desc,
  .tx_desc = tx_desc,
  .rx_buf = &rx_buf[0][0],
  .tx_buf = &tx_buf[0][0],
  .num_rx_buf = XMC_ETH_MAC_NUM_RX_BUF,
  .num_tx_buf = XMC_ETH_MAC_NUM_TX_BUF
};

sys_sem_t eth_rx_semaphore;

__attribute__((aligned(4))) uint8_t buffer[XMC_ETH_MAC_BUF_SIZE];

/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void
low_level_init(struct netif *netif)
{
  XMC_ETH_MAC_PORT_CTRL_t port_control;
  XMC_GPIO_CONFIG_t gpio_config;

  /* set MAC hardware address length */
  netif->hwaddr_len = ETHARP_HWADDR_LEN;

  /* set MAC hardware address */
  netif->hwaddr[0] =  MAC_ADDR0;
  netif->hwaddr[1] =  MAC_ADDR1;
  netif->hwaddr[2] =  MAC_ADDR2;
  netif->hwaddr[3] =  MAC_ADDR3;
  netif->hwaddr[4] =  MAC_ADDR4;
  netif->hwaddr[5] =  MAC_ADDR5;

  /* maximum transfer unit */
  netif->mtu = 1500;
  
  /* device capabilities */
  /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
  netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP;
 
  /* Do whatever else is needed to initialize interface. */
  gpio_config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;
  XMC_GPIO_Init(RXD0, &gpio_config);
  XMC_GPIO_Init(RXD1, &gpio_config);
  XMC_GPIO_Init(CLK_RMII, &gpio_config);
  XMC_GPIO_Init(CRS_DV, &gpio_config);
  XMC_GPIO_Init(RXER, &gpio_config);
  XMC_GPIO_Init(MDIO, &gpio_config);

  port_control.mode = XMC_ETH_MAC_PORT_CTRL_MODE_RMII;
  port_control.rxd0 = XMC_ETH_MAC_PORT_CTRL_RXD0_P2_2;
  port_control.rxd1 = XMC_ETH_MAC_PORT_CTRL_RXD1_P2_3;
  port_control.clk_rmii = XMC_ETH_MAC_PORT_CTRL_CLK_RMII_P15_8;
  port_control.crs_dv = XMC_ETH_MAC_PORT_CTRL_CRS_DV_P15_9;
  port_control.rxer = XMC_ETH_MAC_PORT_CTRL_RXER_P5_3;
  port_control.mdio = XMC_ETH_MAC_PORT_CTRL_MDIO_P2_0;
  XMC_ETH_MAC_SetPortControl(&eth_mac, port_control);

  XMC_ETH_MAC_Init(&eth_mac);

  XMC_ETH_MAC_DisableJumboFrame(&eth_mac);

  gpio_config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
  gpio_config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE;
  gpio_config.mode = (XMC_GPIO_MODE_t)((uint32_t)XMC_GPIO_MODE_OUTPUT_PUSH_PULL |P2_8_AF_ETH0_TXD0);
  XMC_GPIO_Init(TXD0, &gpio_config);

  gpio_config.mode = (XMC_GPIO_MODE_t)((uint32_t)XMC_GPIO_MODE_OUTPUT_PUSH_PULL | P2_9_AF_ETH0_TXD1);
  XMC_GPIO_Init(TXD1, &gpio_config);

  gpio_config.mode = (XMC_GPIO_MODE_t)((uint32_t)XMC_GPIO_MODE_OUTPUT_PUSH_PULL | P2_5_AF_ETH0_TX_EN);
  XMC_GPIO_Init(TX_EN, &gpio_config);

  gpio_config.mode = (XMC_GPIO_MODE_t)((uint32_t)XMC_GPIO_MODE_OUTPUT_PUSH_PULL | P2_7_AF_ETH0_MDC);
  XMC_GPIO_Init(MDC, &gpio_config);

  XMC_GPIO_SetHardwareControl(MDIO, XMC_GPIO_HWCTRL_PERIPHERAL1);

  XMC_ETH_PHY_Init(&eth_mac, PHY_ADDR, &eth_phy_config);

  while(XMC_ETH_PHY_GetLinkStatus(&eth_mac, PHY_ADDR) != XMC_ETH_LINK_STATUS_UP);

  XMC_ETH_LINK_SPEED_t speed = XMC_ETH_PHY_GetLinkSpeed(&eth_mac, PHY_ADDR);
  XMC_ETH_LINK_DUPLEX_t duplex = XMC_ETH_PHY_GetLinkDuplex(&eth_mac, PHY_ADDR);

  XMC_ETH_MAC_SetLink(&eth_mac, speed, duplex);

  /* Enable ethernet interrupts */
  XMC_ETH_MAC_EnableEvent(&eth_mac, XMC_ETH_MAC_EVENT_RECEIVE);

  NVIC_SetPriority(ETH0_0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 63, 0));
  NVIC_ClearPendingIRQ(ETH0_0_IRQn);
  NVIC_EnableIRQ(ETH0_0_IRQn);

  XMC_ETH_MAC_EnableTx(&eth_mac);
  XMC_ETH_MAC_EnableRx(&eth_mac);
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t
low_level_output(struct netif *netif, struct pbuf *p)
{
  struct pbuf *q;
  int framelen = 0;
  XMC_ETH_MAC_STATUS_t status;
  
  if (p->tot_len > XMC_ETH_MAC_BUF_SIZE) {
    return ERR_BUF;
  }

#if ETH_PAD_SIZE
  pbuf_header(p, -ETH_PAD_SIZE);    /* Drop the padding word */
#endif

  for(q = p; q != NULL; q = q->next) {
    /* Send the data from the pbuf to the interface, one pbuf at a
       time. The size of the data in each pbuf is kept in the ->len
       variable. */
    memcpy(&buffer[framelen], q->payload, q->len);
    framelen += q->len;
  }

#if ETH_PAD_SIZE
  pbuf_header(p, ETH_PAD_SIZE);    /* Reclaim the padding word */
#endif

  status = XMC_ETH_MAC_SendFrame(&eth_mac, buffer, framelen, 0);
  if (status != XMC_ETH_MAC_STATUS_OK)
  {
    return ERR_BUF;
  }


  return ERR_OK;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf *
low_level_input(void)
{
  struct pbuf *p = NULL;
  struct pbuf *q;
  uint32_t len;

  len = XMC_ETH_MAC_GetRxFrameSize(&eth_mac);

#if ETH_PAD_SIZE
  len += ETH_PAD_SIZE;    /* allow room for Ethernet padding */
#endif

  if (len < XMC_ETH_MAC_BUF_SIZE)
  {

    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
  
    if (p != NULL)
    {
#if ETH_PAD_SIZE
      pbuf_header(p, -ETH_PAD_SIZE);  /* drop the padding word */
#endif

      XMC_ETH_MAC_ReadFrame(&eth_mac, buffer, len);

      len = 0;
      /* We iterate over the pbuf chain until we have read the entire
       * packet into the pbuf. */
      for (q = p; q != NULL; q = q->next)
      {
        /* Read enough bytes to fill this pbuf in the chain. The
         * available data in the pbuf is given by the q->len
         * variable.
         * This does not necessarily have to be a memcpy, you can also preallocate
         * pbufs for a DMA-enabled MAC and after receiving truncate it to the
         * actually received size. In this case, ensure the tot_len member of the
         * pbuf is the sum of the chained pbuf len members.
         */
         memcpy(q->payload, &buffer[len], q->len);
         len += q->len;
      }

#if ETH_PAD_SIZE
      pbuf_header(p, ETH_PAD_SIZE);    /* Reclaim the padding word */
#endif

    }
    else
    {
      XMC_ETH_MAC_ReadFrame(&eth_mac, NULL, 0);
    }
  }
  else
  {
    XMC_ETH_MAC_ReadFrame(&eth_mac, NULL, 0);
  }

  return p;  
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
static void
ethernetif_input(void *arg)
{
  struct pbuf *p = NULL;
  struct eth_hdr *ethhdr;
  struct netif *netif = (struct netif *)arg;

  while(1)
  {
    sys_arch_sem_wait(&eth_rx_semaphore, 0);

    p = low_level_input();

    if (p != NULL)
    {
   	  ethhdr = p->payload;
   	  switch (htons(ethhdr->type))
   	  {
   	    case ETHTYPE_IP:
   	    case ETHTYPE_ARP:
   	      /* full packet send to tcpip_thread to process */
          if (netif->input( p, netif) != ERR_OK)
          {
            pbuf_free(p);
          }

          break;

   	    default:
   	      pbuf_free(p);
   	      break;
   	  }
    }
  }

}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t
ethernetif_init(struct netif *netif)
{
  LWIP_ASSERT("netif != NULL", (netif != NULL));
    
#if LWIP_NETIF_HOSTNAME
  /* Initialize interface hostname */
  netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

  netif->name[0] = IFNAME0;
  netif->name[1] = IFNAME1;

  netif->output = etharp_output;
  netif->linkoutput = low_level_output;

  /* initialize the hardware */
  low_level_init(netif);

  sys_sem_new(&eth_rx_semaphore, 0);
  sys_thread_new("ETH_RX_INPUT", ethernetif_input, netif, 512, osPriorityNormal);

  return ERR_OK;
}

void ETH0_0_IRQHandler(void)
{
  uint32_t status;

  status = XMC_ETH_MAC_GetEventStatus(&eth_mac);

  if (status & XMC_ETH_MAC_EVENT_RECEIVE)
  {
    sys_sem_signal(&eth_rx_semaphore);
  }

  XMC_ETH_MAC_ClearEventStatus(&eth_mac, status);

}
