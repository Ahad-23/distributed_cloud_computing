import java.io.*;
import java.net.*;
public class Client
{
    public static void main(String[] args) {
        try(Socket socket = new Socket("localhost", 62215);)
{
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream()));

        out.println("Hello Server");
        String response = in.readLine();
        System.out.println("Server says: " + response);

        in.close();
        out.close();
        socket.close();}
        catch(Exception e){ e.printStackTrace();}
    }
}