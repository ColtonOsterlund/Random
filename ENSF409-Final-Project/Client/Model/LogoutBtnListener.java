package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class logs the client/customer out of their respective frame and returns to the login frame

 * @author Colton Osterlund
 *
 */
public class LogoutBtnListener implements ActionListener{
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
	public LogoutBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}

	/**
	 * This method calls the method to display the login frame from guiController
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		guiController.displayLoginFrame();
	}
}
