/**
 * @file descriptors.c
 * @date 2015-10-08
 *
 * @cond
 ***********************************************************************************************************************
 * USBD_VCOM v4.0.8 - The USB virtual COM port driver for XMC4000 family of controllers.
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
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the    
 *   following disclaimer in the documentation and/or other materials provided with the distribution.     
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
 * 2015-04-23:
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


/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include "descriptors.h"

 
 /***********************************************************************************************************************
 * GLOBAL DATA
 **********************************************************************************************************************/

/** Device descriptor structure. This descriptor, located in FLASH memory,
 * describes the overall device characteristics, including the supported USB
 * version, control endpoint size and the number of device configurations.
 * The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
#define PROGMEM
const USB_Descriptor_Device_t PROGMEM device_descriptor =
{
	.Header                 = {
			.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = USBD_VCOM_FS_SPEC,
	.Class                  = CDC_CSCP_CDCClass,
	.SubClass               = CDC_CSCP_NoSpecificSubclass,
	.Protocol               = CDC_CSCP_NoSpecificProtocol,

	.Endpoint0Size          = USBD_VCOM_EP0_SIZE,

	.VendorID               = IFX_USB_VENDOR_ID,
	.ProductID              = USBD_VCOM_PRODUCT_ID,
	.ReleaseNumber          = 0x0001,

	.ManufacturerStrIndex   = USBD_VCOM_MANUF_STRING_INDEX,
	.ProductStrIndex        = USBD_VCOM_PROD_STRING_INDEX,
	.SerialNumStrIndex      = 0,

	.NumberOfConfigurations = 1
};

/** Configuration descriptor structure. This descriptor, located in FLASH
 *  memory, describes the usage of the device in one of its supported
 *  configurations, including information about any device interfaces and
 *  endpoints. The descriptor is read out by the USB host during the enumeration
 *   process when selecting a configuration so that the host may correctly
 *   communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM configuration_descriptor =
{
	.config =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Configuration_Header_t),
					.Type = DTYPE_Configuration},

			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
			.TotalInterfaces        = 2,

			.ConfigurationNumber    = 1,
			.ConfigurationStrIndex  = NO_DESCRIPTOR,

			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED),

			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
		},

	.cdc_cci_interface =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Interface_t),
					.Type = DTYPE_Interface},

			.InterfaceNumber        = 0,
			.AlternateSetting       = 0,

			.TotalEndpoints         = 1,

			.Class                  = CDC_CSCP_CDCClass,
			.SubClass               = CDC_CSCP_ACMSubclass,
			.Protocol               = CDC_CSCP_ATCommandProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},

	.cdc_functional_header =
		{
			.Header                 = {
					.Size = sizeof(USB_CDC_Descriptor_FunctionalHeader_t),
					.Type = DTYPE_CSInterface},
			.Subtype                = CDC_DSUBTYPE_CSInterface_Header,

			.CDCSpecification       = USBD_VCOM_FS_SPEC,
		},

	.cdc_functional_acm =
		{
			.Header                 = {
					.Size = sizeof(USB_CDC_Descriptor_FunctionalACM_t),
					.Type = DTYPE_CSInterface},
			.Subtype                = CDC_DSUBTYPE_CSInterface_ACM,

			.Capabilities           = 0x06,
		},

	.cdc_functional_union =
		{
			.Header                 = {
					.Size = sizeof(USB_CDC_Descriptor_FunctionalUnion_t),
					.Type = DTYPE_CSInterface},
			.Subtype                = CDC_DSUBTYPE_CSInterface_Union,

			.MasterInterfaceNumber  = 0,
			.SlaveInterfaceNumber   = 1,
		},

	.cdc_notification_endpoint =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Endpoint_t),
					.Type = DTYPE_Endpoint},

			.EndpointAddress        = (ENDPOINT_DIR_IN| CDC_NOTIFICATION_EPNUM),
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC
											| ENDPOINT_USAGE_DATA),
			.EndpointSize           = CDC_NOTIFICATION_EPSIZE,
			.PollingIntervalMS      = 0xFF
		},

	.cdc_dci_interface =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Interface_t),
					.Type = DTYPE_Interface},

			.InterfaceNumber        = 1,
			.AlternateSetting       = 0,

			.TotalEndpoints         = 2,

			.Class                  = CDC_CSCP_CDCDataClass,
			.SubClass               = CDC_CSCP_NoDataSubclass,
			.Protocol               = CDC_CSCP_NoDataProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},

	.cdc_data_out_endpoint =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Endpoint_t),
					.Type = DTYPE_Endpoint},

			.EndpointAddress        = (ENDPOINT_DIR_OUT | CDC_RX_EPNUM),
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC |
														ENDPOINT_USAGE_DATA),
			.EndpointSize           = CDC_TXRX_EPSIZE,
			.PollingIntervalMS      = 0x01
		},

	.cdc_data_in_endpoint =
		{
			.Header                 = {
					.Size = sizeof(USB_Descriptor_Endpoint_t),
					.Type = DTYPE_Endpoint},

			.EndpointAddress        = (ENDPOINT_DIR_IN | CDC_TX_EPNUM),
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC |
												ENDPOINT_USAGE_DATA),
			.EndpointSize           = CDC_TXRX_EPSIZE,
			.PollingIntervalMS      = 0x01
		}
};

/** Language descriptor structure. This descriptor, located in FLASH memory, is
 *  returned when the host requests the string descriptor with index 0 (the
 *  first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device
 *  supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM language_string =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

	.UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the
 *  manufacturer's details in human readable  form, and is read out upon request
 *   by the host when the appropriate string ID is requested, listed in the
 *   Device Descriptor.
 */
const USB_Descriptor_String_t PROGMEM manufacturer_string =
{
	.Header                 =
						{.Size = USB_STRING_LEN(8), .Type = DTYPE_String},

	.UnicodeString          = { 'I','n','f','i','n','e','o','n'}
};

/** Product descriptor string. This is a Unicode string containing the product's
 *  details in human readable form, and is read out upon request by the host
 *  when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM product_string =
{
	.Header                 =
						{.Size = USB_STRING_LEN(7), .Type = DTYPE_String},

	.UnicodeString          = {'I','F','X',' ','C','D','C'}
};

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*  This function is called by the library when in device mode, and must be
 *  overridden (see library "USB Descriptors" documentation) by the application
 *   code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on
 *  the control endpoint, this function is called so that the descriptor details
 *   can be passed back and the appropriate descriptor sent back to the USB
 *   host.
 */
uint16_t USBD_VCOM_Event_GetDescriptor(const uint16_t w_value,
                                    const uint16_t w_index,
                                    const void** const descriptor_address)
{
	const uint8_t  descriptor_type   = (w_value >> 8);
	const uint8_t  descriptor_number = (w_value & 0xFF);
	const void* address = NULL;
	uint16_t    size    = NO_DESCRIPTOR;

	switch (descriptor_type)
	{
		case DTYPE_Device:
			address = &device_descriptor;
			size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			address = &configuration_descriptor;
			size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (descriptor_number)
			{
				case 0x00:
					address = &language_string;
					size    = language_string.Header.Size;
					break;
				case 0x01:
					address = &manufacturer_string;
					size    = manufacturer_string.Header.Size;
					break;
				case 0x02:
					address = &product_string;
					size    = product_string.Header.Size;
					break;
			}
			break;
	}

	(void)w_index;
	*descriptor_address = address;
	return size;
}

