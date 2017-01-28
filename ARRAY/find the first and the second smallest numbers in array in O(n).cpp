// PROBLEM :: FIND THE SMALLEST AND SECOND SMALLEST NUMBER IN ARRAY.


#include <bits/stdc++.h>
using namespace std;

//method 1 :: using merge sort and find displaying the last two numbers

// method 2 :: using the 2-traversals

void func2(int arr[],int n)
{
	int min1=INT_MAX;
	for(int i=0;i<n;i++)
		if(arr[i]<min1)min1=arr[i];

	int min2=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min2 && arr[i]>min1)
			min2=arr[i];
	}

	cout<<min1<<" "<<min2;
}

// method 3 :: using single traversal

void func3(int arr[],int n)
{
	int first,second;
	first=second=INT_MAX;

	for(int i=0;i<n;i++)
	{
		if(arr[i]<first)
			first=arr[i];
		if(arr[i]<second && arr[i]>first)
			second=arr[i];
	}

	cout<<first<<" "<<second;
}


int main()
{

	int arr[]={5,4,3,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);

	func2(arr,n);
	cout<<"\n";
	func3(arr,n);
}
