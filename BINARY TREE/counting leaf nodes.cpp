	// NOTE:SELF
	// COUNTING ALL THE LEAF NODES

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

// this function counts the number of leaf nodes

int countLeaf(node*root)
{
	if(root==NULL)return 0;
	else if(root->left==NULL && root->right==NULL)return 1;  // checking leaf node condition
	else
	{
		return (countLeaf(root->left)+countLeaf(root->right));
	}
}

int main()
{
	// creating the tree
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	//calling the function
	cout<<countLeaf(root);
}


