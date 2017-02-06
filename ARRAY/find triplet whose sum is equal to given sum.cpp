// PROBLEM :: FIND TRIPLET WHOSE SUM IS EQUAL TO A GIVEN SUM

// TC :: O(N^2)

#include <bits/stdc++.h>
using namespace std;


void mA(int temp[],int arr[],int l,int md,int h)
{
	int i=l;
	int k=l;
	int j=md;

	while(i<=md-1 && j<=h)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=md-1)
		temp[k++]=arr[i++];

	while(j<=h)
		temp[k++]=arr[j++];

	for(int i=l;i<=h;i++)
		arr[i]=temp[i];
}

void _ms(int temp[],int arr[],int l,int h)
{
	if(l<h)
	{
		int md=(l+h)/2;
		_ms(temp,arr,l,md);
		_ms(temp,arr,md+1,h);
		mA(temp,arr,l,md+1,h);
	}
}
void ms(int arr[],int n)
{
	int temp[n];
	_ms(temp,arr,0,n-1);
}

void findTriplet(int arr[],int n,int sum)
{
	ms(arr,n);

	for(int i=0;i<n-2;i++)
	{
		int l=i+1;
		int r=n-1;

		while(l<r)
		{
			if(arr[i]+arr[l]+arr[r]==sum)
			{
				cout<<"triplet is found "<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<"\n";
				break;
			}
			else if(arr[i]+arr[l]+arr[r]<sum)
				l++;
			else if(arr[i]+arr[l]+arr[r]>sum)
				r--;
		}
	}
}
int main()
{
	int arr[]={1, 4, 45, 6, 10, 8};
	int n=(sizeof(arr)/sizeof(arr[0]));

	int sum=22;
	findTriplet(arr,n,sum);
}
