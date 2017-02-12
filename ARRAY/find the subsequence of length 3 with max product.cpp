// PROBLEM :: FIND THE SUBSEQUENCE OF LENGTH 3 WITH MAXIMUM PRODUCT

// REQUIRED TC :: O(n log n)

#include <bits/stdc++.h>
using namespace std;


void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
}
void maxProdSubsequence(int arr[],int n)
{
	int lsl[n];
	int lgr[n];

	// FILLING LSL USING SELF BALANCING BINARY TREE IN O(n log n)
	set<int>s;
	s.insert(arr[0]);

	lsl[0]=-1;
	for(int i=1;i<n;i++)
	{
		s.insert(arr[i]);
		set<int>::iterator it = s.lower_bound(arr[i]);
		if(it!=s.begin())
		{
			it--;
			lsl[i]=*it;
		}
		else
		{
			lsl[i]=-1;
		}
	}

	// FILLING LGR USING NORMAL ARRAY CONCEPT IN O(n)

	int max=arr[n-1];
	lgr[n-1]=-1;
	for(int i=n-2 ; i>=0 ; i--)
	{
		if(arr[i]<max)
		{
			lgr[i]=max;
		}
		else
		{
			lgr[i]=-1;
			max=arr[i];
		}
	}

	int ans=INT_MIN;

	int a,b,c;



	for(int i=0;i<n;i++)
	{
		int temp=arr[i];
		if(lgr[i]!=-1)
			temp*=lgr[i];
		if(lsl[i]!=-1)
			temp*=lsl[i];

		if(temp>ans)
		{
			a=lgr[i];
			b=arr[i];
			c=lsl[i];
			ans=temp;
		}
	}


	cout<<"the subsequence with longest increasing product is :: ";
	cout<<a<<" "<<b<<" "<<c<<"\n";


}
int main()
{
	int arr[]={6, 7, 8, 1, 2, 3, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	maxProdSubsequence(arr,n);
}
