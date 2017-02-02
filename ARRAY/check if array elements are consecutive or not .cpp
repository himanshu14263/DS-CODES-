// CHECK IF THE ARRAY ELEMENT ARE CONSECUTIVE OR NOT
// TC :: O(n)
// BUT THIS METHOD REQUIRES EXTRA SPACE FOR MAPPING FUNCTIONS

#include <bits/stdc++.h>
using namespace std;


bool cond2(int arr[],int n)
{
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		if(mp[i]==0)
			mp[i]=1;
		else
			return 0;
	}
	return 1;
}
bool isConsecutive(int arr[],int n)
{
	int min=INT_MAX,max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}

	bool cond1 = ((max-min+1)==n);
	if((cond1) && (cond2(arr,n)))
		return true;
	else
		return false;
}
int main()
{
	int arr[]={5,2,3,1,4};
	int n=((sizeof(arr)/sizeof(arr[0])));

	if(isConsecutive(arr,n))
		cout<<"elements are consecutive\n";
	else
		cout<<"elements aren't consecutive\n";
}
