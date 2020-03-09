package com.test.listcreatorclientserverapplication;

import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

    private final String serverIP = "192.168.0.19"; //must be changed to the actual serverIP
    private final int outputPort = 5000; //must be changed to the actual port
    private Socket clientSocket;
    private BufferedReader inStream;
    private PrintWriter outStream;
    private final String TAG = "Client";

    public BufferedReader getInStream(){
        return inStream;
    }

    public PrintWriter getOutStream(){
        return outStream;
    }

    public void setClientSocket(){
        try{
            clientSocket = new Socket(serverIP, outputPort);
        }catch(UnknownHostException e){
            Log.e(TAG, "UnknownHostException while initializing socket");
            return;
         }catch(IOException e){
            Log.e(TAG, "IOException while initializing socket");
            return;
         }
    }

    public void setInStream(BufferedReader br){
        inStream = br;
    }

    public void setOutStream(PrintWriter pr){
        outStream = pr;
    }

    public String getServerIP(){
        return serverIP;
    }
    public int getOutputPort(){
        return outputPort;
    }

    public Socket getClientSocket(){
        return clientSocket;
    }
}
