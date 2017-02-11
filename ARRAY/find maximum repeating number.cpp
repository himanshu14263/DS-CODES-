// PROBLEM :: FIND MAXIMUM REPEATING NUMBER IN O(N) TIME AND O(1) EXTRA SPACE.

// Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer and k <= n.
// Find the maximum repeating number in this array.

#include <bits/stdc++.h>
using namespace std;

int findMaxRepeating(int arr[],int n,int k)
{
	for(int i=0;i<n;i++)
		arr[arr[i]%k]+=k;


	int ans;
	int max=INT_MIN;
	int maxIndex=-1;

	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			maxIndex=i;
		}
	}

	ans=maxIndex;

	// converting array to original form :

	for(int i=0;i<n;i++)
		arr[i]=arr[i]%k;

	return ans;

}
int main()
{
	int arr[]={2, 3, 3, 5, 3, 4, 1, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k;
	cout<<"enter the value of k :: \n";
	cin>>k;
	cout<<"the maximum repeating value is :: "<<findMaxRepeating(arr,n,k);

}
