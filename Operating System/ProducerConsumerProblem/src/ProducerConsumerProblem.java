import java.util.LinkedList;
import java.util.Scanner;

public class ProducerConsumerProblem {
    
    public static class ProducerConsumer {
        LinkedList<Integer> list = new LinkedList<>();
        public int globalValue = 0;
        int capacity;
        int totalItem;

        ProducerConsumer(int capacity, int totalItem) {
            this.capacity = capacity;
            this.totalItem = totalItem;
        }

        public void produce() throws InterruptedException {
            int item = 1;
            do {
                synchronized (this) {
                    while (list.size() == capacity) {
                        wait();
                    }

                    list.add(item);
                    System.out.println("Producer "+ item +": Data " + item*5 + " inserted in the buffer");
                    globalValue++;
                    int temp = capacity-globalValue;
                    System.out.println("Empty Space: " + temp);
                    System.out.println("Full Space: " + globalValue);
                    
                    item++;

                    notify();
                    Thread.sleep(1000);
                }
            } while (item <= totalItem);
        }

        public void consume() throws InterruptedException {
            int item = 1;
            do {
                synchronized (this) {
                    while (list.size() == 0) {
                        wait();
                    }

                    item = list.removeFirst();
                    System.out.println("Consumer "+ item +": Consumed Data " + item*5 + " from the buffer" );
                    globalValue--;
                    System.out.println("Full Space: " + globalValue);
                    
                    notify();
                    Thread.sleep(1000);
                }
            } while (item <= totalItem);
        }
    }

    public static void main(String[] args) throws InterruptedException {
     
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of item: ");
        int item = sc.nextInt();
        System.out.println("Enter buffer capacity: ");
        int capacity = sc.nextInt();
        
        ProducerConsumer pc = new ProducerConsumer(capacity, item);

        Thread producerThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread consumerThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        producerThread.start();
        consumerThread.start();
        producerThread.join();
        consumerThread.join();
    }
}
