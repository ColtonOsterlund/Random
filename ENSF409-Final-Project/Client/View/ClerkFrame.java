package Client.View;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import javax.swing.UIManager;
import javax.swing.border.LineBorder;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableModel;

import Client.Model.FrameWindowListener;

/**
 * This class creates the Shop from from the clerk point of view and sets all
 * buttons and listeners for said buttons
 * 
 * @author Boma Nkwonta
 *
 */
public class ClerkFrame extends javax.swing.JFrame {
	/**
	 * JButton object to instantiate a Add Item button
	 */
	private JButton addItemBtn;
	/**
	 * JButton object to instantiate a Remove Item button
	 */
	private JButton removeItemBtn;
	/**
	 * JButton object to instantiate a Search Item by ID button
	 */
	private JButton searchIDBtn;
	/**
	 * JButton object to instantiate a List All button
	 */
	private JButton listInvBtn;
	/**
	 * JButton object to instantiate a Search Item by Name button
	 */
	private JButton searchNameBtn;
	/**
	 * JButton object to instantiate a Sell Item button
	 */
	private JButton sellItemBtn;
	/**
	 * JButton object to instantiate a Export Item button
	 */
	private JButton exportOrderBtn;
	/**
	 * JButton object to instantiate a Logout Item button
	 */
	private JButton logoutBtn;
	/**
	 * JLabel object to hold the title label
	 */
	private JLabel titleLabel;
	/**
	 * JPanel object to hold the title panel
	 */
	private JPanel titlePanel;
	/**
	 * JPanel object to hold the text panel
	 */
	private JPanel textPanel;
	/**
	 * JPanel object to hold the button panel
	 */
	private JPanel buttonPanel;
	/**
	 * JContainer object to hold the JFrames container
	 */
	private Container container;
	/**
	 * JScrollPane object to give the tableArea object a scroll bar
	 */
	private JScrollPane scrollPane;
	/**
	 * JTable to hold the table to display the item inventory
	 */
	private JTable tableArea;
	/**
	 * DefaultTableModel object to edit the JTable properties
	 */
	private DefaultTableModel tableModel;

	/**
	 * The constructor for this class calls methods to set the frame, initialize the
	 * frames components, add components to the panel, and add the panel to the
	 * frame
	 */
	public ClerkFrame() {
		this.setFrame();
		try {
			this.componentInitialization();
		} catch (IOException e) {
			e.printStackTrace();
		}
		this.initializePanels();
		this.addPanelsToFrame();
		this.pack();
	}

	/**
	 * This method sets the size and title of the frame, as well as setting the
	 * layout that the frame will use
	 */
	public void setFrame() {
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		setBounds(0, 0, screenSize.width / 2, screenSize.height / 2);
		setTitle("Clerk Window");
		setLayout(new BorderLayout());
	}

	/**
	 * This method initializes the panels used in the frame and sets a color for the
	 * title panel. The method also adds the buttons to the button panel and adds
	 * the table area to the scroll pane
	 */
	public void initializePanels() {
		// creating new panels
		titlePanel = new JPanel();
		//titlePanel.add(logo);
		titlePanel.setBackground(Color.getHSBColor(200, 200, 80));

		scrollPane.getViewport().add(tableArea);

		buttonPanel = new JPanel();
		buttonPanel.add(listInvBtn);
		buttonPanel.add(addItemBtn);
		buttonPanel.add(removeItemBtn);
		buttonPanel.add(searchNameBtn);
		buttonPanel.add(searchIDBtn);
		buttonPanel.add(sellItemBtn);
		buttonPanel.add(exportOrderBtn);
		buttonPanel.add(logoutBtn);
		System.out.println(buttonPanel.getSize());
		buttonPanel.setBackground(Color.getHSBColor(200, 200, 80));
	}

	/**
	 * This method adds the panels to the frame with respect to the layout being
	 * used
	 */
	public void addPanelsToFrame() {
		container = getContentPane();
		container.add("Center", scrollPane);
		container.add("South", buttonPanel);
	}

	/**
	 * This method initializes the components in the frame by creating the table, scroll pane, table area, and all buttons
	 * @throws IOException
	 */
	public void componentInitialization() throws IOException {
		titleLabel = new JLabel("Shop Application");
		titleLabel.setFont(new Font("Plantin Titling", Font.BOLD, 45));

		tableModel = new DefaultTableModel();
		tableModel.addColumn("Item ID");
		tableModel.addColumn("Item Name");
		tableModel.addColumn("Item Quantity");
		tableModel.addColumn("Item Price ($)");
		tableModel.addColumn("Supplier ID");
		tableModel.addColumn("Supplier Name");
		tableArea = new JTable(tableModel) {
			@Override
			public boolean isCellEditable(int rowIndex, int colIndex) {
				return false; // this disables you being allowed to edit any of the cells from the gui in the
								// table by typing
			}
		};
		tableArea.setFont(new Font("Serif", Font.PLAIN, 20));
		tableArea.setRowSelectionAllowed(true);
		tableArea.setColumnSelectionAllowed(false);
		tableArea.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

		scrollPane = new JScrollPane(tableArea, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scrollPane.getVerticalScrollBar().setPreferredSize(new Dimension(25, 0));
		scrollPane.getHorizontalScrollBar().setPreferredSize(new Dimension(0, 25));

		exportOrderBtn = new JButton(" EXPORT ORDER ");
		exportOrderBtn.setBackground(Color.getHSBColor(200, 200, 80));
		exportOrderBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		exportOrderBtn.setForeground(Color.BLACK);
		exportOrderBtn.setBorder(new LineBorder(Color.BLACK, 2));

		sellItemBtn = new JButton(" SELL ITEM ");
		sellItemBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		sellItemBtn.setForeground(Color.BLACK);
		sellItemBtn.setBackground(Color.getHSBColor(200, 200, 80));
		sellItemBtn.setBorder(new LineBorder(Color.BLACK, 2));

		searchNameBtn = new JButton(" SEARCH BY NAME ");
		searchNameBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		searchNameBtn.setForeground(Color.BLACK);
		searchNameBtn.setBackground(Color.getHSBColor(200, 200, 80));
		searchNameBtn.setBorder(new LineBorder(Color.BLACK, 2));

		listInvBtn = new JButton(" LIST INVENTORY ");
		listInvBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		listInvBtn.setForeground(Color.BLACK);
		listInvBtn.setBackground(Color.getHSBColor(200, 200, 80));
		listInvBtn.setBorder(new LineBorder(Color.BLACK, 2));

		searchIDBtn = new JButton(" SEARCH BY ID ");
		searchIDBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		searchIDBtn.setForeground(Color.BLACK);
		searchIDBtn.setBackground(Color.getHSBColor(200, 200, 80));
		searchIDBtn.setBorder(new LineBorder(Color.BLACK, 2));

		removeItemBtn = new JButton(" REMOVE ITEM ");
		removeItemBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		removeItemBtn.setForeground(Color.BLACK);
		removeItemBtn.setBackground(Color.getHSBColor(200, 200, 80));
		removeItemBtn.setBorder(new LineBorder(Color.BLACK, 2));

		addItemBtn = new JButton(" ADD ITEM ");
		addItemBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		addItemBtn.setForeground(Color.BLACK);
		addItemBtn.setBackground(Color.getHSBColor(200, 200, 80));
		addItemBtn.setBorder(new LineBorder(Color.BLACK, 2));

		logoutBtn = new JButton(" LOGOUT ");
		logoutBtn.setFont(new Font("Serif", Font.PLAIN, 20));
		logoutBtn.setForeground(Color.BLACK);
		logoutBtn.setBackground(Color.getHSBColor(200, 200, 80));
		logoutBtn.setBorder(new LineBorder(Color.BLACK, 2));

		UIManager.put("OptionPane.minimumSize", new Dimension(600, 200));
		UIManager.put("OptionPane.messageFont", new Font("Serif", Font.PLAIN, 30));
		UIManager.put("OptionPane.buttonFont", new Font("Serif", Font.PLAIN, 30));
		UIManager.put("TextField.font", new Font("Serif", Font.PLAIN, 30));
	}

	/**
	 * This method adds the Object array found in the parameter to the table model so it can be 
	 * viewed in the frame 
	 * @param row Object array being added to the table model
	 */
	public void addTableRow(Object[] row) {
		tableModel.addRow(row);
	}

	/**
	 * This method sets the list inventory button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the list inventory button
	 */
	public void setListInvBtnListener(ActionListener listener) {
		listInvBtn.addActionListener(listener);
	}

	/**
	 * This method sets the add item button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the add item button
	 */
	public void setAddItemBtnListener(ActionListener listener) {
		addItemBtn.addActionListener(listener);
	}

	/**
	 * This method sets the remove item button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the remove item button
	 */
	public void setRemoveItemBtnListener(ActionListener listener) {
		removeItemBtn.addActionListener(listener);
	}

	/**
	 * This method sets the search id button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the search id button
	 */
	public void setSearchIDBtnListener(ActionListener listener) {
		searchIDBtn.addActionListener(listener);
	}

	/**
	 * This method sets the search name button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the search name button
	 */
	public void setSearchNameBtnListener(ActionListener listener) {
		searchNameBtn.addActionListener(listener);
	}

	/**
	 * This method sets the sell item button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the sell item button
	 */
	public void setSellItemBtnListener(ActionListener listener) {
		sellItemBtn.addActionListener(listener);
	}

	/**
	 * This method sets the export order button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the export order button
	 */
	public void setExportOrderBtnListener(ActionListener listener) {
		exportOrderBtn.addActionListener(listener);
	}

	/**
	 * This method sets the logout button listener to the ActionListener object in the parameter
	 * @param listener ActionListener being set to the logout button
	 */
	public void setLogoutBtnListener(ActionListener listener) {
		logoutBtn.addActionListener(listener);
	}

	/**
	 * This method sets the table area model listener to the TableModelListener object in the parameter
	 * @param listener TableModelListener being set to the table area model
	 */
	public void setTableAreaModelListener(TableModelListener listener) {
		tableModel.addTableModelListener(listener);
	}

	/**
	 * This method sets the table area mouse listener to the MouseListener object in the parameter
	 * @param listener MouseListener being set to the table area mouse
	 */
	public void setTableAreaMouseListener(MouseListener listener) {
		tableArea.addMouseListener(listener);
	}

	/**
	 * This method sets the window listener to the FrameWindowListener object in the parameter
	 * @param listener FrameWindowListener being set to the window listener
	 */
	public void setWindowListener(FrameWindowListener listener) {
		this.addWindowListener(listener);
	}

	/**
	 * This method returns the table area for the clerk frame
	 * @return The table area of the clerk frame
	 */
	public JTable getTableArea() {
		return tableArea;
	}

	/**
	 * This method returns the table model for the clerk frame
	 * @return The table model of the clerk frame
	 */
	public DefaultTableModel getTableAreaModel() {
		return tableModel;
	}

}
