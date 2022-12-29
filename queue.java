import java.util.*;
import java.lang.*;

public class queue{
    static final int size = 5;
    static int[] arr = new int[size];
    static int front = -1;
    static int rear = -1;
    static Scanner scr = new Scanner(System.in);

    static void enqueue(){
        int data;
        if(rear == size -1) {
            System.out.println("\nCant enqueue, queue is full\n");
        }
        else {
            System.out.println("\nEnter the data to enqueue : ");
            data = scr.nextInt();
            if (rear == -1) {
                front = 0;
                rear ++;
            }
            else {
                rear ++;
            }
            arr[rear]=data;
        }
    }

    static void dequeue() {
        if(front == -1) {
            System.out.println("\nCant dequeue, queue is empty\n");
        }
        else if(front == rear) {
            System.out.println(arr[front]+ " is dequeue from the queue and queue is empty\n");
            front = -1;
            rear = -1;
        }
        else {
            System.out.println("\n"+arr[front]+ " is dequeue from the queue\n");
            front ++;
        }
    }

    static void peek() {
        if(front == -1 ) {
            System.out.println("\npeek element is not exist, queue is empty\n");
        }
        else {
            System.out.println("\npeek element is "+ arr[rear]+"\n");
        }
    }

    static void display() {
        int i;
        if(front == -1 ) {
            System.out.println("\nCant dispiay, queue is empty\n");
        }
        else {
            for(i=front;i<=rear;i++) {
                System.out.println(arr[i]);
            }
        }
    }
    public static void main(String[] args) {

        queue obj = new queue();
        int ch;
        while(true) {
            System.out.print("1 -> enqueue \n2 -> dequeue \n3 -> peek \n4 -> display\n5 -> exit\nEnter the choise : \n");
            ch = scr.nextInt();
            switch (ch) {
                case 1 -> obj.enqueue();
                case 2 -> obj.dequeue();
                case 3 -> obj.peek();
                case 4 -> obj.display();
                case 5 -> System.exit(0);
                default -> System.out.println("\nInvalid, please enter the valid option\n");
            }
        }

    }
}
