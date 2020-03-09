import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.swing.JOptionPane;

/**
 * The following class implements the ActionListener interface. The class listens for actions 
 * by the Create button, which reads data from a text file and creates the binary search tree.
 * This class is controlled by the Controller class
 * 
 * @author Boma Nkwonta & Colton Osterlund
 * @Version 1.0
 * @Since March 29, 2019
 *
 */
class CreateBtnListener implements ActionListener {

	private Controller controller;

	/**
	 * The following method is the constructor for the Create button listener
	 * 
	 * @param controller the controller object which will control the usage of this
	 *                   button
	 */
	public CreateBtnListener(Controller controller) {
		this.controller = controller;
	}

	/**
	 * The following method is a method of the ActionListener interface. This method
	 * listens for actions sent by the Create button which creates the binary search
	 * tree by reading through a text file and sorting the nodes
	 * 
	 */
	public void actionPerformed(ActionEvent actionEvent) {
		String fileName = JOptionPane.showInputDialog("Enter the filename:");
		Scanner fileIn = null;

		try {
			fileIn = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			JOptionPane.showMessageDialog(null, "File not found", "Error Message", JOptionPane.PLAIN_MESSAGE);
			return;
		}

		controller.setBinTree(new BinSearchTree());

		while (fileIn.hasNextLine()) {
			controller.getBinTree().insert(Integer.parseInt(fileIn.next()), fileIn.next(), fileIn.next(),
					fileIn.next());
		}

		fileIn.close();

		JOptionPane.showMessageDialog(null, "Binary search tree was loaded succesfully", "Success",
				JOptionPane.PLAIN_MESSAGE);
	}
}
