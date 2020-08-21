#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next,*prev;
	
};
void deletepos(struct node**head,int pos)
{
	struct node*temp=(*head);
	if(pos==1)
	{
		(*head)=(*head)->next;
		free(temp);
	}
	else
	{
	int i;
    for( i=1;i<pos;i++)
    {
       temp=temp->next;	
	}
	if(temp->next!=NULL)
	{
	
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
    }
    else
    {
    temp->prev->next=temp->next;
	  free(temp);
	}
   
   }
}
void deleteend(struct node**head)	
{
	struct node *temp=(*head);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
	
void deletein(struct node**head)
{
	struct node *temp=(*head);
    temp->next->prev=NULL;
	(*head)=(*head)->next;
	
	free(temp);
	

}

void push(struct node **head,int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
/*	temp->next=(*head);
	temp->prev=NULL;
	if((*head)!=NULL)
	{
	    	(*head)->prev=temp;
	}
	
	(*head)=temp;
	*/
	struct node *last=(*head);
	if((*head)==NULL)
	{
		temp->prev=NULL;
		temp->next=NULL;
		(*head)=temp;
	}
	else
	{
	   	while(last->next!=NULL)
	   	{
	   	  last=last->next;	
		}
		temp->next=NULL;
		temp->prev=last;
	    last->next=temp;
	}
}
void printlist(struct node *head)
{
	struct node *last=head;
	struct node *temp;
	while(last!=NULL)
	{
		printf("%d ",last->data);
		temp=last;
		last=last->next;
	}
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
void insart(struct node **head,int pos,int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node ));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	struct node * last=(*head);
	if(pos==1)
	{
	    temp->next=(*head);
	    (*head)=temp;
	}
	else
	{
		int i;
		for( i=1;i<pos;i++)
		{
			last=last->next;
	    }
		
	    temp->next=last;
	    temp->prev=last->prev;
	    last->prev->next=temp;
	    last->prev=temp;
	    
	}
}
int main()
{
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	printf("after pushing element at end\n");
	printlist(head);
	
	deletein(&head);
	printf("after deleting element at stating point\n");
	
	printlist(head);
	push(&head,1);
		push(&head,6);
			push(&head,7);
				push(&head,1);
	printf("after sum modification\n");
	printlist(head);			
  	deleteend(&head);
  	printf("after deleting element at ending point\n");
	printlist(head);
	insart(&head,2,8);
	
	printf("after pushing element at 2nd position\n");
	printlist(head);
	deletepos(&head,6);
	printf("after deleting element at 6th position\n");
	printlist(head);
	getchar();
	
	return 0;
	
}

