// PROBLEM :: MERGE K SORTED ARRAY USING HEAP

// REQUIRED T.C. :: n * k(log k)

#include <bits/stdc++.h>
using namespace std;


struct heapElement
{
	int value;
	int indx;
	int j;
};
const int n=4;
int hsize=0;
int capacity;
heapElement*harr;

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

void insert(int value,int indx,int j)
{
	if(hsize==capacity)
	{
		cout<<"overflow\n";
		return;
	}

	harr[hsize].value=value;
	harr[hsize].indx=indx;
	harr[hsize].j=j;
	hsize++;

	int i=hsize-1;

	while( i>=0 && harr[i].value<harr[parent(i)].value)
	{
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}

void heapify(int i)
{
	int l=lchild(i);
	int r=rchild(i);

	int min=i;

	if(l<hsize && harr[i].value>harr[l].value)
		min=l;
	if(r<hsize && harr[r].value<harr[min].value)
		min=r;

	if(min!=i)
	{
		swap(harr[i],harr[min]);
		heapify(min);
	}
}
heapElement extractMin()
{
	if(hsize<1)
	{
		cout<<"heap empty";

		heapElement x;
		x.value=INT_MAX;

		return x;
	}
	if(hsize==1)
	{
		hsize--;
		return harr[0];
	}
	heapElement root=harr[0];
	harr[0]=harr[hsize-1];
	hsize--;

	heapify(0);

	return root;
}

void mergeKsorted(int arr[][n],int n,int k)
{

	int*out=new int[n*k];

	for(int i=0;i<k;i++)
	{
		insert(arr[i][0],i,0);
	}

	for(int i=0;i<n*k;i++)
	{
		heapElement x = extractMin();
		out[i]=x.value;

		if(x.j == n-1)
		{
			insert(INT_MAX,n,k);
		}
		else
		{
			insert(arr[x.indx][x.j+1],x.indx,x.j+1);
		}
	}

	for(int i=0;i<k*n;i++)
		cout<<out[i]<<" ";
	cout<<"\n";

}
int main()
{

	int k=3;
	int arr[][n] =  {{2, 6, 12, 34},
	                     {1, 9, 20, 1000},
	                     {23, 34, 90, 2000}};

	capacity=k;
	harr=new heapElement[capacity];

	mergeKsorted(arr,n,k);


}
