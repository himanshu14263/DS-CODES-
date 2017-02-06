// PROBLEM :: FIND MAX ELEMENT IN THE ARRAY WHICH IS FIRST INCREASING AND THEN DECREASING

// TC REQD :: O(n)

#include <bits/stdc++.h>
using namespace std;

// METHOD 2 :: USING BINARY SEARCH

int bs(int arr[],int l,int h)
{
	// WHEN THERE IS ONLY ONE ELEMENT PRESENT
	if(l==h)
		return arr[l];

	// WHEN THERE ARE ONLY TWO ELEMENTS PRESENT
	if(h==l+1)
		return max(arr[l],arr[h]);

	// WHEN MORE THAN TWO ELEMENTS ARE PRESENT
	int md = (l+h)/2;

	// when current element is greater than elements on both sides
	if(arr[md]>arr[md-1] && arr[md]>arr[md+1])
		return arr[md];

	// when element is greater than previous and less than next.
	if(arr[md]>arr[md-1] && arr[md]<arr[md+1])
		return bs(arr,md+1,h);

	// when element is less than previous and less than next.
	if(arr[md]<arr[md-1] && arr[md]>arr[md+1])
		return bs(arr,l,md-1);

	return -1;
}
int main()
{
	int arr[]={1, 3, 50, 10, 9, 7, 6};
	int n=(sizeof(arr)/sizeof(arr[0]));
	//findMax2(arr,n);

	cout<<"the max element in the array is "<<bs(arr,0,n-1)<<"\n";
}
