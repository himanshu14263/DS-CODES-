// PROBLEM :: MERGE SORT FOR ARRAYS

// REQUIRED TC: O(N log N)

// refer notebook for comments

#include <bits/stdc++.h>
using namespace std;


void mergeArr(int arr[],int l,int md,int r)
{
	int n1,n2;

	n1=(md-l+1);
	n2=(r-md);

	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];

	for(int j=0;j<n2;j++)
		right[j]=arr[md+1+j];

	int i,j,k;
	i=0;j=0;k=l;

	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=right[j];
			j++;
			k++;
		}
	}

	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int md=(l+r)/2;
		mergeSort(arr,l,md);  			//
		mergeSort(arr,md+1,r);
		mergeArr(arr,l,md,r);
	}
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int main()
{
	int arr[]={4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	display(arr,n);

	mergeSort(arr,0,n-1);

	display(arr,n);
}
