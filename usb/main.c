 #include <DAVE.h>
 int8_t RxBuffer[64] = { 0 };
 int8_t TxBuffer[64] = { 0 };
 uint8_t Bytes;



 int main(void)
 {
   DAVE_STATUS_t status;

   status = DAVE_Init();
   if (status == DAVE_STATUS_FAILURE)
   {
     XMC_DEBUG(("DAVE Apps initialization failed with status %d\n", status));
     while (1U)
     {
     }
   }


   if(USBD_VCOM_Connect() != USBD_VCOM_STATUS_SUCCESS)
   {
       return -1;
   }

   while(!USBD_VCOM_IsEnumDone());

   while (1U)
   {
     Bytes = USBD_VCOM_BytesReceived();

     if (Bytes)
     {

       USBD_VCOM_ReceiveByte(&RxBuffer[0]);

       USBD_VCOM_SendByte(RxBuffer[0]);

     }
     CDC_Device_USBTask(&USBD_VCOM_cdc_interface);
   }

   return 1;
 }
