#include<stdio.h>
#define size 100
char stack[size];
int top = -1;
void main()
{
    char str[size],ch,ch_temp;
    int i;
    printf("Enter the parathasis string : ");
    scanf("%s",str);
    for(i=0; str[i]!='\0'; i++) {
        ch = str[i];
        if(ch == '('|| ch == '{' || ch == '[') {
            top++;
            stack[top]=ch;
        } else if(ch==')'|| ch=='}'|| ch==']') {
            ch_temp = stack[top];
            if(ch==')'&& ch_temp=='('|| ch=='}'&& ch_temp=='{'||ch==']'&& ch_temp=='[') {
                top--;
            }
        }
    }
    if(top == -1) {
        printf("Balanced paranthasis");
    } else {
        printf("Inbalanced paranthsis");
    }
}
