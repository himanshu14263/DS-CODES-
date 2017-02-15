#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
void printDistinct(int arr[],int n)
{
	set<int>s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);	// insertion takes lograthmic time.

	set<int>::iterator it;
	for(it=s.begin();it!=s.end();++it)
		cout<<*it<<" ";
	cout<<"\n";
}
int main()
{
	int arr[]={1,1,1,1,2,4,5,6,6,2,78};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"the given array is :: \n";
	display(arr,n);
	cout<<"\ndistinct elements are :: \n";
	printDistinct(arr,n);
}
