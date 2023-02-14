#include<stdio.h>
#include<stdlib.h>
#define size 5
int dequeue[size];
int front=-1,rear=-1;
void inserFront();
void insertRear();
void delectFront();
void delectRear();
void getFront();
void getRear();
void display();

void insertFront(){
    int data;
    if((rear+1)%size==front){ // if(front == rear+1  ||  front == 0 && rear == size -1)
        printf("cant insert at front since the dequeue is full\n");
    }
    else{
        printf("Enter the data to be insert at front : ");
        scanf("%d",&data);
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
        }
        else if(front == 0){
            front = size -1;
        }
        else{
            front--;	//front 0 to -1 to -2 to -3 
        }
        dequeue[front]=data;
    }
}
void insertRear(){
    int data;
    if((rear+1)%size==front){   // if(front == rear+1  ||  front == 0 && rear == size -1)
        printf("cant insert at rear since the dequeue is full\n");
    }
    else{
        printf("Enter the data to be insert at front : ");
        scanf("%d",&data);
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
        }
        else if(rear == size-1){
            rear = 0;
        }
        else{
            rear++;   //front 4 to 0 to 1 to 2 
        }
        dequeue[rear]=data;
    }
}

void delectFront(){
    if(front == -1 && rear == -1){
        printf("cant delect at front since the dequeue id empty\n");
    }
    else if(front == rear){
        printf("delected element from front is [ %d ]\n",dequeue[front]);
        front = -1;
        rear = -1;
    }
    else if(front == size -1){
        front = 0;
    }
    else{
        front++;
    }
}

void delectRear(){
    if(front == -1 && rear == -1){
        printf("cant delect at rear since the dequeue id empty\n");
    }
    else if(front == rear){
        printf("delected element from front is [ %d ]\n",dequeue[rear]);
        front = -1;
        rear = -1;
    }
    else if(rear==0){
        rear=size -1;
    }
    else{
        rear--;
    }
}

void getFront(){
    if(front == -1 && rear == -1){
        printf("cant display at front since the dequeue id empty\n");
    }
    else{
    printf("[ %d ]\n",dequeue[front]);
    }
}

void getRear(){
    if(front == -1 && rear == -1){
        printf("cant display at rear since the dequeue id empty\n");
    }
    else{
    printf("[ %d ]\n",dequeue[rear]);
    }
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("cant display at front since the dequeue id empty\n");
    }
    else{
        i= front;
        while(i!=rear){
            printf("[ %d ]   ",dequeue[i]);
            i = (i+1)%size;
        }
        printf("[ %d ]\n",dequeue[rear]);
    }
}

void main(){
    int ch;
    while(3000){
        printf("1 -> inserfront\n2 -> insertrear\n3 -> delect front\n4 -> delect rear\n5 -> display\n6 -> getfront\n7 -> getrear\n8 -> exit from program\n\t Enter your choise : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertFront();break;
            case 2:insertRear();break;
            case 3:delectFront();break;
            case 4:delectRear();break;
            case 5:display();break;
            case 6:getFront();break;
            case 7:getRear();break;
            case 8:exit(1);break;
            default : printf("Please enter the valid choise\n");
        }
    }
}
