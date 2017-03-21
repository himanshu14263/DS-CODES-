// PROBLEM :: FIND THE FREQUENCY OF ALL ELEMENTS IN THE ARRAY GIVEN THAT ELEMENTS WILL RANGE FORM 1 TO N.
// REQUIREMENT :: TIME COMPLEXITY :: O(N)
// 				  SPACE COMPLEXITY :: O(1)

#include <bits/stdc++.h>
using namespace std;

void findFrequency(int arr[],int n)
{
	for(int i=0;i<n;i++)
		arr[i]=arr[i]-1;

	for(int i=0;i<n;i++)
		arr[arr[i]%n]=arr[arr[i]%n]+n;

	cout<<"element       frequency \n";
	for(int i=0;i<n;i++)
		cout<<" "<<(i+1)<<"	 -->	 "<<arr[i]/n<<"\n";
}

int main()
{
	int arr[]={2,3,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	findFrequency(arr,n);
}
