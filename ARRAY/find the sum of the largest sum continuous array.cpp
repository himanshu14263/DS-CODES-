// PROBLEM :: find the sum of the largest sum continuous array.

#include<bits/stdc++.h>
using namespace std;

// METHOD 1 : USING KADANE'S ALGORITHM
// DOESN'T WORK IF ALL THE ELEMENTS ARE NEGATIVE

void kadaneAlgo(int arr[],int n)
{
	int max_so_far=0;
	int curr_max=0;

	for(int i=0;i<n;i++)
	{
		curr_max+=arr[i];
		if(curr_max<0)
			curr_max=0;
		else if(curr_max>max_so_far)
			max_so_far=curr_max;
	}

	cout<<max_so_far<<"\n";
}

// METHOD 2 :: IMPROVED VERSION
// works well for all negative elements

void maxSumSubArray(int a[],int n)
{
	int max_so_far=a[0];
	int curr_max=a[0];

	for(int i=1;i<n;i++)
	{
		curr_max=max(a[i],curr_max+a[i]);
		if(curr_max>max_so_far)
			max_so_far=curr_max;
	}

	cout<<max_so_far<<"\n";
}
int main()
{

	int arr[]={-6,-6,-2,-2,-7,-7,-7};

	int n = sizeof(arr)/sizeof(arr[0]);

	kadaneAlgo(arr,n);

	maxSumSubArray(arr,n);

}

