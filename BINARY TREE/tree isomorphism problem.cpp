// note:not-self;
// PROBLEM: tree isomorphism problem.

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

// checking if tree are isomorphic or not.
bool isIsomorphic(node*root1,node*root2)
{
	if(root1==NULL && root2==NULL)return true;
	if((root1 && root2==NULL)||(root2 && root1==NULL))return false;
	if(root1->data!=root2->data)return false;

	// basically two cases are possible either the left and right sub tree are flipped or not.
	// if they are not flipped then check the equality of left and right subtree.
	// if they are flipped then check for opposite childs whether they are equal or not.
	return (((isIsomorphic(root1->left,root2->left))&&(isIsomorphic(root1->right,root2->right)))  ||
			((isIsomorphic(root1->left,root2->right))&&(isIsomorphic(root1->right,root2->left))));
}

int main()
{
	node*root1=newnode(1);
	root1->left=newnode(2);
	root1->right=newnode(3);
	root1->left->left=newnode(4);
	root1->left->right=newnode(5);

	node*root2=newnode(1);
	root2->left=newnode(3);
	root2->right=newnode(2);
	root2->right->right=newnode(4);
	root2->right->left=newnode(5);

	if(isIsomorphic(root1,root2))
		cout<<"they are isomorphic\n";
	else
		cout<<"they are not isomorphic\n";
}

