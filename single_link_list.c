#include<stdio.h>
#include<stdlib.h>

int noofnodes();
void pnoofnodes();
void insertnode();
void insertbegin();
void insertend();
void insertposition();
void delect();
void delectbegining();
void delectposition();
void seach();
void display();
void reverse();
void find_min();
void find_max();

struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL,*newnode,*ptr,*pptr;

int noofnodes()
{
	int count=0;
	if(start==NULL)
	{
		return 0;
	}
	else
	{
		ptr=start;
		while(ptr!=NULL){
		count++;
		ptr=ptr->next;
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
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
	newnode->next=NULL;
}

void insertbegin()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
}

void insertend()
{
    if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
    }
    else
    {
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : \n");
    scanf("%d",&newnode->data);
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=NULL;
    }
}

void insertposition()
{
	int position,count=1,value;
	if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
	}
	else
	{
		printf("Enter the position : ");
		scanf("%d",&position);
		
		if(position>noofnodes()){
		    printf("\nInvalid position\n");
		}
		else if(position==1){
		    insertbegin();
		}
        else
        {
	       newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the data : ");
			scanf("%d",&value);
			newnode->data=value;
			ptr=start;
			while(count<position)
			{
			    pptr=ptr;
				ptr=ptr->next;
				count++;
			}
		    newnode->next=ptr;
		    pptr->next=newnode;
        }
	}
}

void delect()
{
	if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
	}
	else
	{
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
		printf("\nSince list is empty, this function doesn't work\n");
	}
	else
	{
	ptr=start;
	start=start->next;
	free(ptr);
    }
}

void delectposition()
{
	int count=1;
	int pos;
	if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
    }
    else
    {
    	printf("Enter the position : "); 
    	scanf("%d",&pos);
    	
    	    if(pos>noofnodes())
    	    {
    	        printf("\nInvalid function\n");
		    }
		    else if(pos==1){
		        delectbegining();
		    }
	    	else
		    {
			    ptr=start;
			    while(count!=pos)
			    {
				    pptr=ptr;
				    ptr=ptr->next;
				    count++;
			    }
			pptr->next=ptr->next;
			free(ptr);
		}
	}
}

void seach()
{
    if(start==NULL){
		printf("\nSince list is empty, this function doesn't work\n");
    }
    else
    {
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

void display()
{
	if(start==NULL){
	 printf("\n[ head ] -->");
	}
	else{
		ptr=start;
		printf("\nhead-->");
		while(ptr!=NULL){
			printf("[ %d ]--->",ptr->data);
			ptr=ptr->next;
		}
	}
		printf(" [ NULL ]\n");
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


void main()
{
	int ch;
	while(1){
		printf("\n1->insert a node\n2->insert at begining\n3->insert at end\n4->insert at position\n5->delect\n6->delectbegining\n7->delect position\n8->search\n9->display\n10->no of nodes\n11->Minimun element\n12->Maximum element\n13->reverse the link list\n14->Exit from program :\n\tEnter your choice : ");
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
	   		case 8:seach();
	   		break;
	   		case 9:display();
	   		break;
	   		case 10:pnoofnodes();
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
