// PROBLEM :: FIND SUBARRAY WITH GIVEN SUM

// TC :: O(N^2)

#include <bits/stdc++.h>
using namespace std;

// MEHTOD 1 :: USING TWO LOOPS
void func(int arr[],int n,int sum)
{
	int i,j;
	int flag=0;
	for(i=0;i<n;i++)
	{
		int temp=0;
		for(j=i;j<n;j++)
		{
			temp+=arr[i];
			if(temp==sum)
			{
				flag=1;
				break;
			}
		}

		if(flag==1)
			break;
	}

	cout<<i<<" "<<j;
}

// METHOD 2 :: USING SINGLE LOOP (EFFECTIVE SOLUTIONS)

void func2(int arr[],int n,int sum)
{
	int currSum=arr[0];
	int start=0,i;

	for(i=1;i<=n;i++)
	{
		while(currSum>sum && start < i-1)
		{
			currSum-=arr[start];
			start++;
		}

		if(currSum==sum)
		{
			cout<<"the subarray is found b/w "<<start<<" and "<<i-1;
			return;
		}

		if(i<n)
			currSum+=arr[i];
	}

	cout<<"no subarray is found\n";
	return;
}
int main()
{
	int arr[]={1, 4, 100, 3, 10, 5};
	int n=(sizeof(arr)/sizeof(arr[0]));

	func2(arr,n,18);
}
