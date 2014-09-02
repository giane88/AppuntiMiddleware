import java.net.*;
import java.io.*;

public class TCPServer {
    public static void main(String[] args) throws java.io.IOException {
	int port;
	ServerSocket sock;
	Socket s;
	BufferedReader in;
	String line;
	// Parse command line arguments
	if(args.length!=1) {
	    System.err.println("Usage: java Server <port>");
	    System.exit(-1);
	}
	port = Integer.parseInt(args[0]);
	// Create the server socket
	sock = new ServerSocket(port);
	// Accept incoming requests (main loop)
	while(true) {
	    // Accept a new connection
	    s = sock.accept();
	    // Receive incoming data
	    in = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    while((line = in.readLine())!=null) {
		System.out.println(line);
	    } 
	} 
    } 
}

