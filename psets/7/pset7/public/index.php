<?php

    // configuration
    require("../includes/config.php"); 


    if (isset($_SESSION["id"]))
    {
    	$rows = CS50::query("SELECT symbol, shares from portfolios WHERE user_id = ?", $_SESSION["id"]);

    	$cashArr = CS50::query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
    	$cash = $cashArr[0]["cash"];

    	$usernameArr = CS50::query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
    	$username = $usernameArr[0]["username"];
    }
    
    $positions = [];

    foreach($rows as $row)
    {
    	$stock = lookup($row["symbol"]);

    	if ($stock !== false)
    	{
    		$positions[] = [
    			"name" => $stock["name"],
    			"symbol" => $row["symbol"],
    			"shares" => $row["shares"],
    			"price" => $stock["price"]
    		];
    	}
    }
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions,
    						"cash" => $cash, "username"=> $username]);

?>
