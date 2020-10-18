/**
 * @file descriptors.h
 * @date 2015-10-08
 *
 * @cond
 ***********************************************************************************************************************
 * USBD_VCOM v4.0.8 - The USB virtual COM port driver for XMC4000 family of controllers
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.                        
 *                                             
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the           
 * following conditions are met:   
 *                                                                              
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following   
 *   disclaimer.                        
 * 
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following   
 *   disclaimer in the documentation and/or other materials provided with the distribution.     
 *                         
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 *   products derived from this software without specific prior written permission. 
 *                                             
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,  
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE   
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,  
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR        
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,      
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE   
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
 *                                                                              
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes       
 * with Infineon Technologies AG (dave@infineon.com).         
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version.
 *           
 * 2015-03-18:
 *     - Updated the review comments from AEs.    
 * 2015-06-20:
 *     - Updated the file header.
 *
 * @endcond 
 *
 */
/*
  Copyright 2014  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


#ifndef DESCRIPTORS_H
#define DESCRIPTORS_H
/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
	extern "C" {
#endif

/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include "../usbd_vcom.h"

/**********************************************************************************************************************
 * MACROS                                                                                                            
 **********************************************************************************************************************/
	/**
	 * @ingroup USBD_VCOM_constants
	 * @{
	 */
	/* Macros: */
		/** Endpoint number of the CDC device-to-host notification IN
		 * endpoint. */
		#define CDC_NOTIFICATION_EPNUM         1U

		/** Endpoint number of the CDC device-to-host data IN endpoint. */
		#define CDC_TX_EPNUM                   2U

		/** Endpoint number of the CDC host-to-device data OUT endpoint. */
		#define CDC_RX_EPNUM                   3U

		/** Size in bytes of the CDC device-to-host notification IN endpoint. */
		#define CDC_NOTIFICATION_EPSIZE        8U

		/** Size in bytes of the CDC data IN and OUT endpoints. */
		#define CDC_TXRX_EPSIZE                64U

		/*IN endpoint mask to get the direction of EP*/
		#define CDC_IN_EP_MASK (1U << 7U)

		/*OUT endpoint mask to get the direction of EP*/
		#define CDC_OUT_EP_MASK               (0U)
	/**
	 * @}
	 */

/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/
	/**
	 * @ingroup USBD_VCOM_datastructures
	 * @{
	 */
	/* Type Defines: */
		/** Type define for the device configuration descriptor structure. This
		 * must be defined in the application code, as the configuration
		 * descriptor contains several sub-descriptors which vary between
		 * devices, and which describe the device's usage to the host.
		 */
		typedef struct
		{
			USB_Descriptor_Configuration_Header_t    config;
			USB_Descriptor_Interface_t               cdc_cci_interface;
			USB_CDC_Descriptor_FunctionalHeader_t    cdc_functional_header;
			USB_CDC_Descriptor_FunctionalACM_t       cdc_functional_acm;
			USB_CDC_Descriptor_FunctionalUnion_t     cdc_functional_union;
			USB_Descriptor_Endpoint_t                cdc_notification_endpoint;
			USB_Descriptor_Interface_t               cdc_dci_interface;
			USB_Descriptor_Endpoint_t                cdc_data_out_endpoint;
			USB_Descriptor_Endpoint_t                cdc_data_in_endpoint;
		} USB_Descriptor_Configuration_t;
		/**
		 * @}
		 */

/* Disable C linkage for C++ Compilers: */
	#if defined(__cplusplus)
		}
	#endif
#endif

