<html>
<head>
	<title>Quote Look-up Page</title>
</head>
<style>

</style>
<body>
	<center>
	<h1>Search for Quote</h1>
<?php
$servername = "students";
$username = "zID";
$password = "DoB";
$dbname = $username;

// Create connection
flush-hosts;
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully to: " . $servername;

/* change character set to utf8 */
$conn->set_charset("utf8");

$sql = "SELECT * FROM Quote WHERE Sanctioned = TRUE";
$result = $conn->query($sql);
if ($result->num_rows > 0)
{
	Print "<form action='convert_quote.php' method='POST'>";
	Print "<table>";
	Print "<tr>";
	Print "<th>Quote ID</th><th>Price</th><th>Customer ID</th><th>E-mail</th><th>Salesperson ID</th><th>Discount</th>";
	Print "</tr>";

	while($row = $result->fetch_assoc())
	{
		Print "<tr>";
		Print "<td>".$row['QuoteID']."</td>";
		Print "<td>".$row['Price']."</td>";
		Print "<td>".$row['CustomerID']."</td>";
		Print "<td>".$row['Email']."</td>";
		Print "<td>".$row['UserID']."</td>";
		Print "<td>".$row['Discount']."</td>";
		Print "<td><input type='radio' name='ID' value='".$row['QuoteID']."' /></td></tr>";
	}
	Print "</table>";
	Print "<input type='submit' value='submit'/>";
}
else
{
	Print "0 records found";
}
$conn->close();
?>
</center>
</body>
</html>
