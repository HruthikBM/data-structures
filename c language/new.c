#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
  struct node *next;
  struct node *pre;	
};
typedef struct node *NODE;
NODE crea(int x)
{
	NODE temp=(NODE)malloc (sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->pre=NULL;
	return temp;
}
void insart(int x)
{
	NODE temp=crea(x);
	if(head==NULL)
	{
		head=temp;
    }
    temp->next=head;
    head->pre=temp;
    head=temp;
	  
}
void print()
{
	NODE temp,last;
	temp =head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		last=temp;
		temp=temp->next;
	}
	printf("\n");
	while(last!=NULL)
	{
		printf("%d ",last->data);
		last=last->next;
	}
	printf("\n");
}
NODE head
int main()
{
   head=NULL;
   insart(1);
   insart(2);	
   insart(3);
   print();
   return 0;
}

