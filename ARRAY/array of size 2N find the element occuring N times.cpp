// PROBLEM :: N elements of array a 2N array are same remaining N are different find the same element. Find the same element.

#include <bits/stdc++.h>
using namespace std;

// USING BOOTH'S VOTING ALGORITHM

void  boothVotingAlgo(int a[],int n)
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

	cout<<"the N times common element is :: ";
	cout<<ans<<"\n";
}
int main()
{

	int arr[]={1,3,2,2,2,2,4,5};

	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<"\n";

	boothVotingAlgo(arr,n);

}

