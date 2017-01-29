// PROBLEM :: SEGREGATE Os and 1s IN AN ARRAY 

// REQD TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;

void segregate(int arr[],int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		while((i<j) && (a[i]==0))
			i++;
		while((i<j) && (a[j]==1))
			j--;

		if(i<j)
		{
			a[j]=1;
			a[i]=0;
			i++;
			j--;
		}
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
	int arr[]={1,1,1,1,1,0,0,0,0};
	int n=sizeof(arr)/sizeof(arr[0]);

	display(arr,n);
	segregate(arr,n);
	display(arr,n);
}