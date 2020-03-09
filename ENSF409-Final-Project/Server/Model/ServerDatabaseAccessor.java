package Server.Model;

import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 *  This class controls the MySQL database being used to
 *  store and access details for the users, suppliers, and items
 *  associated with the shop
 *  @author Colton Osterlund
 */
public class ServerDatabaseAccessor {
	/**
	 * Connection object to initiate connected to the MySQL database
	 */
	private Connection dbConnection;
	/**
	 * String that composes the order and is returned to the client to be printed to a .txt file when prompted
	 */
	private String orderFile = "ORDERS\n**********\n";
	/**
	 * DateTimeFormatter object to get the current date and time
	 */
	private DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

	/**
	 * This method runs the getConnection method to set a connection to the MySQL
	 * database being used in the project
	 */
	public ServerDatabaseAccessor() {
		this.getConnection();
	}

	/**
	 * This method sets a database connection by instantiating the Connection object
	 * dbConnection to the connection received by the DriverManager getConnection
	 * method and the indicated URL
	 */
	public void getConnection() {
		try {
			// Class.forName("ServerDatabaseController");
			dbConnection = DriverManager.getConnection("jdbc:mysql://localhost:3306/iteminventory", "root",
					"Gmcia330@");
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}
	
	
	/**
	 * This method returns the order line when an order is exported from the clerk frame
	 * @return String representing the order from the clerk frame is returned
	 */
	public String getOrderFile() {
		String toReturn = orderFile;
		
		orderFile = new String("ORDERS\n**********\n"); //resetting orderFile after you export it
		
		return toReturn;
	} 
	

	/**
	 * This method searches through the database using a prepared statement to find
	 * the item with the name given by the user, set to the name parameter. Returns
	 * the details of said item if found. Else, returns an empty string
	 * 
	 * @param name String set by user that is used to search the database for an
	 *             item with a matching name
	 * @return Returns a string containing the details of the item if found. If not,
	 *         returns an empty string
	 */
	public String querySearchByName(String name) {
		String query = "SELECT * FROM ITEM WHERE name = ?";
		String toReturn = "";

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			ResultSet rs;
			pStat.setString(1, name);
			rs = pStat.executeQuery();
			if (rs.next()) {
				toReturn += "Item ID: ";
				toReturn += rs.getString("id");
				toReturn += "\n";
				toReturn += "Item Name: ";
				toReturn += rs.getString("name");
				toReturn += "\n";
				toReturn += "Item Quantity: ";
				toReturn += rs.getString("quantity");
				toReturn += "\n";
				toReturn += "Item Price ($): ";
				toReturn += rs.getString("price");
				toReturn += "\n";
				toReturn += "Supplier ID: ";
				toReturn += rs.getString("supplierID");
				toReturn += "\n";
			}

			pStat.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return toReturn;
	}

	/**
	 * This method searches the database for an item matching a specific id. If
	 * found, the details of this item are returned as a string. Else, an empty
	 * string is returned
	 * 
	 * @param ID Id being searched for in the database. Set by user
	 * @return If found, returns a string containing the details of the item
	 *         matching the id. Else, returns a blank string
	 */
	public String querySearchById(String ID) {
		String query = "SELECT * FROM ITEM WHERE id = ?";
		String toReturn = "";

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			ResultSet rs;
			pStat.setString(1, ID);
			rs = pStat.executeQuery();
			if (rs.next()) {
				toReturn += "Item ID: ";
				toReturn += rs.getString("id");
				toReturn += "\n";
				toReturn += "Item Name: ";
				toReturn += rs.getString("name");
				toReturn += "\n";
				toReturn += "Item Quantity: ";
				toReturn += rs.getString("quantity");
				toReturn += "\n";
				toReturn += "Item Price ($): ";
				toReturn += rs.getString("price");
				toReturn += "\n";
				toReturn += "Supplier ID: ";
				toReturn += rs.getString("supplierID");
				toReturn += "\n";
			}

			pStat.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return toReturn;
	}
	
	/**
	 * This method adds a new user to the user table in the database. The user details are set to the Strings in 
	 * the parameters
	 * @param username Username of the user being added to the database
	 * @param password Password of the user being added to the database
	 * @param email Email of the user being added to the database
	 * @param accountType Account type of the user being added to the database
	 * @return Returns a success message if the username is free to use, and an error message if not
	 */
	public synchronized String queryAddUser(String username, String password, String email, String accountType) {
		String query = "SELECT * FROM USER WHERE username = ?";
		String toReturn = null;
		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, username);
			ResultSet rs = pStat.executeQuery();
			
			if(rs.next()) 
				toReturn = "Username Already Exists";
				
			pStat.close();
		}catch(SQLException e) {
			e.printStackTrace();
		}
			
		if(toReturn != null)
			return toReturn;
			
		
		query = "INSERT INTO USER (username, password, email, userType) values (?,?,?, ?)";
		
		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, username);
			pStat.setString(2, password);
			pStat.setString(3, email);
			pStat.setString(4, accountType);
			pStat.executeUpdate();
			pStat.close();
		}catch(SQLException e) {
			e.printStackTrace();
		}
		
		return "Successfully Added User";
	}
	
	
	/**
	 * This method returns the password of the user indicated by the username in the parameter
	 * @param username The username used to identify the user whose password will be returned
	 * @return The password of the indicated user
	 */
	public String queryReturnEmailPassword(String username) {
		String query = "SELECT * FROM USER WHERE username = ?";
		String toReturn = "";
		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, username);
			ResultSet rs = pStat.executeQuery();
			
			if(!rs.next()) 
				toReturn += "Username Does Not Exist";
			else {
				toReturn += rs.getString("email");
				toReturn += "\n";
				toReturn += rs.getString("password");
			}
				
			pStat.close();
		}catch(SQLException e) {
			e.printStackTrace();
		}
		
		
		return toReturn;
	}
	
	
	/**
	 * This method validates the user indicated by the parameters if such a user exists in the database
	 * @param username Username of the user being validated in the database
	 * @param password Password of the user being validated in the database
	 * @return
	 */
	public String queryValidateUser(String username, String password) {
		String query = "SELECT * FROM USER WHERE username = ? AND password = ?";
		String toReturn = null;
		
		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, username);
			pStat.setString(2, password);
			ResultSet rs = pStat.executeQuery();
			
			if(rs.next())
				toReturn = "Valid\n" + rs.getString("userType");
			else
				toReturn ="Invalid Userame or Password"; 
			
			pStat.close();
		}catch(SQLException e) {
			e.printStackTrace();
		}
				
		return toReturn;
	}

	/**
	 * This method adds an item to the database/shop. The details for the new item
	 * are set by the user through a prepared statement, and are supplied to the
	 * method as arguments. Returns a string containing the details of the new item
	 * added to the database, along with all items already in the database
	 * 
	 * @param itemID       Id of the item being added to the database
	 * @param itemName     Name of the item being added to the database
	 * @param itemQuantity Quantity of the item being added to the database
	 * @param itemPrice    Price of the item being added to the database
	 * @param supplierID   Supplier id of the item being added to the database
	 * @return String containing new item details
	 */
	public synchronized String queryAddItem(String itemID, String itemName, String itemQuantity, String itemPrice,
			String supplierID) {
		String query = "INSERT INTO ITEM (id, name, quantity, price, supplierID) values (?,?,?,?,?)";

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, itemID);
			pStat.setString(2, itemName);
			pStat.setString(3, itemQuantity);
			pStat.setString(4, itemPrice);
			pStat.setString(5, supplierID);
			pStat.executeUpdate();
			pStat.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return queryListAll();
	}

	/**
	 * This method removes an item from the shop, and therefore the database.
	 * Returns a string containing all items in the database, with the exception of
	 * the item being removed. If no item matches the id, no change is made to the
	 * database/shop
	 * 
	 * @param itemID Id of the item being removed from the shop and database
	 * @return Returns a string containing all the remaining items in the
	 *         database/shop
	 */
	public synchronized String queryRemoveItem(String itemID) {
		System.out.println(itemID);

		String query = "DELETE FROM ITEM WHERE id = ?";

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, itemID);
			pStat.executeUpdate();
			pStat.close();

		} catch (SQLException e) {
			e.printStackTrace();
		}

		return queryListAll();
	}

	/**
	 * This method reads through the database and places every item row (including
	 * item details) into a string line by line. Each string is then joined together
	 * with a new line character in between separate fields, then returned all
	 * together. The client method then correctly formats the string
	 * 
	 * @return Item details for every item is put into a string and returned
	 */
	public String queryListAll() {
		ArrayList<String> toPrint = new ArrayList<String>();

		try {
			Statement findItemFields = dbConnection.createStatement();
			ResultSet itemResultSet = findItemFields.executeQuery("SELECT * FROM ITEM");

			while (itemResultSet.next()) {
				toPrint.add(itemResultSet.getString("id"));
				toPrint.add(itemResultSet.getString("name"));
				toPrint.add(itemResultSet.getString("quantity"));
				toPrint.add(itemResultSet.getString("price"));
				toPrint.add(itemResultSet.getString("supplierID"));

				Statement findSupplierName = dbConnection.createStatement();
				ResultSet supplierResultSet = findSupplierName.executeQuery(
						"SELECT companyName FROM SUPPLIER WHERE supplierID = " + toPrint.get(toPrint.size() - 1));
				if (supplierResultSet.next())
					toPrint.add(supplierResultSet.getString("companyName"));
				findSupplierName.close();
			}

			findItemFields.close();

		} catch (SQLException e) {
			e.printStackTrace();
		}

		String toReturn = "";
		for (String s : toPrint) {
			toReturn += s;
			toReturn += "\n";
		}

		return toReturn;
	}

	/**
	 * This method simulates purchasing an item by reducing the quantity of the item
	 * by one in the database. The item being purchased is indicated by the item ID
	 * parameter. The new, modified item details are again put into the queryListAll
	 * method and returned
	 * 
	 * @param itemID id of the item being purchased
	 * @return String containing modified item details
	 */
	public synchronized String queryBuyItem(String itemID) {
		String query = "SELECT * FROM ITEM WHERE id = ?";
		String toModify = null;

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			ResultSet rs;
			pStat.setString(1, itemID);
			rs = pStat.executeQuery();
			if (rs.next()) {
				toModify = rs.getString("quantity");
				if(Integer.parseInt(toModify) < 40) {
					orderFile += "\n" + dateFormat.format(LocalDateTime.now()).toString() + "\n" + "Name: " + rs.getString("name") + "\nID: " + rs.getString("id")
									+ "\n" + "Requested Shipment: " + (50 - Integer.parseInt(toModify)) + "\n";
				}
			}
				

			pStat.close();

			if (toModify == null)
				return queryListAll();
			

			int quantity = Integer.parseInt(toModify);
			
			if(quantity == 0)
				return "This Item is Not Currently in Stock\n";
			
			quantity--;
			String toUpdate = Integer.toString(quantity);

			query = "UPDATE ITEM SET quantity = ? WHERE id = ?";
			pStat = dbConnection.prepareStatement(query);
			pStat.setString(1, toUpdate);
			pStat.setString(2, itemID);
			pStat.executeUpdate();

		} catch (SQLException e) {
			e.printStackTrace();
		}
		

		return "In Stock\n" + queryListAll();
	}
	
	
	/**
	 * This method will return the price for the item in the database that matches the id
	 * in the parameters of the method
	 * @param id ID of item being searched for in database
	 * @return Price of item that matches parameter is returned
	 */
	public String queryGetItemPrice(String id) {
		String query = "SELECT * FROM ITEM WHERE id = ?";
		String toReturn = "";

		try {
			PreparedStatement pStat = dbConnection.prepareStatement(query);
			ResultSet rs;
			pStat.setString(1, id);
			rs = pStat.executeQuery();
			if (rs.next())
				toReturn += rs.getString("price");

			pStat.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return toReturn;
	}
	
	/**
	 * This method returns the orderFile for the clerk order by calling the getOrderFile method
	 * @return String representing ordered items for the clerk
	 */
	public String returnOrder() {
		return getOrderFile();
	}
	

	/**
	 * This method initializes the database and sets the columns and primary keys for
	 * all three database tables
	 */
	public void initializeDatabase() {
		try {
			Statement statement = dbConnection.createStatement();
			statement.executeUpdate(

					"CREATE TABLE SUPPLIER" + "(supplierID VARCHAR(225) not NULL, " + "companyName VARCHAR(225), "
							+ "address VARCHAR(225), " + "ownerName VARCHAR(225), " + " PRIMARY KEY ( supplierID ))"

			);
			statement.close();

			statement = dbConnection.createStatement();
			statement.executeUpdate(

					"CREATE TABLE ITEM " + "(id VARCHAR(225) not NULL, " + "name VARCHAR(225), "
							+ "quantity VARCHAR(225), " + "price VARCHAR(225), " + "supplierID VARCHAR(225), "
							+ " PRIMARY KEY ( id ), "
							+ " FOREIGN KEY ( supplierID ) REFERENCES SUPPLIER ( supplierID ))"

			);

			statement.close();

			statement = dbConnection.createStatement();
			statement.executeUpdate(

					"CREATE TABLE USER" + "(username VARCHAR(225) not NULL, " + "password VARCHAR(225), "
							+ "email VARCHAR(225), " + "userType VARCHAR(225), " + " PRIMARY KEY ( username ))"

			);
			statement.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	/**
	 * This method closes the connection between the database controller and the
	 * MySQL database
	 */
	public void closeConnection() {
		try {
			dbConnection.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	/**
	 * This method loads the suppliers from the text file and inserts them into the
	 * suppliers table found in the MySQL database
	 */
	public void loadSuppliers() {
		try {

			Scanner supplierFileReader = new Scanner(new File("suppliers.txt"));
			supplierFileReader.useDelimiter(";|\\n");
			String[] supplierValues = new String[4];
			while (supplierFileReader.hasNext()) {
				for (int i = 0; i < 4; i++)
					supplierValues[i] = supplierFileReader.next().trim();

				String query = "INSERT INTO SUPPLIER (supplierID, companyName, address, ownerName) values (?,?,?,?)";
				PreparedStatement pStat = dbConnection.prepareStatement(query);
				pStat.setString(1, supplierValues[0]);
				pStat.setString(2, supplierValues[1]);
				pStat.setString(3, supplierValues[2]);
				pStat.setString(4, supplierValues[3]);
				pStat.executeUpdate();
				pStat.close();

			}

			supplierFileReader.close();

		} catch (SQLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	/**
	 * This method loads the items from the text file and inserts them into the
	 * items table found in the MySQL database
	 */
	public void loadItems() {

		try {

			Scanner itemFileReader = new Scanner(new File("items.txt"));
			itemFileReader.useDelimiter(";|\\n");
			String[] itemValues = new String[5];
			while (itemFileReader.hasNext()) {
				for (int i = 0; i < 5; i++)
					itemValues[i] = itemFileReader.next().trim();

				String query = "INSERT INTO ITEM (id, name, quantity, price, supplierID) values (?,?,?,?,?)";
				PreparedStatement pStat = dbConnection.prepareStatement(query);
				pStat.setString(1, itemValues[0]);
				pStat.setString(2, itemValues[1]);
				pStat.setString(3, itemValues[2]);
				pStat.setString(4, itemValues[3]);
				pStat.setString(5, itemValues[4]);
				pStat.executeUpdate();
				pStat.close();

			}

			itemFileReader.close();

		} catch (SQLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
 
	/**
	 * This is the main method of the class which will initialize the database, then load the text file data
	 * into their respective tables in the database. This method only gets run once on a new machine to set up the database then is 
	 * never run again. Comment out this method once ran to ensure that it will not be run a second time. 
	 * @param args Command line arguments
	 */
	public static void main(String[] args) { // only run this method once on the computer running the database!
		ServerDatabaseAccessor servDBControl = new ServerDatabaseAccessor();
		servDBControl.initializeDatabase();
		servDBControl.loadSuppliers();
		servDBControl.loadItems();
		servDBControl.closeConnection();
		System.out.println("successful database build");
	}
}
