// STOCK SPAN PROBLEM
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cout<<"how many element you want to enter \n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	///////////////////// CODE FOR STOCK SPAN /////////////////////////////

	stack<int>s;
	int span[n];
	s.push(0);
	span[0]=1;

	for(int i=0;i<n;i++)
	{
		while(!s.empty() && a[s.top()]<=a[i])
			s.pop();

		span[i]=s.empty()?(i+1):(i-s.top());
		s.push(i);
	}

	for(int i=0;i<n;i++)
		cout<<span[i]<<" ";

}
