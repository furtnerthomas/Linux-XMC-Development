/**
 * @file cdc_class_common.h
 * @date 2015-06-20 
 *
 * @cond
 ***********************************************************************************************************************
 * The USB virtual COM port driver for XMC4000 family of controllers
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

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


#ifndef _CDC_CLASS_COMMON_H_
#define _CDC_CLASS_COMMON_H_

 /***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
		#include "../../../USBD/usb/core/std_descriptors.h" /*FIX*/

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif
    
 /**********************************************************************************************************************
  * MACROS                                                                                                            
 **********************************************************************************************************************/
/**
 * @ingroup USBD_VCOM_constants
 * @{
 */

		/* Macros: */

		/** Mask for the DTR handshake line for use with the
		 * \ref CDC_REQ_SetControlLineState class-specific request
		 *  from the host, to indicate that the DTR line state should be high.
		 */
		#define CDC_CONTROL_LINE_OUT_DTR         (1 << 0U)

		/** Mask for the RTS handshake line for use with the
		 * \ref CDC_REQ_SetControlLineState class-specific request
		 *  from the host, to indicate that the RTS line state should be high.
		 */
		#define CDC_CONTROL_LINE_OUT_RTS         (1 << 1U)

		/** Mask for the DCD handshake line for use with the
		 * \ref CDC_NOTIF_SerialState class-specific notification
		 *  from the device to the host, to indicate that the DCD line state is
		 *  currently high.
		 */
		#define CDC_CONTROL_LINE_IN_DCD          (1 << 0U)

		/** Mask for the DSR handshake line for use with the
		 * \ref CDC_NOTIF_SerialState class-specific notification
		 *  from the device to the host, to indicate that the DSR line state is
		 *  currently high.
		 */
		#define CDC_CONTROL_LINE_IN_DSR          (1 << 1U)

		/** Mask for the BREAK handshake line for use with the
		 * \ref CDC_NOTIF_SerialState class-specific notification
		 *  from the device to the host, to indicate that the BREAK line state
		 *  is currently high.
		 */
		#define CDC_CONTROL_LINE_IN_BREAK        (1 << 2U)

		/** Mask for the RING handshake line for use with the
		 * \ref CDC_NOTIF_SerialState class-specific notification
		 *  from the device to the host, to indicate that the RING line state is
		 *   currently high.
		 */
		#define CDC_CONTROL_LINE_IN_RING         (1 << 3U)

		/** Mask for use with the \ref CDC_NOTIF_SerialState class-specific
		 * notification from the device to the host,
		 *  to indicate that a framing error has occurred on the virtual serial
		 *  port.
		 */
		#define CDC_CONTROL_LINE_IN_FRAMEERROR   (1 << 4U)

		/** Mask for use with the \ref CDC_NOTIF_SerialState class-specific
		 * notification from the device to the host,
		 *  to indicate that a parity error has occurred on the virtual serial
		 *  port.
		 */
		#define CDC_CONTROL_LINE_IN_PARITYERROR  (1 << 5U)

		/** Mask for use with the \ref CDC_NOTIF_SerialState class-specific
		 * notification from the device to the host,
		 *  to indicate that a data overrun error has occurred on the virtual
		 *  serial port.
		 */
		#define CDC_CONTROL_LINE_IN_OVERRUNERROR (1 << 6U)

		/** Macro to define a CDC class-specific functional descriptor. CDC
		 * functional descriptors have a
		 *  uniform structure but variable sized data payloads, thus cannot be
		 *  represented accurately by
		 *  a single typedef struct. A macro is used instead so that functional
		 *  descriptors can be created
		 *  easily by specifying the size of the payload. This allows
		 *  \c sizeof() to work correctly.
		 *
		 *  \param[in] DataSize  Size in bytes of the CDC functional
		 *  descriptor's data payload.
		 */
		#define CDC_FUNCTIONAL_DESCRIPTOR(DataSize)        \
		     struct                                        \
		     {                                             \
		          USB_Descriptor_Header_t Header;          \
			      uint8_t                 SubType;         \
		          uint8_t                 Data[DataSize];  \
		     }
/**
 * @}
 */

/**********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/

/**
 * @ingroup USBD_VCOM_enumerations
 * @{
 */

		/** Enum for possible Class, Subclass and Protocol values of device and
		 *  interface descriptors relating to the CDC device class.
		 */
		enum CDC_Descriptor_ClassSubclassProtocol_t
		{
			/** Descriptor Class value indicating that the device or interface belongs to the CDC class.*/
			CDC_CSCP_CDCClass               = 0x02,

			/** Descriptor Subclass value indicating that the device or interface belongs to no
			 * specific subclass of the CDC class.*/
			CDC_CSCP_NoSpecificSubclass     = 0x00,

			/** Descriptor Subclass value indicating that the device or interface belongs to the
			 * Abstract Control Model CDC subclass.*/
			CDC_CSCP_ACMSubclass            = 0x02,

			/** Descriptor Protocol value indicating that the device or interface belongs to the
			 * AT Command protocol of the CDC class.*/
			CDC_CSCP_ATCommandProtocol      = 0x01,

			/** Descriptor Protocol value indicating that the device or interface belongs to no
			 * specific protocol of the CDC class.*/
			CDC_CSCP_NoSpecificProtocol     = 0x00,

			/** Descriptor Protocol value indicating that the device or interface belongs to a
			 * vendor-specific protocol of the CDC class.*/
			CDC_CSCP_VendorSpecificProtocol = 0xFF,

			/** Descriptor Class value indicating that the device or interface belongs to the CDC Data class.*/
			CDC_CSCP_CDCDataClass           = 0x0A,

			/** Descriptor Subclass value indicating that the device or interface belongs to no
			 * specific subclass of the CDC data class.*/
			CDC_CSCP_NoDataSubclass         = 0x00,

			/** Descriptor Protocol value indicating that the device or interface belongs to no
			 * specific protocol of the CDC data class.*/
			CDC_CSCP_NoDataProtocol         = 0x00,
		};

		/** Enum for the CDC class specific control requests that can be issued by the USB bus host. */
		enum CDC_ClassRequests_t
		{
			/** CDC class-specific request to send an encapsulated command to the device. */
			CDC_REQ_SendEncapsulatedCommand = 0x00,

			/** CDC class-specific request to retrieve an encapsulated command response from the device. */
			CDC_REQ_GetEncapsulatedResponse = 0x01,

			/** CDC class-specific request to set the current virtual serial port configuration settings. */
			CDC_REQ_SetLineEncoding         = 0x20,

			/** CDC class-specific request to get the current virtual serial port configuration settings. */
			CDC_REQ_GetLineEncoding         = 0x21,

			/** CDC class-specific request to set the current virtual serial port handshake line states. */
			CDC_REQ_SetControlLineState     = 0x22,

			/** CDC class-specific request to send a break to the receiver via the carrier channel. */
			CDC_REQ_SendBreak               = 0x23,
		};

		/** Enum for the CDC class specific notification requests that can be
		 * issued by a CDC device to a host. */
		enum CDC_ClassNotifications_t
		{
			/** Notification type constant for a change in the virtual serial port handshake line states,
			 * for use with a USB_Request_Header_t notification structure when sent to the host via the
			 * CDC notification endpoint.*/
			CDC_NOTIF_SerialState               = 0x20,
		};

		/** Enum for the CDC class specific interface descriptor subtypes. */
		enum CDC_DescriptorSubtypes_t
		{
			/** CDC class-specific Header functional descriptor. */
			CDC_DSUBTYPE_CSInterface_Header           = 0x00,

			/** CDC class-specific Call Management functional descriptor. */
			CDC_DSUBTYPE_CSInterface_CallManagement   = 0x01,

			/** CDC class-specific Abstract Control Model functional descriptor. */
			CDC_DSUBTYPE_CSInterface_ACM              = 0x02,

			/** CDC class-specific Direct Line functional descriptor. */
			CDC_DSUBTYPE_CSInterface_DirectLine       = 0x03,

			/** CDC class-specific Telephone Ringer functional descriptor. */
			CDC_DSUBTYPE_CSInterface_TelephoneRinger  = 0x04,

			/** CDC class-specific Telephone Call functional descriptor. */
			CDC_DSUBTYPE_CSInterface_TelephoneCall    = 0x05,

			/** CDC class-specific Union functional descriptor. */
			CDC_DSUBTYPE_CSInterface_Union            = 0x06,

			/** CDC class-specific Country Selection functional descriptor. */
			CDC_DSUBTYPE_CSInterface_CountrySelection = 0x07,

			/** CDC class-specific Telephone Operation Modes functional descriptor. */
			CDC_DSUBTYPE_CSInterface_TelephoneOpModes = 0x08,

			/** CDC class-specific USB Terminal functional descriptor. */
			CDC_DSUBTYPE_CSInterface_USBTerminal      = 0x09,

			/** CDC class-specific Network Channel functional descriptor. */
			CDC_DSUBTYPE_CSInterface_NetworkChannel   = 0x0A,

			/** CDC class-specific Protocol Unit functional descriptor. */
			CDC_DSUBTYPE_CSInterface_ProtocolUnit     = 0x0B,

			/** CDC class-specific Extension Unit functional descriptor. */
			CDC_DSUBTYPE_CSInterface_ExtensionUnit    = 0x0C,

			/** CDC class-specific Multi-Channel Management functional descriptor. */
			CDC_DSUBTYPE_CSInterface_MultiChannel     = 0x0D,

			/** CDC class-specific Common ISDN API functional descriptor. */
			CDC_DSUBTYPE_CSInterface_CAPI             = 0x0E,

			/** CDC class-specific Ethernet functional descriptor. */
			CDC_DSUBTYPE_CSInterface_Ethernet         = 0x0F,

			/** CDC class-specific Asynchronous Transfer Mode functional descriptor. */
			CDC_DSUBTYPE_CSInterface_ATM              = 0x10,
		};

		/** Enum for the possible line encoding formats of a virtual
		 * serial port. */
		enum CDC_LineEncodingFormats_t
		{
			CDC_LINEENCODING_OneStopBit          = 0, /**< Each frame contains one stop bit. */
			CDC_LINEENCODING_OneAndAHalfStopBits = 1, /**< Each frame contains one and a half stop bits. */
			CDC_LINEENCODING_TwoStopBits         = 2, /**< Each frame contains two stop bits. */
		};

		/** Enum for the possible line encoding parity settings of a virtual
		 * serial port. */
		enum CDC_LineEncodingParity_t
		{
			CDC_PARITY_None  = 0, /**< No parity bit mode on each frame. */
			CDC_PARITY_Odd   = 1, /**< Odd parity bit mode on each frame. */
			CDC_PARITY_Even  = 2, /**< Even parity bit mode on each frame. */
			CDC_PARITY_Mark  = 3, /**< Mark parity bit mode on each frame. */
			CDC_PARITY_Space = 4, /**< Space parity bit mode on each frame. */
		};
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

		/** CDC class-specific Functional Header Descriptor
		 * (LUFA naming conventions).
		 *
		 *  Type define for a CDC class-specific functional header descriptor.
		 *  This indicates to the host that the device
		 *  contains one or more CDC functional data descriptors, which give the
		 *   CDC interface's capabilities and configuration.
		 *  See the CDC class specification for more details.
		 *
		 *  Regardless of CPU architecture, these values should be stored as
		 *  little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_Descriptor_FunctionalHeader
		{
			/** Regular descriptor header containing the descriptor's type and length. */
			USB_Descriptor_Header_t Header;

			/** Sub type value used to distinguish between CDC class-specific descriptors.
			 * Must be CDC_DSUBTYPE_CSInterface_Header.*/
			uint8_t                 Subtype;

			/** Version number of the CDC specification implemented by the device,
			 * encoded in BCD format.*/
			uint16_t                CDCSpecification;
		}ATTR_PACKED;
		typedef struct USB_CDC_Descriptor_FunctionalHeader USB_CDC_Descriptor_FunctionalHeader_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC class-specific Functional Header Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for a CDC class-specific functional header descriptor. This indicates to the host that
		 *  the device contains one or more CDC functional data descriptors, which give the CDC interface's
		 *  capabilities and configuration. See the CDC class specification for more details.
		 *
		 * Regardless of CPU architecture, these values should be stored as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_StdDescriptor_FunctionalHeader
		{
			/** Size of the descriptor, in bytes. */
			uint8_t  bFunctionLength;

			/** Type of the descriptor, either a value in USB_DescriptorTypes_t or a value given by the
			 * specific class.*/
			uint8_t  bDescriptorType;

			/** Sub type value used to distinguish between CDC class-specific descriptors.
			 * Must be CDC_DSUBTYPE_CSInterface_Header.*/
			uint8_t  bDescriptorSubType;

			/* Version number of the CDC specification implemented by the device.
			Encoded in BCD format.*/
			uint16_t bcdCDC;
		}ATTR_PACKED;
		typedef struct USB_CDC_StdDescriptor_FunctionalHeader USB_CDC_StdDescriptor_FunctionalHeader_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC class-specific Functional ACM Descriptor (LUFA naming conventions).
		 *
		 *  Type define for a CDC class-specific functional ACM descriptor. This indicates to the host that
		 *  the CDC interface supports the CDC ACM subclass of the CDC specification. See the CDC class
		 *  specification for more details.
		 *
		 *  \see \ref USB_CDC_StdDescriptor_FunctionalACM_t for the version of this type with standard element names.
		 *
		 *  \note Regardless of CPU architecture, these values should be stored as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_Descriptor_FunctionalACM
		{
			/**< Regular descriptor header containing the descriptor's type and length. */
			USB_Descriptor_Header_t Header;

			/**< Sub type value used to distinguish between CDC class-specific descriptors.
			 * Must be \ref CDC_DSUBTYPE_CSInterface_ACM.*/
			uint8_t                 Subtype;

			/**< Capabilities of the ACM interface, given as a bit mask. For most devices, this should
			 * be set to a fixed value of 0x06 - for other capabilities, refer to the CDC ACM specification.*/
			uint8_t                 Capabilities;
		}ATTR_PACKED;
		typedef struct USB_CDC_Descriptor_FunctionalACM USB_CDC_Descriptor_FunctionalACM_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC class-specific Functional ACM Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for a CDC class-specific functional ACM descriptor. This indicates to the host that the
		 *  CDC interface supports the CDC ACM subclass of the CDC specification. See the CDC class specification
		 *  for more details.
		 *
		 *  \see \ref USB_CDC_Descriptor_FunctionalACM_t for the version of this type with non-standard LUFA specific
		 *   element names.
		 *
		 *  \note Regardless of CPU architecture, these values should be stored as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_StdDescriptor_FunctionalACM
		{
			uint8_t bFunctionLength; /**< Size of the descriptor, in bytes. */
			uint8_t bDescriptorType; /**< Type of the descriptor, either a value in USB_DescriptorTypes_t or a value
			                          *   given by the specific class.
			                          */
			uint8_t bDescriptorSubType; /**< Sub type value used to distinguish between CDC class-specific descriptors,
			                             *   must be \ref CDC_DSUBTYPE_CSInterface_ACM.
			                             */
			uint8_t bmCapabilities; /**< Capabilities of the ACM interface, given as a bit mask. For most devices,
			                         *   this should be set to a fixed value of 0x06 - for other capabilities, refer
			                         *   to the CDC ACM specification.
			                         */
		}ATTR_PACKED;
		typedef struct USB_CDC_StdDescriptor_FunctionalACM USB_CDC_StdDescriptor_FunctionalACM_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC class-specific Functional Union Descriptor
		 * (LUFA naming conventions).
		 *
		 *  Type define for a CDC class-specific functional Union descriptor.
		 *  This indicates to the host that specific
		 *  CDC control and data interfaces are related. See the CDC class
		 *  specification for more details.
		 *
		 *  \see \ref USB_CDC_StdDescriptor_FunctionalUnion_t for the version of
		 *   this type with standard element names.
		 *
		 *  \note Regardless of CPU architecture, these values should be stored
		 *  as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_Descriptor_FunctionalUnion
		{
			/**< Regular descriptor header containing the descriptor's type and length. */
			USB_Descriptor_Header_t Header;

			/**< Sub type value used to distinguish between CDC class-specific descriptors.
			 * Must be \ref CDC_DSUBTYPE_CSInterface_Union. */
			uint8_t                 Subtype;

			/**< Interface number of the CDC Control interface. */
			uint8_t                 MasterInterfaceNumber;

			/**< Interface number of the CDC Data interface. */
			uint8_t                 SlaveInterfaceNumber;
		}ATTR_PACKED;
		typedef struct USB_CDC_Descriptor_FunctionalUnion USB_CDC_Descriptor_FunctionalUnion_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC class-specific Functional Union Descriptor
		 * (USB-IF naming conventions).
		 *
		 *  Type define for a CDC class-specific functional Union descriptor.
		 *  This indicates to the host that specific
		 *  CDC control and data interfaces are related. See the CDC class
		 *  specification for more details.
		 *
		 *  \see \ref USB_CDC_Descriptor_FunctionalUnion_t for the version of
		 *  this type with non-standard LUFA specific
		 *       element names.
		 *
		 *  \note Regardless of CPU architecture, these values should be stored
		 *  as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED USB_CDC_StdDescriptor_FunctionalUnion
		{
			uint8_t bFunctionLength; /**< Size of the descriptor, in bytes. */
			uint8_t bDescriptorType; /**< Type of the descriptor, either a value in USB_DescriptorTypes_t or a value
			                          *   given by the specific class.
			                          */
			uint8_t bDescriptorSubType; /**< Sub type value used to distinguish between CDC class-specific descriptors,
			                             *   must be \ref CDC_DSUBTYPE_CSInterface_Union.
			                             */
			uint8_t bMasterInterface; /**< Interface number of the CDC Control interface. */
			uint8_t bSlaveInterface0; /**< Interface number of the CDC Data interface. */
		}ATTR_PACKED;
		typedef struct USB_CDC_StdDescriptor_FunctionalUnion USB_CDC_StdDescriptor_FunctionalUnion_t;
/**
 * @}
 */

/**
 * @ingroup USBD_VCOM_datastructures
 * @{
 */
		/** CDC Virtual Serial Port Line Encoding Settings Structure.
		 *
		 *  Type define for a CDC Line Encoding structure, used to hold the
		 *  various encoding parameters for a virtual
		 *  serial port.
		 *
		 *  \note Regardless of CPU architecture, these values should be stored
		 *  as little endian.
		 */
		IAR_ATTR_PACKED struct TASKING_ATTR_PACKED CDC_LineEncoding
		{
			uint32_t BaudRateBPS; /**< Baud rate of the virtual serial port, in bits per second. */
			uint8_t  CharFormat; /**< Character format of the virtual serial port, a value from the
								  *   \ref CDC_LineEncodingFormats_t enum.
								  */
			uint8_t  ParityType; /**< Parity setting of the virtual serial port, a value from the
								  *   \ref CDC_LineEncodingParity_t enum.
								  */
			uint8_t  DataBits; /**< Bits of data per character of the virtual serial port. */
		}ATTR_PACKED;
		typedef struct CDC_LineEncoding CDC_LineEncoding_t;

/**
 * @}
 */

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif


