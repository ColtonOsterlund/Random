import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
/**
 * provides methods and variables to create a new orderLine to be written to the file orders.txt
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public class OrderLine {
	
	/**
	 * object of type Item that is low in stock and must be ordered
	 */
	private Item itemToOrder;
	/**
	 * Output stream object allowing for the Orders to be written to a file orders.txt
	 */
	private PrintWriter fileWriter;
	/**
	 * amount of object of type Item to order which should be equal to (50 - current quantity of the tool)
	 */
	private int amountToOrder;
	/**
	 * Constructor to assign all member variables to the values of the arguments received by the method, and writes an orderLine to the file orders.txt
	 * @param tool object of type Item that is low in stock and needs to be ordered
	 * @throws IOException
	 */
public OrderLine(Item tool) throws IOException {
		setItemToOrder(tool);
		fileWriter = new PrintWriter(new FileWriter("D:\\School\\Course Documents\\ENSF 409\\Lab 3\\Exercise 1 - Shop Inventory Tool\\Shop Inventory Tool\\src\\orders.txt", true));
		//second argument of file writer sets to append mode
		amountToOrder = 50 - tool.getQuantity();
		
		fileWriter.println(); //new line character doesnt work with this for some reason. Figure this out to clean up code
		fileWriter.println("Item Description:	" + tool.getName());
		fileWriter.println("Amount Ordered:		" + amountToOrder);
		fileWriter.println("Supplier:		" + tool.getSupplierName());
		
		fileWriter.close();
	}
/**
 * returns itemToOrder member variable
 * @return object of type Item
 */
public Item getItemToOrder() {
	return itemToOrder;
}

/**
 * sets the itemToOrder member variable to the object of type Item it receives as an argument
 * @param itemToOrder object of type Item to be set to the itemToOrder member variable
 */
public void setItemToOrder(Item itemToOrder) {
	this.itemToOrder = itemToOrder;
}

}
