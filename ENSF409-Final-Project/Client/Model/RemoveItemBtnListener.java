package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class contains methods and data to create a RemoveItemBtnListener for the RemoveItemBtn in the Clerk frame
 * @author Colton Osterlund
 *
 */
public class RemoveItemBtnListener implements ActionListener{
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
	public RemoveItemBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 2 to the server, as well as the ID of the selected item in 
	 * the shop. The item is then removed from the shop and the database
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		String itemID = null;
		
		itemID = guiController.getClerkFrame().getTableArea().getValueAt(guiController.getClerkFrame().getTableArea().getSelectedRow(), 0).toString();
		
		comController.sendServer("2");
		comController.sendServer(itemID);
		
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
