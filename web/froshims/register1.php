<?php
	if (empty($_POST["name"]) || empty($_POST["gender"]) || empty($_POST["dorm"]))
	{
		header("Location: http://localhost/froshims.php");
		exit;
	}
?>


<!DOCTYPE html>
<html>
	<head>
		<title> Frosh IMs</title>
	</head>
	<body>
		You are registered! (Well, not really.)
	</body>
</html>