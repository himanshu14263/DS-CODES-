// PROBLEM :: PRINT THE GIVEN ARRAY IN ZIG-ZAG MANNER.

// REQUIRED TIME COMPLEXITY :: O(N)

#include <bits/stdc++.h>
using namespace std;

void formZigZag(int arr[],int n)
{

	cout<<"the original array is :: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n\n";


	// main logic starts here
	bool flag=1;
	for(int i=0;i<n-1;i++)
	{
		if(flag)
		{
			if(arr[i+1]<arr[i])
				swap(arr[i+1],arr[i]);
			flag=!flag;
		}
		else
		{
			if(arr[i]<arr[i+1])
				swap(arr[i],arr[i+1]);
			flag=!flag;
		}
	}

	// printing the zig-zaged array

	cout<<"the zig-zaged array is :: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int main()
{
	int arr[]={4, 3, 7, 8, 6, 2, 1};

	int n=sizeof(arr)/sizeof(arr[0]);

	formZigZag(arr,n);
}
