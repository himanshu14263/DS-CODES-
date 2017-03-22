// PROBLEM :: TRAPPING RAIN WATER PROBLEM.

#include <bits/stdc++.h>
using namespace std;

void findTrappedWater(int arr[],int n)
{
	int leftMax[n],rightMax[n];
	int lMax=0,rMax=0;
	for(int i=0;i<n;i++)
	{
		leftMax[i]=lMax;
		if(arr[i]>lMax)
			lMax=arr[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		rightMax[i]=rMax;
		if(arr[i]>rMax)
			rMax=arr[i];
	}

	int waterStored=0;
	for(int i=1;i<n-1;i++)
	{
		waterStored+=(min(leftMax[i],rightMax[i])-arr[i]);
	}

	cout<<"water stored is :: "<<waterStored<<"\n";

}
int main()
{
	int arr[]={3,0,0,2,0,4};
	int n=sizeof(arr)/sizeof(arr[0]);

	findTrappedWater(arr,n);
}
