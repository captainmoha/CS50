<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // search database for places matching $_GET["geo"], store in $places

    $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST(? IN BOOLEAN MODE) AND (postal_code LIKE ? OR place_name LIKE ?) LIMIT 40", $_GET["geo"] . '*',
		$_GET["geo"]."%", $_GET["geo"]."%");

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>