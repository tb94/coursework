<html>
<head>
	<title>Send Quote to Internal Database</title>
</head>
<body>

<?php

$servername = "students";
$username = "z1697841";
$password = "19941008";
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

$sql = "UPDATE Quote
		SET Discount={$_POST['discount']}
		WHERE CustomerID={$_POST['customerid']}"

if ($conn->query($sql) === TRUE)
{
	echo "<br>Sanctioned successfully";
}
else
{
	echo "<br>Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

?>
</body>
</html>
