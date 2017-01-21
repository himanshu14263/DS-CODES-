// PROBLEM : PROGRAM FOR ARRAY ROTATION
// TC: O(N)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

// recursive method ....
void reverse(int arr[],int s,int e)
{
	if(s>=e)
		return;

	int temp=arr[s];
	arr[s]=arr[e];
	arr[e]=temp;

	reverse(arr,s+1,e-1);
}

// USING REVERSAL ALGO
// first reverse the first half
// reverse the second half
// now reverse the entire array
// you will get the rotated array.
void arrayRotation(int arr[],int n,int d)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}
int main()
{
	int arr[]={1,2,3,4};

	int n=(sizeof(arr)/sizeof(arr[0]));

	display(arr,n);

	int d;
	cout<<"enter the value to rotate\n";
	cin>>d;

	arrayRotation(arr,n,d);

	display(arr,n);

}
