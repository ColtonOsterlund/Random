import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
/**
 * Class that contatins all the orderLines written within a day
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public class Order {
	/**
	 * array list contataining all the orderLine object written for the specific day associated with the Order object.
	 */
	private ArrayList<OrderLine> orderLineList;
	/**
	 * String date to keep track of what day the Order object contains the orderLine objects for
	 */
	private String date;
	/**
	 * randomly generated 5-digit id unique to each Order object
	 */
	private long id;
	/**
	 * Output stream object allowing for the Orders to be written to a file orders.txt
	 */
	private PrintWriter fileWriter;
	/**
	 * Constructor to assign all member variables to the values of the arguments received by the method, and writes the header of the Order to the file orders.txt
	 * @param date String date to be assinged to member variable date
	 * @throws IOException
	 */
	public Order(String date) throws IOException {
		this.date = date;
		id = Math.round((Math.random() * (99999 - 10000)) + 10000);
		orderLineList = new ArrayList<OrderLine>();
		fileWriter = new PrintWriter(new FileWriter("D:\\School\\Course Documents\\ENSF 409\\Lab 3\\Exercise 1 - Shop Inventory Tool\\Shop Inventory Tool\\src\\orders.txt", true));
		//second argument of file writer sets to append mode
		
		fileWriter.println("****************************************************");
		fileWriter.println("Order ID:	" + id);
		fileWriter.println("Date:		" + date);
		fileWriter.println(); //newline character doesnt work with this for some reason - look into it to clean up code

		fileWriter.close();
	}
	/**
	 * Returns the date member variable
	 * @return String date member variable
	 */
	public String getDate() {
		return date;
	}
	/**
	 * sets the date member variable to the argument taken in as an argument
	 * @param date String date to assign to date member variable
	 */
	public void setDate(String date) {
		this.date = date;
	}
/**
 * creates a new object of type orderLine in the array list orderLineList and uses this object to write a new orderLine
 * @param tool object of type Item that is low in stock and needs to be ordered
 * @throws IOException
 */
	public void writeNewOrderLine(Item tool) throws IOException {
		for(OrderLine ol: orderLineList) {
			if(ol.getItemToOrder() == tool) {
				System.out.print("\nWarning: Low Stock. Previous order pending.\n");
				return;
			}
		}
		orderLineList.add(new OrderLine(tool));
		System.out.print("\nWarning: Low Stock. New order has been processed.\n");
	}
}
