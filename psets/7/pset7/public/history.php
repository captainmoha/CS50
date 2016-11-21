<?php
	require("../includes/config.php");

	$rows = CS50::query("SELECT transaction, time, symbol, shares, price FROM history WHERE user_id = ?",
						$_SESSION["id"]);

	render("history.php", ["title" => "History", "data" => $rows]);
?>