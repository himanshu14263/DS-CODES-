// PROBLEM :: COUNT THE INVERSION IN THE ARRAY

// REQUIRED TC: O(N log N)

// refer notebook for comments

#include<bits/stdc++.h>
using namespace std;


int mergeArr(int arr[],int temp[],int l,int md,int h)
{
	int rev_cnt=0;

	int i=l;
	int j=md;
	int k=l;

	while((i<=md-1) && (j<=h))
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
		{
			temp[k++]=arr[j++];
			rev_cnt+=(md-i);
		}
	}

	while(i<=md-1)
		temp[k++]=arr[i++];
	while(j<=h)
		temp[k++]=arr[j++];

	for(int i=l;i<=h;i++)
		arr[i]=temp[i];

	return rev_cnt;
}
int _ms(int arr[],int temp[],int l,int h)
{
	int rev_cnt=0;
	if(l<h)
	{
		int md=(l+h)/2;
		rev_cnt=(_ms(arr,temp,l,md));
		rev_cnt+=(_ms(arr,temp,md+1,h));
		rev_cnt+=mergeArr(arr,temp,l,md+1,h);		// why md+1;
	}

	return rev_cnt;
}

int mergeSort(int arr[],int n)
{
	int temp[n];
	return _ms(arr,temp,0,n-1);
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int arr[]={1,20,6,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	display(arr,n);

	cout<<mergeSort(arr,n);cout<<"\n";

	display(arr,n);


}
