// PROBLEM :: MAXIMUM CIRCULAR SUBARRAY SUM

// REQUIRED TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;


int kadane(int arr[],int n)
{
	int msf,currMax;

	currMax=arr[0];
	msf=arr[0];

	for(int i=1;i<n;i++)
	{
		currMax=max(currMax+arr[i],arr[i]);

		if(msf<currMax)
		{
			msf=currMax;
		}
	}

	return msf;
}
int findMaxSum(int arr[],int n)
{
	// case 1 :: when there is no wrapping

		int noWrapSum=kadane(arr,n);

	// case 2 :: when there is wrapping

		// find the total sum of all elements of array

		int totalSum=0;
		for(int i=0;i<n;i++)
			totalSum+=arr[i];


		// find sum of non-contributing and non-wrapping elements
		for(int i=0;i<n;i++)
			arr[i]*=-1;


		// final sum of wrapped elements is the difference of totalSum - non contributing non wrapped elements
		int wrapSum= (totalSum + kadane(arr,n));


	return max(noWrapSum,wrapSum);
}
int main()
{
	int arr[]={8, -8, 9, -9, 10, -11, 12};
	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<"the max cicular subarray sum is :: "<<findMaxSum(arr,n);
}
