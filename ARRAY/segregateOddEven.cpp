// PROBLEM :: SEGREGATE ODD AND EVEN NUMBERS

// REQD TC :: O(n)

#include <bits/stdc++.h>
using namespace std;

void segregateOddEven(int arr[],int n)
{
	int l=0,h=n-1;

	while(l<h)
	{
		while(!(arr[l]&1))
			l++;
		while(arr[h]&1)
			h--;

		if(l<h)
		{
			swap(arr[l],arr[h]);
			l++;
			h--;
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
	int arr[]={12,34,45,9,8,90,3};
	int n=(sizeof(arr)/sizeof(arr[0]));

	display(arr,n);

	segregateOddEven(arr,n);

	display(arr,n);
}
