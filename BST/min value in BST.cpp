#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
};
node*newnode(int val)
{
	node*n=new node;
	n->left=n->right=NULL;
	n->data=val;
	return n;
}
node* insert(node*root,int val)
{
	if(root==NULL)return newnode(val);
	if(root->data<val)
		root->right=insert(root->right,val);
	if(root->data>val)
		root->left=insert(root->left,val);
	return root;
}

node*minVal(node*root)
{
	node*curr=root;
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}

void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}
int main()
{

	node*root=NULL;
	root=insert(root,10);
	insert(root,14);
	insert(root,5);
	insert(root,3);

	cout<<"the sorted elements are :: ";
	inO(root);cout<<"\n";

	cout<<"the minimum value is :: ";
	cout<<minVal(root)->data;

}
