// PROBLEM :: COUNT INVERSION OF SIZE 3 IN GIVEN ARRAY

#include<bits/stdc++.h>
using namespace std;

int findInv(int arr[],int n)
{
	int invCnt=0;
	for(int i=0;i<n;i++)
	{
		int less=0;
		for(int j=i+1;i<n;i++)
		{
			if(arr[i]>arr[j])
				less++;
		}
		int great=0;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i]<arr[j])
				great++;
		}

		invCnt+=(less*great);
	}
	return invCnt;
}
int main()
{
	int arr[]={8, 4, 2, 1};
	int n=sizeof(arr)/sizeof(arr[0]);

	int inversions=findInv(arr,n);
	cout<<"the number of inversions are :: "<<inversions<<"\n";

}
