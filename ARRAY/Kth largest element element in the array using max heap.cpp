// PROBLEM :: FINDING THE Kth LARGEST ELEMENT IN AN ARRAY USING MAX HEAP

#include <bits/stdc++.h>
using namespace std;

const int capacity=20;
int harr[capacity];
int size=0;

int parent(int i)
{
	return (i-1)/2;
}

int leftchild(int i)
{
	return (2*i)+1;
}
int rightchild(int i)
{
	return (2*i)+2;
}

// making max heap
void  insert(int val)
{
	if(size>=capacity)
	{
		cout<<"array is full\n";
		return;
	}

	harr[size]=val;
	size++;

	int i=size-1;

	while((i!=0) && (harr[i]>harr[parent(i)]))
	{
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}

// heapify
void heapify(int i)
{
	int lchild=(2*i)+1;
	int rchild=(2*i)+2;

	int max=i;
	if(lchild<size && harr[lchild]>harr[i])
		max=lchild;
	if(rchild<size && harr[rchild]>harr[max])
		max=rchild;

	if((max<size) && (max!=i))
	{
		swap(harr[max],harr[i]);
		heapify(max);
	}
}

// extract max
int extractMax()
{
	if(size<1)
		return -1;

	if(size==1)
	{
		size--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[size-1];
	size--;

	heapify(0);

	return root;
}
int main()
{
	int arr[]={2,1,5,67,7,8,9,55};
	int n=sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		insert(arr[i]);

	cout<<"enter the value of K\n";
	int k;
	cin>>k;


	cout<<"the max k elements are :: ";
	while(k--)
	{
		cout<<extractMax()<<" ";
	}
}
