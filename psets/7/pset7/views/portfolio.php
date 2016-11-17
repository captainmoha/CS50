<div id="user_section">
    <?php
    	print("<h1>Welcome back <strong>{$username}</strong>!</h1>");
    	print("<h3>Current cash: <strong>{$cash}</strong></h1>");
    ?>
</div>

<br>

<div id="data_table">
	<table class="table table-hover">
		<thead>
			<tr>
				<th class="text-center">Company Name</th>
				<th class="text-center">Symbol</th>
				<th class="text-center">Shares</th>
				<th class="text-center">Price</th>

			</tr>
		</thead>

		<tbody>
			<?php
				if (count($positions) > 0)
				{
					foreach($positions as $position)
		    		{
		    			print("<tr>");
		    			print("<td>{$position["name"]}</td>");
		    			print("<td>{$position["symbol"]}</td>");
		    			print("<td>{$position["shares"]}</td>");
		    			print("<td>{$position["price"]}</td>");
		    			print("</tr>");
		    		}
				}
				
				else
				{
					print("<h5>You don't own any shares at the moment. Go buy some!</h5>");
				}
			?>
		</tbody>
    </table>
</div>
