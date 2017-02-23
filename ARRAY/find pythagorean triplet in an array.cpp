// FIND PYTHAGOREAN TRIPLET IN AN ARRAY.

// REQUIRED TC :: O(n*n)

#include <bits/stdc++.h>
using namespace std;


bool findPythaTriplet(int arr[],int n)
{
	sort(arr,arr+n);

	for(int i=n-1;i>=0;i--)
	{
		int j=0;
		int k=i-1;

		while(j<k)
		{
			int c=arr[i]*arr[i];
			int a=arr[j]*arr[j];
			int b=arr[k]*arr[k];

			if(((a)+(b))==(c))
				return true;

			if(((a)+(b))<(c))
				j++;
			else
				k--;
		}
	}

	return false;
}
int main()
{
	int arr[]={3, 1, 4, 6, 5};
	int n=sizeof(arr)/sizeof(arr[0]);

	if(findPythaTriplet(arr,n))
		cout<<"triplet is present\n";
	else
		cout<<"no triplet is present\n";
}
