import java.util.ArrayList;
/**
 * Provides member variables and methods to create a Supplier responsible for supplying Item objects (tools) to the inventory.
 * @author Colton Osterlund
 * @version 1.0
 * @Since February 5th, 2019
 *
 */
public class Supplier {
	/**
	 * unique identification number for each supplier
	 */
	private int id;
	/**
	 * Company name of the supplier
	 */
	private String companyName;
	/**
	 * Address of the supplier
	 */
	private String address;
	/**
	 * Name of person who runs the company to contact
	 */
	private String contactName;
	/**
	 * ArrayList of type Item containing all the tools that the supplier provides to the inventory
	 */
	private ArrayList<Item> itemList = new ArrayList<Item>();
	
	/**
	 * Constructor to assign all member variables to the values of the arguments received by the method
	 * @param id set to member variable id
	 * @param companyName set to member variable companyName
	 * @param address set to member variable address
	 * @param contactName set to member variable contactName
	 */
	public Supplier(int id, String companyName, String address, String contactName) {
		this.setId(id);
		this.setCompanyName(companyName);
		this.address = address;
		this.contactName = contactName;
	}

/**
 * returns the value of id
 * @return id
 */
	public int getId() {
		return id;
	}

/**
 * sets the value of id
 * @param id Integer to which to set the value of the member variable id
 */
	public void setId(int id) {
		this.id = id;
	}
	
	/**
	 * adds new Item object to the itemList array list
	 * @param item Item object to add to the array list
	 */
	public void setNewTool(Item item) {
		itemList.add(item);
	}

/**
 * returns String companyName
 * @return companyName 
 */
	public String getCompanyName() {
		return companyName;
	}

/**
 * sets String companyName
 * @param companyName String with which to set the value of the member variable companyName
 */
	public void setCompanyName(String companyName) {
		this.companyName = companyName;
	}
}
