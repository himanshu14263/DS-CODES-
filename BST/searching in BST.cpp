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
int main()
{

	    node*root2=NULL;
	    root2=insert(root2,0);
		insert(root2,2);
		insert(root2,3);
		insert(root2,4);
		insert(root2,6);

		node*ans=search(root2,6);

		// TEST 1
		if(ans)
			cout<<ans->data<<"\n";
		else
			cout<<"node doen't exists\n";

		// TEST 2
		ans=search(root2,19);
		if(ans)
			cout<<ans->data<<"\n";
		else
			cout<<"node doen't exists\n";
}
