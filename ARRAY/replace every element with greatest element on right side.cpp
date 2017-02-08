// PROBLEM :: REPLACE EVERY ELEMENT WITH GREATEst ELEMENT ON THE RIGHT SIDE.

#include <bits/stdc++.h>
using namespace std;

// TRICKY MEHTOD  : TC(O(n))

void func(int arr[],int n)
{
	int max=arr[n-1];
	arr[n-1]=-1;

	for(int i=n-2;i>=0;i--)
	{
		int temp=max;

		if(arr[i]>max)
			max=arr[i];

		arr[i]=temp;
	}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";



}
int main()
{
	int arr[]={16, 17, 4, 3, 5, 2};
	int n=(sizeof(arr)/sizeof(arr[0]));

	func(arr,n);
}
