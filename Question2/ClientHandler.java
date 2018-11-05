
// Assignment3  , Question 2 
//ClientHandler Class 
// Created by Simran Kaur and Syed Turab on 2018-11-02
// The purpose of this class is to conn-currently run mutliple clients.
import java.net.*;
import java.io.*;
import java.util.Scanner;



public  class ClientHandler implements Runnable {
 private final Socket clientSocket; // private client socket 

 //constructor 
 public  ClientHandler(Socket socket){
 	this.clientSocket = socket;
 }

@Override // overriding method run 
public void run() { 
PrintWriter output = null;  // printwriter is null
BufferedReader input = null;  // bufferedreader is null 
try {  // try clause
 output =  new PrintWriter(clientSocket.getOutputStream(),true); // output in the printwriter
 input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));  //input  in the buffered reader
 String line; // string line represents client input
 while ((line = input.readLine()) !=null) {  // while there is client input
 	System.out.printf ("This was sent from the client: %s\n", line); // display the message from the client 
 	output.println(line);

 	if (line.equals(".")){ // when the client enters ".", close the connection
                break;
            }

 }
} catch (IOException e){ // catch exception
	e.printStackTrace();
} finally {
	try { 
		if (output !=null) { // if output is not null, close the output
			output.close();
		}
	
	if (input !=null)  // if input is not null, close the input
		input.close();
		clientSocket.close(); // close the clientSocket 
	
} catch (IOException e) { // 
  e.printStackTrace();
}


        }

        





}
}

