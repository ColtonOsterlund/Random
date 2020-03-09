package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;
import javax.swing.JTextField;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;
/**

/**
 * This class contains methods and data to create a ClerkFrameAddItemBtnListener for the AddItemBtn in the Clerk frame
 * @author Colton Osterlund
 *
 */
public class ClerkFrameAddItemBtnListener implements ActionListener{
	/**
	 * ClientGUIController object aggregated to this Listener class
	 */
	private ClientGUIController guiController;
	/**
	 * ClientCommunicationController object aggregated to this Listener class
	 */
	private ClientCommunicationController comController;

	/**
	 * The constructor for this class sets its ClientGUIController and ClientCommunicationController objects
	 * from the parameters given to it via aggregation
	 * @param guiController Object of ClientGUIController that is set to the class
	 * @param comController Object of ClientCommunicationController that is set to class
	 */
	public ClerkFrameAddItemBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 1 to the server. The method then displays text fields for the user to fill
	 * with the details of the item. These text fields are then put into a single string and sent to the server,
	 * and then added to the database and table
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		comController.sendServer("1");
		
		JTextField field1 = new JTextField();
		JTextField field2 = new JTextField();
		JTextField field3 = new JTextField();
		JTextField field4 = new JTextField();
		JTextField field5 = new JTextField();

		Object[] message = { "Item ID:", field1, "Item Name:", field2, "Item Price:", field3, "Item Quantity:", field4, "Supplier ID:", field5 };

		int option = JOptionPane.showConfirmDialog(null, message, "Enter the Following Values",
				JOptionPane.OK_CANCEL_OPTION);

		if (option == JOptionPane.OK_OPTION) {
			String itemID = field1.getText();
			String itemName = field2.getText();
			String itemPrice = field3.getText();
			String itemQuantity = field4.getText();
			String supplierID = field5.getText();
			
			
			comController.sendServer(itemID + "\n" + itemName + "\n" + itemQuantity + "\n" + itemPrice + "\n" + supplierID + "\n");
			
			guiController.getClerkFrame().getTableAreaModel().setRowCount(0);
			
			String [] rowToAdd = new String[6];
			while(true) {
				for(int i = 0; i < 6; i++) {
					rowToAdd[i] = comController.readServerLine();
					if(rowToAdd[i].trim().contentEquals("TERMINATE"))
						return;
				}
				guiController.getClerkFrame().addTableRow(rowToAdd);
			}
		}
	}
}
