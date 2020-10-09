/******************************************************************************
* /******************************************************************************
* Software License Agreement
*
* Copyright (c) 2016, Infineon Technologies AG
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* Neither the name of the copyright holders nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* To improve the quality of the software, users are encouraged to share
* modifications, enhancements or bug fixes with Infineon Technologies AG
* (dave@infineon.com).
*
*****************************************************************************/

/**
 * @file
 * @date 22 March, 2017
 * @version 1.1.0
 *
 * @brief IOT_EXAMPLE_XMC47 example
 * Implementation of an IoT client: A webserver shows the status of 8 LEDs and logs connection / 
 * disconnection event. Upon pressing a button on the IoT client an email will be send to a configurable
 * email address. The XMC4700 /XMC4800 Relax kit plus extension board is required.
 *
 * History <br>
 *
 * Version 1.0.0 Initial <br>
 * Version 1.1.0 Fixed abortion of tcp connection during prolonged startup <br>
 */

 
/****************************************************************
* HEADER FILES
***************************************************************/
#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/****************************************************************
* MACROS AND DEFINES
***************************************************************/
/* Server IP address */
#define SERVER_IP_ADDR0    192U
#define SERVER_IP_ADDR1    168U
#define SERVER_IP_ADDR2    0U
#define SERVER_IP_ADDR3    5U

/* Server HTTP port number */
#define SERVER_HTTP_PORT   80U

/* Server domain name */
#define DOMAIN_NAME "192.168.0.5"

/* Enable DHCP bounding check for client
 * (disabled by default) */
#define DHCP_ENABLED 0U

/* Client ID
 * ATTENTION: Don't forget to set a different MAC address
 * inside ETH_LWIP_0 APP as well.
 * (0 = Device#1; 1 = Device #2) */
#define DEVICE_ID 0U

/****************************************************************
* PROTOTYPES
***************************************************************/
void client_err(void *arg, err_t err);
void client_init(void);
err_t client_connected(void *arg, struct tcp_pcb *pcb, err_t err);
void client_close(struct tcp_pcb *pcb);
err_t client_sent(void *arg, struct tcp_pcb *pcb, u16_t len);

/****************************************************************
* LOCAL DATA
***************************************************************/
/* Array to access LED Bit0 to LED Bit7 */
const DIGITAL_IO_t* LED_X[8]={&LED_0,&LED_1,&LED_2,&LED_3,&LED_4,&LED_5,&LED_6,&LED_7};

/* Pointer to lwIP network interface structure */
extern struct netif xnetif;

/* TCP protocol control block */
struct tcp_pcb *pcb_send, *pcb_open;

/* Connection status */
uint8_t connection_ready=0,pcb_valid=0;

/* Counter reflecting status of device for this example */
uint8_t counter=0;

/****************************************************************
* API IMPLEMENTATION
***************************************************************/
/**
 * @client_err
 *
 * Error callback, called by lwip. Invalidates global protocol control block pointer in case of connection resets.
 *
 * @input  : none
 *
 * @output : none
 *
 * @return : none
 *
 * */
void client_err(void *arg, err_t err)
{
  if (err == ERR_RST)
    pcb_valid=0;
  return;
}

/**
 * @client_init
 *
 * Initializes the connection to the server.
 * Registers callback client_connected, which is called when connecting trials are done
 * Registers callback client_error, which is called when there is an error on the connection
 *
 * @input  : none
 *
 * @output : none
 *
 * @return : none
 *
 * */
void client_init(void)
{
  struct ip_addr dest;
  IP4_ADDR(&dest, SERVER_IP_ADDR0, SERVER_IP_ADDR1, SERVER_IP_ADDR2, SERVER_IP_ADDR3);

  if (pcb_open!=0)
    tcp_abort(pcb_open);
  pcb_open = tcp_new();
  tcp_err(pcb_open, client_err);
  tcp_bind(pcb_open, IP_ADDR_ANY, SERVER_HTTP_PORT); //server port for incoming connection
  tcp_arg(pcb_open, NULL);
  tcp_connect(pcb_open, &dest, SERVER_HTTP_PORT, client_connected); //server port for incoming connection
}

/**
 * @client_connected
 *
 * Confirmation callback, called by lwip. Store global protocol control block pointer in case of successfull connection, otherwise
 * invalidate
 *
 * @input  : none
 *
 * @output : none
 *
 * @return : err_t error type
 *
 * */
err_t client_connected(void *arg, struct tcp_pcb *pcb, err_t err)
{
  /* Connection succeded ?*/
  if (err==ERR_OK)
  {
    /* Store protocol control block for next send */
    connection_ready=1;
    pcb_valid=1;
    pcb_send=pcb;
  }
  else
  {
    /* Close/Inavlidate protocol control block */
    client_close(pcb);
    pcb_valid=0;
  }
  return err;
}

/**
 * @client_close
 *
 * Close connection
 *
 * @input  : pcb - pointer to protocol control block
 *
 * @output : none
 *
 * @return : none
 *
 * */
void client_close(struct tcp_pcb *pcb)
{
  tcp_arg(pcb, NULL);
  tcp_sent(pcb, NULL);
  tcp_abort(pcb);
}

/**
 * @client_close
 *
 * Confirmation callback, called by lwip when data was sent.
 * Invalidate protocol control block and re-initialize connection for next transfer.
 *
 * @input  : pcb - protocl control block
 *           len - length
 *
 * @output : none
 *
 * @return : err_t error type
 *
 * */
err_t client_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
  /* Sending succeeded; Close protocol control block */
  client_close(pcb);
  pcb_valid=0;
  /* Prepare already connection for next transfer */
  client_init();
  return ERR_OK;
}

/**
 * @client_close
 *
 * Send http header and set the LEDs on the extension board
 *
 * @input  : button1        - set to 1 if button1 was released; otherwise 0
 *           button2        - set to 1 if button2 was released; otherwise 0
 *           counter_state  - 8 bit value representing the state of the client
 *
 * @output : none
 *
 * @return : none
 *
 * */
void send_data(uint8_t button1, uint8_t button2, uint8_t counter_state)
{
  static uint32_t connect_WD=0;
  char http_header[1024];
  sprintf(http_header,"GET /pushData.php?"
                      "device=%i&value=%i&button1=%i&button2=%i HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: keep-alive\r\n"
                      "Pragma: no-cache\r\n"
                      "Cache-Control: no-cache\r\n"
                      "Accept: text/html,application/xhtml+xml,"
                      "application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
                      "Accept-Encoding: gzip, deflate, sdch\r\n\r\n"
                      ,DEVICE_ID, counter_state, button1, button2, DOMAIN_NAME);

  if ((connection_ready==1)&&(pcb_send!=0))
  {
    connection_ready=0;
    connect_WD=0;
    tcp_sent(pcb_send, client_sent);
    tcp_write(pcb_send, (char*)&http_header, sizeof(http_header), 0);
    tcp_output(pcb_send);
    for (uint8_t bit=0; bit<8; bit++)
    {
      if (counter_state&(1<<bit))
        DIGITAL_IO_SetOutputLow(LED_X[bit]);
      else
        DIGITAL_IO_SetOutputHigh(LED_X[bit]);
    }
  }
  else
  {
    /* Connection watchdog triggered
     * --> reset Protocol Control Block
     */
    connect_WD++;
    if (connect_WD==10)
    {
      client_close(pcb_send);
      pcb_valid=0;
    }
  }
}

/**
 * @tim_sys_check_timeouts_wrap
 *
 * Timer callback to administrate the timeouts of lwip stack.
 *
 * @input  : none
 *
 * @output : none
 *
 * @return : none
 *
 * */
void tim_sys_check_timeouts_wrap(void *args)
{
  sys_check_timeouts();
}

/**
 * @tim_counter_increment
 *
 * Timer callback to increment state counter
 *
 * @input  : none
 *
 * @output : none
 *
 * @return : none
 *
 * */
void tim_counter_increment(void *args)
{
  counter++;
}

/**
 * @check_buttons_released
 *
 * Checks if button have been released and store state.
 * Reset state if requested
 *
 * @input  : reset - reset button released state
 *
 * @output : *ptr_button1 - return if button1 has been released since last reset
 *           *ptr_button2 - return if button2 has been released since last reset
 *
 * @return : none
 *
 * */
void check_buttons_released(uint8_t *ptr_button1, uint8_t *ptr_button2, uint8_t reset)
{
  static uint8_t button1_state_up=0,button2_state_up=0,button1=0,button2=0;
  /* Check if button1 was released and store inside button1 variable */
  if (DIGITAL_IO_GetInput(&BUTTON_1)==0)
  {
    button1_state_up=1;
  }
  else
  {
    if (button1_state_up==1)
    {
      button1_state_up=0;
      button1=1;
    }
  }
  /* Check if button2 was released and store inside button2 variable */
  if (DIGITAL_IO_GetInput(&BUTTON_2)==0)
  {
    button2_state_up=1;
  }
  else
  {
    if (button2_state_up==1)
    {
      button2_state_up=0;
      button2=1;
    }
  }
  *ptr_button1=button1;
  *ptr_button2=button2;
  /* Reset last transition from pushed -> released */
  if (reset==1)
  {
	  button1=0;
	  button2=0;
  }

}
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
int main(void)
{
  DAVE_STATUS_t status;
  uint32_t timer_systimer_lwip, timer_systimer_counter;
  uint8_t button1=0,button2=0;
  uint8_t counter_old=0;

  status = DAVE_Init(); /* Initialization of DAVE APPs  */
  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code.
     * The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");
    while(1U)
    {
    }
  }

  /* Initialize and start lwip system timer */
  timer_systimer_lwip = SYSTIMER_CreateTimer(100000,
                                             SYSTIMER_MODE_PERIODIC ,
											 tim_sys_check_timeouts_wrap,0);
  SYSTIMER_StartTimer(timer_systimer_lwip);

  /* Initialize and start client state counter timer */
  timer_systimer_counter = SYSTIMER_CreateTimer (500000,
                                                 SYSTIMER_MODE_PERIODIC ,
                                                 tim_counter_increment,0);
  SYSTIMER_StartTimer(timer_systimer_counter);

  while(1)
  {
    /* Check if client state counter was incremented.
     * If yes, send next header (incl. state counter, button1/2 state */
    if (counter!=counter_old)
    {
      /* Connection already/still active? */
      if ((connection_ready==0)&&(pcb_valid==0))
      {
#if DHCP_ENABLED==1
       /* IP address via DHCP already valid? */
       if ((xnetif.dhcp->state) == DHCP_BOUND)
#endif
         /* Re-Initialize TCP/IP connection */
         client_init();
      }
      else
      {
        check_buttons_released(&button1, &button2, 1 /*reset released state*/);
        send_data(button1, button2, counter);
      }
      counter_old=counter;
    }
    check_buttons_released(&button1, &button2, 0 /*reset released state*/);
  }
}
