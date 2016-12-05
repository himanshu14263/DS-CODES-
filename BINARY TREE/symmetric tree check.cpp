// PROBLEM : SYMMETRIC TREE CHECK
#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node*left;
	node*right;
};
node* newnode(char data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void func(node*l,node*r,bool&ans)
{
	if(!l && !r)return;				//  to handle leaf nodes

	// if one is leaf and other isn't then return false;
	if(!l && r)
	{
		ans=0;return;
	}
	if(l && !r)
	{
		ans=0;return;
	}


	// for tree to be symmetric following three condition must be satisfied :-

	// 1)if data of both nodes isn't equal then return false
	if(l->data != r->data)
	{
		ans=0;return;
	}
	// 2) left subtree of left tree must be equal to the right subtree of right tree.
	// 3) right subtree of left tree must be equla  to the left subtree of right tree.

	func(l->right,r->left,ans);
	func(l->left,r->right,ans);
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(4);
	root->right->left=newnode(4);
	root->right->right=newnode(3);
	root->left->left->left=newnode(6);
	root->left->left->right=newnode(7);
	root->left->right->left=newnode(8);
	root->left->right->right=newnode(9);
	root->right->left->left=newnode(9);
	root->right->left->right=newnode(8);
	root->right->right->left=newnode(7);
	root->right->right->right=newnode(6);

	bool ans=1;
	func(root->left,root->right,ans);

	if(ans)cout<<"symmetric tree\n";
	else cout<<"not symmetric tree\n";
}
