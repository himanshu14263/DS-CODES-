// PROBLEM :: FIND HOW MANY TRIANGLES ARE POSSIBLE.

// REQUIRED TIME COMPLEXITY :: O(n)

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
void mergeSort(int arr[],int n)
{
	int temp[n];
	_ms(temp,arr,0,n-1);
}
int countTriangle(int arr[],int n)
{
	mergeSort(arr,n);
	int cnt=0;

	for(int i=0;i<n-2;i++)
	{
		int k=i+2;

		for(int j=i+1;j<n;j++)
		{
			while(k<n && arr[i]+arr[j]>arr[k])
				k++;
			cnt+=(k-j-1);
		}
	}

	return cnt;
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int arr[]={4, 6, 3, 7};
	int n=(sizeof(arr)/sizeof(arr[0]));


	int cnt = countTriangle(arr,n);
	cout<<"the total number of possible triangles :: "<<cnt;
}
