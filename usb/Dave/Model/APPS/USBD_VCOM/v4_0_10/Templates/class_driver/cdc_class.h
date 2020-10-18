/**
 * @file cdc_class.h
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


/*
 *  CDC Class Driver module. This module contains an internal implementation of
 *  the USB CDC-ACM class Virtual Serial Ports, for both Device and Host USB
 *  modes. User applications can use this class driver instead of implementing
 *  the CDC class manually via the low-level APIs.
 *
 *  This module is designed to simplify the user code by exposing only the
 *  required interface needed to interface with Hosts or Devices using the USB
 *  CDC Class.
 *
 */

#ifndef _CDC_CLASS_H_
#define _CDC_CLASS_H_
/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
	extern "C" {
#endif
	
		#define __INCLUDE_FROM_USB_DRIVER
		#define __INCLUDE_FROM_CDC_DRIVER

/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
	#include "../../USBD/usb/core/usb_mode.h" /*IFX*/

	#if defined(USB_CAN_BE_DEVICE)
		#include "device/cdc_class_device.h"
	#endif

/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
	}
#endif
#endif


