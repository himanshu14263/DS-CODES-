// PROBLEM :: SORTED ORDER PRINTING OF GIVEN ARRAY THAT STORES A FULL BST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
node* insert(node*root,int data)
{
	if(root==NULL)return newnode(data);
	if(root->data<data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
	return root;
}

// printing the array in sorted order(ascending).
void sortedPrint(int arr[],int strt,int end)
{
	if(strt>end)return;

	sortedPrint(arr,2*strt+1,end);
	cout<<arr[strt]<<" ";
	sortedPrint(arr,2*strt+2,end);
}
int main()
{
	int arr[]={4,2,5,1,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	sortedPrint(arr,0,n-1);
}
