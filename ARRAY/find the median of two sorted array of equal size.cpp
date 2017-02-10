// PROBLEM :: FIND THE MEDIAN OF TWO SORTED ARRAYS OF EQUAL SIZE

// REQURIED TIME COMLEXITY :: O(log n)

#include <bits/stdc++.h>
using namespace std;

int median(int arr[],int n)
{
	if(n%2 == 0)
		return (arr[n/2]+arr[n/2-1])/2;
	return arr[n/2];
}
int findMedian(int a1[],int a2[],int n)
{
	if(n==0)return -1;
	if(n==1)return (a1[0]+a2[0])/2;
	if(n==2)return (max(a1[0],a2[0])+min(a1[1],a2[1]))/2;

	int m1=median(a1,n);
	int m2=median(a2,n);

	if(m1>m2)
	{
		if(n%2 == 0)
			return findMedian(a1,a2+n/2-1,(n/2)+1);
		return findMedian(a1,a2+n/2,n/2+1);
	}

	if(n%2 == 0)
		return findMedian(a1+n/2-1,a2,(n/2)+1);
	return findMedian(a1+n/2,a2,n/2+1);
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int a1[]={1, 2, 3, 6};
	int a2[]={4,6,8,10};
	int n=(sizeof(a1)/sizeof(a1[0]));

	display(a1,n);
	display(a2,n);

	int ans = findMedian(a1,a2,n);

	cout<<"the median of two sorted array is :: "<<ans;
}
