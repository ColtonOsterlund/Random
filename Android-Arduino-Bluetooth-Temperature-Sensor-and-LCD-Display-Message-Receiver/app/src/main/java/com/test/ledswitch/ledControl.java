package com.test.ledswitch;

import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.util.UUID;
import java.util.concurrent.TimeUnit;

public class ledControl extends AppCompatActivity {

    Button btnOn, btnDis, btnRef;
    TextView temp;
    EditText message = null;
    String address = null;
    String txtmessage;
    int temperature;
    private ProgressDialog progress;
    BluetoothAdapter mBluetoothAdapter = null;
    BluetoothSocket btSocket = null;
    private boolean isBTConnected = false;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_led_control);

        Intent newint = getIntent();
        address = newint.getStringExtra(DeviceList.EXTRA_ADDRESS);

        btnOn = (Button)findViewById(R.id.button2);
        btnDis = (Button)findViewById(R.id.button4);
        btnRef = (Button)findViewById(R.id.button5);
        temp = (TextView)findViewById(R.id.textView3);
        message = (EditText)findViewById(R.id.textedit);


        ConnectBT bt = new ConnectBT();
        bt.execute();

        btnOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                turnOnLed();
            }
        });

        btnDis.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Disconnect(); //close connection
            }
        });

        btnRef.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                refreshTemp();
            }
        });
    }

    private void Disconnect(){
        if (btSocket!=null) //If the btSocket is busy
        {
            try
            {
                btSocket.close(); //close connection
            }
            catch (IOException e)
            { msg("Error");}
        }
        finish(); //return to the first layout
    }

    private void turnOnLed()
    {
        if (btSocket!=null)
        {
            try
            {
                btSocket.getOutputStream().write("a".toString().getBytes());
            }
            catch (IOException e)
            {
                msg("Error");
            }
        }

        txtmessage = message.getText().toString();

            try {
                btSocket.getOutputStream().write(txtmessage.getBytes());
            } catch (IOException e) {
                e.printStackTrace();
            }
    }

    private void refreshTemp(){
        if(btSocket!=null){
            try
            {
                btSocket.getOutputStream().write("c".toString().getBytes()); //tell arduino to re-read temperature and send value to input stream
            }
            catch (IOException e)
            {
                msg("Error");
            }


            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            try {
                temperature = btSocket.getInputStream().read();
            } catch (IOException e) {
                e.printStackTrace();
            }

            temp.setText(Integer.toString(temperature) + " °C");
        }
    }

    private class ConnectBT extends AsyncTask<Void, Void, Void>  // UI thread --- THIS CLASS MIGHT NEED TO BE PLACED OUTSIDE OF THE ledControl CLASS
    {
        private boolean ConnectSuccess = true;

        @Override
        protected void onPreExecute()
        {
            progress = ProgressDialog.show(ledControl.this, "Connecting...", "...");
        }

        @Override
        protected Void doInBackground(Void... devices)
        {
            try
            {
                if (btSocket == null || !isBTConnected)
                {
                    mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();//get the mobile bluetooth device
                    BluetoothDevice dispositivo = mBluetoothAdapter.getRemoteDevice(address);//connects to the device's address and checks if it's available
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);//create a RFCOMM (SPP) connection
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();//start connection
                }
            }
            catch (IOException e)
            {
                ConnectSuccess = false;
            }
            return null;
        }
        @Override
        protected void onPostExecute(Void result) //after the doInBackground, it checks if everything went fine
        {
            super.onPostExecute(result);

            if (!ConnectSuccess)
            {
                msg("Connection Failed. Is it a SPP Bluetooth? Try again.");
                finish();
            }
            else
            {
                msg("Connected.");
                isBTConnected = true;
            }
            progress.dismiss();
        }

    }

    private void msg(String s){
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }
}
