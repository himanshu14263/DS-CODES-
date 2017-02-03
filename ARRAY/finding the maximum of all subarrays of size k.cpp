// PROBLEM :: FINDING THE MAXIMUM OF ALL SUBARRAYS OF SIZE K
// REQD TC :: O(n log n)

#include <bits/stdc++.h>
using namespace std;


// METHOD 1 :: using self balancing BST

void maxOfSubArr(int arr[],int n,int k)
{
	set<int>s;

		for(int i=0;i<k;i++)
			s.insert(arr[i]);


		s.size();

		for(int i=0;i<=n-k;i++)
		{
			cout<<(*(s.rbegin()))<<" ";

			s.erase(arr[i]);

			s.insert(arr[i+k]);
		}
}
int main()
{
	int arr[]={1,2,3,1,4,5,2,3,6};
	int n=sizeof(arr)/sizeof(arr[0]);

	int k;
	cout<<"enter  k";
	cin>>k;

	maxOfSubArr(arr,n,k);



}
