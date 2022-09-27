#include <stdio.h>
void peek(void);
void display(void);
void pop(void);
void push(void);
int stack[50],t,choice,n,p,x,i;

int main()
{
printf("\n Enter the size of stack: ");
scanf("%d",&n);
t=-1;
printf("\nEnter the choice 1. push 2. pop 3. peek 4. display 5. exit\n");
do
{
printf("\nEnter choice:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
push();
break;
}

case 2:
{
pop();
break;
}

case 3:
{
peek();
break;
}

case 4:
{
display();
break;
}

case 5:
{
printf("exit");
break;
}

default:
{
printf("you are wrong with your choice\n");
break;
}
}
}
while(choice!=5);
return 0;
}

void pop()
{   
    if (t <0)
    {
        printf("stack is underflow/empty\n");
    }
    else
        printf(" poped element :%d",stack[t]);
        t--;
}

void push()
{   t+=1;
    if (t > n)
    {
        printf("stack is overflow");
    }
    else
    {
        printf("PUSH at %d:",t);
        scanf("%d",&x);
        stack[t]=x;
    }
}

void peek()
{   
    if (t <0)
    {
        printf("stack is underflow/empty");
    }
    else
        printf("peeked element: %d",stack[t]);
}

void display()
{
     if (t <0)
    {
        printf("stack is underflow/empty");
    }
    else
    { 
        for (i=t;i>=0;i--)
        {
            printf("%d | ",stack[i]);
        }
        printf("\n");
    }
}
