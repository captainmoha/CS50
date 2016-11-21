<div>
	<form action="sell.php" method="post" class="form-horizontal">
		<div class="form-group">
			<select name="symbol" class="form-control">
				<option disabled="" selected="" value="">Symbol</option>
				<?php
					foreach ($ownedStocks as $stock)
					{	
						$price = lookup($stock["symbol"])["price"] * $stock["shares"];
						print("<option value=\"{$stock["symbol"]}\">{$stock["symbol"]} -- \${$price}</option>");
					}
				?>
			</select>
		</div>

		<div class="form-group">
			<button type="submit" class="btn btn-primary">
				<span aria-hidden="true" class="glyphicon glyphicon-usd"></span>
				Sell
			</button>
		</div>
	</form>
</div>
