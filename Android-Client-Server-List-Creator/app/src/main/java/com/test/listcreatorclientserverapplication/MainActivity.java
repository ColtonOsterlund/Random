package com.test.listcreatorclientserverapplication;

import android.support.design.widget.TextInputEditText;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import java.io.IOException;


public class MainActivity extends AppCompatActivity { //essentially same as the main method
    private final String TAG = "MainActivity";

    private Button sendBtn;
    private TextInputEditText stringToSend;

    Client client;

    @Override
    protected void onCreate(Bundle savedInstanceState) { //this is run when the app is created
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setGUIComponents(); //set the findViewIds for all GUI components

        client = new Client();
        ConnectionThread conThread = new ConnectionThread(client, getApplicationContext());
        Thread ct = new Thread(conThread);
        ct.start();
        try {
            ct.join();
        }catch(InterruptedException e){
            Log.e(TAG, "InterruptedException while joining conThread");
        }

        setListeners();
    }

    @Override
    protected void onDestroy(){
        client.getOutStream().println("0"); //apparently only reading from the network needs to be done in a seperate thread, you can print to the network just fine
        try {
            client.getInStream().close();
        }catch(IOException e){
            Log.e(TAG, "IOException while closing inStream");
        }
        client.getOutStream().close();
        try {
            client.getClientSocket().close();
        }catch(IOException e) {
            Log.e(TAG, "IOException thrown while closing clientSocket");
        }

        super.onDestroy();
    }

    private void setGUIComponents() {
        sendBtn = (Button) findViewById(R.id.storeBtn);
        stringToSend = (TextInputEditText) findViewById(R.id.textIn);
    }


    private void setListeners() {
        sendBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Thread clientTaskThread = new Thread(new ClientTaskThread(client, stringToSend.getText().toString()));
                clientTaskThread.start();
                try {
                    clientTaskThread.join();
                }catch(InterruptedException e){
                    Log.e(TAG, "InterruptedException while joining clientTaskThread");
                }
            }
        });
    }
}
