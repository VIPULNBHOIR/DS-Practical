#include <stdio.h>
#include <stdlib.h>

struct node{
int data;            //this can be either int or float or char 
struct node *link;   //add. of the node
};

//No of nodes
void No_nodes(struct node *head)
{
int count=0;
if(head==0)
{printf("link list is empty");}
struct node *ptr=0;
ptr=head;
while(ptr!=0)
{
count+=1;
ptr=ptr->link;
}
printf("Total no. of nodes : %d\n",count);
}

//print data
void get_data(struct node *head)
{
if(head == 0)
{
printf("link list is empty");
}
struct node *ptr=0;
ptr=head;
while(ptr!=0)
{
printf("%d | ",ptr->data);
ptr=ptr->link;
}
}

//delete data from begining
struct node *delete_from_Beg(struct node *head)
{
if(head==0){
printf("link list is empty");    
}
else{
struct node *temp;
temp=head;
head=head->link;
printf("deleted data:%d\n",temp->data);
free(temp);
printf("data successfully deleted");
return head;                         //.....returning updated head pointer
}
}


//delete data from end
void delete_from_end(struct node *head)
{
struct node *temp,*prev;
temp=head;
while(temp->link!= 0){
prev=temp;
temp=temp->link;
}
prev->link=0;
printf("deleted data:%d\n",temp->data);
free(temp);
printf("data successfully deleted");
}

//add node at end
struct node *New_nodeAt_End(struct node *ptr,int value)
{
struct node *temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=0;
ptr->link=temp;

ptr=temp;
return ptr;
}

//add node at beg
struct node *New_nodeAt_Beg(struct node *head,int value)
{
struct node *temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=head;
head=temp;
return head;           //returning updated head pointer

}



int main(){
int value;
//creating a 1st node by forming size using malloc 

struct node *head=malloc(sizeof(struct node));
struct node *ptr=head;
head->data=50;
head->link=0;

printf("ENTER:\n1.insert at END\n2.insert at BEG.\n3.Print data\n4.Delete from END\n5.Delete from BEG.\n6.Count NO. of nodes\n ");
int x=1;

while(x!=0)
{
printf("\nEnter:");
scanf("%d",&x);
switch(x)
{
case 1:
printf("Enter data:");
scanf("%d",&value);
ptr=New_nodeAt_End(ptr,value);
break;

case 2:
printf("Enter data:");
scanf("%d",&value);
head=New_nodeAt_Beg(head,value);
break;

case 3:
get_data(head);
break;

case 0:
exit(1);
break;

case 4:
delete_from_end(head);
break;

case 5:
head=delete_from_Beg(head);
break;

case 6:
No_nodes(head);
break;

default:
printf("Enter correct choice please !!");
break;

}
}
return 0;
}

