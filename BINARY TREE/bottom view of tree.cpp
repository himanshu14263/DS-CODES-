// PROBLEM: GIVEN A TREE PRINT ITS BOTTOM VIEW
// SELF
// NOTE : NOT SURE WHETHER CORRECT OR NOT B/C JUST REVERSED WHAT WE HAVE DONE FOR TOP VIEW
// TIME COMPLEXITY :  O(N^2)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

int arr[500];	// flag array

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// finds height to use in lot
int ht(node*root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}

// print the nodes of particular level and the BOTTOM most node at horizontal distance x
void func(node*root,int h,int x)
{
	if(root==NULL)return;
	if(h==1 && !arr[x])	// CHECKS WHETHER BOTTOM-MOST HORIZONTAL DISTANCE ELEMENT HAVE ALREADY BEEN PRINTED OR NOT.
		{
			cout<<root->data<<" ";
			arr[x]=1;
		}

	func(root->right,h-1,x+1);

	func(root->left,h-1,x-1);
}

// initiator function of lot and prints every level,one by one
void lot(node*root)
{
	memset(arr,0,sizeof(arr));
	int x=50;		// it can be any number for index of the array
	int h=ht(root);
	// PRINTING THE BOTTOM-MOST ELEMENT OF AT DIFFERENT HORIZONTAL DISTANCE.
	// JUST REVERSED THE ACCESSING THE LEVEL FROM (TOP TO BOTTOM) TO (BOTTOM TO TOP) MANNER
	for(int i=h;i>=1;i--)
		{
			func(root,i,x);
		}
}
int main()
{
	node*root=newnode(20);
	root->left=newnode(8);
	root->left->left=newnode(5);
	root->left->right=newnode(3);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	root->right=newnode(22);
	root->right->right=newnode(25);
	root->right->left=newnode(4);

	lot(root);
}
