#include<stdio.h>
#include<stdlib.h>
void order(int arr[],int n,int i)
{
	int par=(i-1)/2;
//	printf("[%d]",par);
	if(arr[i]>arr[par])
	{
	
	 int temp=arr[i];
	 arr[i]=arr[par];
	 arr[par]=temp;	
	 
	  order(arr,n,par);   
    }
   
}
void heaporder(int arr[],int n,int i)
{
	int larg=i;
	int l=i*2+1;
	int r=i*2+2;
	if(l<n&&arr[larg]<arr[l])
	  larg=l;
	if(r<n&&arr[larg]<arr[r])
	  larg=r;
	if(larg!=i)
	{
	int temp=arr[larg];
	arr[larg]=arr[i];
	arr[i]=temp;
	heaporder(arr,n,larg);	
    }    
}
void insart(int arr[],int n,int x)
{
	n=n+1;
	arr[n-1]=x;
	order(arr,n,n-1);
//	print(arr,n);
}
void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
void delet(int arr[],int n)
{
	int last=arr[n-1];
	arr[0]=last;
	n=n-1;
	heaporder(arr,n,0);
	print(arr,n);
}
int main()
{

//	int arr[100];
	 int arr[100];
	 
	int n=0;
	printf("enter  opsn:\n");
	int c;
	scanf("%d",&c);
	while(c!=-1)
	{
	  insart(arr,n,c);	
     	n++;
		printf("enter  opsn:\n");
		scanf("%d",&c);
	}
	print(arr,n);
	printf("\n");
    delet(arr,n);

    
	
//	print(arr,n);
	
	return 0;
}
