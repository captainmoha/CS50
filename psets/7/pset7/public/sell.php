<?php
	
	// config
	require("../includes/config.php");

	// if the user got here to sell
	if ($_SERVER["REQUEST_METHOD"] == "GET")
	{	
		// Get the stocks the user currently owns and pass along the title to render the form
		$rows = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
		if (count($rows) < 1)
		{
			apologize("Nothing to sell!");
		}

		render("sell_form.php", ["title" => "Sell", "ownedStocks" => $rows]);
	}

	// if the user got here after submiting the selling form
	else if ($_SERVER["REQUEST_METHOD"] == "POST")
	{	
		// make sure that user has selected something
		$userInp = isset($_POST["symbol"]) ? $_POST["symbol"] : false;

		//  if the user has selected a valid stock
		if ($userInp)
		{	
			// query the number of shares the user has of the selected stock
			$rows = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?",
								 $_SESSION["id"], $userInp);

			// lookup the price of the stock on yahoo finance
			$sharePrice = lookup($userInp)["price"];

			// calculate the total price
			$totalPrice = $sharePrice * $rows[0]["shares"];

			// sell the stock ie: delete its entry from the database

			$sellStock = CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?",
									 $_SESSION["id"], $userInp);

			// update user's cash
			$cashIn = CS50::query("UPDATE users SET cash = cash + $totalPrice WHERE id = ?", $_SESSION["id"]);

			// go back to the root
			redirect("/");
		}

		else
		{
			apologize("You must select a stock to sell!");
		}
	}
?>