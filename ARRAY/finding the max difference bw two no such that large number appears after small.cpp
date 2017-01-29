// find the union and intersection of two sorted array.

#include <bits/stdc++.h>
using namespace std;

void intersection(int arr[],int n1)
{

}

void union(int arr1[],int n1,int arr2[],int n2)
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
			cout<<arr1[i];i++;
		}
		else
		{
			cout<<arr2[j];j++;
		}
	}

	while(i<n1)
	{
		cout<<arr1[i];i++;
	}
	while(j<n2)
	{
		cout<<arr2[j];j++;
	}		
}

int main()
{
	int arr1[]={};
	int arr2[]={};

	union(arr1,n1);
	intersection(arr2,n2);
}