<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {   
        $username = $_POST["username"];
        $pass = $_POST["password"];
        $confirmPass = $_POST["confirmation"];

        if (empty($username))
        {
            apologize("Username cannot be empty!");
        }

        else if (empty($pass))
        {
            apologize("Password cannot be empty!");
        }

        else if ($pass != $confirmPass)
        {
            apologize("Password and confirmation don't match.");
        }

        else
        {   
            // insert user into database
            $wasInserted = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));

            // insertion failed
            if ($wasInserted == 0)
            {
                apologize("Username already exists!");
            }

            // insertion succeded
            else
            {   
                // get the id of the user
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];

                // log them in
                $_SESSION["id"] = $id;
                redirect("/");
            }
        }
    }

?>