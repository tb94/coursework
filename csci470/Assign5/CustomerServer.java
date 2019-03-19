import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;

public class CustomerServer extends Thread {
    private ServerSocket listenSocket;

    public static void main(String args[]) {
        new CustomerServer();
    }

    private CustomerServer() {
        int port = 9713;

        try {
            listenSocket = new ServerSocket(port);
        } catch (IOException e) {
            System.err.println("Exception creating server socket: " + e);
            System.exit(1);
        }

        System.out.println("LOG: Server listening on port " + port);
        this.start();
    }

    /**
     * run()
     * The body of the server thread. Loops forever, listening for and
     * accepting connections from clients. For each connection, create a
     * new Conversation object to handle the communication through the
     * new Socket.
     */

    public void run() {
        try {
            while (true) {
                Socket clientSocket = listenSocket.accept();

                System.out.println("LOG: Client connected");

                // Create a Conversation object to handle this client and pass
                // it the Socket to use.  If needed, we could save the Conversation
                // object reference in an ArrayList. In this way we could later iterate
                // through this list looking for "dead" connections and reclaim
                // any resources.
                new Conversation(clientSocket);
            }
        } catch (IOException e) {
            System.err.println("Exception listening for connections: " + e);
        }
    }
}

/**
 * The Conversation class handles all communication with a client.
 */
class Conversation extends Thread {

    private Socket clientSocket;
    private ObjectInputStream objectIn;
    private ObjectOutputStream objectOut;
    private BufferedReader reader;
    private PrintWriter writer;

    // Where JavaCustXX is your database name
    private static final String URL = "jdbc:mysql://courses:3306/JavaCust17";

    private Statement getAllStatement = null;
    private PreparedStatement addStatement = null;
    private PreparedStatement deleteStatement = null;
    private PreparedStatement updateStatement = null;

    /**
     * Constructor
     * <p>
     * Initialize the streams and start the thread.
     */
    Conversation(Socket socket) {
        clientSocket = socket;

        try {
            objectIn = new ObjectInputStream(clientSocket.getInputStream());
            objectOut = new ObjectOutputStream(clientSocket.getOutputStream());
            writer = new PrintWriter(clientSocket.getOutputStream(), true);
            reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            System.out.println("LOG: Streams opened");
        } catch (IOException e) {
            try {
                clientSocket.close();
            } catch (IOException e2) {
                System.err.println("Exception closing client socket: " + e2);
            }

            System.err.println("Exception getting socket streams: " + e);
            return;
        }

        try {
            System.out.println("LOG: Trying to create database connection");
            Connection connection = DriverManager.getConnection(URL);

            // Create your Statements and PreparedStatements here
            getAllStatement = connection.createStatement();
            addStatement = connection.prepareStatement
                    ("INSERT INTO customer (name, ssn, address, zipCode) VALUES (?, ?, ?, ?)");
            deleteStatement = connection.prepareStatement
                    ("DELETE FROM customer (name, ssn, address, zipCode) WHERE name = ?");
            updateStatement = connection.prepareStatement
                    ("UPDATE cust SET name = ?, address = ?, zipCode = ? WHERE ssn = ?");


            System.out.println("LOG: Connected to database");

        } catch (SQLException e) {
            System.err.println("Exception connecting to database manager: " + e);
            return;
        }

        // Start the run loop.
        System.out.println("LOG: Connection achieved, starting run loop");
        this.start();
    }

    /**
     * run()
     * <p>
     * Reads and processes input from the client until the client disconnects.
     */
    public void run() {
        System.out.println("LOG: Thread running");

        try {
            while (true) {
                // Read and process input from the client.
                String s = objectIn.readUTF();
                System.out.println("LOG: Attemting to " + s);
                switch (s) {
                    case "Create":
                        handleAdd((Customer) objectIn.readObject());
                        break;
                    case "Read":
                        handleGetAll();
                        break;
                    case "Update":
                        handleUpdate((Customer) objectIn.readObject());
                        break;
                    case "Delete":
                        handleDelete((Customer) objectIn.readObject());
                        break;
                }
            }
        } catch (IOException e) {
            System.err.println("IOException: " + e);
            System.out.println("LOG: Client disconnected");
        } catch (SQLException e) {
            System.err.println("SQLException: " + e);
            System.out.println("LOG: Fix your SQL shit");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                System.err.println("Exception closing client socket: " + e);
            }
        }
    }

    private void handleGetAll() throws SQLException, IOException {
        System.out.println("LOG: Executing Query");
        ResultSet resultSet = getAllStatement.executeQuery("SELECT * FROM customer");

        while (resultSet.next()) {
            objectOut.writeUTF("Name: " + resultSet.getString(1) + " SSN: " + resultSet.getString("ssn"));
        }
        objectOut.writeUTF("END");
        objectOut.flush();

        try {
            getAllStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void handleAdd(Customer clientMsg) throws SQLException {
        System.out.println("LOG: Add " + clientMsg);

        addStatement.setString(1, clientMsg.getName());
        addStatement.setString(2, clientMsg.getSsn());
        addStatement.setString(3, clientMsg.getAddress());
        addStatement.setString(4, clientMsg.getZipCode());

        ResultSet result = addStatement.executeQuery();
    }

    private void handleDelete(Customer clientMsg) throws SQLException {
        System.out.println("LOG: Delete " + clientMsg);

        deleteStatement.setString(1, clientMsg.getName());

        ResultSet result = deleteStatement.executeQuery();
    }

    private void handleUpdate(Customer clientMsg) throws SQLException {
        System.out.println("LOG: Modify " + clientMsg);

        updateStatement.setString(1, clientMsg.getName());
        updateStatement.setString(2, clientMsg.getAddress());
        updateStatement.setString(3, clientMsg.getZipCode());
        updateStatement.setString(4, clientMsg.getSsn());
    }
}
class Customer {
        private String name;
        private String ssn;
        private String address;
        private String zipCode;

        public Customer() {
            name = "";
            ssn = "";
            address = "";
            zipCode = "";
        }

        public Customer(String name, String ssn, String address, String zipCode) {
            this.name = name;
            this.ssn = ssn;
            this.address = address;
            this.zipCode = zipCode;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getSsn() {
            return ssn;
        }

        public void setSsn(String ssn) {
            this.ssn = ssn;
        }

        public String getAddress() {
            return address;
        }

        public void setAddress(String address) {
            this.address = address;
        }

        public String getZipCode() {
            return zipCode;
        }

        public void setZipCode(String zipCode) {
            this.zipCode = zipCode;
        }
    }
