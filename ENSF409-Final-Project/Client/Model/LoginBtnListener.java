package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class logs the user in to the frame their account type specifies (Clerk or Customer)
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class LoginBtnListener implements ActionListener {
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
	public LoginBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;

	}

	/**
	 * This method logs the user in and displays their respective frame by The method then sends a string containing
	 *  the number 9 to the server which, through the use of sockets, will validate the users information.
	 *  If valid, the method will read a the account type for the user and display the appropriate frame
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		comController.sendServer("9");
		comController.sendServer(guiController.getLoginFrame().getUsernameField().getText() + "\n" +  new String(guiController.getLoginFrame().getPasswordField().getPassword()));
		
		String validation = comController.readServerLine();
		System.out.println(validation);
		
		if(validation.contentEquals("Valid")) {
			String accountType = comController.readServerLine();
			
			if(accountType.contentEquals("1")) {
				guiController.displayCustomerFrame();
				return;
			}
			else if(accountType.contentEquals("2")) {
				guiController.displayClerkFrame();
				return;
			}
		}
		
		else
			JOptionPane.showMessageDialog(null, validation, "Error Message", JOptionPane.ERROR_MESSAGE);
	}
}

