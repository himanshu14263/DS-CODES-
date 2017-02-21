#include <bits/stdc++.h>
using namespace std;
void findPair(int arr1[],int arr2[],int n1,int n2,int x)
{
	int min=INT_MAX;
	int l=0;
	int h=n2-1;

	int key1,key2;

	while(l<n1 && h>=0)
	{
		int sum=arr1[l]+arr2[h];
		if(abs(sum-x)<min)
		{
			min=abs(sum-x);
			key1=arr1[l];
			key2=arr2[h];
		}

		if(sum<x)
			l++;
		else
			h--;
	}

	cout<<key1<<" "<<key2;
}
int main()
{
	int arr1[]={1, 4, 5, 7};
	int arr2[]={10, 20, 30, 40};

	int n1=(sizeof(arr1)/sizeof(arr1[0]));
	int n2=(sizeof(arr2)/sizeof(arr2[0]));

	int x=50;

	findPair(arr1,arr2,n1,n2,x);
}
