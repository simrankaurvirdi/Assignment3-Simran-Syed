// EchoServer.java
// Assignment3  , Question 2 
// Echo Server Class 
// Created by Simran Kaur and Syed Turab on 2018-11-02

import java.net.*;
import java.io.*;
import java.util.Scanner;


public class EchoServer { 
public static void main(String[] args) { 

ServerSocket server = null; // socket of the server

try { 
 server = new ServerSocket(9789); // new serversocket on the local port 

 while (true) { // while connection is requested to post 9789
 	Socket client = server.accept(); // accept the connection
 	System.out.println ("The client has sucessfully connected" + client.getInetAddress().getHostAddress());
 	ClientHandler clientSock = new ClientHandler(client); // calling the ClientHanlder class 

 	// thread process 

 	new Thread(clientSock).start(); // starting the thread processes

 }

} catch (IOException e){ // expection 
	e.printStackTrace();
} finally {
	if (server !=null){ // if server is not null
		try { //try
			server.close(); // close the server
		} catch (IOException e) { // catch
			e.printStackTrace();
		}
	}
}
}




}






























