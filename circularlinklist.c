#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL,*newnode,*ptr,*pptr;

int no_of_nodes(){
    int c=0;
    if(start==NULL){
        return c;
    }
    else{
        ptr=start->next;
        do{
            c++;
            ptr=ptr->next;
        }while(ptr!=start->next);
        return c;
    }
}

void print_of_nodes(){
    int c=0;
    if(start==NULL){
        printf("\n zero nodes");
    }
    else{
        ptr=start->next;
        do{
            c++;
            ptr=ptr->next;
        }while(ptr!=start->next);
        printf("\n %d nodes",c);
    }
}

void insert(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if(start==NULL){
        start=newnode;
        newnode->next=start;
    }
    else{
        newnode->next=start->next;
        start->next=newnode;
        start=newnode;
    }
}

void display(){
    if(start==NULL){
        printf("cant display since the list is emply");
    }
    else{
        ptr=start->next;
        do{
           printf("[ %d ]    ",ptr->data);
           ptr=ptr->next;
        }while(ptr!=start->next);
    }
}

void insert_begin(){
    if(start==NULL){
        insert();
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=start->next;
        start->next=newnode;
    }
}

void insert_end(){
    if(start==NULL){
        printf("\nInserction at ending is not possible since the list is emply");
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=start->next;
        start->next=newnode;
        start=newnode;
    }
}

void insert_position(){
    int pos,count=2;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==1){
        insert_begin();
    }
    else if(pos>no_of_nodes()){
        printf("\ncan't insert since the position is out of range");
    }
    else{
        if(pos==no_of_nodes()){
            insert_end();
        }
        else{
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data : ");
            scanf("%d",&newnode->data);
            ptr=start->next;
            while(count!=pos){
                ptr=ptr->next;
                count++;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
    }
}

void delect(){
    if(start==NULL){
        printf("\ndelection is not possible since the list is emply");
    }
    else{
        ptr=start->next;
        do{
            pptr=ptr;
            ptr=ptr->next;
        }while(ptr->next!=start->next);
        pptr->next=ptr->next;
        start=pptr;
        free(ptr);
    }
}

void delect_begin(){
    if(start==NULL){
        printf("\ndelection at start is not possible since the list is emply");
    }
    else{
        ptr=start->next;
        start->next=start->next->next;
        free(ptr);
    }
}

void delect_position(){
    int pos,count=1;
    if(start==NULL){
        printf("\ndelection at possible is not possible since the list is emply");
    }
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos>no_of_nodes()){
        printf("\ncan't delect since the position is out of range");
    }
    else{
        if(pos==no_of_nodes()){
            delect();
        }
        else if(pos==1){
        	delect_begin();
		}
        else{
            ptr=start->next;
            while(count!=pos){
                pptr=ptr;
                ptr=ptr->next;
                count++;
            }
            pptr->next=ptr->next;
            free(ptr);
        }
    }
}

void serch(){
    if(start==NULL){
        printf("\nserch function cant work since the list is emply");
    }
    else{
        int key;
        int c=0;
        printf("Enter the key element : ");
        scanf("%d",&key);
        ptr=start->next;
        do{
           if(ptr->data==key){
               c=1;
               break;
           } 
           else{
               ptr=ptr->next;
           }
        }while(ptr!=start->next);
        if(c==1){
            printf("\n[  %d  ] element is found",key);
        }
        else{
            printf("\nelement is not found");
        }
    }
}

void max_element(){
    int max;
    if(start==NULL){
        printf("\nmaximum element cant find since the list is emply");
    }
    else{
        ptr=start->next;
        max=ptr->data;
        do{
           if(ptr->data>max){
               max=ptr->data;
           }
           ptr=ptr->next;
        }while(ptr!=start->next);
        printf("maximum element is [ %d ]",max);
    }
}

void min_element(){
    int min;
    if(start==NULL){
        printf("\nminimum element cant find since the list is emply");
    }
    else{
        ptr=start->next;
        min=ptr->data;
        do{
           if(ptr->data<min){
               min=ptr->data;
           }
           ptr=ptr->next;
        }while(ptr!=start->next);
        printf("maximum element is [ %d ]",min);
    }
}


void main(){
    int ch;
    while(1){
        		printf("\n1->insert a node\n2->insert at begining\n3->insert at end\n4->insert at position\n5->delect\n6->delectbegining\n7->delect position\n8->search\n9->display\n10->no of nodes\n11->Minimun element\n12->Maximum element\n13->Exit from program :\n\tEnter your choice : ");
                scanf("%d",&ch);
                switch(ch){
                    case 1:insert();
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
                    case 8:serch();
                            break;
                    case 9:display();
                            break;
                    case 10:print_of_nodes();
                            break;
                    case 11:max_element();
                            break;
                    case 12:min_element();
                            break;
                    case 13:exit(1);
                            break;
                    default:printf("\tYour choice is INVALLID, please choose a VALID choice\n"); 
                            break;
                    
    	}
   }
}



