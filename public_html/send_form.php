<!DOCTYPE html">
<html>
<head>
	<title>CSCI467/567 Access to Legacy Database Test Page</title>
</head>
<body>
<h3>Customer Database Content</h3>

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
echo "Connected successfully to: " . $servername;

/* change character set to utf8 */
$conn->set_charset("utf8");

// Collects data from "customers" table
$name = $_POST["Cname"];
$sql = "SELECT * FROM customers WHERE name LIKE '%$name%'";
$result = $conn->query($sql);
if ($result->num_rows > 0)
{
	// print header
   Print "<form action='new_quote.php' method='POST'>";
	Print "<table border>";
	Print "<tr>";
	Print "<th>Id</th><th>Name</th><th>City</th><th>Street</th><th>Contact</th><th> </th>";
	Print "</tr>";
	while($row = $result->fetch_assoc())
	{
		Print "<tr>";
		Print "<td>".$row['id'] . "</td> ";
		Print "<td>".$row['name'] . " </td>";
		Print "<td>".$row['city'] . " </td>";
		Print "<td>".$row['street'] . " </td>";
		Print "<td>".$row['contact'] . " </td>";
		Print "<td><input type='radio' name='radio1' value='".$row['id']."' /></td></tr>";
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
</body>
</html>
