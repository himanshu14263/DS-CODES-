// note:self;
// PROBLEM: checking if tree is height balanced or not.
// TIME COMPLEXITY : O(n^2)

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

int height(node*root)		// function to find the height of the BT
{
	if(root==NULL)return 0;
	return (1+max((height(root->left)),(height(root->right))));
}

// ALGO: 1) Left subtree must be balanced 
//		 2) Right subtree must be balanced 
//		 3) difference in the height of right subtree must not be greater than 1


bool balanceCheck(node*root)		// this recursive function checks the difference in ht of left and right sub-tree
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return true;

	int hl=height(root->left);
	int hr=height(root->right);
	return ((hl-hr<=1) && (balanceCheck(root->left) && (balanceCheck(root->right))));
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->left->right->left=newnode(6);
	root->left->right->left->right=newnode(7);

	root->right=newnode(3);
	root->right->right=newnode(8);
	root->right->right->left=newnode(9);


	if(balanceCheck(root))
		cout<<"balance tree\n";
	else cout<<"unbalanced tree\n";






}
