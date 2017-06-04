// PROBLEM ::  FINDING THE MINIMUM ELEMENT IN THE GIVEN RANGE

#include<bits/stdc++.h>
using namespace std;

void createSegTreeUtil(int input[],int segTree[],int low ,int high,int pos)
{
	if(low==high)
	{
		segTree[pos]=input[low];
		return;
	}

	int mid = (low+high)/2;

	createSegTreeUtil(input,segTree,low,mid,2*pos+1);
	createSegTreeUtil(input,segTree,mid+1,high,2*pos+2);

	segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
}

void createSegTree(int arr[],int segTree[],int len)
{
	createSegTreeUtil(arr,segTree,0,len-1,0);
}

int queryUtil(int segTree[],int qlow,int qhigh,int low, int high,int pos)
{
	// complete overlap
	if(qlow<=low && qhigh>=high)
		return segTree[pos];

	// no overlap
	if(qlow >high || qhigh<low )
		return INT_MAX;

	// partial overlap
	int mid = (low+high)/2;

	return min(queryUtil(segTree,qlow,qhigh,low,mid,2*pos+1),queryUtil(segTree,qlow,qhigh,mid+1,high,2*pos+2));

}

int query(int segTree[],int qlow ,int qhigh,int len)
{
	return queryUtil(segTree,qlow,qhigh,0,len-1,0);
}

void updateTreeUtil(int segTree[],int qlow,int qhigh,int low,int high,int delta,int pos)
{

			if(qhigh<low || qlow>high)
				return;

			if(low==high)
			{
				segTree[pos]+=delta;
				return;
			}

			int mid = (low+high)/2;

			updateTreeUtil(segTree,qlow,qhigh,low,mid,delta,2*pos+1);
			updateTreeUtil(segTree,qlow,qhigh,mid+1,high,delta,2*pos+2);

			segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
}
void updateTree(int segTree[],int qlow,int qhigh,int low,int high,int delta)
{
	updateTreeUtil(segTree,qlow,qhigh,low,high-1,delta,0);
}
int main()
{
	int arr[]={-1,3,4,0,2,1};

	int n = sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++)
		cout<<i<<" ";

	cout<<"\n";

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";


	int h = (int)(ceil(log2(n)));
	int max_size = 2*(pow(2,h))-1;

	int *segTree= new int [max_size];

	createSegTree(arr,segTree,n);

	cout<<"enter the range\n";
	int a,b;
	cin>>a>>b;
	cout<<query(segTree,a,b,n);

	cout<<"\n";
	for(int i=0;i<max_size;i++)
		cout<<segTree[i]<<" ";
	cout<<"\n";

	cout<<"enter the range to update\n";
	cin>>a>>b;
	cout<<"enter incrementation value\n";
	int x;
	cin>>x;

	updateTree(segTree,a,b,0,n,x);

	cout<<"enter the range\n";
		cin>>a>>b;
		cout<<query(segTree,a,b,n);

		cout<<"\n";
			for(int i=0;i<max_size;i++)
				cout<<segTree[i]<<" ";
			cout<<"\n";



}
