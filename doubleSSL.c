#include<stdio.h>
#include<stdlib.h>

int noofnodes();
void pnoofnodes();
void insert();
void insertbegin();
void insertend();
void insertposition();
void delect();
void delectbegin();
void delectposition();
void display();


struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start=NULL,*newnode,*ptr,*pptr;

int noofnodes()
{
	int count=0;
	if(start==NULL){
		return count;
	}
	else{
		ptr=start;
		while(ptr!=NULL){
			ptr=ptr->next;
			count++;
		}
		return count;
	}
}

void pnoofnodes()
{
	int count=0;
	if(start==NULL)
	{
		printf("\n\t 0 nodes\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("\n\t %d nodes\n",count);
	}
	
}

void insertnode()
{
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	if(start==NULL){
		start=newnode;
		newnode->prev=NULL;
	}
	else{
		ptr=start;
		while(ptr->next=NULL){
			ptr=ptr->next; 
		}
		ptr->next=newnode;
		newnode->prev=ptr;
	}
		newnode->next=NULL;	
}

void insertbegin()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=start;
	start=newnode;
}

void insertend()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
	newnode->next=NULL;
}

void insertposition()
{
	int position,value=1;
	if(start==NULL){
		printf("\n\tSince list is empty, this function doesn't work\n");
	}
	else{
		printf("Enter the position : ");
		scanf("%d",&position);
		if(position>noofnodes()){
			printf("\n\tInvalid position\n");
		}
		else if(position==1){
			insertbegin();
		}
		else{
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the data : ");
			scanf("%d",&newnode->data);
			ptr=start;
			while(value<position){
				pptr=ptr;
				ptr=ptr->next;
				value++;
			}
			pptr->next=newnode;
			newnode->prev=pptr;
			newnode->next=ptr;
			ptr->prev=newnode;
		}
	}
}

void delect()
{
	if(start==NULL){
		printf("\n\tSince list is empty, this function doesn't work\n");
	}
	else{
		ptr=start;
		while(ptr->next!=NULL){
			pptr=ptr;
			ptr=ptr->next;
		}
		pptr->next=NULL;
		free(ptr);
	}
}

void delectbegining()
{
		if(start==NULL){
		printf("\n\tSince list is empty, this function doesn't work\n");
	}
	else{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		free(ptr);
	}
}

void delectposition()
{
	int position,count=1;
		if(start==NULL){
		printf("\n\tSince list is empty, this function doesn't work\n");
	}
	else {
		printf("Enter the position : ");
		scanf("%d",&position);
		if(position>noofnodes()){
			printf("\n\tInvalid position\n");
		}
		else if(position==noofnodes()){
			delect();
		}
		else{
			ptr=start;
			while(count!=position){
				pptr=ptr;
				ptr=ptr->next;
				count++;
			}
			pptr->next=ptr->next;
			ptr->next->prev=pptr;
			free(ptr);
		}
	}
}

void display()
{
		if(start==NULL){
		printf("\n\t[ start ]<==>");
	}
	else{
		printf("\n\t[ start ]<==>");
		ptr=start;
		while(ptr!=NULL){
			printf("[ %d ]<==>",ptr->data);
			ptr=ptr->next;
		}
		printf("[ NULL ] \n");
	}	
}

void main()
{
	int ch;
	while(1){
		printf("\n1->insert a node\n2->insert at begining\n3->insert at end\n4->insert at position\n5->delect\n6->delectbegining\n7->delect position\n8->display\n9->no of nodes\n10->Exit from program :\n\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:insertnode();
	    	break;
	   		case 2:insertbegin();
	   		break;
	   		case 3:insertend();
	   		break;
	   		case 4:insertposition();
	   		break;
	   		case 5:delect();
	   		break;
	   		case 6:delectbegining();
	   		break;
	   		case 7:delectposition();
	   		break;
	   		case 8:display();
	   		break;
	   		case 9:pnoofnodes();
	   		break;
	   		case 10: printf("\tYou exited from the list\n"); 
		    exit(1); 
		    break; 
			default: printf("\tYour choice is INVALLID, please choose a VALID choice\n"); 
			break;
		}
	}	
}
