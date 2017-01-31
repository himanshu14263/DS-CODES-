// PROBLEM :: SORT ARRAY CONTAINING 0,1,2 ONLY IN O(n)

#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[],int n)
{
	int lo=0,md=0,hi=n-1;

	while(md<hi)
	{
		switch(arr[md])
		{
			case 0:
				swap(arr[lo],arr[md]);
				lo++;
				md++;
				break;

			case 1:
				md++;
				break;

			case 2:
				swap(arr[md],arr[hi]);
				hi--;
				break;
		}
	}
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
		cout<<"\n";
}
int main()
{
	int arr[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n=(sizeof(arr)/sizeof(arr[0]));

	display(arr,n);
	sort012(arr,n);
	display(arr,n);
}
