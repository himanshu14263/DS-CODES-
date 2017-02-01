// PROBLEM :: FIND DUPLICATES WITH O(N) TIME AND O(1) EXTRA SPACE.

// NOTE :: the given array will contain only n elements and their value will vary from 0 to n-1

#include <bits/stdc++.h>
using namespace std;

void findDuplicates(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])]= -(arr[abs(arr[i])]);
		else
			cout<<abs(arr[i])<<" ";
	}
}
int main()
{
	int arr[]={1,2,3,1,3,6,6};
	int n=(sizeof(arr)/sizeof(arr[0]));

	findDuplicates(arr,n);
}
