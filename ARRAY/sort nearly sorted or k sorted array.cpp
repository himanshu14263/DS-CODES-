// PROBLEM :: SORTED NEARLY SORTED OR K-SORTED ARRAY
// TC :: O(n log k)   // where n is the total number of elements and they at most k distance away from their exact position.

#include <bits/stdc++.h>
using namespace std;

// method 1 :: using insertion sort (time complexity :: O(n*k))

void insertionSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=i;
		int temp=arr[i];
		while(j>0 && arr[j]<arr[j-1])
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
	}
}


void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int harr[1000];
int capacity=10;
int hsize=0;

int parent(int i)
{
	return (i-1)/2;
}

int lchild(int i)
{
	return 2*i+1;
}

int rchild(int i)
{
	return 2*i+2;
}


void heapify(int i)
{
		int l=lchild(i);
		int r=rchild(i);

		int min=i;
		if(l<hsize && harr[l]<harr[min])
			min=l;
		if(r<hsize && harr[r]<harr[min])
			min=r;

		if(min!=i)
		{
			swap(harr[min],harr[i]);
			heapify(min);
		}

}

void insert(int val)
{
	if(hsize>=capacity)
	{
		cout<<"reached capacity\n";
		return;
	}

	harr[hsize]=val;
	hsize++;

	int i=hsize-1;
	while(i>0 && harr[parent(i)]>harr[i])
	{
		swap(harr[parent(i)],harr[i]);
		i=parent(i);
	}
}


int extractMin()
{

	if(hsize==0)
		return INT_MAX;

	if(hsize==1)
	{
		hsize--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[hsize-1];
	hsize--;

	heapify(0);
	return root;
}


void kSort(int arr[],int n,int k)
{
	capacity=k+1;

	for(int i=0;i<=k;i++)
		insert(arr[i]);

	int ti=0;

	for(int i=k+1 ; i<n ; i++,ti++)
	{
		int x=extractMin();
		arr[ti]=x;
		insert(arr[i]);
	}

	while(hsize>0)
	{
		arr[ti]=extractMin();
		ti++;
	}


}
int main()
{
	int arr[]={2, 6, 3, 12, 56, 8};

	int n=(sizeof(arr)/sizeof(arr[0]));

	cout<<"enter the value of k\n";
	int k;
	cin>>k;

	cout<<"the input array is :: ";display(arr,n);
	kSort(arr,n,k);
	cout<<"the output array is :: ";display(arr,n);


}
