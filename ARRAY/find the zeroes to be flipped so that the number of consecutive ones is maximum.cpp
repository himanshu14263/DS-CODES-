// PROBLEM :: FIND THE ZEROES TO BE FLIPPED SO THAT NUMBER OF CONSECUTIVE 1'S IS MAXIMUM.

#include <bits/stdc++.h>
using namespace std;

void findZeroPos(int arr[],int n,int m)
{
	int wL=0,wR=0,bestWindow=0,bestL=0,zeroCount=0;

	while(wR<n)
	{
		if(zeroCount<=m)
		{
			if(arr[wR]==0)
				zeroCount++;
			wR++;
		}
		if(zeroCount>m)
		{
			if(arr[wL]==0)
				zeroCount--;
			wL++;
		}
		if((wR-wL)>bestWindow)
		{
			bestWindow=(wR-wL);
			bestL=wL;
		}
	}

	cout<<"maximum number of consecutive ones :: "<<bestWindow<<"\n";
	cout<<"the zeroes index are :: ";
	for(int i=0;i<bestWindow;i++)
	{
		if(arr[bestL+i]==0)
			cout<<bestL+i<<" ";
	}
}
int main()
{
	int arr[]={1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m=2;

	findZeroPos(arr,n,m);
}
