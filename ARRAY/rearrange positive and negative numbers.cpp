// PROBLEM :: REARRANGE POSITIVE AND NEGATIVE NUMBER IN

// CONSTRAINT :: using linear time and constant extra space.


#include <bits/stdc++.h>
using namespace std;


void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
    int arr[] = {1,-2,-3,4,-5,6,-7};
    int n = sizeof(arr)/sizeof(arr[0]);


    display(arr,n);


    int j=0;
    for(int i=0;i<n;i++)
    {
    	if(arr[i]<0)
    	{
    		swap(arr[i],arr[j]);
    		j++;
    	}
    }

    int i=0;

    while(j<n && i<j && arr[i]<0)
    {
    	swap(arr[i],arr[j]);
    	i+=2;
    	j++;
    }

    cout<<"\nthe rearranged array is :: \n\n";
    display(arr,n);


}
