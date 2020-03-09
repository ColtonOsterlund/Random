package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;


/**
 * This class contains methods and data to create a CustomerFrameSellItemBtnListener for the PurchaseBtn in the Customer frame
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class CustomerFrameSellItemBtnListener implements ActionListener{
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
	public CustomerFrameSellItemBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 6 and the item ID to the server to decrement the quantity of the specified item, then
	 * sends the string 7 and the item ID once again to the server to increment the running total for the customer
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		
		String itemID = null;
		
		itemID = guiController.getCustomerFrame().getTableArea().getValueAt(guiController.getCustomerFrame().getTableArea().getSelectedRow(), 0).toString();
		
		comController.sendServer("6");
		comController.sendServer(itemID);
		comController.sendServer("7");
		comController.sendServer(itemID);
		
		String inStock = comController.readServerLine();
		if(inStock.contentEquals("This Item is Not Currently in Stock")) {
			JOptionPane.showMessageDialog(null, inStock, "Error", JOptionPane.ERROR_MESSAGE);
			comController.readServerLine(); //this is to discard the TERMINATE\n String now sitting in the BufferReader
			return;
		}
		
		guiController.getCustomerFrame().getTableAreaModel().setRowCount(0);
		
		String [] rowToAdd = new String[6];
		while(true) {
			//System.out.println("in loop");
			for(int i = 0; i < 6; i++) {
				rowToAdd[i] = comController.readServerLine();
				if(rowToAdd[i].trim().contentEquals("TERMINATE"))
					return;
			}
			guiController.getCustomerFrame().addTableRow(rowToAdd);
		}
	}
}