package Server.Controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import Server.Model.ServerDatabaseAccessor;

/**
 * This class contains data and methods to run a thread pool for the server side of the project
 * @author Colton Osterlund & Boma Nkwonta
 *
 */
public class ShopThread implements Runnable{

	/**
	 * Socket object to make a connection with the client
	 */
	private Socket sock;
	/**
	 * BufferedReader object to read from the socket
	 */
	private BufferedReader sockIn;
	/**
	 * PrintWriter object to print to the socket
	 */
	private PrintWriter sockOut;
	/**
	 * ServerDatabaseAccessor object to be associated with this ShopThread object
	 */
	private ServerDatabaseAccessor servDBControl;
	/**
	 * Double to keep track of the running session price of the customer client
	 */
	private double runningSessionTotal;
	
	/**
	 * This constructor sets the socket and database accessors of the class and creates new input an output writers for
	 * the socket
	 * @param sock Socket object being set to class
	 * @param servDBControl ServerDatabaseAccessor object being set to class
	 */
	public ShopThread(Socket sock, ServerDatabaseAccessor servDBControl) {
		this.sock = sock;
		
		try {
			sockIn = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			sockOut = new PrintWriter(sock.getOutputStream(), true);
			runningSessionTotal = 0;
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		this.servDBControl = servDBControl;
	}
	
	/**
	 * This method receives string inputs from the client side of the program and sends back server method outputs
	 * appended with other characters for the client side to read and operate as it needs to
	 */
	@Override
	public void run() {
		boolean servRunning = true;
		String clientCommand = "";
		while (servRunning) {

			try {
				clientCommand = sockIn.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(1);
			}

			switch (clientCommand) {
			case "0":
				servRunning = false;
				break;

			case "1":
				try {
					this.sendStringToClient(servDBControl.queryAddItem(sockIn.readLine(), sockIn.readLine(), sockIn.readLine(), sockIn.readLine(), sockIn.readLine()) + "TERMINATE\n");
				}catch(IOException e) {
					e.printStackTrace();
				}
				break;

			case "2":
				try {
					this.sendStringToClient(servDBControl.queryRemoveItem(sockIn.readLine()) + "TERMINATE\n");
				} catch (IOException e) {
					e.printStackTrace();
				}

				break;

			case "3":
				try {
					this.sendStringToClient(servDBControl.querySearchByName(sockIn.readLine()) + "TERMINATE\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;

			case "4":
				try {
					this.sendStringToClient(servDBControl.querySearchById(sockIn.readLine()) + "TERMINATE\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;

			case "5":
				this.sendStringToClient(servDBControl.queryListAll() + "TERMINATE\n");
				break;

			case "6":
				try {
					this.sendStringToClient(servDBControl.queryBuyItem(sockIn.readLine()) + "TERMINATE\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;

			case "7":
				try {
					runningSessionTotal += Double.parseDouble(servDBControl.queryGetItemPrice(sockIn.readLine()));
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;
				
			case "8":
				try {
					this.sendStringToClient(servDBControl.queryAddUser(sockIn.readLine(), sockIn.readLine(), sockIn.readLine(), sockIn.readLine()) + "\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;
				
			case "9":
				try {
					this.sendStringToClient(servDBControl.queryValidateUser(sockIn.readLine(), sockIn.readLine()) + "\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;
				
			case "10":
				try {
					this.sendStringToClient(servDBControl.queryReturnEmailPassword(sockIn.readLine()) + "\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;
				
			case "11":
					this.sendStringToClient(servDBControl.returnOrder() + "TERMINATE\n");
				break;
				
			case "12":
				this.sendStringToClient(Double.toString(runningSessionTotal) + "\n");
				runningSessionTotal = 0; //reset runningSessionTotal for the next user
				break;
				
			}

		}

		sockOut.close();
		try {
			sockIn.close();
			sock.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	
	/**
	 * This method sends a string to the Client Communication Controller using the socket connection between the two 
	 * controllers
	 * @param toSend String being sent to the Client Communication Controller
	 */
	private void sendStringToClient(String toSend) {
		sockOut.print(toSend);
		sockOut.flush();
	}

}
