// CHECK IF ARRAY IS SUBSET OF ANOTHER ARRAY OR NOT
// REQD TC :: less than O(n^2)

#include <bits/stdc++.h>
using namespace std;

// merging subarrays
void mA(int temp[], int arr[],int l,int md,int h)
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

// splitting arrays
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

// utility function for merge sort.
void ms(int arr[],int n)
{
	int temp[n];
	_ms(temp,arr,0,n-1);
}


// checking if the second array is the subset of given main array or not.
bool isSubArray(int arr1[],int arr2[],int m,int n)
{
	// sorting both the arrays
	ms(arr1,m);
	ms(arr2,n);


	int i=0,j=0;


	// checking if second array is present in first array or not
	while(i<m && j<n)
	{
		if(arr1[i]<arr2[j])
			i++;
		else if(arr1[i]==arr2[j])
		{
			i++;j++;
		}
		else if(arr1[i]>arr2[j])
			return 0;
	}


	if(j<n)
		return 0;
	else
		return 1;
}
int main()
{
	int arr1[]={11, 1, 13, 21, 3, 7};
	int m=(sizeof(arr1)/sizeof(arr1[0]));

	int arr2[]={11, 88, 7, 1};
	int n=(sizeof(arr2)/sizeof(arr2[0]));

	if(isSubArray(arr1,arr2,m,n))
		cout<<"ARRAY2 isn't present as sub-array\n";
	else
		cout<<"ARRAY2 isn't present as sub-array\n";
}
