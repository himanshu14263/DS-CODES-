// PROBLEM :: FIND THE MISSING NUMBER.
//			  array contains number from 1 to n and one of the number is missing find the missing number.

#include<bits/stdc++.h>
using namespace std;



// MEHTOD 1 :: USING SUM OF NUMBERS
void findMissing(int arr[],int n)
{
	int actualSum=0;
	int currSum=0;

	for(int i=0;i<n;i++)
		currSum+=arr[i];

	int k=n+1;
	actualSum=(k*(k+1))/2;
	cout<<actualSum-currSum<<"\n";
}


// METHOD 2 :: USING XOR
void findMissing2(int arr[],int n)
{
	int xorArrElement=arr[0];
	int xor1ToN=1;
	for(int i=1;i<n;i++)
		xorArrElement=(xorArrElement^arr[i]);

	for(int i=2;i<=n+1;i++)
		xor1ToN=(xor1ToN^i);

	cout<<(xor1ToN^xorArrElement);
}
int main()
{

	int arr[]={1,2,4,6,3,7,8};

	int n = sizeof(arr)/sizeof(arr[0]);

	findMissing(arr,n);
	cout<<"\n";
	findMissing2(arr,n);



}

