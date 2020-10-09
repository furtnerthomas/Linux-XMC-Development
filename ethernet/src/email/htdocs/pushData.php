<?php

$Sender=array(array("From: Button1@Device1.de\r\n","From: Button2@Device1.de\r\n"),array("From: Button1@Device2.de\r\n","From: Button2@Device2.de\r\n"));

for ($i=0,$uuid="";$i<16;$i++)
		$uuid.=dechex(mt_rand(4096,65535));	
if (isset($_GET["value"])&&(isset($_GET["device"])))
{
	$time_now=time();
	$testread=10;
	while(($time_old==0)&&($testread>0))
	{
		$time_old=file_get_contents("./Device".$_GET["device"]);
		$testread--;
	}
	$date_now=date("Y-m-d@H:i:s",$time_now);
	$date_old=date("Y-m-d@H:i:s",$time_old);
	
	if ($time_now!=$time_old)
		file_put_contents("./Device".$_GET["device"], $time_now);
	$device=intval($_GET["device"])+1;
	if ((($time_now-intval($time_old))>4))
	{
		file_put_contents("./LOGBOOK",$date_old."_Device#".$device."_DEVICE-DISCONNECTED\n",FILE_APPEND);	
		file_put_contents("./LOGBOOK",$date_now."_Device#".$device."_DEVICE-CONNECTED\n",FILE_APPEND);			
	}
	if (($_GET["value"]>=0)&&($_GET["value"]<=255)&&($_GET["device"]>=0)&&($_GET["device"]<=1))
	{
		if($_GET["device"]==0)
		{
			file_put_contents("./LED1",$_GET["value"]." ".$uuid );
		}
		else 
		{
			file_put_contents("./LED2",$_GET["value"]." ".$uuid  );			
		}
	}
	$mail=file_get_contents("./MAILADR");
	if ($_GET["button1"]==1)
	{
		$counter=intval(file_get_contents("./BUTTON1"));
		$counter++;
		file_put_contents("./BUTTON1",$counter );
		mail($mail,"ALERT - BUTTON 1 PUSHED","Do not reply to this message!",$Sender[$_GET["device"]][0]);
		file_put_contents("./LOGBOOK",$date_now."_Device#".$device."_EVENT-BUTTON1\n",FILE_APPEND);
		file_put_contents("./LOGBOOK",$date_now."_Device#".$device."_MAIL SENT:".$mail."\n",FILE_APPEND);
	}
	if ($_GET["button2"]==1)
	{
		$counter=intval(file_get_contents("./BUTTON2"));
		$counter++;
		file_put_contents("./BUTTON2",$counter );		
		mail($mail,"ALERT BUTTON 2 PUSHED","Do not reply to this message!",$Sender[$_GET["device"]][1]);
		file_put_contents("./LOGBOOK",$date_now."_Device#".$device."_EVENT-BUTTON2\n",FILE_APPEND);
		file_put_contents("./LOGBOOK",$date_now."_Device#".$device."_MAIL SENT:".$mail."\n",FILE_APPEND);
	}
}
?>
