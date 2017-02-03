// PROBLEM :: GIVEN AN ARRAY ARR[] FIND MAX (j-i) SUCH THAT ARR[j] > ARR[i]

// TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;

int findMaxDiff(int arr[],int n)
{

	int lMin[n],rMax[n];
	lMin[0]=arr[0];
	for(int i=1;i<n;i++)
		lMin[i]=min(arr[i],lMin[i-1]);

	rMax[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
		rMax[i]=max(arr[i],rMax[i+1]);

	int minDist=-1;

	int i=0,j=0;
	while(i<n && j<n)
	{
		if(lMin[i]<rMax[j])
		{
			minDist=max(minDist,j-i);
			j++;
		}
		else
			i++;
	}

	return minDist;
}
int main()
{
	int arr[]={9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<findMaxDiff(arr,n);
}
