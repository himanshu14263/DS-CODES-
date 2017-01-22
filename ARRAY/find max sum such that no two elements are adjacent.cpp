// FIND MAX SUM SUCH THAT NO TWO ELEMENTS ARE ADJACENT

// REQUIRED TC: O(N)

// refer notebook for comments

#include<bits/stdc++.h>
using namespace std;

int findMax(int a[],int n)
{
	int incl=a[0],excl=0,excl_temp;

	for(int i=1;i<n;i++)
	{
		excl_temp=max(incl,excl);

		incl=excl+a[i];

		excl=excl_temp;
	}

	return max(incl,excl);

}
int main()
{
	int arr[]={3,2,7,10};
	int n=sizeof(arr)/sizeof(arr[0]);

	int ans=findMax(arr,n);
	cout<<ans<<"\n";
}
