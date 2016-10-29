// note:self;
// PROBLEM: boundary traversal of tree
// TIME COMPLEXITY : - O(N)

#include <bits/stdc++.h>
using namespace std;
typedef struct node node;

struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void leftBoundaryNodes(node*root)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)return;
	cout<<root->data<<" ";
	leftBoundaryNodes(root->left);
}
void rightBoundaryNodes(node*root)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)return;
	rightBoundaryNodes(root->right);
	cout<<root->data<<" ";
}
void printingLeafNodes(node*root)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)cout<<root->data<<" ";
	printingLeafNodes(root->left);
	printingLeafNodes(root->right);
}

// first print all the left boundary nodes except leaf node in top to bottom manner.
// second print all the leaves nodes in tree from left to right
// third print all the right boundary nodes except the leaf node in bottom to up manner.
void boundaryTraversal(node*root)
{
	leftBoundaryNodes(root);
	printingLeafNodes(root);
	rightBoundaryNodes(root->right);
}
int main()
{
	node*root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(4);
	root->left->right=newnode(12);
	//root->right->left=newnode(6);
	root->right->right=newnode(25);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);


	cout<<"boundary traversal of given binary tree : ";
	boundaryTraversal(root);

}
