import java.net.*;
import java.io.*;

public class Client {
	private Socket socket = null;
	private DataInputStream dis = null;
	private DataOutputStream dos = null;
	private BufferedReader br = null;
	
	Client(String serverIPAddress, int port){
		try
        { 
            socket = new Socket(serverIPAddress, port); 
            System.out.println("Connected to server"); 
  
            // takes input from terminal 
            dis = new DataInputStream(System.in); 
  
            // sends output to the socket 
            dos = new DataOutputStream(socket.getOutputStream()); //returns an output stream object for this socket
            br = new BufferedReader(new InputStreamReader(dis));
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
                line = br.readLine(); 
                dos.writeUTF(line); 
            } 
            catch(IOException i) 
            { 
                System.out.println(i); 
            } 
        } 
  
        // close the connection 
        try
        { 
            dis.close(); 
            dos.close(); 
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

