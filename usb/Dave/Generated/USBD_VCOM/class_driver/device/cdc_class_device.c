/**
 * @file cdc_class_device.c
 * @date 2015-06-20 
 *
 * @cond
 ***********************************************************************************************************************
 * The USB virtual COM port driver for XMC4000 family of controllers.
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


#define  __INCLUDE_FROM_USB_DRIVER

/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include  "../../../USBD/usb/core/usb_mode.h" /*IFX*/

#if defined(USB_CAN_BE_DEVICE)

#define  __INCLUDE_FROM_CDC_DRIVER
#define  __INCLUDE_FROM_CDC_DEVICE_C
#include "cdc_class_device.h"
#include "../../usbd_vcom.h"

extern USB_CDCClass_event_CB_t cdc_class_events;

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/
void CDC_Device_ProcessControlRequest(
					USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	if ((Endpoint_IsSETUPReceived() != 0) && (USB_ControlRequest.wIndex ==
			CDCInterfaceInfo->Config.ControlInterfaceNumber))
	{

		switch (USB_ControlRequest.bRequest)
		{
			case CDC_REQ_GetLineEncoding:
				if ((REQDIR_DEVICETOHOST | REQTYPE_CLASS | REQREC_INTERFACE) == USB_ControlRequest.bmRequestType)
				{
					Endpoint_ClearSETUP();

					while (!(Endpoint_IsINReady()));

					Endpoint_Write_32_LE(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS);
					Endpoint_Write_8(CDCInterfaceInfo->State.LineEncoding.CharFormat);
					Endpoint_Write_8(CDCInterfaceInfo->State.LineEncoding.ParityType);
					Endpoint_Write_8(CDCInterfaceInfo->State.LineEncoding.DataBits);

					Endpoint_ClearIN();
					Endpoint_ClearStatusStage();
				}

				break;
			case CDC_REQ_SetLineEncoding:
				if ((REQDIR_HOSTTODEVICE |REQTYPE_CLASS | REQREC_INTERFACE) == USB_ControlRequest.bmRequestType)
				{
					Endpoint_ClearSETUP();

					while (!(Endpoint_IsOUTReceived()))
					{
						if (USB_DeviceState == DEVICE_STATE_Unattached)
						  return;
					}

					CDCInterfaceInfo->State.LineEncoding.BaudRateBPS = Endpoint_Read_32_LE();
					CDCInterfaceInfo->State.LineEncoding.CharFormat  = Endpoint_Read_8();
					CDCInterfaceInfo->State.LineEncoding.ParityType  = Endpoint_Read_8();
					CDCInterfaceInfo->State.LineEncoding.DataBits    = Endpoint_Read_8();

					//Endpoint_ClearOUT();
					Endpoint_ClearStatusStage();

					if(0 != cdc_class_events.LineEncodingChanged)
					{
						cdc_class_events.LineEncodingChanged(CDCInterfaceInfo);
					}

				}

				break;
			case CDC_REQ_SetControlLineState:
				if ((REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE) == USB_ControlRequest.bmRequestType)
				{
					Endpoint_ClearSETUP();
					Endpoint_ClearStatusStage();

					CDCInterfaceInfo->State.ControlLineStates.HostToDevice = USB_ControlRequest.wValue;

					if(0 != cdc_class_events.ControLineStateChanged)
					{
						cdc_class_events.ControLineStateChanged(CDCInterfaceInfo);
					}

				}

				break;
			case CDC_REQ_SendBreak:
				if ((REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE) == USB_ControlRequest.bmRequestType)
				{
					Endpoint_ClearSETUP();
					Endpoint_ClearStatusStage();

					if(0 != cdc_class_events.Device_BreakSent)
					{
						cdc_class_events.Device_BreakSent(CDCInterfaceInfo,	(uint8_t)USB_ControlRequest.wValue);
					}

				}

				break;
		}
	}
}




bool CDC_Device_ConfigureEndpoints(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	bool status = true;
	memset(&CDCInterfaceInfo->State, 0x00, sizeof(CDCInterfaceInfo->State));

	CDCInterfaceInfo->Config.DataINEndpoint.Type       = EP_TYPE_BULK;
	CDCInterfaceInfo->Config.DataOUTEndpoint.Type      = EP_TYPE_BULK;
	CDCInterfaceInfo->Config.NotificationEndpoint.Type = EP_TYPE_INTERRUPT;

	if (!(Endpoint_ConfigureEndpointTable(&CDCInterfaceInfo->Config.DataINEndpoint, 1)))
	{
		status = false;
	}

	if (!(Endpoint_ConfigureEndpointTable(
							&CDCInterfaceInfo->Config.DataOUTEndpoint, 1)))
	{
		status = false;
	}

	if (!(Endpoint_ConfigureEndpointTable(
						&CDCInterfaceInfo->Config.NotificationEndpoint, 1)))
	{
		status = false;
	}

	return status;
}

void CDC_Device_USBTask(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{
		#if !defined(NO_CLASS_DRIVER_AUTOFLUSH)
		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataINEndpoint.Address);

		if (Endpoint_IsINReady())
		{
		  CDC_Device_Flush(CDCInterfaceInfo);
		}
		#endif
	}
}

uint8_t CDC_Device_SendString(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo, const char* const String)
{
	uint8_t status = 0;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{

		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataINEndpoint.Address);
		status = Endpoint_Write_Stream_LE(String, strlen(String), NULL);
	}
	else
	{
		status = ENDPOINT_RWSTREAM_DeviceDisconnected;
	}

	return status;
}

uint8_t CDC_Device_SendData(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo,
                            const void* const Buffer,
                            const uint16_t Length)
{
	uint8_t status = 0;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{

		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataINEndpoint.Address);
		status = Endpoint_Write_Stream_LE(Buffer, Length, NULL);
	}
	else
	{
		status = ENDPOINT_RWSTREAM_DeviceDisconnected;
	}
	return status;
}

uint8_t CDC_Device_SendByte(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo,
                            const uint8_t Data)
{
	uint8_t status = 0;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{

		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataINEndpoint.Address);

		if (Endpoint_IsReadWriteAllowed())
		{
			Endpoint_Write_8(Data);
			status = ENDPOINT_READYWAIT_NoError;
		}
		else
		{
			Endpoint_ClearIN();
			status = Endpoint_WaitUntilReady();
		}
	}
	else
	{
		status = ENDPOINT_RWSTREAM_DeviceDisconnected;
	}

	return status;

}

uint8_t CDC_Device_Flush(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	uint8_t status = 0;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{
		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataINEndpoint.Address);

		if (Endpoint_BytesInEndpoint())
		{
			Endpoint_ClearIN();
		}

		status = ENDPOINT_READYWAIT_NoError;
	}
	else
	{
		status = ENDPOINT_RWSTREAM_DeviceDisconnected;
	}

	return status;
}

uint16_t CDC_Device_BytesReceived(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	uint16_t bytes = 0;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{

		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataOUTEndpoint.Address);

		if (Endpoint_IsOUTReceived())
		{
			if (!(Endpoint_BytesInEndpoint()))
			{
				Endpoint_ClearOUT();
				bytes = 0;
			}
			else
			{
				bytes = Endpoint_BytesInEndpoint();
			}
		}
		else
		{
			bytes = 0;
		}
	}

	return bytes;
}

int16_t CDC_Device_ReceiveByte(
						USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	int16_t Rx_bytes = -1;
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{
		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.DataOUTEndpoint.Address);

		if (Endpoint_IsOUTReceived())
		{
			if (Endpoint_BytesInEndpoint())
			{
				Rx_bytes = Endpoint_Read_8();
			}
			else
			{
				Endpoint_ClearOUT();
			}

		}

	}
	return Rx_bytes;
}

void CDC_Device_SendControlLineStateChange(
						USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo)
{
	if ((USB_DeviceState == DEVICE_STATE_Configured) &&	(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS != 0))
	{

		Endpoint_SelectEndpoint(CDCInterfaceInfo->Config.NotificationEndpoint.Address);

		USB_Request_Header_t Notification = (USB_Request_Header_t)
			{
				.bmRequestType = (REQDIR_DEVICETOHOST | REQTYPE_CLASS |	REQREC_INTERFACE),
				.bRequest      = CDC_NOTIF_SerialState,
				.wValue        = 0,
				.wIndex        = 0,
				.wLength       = sizeof(CDCInterfaceInfo->State.ControlLineStates.DeviceToHost),
			};

		Endpoint_Write_Stream_LE(&Notification, sizeof(USB_Request_Header_t), NULL);
		Endpoint_Write_Stream_LE(&CDCInterfaceInfo->State.ControlLineStates.DeviceToHost,
				sizeof(CDCInterfaceInfo->State.ControlLineStates.DeviceToHost), NULL);
		Endpoint_ClearIN();
	}
}

#if defined(FDEV_SETUP_STREAM)
void CDC_Device_CreateStream(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo,
                             FILE* const Stream)
{
	*Stream = (FILE)FDEV_SETUP_STREAM(CDC_Device_putchar, CDC_Device_getchar,_FDEV_SETUP_RW);
	fdev_set_udata(Stream, CDCInterfaceInfo);
}

void CDC_Device_CreateBlockingStream(
						USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo,
                                     FILE* const Stream)
{
	*Stream = (FILE)FDEV_SETUP_STREAM(CDC_Device_putchar, CDC_Device_getchar_Blocking, _FDEV_SETUP_RW);
	fdev_set_udata(Stream, CDCInterfaceInfo);
}

static int CDC_Device_putchar(char c, FILE* Stream)
{
	return CDC_Device_SendByte((USB_ClassInfo_CDC_Device_t*)fdev_get_udata(Stream), c) ? _FDEV_ERR : 0;
}

static int CDC_Device_getchar(FILE* Stream)
{
	int16_t ReceivedByte = CDC_Device_ReceiveByte((USB_ClassInfo_CDC_Device_t*)fdev_get_udata(Stream));

	if (ReceivedByte < 0)
	{
		ReceivedByte = (int16_t)_FDEV_EOF;
	}

	return ReceivedByte;
}

static int CDC_Device_getchar_Blocking(FILE* Stream)
{
	int16_t ReceivedByte = 0;

	while ((ReceivedByte = CDC_Device_ReceiveByte((USB_ClassInfo_CDC_Device_t*)fdev_get_udata(Stream))) < 0)
	{
		if (USB_DeviceState != DEVICE_STATE_Unattached)
		{
			CDC_Device_USBTask((USB_ClassInfo_CDC_Device_t*)fdev_get_udata(Stream));
			USB_USBTask();
		}
		else
		{
			ReceivedByte = (int16_t)_FDEV_EOF;
		}
	}

	return ReceivedByte;
}
#endif


#endif

