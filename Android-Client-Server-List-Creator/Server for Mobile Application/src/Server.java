import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	ServerSocket servSocket;
	Socket socket;
	private PrintWriter socketOut;
	private BufferedReader socketIn;
	
	public Server(int port, int backlog) {
		try {
		servSocket = new ServerSocket(port, backlog);
		}catch(IOException e) {
			System.out.print("Error creating ServerSocket object");
			e.printStackTrace();
		}
		
		System.out.println("Server Started");
		
		try {
			socket = servSocket.accept();
			}catch(IOException e) {
				System.out.print("Error accepting connection");
				e.printStackTrace();
			}
			System.out.println("Server Connected");
			
			try {
				socketIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			}catch(IOException e) {
				System.out.println("Error creating input stream");
				e.printStackTrace();
			}
			
			try {
			socketOut = new PrintWriter(socket.getOutputStream(), true); //boolean auto-flushes the PrintWriter
			}catch(IOException e) {
				System.out.print("Error creating output stream");
				e.printStackTrace();
			}
	}
	
	public void runServer() {
		String word = "";
		
		while(true) {
			try {
				word = socketIn.readLine();
			}catch(IOException e) {
				System.out.println("Error reading input");
				e.printStackTrace();
			}
			
			if(word.contentEquals("0"))
				return;
			
			System.out.println(word);
			
		}
		
	}
	
	public void closeSockets() {
		try {
		socketIn.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
		socketOut.close();
		try {
		socket.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String [] args) {
		Server server = new Server(5000, 10);
		server.runServer();
		server.closeSockets();
	}
}
