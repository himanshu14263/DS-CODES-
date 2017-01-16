// PROBLEM :: FINDING THE MAJORITY ELEMENT

#include<bits/stdc++.h>
using namespace std;

// using hash map (MY APPROACH)
void findMajority(int arr[],int n)
{
	int map[100000]={0};

	for(int i=0;i<n;i++)
		map[arr[i]]++;


	int val=INT_MIN;
	int ans;

	for(int i=0;i<100000;i++)
	{
		if(map[i]>val)
		{
			val=map[i];
			ans=i;
		}
	}

	if(val>n/2)
		cout<<"value exists :: "<<ans;
	else
		cout<<"no such value exists\n";
}

// USING BOOTH'S VOTING ALGORITHM

void boothVotingAlgo(int a[],int n)
{
	int ans=a[0];
	int cnt=1;

	for(int i=0;i<n;i++)
	{
		if(a[i]==ans)
			cnt++;
		else
			cnt--;
		if(cnt==0)
		{
			ans=a[i];
			cnt=1;
		}
	}

	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==ans)
			cnt++;
	}

	if(cnt>n/2)
		cout<<"the value is :: "<<ans<<"\n";
	else
		cout<<"NONE\n";
}
int main()
{

	int arr[]={3,3,2,2,2,2,1,3};

	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<"\n";

	//findMajority(arr,n);    // method 1    but works only when the range in which the number can occur is given
	boothVotingAlgo(arr,n);   // method 2	 using booth's voting algo
}

