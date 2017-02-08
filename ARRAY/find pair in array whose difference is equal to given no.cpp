// FIND PAIR IN ARRAY WHOSE DIFFERENCE IS EQUAL TO A GIVEN NUMBER.
// TC :: O(n log n)

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
void sort(int arr[],int n)
{
	int temp[n];
	_ms(temp,arr,0,n-1);
}
void findPair(int arr[],int n,int diff)
{
	sort(arr,n);

	int i=0,j=1;

	while(i<j)
	{
		if((i!=j) && (abs(arr[i]-arr[j])==diff))
		{
			cout<<arr[i]<<" "<<arr[j]<<"\n";
			return ;
		}
		else if(abs(arr[i]-arr[j])<diff)
			j++;
		else
			i++;
	}

	cout<<"no such pair exists\n";
}
int main()
{
	int arr[]={1, 8, 30, 40, 100};
	int n=(sizeof(arr)/sizeof(arr[0]));

	int diff;

	cout<<"enter the value of difference\n";
	cin>>diff;

	findPair(arr,n,diff);

}

