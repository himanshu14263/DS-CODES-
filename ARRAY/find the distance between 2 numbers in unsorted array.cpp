// PROBLEM :: FIND THE MINIMUM DISTANCE BETWEEN TWO NUMBERS IN UNSORTED ARRAY

// TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;


int findMinDist(int arr[],int n,int x,int y)
{
	int prev;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x || arr[i]==y)
		{
			prev=i;
			break;
		}
	}

	int dist=INT_MAX;
	for(int i=prev+1;i<n;i++)
	{
		if(arr[i]==arr[prev])
			prev=i;
		else if((arr[i]==x || arr[i]==y ) && (arr[i]!=arr[prev]))
			dist=min(dist,abs(i-prev));
	}

	return dist;
}
int main()
{
	int arr[]={1,1,1,2,2,2,2,2,2,3,3,4,4,4,4};
	int n=(sizeof(arr)/sizeof(arr[0]));

	int x,y;
	cout<<"enter the value of x and y \n";
	cin>>x>>y;

	cout<<"the min distance b/w x and y is :: " << findMinDist(arr,n,x,y);
}
