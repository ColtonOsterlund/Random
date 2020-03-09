package Client.Controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * This class is for the Client Communication Controller, which will connect the client module to the server
 * module and enable communication between the two through sockets
 * @author Colton Osterlund
 *
 */
public class ClientCommunicationController {
	/**
	 * ClientGUIController object associated to this ClientCommunicationController object
	 */
	private ClientGUIController clientGUIControl;
	/**
	 * PrintWriter object to print to the socket connected to the server
	 */
	private PrintWriter socketOut;
	/**
	 * Socket object to communicate with the server
	 */
	private Socket clientComSocket;
	/**
	 * BufferedReader object to read from the socket connected to the server
	 */
	private BufferedReader socketIn;
	
	/**
	 * The constructor creates a socket with the parameters, the instantiates BufferedReader
	 * and PrintWriter objects to read and write from/to the server socket
	 * @param serverName Name of server socket will be connecting to
	 * @param portNum Port being used for socket connection
	 */
	public ClientCommunicationController(String serverName, int portNum){
		try {
			clientComSocket = new Socket(serverName, portNum);
			socketIn = new BufferedReader(new InputStreamReader(clientComSocket.getInputStream()));
			socketOut = new PrintWriter(clientComSocket.getOutputStream(), true);
		}catch (Exception e){
			e.printStackTrace();
		}
	}
	
	/**
	 * This method sends a string to the server module using the PrintWriter object
	 * @param s String being sent to the server
	 */
	public void sendServer(String s){
		System.out.print(s);
		socketOut.println(s);
		socketOut.flush();
	}
	
	/**
	 * This method reads a string from the server module using the BufferedReader object
	 * @return returns the string read from the server
	 */
	public String readServerLine() {
		String toReturn = null;
		try {
			toReturn = socketIn.readLine();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		
		return toReturn;
	}
	
	/**
	 * This method closes the BufferedReader and PrintWriter objects to close the connection between
	 * the server and client
	 */
	public void breakConnection() {
		socketOut.close();
		try{
			socketIn.close();
			clientComSocket.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * This method sets the GUI Controller in the parameter to the Client Communication Controller's GUI Controller
	 * @param clientGUIControl GUI Controller being set to the Client Communication Controller
	 */
	public void setClientGUIController(ClientGUIController clientGUIControl) {
		this.clientGUIControl = clientGUIControl;
	}

}
