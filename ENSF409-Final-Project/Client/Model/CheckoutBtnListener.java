package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigDecimal;
import java.math.RoundingMode;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class contains methods and data to create a CheckoutBtn Listener for the CheckoutBtn in the Customer frame
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class CheckoutBtnListener implements ActionListener{
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
	public CheckoutBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}

	/**
	 * This method sends the string 12 to the server, and then displays the total cost of all items purchased
	 * by the customer
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		comController.sendServer("12");
		
		BigDecimal totalPrice = new BigDecimal(Double.parseDouble(comController.readServerLine())).setScale(2, RoundingMode.HALF_UP);
		
		JOptionPane.showMessageDialog(null,  "Your total today is: $" + totalPrice.toString(), "Checkout", JOptionPane.INFORMATION_MESSAGE);
		
		guiController.displayLoginFrame();
	}
}
