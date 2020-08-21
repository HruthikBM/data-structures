#include<iostream>
using namespace std;
class queue
{
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};
queue* createqueue(int x)
{
   queue* temp= new queue();
   temp->capacity=x;
   temp->front=temp->size=0;
   temp->rear=x-1;
   temp->array=new int[(temp->capacity*sizeof(int))];
   return temp;
}
int isfull(queue* que)
{
	return  que->size==que->capacity;
}
int isempty(queue* que){
	return que->size==0;
}
void enqueue(queue*que,int val)
{
	if(isfull(que))
	{
		cout<<"full"<<endl;
		return;
	}
	que->rear=(que->rear+1)%que->capacity;
	que->array[que->rear]=val;
	que->size=que->size+1;
	cout<<"element "<<val<<"is succesfully updataed"<<endl;
}
int dequeue(queue*que)
{
  if(isempty(que))
  {
  	cout<<"empty"<<endl;
  	return 0;
  }
  int val=que->array[que->front];
  que->front=(que->front-1)%que->capacity;
  que->size=que->size-1;
  return val;
}
int main()
{
	queue* que=createqueue(10);
	enqueue(que,2);
	cout<<dequeue(que)<<endl;
	que delete[]
	return 0;

}