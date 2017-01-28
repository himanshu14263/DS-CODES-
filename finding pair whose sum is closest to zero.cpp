// PROBLEM :: FINDING THE PAIR WHOSE SUM IS CLOSEST TO ZERO.

// TC : O(N LOG N)

#include <bits/stdc++.h>
using namespace std;


void mergeArr(int arr[],int temp[],int l,int md,int h)
{
	int i=l;
	int j=md;
	int k=l;

	while((i<=md-1) && (j<=h))
	{
		if(arr[i]<=arr[j])
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
void _ms(int arr[],int temp[],int l,int h)
{
	if(l<h)
	{
		int md=(l+h)/2;
		_ms(arr,temp,l,md);
		_ms(arr,temp,md+1,h);
		mergeArr(arr,temp,l,md+1,h);
	}
}
void ms(int arr[],int n)
{
	int temp[n];
	_ms(arr,temp,0,n-1);
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void findPair(int arr[],int n)
{
	int i=0;
	int j=n-1;

	int sum;
	int ans=INT_MAX;

	int a,b;

	while(i<j)
	{
		sum=(arr[i]+arr[j]);
		if(abs(sum)<ans)
		{
			ans=sum;
			a=arr[i];
			b=arr[j];
		}

		if(sum>0)
			j--;
		else
			i++;
	}

	cout<<a<<" "<<b;
}
int main()
{
	int arr[]={-3,1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	ms(arr,n);

	findPair(arr,n);

}
