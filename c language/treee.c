#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
struct node* insart(struct node*root,int x);
struct node*getnode(int x)
{
   struct node*temp=(struct node*)malloc (sizeof(struct node));
   temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
} 
bool search(struct node*root,int c)
{
	if(root==NULL)return false;
	else if(c==root->data)return true;
	else if(c<=root->data)return search(root->left,c);
	else return search(root->right,c);
	
}
int maxc(struct node*root)
{
	//struct  node*temp=root;
	if(root==NULL)
	{
		  printf("tree is empty");
		return 0;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;

}
//int maxc
struct node* insart(struct node*root,int x)
{
	if(root==NULL)
	{
	    return  getnode(x);
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
		printf("%d",root->data);
		indoor(root->right);
	}
}
//int minch
int main()
{
	struct node*root=NULL;
	int c,val;
	printf("1.insart,2.indoor,3.sarch,4.maxc,5.exit\n");
	scanf("%d",&c);
	while(c!=5)
	{
		if(c==1)
		{
		 printf("enter the val\n");
		 scanf("%d",&val);
         if(root==NULL) root=insart(root,val);
         else insart(root,val);
        }
        if(c==2)
        {
        	
             indoor(root);
			 printf("\n");	
		}
		if(c==3)
		{
			printf("enter val to be che\n");
			scanf("%d",&val);
			if(search(root,val))
			{
				printf("found");
			}
			else
			{
				printf("notfound");
			}
			printf("\n");
		}
		if(c==4)
		{
			printf("minvalu\n");
		    printf("%d",maxc(root));	
		}
        printf("1.insart,2.indoor,3.sarch,4.maxc,5.exit\n");
        scanf("%d",&c);
   }
	return 0;
}
