// PROBLEM : VERTEX COVER PROBELM OF BINARY TREE
// SELF
// TIME COMPLEXITY : O(n)
// TYPE : DYNAMIC SOLUTION
#include<bits/stdc++.h>
using namespace std;
// adding variable vc to check if the node is already calculated or not.
struct node
{
	int data,vc;
	node*left;
	node*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	n->vc=0;
	return n;
}

int vertexCover(node*root)
{
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return 0;


	// if node is already calculated
	if(root->vc!=0)
		return root->vc;

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

	// storing the calculated vertex cover value for node.
	root->vc=min(root_incl,root_excl);

	return root->vc;
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
