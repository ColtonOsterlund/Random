package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;
/**
 * This class contains methods and data to create a ListAllBtnListener for the ListAllBtn in the ClerkFrame 
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class ListAllBtnListener implements ActionListener{
	/**
	 * ClientGUIController object to be aggregated to the ListAllBtnListener class
	 */
	private ClientGUIController guiController;
	/**
	 * ClientCommunicaitonController object to be aggregated to the ListAllBtnListener class
	 */
	private ClientCommunicationController comController;
	/**
	 * Constructor for the ListAllBtnListener class which sets guiController to a ClientGUIController object taken in as an argument and sets comController to a ClientCommunicaitonController
	 * object taken in as an argument.
	 * @param guiController ClientGUIController object to be set to guiController
	 * @param comController ClientCommunicaitonController object to be set to comController
	 */
	public ListAllBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}

	/**
	 * Method that sends the String "5" to the server specifying the List All command on the server side, then empties the JTable in the JFrame and listens for a new string containing 
	 * all the items which it fills the JTable with.
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		comController.sendServer("5");
		
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
