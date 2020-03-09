import java.net.*;
import java.io.*;

public class Client {
	private Socket socket = null;
	private DataInputStream inputStream = null; //input stream to receive from terminal
	private DataOutputStream outStream = null; //output stream to send to socket
	private BufferedReader d = null;
	
	Client(String ipAddress, int port){
		 try
	        { 
	            socket = new Socket(ipAddress, port); 
	            System.out.println("Connected"); 
	  
	            // takes input from terminal 
	            inputStream = new DataInputStream(System.in); 
	  
	            // sends output to the socket 
	            outStream = new DataOutputStream(socket.getOutputStream()); //returns an output stream object for this socket
	            d = new BufferedReader(new InputStreamReader(inputStream));
	        } 
	        catch(UnknownHostException u) 
	        { 
	            System.out.println("UnknownHostException Thrown: " + u); 
	        } 
	        catch(IOException i) 
	        { 
	            System.out.println("IOException Thrown: " + i); 
	        } 
		
		 
		 String line = "";
		 
		  // keep reading until "Over" is input 
	        while (!line.equals("Over")) 
	        { 
	            try
	            { 
	                line = d.readLine(); 
	                outStream.writeUTF(line); 
	            } 
	            catch(IOException i) 
	            { 
	                System.out.println(i); 
	            } 
	        } 
	  
	        // close the connection 
	        try
	        { 
	            inputStream.close(); 
	            outStream.close(); 
	            socket.close(); 
	        } 
	        catch(IOException i) 
	        { 
	            System.out.println(i); 
	        } 
	    } 
	  
	
		public static void main(String args[]) { 
			String serverIP = args[0];
			Client client = new Client(serverIP, 5000); 
		} 
	}
