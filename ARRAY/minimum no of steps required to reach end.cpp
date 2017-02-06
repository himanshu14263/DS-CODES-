// PROBLEM :: MINIMUM NO OF STEPS REQUIRED TO REACH THE END

// TC :: O(n ^ 2)

#include <bits/stdc++.h>
using namespace std;

int minSteps(int arr[],int n)
{
	int jumps[n];

	if(arr[0]==0 || n==0)
		return INT_MAX;

	jumps[0]=0;

	for(int i=1;i<n;i++)
	{
		jumps[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(i<=j+arr[j] && arr[j]!=INT_MAX)
			{
				jumps[i]=min(jumps[i],jumps[j]+1);
				break;
			}
		}
	}

	for(int i=0;i<n;i++)
		cout<<jumps[i]<<" ";
	cout<<"\n";
	return jumps[n-1];
}
int main()
{
	int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n=(sizeof(arr)/sizeof(arr[0]));

	int ans = minSteps(arr,n);

	if(ans==INT_MAX)
		cout<<"end point isn't reachable\n";
	else
		cout<<"minimum no of steps required are "<<ans<<"\n";
}
