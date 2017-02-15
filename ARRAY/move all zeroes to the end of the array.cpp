#include <bits/stdc++.h>
using namespace std;

void moveZero(int arr[],int n)
{
	int i,j=n-1;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]==0)
		{
			swap(arr[i],arr[j]);
			j--;
		}
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
	int arr[]={0,0,0,1,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	moveZero(arr,n);
	display(arr,n);
}
