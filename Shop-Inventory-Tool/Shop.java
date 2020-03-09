import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Scanner;
/**
 * Provides data fields and methods to create a Shop, which owns/has an aggregation
 * to classes Inventory, Supplier and Order, and has the responsibility of filtering
 * and directing all user requests from the front end console interface.
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public class Shop {

	/**
	 * Instance of class Inventory owned by the Shop
	 */
	private Inventory inv;
	/**
	 * Array list of instances of class Supplier all owned by the Shop
	 */
	private ArrayList<Supplier> supplierList;
	/**
	 * Date to be checked when creating and processing orders
	 */
	private String date;
	/**
	 * Array list of instances of class Order all with a unique order date.
	 */
	private ArrayList<Order> orderList; 
	
	/**
	 * Initializes the member variables to the arguments taken in by the constructor
	 * as well as initializes the orderList member variable with a new array list
	 * to be supplied with instances of class Order
	 * @param inv Instance of class Inventory
	 * @param supplierList Array list filled with instances of class Supplier
	 */
	Shop(Inventory inv, ArrayList<Supplier> supplierList){
		this.inv = inv;
		this.supplierList = supplierList;
		orderList = new ArrayList<Order>();
	}
	
	/**
	 * Adds an item to the stores Inventory object.
	 * @param tool Item to be added to the inventory.
	 */
	public void addTool(Item tool) {
		inv.addTool(tool);
	}
	
	/**
	 * Removes an item from the stores inventory object by calling the deleteTool(tool)
	 * method of Inventory.
	 * @param tool Item to be removed from inventory after sending it 
	 */
	public void removeTool(Item tool) {
		inv.deleteTool(tool);
	}
	
	/**
	 * Searches the stores inventory to find an Item with a name matching
	 * the string taken in as an argument by calling the findTool(name) method from
	 * an instance of class Inventory.
	 * @param name String to search inventory for Item object with matching name to be sent
	 * into the findTool(name) method of Inventory.
	 * @return Item object with matching name if found in the inventory, or null if
	 * no Item objects with matching names were found.
	 */
	public Item findTool(String name) {
		return inv.findTool(name);
	}
	/**
	 * Searches the stores inventory to find an Item with an id matching
	 * the integer taken in as an argument by calling the findTool(id) method from
	 * an instance of class Inventory.
	 * @param name Integer to search inventory for Item object with matching id to be sent
	 * into the findTool(id) method of Inventory.
	 * @return Item object with matching id if found in the inventory, or null if
	 * no Item objects with matching id's were found.
	 */
	public Item findTool(int id) {
		return inv.findTool(id);
	}
	
	/**
	 * Prints all objects in the inventory to the console by calling the listAllTools()
	 * method from an instance of class Inventory.
	 */
	public void listAllTools() {
		inv.listAllTools();
	}
	
	/**
	 * Decreases the quantity of the selected Item object in the inventory, checks if
	 * the quantity of the selected Item object goes below 40 and initializes the order process 
	 * if this case is true.
	 * @param tool Item object to be bought
	 * @throws IOException
	 */
	public void buyItem(Item tool) throws IOException {
		if(inv.buyItem(tool) < 40) {
			date = new SimpleDateFormat("MMM dd, yyyy").format(Calendar.getInstance().getTime()); 
			
			if(orderList.size() == 0) {//if there has been no previous orders placed yet
				orderList.add(new Order(date));
				orderList.get(orderList.size() - 1).writeNewOrderLine(tool);
			}
			else if(!orderList.get(orderList.size() - 1).getDate().contentEquals(date)) { //if it is a new day since the previous order was placed in the list
				orderList.add(new Order(date));
				orderList.get(orderList.size() - 1).writeNewOrderLine(tool);
			}
			else //if the last order in the list was made on the same day ie no new order needs to be created - use the order already created for the day
				orderList.get(orderList.size() - 1).writeNewOrderLine(tool);
			
		}
	}
	
	/**
	 * Returns the quantity of the Item object taken in as an argument by calling
	 * the method getToolQuantity(tool).
	 * @param tool Item object in which you are returning the quantity of by sending it as
	 * an argument to the getToolQuantity(tool) method of an instance of class Inventory.
	 * @return quantity of the Item object taken in as an argument. 
	 */
	public int getToolQuantity(Item tool){
		return inv.getToolQuantity(tool);
	}
	
	/**
	 * Prints all the Item objects info to the console by calling printToolInfo(tool)
	 * method from an instance of class Inventory.
	 * @param tool Item order to be sent to the printToolInfo(tool) method of an instance
	 * of class Inventory to have its info printed to the console. 
	 */
	public void printToolInfo(Item tool) {
		inv.printToolInfo(tool);
	}
	
}
