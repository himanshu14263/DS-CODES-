//PROBLEM :: CONVERSION OF SORTED ARRAY TO BINARY SEARCH TREE (BST)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left=NULL;
	node*right=NULL;
};
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

// LOGIC :: find the mid point of the array
// 			make it as the root
//			make the left subtree as left child and right subtree as the right child
// 			then simply recurse.
node* arrToBst(int arr[],int strt,int end)
{
	if(strt>end)
		return NULL;
	int md=(strt+end)/2;		// important to find the correct mid point.
	node*n=newnode(arr[md]);
	n->left=arrToBst(arr,strt,md-1);
	n->right=arrToBst(arr,md+1,end);
	return n;
}

void preO(node*root)
{
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preO(root->left);
	preO(root->right);
}
int main()
{
	int arr[]={1,2,3,4,5};
	node*root=arrToBst(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	preO(root);
}
