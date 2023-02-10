#include<stdio.h>
#include<ctype.h>
#define size 99
int stack[size],top=-1;
void push(int);
int pop();
int eval(char,int,int);
void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}
int eval(char ch,int a,int b){
	switch(ch){
		case '+':return b+a;
		case '-':return b-a;
		case '*':return b*a;
		case '/':return b/a;
		case '^':return b^a;
		case '%':return b%a;
	}
}
void main(void){
	char str[size],ch;
	int i,num1,num2,num3,result;
	printf("Enter the postfix expression : ");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++){
		ch = str[i];
		if(ch>='0'&&ch<='9'){
			num1 = ch - 48;
			push(num1);
		}
		else{
			int num2 = pop(); 		    	    // let it be a
			int num3 = pop(); 			        // let it be b
			result = eval(ch,num2,num3);    //(eval(ch, a, b)
			push(result);
		}
	}
	printf("the value is %d\n",pop());
}
