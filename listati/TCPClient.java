import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String args[]) throws Exception {
	int port;
	String host, msg;
	if(args.length!=3) {
	    System.err.println("Usage: java TCPClient <host> <port> <msg>");
	    System.exit(-1);
	}
	host = args[0];
	port = Integer.parseInt(args[1]);
	msg = args[2];
	
	Socket s = new Socket(host, port);
	PrintWriter p = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));
	for(int i=0; i<10; i++) {
	    System.out.println("Sending: "+msg);
	    p.println(msg);
	    p.flush();
	    Thread.sleep(1000);
	}
	p.close();
	s.close();
    }
}