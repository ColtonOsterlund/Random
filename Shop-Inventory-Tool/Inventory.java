import java.util.ArrayList;
/**
 * Provides data field and methods to organize and work with an inventory list of instances of the Item class. 
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 */
public class Inventory implements Constants{
/**
 * Array list to fill with instances of class Item to keep track of the stores tool inventory.
 */
	private ArrayList<Item> toolInventory;
	
	/**
	 * Constructor to initialize the inventory array list which is sent in as an argument.
	 * @param tools Array list filled with instances of class Item to be used as the toolInventory array list.
	 */
	public Inventory(ArrayList<Item> tools) {
		toolInventory = tools;
	}
	/**
	 * Adds an instance of class Item to the toolInventory array list. 
	 * @param tool Instance of class Item to be added to the toolInventory array list. 
	 */
	public void addTool(Item tool) {
		toolInventory.add(tool);
	}
	/**
	 * Deletes an instance of class Item from the inventoryList array list.
	 * @param tool Instance of class Item to be removed from the inventoryList array list. 
	 */
	public void deleteTool(Item tool) { //removes first instance of tool in the inventory
		for(Item c: toolInventory) {
			if(c == tool) {
				toolInventory.remove(c);
				break;
			}
		}
	}
	
	/**
	 * Searches the inventoryList array list and returns an instance of class Item with a matching id to that taken in as an argument. 
	 * @param id Integer id to match to the id values of the instances of class Item within the list to find the desired item.
	 * @return Instance of class Item with the matching id number as that which was sent in as an argument. 
	 */
	public Item findTool(int id) {
		for(int i = 0; i < toolInventory.size(); i++) {
			if(toolInventory.get(i).getId() == id) return toolInventory.get(i);
		}
		return null;
	}
	
	/**
	 * Searches the inventoryList array list and returns an instance of class Item with a matching name to that taken in as an argument. 
	 * @param name String name to match to the name values of the instances of class Item within the list to find the desired item.
	 * @return Instance of class Item with the matching name value as that which was send in as an argument. 
	 */
	public Item findTool(String name) {
		for(int i = 0; i < toolInventory.size(); i++) {
			if(toolInventory.get(i).getName().contentEquals(name)) return toolInventory.get(i);
		}
		return null;
	}
	
	/**
	 * Prints out all instances of class Item withing the inventoryList array list to the console.
	 */
	public void listAllTools() {
		for(Item i: toolInventory)
			System.out.print(i.toString());
	}
	
	/**
	 * Decreases the quantity of the instance of class Item sent into the method as an argument if the quantity is larger than 0 and returns the updated quantity of the item. 
	 * @param tool Instance of class Item of which to decrease the quantity.
	 * @return Updated quantity of the Item object which was sent into the method as an argument. 
	 */
	public int buyItem(Item tool) {
		if(tool.getQuantity() > 0) {
			findTool(tool.getId()).setQuantity(findTool(tool.getId()).getQuantity() - 1);
			System.out.print("Item bought!\n");
		}
		else
			System.out.print("\nSorry, tool is out of stock.\n");
		return tool.getQuantity();
	}
	
	/**
	 * Returns the quantity of the Item object received by the method as an argument. 
	 * @param tool Item object who's quantity will be returned. 
	 * @return Integer quantity of the specific Item object received by the method as an integer.
	 */
	public int getToolQuantity(Item tool) {
		return tool.getQuantity();
	}
	/**
	 * Prints all the info for an object of Item which the method receives as an argument to the console. 
	 * @param tool Object of Item which will have all of its info printed to the console. 
	 */
	public void printToolInfo(Item tool) {
		System.out.println(tool.toString());
	}
	
}
