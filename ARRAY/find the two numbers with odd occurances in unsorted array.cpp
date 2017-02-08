// PROBLEM :: FIND 2 NUMBERS WITH ODD OCCURANCES IN UNSORTED ARRAY

// CONSTRAINTS :: TC-> O(n)  &  no extra space should be used.


#include <bits/stdc++.h>
using namespace std;


void findOddNumbers(int arr[],int n)
{
	int xor,x,y;

	xor=arr[0];
	x=0,y=0;

	for(int i=1;i<n;i++)
		xor^=arr[i];

	set_bit_no=(xor & (~(xor-1)));

	for(int i=0;i<n;i++)
	{
		if(arr[i] & set_bit_no)
			x^=arr[i];
		else
			y^=arr[i];
	}

	cout<<x<<"   "<<y;
}
int main()
{
	int a[]={};
	int n=(sizeof(arr)/sizeof(arr[0]));

	findOddNumbers(arr,n);
}