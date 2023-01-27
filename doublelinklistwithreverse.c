#include<stdio.h>
#include<stdlib.h>

int no_of_nodes();
void print_no_of_nodes();
void create();
void insert_begin();
void insert_end();
void insert_position();
void delect();
void delect_begin();
void delect_position();
void seach();
void find_min();
void find_max();
void reverse();

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *start=NULL,*end=NULL,*ptr,*newnode,*pptr;

int no_of_nodes(){
int count=0;
	if(start==NULL){
		return 0;
	}
	else{
		ptr=start;
		while(ptr!=NULL){
			count++;
			ptr=ptr->next;
		}
		return count;
	}
}

void print_no_of_nodes(){
	int count=0;
	if(start==NULL){
		printf("\n\t zero node");
	}
	else{
		ptr=start;
		while(ptr!=NULL){
			count++;
			ptr=ptr->next;
		}
		printf("\n\t%d nodes",count);
	}
}

void create(){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	if(start==NULL){
		start=newnode;
		newnode->prev=NULL;
	}
	else{
		newnode->prev=end;
		end->next=newnode;
	}
	end=newnode;
	newnode->next=NULL;
}

void insert_begin(){
	if(start==NULL){
		create();
	}
	else{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next= start;
		start=newnode;
	}
}

void insert_end(){
	if(start==NULL){
		create();
	}
	else{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&newnode->data);
		end->next=newnode;
		newnode->prev=end;
		newnode->next=NULL;
		end=newnode;
	}
}

void insert_position(){
	int pos,count=2;
	if(start==NULL){
		printf("Can't insert at any position since the list is emply");
	}
	else{
		printf("Enter the position : ");
		scanf("%d",&pos);
		if(pos>no_of_nodes()){
			printf("\nInserction positon out of range\n");
		}
		else if(pos==1){
			insert_begin();
		}
		else if(pos==no_of_nodes()){
			create();
		}
		else{
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the data : ");
			scanf("%d",&newnode->data);
			ptr=start;
			while(count!=pos){
				ptr=ptr->next;
				count++;
			}
			newnode->prev=ptr;
			newnode->next=ptr->next;
			ptr->next=newnode;
			ptr->next->prev=newnode;
		}
	}
}

void delect(){
	if(start==NULL){
		printf("Can't delect since the list is emply");
	}
	else{
		ptr=end;
		end=end->prev;
		end->next=NULL;
		free(ptr);
	}
}

void delect_begin(){
	if(start==NULL){
		printf("Can't delect first node since the list is emply");
	}
	else{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		free(ptr);
	}
}

void delect_position(){
	int count=1,pos;
	if(start==NULL){
		printf("Can't delect since the list is emply");
	}
	else{
		printf("Enter the position : ");
		scanf("%d",&pos);
		if(pos>no_of_nodes()){
			printf("\ndelection positon out of range\n");
		}
		else if(pos==1){
			delect_begin();
		}
		else if(pos==no_of_nodes()){
			delect();
		}
		else{
			ptr=start;
			while(count!=pos){
				ptr=ptr->next;
				count++;
			}
			ptr->next->prev=ptr->prev;
			ptr->prev->next=ptr->next;
			free(ptr);
		}	 
	}
}

void seach(){
    if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
    }
    else{
	int key,x=0;
	printf("Enter the key element : ");
	scanf("%d",&key);
	ptr=start;
	while(ptr!=NULL){
	    
		if(ptr->data==key){
			x++;
			break;
		}
		ptr=ptr->next;
	}
	if(x==0){
		printf("\nElement not found\n");
	}
	else
	{
		printf("\nElement found\n");
	}
    }
}

void display(){
	if(start==NULL){
	 printf("\n[ head ] <==>");
	}
	else{
		ptr=start;
		printf("\n[ head ] <==>");
		while(ptr!=NULL){
			printf("[ %d ] <==>",ptr->data);
			ptr=ptr->next;
		}
	}
		printf(" [ NULL ]\n");
}

void find_min(){
	if(start==NULL){
		printf("\nSince list is empty, we cant find min element\n");
    }
    else{
    	ptr = start;
    	int min = ptr->data;
    	while(ptr!=NULL){
    		if(min>ptr->data){
    			min = ptr->data;
			}
			ptr = ptr->next;
		}
		printf("\nMinimum element in linked list is [ %d ]",min);
	}	
}

void find_max(){
	if(start==NULL){
		printf("\nSince list is empty, we cant find max element\n");
    }
    else{
    	ptr = start;
    	int max = ptr->data;
    	while(ptr!=NULL){
    		if(max<ptr->data){
    			max = ptr->data;
			}
			ptr = ptr->next;
		}
		printf("\nMinimum element in linked list is [ %d ]",max);
	}
}

void reverse()
{
	ptr=NULL;
	pptr=NULL;
	while(start!=NULL){
		pptr=start->next;
		start->next=ptr;
		ptr=start;
		start=pptr;
	}
	start=ptr;
}
void main(){
	int ch;
	while(1){
		printf("\n1->insert a node\n2->insert at begining\n3->insert at end\n4->insert at position\n5->delect\n6->delectbegining\n7->delect position\n8->search\n9->display\n10->no of nodes\n11->Minimun element\n12->Maximum element\n13-> Reverse the link list \n14 ->Exit from program :\n\tEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch){
	    		case 1:create();
	    		break;
	   		case 2:insert_begin();
	   		break;
	   		case 3:insert_end();
	   		break;
	   		case 4:insert_position();
	   		break;
	   		case 5:delect();
	   		break;
	   		case 6:delect_begin();
	   		break;
	   		case 7:delect_position();
	   		break;
	   		case 8:seach();
	   		break;
	   		case 9:display();
	   		break;
	   		case 10:print_no_of_nodes();
	   		break;
	   		case 11:find_min();
	   		break;
	   		case 12:find_max();
	   		break;
	   		case 13:reverse();
	   		break;
	   		case 14: printf("\tYou exited from the list\n"); 
		    	exit(1); 
		    	break; 
			default: printf("\tYour choice is INVALLID, please choose a VALID choice\n"); 
			break;
		}
	}
}
