// PROBLEM :: CHECK FOR MAJORITY ELEMENT IN SORTED ARRAY when the element to search is given

// REQUIRED TC :: O(log n)

#include <iostream>
#include <vector>
using namespace std;


int binarySearch(int arr[],int l,int h,int x)
{
		if(l<=h)		// equal to sign is must so that even the singleton elements can be checked
		{
			int md=(l+h)/2;
			if((md==0)||((arr[md]>arr[md-1]) && (arr[md]==x)))return md;	// important condition to check if the found element is the first occurance or not
			if(arr[md]>=x)return binarySearch(arr,l,md-1,x);
			else
				return binarySearch(arr,md+1,h,x);
		}
		return -1;
}

void isMajority(int arr[],int n,int x)
{
	int k=binarySearch(arr,0,n-1,x);
	cout<<"k :: "<<k<<"\n";
	if(k==-1)
		cout<<"element isn't in the array\n";
	else
	{
		// checking if current element is the majority element or not
		if((k+(n/2)<=(n-1)) && (arr[k+(n/2)]==x))			// checking if the found element is within the bounds of array and 
															// and the n/2 th element is also the current element	
			cout<<"given element is the majority element\n";
		else
			cout<<"no it isn't \n";
	}
}
int main()
{
	int arr[]={1,1,1,3,3,3,4,5,5,5,5,5,5,5,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	int x;
	cin>>x;
	isMajority(arr,n,x);
}

