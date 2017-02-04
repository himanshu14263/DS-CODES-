// PROBLEM :: FIND THE NUMBER OF OCCURANCES IN SORTED ARRAY

// TIME COMPLEXITY :: O(log n)

#include <bits/stdc++.h>
using namespace std;

int lowBS(int arr[],int l,int h,int val)
{
	if(l<=h)
	{
		int md=(l+h)/2;
		if((md==0 && arr[md]==val)  ||  (arr[md]==val && arr[md-1]<val))
			return md;
		else if (arr[md]>=val)
			return lowBS(arr,l,md-1,val);
		else
			return lowBS(arr,md+1,h,val);
	}

	return -1;
}

int highBS(int arr[],int l,int h,int val,int n)
{
	if(l<=h)
	{
		int md=(l+h)/2;
		if(((md==n-1) && (arr[md]==val)) || (arr[md]==val && arr[md]<arr[md+1]))
			return md;
		else if(arr[md]>val)
			return highBS(arr,l,md-1,val,n);
		else
			return highBS(arr,md+1,h,val,n);
	}

	return -1;
}
int findOccur(int arr[],int n,int val)
{
	int low = lowBS(arr,0,n-1,val);
	int high = highBS(arr,0,n-1,val,n);

	return (high-low+1);
}
int main()
{
	int arr[]={1,1,1,2,2,2,2,2,2,3,3,4,4,4,4};
	int n=(sizeof(arr)/sizeof(arr[0]));

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	int x;
	cin>>x;

	cout<<"the value "<<x<<" occurs "<<findOccur(arr,n,x)<<" times\n";
}
