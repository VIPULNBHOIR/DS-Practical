#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front,rear,queue[MAX];

void enque()
{ 
//isFULL condition
if(front==-1 && rear==MAX-1){
printf("Q is full\n");
}
else
{
rear=rear+1;
printf("inserting at rear %d :",rear);
scanf("%d",&queue[rear]);
}
}

void deque()
{
    if(rear==front){
        printf("The queue is Empty\n");
    }
    else{
    front+=1;
    printf("DQ element:%d\n",queue[front]);
    queue[front]='\0';
    printf("front is now %d",front);
    }
   
}

void display(){
if(rear==front){
        printf("The queue is Empty\n");
    }
else{
for(int i=0;i<=rear;i++)
{
printf("%d | ",queue[i]);
}
}
}

void peek(){

if(rear==front)
    {
        printf("The queue is Empty\n");
    }
else
{
printf("peeked element :%d",queue[front+1]);
}
}

int main(){
    int x;
    front =-1;
    rear =-1;
    printf("Enter 1.enque 2.deque 3.display 4.exit 5.peek\n");
    while(1)
    {   printf("\nENTER : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            enque();
            break;
            
            case 2:
            deque();
            break;

            case 3:
            display();
            break;
          
            case 4:
            exit(1);
            break;

            case 5:
            peek();
            break;
                

        }
        
    }
    return 0;
}
