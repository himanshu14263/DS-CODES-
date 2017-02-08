// PROBLEM :: FIND MAX ELEMENT IN THE ARRAY WHICH IS FIRST INCREASING AND THEN DECREASING

// TC REQD :: O(n)

#include <bits/stdc++.h>
using namespace std;


void findMax2(int arr[],int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<arr[i+1])
			cnt++;
		else
		{
			if(cnt<0)
			{
				ans=i;
				cnt=0;
			}
		}
	}

	cout<<arr[ans]<<"\n";
}
int main()
{
	int arr[]={};
	int n=(sizeof(arr)/sizeof(arr[0]));

	findMax(arr,0,n-1);
}