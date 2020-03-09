import java.net.*;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.io.*; 

public class Server {
    private ServerSocket server = null; 
    private DataInputStream das = null;
    private DataOutputStream dos = null;
    Scanner scan = null;
    private final ExecutorService pool = Executors.newFixedThreadPool(3);
	
	
	public Server(int port) {
		
		try {
			server = new ServerSocket(port);
			System.out.println("Server started");
			
			System.out.println("Waiting for client requests...");
			try {
				scan = new Scanner(System.in);
				for(int i = 0; i < 5; i++) {
					pool.execute(new ClientThread(server.accept()));
					i--;
				}
			}catch(IOException e) {
					System.out.println("IOException, shutting down pool");
					pool.shutdown();
				}
			
			pool.shutdown();
			
		}catch(IOException i) {
			System.out.println("IOException");
			i.printStackTrace();
		}
		
	}
	
	public static void main(String [] args) {
		Server server = new Server(5000);
	}
}
