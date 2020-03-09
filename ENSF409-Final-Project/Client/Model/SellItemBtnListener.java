package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;


/**
 * This class contains methods and data to create a SellItemBtnListener for the SellItemBtn in the Clerk frame
 * @author bnkwo
 *
 */
public class SellItemBtnListener implements ActionListener{
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
	public SellItemBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 6 to the server. This decrements the quantity of the item
	 * every time it is called. If the item has a quantity of 0, an out of order message will be displayed
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		
		String itemID = null;
		
		itemID = guiController.getClerkFrame().getTableArea().getValueAt(guiController.getClerkFrame().getTableArea().getSelectedRow(), 0).toString();
		
		comController.sendServer("6");
		comController.sendServer(itemID);
		
		String inStock = comController.readServerLine();
		if(inStock.contentEquals("This Item is Not Currently in Stock")) {
			JOptionPane.showMessageDialog(null, inStock, "Error", JOptionPane.ERROR_MESSAGE);
			comController.readServerLine(); //this is to discard the TERMINATE\n String now sitting in the BufferReader
			return;
		}
		
		guiController.getClerkFrame().getTableAreaModel().setRowCount(0);
		
		String [] rowToAdd = new String[6];
		while(true) {
			//System.out.println("in loop");
			for(int i = 0; i < 6; i++) {
				rowToAdd[i] = comController.readServerLine();
				if(rowToAdd[i].trim().contentEquals("TERMINATE"))
					return;
			}
			guiController.getClerkFrame().addTableRow(rowToAdd);
		}
	}
}
