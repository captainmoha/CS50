<div>
	<form action="sell.php" method="post" class="form-horizontal">
		<div class="form-group">
			<select name="symbol" class="form-control">
				<option disabled="" selected="" value="">Symbol</option>
				<?php
					foreach ($ownedStocks as $stock)
					{
						print("<option value=\"{$stock["symbol"]}\">{$stock["symbol"]}</option>");
					}
				?>
			</select>
		</div>

		<div class="form-group">
			<button type="submit" class="btn btn-primary"> Sell</button>
		</div>
	</form>
</div>
