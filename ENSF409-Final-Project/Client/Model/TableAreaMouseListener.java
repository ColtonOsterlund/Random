package Client.Model;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class contains methods and data to create a TableAreaMouseListener for the table area in the Clerk & Customer frames
 * @author Colton Osterlund
 *
 */
public class TableAreaMouseListener implements MouseListener{
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
	public TableAreaMouseListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method listens for a double click on on an item in the shop table, then 
	 * displays all the information for the selected item
	 */
	@Override
	public void mouseClicked(MouseEvent mEvent) {
		if(mEvent.getClickCount() == 2) {
			String s = "";
			
			for(int i = 0; i < 6; i++) {
				int selectedRow = guiController.getClerkFrame().getTableArea().getSelectedRow();
				s += guiController.getClerkFrame().getTableArea().getColumnName(i) + ": ";
				s += guiController.getClerkFrame().getTableAreaModel().getValueAt(selectedRow, i);
				if(i < 5)
					s += "\n";
			}
			
			JOptionPane.showMessageDialog(null, s, "Selected Item", JOptionPane.INFORMATION_MESSAGE);
		}
	}

	@Override
	public void mouseEntered(MouseEvent mEvent) {
		//do nothing
		
	}

	@Override
	public void mouseExited(MouseEvent mEvent) {
		// do nothing
		
	}

	@Override
	public void mousePressed(MouseEvent mEvent) {
		// do nothing
		
	}

	@Override
	public void mouseReleased(MouseEvent mEvent) {
		// do nothing
		
	}

}
