#include <bits/stdc++.h>
using namespace std;

void mA(int temp[],int arr[],int l,int md,int h)
{
	int i=l;
	int j=md;
	int k=l;

	while(l<=md-1 && j<=h)
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
void sort(int arr[],int n)
{
	int temp[n];
	_ms(temp,arr,0,n-1);
}
int countPairs(int arr[],int n,int k)
{

	sort(arr,n);

	int i=0,j=0;
	int cnt=0;

	while(i<n && j<n)
	{
		if(abs(arr[i]-arr[j])==k)
		{
			cnt++;i++;j++;
		}
		else if(abs(arr[i]-arr[j])>k)
			i++;
		else if(abs(arr[i]-arr[j])<k)
			j++;
	}

	return cnt;
}
int main()
{
	int arr[]={1, 5, 3, 4, 2};
	int n=(sizeof(arr)/sizeof(arr[0]));
	cout<<"enter the value of k ";
	int k;
	cin>>k;

	cout<<"the no of pairs whose difference is equal  to k is :: ";
	cout<<countPairs(arr,n,k);
}
