package com.test.listcreatorclientserverapplication;

import android.app.Activity;
import android.content.Context;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class ConnectionThread implements Runnable {
    private final String TAG = "ConnectionThread";
    Client client;
    Context context;
    private Activity parentActivity;

    public ConnectionThread(Client client, Context context){
        this.client = client;
        this.context = context;
    }

    public void run(){
        initiateServerConnection();
        setStreams();
    }


    private synchronized void initiateServerConnection(){
        client.setClientSocket();

//        if(!(client.getClientSocket() == null))
//            Toast.makeText(context, "Connected to Server", Toast.LENGTH_SHORT).show(); //research what getApplicationContext is
    }

    private synchronized void setStreams(){
        try {
            client.setInStream(new BufferedReader(new InputStreamReader(client.getClientSocket().getInputStream())));
        }catch(IOException e){
            Log.e(TAG, "IOException while initializing inStream");
        }
        try {
            client.setOutStream(new PrintWriter((client.getClientSocket().getOutputStream()), true));
        }catch(IOException e){
            Log.e(TAG, "IOException while initializing outStream");
        }

    }

}
