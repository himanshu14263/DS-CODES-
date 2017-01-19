// PROBLEM :: FIND THE ELEMENT IN SORTED AND ROTATED ARRAY

// the required time complexity is : O(log n)

#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l,int r,int key)
{
	if(l>r)return -1;

	int md=(l+r)/2;

	if(arr[md]==key)
		return md;

	if(arr[l]<=arr[md])			// checking if this half is sorted or not 
	{
		if(key>=arr[l] && key<=arr[md])
			return search(arr,l,md-1,key);
		else
			return search(arr,md+1,r,key);
	}

	if(key>=arr[md] && key<=arr[r])				// if first half isn't sorted then this half will be sorted.
		return search(arr,md+1,r,key);
	return search(arr,l,md-1,key);
}
int main()
{

	int arr[]={3,4,5,6,7,1,2};

	int n = sizeof(arr)/sizeof(arr[0]);

	int x;
	cout<<"enter the number to search\n";
	cin>>x;

	cout<<search(arr,0,n-1,x);
}

