#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*top=NULL,*newnode,*ptr;
void push()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(top==NULL)
        printf("\n cant delect since the stack is empty");
    else {
        printf("\n[ %d ] is delected from the stack ",top->data);
        ptr=top;
        top=top->next;
        free(ptr);
    }
}
void display()
{
    if(top==NULL)
        printf("\n cant display since the stack is empty");
    else {
        ptr=top;
        while(ptr!=NULL) {
            printf("\n     [ %d ]  ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void peek()
{
    if(top==NULL)
        printf("\n peek is not exit since the stack is empty");
    else
        printf("\n[ %d ]  ",top->data);
}
void main()
{
    int ch;
    while(1) {
        printf("\n1->push\n2->pop\n3-peek\n4-display\n5-exit\n\tEnter your choise");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("\nInvalid choise please enter the valid choise");
        }
    }
}
