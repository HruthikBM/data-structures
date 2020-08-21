#include<bits/stdc++.h>
using namespace std;
#define max 11
class Stack
{
 	int top;
 public: 
 	 int a[max];
 	Stack()
 	{
 		top=-1;
 	}
 	void push(int x);
 	int pop();
    bool isempty();
    bool isfull();
    int peek();
};
bool Stack::isempty()
{
	return top<0;
}
bool Stack::isfull()
{
	return top>=max-1;
}
void Stack::push(int x)
{
    if(isfull())
       cout<<"isfull"<<endl;
   else
   {

   	  a[top++]=x;
   	  cout<<"saccesfullypushed"<<endl;
   }

}
int Stack::pop(){
	if(isempty())
	{
		cout<<"isempty"<<endl;
		return 0;
	}
	else
	{
		int i=a[top--];
		return i;
	}
}
int Stack::peek()
{
	if(isempty())
	{
		cout<<"isempty"<<endl;
		 return 0;
	}
	int x;
	x= a[top];
	return x;
}
int main()
{
	class Stack s;
	for(int i=0;i<10;i++)
	   s.push(i);
	for(int i=0;i<10;i++)
	  cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	for(int i=0;i<12;i++)
	   s.push(i);
	return 0;
}