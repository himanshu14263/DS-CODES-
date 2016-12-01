// PROBLEM : VERTEX COVER PROBELM OF BINARY TREE
// SELF
// TIME COMPLEXITY : O(n)
// TYPE : RECURSIVE SOLUTION
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

int vertexCover(node*root)
{
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return 0;

	// including root
	//
	int root_incl=0;
	root_incl+=1+vertexCover(root->left)+vertexCover(root->right);

	// excluding root
	int root_excl=0;
	if(root->left)
	root_excl+=1 + vertexCover(root->left->left)+vertexCover(root->left->right);
	if(root->right)
	root_excl+=1+vertexCover(root->right->left)+vertexCover(root->right->right);

	return min(root_incl,root_excl);
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->right=newnode(4);
	root->left->right->right=newnode(5);
	root->left->right->right->right=newnode(6);
	root->left->right->right->right->right=newnode(7);
	root->right=newnode(3);

	cout<<"the size of vertex cover is :: " <<vertexCover(root);
}
