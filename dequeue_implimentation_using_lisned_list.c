#include<stdio.h>
#include<stdlib.h>

struct dequeue{
	int n;
	struct dequeue *next;
};

struct dequeue *front=NULL,*rear=NULL,*newnode,*ptr,*pptr;
void insertRearEnd(){
	newnode = (struct dequeue *)malloc(sizeof(struct dequeue));
	printf("Enter the n : ");
	scanf("%d",&newnode->n);
	if(front==NULL && rear == NULL){
		front = newnode;
		rear = newnode;
		newnode->next = NULL;
	}
	else{
		rear->next= newnode;
		newnode->next=NULL;
		rear=newnode;
	}
}

void insertFrontEnd(){
	newnode = (struct dequeue *)malloc(sizeof(struct dequeue));
	printf("Enter the n : ");
	scanf("%d",&newnode->n);
	if(front==NULL && rear==NULL){
		front=newnode;
		rear= newnode;
		newnode->next=NULL;
	}
	else{
		newnode->next=front;
		front= newnode;
	}	
}

void delectFrontEnd(){
	if(front==NULL && rear==NULL){
		printf("Cannot delect since the queue is empty\n");
	}
	else{
		ptr=front;
		front = front->next;
		free(ptr);
	}	
}

void delectRearEnd(){
	if(front==NULL && rear==NULL){
		printf("Cannot delect since the queue is empty\n");
	}
	else{
		ptr=front;
		while(ptr->next!=NULL){
			pptr=ptr;
			ptr=ptr->next;
		}
		rear=pptr;
		pptr->next=NULL;
		free(ptr);	
	}
}

void display(){
	if(front==NULL && rear==NULL){
		printf("Cannot display since the queue is empty\n");
	}
	else{
		ptr=front;
		while(ptr!=NULL){
			printf("[ %d ]  ",ptr->n);
			ptr=ptr->next;
		}
		printf("\n");
	}	
}

void getFront(){
	if(front==NULL && rear==NULL){
		printf("front dont exits since the queue is empty\n");
	}
	else{
		printf("front element is [ %d ]\n",front->n);
	}	
}
void getRear(){
	if(front==NULL && rear==NULL){
		printf("rear dont exits since the queue is empty\n");
	}
	else{
		printf("front element is [ %d ]\n",rear->n);
	}	
}

void main(){
	int ch;;
	while(3000){
		printf("1 -> insert front\n2 -> insert rear\n3 -> delect front\n4 -> delect rear\n5 -> display\n6 -> get front element\n7 -> get rear element\n8 -> exit from the program\n\t Enter the choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:insertFrontEnd();break;
			case 2:insertRearEnd();break;
			case 3:delectFrontEnd();break;
			case 4:delectRearEnd();break;
			case 5:display();break;
			case 6:getFront();break;
			case 7:getRear();break;
			case 8:exit(1);
			default: printf("Inva;id choise please enter the VALID choise\n");
		}
	}
}
