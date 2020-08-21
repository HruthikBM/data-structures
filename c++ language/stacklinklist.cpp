#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	 node *next;
	
};
node* newnode(int x)
	{
		node* temp=new node();
		temp->data=x;
		temp->next=NULL;
		return temp;
	}
int isempty(node* root)
{
	return !root;
}
void push(node**root,int x)
{
	node*temp=newnode(x);
	 temp->next=*root;
	 *root=temp;
   cout<<"element is pushed"<<endl;
}
int pop(node**root)
{
	if(isempty(*root))
	{
		return INT_MIN;
	}
	node*temp=*root;
	int x=temp->data;
	*root=(*root)->next;
	free(temp);
	return x;
}
int peek(node*root)
{
	if(isempty(root))
	{
		return INT_MIN;
	}
	return root->data;
}
int main()
{
	node* root =NULL;
	for(int i=0;i<10;i++)
	{
		push(&root,i);
	}
	for(int i=0;i<10;i++)
	{
	cout<<peek(root)<<endl;
	cout<<pop(&root)<<endl;
     }
	return 0;
}