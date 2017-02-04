// PROBLEM :: FIND MAXIMUM LENGTH BITONIC SUBARRAY

// REQD TC :: O(n)

#include <bits/stdc++.h>
using namespace std;


int maxBitonic(int arr[],int n)
{
	int asc[n],desc[n];

	int len=1;
	asc[0]=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			len++;
			asc[i]=len;
		}
		else
		{
			len=1;
			asc[i]=len;
		}
	}

	len=1;
	desc[n-1]=1;

	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>arr[i+1])
		{
			len++;
			desc[i]=len;
		}
		else
		{
			len=1;
			desc[i]=len;
		}
	}

	int ans=INT_MIN;

	for(int i=0;i<n;i++)
	{
		ans=max(ans,(asc[i]+desc[i]-1));
	}

	return ans;

}
int main()
{
	int arr[]={12, 4, 78, 90, 45, 23};
	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<maxBitonic(arr,n);
}
