public class MyThread implements Runnable{
	private String message;
	
	public MyThread (String m) { message = m; }
	public void run() {
		for (int r = 0; r < 20; r++)
			System.out.println(message);
	}
}

class ProvaThread {
	public static void main (String[] args) {
		Thread t1, t2;
		MyThread r1, r2;
		r1 = new MyThread("PrimoThread");
		r2 = new MyThread("Secondo Thread");
		t1 = new Thread(r1);
		t2 = new Thread(r2);
		t1.start();
		t2.start();
	}
}