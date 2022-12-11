#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peak();
void display();

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL,*newnode,*ptr;

void push()
{
	newnode=(struct node*)malloc(sizeof(struct node)); 
	printf("\n\tEnter the data to push : ");
	scanf("%d",&newnode->data);
	newnode->next=top;
	top=newnode;
}
void pop()
{
	if(top==NULL){
		printf("\n\tpop operation is not possible since stack is empty\n");
	}
	else{
	    printf("\n\t[ %d ] pop from from the stack \n",top->data);
		ptr=top;
		top=top->next;
		free(ptr);
	}
}
void peak()
{
	if(top==NULL){
		printf("\n\tTop element not exist, since list is empty\n");
	}
	else{
		printf("\n\t Top element is [ %d ]\n",top->data);
	}
}
void display()
{
	if(top==NULL){
		printf("\n\tCant display since the stack is empty\n");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL){
			printf("[ %d ]\n\t   |\n\t   |\n\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main()
{
	int ch;
	while(1){
		printf("\n1->push\n2->pop\n3->peek\n4->display\n5->exit\n\tEnter yor choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:peak();
			break;
			case 4:display();
			break;
		  case 5: printf("\tYou are out of menu\n");
			exit(0);
			break;
			default: printf("\tInvalid choice\n");
		}
	}
}
