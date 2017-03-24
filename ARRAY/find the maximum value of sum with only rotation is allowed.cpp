//PROBLEM :: FIND THE MAXIMUM VALUE OF SUM i*arr[i] WITH ONLY ROTATION IS ALLOWED ON GIVEN ARRAY.
#include<bits/stdc++.h>
using namespace std;
void maxValueAfterRotation(int arr[],int n)
{
	int arrSum=0,R0=0;

	for(int i=0;i<n;i++)
	{
		arrSum+=arr[i];
		R0+=(i*arr[i]);
	}

	int ans=R0;
	for(int i=1;i<n;i++)
	{
		int R1=R0+(arrSum-n*arr[n-i]);			// main logic refer notebook
		if(R1>ans)
			ans=R1;
		R0=R1;
	}

	cout<<"the maximum value in all rotation is :: "<<ans<<"\n";
}
int main()
{
	int arr[]={1, 20, 2, 10};
	int n=sizeof(arr)/sizeof(arr[0]);

	maxValueAfterRotation(arr,n);
}
