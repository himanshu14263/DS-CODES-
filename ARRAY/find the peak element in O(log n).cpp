// PROBLEM :: FIND THE PEAK ELEMENT IN ARRAY IN O(log N) time.

// CONTRAINT ::  O(log n)

#include <bits/stdc++.h>
using namespace std;

int f(int a[],int l,int h,int n)
{
	if(l<=h)
	{
		int md=(l+h)/2;

		if((md==0 && a[md]>=a[md+1]))
			return a[md];


		else if(md==n-1 && a[md]>=a[md-1])
			return a[md];

		else if((a[md]>=a[md-1]) && (a[md]>=a[md+1]))
			return a[md];

		else if(a[md-1]>=a[md])
			f(a,l,md-1,n);

		else if(a[md+1]>=a[md])
			f(a,md+1,h,n);
	}
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
    int arr[] = {5, 10, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"the peak element is :: "<<f(arr,0,n-1,n);


}
