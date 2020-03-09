import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;

import javax.swing.JOptionPane;

//MCV CONTROLLER

/**
 * Class containing all methods and data to create an ActionListener to be registered to the browseBtn JButton in the MyFrame class
 * @author Colton Osterlund & Boma Nkwonta
 * @Version 1.0
 * @since March 29th, 2019
 *
 */
class BrowseBtnListener implements ActionListener{
		/**
		 * Instance of Controller class register this ActionListener class to the proper JButton in the JFrame class 
		 */
		private Controller controller;
		
		/**
		 * Constructor to instantiate the BrowseBtnListener object and set the the controller reference to an instance of class Controller
		 * taken in as an argument.
		 * @param controller Instance of class Controller to set the controller reference to
		 */
		public BrowseBtnListener(Controller controller){
			this.controller = controller;
		}
		
		/**
		 * Waits for an ActionEvent to be instantiated by the broseButton JButton in the MyFrame class, then prints all the nodes in the\
		 * BinSearchTree object to the textArea JTextArea in the MyFrame class.
		 */
		public void actionPerformed(ActionEvent actionEvent) {
			if(controller.getBinTree() == null || controller.getBinTree().empty()) {
				JOptionPane.showMessageDialog(null, "Must first create tree from file", "Error Message", JOptionPane.PLAIN_MESSAGE);
				return;
			}
			
			StringWriter buffer = new StringWriter();
			PrintWriter writer = new PrintWriter(buffer);
			try {
				controller.getBinTree().print_tree(controller.getBinTree().root, writer);
			}catch(IOException e) {
				JOptionPane.showMessageDialog(null, "Error while printing tree", "Error Message", JOptionPane.PLAIN_MESSAGE);
				return;
			}
			
			controller.getTextArea().setText(buffer.toString());
			
			try {
			buffer.close();
			}catch(IOException e){
				e.printStackTrace();
			}
			writer.close();
			
			
		}
	}
