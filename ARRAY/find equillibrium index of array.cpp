// PROBLEM :: FIND THE EQUILLIBRIUM INDEX OF ARRAY
// TC :: O(n)

#include <bits/stdc++.h>
using namespace std;

int equillibrium(int arr[],int n)
{
	int leftsum,sum=0;

	// find sum and consider it as rightsum of array
	for(int i=0;i<n;i++)
			sum+=arr[i];

	// initialize leftsum as 0
		leftsum=0;

	// now iterate through all the elements and do following
			// remove current element from rightsum
			// check if rightsum is equal to leftsum, if equal return current index
			// add current element to the leftsum
	for(int i=0;i<n;i++)
	{
		sum-=arr[i];

		if(sum == leftsum)
			return i;

		leftsum+=arr[i];
	}

	// if no such index is found return -1
	return -1;
}
int main()
{
	int arr[]={-7,1,5,2,-4,3,0};
	int n=(sizeof(arr)/sizeof(arr[0]));

		int  x = equillibrium(arr,n);

	if(x == -1)
		cout<<"no equillibrium index exists\n";
	else
	{
		cout<<"the equillibrium index is :: "<< x<<"\n";
	}
}
