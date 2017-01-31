// PROLEM :: FIND THE TWO REPEATING ELEMENT IN THE ARRAY

#include <bits/stdc++.h>
using namespace std;

void findRepeat(int arr[],int n)
{
	map<int,int>mp;

	for(int i=0;i<n;i++)
	{
		if(!mp[arr[i]])
			mp[arr[i]]=1;
		else
			cout<<arr[i]<<" ";
	}
}
int main()
{
	int arr[]={1,2,3,4,5,2,4};
	int n=(sizeof(arr)/sizeof(arr[0]));

	findRepeat(arr,n);
}
