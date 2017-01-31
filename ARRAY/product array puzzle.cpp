// PROBLEM :: PRODUCT ARRAY PUZZLE
// a[i] should contain the product of all elements excluding the current
// element.

// REQD TC :: O(N)

#include <bits/stdc++.h>
using namespace std;

void findProdArr(int arr[],int n)
{
	int prod[n];
	memset(prod,1,sizeof(arr));

	int temp=1;
	for(int i=0;i<n;i++)
	{
		prod[i]*=temp;
		temp*=arr[i];
	}

	int temp=1;
	for(int i=n-1;i>=0;i--)
	{
		prod[i]*=temp;
		temp*=arr[i];
	}

	for(int i=0;i<n;i++)
		cout<<prod[i]<<" ";
	cout<<"\n";
}
int main()
{
	int arr[]={10,3,5,6,2};
	int n=(sizeof(arr)/sizeof(arr[0]));

	findProdArr(arr,n);
}