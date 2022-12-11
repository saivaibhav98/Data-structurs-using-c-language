#include<stdio.h>
#include<stdlib.h>

void enQueue();
void deQueue();
void peek();
void isEmpty();
void display();

struct node 
{
	int data;
	struct node *next;
};

struct node *newnode,*front=NULL,*rear=NULL,*ptr;

void enQueue()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	if(front==NULL&&rear==NULL){
		front=newnode;
	}
	else{
		rear->next=newnode;
	}
	rear=newnode;
	newnode->next=NULL;
}

void deQueue()
{
	if(front==NULL){
		printf("\n\tDequeue opration is not possible because queue is empty\n");
	}
	else{
		printf("\n\tElement [ %d ] is dequeued from the queue\n",front->data);
		ptr=front;
		front=front->next;
		free(ptr);
	}
}

void peek()
{
	if(front==NULL){
	printf("\n\tPeek element not possible because queue is empty\n");
	}
	else{
		printf("\n\tPeek element is [ %d ] \n",rear->data);
	}
}

void isEmpty()
{
		if(front==NULL){
	printf("\n\tQueue is empty\n");
	}
	else{
		printf("\n\tQueue is not empty\n");
	}
}

void display()
{
	if(front==NULL){
		printf("\n\tCant display since queue is empty\n");
	}
	else{
		printf("[ Front ]-->");
		ptr=front;
		while(ptr!=NULL){
			printf("[ %d ]-->",ptr->data);
			ptr=ptr->next;
		}
		printf("[ rear ]\n");
	}
}

void main()
{
	int ch;
	while(1){
		printf("\n1->enQueue\n2->deQueue\n3->peek\n4->isEmpty\n5->display\n6->exit\n\tEnter your choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : enQueue();
			break;
			case 2 : deQueue();
			break;
			case 3 : peek();
			break;
			case 4 : isEmpty();
			break;
			case 5 : display();
			break;
			case 6 : exit(1);
			break;
			default : printf("\n\tInvalid choise, Please Enter the VALID choise/n");
			
		}
	}
}
