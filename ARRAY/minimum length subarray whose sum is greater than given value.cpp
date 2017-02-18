// PROBLEM :: MINIMUM LENGTH SUBARRAY WHOSE SUM IS GREATER THAN GIVEN VALUE
// TIME COMPLEXITY :: O(n)

#include <bits/stdc++.h>
using namespace std;

void func(int arr[],int n,int x)
{
	int s,i;
	s=0;
	int sum=0;
	int minLength=n+1;
	int strt,end;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];

		while( sum>x && s<=i)
		{
			int temp=i-s+1;
			if(temp<minLength)
			{
				minLength=temp;
				strt=s;end=i;
			}

			sum-=arr[s++];
		}
	}
	cout<<"the minimum length is :: "<<minLength<<"\n";
	cout<<"array is present at from "<<strt<<" to "<<end<<"\n";

}
int main()
{
	int arr[]={1, 10, 5, 2, 7};
	int n=(sizeof(arr)/sizeof(arr[0]));
	int x=9;
	func(arr,n,x);
}