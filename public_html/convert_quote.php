<html>
<head>
	<title>Convert Quote to Order</title>
</head>

<?php
// First Query
$servername = "students";
$username = "z1697841";
$password = "19941008";
$dbname = $username;
$quoteid = $_POST['ID'];

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

$sql = "SELECT * FROM Quote WHERE QuoteID = {$quoteid}";
$result = $conn->query($sql);
$customerID = $row['CustomerID'];
$price = $row['Price'];

$conn->close();

// Second Query
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

$sql = "SELECT * FROM customer WHERE id = {$customerID}";
$result = $conn->query($sql);
$customer = $row['name'];
$conn->close();

// UDP
$fp = fsockopen( "udp://blitz.cs.niu.edu", 4446, $errno, $errstr );
if (!$fp) die("$errstr ($errno)<br>");
$message = "{$quoteID}:{$customer}:{$price}";
echo "Sending: $message<br>";
fwrite( $fp, $message ) or die("write failed<br>");
$response = fread($fp, 1024);
echo "Received: $response<br>";
fclose($fp);

?>
</html>
