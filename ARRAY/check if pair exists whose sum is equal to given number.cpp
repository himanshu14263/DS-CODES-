// PROBLEM :: GIVEN AN ARRAY AND A NUMBER 'X', CHECK IF A PAIR EXISTS WHOSE SUM IS EQUAL TO X.



#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*arbit;
};


// METHOD 1 :: USING HASH MAP
// here time complexity depends upon the sorting algo.
bool findPair(int a[],int n, int num)
{
	sort(a,a+n);		// if used merge sort then time complexity is :: O(n log n)

	int front, end;
	front=0;end=n-1;

	while(front<end)
	{
		int sum=a[front]+a[end];
		if(sum==num)
		{
			cout<<a[front]<<" "<<a[end];
			return true;
		}
		else if(sum<num)
			front++;
		else
			end--;
	}
	return false;
}

// METHOD 2 :: WITH USING HASH MAP

void ifPairExists(int a[],int n,int sum)
{
	bool map[100000]={0};
	for(int i=0;i<n;i++)
	{
		int temp=sum-a[i];
		if( temp>=0 && map[temp])
		{
			cout<<"the pairs exists and values are :: \n";
			cout<<a[i]<<" "<<temp;
		}
		else
			map[a[i]]=1;

	}
}
int main()
{

	int arr[]={1,5,7,9,6,5,4,2};

	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<"\n";

	int num;
	cout<<"enter the number\n";
	cin>>num;

	cout<<"\n";

//	ifPairExists(arr,n,num);			// METHOD 1 

	ifPairExists(arr,n,num);			// METHOD 2
}

