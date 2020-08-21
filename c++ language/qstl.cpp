#include<iostream>
using namespace std;
#include<queue>
void shoq(queue <int> q)
{
	queue <int> qu=q;
	while(!qu.empty())
	{
		cout<<qu.front()<<' ';
		qu.pop();
	}
	cout<<endl;
}
int main()
{
	int t;
  cout<<"no of test case't'=";
	cin>>t;
	while(t--)
	{
		  queue <int> q;

		  int n,val;
		  cout<<"no of val=";
		  cin>>n;
		  for(int i=0;i<n;i++){
		  cout<<"enter val";
		  	cin>>val;
		  	q.push(val);
		  }
		  shoq(q);

	}
return 0;

}