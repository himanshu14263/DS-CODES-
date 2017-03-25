// PROBLEM :: MERGE TWO SORTED ARRAYS USING O(1) EXTRA SPACE

#include<bits/stdc++.h>
using namespace std;

int calcSize(int arr[])
{
	return (sizeof(arr)/sizeof(arr[0]));
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void merge(int arr1[],int arr2[],int m,int n)
{
	for(int i=n-1;i>=0;i--)
	{
		int last=arr1[m-1];
		int j;
		for(j=m-2;j>=0 && (arr1[j]>arr2[i]);j--)
				arr1[j+1]=arr1[j];

		if(j!=m-2 || last>arr2[i])
		{
			arr1[j+1]=arr2[i];
			arr2[i]=last;
		}
	}
}
int main()
{
	int arr1[]={1, 5, 9, 10, 15, 20};
	int arr2[]={2, 3, 8, 13};
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);

	cout<<"the original arrays\n";
	display(arr1,m);
	display(arr2,n);

	merge(arr1,arr2,m,n);
	cout<<"\n";

	cout<<"sorted arrays\n";
	display(arr1,m);
	display(arr2,n);
}
