package Server.Controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import Server.Model.ServerDatabaseAccessor;

/**
 * 
 * This class is a controller that sets the server for the project. The controller instantiates the server
 * socket and connects it to the client side of the projects to enable communication between the two modules.
 * @author Colton Osterlund
 * 
 */
public class ServerCommunicationController {
	/**
	 * ServerSocket object to accept client connection requests
	 */
	private ServerSocket servSocket;
	/**
	 * ExecutorService to manage the thread pool
	 */
	private ExecutorService pool;
	/**
	 * ServerDatabaseAccessor object to have a composition relation with this ServerCommunicationController object
	 */
	private ServerDatabaseAccessor servDBController;

/**
 *  The constructor for the Server Communication Controller accepts an integer that will be used as
 *  the port number for the machine it runs on. This method will accept the client's socket that is run
 *  through the indicated port. This method also initializes the BufferedReader and PrintWriter, which will 
 *  allow the server to read from the client and send commands to the client using input and output streams
 * @param portNumber Port being used for the server socket connection with the client portion of the project
 */
	public ServerCommunicationController(int portNumber) {
		try {
			servSocket = new ServerSocket(portNumber);
			pool = Executors.newCachedThreadPool();
			System.out.println("Server has been started");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		servDBController = new ServerDatabaseAccessor();

	}

	/**
	 * This method creates a new shop thread set to accept the server socket and run in
	 * the thread pool
	 */
	public void serve() {
		Scanner scan = new Scanner(System.in);
		
		try {
			while(true) {
				ShopThread shop = new ShopThread(servSocket.accept(), servDBController);
				
				System.out.println("New client has been accepted, commencing shop thread");
				
				pool.execute(shop);
				
			}
		}catch(Exception e) {
			e.printStackTrace();
			pool.shutdown();
		}
		
		scan.close();
		pool.shutdown();
	}

	/**
	 * This is the main method of the class. This method instantiates the methods of the class,
	 * including setting the server socket and the port number
	 * @param args Command line arguments
	 */
	public static void main(String[] args) {
		ServerCommunicationController servComControl = new ServerCommunicationController(8000);
		servComControl.serve();
	}
}
