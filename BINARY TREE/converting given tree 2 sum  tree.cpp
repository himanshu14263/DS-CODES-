// note:self;
// PROBLEM: converting a given tree to sum tree
// TIME COMPLEXITY : - O(n^2)

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

void f(node*root)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)return;
	else
	{
		f(root->left);
		f(root->right);
		root->data=sum(root->left)+sum(root->right);
	}
}

void inO(node*root)
{
	if(root==NULL)
		return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}
int main()
{
	node*root=newnode(10);
	root->left=newnode(-2);
	root->right=newnode(6);
	root->left->left=newnode(8);
	root->left->right=newnode(-4);
	root->right->right=newnode(5);
	root->right->left=newnode(7);

	f(root);
	inO(root);

}
