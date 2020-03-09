package Client.View;

import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import Client.Model.FrameWindowListener;

/**
 * This class creates the frame used to log in to the shop. The class also
 * creates and sets all the buttons and listeners for said buttons
 * 
 * @author Boma Nkwonta
 *
 */
public class LoginFrame extends javax.swing.JFrame {
	/**
	 * JButton object to instantiate the login button
	 */
	private JButton loginBtn;
	/**
	 * JButton object to instantiate the forgot password button
	 */
	private JButton forgotBtn;
	/**
	 * JButton object to instantiate the create account button
	 */
	private JButton createBtn;
	/**
	 * JButton object to instantiate the customer login button
	 */
	private JButton customer;
	/**
	 * JLabel object to instantiate the title label
	 */
	private JLabel titleLabel;
	/**
	 * JPanel object to instantiate the text panel
	 */
	private JPanel textPanel;
	/**
	 * JPanel object to instantiate the button panel
	 */
	private JPanel buttonPanel;
	/**
	 * Container object to hold the container for this JFrame object
	 */
	private Container container;
	/**
	 * JTextField to instantiate the text field where the username is entered
	 */
	private JTextField usernameField;
	/**
	 * JPasswordField to instantiate the text field where the username is entered
	 */
	private JPasswordField passwordField;
	// private JComboBox userType;

	/**
	 * This constructor calls the methods responsible for setting the frame, the
	 * buttons, the panels, and the components
	 */
	public LoginFrame() {
		this.setFrame();
		this.setButtons();
		this.setPanels();
		this.setComponents();
		this.setResizable(false);
	}

	/**
	 * This method sets the frame for the login frame, as well as the title and the
	 * the layout
	 */
	public void setFrame() {
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		setBounds(0, 0, screenSize.width / 3, screenSize.height / 2);
		setTitle("User Login");
		setLayout(new GridLayout());
	}

	/**
	 * This method initializes the panels used in the frame and sets a color for the
	 * text panel. The method also adds the buttons to the button panel and adds the
	 * text fields for the user to enter their login details
	 */
	public void setPanels() {

		titleLabel = new JLabel("Sign in to your account");
		titleLabel.setFont(new Font("Plantin Titling", Font.BOLD, 15));

		usernameField = new JTextField();
		usernameField.setMaximumSize(new Dimension(450, 200));
		usernameField.setFont(new Font("Plantin Titling", Font.PLAIN, 25));
		TextPrompt tp = new TextPrompt("Username", usernameField);
		tp.setForeground(Color.GRAY);
		passwordField = new JPasswordField(2);
		passwordField.setMaximumSize(new Dimension(450, 200));
		passwordField.setFont(new Font("Plantin Titling", Font.PLAIN, 25));
		TextPrompt tPass = new TextPrompt("Password", passwordField);
		tPass.setForeground(Color.GRAY);

		buttonPanel = new JPanel();
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS));
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(loginBtn);
		loginBtn.setAlignmentX(buttonPanel.CENTER_ALIGNMENT);
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(forgotBtn);
		forgotBtn.setAlignmentX(buttonPanel.CENTER_ALIGNMENT);
		buttonPanel.add(Box.createVerticalGlue());
		buttonPanel.add(createBtn);
		createBtn.setAlignmentX(buttonPanel.CENTER_ALIGNMENT);
		buttonPanel.add(Box.createVerticalGlue());


		textPanel = new JPanel();
		textPanel.setBackground(Color.getHSBColor(200, 200, 80));
		textPanel.setLayout(new BoxLayout(textPanel, BoxLayout.Y_AXIS));
		textPanel.add(titleLabel);
		textPanel.add(Box.createVerticalGlue());
		textPanel.add(usernameField);
		textPanel.add(Box.createVerticalGlue());
		textPanel.add(passwordField);
		textPanel.add(Box.createVerticalGlue());

	}

	/**
	 * This method sets the components to the container of the frame
	 */
	public void setComponents() {
		container = getContentPane();
		container.add("West", textPanel);
		container.add("South", buttonPanel);

	}

	/**
	 * This method initializes the buttons and labels them
	 */
	public void setButtons() {
		loginBtn = new JButton("Login");
		customer = new JButton("Customer Login");
		forgotBtn = new JButton("Forgot?");
		createBtn = new JButton("Create Account");
	}

	/**
	 * This method sets the login button listener to the ActionListener object in
	 * the parameter
	 * 
	 * @param listener ActionListener being set to the login button
	 */
	public void setLoginListener(ActionListener listener) {
		loginBtn.addActionListener(listener);
	}

	/**
	 * This method sets the forgot button listener to the ActionListener object in
	 * the parameter
	 * 
	 * @param listener ActionListener being set to the forgot button
	 */
	public void setForgotListener(ActionListener listener) {
		forgotBtn.addActionListener(listener);
	}

	/**
	 * This method sets the create account button listener to the ActionListener
	 * object in the parameter
	 * 
	 * @param listener ActionListener being set to the create account button
	 */
	public void setCreateListener(ActionListener listener) {
		createBtn.addActionListener(listener);
	}

	/**
	 * This method sets the customer button listener to the ActionListener object in
	 * the parameter
	 * 
	 * @param listener ActionListener being set to the customer button
	 */
	public void customerListen(ActionListener listener) {
		customer.addActionListener(listener);
	}

	/*
	 * public void setModeListener(ActionListener listener) {
	 * userType.addActionListener(listener); }
	 */

	/**
	 * This method sets the window listener to the FrameWindowListener object in the
	 * parameter
	 * @param listener FrameWindowListener being set to the window listener
	 */
	public void setWindowListener(FrameWindowListener listener) {
		this.addWindowListener(listener);
	}
	
	/**
	 * This method returns the text in the username field
	 * @return the textField used for the username
	 */
	public JTextField getUsernameField() {
		return usernameField;
	}
	
	/**
	 * This method returns the text in the password field
	 * @return the passwordField used for the password
	 */
	public JPasswordField getPasswordField() {
		return passwordField;
	}

}
