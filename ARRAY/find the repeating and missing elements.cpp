// PROBLEM :: FIND THE REPEATING AND THE MISSING ELEMENT IN UNSORTED ARRAY

// DESC :: the array contains elements from 1 to n and one of them is missing and one is repeating
//		   find both the numbers;

// REQD TC :: O(N)

#include <bits/stdc++.h>
using namespace std;

void missingAndRepeating(int arr[],int n)
{
	int missing, repeating;

	for(int i=0;i<n;i++)
	{
		if(arr[abs(arr[i])-1]>0)
			arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
		else
			repeating = abs(arr[i]);
	}

	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
			missing = i+1;
	}

	cout<<"the missing element is :: "<<missing<<"\n";
	cout<<"the repeating element is :: "<<repeating<<"\n";
}
int main()
{
	int arr[]={4, 3, 6, 2, 1, 1};
	int n=(sizeof(arr)/sizeof(arr[0]));

	missingAndRepeating(arr,n);
}
