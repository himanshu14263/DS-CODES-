// problem :: find the fixed point in the array

// tc :: O(log n)

#include <bits/stdc++.h>
using namespace std;

int findFixedPt(int arr[],int l,int h)
{
	if(l<=h)
	{
		int md=(l+h)/2;
		if(arr[md]==md)
			return md;
		else if(md > arr[md])
			return findFixedPt(arr,md+1,h);
		else
			return findFixedPt(arr,l,md-1);
	}

	return -1;
}

int main()
{
	int arr[]={-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<findFixedPt(arr,0,n-1);
}
