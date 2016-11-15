<h3> Quote Details </h3>
<?php
	$newPrice = number_format($price, 4);
	print("<p> A share of {$name} ({$symbol}) costs <strong>\${$newPrice}</strong>.</p>");
?>