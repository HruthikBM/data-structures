#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int maxv=15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

void  preorder(int arr[],int i);
/*int getleft(int i)
{
	if(tree[i]!='\0'&&i*2<=maxv)
	{
		return i*2;
	}
	return -1;
}*/
void insart(int arr[],int x,int i)
{

		if(arr[i]==0)
		{
			arr[i]=x;
		}
		else
		{
			if(x<=arr[i])
			{
				insart(arr,x,2*i);
			}
			else
			{
				insart(arr,x,(i*2)+1);
			}
		}
	

	
}
/*int getright(int i)
{
	if(tree[i]!='\0'&&(i*2)+1<=maxv)
     {
     	return (i*2)+1;
     	
	 }
	 return -1;
}
void  preorder(int i)
{
	if(tree[i]!='\0'&&i>0)
	{
		printf("%d ",tree[i]);
		preorder(getleft(i));
		preorder(getright(i));
	}
}*/
int main()
{
	int arr[6];
	int i,val;
//	preorder(1);
	for(i=0;i<6;i++)arr[i]=0;
	printf("entr 15 val\n");
	for(i=0;i<6;i++)
	{
		printf("entr\n");
		scanf("%d",&val);
	
	      insart(arr,val,1);
    }
    for(i=0;i<6;i++)
    {
	
    printf("%d",arr[i]);
    }
    //preorder(1);

	return 0;
}
