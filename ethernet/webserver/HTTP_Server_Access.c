/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network:Service
 * Copyright (c) 2004-2015 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HTTP_Server_Access.c
 * Purpose: HTTP Server Access Interface
 * Rev.:    V7.0.0
 *----------------------------------------------------------------------------*/
//! [code_HTTP_Server_Access]
#include "rl_net.h"
 
// \brief Accept or deny a connection from a remote HTTP client.
// \param[in]     addr          structure containing IP address and port of remote HTTP client.
// \return
//              - true        = Connection from the remote client is allowed.
//              - false       = Connection is denied.
// \note If this function is missing, all remote clients are accepted. 
bool netHTTPs_AcceptClient (const NET_ADDR *addr) {
  /* Example
  if (addr->addr_type == NET_ADDR_IP4) {
    // IPv4 client
    if (addr->addr[0] == 192  &&
        addr->addr[1] == 168  &&
        addr->addr[2] == 0    &&
        addr->addr[3] == 1) {
      // Accept connection from client at 192.168.0.1
      return (true);
    }
  }
  else {
    // IPv6 client
    const uint8_t ip6_addr[NET_ADDR_IP6_LEN] = { 
                     0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                     0x1c, 0x30, 0x6c, 0xff, 0xfe, 0xa2, 0x45, 0x5e };
    if (memcmp (addr->addr, ip6_addr, NET_ADDR_IP6_LEN) == 0) {
      // Accept connection from client at [fe80::1c30:6cff:fea2:455e]
      return (true);
    }
  }
  // Deny connection.
  return (false);
  */
  return (true);
}
//! [code_HTTP_Server_Access]
