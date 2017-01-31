// PROBLEM :: FIND THE SHORTEST LENGTH SUBARRAY SORTING WHICH MAKES THE COMPLETE ARRAY SORTED.
// REQUIRED TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;

void findSubArr(int arr[],int n)
{
	int s=INT_MAX,e;

	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[i+1])
		{
			s=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]<arr[i-1])
		{
			e=i;
			break;
		}
	}


	int min=arr[s],max=arr[e];
	for(int i=s;i<=e;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}

	for(int i=0;i<s;i++)
	{
		if(arr[i]>min)
			s=i;
	}
	for(int i=e+1;i<n;i++)
	{
		if(arr[i]<max)
			e=i;
	}


	cout<<"the starting and ending of subarray is :: "<<s<<" "<<e;
}
int main()
{
	int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n=(sizeof(arr)/(sizeof(arr[0])));

	findSubArr(arr,n);
}
