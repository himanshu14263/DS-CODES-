// PROBLEM :: FIND PRODUCT OF ALL ELEMENTS OF MAXIMUM PRODUCT SUBARRAY

// CONSTRAINT :: TC(O(n)) and space complexity :: O(1)

#include <bits/stdc++.h>
using namespace std;

int findMaxProduct(int arr[],int n)
{
	int currMax=1;
	int currMin=1;
	int msf=1;

	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			currMax=currMax*arr[i];
			currMin=min(1,currMax*arr[i]);
		}

		else if(arr[i]==0)
		{
			currMax=1;
			currMin=1;
		}

		else
		{
			int temp=currMax;
			currMax=max(1,currMin*arr[i]);
			currMin=min(1,temp*arr[i]);
		}

		if(msf<currMax)
			msf=currMax;
	}

	return msf;
}
int main()
{
	int arr[]={6, -3, -10, 0, 2};
	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<findMaxProduct(arr,n);
}
