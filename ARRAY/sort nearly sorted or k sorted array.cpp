// PROBLEM :: SORTED NEARLY SORTED OR K-SORTED ARRAY 
// TC :: O(n log k)   // where n is the total number of elements and they at most k distance away from their exact position.

#include <bits/stdc++.h>
using namespace std;

// method 1 :: using insertion sort (time complexity :: O(n*k))

void insertionSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=i;
		int temp=arr[i];
		while(j>0 && arr[j]<arr[j-1])
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
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
	int arr[]={5,4,3,2,1};

	display(arr,n);
	insertionSort(arr,n);
	display(arr,n);
}