<?php
	session_start();

	if (isset($_SESSION["counter"]))
	{
		$counter = $_SESSION["counter"];
	}
	else
	{
		$counter = 0;
	}

	$_SESSION["counter"] = $counter + 1;
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Counter</title>
</head>
<body>
	You have visted this site <?= $counter ?> time(s).
</body>
</html>