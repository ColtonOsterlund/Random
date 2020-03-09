package Client.Model;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;
import java.util.Properties;

import javax.mail.Message;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import Client.Controller.ClientCommunicationController;
import Client.Controller.ClientGUIController;

/**
 * This class contains methods and data to create a ForgotBtnListener for the ForgotBtn in the Login frame
 * @author Boma Nkwonta & Colton Osterlund
 *
 */
public class ForgotBtnListener implements ActionListener {
	/**
	 * ClientGUIController object aggregated to this Listener class
	 */
	private ClientGUIController guiController;
	/**
	 * ClientCommunicationController object aggregated to this Listener class
	 */
	private ClientCommunicationController comController;

	/**
	 * The constructor for this class sets its ClientGUIController and ClientCommunicationController objects
	 * from the parameters given to it via aggregation
	 * @param guiController Object of ClientGUIController that is set to the class
	 * @param comController Object of ClientCommunicationController that is set to class
	 */
	public ForgotBtnListener(ClientGUIController guiController, ClientCommunicationController comController) {
		this.guiController = guiController;
		this.comController = comController;
	}

	/**
	 * This method sends the string 10 to the server. The method displays a pane to 
	 * gather the users username, then accesses the database to find the user and 
	 * uses the java.mail and java activation rar files to access the developers email address 
	 * and send an email to the client containing their password
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		JTextField field1 = new JTextField();
		field1.setFont(new Font("Plain Titling", Font.PLAIN, 20));

		Object[] message = { "Username:", field1 };

		int option = JOptionPane.showConfirmDialog(null, message, "Enter the Following Values",
				JOptionPane.OK_CANCEL_OPTION);

		if (option == JOptionPane.OK_OPTION) {
			String username = field1.getText();
			
			comController.sendServer("10");
			comController.sendServer(username);
			String email = comController.readServerLine();
			
			if(email.contentEquals("Username Does Not Exist")) {
				JOptionPane.showMessageDialog(null, email, "Error", JOptionPane.ERROR_MESSAGE);
				return;	
			}
			
			String password = comController.readServerLine();

			String host = "smtp.gmail.com";
			String user = "bomacolton@gmail.com";
			String pass = "Gmcia330@";
			String to = email;
			String from = "bomacolton@gmail.com";
			String subject = "This is your Shop password";
			String messageText = "Your password is : " + password;

			try {
				Properties props = System.getProperties();

				props.put("mail.smtp.starttls.enable", "true");
				props.put("mail.smtp.host", host);
				props.put("mail.smtp.port", "587");
				props.put("mail.smtp.auth", "true");
				props.put("mail.smtp.starttls.required", "true");
				props.put("mail.smtp.debug", "true");
				props.put("mail.user", user);
				props.put("mail.password", pass);

				java.security.Security.addProvider(new com.sun.net.ssl.internal.ssl.Provider());
				Session mailSession = Session.getDefaultInstance(props, null);
				mailSession.setDebug(true);

				Message msg = new MimeMessage(mailSession);
				msg.setFrom(new InternetAddress(from));
				msg.addRecipient(Message.RecipientType.TO, new InternetAddress(to));
				msg.setSubject(subject);
				msg.setSentDate(new Date());
				msg.setText(messageText);

				Transport transport = mailSession.getTransport("smtp");
				transport.connect(host, user, pass);
				transport.sendMessage(msg, msg.getAllRecipients());
				transport.close();
				JOptionPane.showMessageDialog(null, "Email has been sent to " + email + " containing your password", "Success", JOptionPane.INFORMATION_MESSAGE);
			} catch (Exception ex) {
				System.out.println(ex);
			}

		}
	}
}