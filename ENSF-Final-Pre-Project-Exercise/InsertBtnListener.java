import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;

import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 * The following class implements the ActionListener interface to listen for actions from 
 * the Insert button. The class then requests student information from the user and creates
 * a node from this information, then inserts it into the binary search tree. This class is 
 * controlled by the Controller class
 * 
 * @author Boma Nkwonta & Colton Osterlund
 * @Version 1.0
 * @Since March 29, 2019
 */
class InsertBtnListener implements ActionListener {
	private Controller controller;

	/**
	 * The following method is the constructor for the Insert button listener
	 * 
	 * @param controller the controller object which will control the usage of this
	 *                   button
	 */
	public InsertBtnListener(Controller controller) {
		this.controller = controller;
	}

	/**
	 * The following method is a method of the ActionListener interface. This method
	 * listens for actions sent by the Insert button to add a new node to the binary
	 * search tree
	 * 
	 */
	public void actionPerformed(ActionEvent actionEvent) {
		if (controller.getBinTree() == null || controller.getBinTree().empty()) {
			JOptionPane.showMessageDialog(null, "Must first create tree from file", "Error Message",
					JOptionPane.PLAIN_MESSAGE);
			return;
		}

		JTextField field1 = new JTextField();
		JTextField field2 = new JTextField();
		JTextField field3 = new JTextField();
		JTextField field4 = new JTextField();

		Object[] message = { "Student ID:", field1, "Faculty:", field2, "Student Major:", field3, "Year:", field4 };

		int option = JOptionPane.showConfirmDialog(null, message, "Enter the Following Values",
				JOptionPane.OK_CANCEL_OPTION);

		if (option == JOptionPane.OK_OPTION) {
			int studentId = Integer.parseInt(field1.getText());
			String studentFaculty = field2.getText();
			String studentMajor = field3.getText();
			String studentYear = field4.getText();

			controller.getBinTree().insert(studentId, studentFaculty, studentMajor, studentYear);
		}

		StringWriter buffer = new StringWriter();
		PrintWriter writer = new PrintWriter(buffer);
		try {
			controller.getBinTree().print_tree(controller.getBinTree().root, writer);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "Error while printing tree", "Error Message",
					JOptionPane.PLAIN_MESSAGE);
			return;
		}

		controller.getTextArea().setText(buffer.toString());

		try {
			buffer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		writer.close();
	}
}