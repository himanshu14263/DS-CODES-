#include <bits/stdc++.h>
using namespace std;

bool subarrayExists(int arr[],int n)
{
	map<int,bool>sumMap;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum==0 || sumMap[sum]==true)
			return true;
		sumMap[sum]=true;
	}
	return false;
}
int main()
{
	int arr[]={-3, 2, 3, 1, 6};
	int  n = (sizeof(arr)/sizeof(arr[0]));

	if(subarrayExists(arr,n))
		cout<<"a subarray with zero sum exists\n";
	else
		cout<<"no such subarray exists\n";
}
