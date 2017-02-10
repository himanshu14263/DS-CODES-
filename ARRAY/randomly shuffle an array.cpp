// PROBLEM :: TO RANDOMLY SHUFFLES AN ARRAY

// REQUIRED TIME COMPLEXIY :: O(n)


#include <bits/stdc++.h>
using namespace std;

void  shuffle(int arr[],int n)
{
	srand(time(NULL));

	for(int i=n-1; i>=0;i--)
	{
		int j=(rand()%(i+1));

		swap(arr[j],arr[i]);
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
	int arr[]={1,2,3,4,5};
	int n=(sizeof(arr)/sizeof(arr[0]));

	display(arr,n);
	shuffle(arr,n);
	display(arr,n);


}
