<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="SYSTIMER" URI="http://resources/4.1.14/app/SYSTIMER/0" description="The SYSTIMER APP uses the SysTick interrupt to call user&#xA;functions periodically at a specified rate or &#xA;after a given time period expires." version="4.1.14" minDaveVersion="4.0.0" instanceLabel="SYSTIMER_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../ETH_LWIP/v4_0_10/ETH_LWIP_0.app#//@requiredApps.3"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <requiredApps URI="http://resources/4.1.14/app/SYSTIMER/0/appres_clock" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.1.14/app/SYSTIMER/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_12/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="syst" URI="http://resources/4.1.14/app/SYSTIMER/0/hwres_syst" resourceGroupUri="peripheral/cpu/0/systick" mResGrpUri="peripheral/cpu/0/systick">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/cpu/cpu_0.dd#//@provided.6"/>
  </hwResources>
</ResourceModel:App>
