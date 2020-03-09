/**
 * Provides methods and data fields to create an instance of a tool which is stored in the Inventory inventoryList array list which can be sold and
 * ordered through the store.
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public class Item {
	/**
	 * Unique id number for the type of tool Item
	 */
	private int id;
	/**
	 * String to hold the name of the tool
	 */
	private String name;
	/**
	 * quantity of Item tool
	 */
	private int quantity;
	/**
	 * price of Item tool
	 */
	private double price;
	/**
	 * id number of the Supplier object of the Tool item
	 */
	private int supplierId;
	/**
	 * Supplier object that supplies (association relationship with) the tool Item object
	 */
	private Supplier supplier;
	/**
	 * Contructor to set the member variables to the values received as arguments. 
	 * @param id Unique id number for the type of tool Item
	 * @param name String to hold the name of the tool
	 * @param quantity quantity of Item tool
	 * @param price price of Item tool
	 * @param supplierId id number of the Supplier object of the Tool item
	 */
	public Item(int id, String name, int quantity, double price, int supplierId) {
		this.id = id;
		this.name = name;
		this.quantity = quantity;
		this.price = price;
		this.setSupplierId(supplierId);
	}
	/**
	 * Sets the supplier member variable to the Supplier object obtained as an argument.
	 * @param supplier Supplier object to set the supplier member variable equal to
	 */
	public void setSupplier(Supplier supplier) {
		this.supplier = supplier;
	}
	/**
	 * retuns the value of id
	 * @return id
	 */
	public int getId() {
		return id;
	}
	/**
	 * sets the value of id to that of the integer it recieves in its arguments. 
	 * @param id Integer value of which to set member variable id equal to
	 */
	public void setId(int id) {
		this.id = id;
	}
	/**
	 * returns the name of the tool item
	 * @return name
	 */
	public String getName() {
		return name;
	}
	/**
	 * sets the name of the tool item to the String value taken in as an argument
	 * @param name String of which to set member variable name equal to
	 */
	public void setName(String name) {
		this.name = name;
	}
	/**
	 * Returns the quantity of the tool in inventory
	 * @return quantity
	 */
	public int getQuantity() {
		return quantity;
	}
	/**
	 * sets the quantity of tool in inventory
	 * @param quantity Integer value of which to set the member variable quantity
	 */
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	/**
	 * returns a String containing all the info for the tool
	 * @return String containing all the info for the tool
	 */
	public String toString() {
		return "\nID: " + id + "\nName: " + name + "\nPrice: " + price + "$\nQuantity: " + quantity + "\n";
	}
/**
 * returns the id of the Supplier object in which the tool Item is associated with
 * @return Integer value of the id of Supplier object 
 */
	public int getSupplierId() {
		return supplierId;
	}
/**
 * sets the id of the Supplier object in which the tool Item is associated with
 * @param supplierId Integer value of which to set the supplierId member variable equal to
 */
	public void setSupplierId(int supplierId) {
		this.supplierId = supplierId;
	}
	/**
	 * returns the name of the Supplier object in which the tool Item is associated with
	 * @return String name of Supplier object
	 */
	public String getSupplierName() {
		return supplier.getCompanyName();
	}
}
