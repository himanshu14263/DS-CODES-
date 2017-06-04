// PROBLEM :: BINARY INDEXED TREE (CREATION AND QUERYING)

#include<bits/stdc++.h>
using namespace std;

void updateBIT(int BIT[],int n ,int i,int delta)
{
	int index = i+1;

	while(index<=n)
	{
		BIT[index]+=delta;
		index+= (index & (-index));
	}
}

int getResult(int BIT[],int n)
{
	int index = n+1;

	int sum = 0;

	while(index>0)
	{
		sum+=BIT[index];
		index -= (index & (-index));
	}
	return sum;
}

void createBIT(int arr[],int BIT[],int n)
{
	for(int i=0;i<=n;i++)
		BIT[i]=0;

	for(int i=0;i<n;i++)
		updateBIT(BIT,n,i,arr[i]);
}

int main()
{
	int arr[]={2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *BIT = new int[n+1];

	// create fenwick tree
		createBIT(arr,BIT,n);

		cout<<"the fenwick tree before update\n";
		for(int i=0;i<=n;i++)
			cout<<BIT[i]<<" ";
		cout<<"\n";

	// query fenwick tree

		cout<<"the sum of first 5 elements :: "<<getResult(BIT,5)<<"\n";

	// update fenwich tree

		updateBIT(BIT,n,3,6);

		cout<<"\nthe fenwick tree after update\n";
				for(int i=0;i<=n;i++)
					cout<<BIT[i]<<" ";
				cout<<"\n";

	// query fenwick tree
				cout<<"the sum of first 5 elements :: "<<getResult(BIT,5)<<"\n";

}
