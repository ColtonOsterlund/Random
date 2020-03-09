import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

//MCV CONTROLLER

/**
 * Class containing all methods and data to create a WindowListener class to be registered to the JFrame window created from the MyFrame 
 * JFrame class
 * @author Colton Osterlund & Boma Nkwonta
 * @Version 1.0
 * @Since March 29th, 2019
 *
 */
public class MyFrameWindowListener implements WindowListener{
	/**
	 * Instance of Controller class to register this WindowListener class to the proper Window created from the JFrame class 
	 */
	private Controller controller;
	
	/**
	 * Constructor to create and instance of the MyFrameWindowListener class and set the controller reference to an instance of 
	 * Controller taken in as an argument.
	 * @param controller Instance of Controller to set the controller reference
	 */
	public MyFrameWindowListener(Controller controller) {
		this.controller = controller;
	}
	
	/**
	 * Method printing to the console when the window throws a WindowEvent after being iconified.
	 */
	public void windowIconified(WindowEvent e) {
		System.out.println("Window has been iconified");
	}
	/**
	 * Method printing to the console when the window throws a WindowEvent after being deiconified.
	 */
	public void windowDeiconified(WindowEvent e) {
		System.out.println("Window has been deiconified");
	}
	/**
	 * Method printing to the console when the window throws a WindowEvent after being deactivated.
	 */
	public void windowDeactivated(WindowEvent e) {
		System.out.println("Window has been deactivated");
	}
	/**
	 * Method printing to the console when the window throws a WindowEvent after being activated.
	 */
	public void windowActivated(WindowEvent e) {
		System.out.println("Window has been activated");
	}
	/**
	 * Method printing to the console when the window throws a WindowEvent after being opened.
	 */
	public void windowOpened(WindowEvent e) {
		System.out.println("Window has been opened");
	}
	/**
	 * Method printing to the console when the window throws a WindowEvent after being closed.
	 */
	public void windowClosed(WindowEvent e) {
		System.out.println("Window has been closed");
	}
	/**
	 * Method that exits the application when the window throws a WindowEvent after being promted to close.
	 */
	public void windowClosing(WindowEvent e) {
		System.out.println("Window closed, application terminated");
		System.exit(0);
	}
}
