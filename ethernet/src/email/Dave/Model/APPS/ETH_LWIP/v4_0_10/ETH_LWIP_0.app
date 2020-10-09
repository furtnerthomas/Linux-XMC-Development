<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="ETH_LWIP" URI="http://resources/4.0.10/app/ETH_LWIP/0" description="lwIP (lightweight IP) is an open source TCP/IP stack designed for embedded systems.&#xA;lwIP stack supports the IP, TCP, UDP, ICMP, IGMP, ARP, DHCP, AutoIP, DNS and SNMP protocols.&#xA;lwIP is provided under BSD style license and maintained at http://savannah.nongnu.org/projects/lwip." version="4.0.10" minDaveVersion="4.1.2" instanceLabel="ETH_LWIP_0" appLabel="">
  <properties singleton="true" provideInit="true" sharable="true"/>
  <virtualSignals name="interrupt" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_int" hwSignal="intr" hwResource="//@hwResources.0"/>
  <virtualSignals name="carrier_sense" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_crs" hwSignal="crs" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="crs pin" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_crs" hwSignal="pad" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="collision_detect" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_cd" hwSignal="col" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="collision_detect" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_cd" hwSignal="pad" hwResource="//@hwResources.2" required="false"/>
  <virtualSignals name="crs_dv" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rdv" hwSignal="crs_dv" hwResource="//@hwResources.0"/>
  <virtualSignals name="crs_dv" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rdv" hwSignal="pad" hwResource="//@hwResources.3"/>
  <virtualSignals name="rx_error" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxer" hwSignal="rxer" hwResource="//@hwResources.0"/>
  <virtualSignals name="rx_error" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxer" hwSignal="pad" hwResource="//@hwResources.4"/>
  <virtualSignals name="rx_data0" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd0" hwSignal="rxd0" hwResource="//@hwResources.0"/>
  <virtualSignals name="rx_data0" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd0" hwSignal="pad" hwResource="//@hwResources.5"/>
  <virtualSignals name="rx_data1" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd1" hwSignal="rxd1" hwResource="//@hwResources.0"/>
  <virtualSignals name="rx_data1" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd1" hwSignal="pad" hwResource="//@hwResources.6"/>
  <virtualSignals name="rx_data2" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd2" hwSignal="rxd2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="rx_data2" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd2" hwSignal="pad" hwResource="//@hwResources.7" required="false"/>
  <virtualSignals name="rx_data3" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd3" hwSignal="rxd3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="rx_data3" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd3" hwSignal="pad" hwResource="//@hwResources.8" required="false"/>
  <virtualSignals name="tx_enable" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txen" hwSignal="tx_en" hwResource="//@hwResources.0"/>
  <virtualSignals name="tx_enable" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txen" hwSignal="pad" hwResource="//@hwResources.9"/>
  <virtualSignals name="tx_error" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txer" hwSignal="txer" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="tx_error" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txer" hwSignal="pad" hwResource="//@hwResources.10" required="false"/>
  <virtualSignals name="tx_data0" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd0" hwSignal="txd0" hwResource="//@hwResources.0"/>
  <virtualSignals name="tx_data0" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd0" hwSignal="pad" hwResource="//@hwResources.11"/>
  <virtualSignals name="tx_data1" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd1" hwSignal="txd1" hwResource="//@hwResources.0"/>
  <virtualSignals name="tx_data1" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd1" hwSignal="pad" hwResource="//@hwResources.12"/>
  <virtualSignals name="tx_data2" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd2" hwSignal="txd2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="tx_data2" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd2" hwSignal="pad" hwResource="//@hwResources.13" required="false"/>
  <virtualSignals name="tx_data3" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd3" hwSignal="txd3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="tx_data3" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd3" hwSignal="pad" hwResource="//@hwResources.14" required="false"/>
  <virtualSignals name="tx_clock" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_tx_clk" hwSignal="clk_tx" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="tx_clock" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_tx_clk" hwSignal="pad" hwResource="//@hwResources.15" required="false"/>
  <virtualSignals name="rmii_clock" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rx_clk" hwSignal="clk_rmii" hwResource="//@hwResources.0"/>
  <virtualSignals name="rmii_clock" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rx_clk" hwSignal="pad" hwResource="//@hwResources.16"/>
  <virtualSignals name="mdc" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdc" hwSignal="mdc" hwResource="//@hwResources.0"/>
  <virtualSignals name="mdc" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdc" hwSignal="pad" hwResource="//@hwResources.17"/>
  <virtualSignals name="mdio" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdio" hwSignal="mdi" hwResource="//@hwResources.0"/>
  <virtualSignals name="mdio" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdo" hwSignal="mdo" hwResource="//@hwResources.0"/>
  <virtualSignals name="mdio" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio" hwSignal="pad" hwResource="//@hwResources.18"/>
  <virtualSignals name="mdio_hw_o" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio_hw_o" hwSignal="hw_o" hwResource="//@hwResources.18"/>
  <virtualSignals name="eth interrupt" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_interrupt" hwSignal="intr" hwResource="//@hwResources.0"/>
  <virtualSignals name="sr_protocol_events" URI="http://resources/4.0.10/app/ETH_LWIP/0/vs_nvic_node" hwSignal="signal_in" hwResource="//@hwResources.19"/>
  <virtualSignals name="CRS_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_crs" hwSignal="pin" hwResource="//@hwResources.20"/>
  <virtualSignals name="CD_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_cd" hwSignal="pin" hwResource="//@hwResources.21"/>
  <virtualSignals name="CRS_DV_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rdv" hwSignal="pin" hwResource="//@hwResources.22"/>
  <virtualSignals name="RXER_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxer" hwSignal="pin" hwResource="//@hwResources.23"/>
  <virtualSignals name="RXD0_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd0" hwSignal="pin" hwResource="//@hwResources.24"/>
  <virtualSignals name="RXD1_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd1" hwSignal="pin" hwResource="//@hwResources.25"/>
  <virtualSignals name="RXD2_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd2" hwSignal="pin" hwResource="//@hwResources.26"/>
  <virtualSignals name="RXD3_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd3" hwSignal="pin" hwResource="//@hwResources.27"/>
  <virtualSignals name="TXEN_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txen" hwSignal="pin" hwResource="//@hwResources.28"/>
  <virtualSignals name="TXER_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txer" hwSignal="pin" hwResource="//@hwResources.29"/>
  <virtualSignals name="TXD0_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd0" hwSignal="pin" hwResource="//@hwResources.30"/>
  <virtualSignals name="TXD1_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd1" hwSignal="pin" hwResource="//@hwResources.31"/>
  <virtualSignals name="TXD2_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd2" hwSignal="pin" hwResource="//@hwResources.32"/>
  <virtualSignals name="TXD3_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd3" hwSignal="pin" hwResource="//@hwResources.33"/>
  <virtualSignals name="TX_CLK_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_tx_clk" hwSignal="pin" hwResource="//@hwResources.34"/>
  <virtualSignals name="RMII_CLK_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rx_clk" hwSignal="pin" hwResource="//@hwResources.35"/>
  <virtualSignals name="MDC_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdc" hwSignal="pin" hwResource="//@hwResources.36"/>
  <virtualSignals name="MDIO_signal" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdio" hwSignal="pin" hwResource="//@hwResources.37"/>
  <requiredApps URI="http://resources/4.0.10/app/ETH_LWIP/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_12/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.10/app/ETH_LWIP/0/appres_rtos" requiredAppName="CMSIS_RTOS" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.10/app/ETH_LWIP/0/appres_rtt" requiredAppName="SEGGER_RTT" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.10/app/ETH_LWIP/0/appres_systimer" requiredAppName="SYSTIMER" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../SYSTIMER/v4_1_14/SYSTIMER_0.app#/"/>
  </requiredApps>
  <hwResources name="ETH" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_mac" resourceGroupUri="peripheral/eth/*/eth" mResGrpUri="peripheral/eth/*/eth">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/eth0/eth0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="CRS" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_crs" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="CD" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_cd" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="CRS_DV" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rdv" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port15/port15_15.dd#//@provided.5"/>
  </hwResources>
  <hwResources name="RXER" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rxer" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.11"/>
  </hwResources>
  <hwResources name="RXD0" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rxd0" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.15"/>
  </hwResources>
  <hwResources name="RXD1" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rxd1" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="RXD2" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rxd2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RXD3" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rxd3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TXEN" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txen" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="TXER" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txer" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TXD0" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txd0" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.32"/>
  </hwResources>
  <hwResources name="TXD1" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txd1" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.23"/>
  </hwResources>
  <hwResources name="TXD2" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txd2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TXD3" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_txd3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TX_CLK" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_tx_clk" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RMII_CLK" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_rx_clk" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port15/port15_15.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="MDC" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_mdc" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.28"/>
  </hwResources>
  <hwResources name="MDIO" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_eth_port_mdio" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port2/port2_2.dd#//@provided.19"/>
  </hwResources>
  <hwResources name="NVIC node" URI="http://resources/4.0.10/app/ETH_LWIP/0/hwres_nvic_node" resourceGroupUri="peripheral/cpu/0/nvic/interrupt/*" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/cpu/cpu_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="CRS" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_crs" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="CD" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_cd" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="CRS_DV" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rdv" resourceGroupUri="devicepackage/0/53" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.13"/>
  </hwResources>
  <hwResources name="RXER" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rxer" resourceGroupUri="devicepackage/0/70" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.11"/>
  </hwResources>
  <hwResources name="RXD0" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rxd0" resourceGroupUri="devicepackage/0/72" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.12"/>
  </hwResources>
  <hwResources name="RXD1" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rxd1" resourceGroupUri="devicepackage/0/71" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.10"/>
  </hwResources>
  <hwResources name="RXD2" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rxd2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RXD3" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rxd3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXEN" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txen" resourceGroupUri="devicepackage/0/69" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.16"/>
  </hwResources>
  <hwResources name="TXER" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txer" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXD0" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txd0" resourceGroupUri="devicepackage/0/68" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.17"/>
  </hwResources>
  <hwResources name="TXD1" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txd1" resourceGroupUri="devicepackage/0/67" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.18"/>
  </hwResources>
  <hwResources name="TXD2" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txd2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXD3" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_txd3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TX_CLK" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_tx_clk" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RMII_CLK" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_rx_clk" resourceGroupUri="devicepackage/0/54" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="MDC" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_mdc" resourceGroupUri="devicepackage/0/75" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.14"/>
  </hwResources>
  <hwResources name="MDIO" URI="http://resources/4.0.10/app/ETH_LWIP/0/__pin_hwres_eth_port_mdio" resourceGroupUri="devicepackage/0/74" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.15"/>
  </hwResources>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_crs/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_crs" systemDefined="true" sourceSignal="crs pin" targetSignal="carrier_sense" required="false" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.1"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_cd/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_cd" systemDefined="true" sourceSignal="collision_detect" targetSignal="collision_detect" required="false" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.3"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rdv/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rdv" systemDefined="true" sourceSignal="crs_dv" targetSignal="crs_dv" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxer/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxer" systemDefined="true" sourceSignal="rx_error" targetSignal="rx_error" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd0" systemDefined="true" sourceSignal="rx_data0" targetSignal="rx_data0" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd1/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd1" systemDefined="true" sourceSignal="rx_data1" targetSignal="rx_data1" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd2/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd2" systemDefined="true" sourceSignal="rx_data2" targetSignal="rx_data2" required="false" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.13"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd3/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rxd3" systemDefined="true" sourceSignal="rx_data3" targetSignal="rx_data3" required="false" srcVirtualSignal="//@virtualSignals.16" targetVirtualSignal="//@virtualSignals.15"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txen/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txen" systemDefined="true" sourceSignal="tx_enable" targetSignal="tx_enable" srcVirtualSignal="//@virtualSignals.17" targetVirtualSignal="//@virtualSignals.18"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txer/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txer" systemDefined="true" sourceSignal="tx_error" targetSignal="tx_error" required="false" srcVirtualSignal="//@virtualSignals.19" targetVirtualSignal="//@virtualSignals.20"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd0" systemDefined="true" sourceSignal="tx_data0" targetSignal="tx_data0" srcVirtualSignal="//@virtualSignals.21" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd1/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd1" systemDefined="true" sourceSignal="tx_data1" targetSignal="tx_data1" srcVirtualSignal="//@virtualSignals.23" targetVirtualSignal="//@virtualSignals.24"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd2/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd2" systemDefined="true" sourceSignal="tx_data2" targetSignal="tx_data2" required="false" srcVirtualSignal="//@virtualSignals.25" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_txd3/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd3" systemDefined="true" sourceSignal="tx_data3" targetSignal="tx_data3" required="false" srcVirtualSignal="//@virtualSignals.27" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_tx_clk/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_tx_clk" systemDefined="true" sourceSignal="tx_clock" targetSignal="tx_clock" required="false" srcVirtualSignal="//@virtualSignals.30" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rx_clk/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_rx_clk" systemDefined="true" sourceSignal="rmii_clock" targetSignal="rmii_clock" srcVirtualSignal="//@virtualSignals.32" targetVirtualSignal="//@virtualSignals.31"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdc/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdc" systemDefined="true" sourceSignal="mdc" targetSignal="mdc" srcVirtualSignal="//@virtualSignals.33" targetVirtualSignal="//@virtualSignals.34"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdio" systemDefined="true" sourceSignal="mdio" targetSignal="mdio" srcVirtualSignal="//@virtualSignals.37" targetVirtualSignal="//@virtualSignals.35"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_mdo/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio_hw_o" systemDefined="true" sourceSignal="mdio" targetSignal="mdio_hw_o" srcVirtualSignal="//@virtualSignals.36" targetVirtualSignal="//@virtualSignals.38"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_eth_interrupt/http://resources/4.0.10/app/ETH_LWIP/0/vs_nvic_node" systemDefined="true" sourceSignal="eth interrupt" targetSignal="sr_protocol_events" srcVirtualSignal="//@virtualSignals.39" targetVirtualSignal="//@virtualSignals.40"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_crs/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_crs" systemDefined="true" sourceSignal="crs pin" targetSignal="CRS_signal" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.41"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_crs/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_crs" systemDefined="true" sourceSignal="CRS_signal" targetSignal="crs pin" srcVirtualSignal="//@virtualSignals.41" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_cd/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_cd" systemDefined="true" sourceSignal="collision_detect" targetSignal="CD_signal" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.42"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_cd/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_cd" systemDefined="true" sourceSignal="CD_signal" targetSignal="collision_detect" srcVirtualSignal="//@virtualSignals.42" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rdv/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rdv" systemDefined="true" sourceSignal="crs_dv" targetSignal="CRS_DV_signal" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.43"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rdv/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rdv" systemDefined="true" sourceSignal="CRS_DV_signal" targetSignal="crs_dv" srcVirtualSignal="//@virtualSignals.43" targetVirtualSignal="//@virtualSignals.6"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxer/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxer" systemDefined="true" sourceSignal="rx_error" targetSignal="RXER_signal" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.44"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxer/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxer" systemDefined="true" sourceSignal="RXER_signal" targetSignal="rx_error" srcVirtualSignal="//@virtualSignals.44" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd0" systemDefined="true" sourceSignal="rx_data0" targetSignal="RXD0_signal" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.45"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd0" systemDefined="true" sourceSignal="RXD0_signal" targetSignal="rx_data0" srcVirtualSignal="//@virtualSignals.45" targetVirtualSignal="//@virtualSignals.10"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd1/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd1" systemDefined="true" sourceSignal="rx_data1" targetSignal="RXD1_signal" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.46"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd1/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd1" systemDefined="true" sourceSignal="RXD1_signal" targetSignal="rx_data1" srcVirtualSignal="//@virtualSignals.46" targetVirtualSignal="//@virtualSignals.12"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd2/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd2" systemDefined="true" sourceSignal="rx_data2" targetSignal="RXD2_signal" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.47"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd2/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd2" systemDefined="true" sourceSignal="RXD2_signal" targetSignal="rx_data2" srcVirtualSignal="//@virtualSignals.47" targetVirtualSignal="//@virtualSignals.14"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd3/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd3" systemDefined="true" sourceSignal="rx_data3" targetSignal="RXD3_signal" srcVirtualSignal="//@virtualSignals.16" targetVirtualSignal="//@virtualSignals.48"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rxd3/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rxd3" systemDefined="true" sourceSignal="RXD3_signal" targetSignal="rx_data3" srcVirtualSignal="//@virtualSignals.48" targetVirtualSignal="//@virtualSignals.16"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txen/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txen" systemDefined="true" sourceSignal="tx_enable" targetSignal="TXEN_signal" srcVirtualSignal="//@virtualSignals.18" targetVirtualSignal="//@virtualSignals.49"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txen/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txen" systemDefined="true" sourceSignal="TXEN_signal" targetSignal="tx_enable" srcVirtualSignal="//@virtualSignals.49" targetVirtualSignal="//@virtualSignals.18"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txer/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txer" systemDefined="true" sourceSignal="tx_error" targetSignal="TXER_signal" srcVirtualSignal="//@virtualSignals.20" targetVirtualSignal="//@virtualSignals.50"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txer/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txer" systemDefined="true" sourceSignal="TXER_signal" targetSignal="tx_error" srcVirtualSignal="//@virtualSignals.50" targetVirtualSignal="//@virtualSignals.20"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd0" systemDefined="true" sourceSignal="tx_data0" targetSignal="TXD0_signal" srcVirtualSignal="//@virtualSignals.22" targetVirtualSignal="//@virtualSignals.51"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd0" systemDefined="true" sourceSignal="TXD0_signal" targetSignal="tx_data0" srcVirtualSignal="//@virtualSignals.51" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd1/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd1" systemDefined="true" sourceSignal="tx_data1" targetSignal="TXD1_signal" srcVirtualSignal="//@virtualSignals.24" targetVirtualSignal="//@virtualSignals.52"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd1/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd1" systemDefined="true" sourceSignal="TXD1_signal" targetSignal="tx_data1" srcVirtualSignal="//@virtualSignals.52" targetVirtualSignal="//@virtualSignals.24"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd2/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd2" systemDefined="true" sourceSignal="tx_data2" targetSignal="TXD2_signal" srcVirtualSignal="//@virtualSignals.26" targetVirtualSignal="//@virtualSignals.53"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd2/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd2" systemDefined="true" sourceSignal="TXD2_signal" targetSignal="tx_data2" srcVirtualSignal="//@virtualSignals.53" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd3/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd3" systemDefined="true" sourceSignal="tx_data3" targetSignal="TXD3_signal" srcVirtualSignal="//@virtualSignals.28" targetVirtualSignal="//@virtualSignals.54"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_txd3/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_txd3" systemDefined="true" sourceSignal="TXD3_signal" targetSignal="tx_data3" srcVirtualSignal="//@virtualSignals.54" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_tx_clk/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_tx_clk" systemDefined="true" sourceSignal="tx_clock" targetSignal="TX_CLK_signal" srcVirtualSignal="//@virtualSignals.30" targetVirtualSignal="//@virtualSignals.55"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_tx_clk/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_tx_clk" systemDefined="true" sourceSignal="TX_CLK_signal" targetSignal="tx_clock" srcVirtualSignal="//@virtualSignals.55" targetVirtualSignal="//@virtualSignals.30"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rx_clk/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rx_clk" systemDefined="true" sourceSignal="rmii_clock" targetSignal="RMII_CLK_signal" srcVirtualSignal="//@virtualSignals.32" targetVirtualSignal="//@virtualSignals.56"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_rx_clk/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_rx_clk" systemDefined="true" sourceSignal="RMII_CLK_signal" targetSignal="rmii_clock" srcVirtualSignal="//@virtualSignals.56" targetVirtualSignal="//@virtualSignals.32"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdc/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdc" systemDefined="true" sourceSignal="mdc" targetSignal="MDC_signal" srcVirtualSignal="//@virtualSignals.34" targetVirtualSignal="//@virtualSignals.57"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdc/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdc" systemDefined="true" sourceSignal="MDC_signal" targetSignal="mdc" srcVirtualSignal="//@virtualSignals.57" targetVirtualSignal="//@virtualSignals.34"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdio" systemDefined="true" sourceSignal="mdio" targetSignal="MDIO_signal" srcVirtualSignal="//@virtualSignals.37" targetVirtualSignal="//@virtualSignals.58"/>
  <connections URI="http://resources/4.0.10/app/ETH_LWIP/0/http://resources/4.0.10/app/ETH_LWIP/0/__pin_vs_port_mdio/http://resources/4.0.10/app/ETH_LWIP/0/vs_port_mdio" systemDefined="true" sourceSignal="MDIO_signal" targetSignal="mdio" srcVirtualSignal="//@virtualSignals.58" targetVirtualSignal="//@virtualSignals.37"/>
</ResourceModel:App>
