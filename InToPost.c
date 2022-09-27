
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100


char stack[MAX];
char postfix[MAX],infix[MAX];
int top=-1;

char pop();
void push(char);
int post_Eval();
int isEmpty();
void in_to_post();
void print();
int precd(char);

int main()
{    
    int result;
    char 
    printf("enter the infix expresion:");
    gets(infix);
    in_to_post();
    print();
    result=post_Eval();
    printf("the result of the EXP = %d",result);
    return 0;
}

void in_to_post()
{
int i,j=0;
char symbol,next;
for(i=0;i<strlen(infix);i++)
{
    symbol=infix[i];
    switch(symbol)
    {
        case '(':
        push(symbol);
        break;
        case ')':
        while ((next=pop())!='(')
        {
            postfix[j++]=next;
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while(!isEmpty() && precd(stack[top])>= precd(symbol) )
        {
            postfix[j++]=pop();
        }
        push(symbol);
        break;
        default:
        postfix[j++]=symbol;
    }
}
while (!isEmpty())
    postfix[j++]=pop();

postfix[j]='\0';

}

int isEmpty()
{
    if (top<=-1)
    return 1;
    else 
    return 0;
}

void print()
{
    int i;
    printf("postfix EXP:");
    for (i=0;i<strlen(postfix);i++)
    {
        printf("%c",postfix[i]);
        
    }
    printf("\n");
}

int precd(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        return 1;
        break;
        
        case '*':
        case '/':
        return 2;
        break;
        
        case '^':
        return 3;
        break;
        
        default:
        return 0;
        break;
    }
}

int post_Eval()
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


