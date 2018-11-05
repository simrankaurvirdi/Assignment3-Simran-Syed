// EchoClient.java
// Assignment3  , Question 2 
// Echo Client Class 
// Created by Simran Kaur and Syed Turab on 2018-11-02

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class EchoClient {
    public static void main (String[] args){
        
        String host = "127.0.0.1"; // loop back (local host)
        int port = 9789; // the port
         
        try (Socket socket = new Socket (host, port)) { 
            PrintWriter output = new PrintWriter(socket.getOutputStream(),true); // input
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));  //output 
            Scanner scanner = new Scanner(System.in);  // scan the input for client  
            String inputline = null; 
            while (!"exit".equalsIgnoreCase(inputline)) { 
                inputline = scanner.nextLine(); 
                output.println(inputline); // pointing to the server 
                output.flush(); // deleting content from the buffer 
                System.out.println("The Server responded:" + input.readLine());
                
                
                
            }
        } catch (IOException e){//catching any exception
        }
    }
    }          
            
    
    
    

