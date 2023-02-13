#include<stdio.h>
#define size 5
int queue[size],front=-1,rear=-1;

void enqueue(){
	int data;
	if((rear+1)%size==front){
		printf("Can't enqueue since the circular queue is full");
	}
	else{
		printf("\nEnter the data to enqueue: ");
		scanf("%d",&data);
		if(front == -1 && rear == -1){
			front++;
			rear++;
			queue[rear]=data;
		}
		else{
			rear = (rear+1)%size;
			queue[rear]=data;
		}
	}
	printf("[ %d ] is inserted in circular queue",data);
}

void dequeue(){
	if((rear+1)%size==front){
		printf("Can't dequeue since the circular queue is full");
	}
	else{
		printf("dequeued element is [ %d ]\n",queue[front]);
		if(front == rear){
			front =-1;
			rear = -1;
		}
		else{
			front = (front+1)%size;
		}
	}
}

void display(){
	int i=front;
	if(front ==-1 && rear ==-1 ){
		printf("Can't display since the circular queue is empty\n");
	}
	else{
		while(i!=rear){
			printf("[ %d ]   ",queue[i]);
			i=(i+1)%size;
		}
		printf("[ %d ]\n",queue[rear]);
	}
}

void peek(){
	if(front ==-1 && rear ==-1 ){
		printf("Can't display since the circular queue is empty\n");
	}
	else{
		printf("Peek element is [ %d ]\n",queue[front]);
	}
}

void main(){
	int ch;
	while(99){
		printf("1 -> Enqueue\n2 -> dequeue\n3 -> display\n4 -> peek element\n5 -> exit from the program\n\tEnter yor choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 4:peek();break;
			case 5:exit(1);
		}
	}
}
