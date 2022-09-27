#include <stdio.h>
#define SIZE 5
#include <stdlib.h>

int queue[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\nQueue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    printf("\nInserted : %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\nQueue is empty \n");
    return (-1);
  } else {
    element = queue[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\nDeleted element :%d \n", element);
    return (element);
  }
}
void peek(){
    if ( isEmpty())
    printf("Queue is Empty");
    else
    printf("peeked element: %d",queue[front]);
    
}
// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\nItems : ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
  }
}

int main() {
  int choice,value;
  printf("\n1.NQ 2.DQ 3.Peek 4.display 5.exit\n");
  while(1){
      printf("\nEnter choice:");
      scanf("%d",&choice);
      switch(choice){
           case 1:
           printf("value:");
           scanf("%d",&value);
           enQueue(value);
           break;
           
           case 2:
           deQueue();
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
           
           
      }
      
  }
 

  return 0;
}