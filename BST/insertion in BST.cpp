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

///////////////////////// MY WAY FOR INSERTION ////////////////////////
node* insert2(node*root,int x)
{
	if(root==NULL)
		return newnode(x);
	// going in left subtree
	if(root->data>x)
	{
		if(root->left==NULL)root->left=newnode(x);
		// traversing
		else
			insert2(root->left,x);
	}
	// going in right subtree
	if(root->data<x)
	{
		if(root->right==NULL)
			root->right=newnode(x);
		else //traversing
			insert2(root->right,x);
	}
}
/////////////////////////  OTHER'S CODE  /////////////////////////////

node* insert(node*root,int val)
{
	if(root==NULL)
		return newnode(val);
	if(root->data<val)
		root->right=insert(root->right,val);
	if(root->data>val)
		root->left=insert(root->left,val);

	return root;  // this return help to create the internal tree/subtree

}

node* search(node*root,int x)
{
	// if base tree is NULL or
	// function reached leaf node and required data isn't found
	if(root==NULL)
		return root;
	// found the required data and thus returning the data
	if(root->data==x)
		return root;
	// searching the right sub-tree
	if(root->data<x)
		return search(root->right,x);

	// searching the left sub-tree
	return search(root->left,x);
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

	    node*root2=NULL;
	    root2=insert(root2,0);
		insert(root2,2);
		insert(root2,3);
		insert(root2,4);
		insert(root2,6);

		inO(root2);
		cout<<"\n";

		node*root=NULL;
		root=insert(root,10);
		insert(root,12);
		insert(root,13);
		insert(root,14);
		insert(root,16);

		inO(root);
		cout<<"\n";


}
