#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100


int stack[MAX];
char postfix[MAX];
int top=-1;

char pop();
void push(char);
char post_Eval();

int main()
{
    int result;
    printf("enter the postfix expresion:");
    gets(postfix);
    result=post_Eval();
    printf("the result of the EXP: %d",result);
    return 0;
}

char post_Eval()
{ 
    int i,a,b;
    for(i=0;i<strlen(postfix);i++)
    {
        if (postfix[i]>= '0' && postfix[i]<='9')
        push(postfix[i]-'0');
        else 
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                push(b+a); 
                break;
                case '-':
                push(b-a); 
                break;
                case '*':
                push(b*a); 
                break;
                case '/':
                push(b/a); 
                break;
                case '^':
                push(pow(b,a)); 
                break;
                
            }
        }
    }
    
    return pop();
}

char pop()
{   char c;
    if (top == -1)
    {
        printf("stack is underflow/empty");
        exit(1);
    }

        c=stack[top];
        top--;
        return c;
}

void push(char c)
{
    if (top == MAX-1)
    {
        printf("stack is overflow");
        return;
    }
    top++;
    stack[top]=c;
}