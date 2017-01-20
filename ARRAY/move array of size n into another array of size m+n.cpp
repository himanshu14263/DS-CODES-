// PROBLEM : MOVE AN ARRAY OF SIZE N INTO ANOTHER ARRAY OF SIZE M+N (GIVEN BOTH THE ARRAYS ARE SORTED)

#include <bits/stdc++.h>
using namespace std;

void moveToEnd(int arr[],int n)
{
	int j=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]!=-1)
		{
			arr[j]=arr[i];
			j--;
		}
	}
}
int main()
{
	int arr[]={2,-1,7,-1,-1,10,-1};
	int size=(sizeof(arr)/sizeof(arr[0]));

	int b[]={5,8,12,14};
	int n=(sizeof(b)/sizeof(b[0]));

	moveToEnd(arr,size);

	int i=0,k=0,j=n;
	while(i<n && j<size)
	{
		if(b[i]<arr[j])
		{
			arr[k]=b[i];
			i++;k++;
		}
		else
		{
			arr[k]=arr[j];
			j++;k++;
		}
	}

	if(i==n)
	{
		while(j<size)
		{
			arr[k]=arr[j];
			j++;k++;
		}
	}
	else if(j==size)
	{
		while(i<n)
		{
			arr[k]=b[i];
			i++;k++;
		}
	}

	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
