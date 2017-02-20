// PROBLEM :: GIVEN A SORTED ARRAY FIND A PAIR WHOSE SUM IS CLOSEST TO GIVEN VALUE x.

#include <bits/stdc++.h>
using namespace std;

void findPair(int arr[],int n,int x)
{
	int l,h;
	l=0;h=n-1;

	int val1,val2;
	int min=INT_MAX;

	while(l<h)
	{
		int sum=arr[l]+arr[h];
		if(abs(sum-x)<min)
		{
			min=abs(sum-x);
			val1=arr[l];
			val2=arr[h];
		}
		if(sum<x)
			l++;
		else
			h--;
	}

	cout<<val1<<" "<<val2;
}
int main()
{
	int arr[]={1, 3, 4, 7, 10};
	int n=sizeof(arr)/sizeof(arr[0]);

	int x;
	cin>>x;

	findPair(arr,n,x);
}
