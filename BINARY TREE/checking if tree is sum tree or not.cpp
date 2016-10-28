// note:self;
// PROBLEM: checking if tree is sum tree or not.
// TIME COMPLEXITY : - O(n)

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
int sum(node*root)
{
	if(root==NULL)return 0;
	else
	{
		return(root->data+sum(root->left)+sum(root->right));
	}
}


bool func(node*root)
{

	if(root==NULL)return true;
	if(root->left==NULL && root->right==NULL)return true;
	else
	{
		return((root->data==sum(root->left)+sum(root->right))&&(func(root->left))&&(func(root->right)));
	}
}
int main()
{
	node*root=newnode(26);
	root->left=newnode(10);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(6);
	root->right->right=newnode(3);
	//root->right->left=newnode(3);
	if(func(root))
		cout<<"sumtree\n";
	else
		cout<<"not sumtree\n";
}
