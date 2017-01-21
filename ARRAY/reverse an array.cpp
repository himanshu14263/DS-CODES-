// PROBLEM : REVERSE AN ARRAY

#include <bits/stdc++.h>
using namespace std;

void swap(int& a,int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}


// ITERATIVE METHOD
void reverse(int arr[],int n)
{
	int l=0,h=n-1;

	while(l<h)
	{
		swap(arr[l],arr[h]);
		l++;h--;
	}
}

// RECURSIVE METHOD
void reverseRecur(int arr[],int strt,int end)
{
	int temp;
	if(strt>=end)return;

	temp=arr[strt];
	arr[strt]=arr[end];
	arr[end]=temp;

	reverseRecur(arr,strt+1,end-1);
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int main()
{
	int arr[]={1,2,3,4};

	int size=(sizeof(arr)/sizeof(arr[0]));

	display(arr,size);

	reverseRecur(arr,0,size-1);

	display(arr,size);

}
