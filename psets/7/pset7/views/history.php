<div id="history_table">
	<table class="table table-hover">
		<thead>
			<tr>
				<th class="text-center">Transaction</th>
				<th class="text-center">Date/Time</th>
				<th class="text-center">Symbol</th>
				<th class="text-center">Shares</th>
				<th class="text-center">Price</th>

			</tr>
		</thead>

		<tbody>
			<?php
				if (count($data) > 0)
				{
					foreach($data as $datum)
		    		{	
		    			$transaction = $datum["transaction"] ? "BUY" : "SELL";
		    			print("<tr>");
		    			print("<td>{$transaction}</td>");
		    			print("<td>{$datum["time"]}</td>");
		    			print("<td>{$datum["symbol"]}</td>");
		    			print("<td>{$datum["shares"]}</td>");
		    			print("<td>{$datum["price"]}</td>");
		    			print("</tr>");
		    		}
				}
				
				else
				{
					print("<h2>You haven't made any transactions yet. Go buy something!</h2>");
				}
			?>
		</tbody>
    </table>
</div>
