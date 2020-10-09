$(document).ready(function()
{
var LED1,LED2;
var LED1_UUID_OLD="9999",LED2_UUID_OLD="9999";
var LED1_UUID,LED2_UUID;
var count =0;
var off=0;
$.ajaxSetup({ cache: false });
function timed_function() {
	$.getJSON( "getData.php",{
			},
			function(data){
				data.forEach(	function(item){
						LED1_UUID=item[1];
						LED2_UUID=item[3];
						for (var bit=0;bit<8;bit++)
						{
							var device1_children=$($("#device1 .LED").get(bit)).children();
							var device2_children=$($("#device2 .LED").get(bit)).children();
							if ((LED1_UUID!=LED1_UUID_OLD)&&(LED1_UUID_OLD!="9999"))
							{
								if (item[0]&(1<<bit))
								{
									device1_children.filter(".RED").show();							
									device1_children.filter(".GREEN").hide();							
									device1_children.filter(".BLUE").hide();							
								}
								else
								{
									device1_children.filter(".GREEN").show();							
									device1_children.filter(".RED").hide();							
									device1_children.filter(".BLUE").hide();							
								}	
							}
							else
							{
									device1_children.filter(".GREEN").hide();							
									device1_children.filter(".RED").hide();							
									device1_children.filter(".BLUE").show();															
							}
							if ((LED2_UUID!=LED2_UUID_OLD)&&(LED2_UUID_OLD!=9999))
							{
								if (item[2]&(1<<bit))
								{
									device2_children.filter(".RED").show();							
									device2_children.filter(".GREEN").hide();							
									device2_children.filter(".BLUE").hide();							
								}
								else
								{
									device2_children.filter(".GREEN").show();							
									device2_children.filter(".RED").hide();							
									device2_children.filter(".BLUE").hide();							
								}	
							}
							else
							{
									device2_children.filter(".GREEN").hide();							
									device2_children.filter(".RED").hide();							
									device2_children.filter(".BLUE").show();															
							}
						}
						LED1_UUID_OLD=LED1_UUID;
						LED2_UUID_OLD=LED2_UUID;
						});
			});				
	window.setTimeout(timed_function,500);	
}	

timed_function();

});