#include<stdio.h>
#include<ctype.h>
char a[100];
int top =-1;

void push(int x){a[++top]=x;}

char pop(){return a[top--];}

int priority(char x){
    if(x=='+'|| x=='-') return 0;
    if(x=='*'|| x=='/') return 1;
    if(x=='^') return 2;
}

void main(){
    char b[100];
    char *p,x;
    printf("Enter the expression : ");
    gets(b);
    p=b;
    while(*p!='\0'){
        if(isalpha(*p)){
            printf("%c  ",*p);
        }
        else if(*p=='(')
        push(*p);
        else if(*p==')')
        {
            while((x=pop())!='(')
            printf("%c ",*p);
        }
        else{
            if(priority(a[top]>=priority(*p))){
                printf("%c  ",pop());
                push(*p);
            }
             p++;
        }
    }
}
