// PROBLEM :: FIND THE MAXIMUM AVERAGE SUM SUBARRAY OF SIZE 'K'
#include <bits/stdc++.h>
using namespace std;
void findMaxAvgSubArray(int arr[],int n,int k)
{
		int maxSum=0;
		int ansL=0;

		for(int i=0;i<k;i++)
			maxSum+=arr[i];

		int l=0,h=k-1;
		while(h<n-1)
		{
			h++;
			int temp=maxSum;
			temp-=arr[l];
			l++;
			temp+=arr[h];
			if(temp>maxSum)
			{
				maxSum=temp;
				ansL=l;
			}
		}

		cout<<"the starting point is ::"<<ansL<<"\n\n";
		cout<<"the subarray is :: ";

		for(int i=0;i<k;i++)
		{
			cout<<arr[i+ansL]<<" ";
		}
}
int main()
{
	int arr[]={1, 12, -5, -6, 50, 3};
	int n=sizeof(arr)/sizeof(arr[0]);

	int k=4;
	findMaxAvgSubArray(arr,n,k);
}
