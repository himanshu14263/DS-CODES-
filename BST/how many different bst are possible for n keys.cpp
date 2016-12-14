// PROBLEM :: FIND DIFFERENT NUMBER OF BST POSSIBLE  WITH N KEYS/NODES

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};


// nCr	= 	[n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
int binoCoeff(int n,int r)
{
	if(n-r<r)
		r=n-r;

	int res=1;
	for(int i=0;i<r;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

// WE USED THE CONCEPT OF CATALAN NUMBER
// CATALAN NUMBER	=	2nCn / (n+1)

int diffTrees(int n)
{
	return (binoCoeff(2*n,n))/(n+1);
}
int main()
{
	int n;
	cout<<"enter the number of different nodes\n";
	cin>>n;
	cout<<"total number of different bst are :: " << diffTrees(n);
}
