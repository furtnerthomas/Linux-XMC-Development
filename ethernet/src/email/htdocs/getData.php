<?php

$led1=file_get_contents ("./LED1");
$led2=file_get_contents ("./LED2");

$led1_int=intval($led1);
$led2_int=intval($led2);

$led1_uuid=explode (" ", $led1 );
$led2_uuid=explode (" ", $led2 );


$results[]=array($led1_int,$led1_uuid[1],$led2_int, $led2_uuid[1]);

echo json_encode($results);
?>
