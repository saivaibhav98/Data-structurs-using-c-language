#include<stdio.h>
#define size 100
char stack[size];
int top = -1;
int priority(char ch1){
	if(ch1=='(')
	return 0;
	else if(ch1 == '+'|| ch1=='-')
	return 1;
	else if(ch1=='*'|| ch1=='/')
	return 2;
	else if(ch=='^')
	return 3;
}
void push(char ch){
    stack[++top]=ch;
}
char pop(){
    return stack[top--];
}
void main(){
	char infix[size];
	char ch,x;
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	int i;
	for(i=0;infix[i]!='\0';i++){
		ch=infix[i];
		if(ch>='0'&& ch<='9'|| ch>='a' && ch<='z'||ch>='A'&& ch<='Z'){
			printf("%c ",ch);
		}
		else if(ch=='('){
			push(ch);
		}
		else if(ch==')'){
			while((x=pop()) !='('){
				printf("%c ",x);
			}
		}
		else{
			while(priority(stack[top])>=priority(ch)){
				printf("%c ",pop());
			}
			push(ch);
		}
	}
	while(top!=-1){
	    printf("%c ",pop());
	}
}
