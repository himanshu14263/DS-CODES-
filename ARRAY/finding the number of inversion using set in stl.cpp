// PROBLEM :: FINDING THE INVERSION COUNT IN ARRAY.

// TIME COMPLEXITY :: O(N*N)

#include<bits/stdc++.h>
using namespace std;


// calculation are based on the fact that :
// how many elements are greater on the left side of current element


int invCnt(int arr[], int n)
{
	int inv_cnt=0;

	set<int>s;

	s.insert(arr[0]);

	for(int i=1;i<n;i++)
	{
		s.insert(arr[i]);

		set<int>::iterator it=upper_bound(s.begin(),s.end(),arr[i]);

		inv_cnt+=(distance(it,s.end()));

	}
	return inv_cnt;
}
int main()
{

	int arr[]={4,3,2,1};

	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<"THE NUMBER OF INVERSION ARE :: "<<invCnt(arr,n);

}
