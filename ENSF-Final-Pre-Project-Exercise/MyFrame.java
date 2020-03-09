import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.util.Scanner;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;

//MCV VIEW

/**
 * Class containing methods and data to create a simple GUI Frame to run the application.
 * @author Colton Osterlund & Boma Nkwonta
 * @Version 1.0
 * @Since March 29th, 2019
 *
 */
public class MyFrame extends javax.swing.JFrame{
/**
 * JButton displaying "insert"
 */
	private JButton insertBtn;
	/**
	 * JButton displaying "find"
	 */
	private JButton findBtn;
	/**
	 * JButton displaying "browse"
	 */
	private JButton browseBtn;
	/**
	 * JButton displaying "create"
	 */
	private JButton createBtn;
	/**
	 * JTextArea to display the list of students to the user
	 */
	private JTextArea textArea;
	/**
	 * JScrollPane to scroll the list of students in the JTextArea
	 */
	private JScrollPane scrollPane;
	/**
	 * JTitleArea to display the title of the application within the window
	 */
	private JLabel titleLabel;
	/**
	 * JPanel to enclose titleLabel
	 */
	private JPanel titlePanel;
	/**
	 * JPanel to enclose textArea
	 */
	private JPanel textPanel;
	/**
	 * JPanel to enclose all the JButton objects
	 */
	private JPanel buttonPanel;
	/**
	 * Container of the JFrame
	 */
	private Container container;
	
	/**
	 * Constructor that instantiates the JFrame and all of its internal components and displays to the screen for the user
	 */
	public MyFrame() {
		this.setFrame();
		this.initializePanels();
		this.initializeComponents();
		this.addComponentsToPanels();
		this.addPanelsToFrame();
		this.pack();
		this.setVisible(true);
	}
	
	/**
	 * Sets the Size, Title and Layout of the JFrame object
	 */
	public void setFrame() {
		setSize(1500, 1000);
		setTitle("Main Window");
		setLayout(new BorderLayout());
	}
	
	/**
	 * Initializes all the internal JPanels of the JFrame
	 */
	public void initializePanels() {
		//creating new panels
		titlePanel = new JPanel();
		textPanel = new JPanel();
		buttonPanel = new JPanel();
	}
	
	/**
	 * Initializes all the internal JButton, JTextArea and JScrollPane components of the JTextFrame and sets their font/font size
	 */
	public void initializeComponents() {
		titleLabel = new JLabel("Student Record Application");
		titleLabel.setFont(new Font("Serif", Font.PLAIN, 30));
		
		insertBtn = new JButton("Insert");
		insertBtn.setFont(new Font("Serif", Font.PLAIN, 30));
		
		
		findBtn = new JButton("Find");
		findBtn.setFont(new Font("Serif", Font.PLAIN, 30));
		
		
		browseBtn = new JButton("Browse");
		browseBtn.setFont(new Font("Serif", Font.PLAIN, 30));
		
		
		createBtn = new JButton("Create Tree from File");
		createBtn.setFont(new Font("Serif", Font.PLAIN, 30));
		
		
		textArea = new JTextArea(20, 80);
		textArea.setFont(new Font("Serif", Font.PLAIN, 20));
		scrollPane = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scrollPane.getVerticalScrollBar().setPreferredSize(new Dimension(25, 0));
		scrollPane.getHorizontalScrollBar().setPreferredSize(new Dimension(0, 25));
		
		
		UIManager.put("OptionPane.minimumSize",new Dimension(600,200));
		UIManager.put("OptionPane.messageFont", new Font("Serif", Font.PLAIN, 30));
		UIManager.put("OptionPane.buttonFont", new Font("Serif", Font.PLAIN, 30));
		UIManager.put("TextField.font", new Font("Serif", Font.PLAIN, 30));
	}
	
	/**
	 * Adds all JButton, JTextArea and JScrollPane components to the internal JPanels of the JFrame
	 */
	public void addComponentsToPanels() {
		//adding components to the panels
		titlePanel.add(titleLabel);
		
		textPanel.add(textArea);
		scrollPane.getViewport().add(textArea);
		textPanel.add(scrollPane);
		
		buttonPanel.add(insertBtn);
		
		buttonPanel.add(findBtn);
		
		buttonPanel.add(browseBtn);
		
		buttonPanel.add(createBtn);
	}
	
	/**
	 * Adds all the internal JPanels to the JFrame object
	 */
	public void addPanelsToFrame() {
		container = getContentPane();
		container.add("North", titlePanel);
		container.add("Center", textPanel);
		container.add("South", buttonPanel);
	}
	
	/**
	 * Registers an ActionListener object to the insertBtn JButton
	 * @param listener ActionListener to be registered to the JButton
	 */
	public void setInsertBtnListener(ActionListener listener) {
		insertBtn.addActionListener(listener);
	}
	
	/**
	 * Registers an ActionListener object to the createBtn JButton
	 * @param listener ActionListener to be registered to the JButton
	 */
	public void setCreateBtnListener(ActionListener listener) {
		createBtn.addActionListener(listener);
	}
	
	/**
	 * Registers an ActionListener object to the findBtn JButton
	 * @param listener ActionListener to be registered to the JButton
	 */
	public void setFindBtnListener(ActionListener listener) {
		findBtn.addActionListener(listener);
	}
	
	/**
	 * Registers an ActionListener object to the browseBtn JButton
	 * @param listener ActionListener to be registered to the JButton
	 */
	public void setBrowseBtnListener(ActionListener listener) {
		browseBtn.addActionListener(listener);
	}
	
	/**
	 * Returns the JTextArea textArea
	 * @return JTextArea textArea
	 */
	public JTextArea getTextArea() {
		return textArea;
	}

	public static void main(String [] args) {
		MyFrame frame = new MyFrame();
	}
}



