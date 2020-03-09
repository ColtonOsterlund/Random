package Client.Model;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JComboBox;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;
/**
 * This class creates a new account and adds it to the database
 * @author Colton Osterlund
 *
 */
public class LoginFrameCreateAccountBtnListener implements ActionListener {
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
	public LoginFrameCreateAccountBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method reads text fields for the users input and stores those as the users
	 * username, password, and email, then reads the users selection from the drop-down menu
	 * to indicate whether they are a customer or a clerk. The method then sends a string containing
	 *  the number 8 to the server which, through the use of sockets,
	 *  will make sure the user does not already exist, at which point
	 *  this information is then stored in the database
	 */
	@Override
	public void actionPerformed(ActionEvent e) {		
		
		JTextField field1 = new JTextField();
		field1.setFont(new Font("Plain Titling", Font.PLAIN, 20));
		JPasswordField field2 = new JPasswordField();
		field2.setFont(new Font("Plain Titling", Font.PLAIN, 20));
		JTextField field3 = new JTextField();
		field1.setFont(new Font("Plain Titling", Font.PLAIN, 20));
		String [] modes = {" ", "Customer", "Clerk"};
		JComboBox field4 = new JComboBox(modes);
		field4.setSelectedIndex(0);

		Object[] message = { "Username:", field1, "Password:", field2, "Email", field3, "Account Type:", field4 };

		int option = JOptionPane.showConfirmDialog(null, message, "Enter the Following Values",
				JOptionPane.OK_CANCEL_OPTION);

		if (option == JOptionPane.OK_OPTION) {
			String username = field1.getText();
			String password = new String(field2.getPassword());
			String email = field3.getText();
			int accountType = field4.getSelectedIndex();
		
			if(accountType == 0) {
				JOptionPane.showMessageDialog(null, "You Must Select an Account Type", "Error Message", JOptionPane.ERROR_MESSAGE);
				return;
			}
			
			comController.sendServer("8");
			comController.sendServer(username + "\n" + password + "\n" + email + "\n" + Integer.toString(accountType));
			
			String result = comController.readServerLine();
			
			if(result.contentEquals("Username Already Exists")) {
				JOptionPane.showMessageDialog(null, result, "Error Message", JOptionPane.ERROR_MESSAGE);
				return;
			}
				
			JOptionPane.showMessageDialog(null, result, "Success", JOptionPane.INFORMATION_MESSAGE);
			
		}
		
	}

}
