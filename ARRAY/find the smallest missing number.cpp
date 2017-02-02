// PROBLEM :: FIND THE SMALLEST MISSING NUMBER
// DESCP :: given sorted array of n integers where each integer is from 0 to m-1  where m>n. Find the smallest missing number
//          from array.

#include <bits/stdc++.h>
using namespace std;


// METHOD 2 :: LINEAR SEARCH
int findMissing(int arr[],int n)
{
	if(arr[0]!=0)
		return 0;
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if((arr[i+1]-arr[i])!=1)
				return arr[i]+1;
		}
	}
	return INT_MAX;
}
int main()
{
	int arr[]={0,1,2,5,9};
	int m,n;
	cout<<"enter the value of n and m\n";
	cin>>n>>m;

	int x=findMissing(arr,n);

	if(x==INT_MAX)
		cout<<"there is no missing element\n";
	else
		cout<<"the missing element is :: "<<x;
}
