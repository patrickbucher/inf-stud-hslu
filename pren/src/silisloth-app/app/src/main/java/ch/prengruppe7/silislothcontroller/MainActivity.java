package ch.prengruppe7.silislothcontroller;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;

public class MainActivity extends AppCompatActivity {
    TcpClient tcpClient;
    EditText editTextXAchse;
    EditText editTextZAchse;
    Button buttonStart;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editTextXAchse = findViewById(R.id.editTextXValue);
        editTextZAchse = findViewById(R.id.editTextZValue);
        buttonStart = findViewById(R.id.buttonStart);
    }

    public void startButtonClicked(View view) throws InterruptedException {
        String buttonText = buttonStart.getText().toString();
        if(buttonText.equals("Start")) {
            buttonStart.setText("Stop");

            //Start connection with server
            new ConnectTask().execute("");
        }
        else {
            buttonStart.setText("Start");
            tcpClient.stopClient();
            editTextXAchse.setText("0");
            editTextZAchse.setText("0");

        }

    }

    public class ConnectTask extends AsyncTask<String, String, TcpClient> {

        @Override
        protected TcpClient doInBackground(String... message) {

            //we create a TCPClient object
            tcpClient = new TcpClient(new TcpClient.OnMessageReceived() {
                @Override
                //here the messageReceived method is implemented
                public void messageReceived(String message) {
                    //this method calls the onProgressUpdate
                    publishProgress(message);
                }
            }, "192.168.88.7");   //192.168.88.7 = static IP of the Raspberry

            tcpClient.run();

            return null;
        }

        @Override
        protected void onProgressUpdate(String... values) {
            super.onProgressUpdate(values);
            //response received from server
            Log.d("test", "response " + values[0]);
            //process server response here....

            String message = values[0];
            String[] xAndzValues = message.split(";");
            String xValue = xAndzValues[0].replaceAll("x=","");
            String zValue = xAndzValues[1].replaceAll("z=","");

            if(Integer.parseInt(xValue) >= 0)
                editTextXAchse.setText(xValue);

            if(Integer.parseInt(zValue) >= 0)
                editTextZAchse.setText(zValue);
        }
    }
}
