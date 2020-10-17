Basic Webserver Demo Example

Description of example project
==============================

HTTPSERVER

This is a demonstration of how to make the most basic kind 
of server using lWIP.

* httpserver-netconn.c - uses netconn and netbuf API

Hardware Setup
===============
1. XMC4500 Relaxkit 
2. Crossover cable if you would like to connect directly to PC or
   Standard cable to connect to a switch.
   
How to test the application
====================================================================================
For Importing Project:
====================================================================================

a. Import the project
b. Compile and flash the application onto the device
c. Run the application. 
d. Connect cable to PC (crossover cable required) or to a switch.
e. Go to the setting IPV4 of your ethernet card disable DHCP and set ip address to 
   192.168.0.40 and subnet mask 255.255.255.0 (see picture IPV4_settings.jpg)  
    
====================================================================================
For Creating New Project:
====================================================================================

a. Create a new project in DAVE with following properties
   Simple Main Project
   Select the target MCU according to the example file you would like to use
   (after the project is created the  device relevant XMC lib  files are copied into the project 
   and can be found in the the "Libraries" folder
b. Delete the main.c in the newly created project
c. Copy the main.c and other required project sources form the the example folder of the XMC Lib package
   into the created DAVE v4 project
d. Right click on Project -> Properties -> C/C++ Build -> Settings 

    i. Preprocessor -> XMC4500_F144x1024
                       __CORTEX_M4
                       __FPU_PRESENT
                       __CMSIS_RTOS
    ii. Directories- > Add below mentioned path
    
        "${workspace_loc:/${ProjName}/Libraries/XMCLib/inc}"
        "${workspace_loc:/${ProjName}}/Libraries/CMSIS/Include"
        "${workspace_loc:/${ProjName}}/Libraries/CMSIS/Infineon/XMC4500_series/Include"
        "${workspace_loc:/${ProjName}}"
        "${workspace_loc:/${ProjName}/Libraries}"
        "${workspace_loc:/${ProjName}/Libraries/cmsis_rtos_rtx/INC}"
        "${workspace_loc:/${ProjName}/Libraries/lwip/include}"
        "${workspace_loc:/${ProjName}/Libraries/lwip/include/ipv4}"
        "${workspace_loc:/${ProjName}/Libraries/lwip/port/cmsis-rtos/include}"
        "${workspace_loc:/${ProjName}/Libraries/lwip/port/cmsis-rtos/netif}"
         
e. Compile and download to the target
f. Connect cable to PC (crossover cable required) or to a switch.
g. Go to the setting IPV4 of your ethernet card disable DHCP and set ip address to 
   192.168.0.40 and subnet mask 255.255.255.0 (see picture IPV4_settings.jpg) 
   
   
   
   
   
====================================================================================
Expected Output
====================================================================================
1. open cmd window and type   ping 192.168.0.10
	
	Pinging 192.168.0.10 with 32 bytes of data:
	Reply from 192.168.0.10: bytes=32 time<1ms TTL=255
	Reply from 192.168.0.10: bytes=32 time<1ms TTL=255
	Reply from 192.168.0.10: bytes=32 time<1ms TTL=255
	Reply from 192.168.0.10: bytes=32 time<1ms TTL=255
	
	Ping statistics for 192.168.0.10:
	    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
	Approximate round trip times in milli-seconds:
	    Minimum = 0ms, Maximum = 0ms, Average = 0ms

2. Then check with a webbrowser at this address:
   http://192.168.0.10   
   
   The IP address is manual configure using 192.168.0.10.
   Direct your web browser at 192.168.0.10, a welcome message should be displayed.