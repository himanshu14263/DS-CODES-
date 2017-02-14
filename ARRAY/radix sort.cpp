// PROBLEM :: RADIX SORT

#include <bits/stdc++.h>
using namespace std;


void countSort(int arr[],int n,int exp)
{
	int count[10]={0};
	int output[n];

	for(int i=0;i<n;i++)
	{
		count[(arr[i]/exp)%10]++;
	}

	for(int i=1;i<10;i++)
		count[i]+=count[i-1];

	for(int i=n-1;i>=0;i--)
	{
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		--count[(arr[i]/exp)%10];
	}

	for(int i=0;i<n;i++)
		arr[i]=output[i];

}
void radixSort(int arr[],int n)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}

	int d=0;
	while(max!=0)
	{
		d++;
		max/=10;
	}

	int exp=1;
	for(int i=0;i<d;i++)
	{
		countSort(arr,n,exp);
		exp*=10;
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
    int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
    int n=sizeof(arr)/sizeof(arr[0]);

    display(arr,n);
    radixSort(arr,n);
    display(arr,n);
}
