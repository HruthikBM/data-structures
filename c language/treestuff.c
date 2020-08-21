#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
struct node*insart(struct node*root,int x);
struct node*creat(int x)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node*insart(struct node*root,int x)
{
	if(root==NULL)
	{
		return creat(x);
	}
	else if(x<=root->data)
	{
		root->left=insart(root->left,x);
	}
	else
	{
		root->right=insart(root->right,x);
	}
	return root;
}
void indoor(struct node*root)
{
	if(root!=NULL)
	{
		indoor(root->left);
		printf("%d ",root->data);
		indoor(root->right);
	}
}
int  preorder(struct node*root)
{
	if(root==NULL) return root;
	
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
 void  postorder(struct node*root)
{
	if(root!=NULL)
  {
  	postorder(root->left);
  	postorder(root->right);
  	printf("%d",root->data);
  }
}
struct node* findmin(struct node*root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
struct node*delet(struct node*root,int val)
{
	
	if(root==NULL)
	{
		return root;
	}
	else if(val<root->data)  root->left=delet(root->left,val);
	else if (val>root->data) root->right=delet(root->right,val);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			struct node*temp=root;
			root=root->right;
			free(temp);
		}
		else if (root->right==NULL)
		{
			struct node*temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			struct node*temp=findmin(root->right);
			root->data=temp->data;
			root->right=delet(root->right,temp->data);
	    }
		
	}
	return root;
}


int main()
{
	struct node* root=NULL;
	  root =insart(root,5);
     insart(root,10);
     insart(root,3);
     insart(root,4);
     insart(root,2);
     insart(root,1);
     insart(root,12);
     insart(root,13);
     insart(root,11);
     //struct node*temp=root->right;
     printf("inorder=");
     indoor(root);
     printf("\n");
	 printf("preorder");
     preorder(root);
     printf("\n");
     printf("postorder");
     postorder(root);
     printf("\n");
     root=delet(root,3);
     printf("after delete inorder=");
     indoor(root);
     printf("\n");
     
     return 0;
}
