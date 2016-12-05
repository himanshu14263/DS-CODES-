// PROBLEM : REMOVE ALL THE HALF NODE FROM THE B.T.
// TIME-COMPLEXITY REQD: O(N)
// NOTE : same logic used as removal of all nodes in the path having root to leaf path length less than k

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
// this can even change the root node
node* removeHalfNode(node*root)
{
	if(root==NULL)return NULL;

	root->left=removeHalfNode(root->left);
	root->right=removeHalfNode(root->right);

	// if root don't have any child then simply return the root
	if(!root->left && !root->right)
		return root;

	// if left child doesn't exist then create a new node having data of right child
	// and then delete the current node and return the new node.
	if(!root->left)
	{
		node*n=root->right;
		delete(root->left);
		return n;
	}

	// if right child doesn't exist then create new node having the data of left child
	// and then delete the current node and return this new node.
	if(!root->right)
	{
		node*n=root->left;
		delete(root->right);
		return n;
	}

	// and if it has both the child then leave it as it is and return current node.
	return root;
}

void inO(node* root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}
int main()
{
	 	node*root=newnode(1);
	 	root->left=newnode(2);
	 	root->right=newnode(3);
	 	root->left->left=newnode(4);
	 	root->left->right=newnode(5);
	 	root->right->right=newnode(6);
	 	root->left->left->left=newnode(7);
	 	root->right->right->left=newnode(8);

	 	cout<<"printing the tree before deletion\n";
	   inO(root);
	   cout<<"\n";

	   removeHalfNode(root);

	   cout<<"printing the tree after the deletion\n";
	   inO(root);


}
