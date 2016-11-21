<?php
	require("../includes/config.php");


	if ($_SERVER["REQUEST_METHOD"] == "GET")
	{
		render("buy_form.php", ["title" => "Buy"]);
	}

	else if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$symbol = $_POST["symbol"];

		$isStock = lookup($symbol);

		if ($isStock)
		{
			$shares = $_POST["shares"];
			if (preg_match("/^\d+$/", $shares))
			{
				$cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];
				$price = $isStock["price"] * $shares;

				if ($price <= $cash)
				{
					// insert new entery into portfolios. if it's there update the number of shares.
					CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $isStock["symbol"],
																	$shares);
					CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $price, $_SESSION["id"]);
					redirect("/");
				}

				else
				{
					apologize("You don't have enough money to buy these shares :(");
				}


			}

			else
			{
				apologize("Invalid number of shares.");
			}

		}
		else
		{
			apologize("Invalid stock symbol.");
		}

	}
?>