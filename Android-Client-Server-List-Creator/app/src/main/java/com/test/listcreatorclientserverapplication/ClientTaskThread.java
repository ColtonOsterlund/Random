package com.test.listcreatorclientserverapplication;

public class ClientTaskThread implements Runnable {

    Client client;
    String stringToSend;

    public ClientTaskThread(Client client, String stringToSend){
        this.client = client;
        this.stringToSend = stringToSend;
    }

    public void run(){
        //write to stream
        client.getOutStream().println(stringToSend);
    }

}
