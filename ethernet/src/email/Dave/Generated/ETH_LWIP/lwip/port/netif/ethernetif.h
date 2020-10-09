#ifndef __ETHERNETIF_H__
#define __ETHERNETIF_H__


#include "../../include/lwip/err.h"
#include "../../include/lwip/netif.h"

err_t ethernetif_init(struct netif *netif);

#endif 
