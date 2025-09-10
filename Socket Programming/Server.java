import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
public class Server
{
    public static void main(String[] args) {

     try (  ServerSocket serverSocket=new ServerSocket(62215);)
     {

    System.out.println("Server listening on port 62215");

    Socket clientSocket=serverSocket.accept();
    System.out.println("Client connected");

    BufferedReader in=new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

       PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

        String message = in.readLine();
        System.out.println("Message from client: " + message);

        out.println("Hello from Server");

        in.close();
        out.close();
        clientSocket.close();
        serverSocket.close();
     }
     catch(IOException e) {e.printStackTrace();}
        
    }
}