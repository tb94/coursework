<html>
<head>
   <title>Create new Quote</title>
</head>
<style>

</style>
<body>
   <center>
   <h1>Enter a New Quote</h1>
   <form action="send_quote.php" method="POST">
	<?php
		$id = $_POST['radio1'];
	?>
      <table>
         <tr>
            <td>Customer ID:</td>
				<td><?php echo "{$id}";?></td>
         </tr>
			<tr>
				<td>Salesperson:</td>
<?php
$servername = "blitz.cs.niu.edu";
$username = "student";
$password = "student";
$dbname = "csci467";

// Create connection
flush-hosts;
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}
$conn->set_charset("utf8");

$sql = "SELECT FirstName, UserID FROM SalesPerson";
$result = $conn->query($sql);
if ($result->num_rows > 0)
{
	Print "<td><select name="salesperson">";
	while($row = $result->fetch_assoc())
		Print "<option value=" . $row['UserID'] . ">" .$row['FirstName'] . "</option>"
}
$conn->close();

?>
				</select></td>
			</tr>
			<tr>
				<td>Quote:</td>
				<td><input type="text" name="price"></td>
			</tr>
			<tr>
				<td>E-mail:</td>
				<td><input type="text" name="email"></td>
			</tr>
			<tr>
				<td>Note:</td>
				<td><textarea name="note" rows="5"></textarea></td>
			</tr>
      </table>

		<input type="hidden" name="id" value="<?php echo $id;?>" />
      <input type="submit" value="Submit" /></td>
      <input type="reset" value="Clear Fields" /></td>
	</form>
</center>
</body>
</html>
