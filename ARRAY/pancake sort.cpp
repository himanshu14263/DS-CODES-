// PROBLEM :: PANCAKE SORT PROBLEM.

// DESCRIPTION :: In normal sorting algorithms the goal is to achieve minimum comparison possible,
//				  while in this sorting algo. our goal is to achieve minimum reversal possible.

#include <bits/stdc++.h>
using namespace std;


void flip(int arr[],int n)
{
	int i=0,j=n;

	while(i<j)
	{
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
}
void pancakeSort(int arr[],int n)
{
	for(int i=n-1 ; i>1 ; i--)
	{
		int max=INT_MIN;
		int maxIndex=-1;
		for(int j=0;j<=i;j++)
		{
			if(arr[j]>max)
			{
				max=arr[j];
				maxIndex=j;
			}
		}

		flip(arr,maxIndex);
		flip(arr,i);
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
	int arr[]={23, 10, 20, 11, 12, 6, 7};
	int n=(sizeof(arr)/sizeof(arr[0]));

	display(arr,n);
	pancakeSort(arr,n);
	display(arr,n);
}
