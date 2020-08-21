#include<stdio.h> 
struct node
{
	int data;
	struct node*next;
};
struct queue
{
	struct node*front;
	struct node*rear;
};
struct queue*creat()
{
	struct queue*qu=(struct queue*)malloc(sizeof(struct queue));
	qu->front=NULL;
	qu->rear=NULL;
	return qu;
}

int main()
{
	struct queue*qu=creat();
	printf()
	return 0;
}
