<?php
	require("../includes/config.php");

	if ($_SERVER["REQUEST_METHOD"] == "GET")
	{
		render("password_form.php", ["title" => "Change Password"]);
	}

	else if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		if (empty($_POST["password"]) || empty($_POST["password2"]))
		{
			apologize("You need to fill both password fields.");
		}

		else if ($_POST["password"] != $_POST["password2"])
		{
			apologize("Passwords don't match.");
		}

		else
		{
			CS50::query("UPDATE users SET hash = ? WHERE id = ?",
						password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
			redirect("/");
		}
	}
?>