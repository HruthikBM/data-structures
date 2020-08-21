#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next,*prev;
};
void indartmid(struct node**head,int pos,int x)
{
	struct node*temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
    struct node *curr=(*head);
	 if((*head)==NULL)	
	 {
	 	(*head)=temp;
	 	temp->next=(*head);
	 	temp->prev=(*head);
	 }
	 else
	 {
	 	int i;
	     for(i=1;i<pos;i++)	
	     {
	     	 curr=curr->next;
		 }
		 
	 }
}
void insartend(struct node**head,int x)
{
	struct node *last=(*head);
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
		if((*head)==NULL)
	{
		(*head)=temp;
		temp->next=(*head);
		temp->prev=(*head);
	}
		else
	{
		last=(*head)->prev;
		last->next=temp;
		temp->prev=last;
		(*head)->prev=temp;
		temp->next=(*head);
	//	(*head)=temp;
	}
	
}
void printlik(head)
{
	struct node *temp=head;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
void insartbeg(struct node**head,int x)
{

	struct node *temp=(struct node*)malloc (sizeof(struct node));
	temp->data=x;
	if((*head)==NULL)
	{
			(*head)=temp;
		temp->next=(*head);
		temp->prev=(*head); 
	}
	else
	{
	
    struct node *last=(*head)->prev;
	temp->next=(*head);
	temp->prev=last;
	last->next=(*head)->prev=temp;
	(*head)=temp;
   }
}

int main()
{
	struct node*head=NULL;
	insartend(&head,1);
	insartend(&head,2);
	insartend(&head,3);
	printf("after insarting at ending\n");
	printlik(head);
	insartbeg(&head,0);
	insartbeg(&head,-1);
	printf("after insarting at beginning\n");
	printlik(head);
	insartmid(&head,2,9);
	printf("after insarting at middle\n");
	printlik(head);
	return 0;
}
