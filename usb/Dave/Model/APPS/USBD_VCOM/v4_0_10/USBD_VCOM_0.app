<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="USBD_VCOM" URI="http://resources/4.0.10/app/USBD_VCOM/0" description="USB virtual COM port application. This APP implements the VCOM over USB CDC class driver." mode="NOTSHARABLE" version="4.0.10" minDaveVersion="4.0.0" instanceLabel="USBD_VCOM_0" appLabel="">
  <properties singleton="true" provideInit="true"/>
  <requiredApps URI="http://resources/4.0.10/app/USBD_VCOM/0/ra_usbd" requiredAppName="USBD">
    <downwardMapList xsi:type="ResourceModel:App" href="../../USBD/v4_0_14/USBD_0.app#/"/>
  </requiredApps>
</ResourceModel:App>
