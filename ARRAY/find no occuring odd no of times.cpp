// PROBLEM :: finding the number occuring odd no. of times.
#include<bits/stdc++.h>
using namespace std;


// TC : O(n) USING XOR METHOD
// this method works only when there is only one odd element
void findOddNum(int a[],int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
		ans=ans^a[i];

	cout<<"the odd element is :: "<< ans;
}
int main()
{

	int arr[]={6,6,2,2,7,7,7};

	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<"\n";

	findOddNum(arr,n);

}

