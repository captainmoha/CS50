<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<title>Frosh IMs</title>
	</head>
	<body>
		<?php
			session_start();
			if (isset($_SESSION["name"]))
			{
				print("<h1>You have already registered {$_SESSION["name"]} :)");
				exit(0);
			}
		?>
		<h1>Register for Frosh IMs</h1>

		<form action="register2.php" method="post">
			Name: <input name="name" type="text"/>
			<br>
			<input name="captain" type="checkbox"/> Captain?
			<br>
			<input name="gender" type="radio" value="F"/> Female
			<input name="gender" type="radio" value="M"/> Male
			<br>
			Dorm:
			<select name="dorm">
				<option value=""></option>
	            <option value="Apley Court">Apley Court</option>
	            <option value="Canaday">Canaday</option>
	            <option value="Grays">Grays</option>
	            <option value="Greenough">Greenough</option>
	            <option value="Hollis">Hollis</option>
	            <option value="Holworthy">Holworthy</option>
	            <option value="Hurlbut">Hurlbut</option>
	            <option value="Lionel">Lionel</option>
	            <option value="Matthews">Matthews</option>
	            <option value="Mower">Mower</option>
	            <option value="Pennypacker">Pennypacker</option>
	            <option value="Stoughton">Stoughton</option>
	            <option value="Straus">Straus</option>
	            <option value="Thayer">Thayer</option>
	            <option value="Weld">Weld</option>
	            <option value="Wigglesworth">Wigglesworth</option>
			</select>
			<br>
			<input type="submit" value="Register">
		</form>
	</body>
</html>