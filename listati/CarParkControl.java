public class CarParkControl {
	private int space;
	private int capacity;
	
	public CarParkControl (int n) {
		capacity = space = n;
	}
	synchronized public void arrive() throws InterruptedException {
		while (space == 0) wait();
		--space;
		notifyAll();
	}
	synchronized public void depart() throws InterruptedException {
		while (space == capacity) wait();
		++space;
		notifyAll();
	}
}
