package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class contains methods and data to create a SearchIDBtnListener for the SearchIDBtn in the Clerk & Customer frames
 * @author Colton Osterlund
 *
 */
public class SearchIDBtnListener implements ActionListener{
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
	public SearchIDBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 4 to the server, then sends the ID of the item being searched for
	 * to the server as well. Through sockets, the server will communicate and notify this method
	 * of whether or not this item is in the database. If it is, the items details (ID, Name, Price, Quantity, Supplier etc)
	 * will be returned to the method and then displayed to the user
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		String toSearch = JOptionPane.showInputDialog("Search For:");
		
		if(toSearch == null)
			return;
		
		comController.sendServer("4");
		comController.sendServer(toSearch);
		
		String s = "";
		String toAdd;
		while(true) {
			toAdd = comController.readServerLine();
			if(toAdd.contentEquals("TERMINATE"))
				break;
			
			s += toAdd + "\n";
		}
		
		if(s.trim().contentEquals("")) {
			JOptionPane.showMessageDialog(null, "Item does not exist", "Error Message", JOptionPane.ERROR_MESSAGE);
			return;
		}
			
		JOptionPane.showMessageDialog(null, s, "Selected Item", JOptionPane.INFORMATION_MESSAGE);
	}
}
