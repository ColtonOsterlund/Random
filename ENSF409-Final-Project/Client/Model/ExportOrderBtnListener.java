package Client.Model;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import javax.swing.JOptionPane;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;


/**
 * This class contains methods and data to create a ExportOrderBtnListener for the ExportOrderBtn in the Clerk frame
 * @author Colton Osterlund
 *
 */
public class ExportOrderBtnListener implements ActionListener{
	/**
	 * ClientGUIController object aggregated to this Listener class
	 */
	private ClientGUIController guiController;
	/**
	 * ClientCommunicationController object aggregated to this Listener class
	 */
	private ClientCommunicationController comController;
	/**
	 * PrintWriter object to print to a .txt file
	 */
	private PrintWriter fileWriter;
	/**
	 * DateTimeFormatter object to get the current date/time
	 */
	private DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("yyyy_MM_dd");

	/**
	 * The constructor for this class sets its ClientGUIController and ClientCommunicationController objects
	 * from the parameters given to it via aggregation
	 * @param guiController Object of ClientGUIController that is set to the class
	 * @param comController Object of ClientCommunicationController that is set to class
	 */
	public ExportOrderBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}
	
	/**
	 * This method sends the string 11 to the server. This method constructs the order based on which
	 * item(s) has a quantity less than 40. The method then declares the fileName which the constructed order will
	 * be exported to
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		comController.sendServer("11");
		String fileName = "ShopOrder_" + dateFormat.format(LocalDateTime.now()).toString() + "_Export.txt";
		try {
			fileWriter = new PrintWriter(new File(fileName));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		//second argument of file writer sets to append mode
		
		while(true) {
			String toPrint = comController.readServerLine();
			if(toPrint.contentEquals("TERMINATE"))
				break;
			fileWriter.print(toPrint + "\n");
		}
		
		fileWriter.close();
		
	}
}
