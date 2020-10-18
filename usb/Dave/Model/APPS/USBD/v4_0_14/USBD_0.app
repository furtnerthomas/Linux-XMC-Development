<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="USBD" URI="http://resources/4.0.14/app/USBD/0" description="USB device protocol layer APP.This APP handles the device and endpoint requests from the LLD.&#xA;The APP uses LUFA library to communicate to XMC USBD LLD." mode="NOTSHARABLE" version="4.0.14" minDaveVersion="4.0.0" instanceLabel="USBD_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../USBD_VCOM/v4_0_10/USBD_VCOM_0.app#//@requiredApps.0"/>
  <properties singleton="true"/>
  <virtualSignals name="usb_irq" URI="http://resources/4.0.14/app/USBD/0/vs_nvic_signal_in" hwSignal="signal_in" hwResource="//@hwResources.0" required="false"/>
  <requiredApps URI="http://resources/4.0.14/app/USBD/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_12/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.14/app/USBD/0/appres_clock_xmc4" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="NVIC Node" URI="http://resources/4.0.14/app/USBD/0/hwres_usbd_xmc4_node" resourceGroupUri="peripheral/cpu/0/nvic/interrupt/sv0" solverVariable="true" mResGrpUri="peripheral/cpu/0/nvic/interrupt/sv0">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU/CPU_0.dd#//@provided.0"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="107"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="107"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="usbd" URI="http://resources/4.0.14/app/USBD/0/hwres_usb" resourceGroupUri="peripheral/usb/*/usb" mResGrpUri="peripheral/usb/*/usb">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/USB/USB_0.dd#//@provided.0"/>
  </hwResources>
</ResourceModel:App>
