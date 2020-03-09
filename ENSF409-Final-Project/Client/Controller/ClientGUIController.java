package Client.Controller;

import Client.Model.CheckoutBtnListener;
import Client.Model.ClerkFrameAddItemBtnListener;
import Client.Model.CustomerFrameSellItemBtnListener;
import Client.Model.CustomerTableAreaMouseListener;
import Client.Model.ExportOrderBtnListener;
import Client.Model.ForgotBtnListener;
import Client.Model.FrameWindowListener;
import Client.Model.ListAllBtnListener;
import Client.Model.ListAllCustListener;
import Client.Model.LoginBtnListener;
import Client.Model.LoginFrameCreateAccountBtnListener;
import Client.Model.LogoutBtnListener;
import Client.Model.RemoveItemBtnListener;
import Client.Model.SearchIDBtnListener;
import Client.Model.SearchNameBtnListener;
import Client.Model.SellItemBtnListener;
import Client.Model.TableAreaMouseListener;
import Client.View.ClerkFrame;
import Client.View.CustomerFrame;
import Client.View.LoginFrame;

/**
 * This class controls the visibility of the frames used in the project. The class also
 * controls the status of the listeners for the components in these frames
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class ClientGUIController {
	/**
	 * ClientCommunicationController object to be asoociated to to this ClientGUIController
	 */
	private ClientCommunicationController clientComControl;
	/**
	 * LoginFrame object holding a GUI frame for the login screen
	 */
	private LoginFrame loginFrame;
	/**
	 * ClerkFrame object holding a GUI frame for the clerk screen
	 */
	private ClerkFrame clerkFrame;
	/**
	 * CustomerFrame object holding a GUI frame for the customer screen
	 */
	private CustomerFrame customerFrame;
	
	/**
	 * The constructor of this class sets the objects of the different frames which are aggregated to the class
	 * @param loginFrame Login frame set to the GUI Controller
	 * @param createAccountFrame Create account frame set to the GUI Controller
	 * @param clerkFrame Clerk frame set to the GUI Controller
	 * @param customerFrame Customer frame set to the GUI Controller
	 */
	public ClientGUIController(LoginFrame loginFrame,ClerkFrame clerkFrame, CustomerFrame customerFrame){
		this.loginFrame = loginFrame;
		
		
		this.clerkFrame = clerkFrame;
		
		this.customerFrame = customerFrame;
	}
	
	/**
	 * This method calls the login frames display method, which will set the login frame to be visible
	 */
	public void commenceGUI() {
		this.displayLoginFrame();
	}
	
	/**
	 * This method sets the listeners for the frames, which will then set the listeners for the buttons in them
	 */
	public void setListeners() {
		this.setLoginFrameListeners();
		this.setClerkFrameListeners();
		this.setCustomerFrameListeners();
	}
	
	/**
	 * This method sets the listeners for the buttons in the login frame
	 */
	public void setLoginFrameListeners() {
		loginFrame.setLoginListener(new LoginBtnListener(this, clientComControl));
		loginFrame.setForgotListener(new ForgotBtnListener(this, clientComControl));
		loginFrame.setCreateListener(new LoginFrameCreateAccountBtnListener(this, clientComControl));
		loginFrame.setWindowListener(new FrameWindowListener(this, clientComControl));
	}
	
	/**
	 * This method sets the listeners for the buttons in the clerk shop frame, along with winow listeners
	 * and table listeners
	 */
	public void setClerkFrameListeners() {
		clerkFrame.setListInvBtnListener(new ListAllBtnListener(this, clientComControl));
		clerkFrame.setAddItemBtnListener(new ClerkFrameAddItemBtnListener(this, clientComControl));
		clerkFrame.setRemoveItemBtnListener(new RemoveItemBtnListener(this, clientComControl));
		clerkFrame.setSearchNameBtnListener(new SearchNameBtnListener(this, clientComControl));
		clerkFrame.setSearchIDBtnListener(new SearchIDBtnListener(this, clientComControl));
		clerkFrame.setSellItemBtnListener(new SellItemBtnListener(this, clientComControl));
		clerkFrame.setExportOrderBtnListener(new ExportOrderBtnListener(this, clientComControl));
		clerkFrame.setLogoutBtnListener(new LogoutBtnListener(this, clientComControl));
		clerkFrame.setTableAreaMouseListener(new TableAreaMouseListener(this, clientComControl));
		clerkFrame.setWindowListener(new FrameWindowListener(this, clientComControl));
	}
	
	/**
	 * This method sets the listeners for the buttons in the customer shop frame
	 */
	public void setCustomerFrameListeners() {
		customerFrame.setListInvBtnListener(new ListAllCustListener(this, clientComControl));
		customerFrame.setCheckoutBtnListener(new CheckoutBtnListener(this, clientComControl));
		customerFrame.setSearchNameBtnListener(new SearchNameBtnListener(this, clientComControl));
		customerFrame.setSearchIDBtnListener(new SearchIDBtnListener(this, clientComControl));
		customerFrame.setTableAreaMouseListener(new CustomerTableAreaMouseListener(this, clientComControl));
		customerFrame.setPurchaseBtnListener(new CustomerFrameSellItemBtnListener(this, clientComControl));
		customerFrame.setWindowListener(new FrameWindowListener(this, clientComControl));
	}
	
	/**
	 * This method sets the Client Communication Controller object for the GUI controller to
	 * the Client Communication Controller indicated in the method parameter
	 * @param clientComControl Client Communication Controller object being set to the Client
	 * GUI Controller
	 */
	public void setClientCommunicationController(ClientCommunicationController clientComControl) {
		this.clientComControl = clientComControl;
	}
		
	/**
	 * This method displays the login frame by setting its visibility to true and setting the visibility
	 * of the other frames to false
	 */
	public void displayLoginFrame() {
		clerkFrame.setVisible(false);
		customerFrame.setVisible(false);
		loginFrame.setVisible(true);
		
		this.loginFrame.getUsernameField().setText("");
		this.loginFrame.getPasswordField().setText("");
	}
	
	/**
	 * This method displays the clerk frame by setting its visibility to true and setting the visibility
	 * of the other frames to false
	 */
	public void displayClerkFrame() {
		loginFrame.setVisible(false);
		customerFrame.setVisible(false);
		clerkFrame.setVisible(true);
	}
	
	/**
	 * This method displays the customer frame by setting its visibility to true and setting the visibility
	 * of the other frames to false
	 */
	public void displayCustomerFrame() {
		loginFrame.setVisible(false);
		clerkFrame.setVisible(false);
		customerFrame.setVisible(true);
	}
	
	/**
	 * This method returns the login frame for the GUI Controller
	 * @return the login frame of the GUI Controller
	 */
	public LoginFrame getLoginFrame() {
		return loginFrame;
	}
	
	/**
	 * This method returns the clerk frame for the GUI Controller
	 * @return the clerk frame of the GUI Controller
	 */
	public ClerkFrame getClerkFrame() {
		return clerkFrame;
	}
	
	/**
	 * This method returns the customer frame for the GUI Controller
	 * @return the customer frame of the GUI Controller
	 */
	public CustomerFrame getCustomerFrame() {
		return customerFrame;
	}
	
	/**
	 * This is the main method of the GUI Controller. This method instantiates a login, create account, clerk, and customer frame,
	 * along with a GUI controller containing all these frames, and a Client Communication Controller with the server name
	 * and port number. The method then sets the Client Communication controller, the GUI Controller, and listeners for 
	 * all the frames. The method then commences the GUI
	 * @param args Command line arguments
	 */
	public static void main (String [] args)
	{
		LoginFrame loginFrame = new LoginFrame();
		ClerkFrame clerkFrame = new ClerkFrame();
		CustomerFrame customerFrame = new CustomerFrame();
		
		ClientGUIController clientGUIControl = new ClientGUIController(loginFrame, clerkFrame, customerFrame);
		ClientCommunicationController clientComControl = new ClientCommunicationController(args[0], 8000);
		
		clientGUIControl.setClientCommunicationController(clientComControl);
		clientComControl.setClientGUIController(clientGUIControl);
		
		clientGUIControl.setListeners();
		clientGUIControl.commenceGUI();
		
	}
}
