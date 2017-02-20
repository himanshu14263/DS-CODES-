// PROBLEM :: COUNT 1'S IN SORTED BINARY ARRAY

#include <bits/stdc++.h>
using namespace std;

int countOneUtil(int arr[],int l,int h,int n)
{
	if(l<=h)
	{
		int md = (l+h)/2;
		if(arr[md]==1 && arr[md-1]==0)
			return md;
		if(md==0 && arr[md]==1)
			return md;
		if(md==n-1 && arr[md]==0)
			return -1;
		if(arr[md]==0)
			return countOneUtil(arr,md+1,h,n);
		if(arr[md]==1)
			return countOneUtil(arr,l,md-1,n);
	}
}
int countOne(int arr[],int n)
{
	return countOneUtil(arr,0,n-1,n);
}
int main()
{
	int arr[]={0,0,0,0,1,1,1,1,1,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x = countOne(arr,n);
	if(x==-1)
		cout<<"no 1 is present in the array\n";
	else
		cout<<"the number of one's in the array is :: "<<n-x;
}
