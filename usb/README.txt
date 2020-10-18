EXAMPLE NAME: USBD_VCOM_APP_Example_XMC45

HISTORY:
V1.0.0 initial version 


OVERVIEW: 
XMC4500 USB demo based on DAVE APPs (DAVE v4).
This USB example is based on the easy to use DAVE APPs (DAVE v4). It initializes the USB as a USB VCOM device.
Every character received is returned to the sender.

This project is referenced from the USBH_VCOM_XMC45 project to be used as VCOM device counterpart 
to demonstrate a VCOM communication between a host and a device.

REQUIREMENTS:
1) "XMC4500 General Purpose CPU_45A-V3 board 
2) Micro USB Cable 
3) Windows PC/Laptop installed with DAVE v4 (Version 4.1.4 or higher)

DESCRIPTION:
After initialization of DAVE, the application connects the VCOM and waits for finishing of enumeration.
After enumeration every byte received is returned to the sender.
Please be aware, on your Relax Kit hardware the USB ports are only connected  to the outside world
on USB plug X100. On USB plug X100 the debug feature is not available. Still you can use a second 
Micro USB cable connected to X101 for debug purpose in parallel.

Source structure:
1)main.c         configuration and initialization of modules
                 connect USB VCOM device to host
		 wait for enumeration to finish
		 send every byte which is received
				 
Following DAVE APP (DAVE v4) is used:
1)USBD_VCOM      Purpose: Implement, configure and control the USB device as a VCOM device.

BUILD:
Please note, the project has to be rebuild after importing because the build result folder 
has been deleted to reduce the size.
1) Import the project
2) Build and flash the application to the device using USB X101 connection

SETUP:
1) Connect Micro USB cable to Relax Kit USB plug X100 and to a PC/laptop.
2) After connecting Windows USB host automatically loads the driver after verifying the descriptors.
   The first time user has to point  to proper .inf file from the following project path:
   "...\Dave\Generated\USBD_VCOM\inf\driver.inf".
3) Check inside the "Computer Management/Device manager" on your PC/Laptop on which
   COM port the entry "Communication Ports" appears.
4) Open a terminal (e.g. putty) select the COM port observed inside step 2 and connect to the interface.

HOW TO TEST:
1) After reset start typing on your terminal.
   OBSERVATION: The characters are returned and appear inside your terminal. 
