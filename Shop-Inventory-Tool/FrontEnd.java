import java.util.ArrayList;
import java.util.Scanner;
import java.io.File; 
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * Provides a console based interface for user to be able to interact with the
 * inventory system, as well as initializes and populates both the inventory list
 * and the supplier list from files item.txt and suppliers.txt.
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public class FrontEnd {
	/**
	 * Initializes both the supplier list and the inventory list and populates them with the files
	 * items.txt and suppliers.txt, then sets up and continuously runs a console based 
	 * interface the user prompts to quit the application.
	 * @param args String containing the arguments entered into the command line
	 * @throws IOException
	 */
	public static void main(String [] args) throws IOException {
		/*
		 * Array list that holds all of the Supplier objects from the suppliers.txt file
		 */
		ArrayList<Supplier> supplierList = new ArrayList<Supplier>();
		/**
		 * Array list that holds all of the Item objects from the items.txt file
		 */
		ArrayList<Item> itemList = new ArrayList<Item>();
		supplierList = importSuppliersFromFile(supplierList);
		itemList = importToolsFromFile(itemList, supplierList);
		
		/**
		 * Shop item connect user to the back-end inventory system and give
		 * access to the inventories functionality.
		 */
		Shop shop = new Shop(new Inventory(itemList), supplierList);
		/**
		 * Scanner object to read user input from the keyboard.
		 */
		Scanner scanner = new Scanner(System.in);
		/**
		 * Tool to be selected when the user searches the inventory for
		 * a specific tool to buy.
		 */
		Item selectedTool = null;
		
		while(true) {
			
			System.out.println("\n1. List all tools in inventory");
			System.out.println("2. Search by tool name");
			System.out.println("3. Search by tool ID");
			System.out.println("4. Check item quantity");
			System.out.println("5. Purchase item");
			System.out.println("6. Exit Application\n");
			
		    int userInput = scanner.nextInt();
		    
		    switch (userInput) {
		        case 1:
		        	shop.listAllTools();
		            break;
		
		        case 2:
		        	System.out.println("Enter tool name: ");
		        	if(scanner.hasNextLine()) scanner.nextLine();
		        	String toolName = scanner.nextLine();
		        	selectedTool = shop.findTool(toolName);
		        	if(selectedTool == null) System.out.println("Sorry, tool not found...\n");
		        	else{
		        		System.out.print("Item found!\n");
		        		shop.printToolInfo(selectedTool);
		        	}
		            break;
		            
		        case 3:
		        	System.out.println("Enter tool ID: ");
		        	int toolId = scanner.nextInt();
		        	selectedTool = shop.findTool(toolId);
		        	if(selectedTool == null) System.out.println("Sorry, tool not found...\n");
		        	else{
		        		System.out.print("Item found!\n");
		        		shop.printToolInfo(selectedTool);
		        	}
		            break;
		            
		        case 4:
		        	if(selectedTool == null) System.out.print("Search for tool in inventory first...\n");
		        	else {
		        		System.out.println("Quantity: " + shop.getToolQuantity(selectedTool));
		        	}
		            break;
		            
		        case 5:
		        	if(selectedTool == null) System.out.println("\nSearch for tool in inventory first...\n");
		        	else {
		        		shop.buyItem(selectedTool);
		        		shop.printToolInfo(selectedTool);
		        	}
		            break;
		            
		        case 6:
		            System.out.println("Application terminated");
		            System.exit(0);
		            break;
		            
		        default:
		            System.out.print("Invalid input. Please select one of the options above.\n");
		    }

		}
		
	}
	
	/**
	 * 
	 * @param supplierList Array list to be filled in with suppliers from the supplier.txt file
	 * @return Array list filled in with suppliers from the supplier.txt file
	 * @throws FileNotFoundException
	 */
	private static ArrayList<Supplier> importSuppliersFromFile(ArrayList<Supplier> supplierList) throws FileNotFoundException {
		Scanner supplierFileReader = new Scanner(new File("D:\\School\\Course Documents\\ENSF 409\\Lab 3\\Exercise 1 - Shop Inventory Tool\\Shop Inventory Tool\\src\\suppliers.txt"));
		supplierFileReader.useDelimiter(";|\\n");
		while(supplierFileReader.hasNext())
			supplierList.add(new Supplier(Integer.parseInt(supplierFileReader.next().trim()), supplierFileReader.next().trim(), supplierFileReader.next().trim(), supplierFileReader.next().trim()));
		supplierFileReader.close();
		return supplierList;
	}
	
	/**
	 * 
	 * @param itemList
	 * @param supplierList Array list to be filled in with the items from the items.txt file
	 * @return Array list filled in with items from the items.txt file
	 * @throws FileNotFoundException
	 */
	private static ArrayList<Item> importToolsFromFile(ArrayList<Item> itemList, ArrayList<Supplier> supplierList) throws FileNotFoundException {
		Scanner itemFileReader = new Scanner(new File("D:\\School\\Course Documents\\ENSF 409\\Lab 3\\Exercise 1 - Shop Inventory Tool\\Shop Inventory Tool\\src\\items.txt"));
		itemFileReader.useDelimiter(";|\\n");
		while(itemFileReader.hasNext()) {
			Item item = new Item(Integer.parseInt(itemFileReader.next().trim()), itemFileReader.next().trim(), Integer.parseInt(itemFileReader.next().trim()), Double.parseDouble(itemFileReader.next().trim()), Integer.parseInt(itemFileReader.next().trim()));
			
			for(Supplier s: supplierList) {
				if(item.getSupplierId() == s.getId()) {
					item.setSupplier(s);
					s.setNewTool(item);
				}
			}
			
			itemList.add(item);
		}
			itemFileReader.close();
			return itemList;
	}
	
}
