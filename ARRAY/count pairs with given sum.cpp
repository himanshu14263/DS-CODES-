// PROBLEM :: COUNT PAIRS WITH GIVEN SUM

// TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;
int countPairs(int arr[],int n,int sum)
{
	map<int,int>mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;

	int pairCnt=0;
	for(int i=0;i<n;i++)
	{
		pairCnt+=(mp[sum-arr[i]]);

		if(arr[i]==(sum-arr[i]))
			pairCnt--;
	}
	return pairCnt/2;
}
int main(int argc, char const *argv[])
{
	int arr[]={1, 5, 7, -1, 5};
	int n=sizeof(arr)/sizeof(arr[0]);

	int sum=6;
	int x=countPairs(arr,n,sum);
	cout<<"the number of pairs are :: "<<x;
	return 0;
}
