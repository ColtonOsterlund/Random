import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientThread implements Runnable{

	private final Socket socket;
	private DataOutputStream dos;
	private DataInputStream dis;
	
	ClientThread(Socket socket){
		this.socket = socket;
		try {
			dos = new DataOutputStream(socket.getOutputStream());
		}catch(IOException e) {
			System.out.println("IOException on DataOutputStream dos");
			e.printStackTrace();
		}
		try {
			dis = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
		}catch(IOException e) {
			System.out.println("IOException on DataInputStream dis");
			e.printStackTrace();
		}
	}
	
	public void run(){
		System.out.println("Starting client thread services");
		String line = "";
		
        while (!line.equals("Over")) 
        { 
            try
            { 
                line = dis.readUTF(); 
                System.out.println(line); 

            } 
            catch(IOException i) 
            { 
                System.out.println(i); 
            } 
        } 
        
         System.out.println("End of client thread services");
	}
}
