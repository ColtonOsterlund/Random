import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

/**
 * The following class implements the ActionListener interface to listen for actions 
 * by the Find button. The class then searches for a student node containing a specific
 * studentID to locate the intended student. This class is controlled by the Controller class
 * 
 * @author Boma Nkwonta & Colton Osterlund
 * @Version 1.0
 * @Since March 29, 2019
 *
 */
class FindBtnListener implements ActionListener {

	private Controller controller;

	/**
	 * The following method is the constructor for the Find button listener
	 * 
	 * @param controller the controller object which will control the usage of this
	 *                   button
	 */
	public FindBtnListener(Controller controller) {
		this.controller = controller;
	}

	/**
	 * The following method is a method of the ActionListener interface. This method
	 * listens for actions sent by the Find button to search the binary search tree
	 * for the student node with a specific studentID
	 * 
	 */
	public void actionPerformed(ActionEvent actionEvent) {
		if (controller.getBinTree() == null || controller.getBinTree().empty()) {
			JOptionPane.showMessageDialog(null, "Must first create tree from file", "Error Message",
					JOptionPane.PLAIN_MESSAGE);
			return;
		}

		int studentId = Integer.parseInt(JOptionPane.showInputDialog("Enter the students ID:"));

		Node studentNode = controller.getBinTree().find(controller.getBinTree().root, studentId);

		if (studentNode == null) {
			JOptionPane.showMessageDialog(null, "Student not found", "Error Message", JOptionPane.PLAIN_MESSAGE);
			return;
		}

		JOptionPane.showMessageDialog(null, studentNode.toString(), "Student Found", JOptionPane.PLAIN_MESSAGE);

	}
}
