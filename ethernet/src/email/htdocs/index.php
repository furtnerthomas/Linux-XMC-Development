<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>IoT - Inspiration</title>
  <script src="./js/jquery-1.12.3.js"></script>
  <script src="./js/base.js"></script>
  <link rel="stylesheet" type="text/css" href="./css/styles.css">
</head>
<body>
<div id="header">
<img src="./res/Infineon.jpeg">
</div>
<div id="main">
<br><br><br>
Device #1:
<div id="device1">
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
</div> 
<br><br><br>
Device #2:
<div id="device2">
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
	<div class="LED">
		<img class="RED" src="./res/RED.jpeg">
		<img class="GREEN" src="./res/GREEN.jpeg">
		<img class="BLUE" src="./res/BLUE.jpeg">
	</div>
</div>
<br>
<br>
<br>
<br>
</div>
<div class="LOGBOOK">
<?php
		$content=file("./LOGBOOK",FILE_IGNORE_NEW_LINES);
		echo "<table>";
				foreach ($content as $item)
		{
			$items=explode("_",$item);
			echo "<tr><td>".$items[0]."</td><td>".$items[1]."</td><td>".$items[2]."</td>"."</tr>";
		}
		echo "</table>";
?>
</div>
</body>
</html>