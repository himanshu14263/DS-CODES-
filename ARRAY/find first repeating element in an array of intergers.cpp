// PROBLEM :: FIND FIRST REPEATING ELEMENT WHOSE FIRST ELEMENT HAS MINIMUM INDEX.
// DESCRIPTION :: there will be many repeating elements but we have to print that element whose first element's index is the minimum.

#include <bits/stdc++.h>
using namespace std;

void findFirstRepeating(int arr[],int n)
{
	int minIndex=INT_MAX;
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		if(mp[arr[i]]==0)
			mp[arr[i]]=i;
		else
		{
			if(mp[arr[i]]<minIndex)	// checking if the first element index of this element is minimum of all repeating elements.
				minIndex=i;
		}
	}

	cout<<"repeating element with minimum index of first element is :: "<<arr[minIndex]<<"\n";
}

int main()
{
	int arr[]={10, 5, 3, 4, 3, 5, 6};
	int n = (sizeof(arr)/sizeof(arr[0]));
	findFirstRepeating(arr,n);
}
