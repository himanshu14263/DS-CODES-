// find the union and intersection of two sorted array.

#include <bits/stdc++.h>
using namespace std;

void intersection(int arr1[],int n1,int arr2[],int n2)
{
	int i=0,j=0;

	while(i<n1 && j<n2)
	{
		if(arr1[i]==arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;j++;
		}
		if(arr1[i]<arr2[j])
			i++;
		else
			j++;
	}
}

void union1(int arr1[],int n1,int arr2[],int n2)
{
	int i=0,j=0;
	while(i<n1 && j<n2)
	{
		if(arr1[i]==arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;j++;
		}
		if(arr1[i]<arr2[j])
		{
			cout<<arr1[i]<<" ";i++;
		}
		else
		{
			cout<<arr2[j]<<" ";j++;
		}
	}

	while(i<n1)
	{
		cout<<arr1[i]<<" ";i++;
	}
	while(j<n2)
	{
		cout<<arr2[j]<<" " ;j++;
	}
}

int main()
{
	int arr1[]={1,3,4,5,7};
	int arr2[]={2,3,5,6};

	union1(arr1,5,arr2,4);
	cout<<"\n\n";
	intersection(arr1,5,arr2,4);
}
