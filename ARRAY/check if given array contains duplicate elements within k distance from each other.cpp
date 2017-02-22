// PROBLEM :: CHECK IF GIVEN ARRAY CONTAINS DUPLICATE ELEMENTS WITHIN 'K' DISTANCE FROM EACH OTHER

// TC :: O(n)

#include <bits/stdc++.h>
using namespace std;

bool findDuplicates(int arr[],int n,int k)
{
	map<int,int>mp;

	for(int i=0;i<n;i++)
	{
		if(i>k)
			mp[arr[i-k-1]]=0;

		if(mp[arr[i]]==1)
			return true;

		mp[arr[i]]=1;
	}

	return false;
}
int main()
{
	int arr[]={1, 2, 3, 1, 4, 5};
	int n = (sizeof(arr)/sizeof(arr[0]));
	int k=3;

	cout<<"the given array is :: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	cout<<"the value of k is :: "<<k<<"\n\n";

	if(findDuplicates(arr,n,k))
		cout<<"duplicates present\n";
	else
		cout<<"duplicates not present\n";
}
