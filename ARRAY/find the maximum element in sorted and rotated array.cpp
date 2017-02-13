// PROBLEM :: FIND THE MAXIMUM ELEMENT IN SORTED AND ROTATED ARRAY

// REQUIRED T.C. :: O(log n)


#include <bits/stdc++.h>
using namespace std;

int func(int arr[],int l, int h)
{
	if(l==h)return l;
	if(arr[l]<arr[h])return l;
	int md=(l+h)/2;

	if(arr[l]>arr[md])return func(arr,l,md);
	return func(arr,md+1,h);
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n= (sizeof(arr)/sizeof(arr[0]));

	int lowest=func(arr,0,n-1);

	if(lowest==0)
	{
		cout<<"the max element is :: "<<arr[n-1]<<"\n";
	}
	else
	{
		cout<<"the max element is :: "<<arr[lowest-1]<<"\n";
	}
}
