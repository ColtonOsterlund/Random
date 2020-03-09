package Client.Model;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;
/**
 * This class contains methods and data to create a WindowListener for the projects 4 GUI Frames 
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class FrameWindowListener implements WindowListener{
	/**
	 * ClientGUIController object to be aggregated to the FrameWindowListener class
	 */
	private ClientGUIController guiController;
	/**
	 * ClientCommunicaitonController object to be aggregated to the FrameWindowListener class
	 */
	private ClientCommunicationController comController;
	/**
	 * Constructor for the FrameWindowListener class which sets guiController to a ClientGUIController object taken in as an argument and sets comController to a ClientCommunicaitonController
	 * object taken in as an argument.
	 * @param guiController ClientGUIController object to be set to guiController
	 * @param comController ClientCommunicaitonController object to be set to comController
	 */
	public FrameWindowListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	public void windowIconified(WindowEvent e) {
		//do nothing special
	}
	
	public void windowDeiconified(WindowEvent e) {
		//do nothing special
	}
	
	public void windowDeactivated(WindowEvent e) {
		//do nothing special
	}
	
	public void windowActivated(WindowEvent e) {
		//do nothing special
	}
	
	public void windowOpened(WindowEvent e) {
		//do nothing special
	}
	
	public void windowClosed(WindowEvent e) {
		//do nothing special
	}
	
	/**
	 * This method listens for a WindowEvent instantiated when the red X at the top right corner of the window is clicked, and safely breaks the server connection then terminates the 
	 * application.
	 */
	public void windowClosing(WindowEvent e) {
		System.out.println("Window closed, application terminated");
		comController.sendServer("0"); //this safely breaks the server connection on the server side
		comController.breakConnection(); //this closes the socket streams and the connection on the client side
		System.exit(0);
	}
}