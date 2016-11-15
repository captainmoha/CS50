<?php
	
	// configuration
	require("../includes/config.php");

	// if the user reached the page via GET
	if ($_SERVER["REQUEST_METHOD"] == "GET")
	{
		render("../views/quote_form.php", ["title" => "Get Quote"]);
	}

	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{	
		if (empty($_POST["stock"]))
		{
			apologize("You did not enter a stock to get its quote!");
		}
		else
		{
			$quote = lookup($_POST["stock"]);

			if (!$quote)
			{
				apologize("You did not enter a valid quote symbol");
			}

			else
			{
				render("../views/quote.php",
					["title" => "Quote results", "symbol" => $quote["symbol"], "name" => $quote["name"], "price" => $quote["price"]]);

			}
		}
	}
?>