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
	if((root->data-4<val) && (root->data+4 >val))
		return root;
	if(root->data<val)
		root->right=insert(root->right,val);
	if(root->data>val)
		root->left=insert(root->left,val);
	return root;
}

void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

node*inOsuccessor(node*root)
{
	node*current=root;
	while(current->left!=NULL)
		current=current->left;
	return current;
}
node* deleteNode(node*root,int data)
{
	// tree doesn't exists
	if(root==NULL)return root;

	// searching left subtree
	if(root->data<data)
		root->right=deleteNode(root->right,data);

	// searching right subtree
	if(root->data>data)
		root->left=deleteNode(root->left,data);

	//value found
	else
	{
		// one child or no child
		if(root->left==NULL)
		{
			node*temp=root->right;
			free(root);
			return temp;
		}
		// one left child
		if(root->right==NULL)
		{
			node*temp=root->left;
			free(root);
			return temp;
		}

		// having both child
		node*temp=inOsuccessor(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}

	return root;

}
int main()
{

	node*root=NULL;
	root=insert(root,10);
	insert(root,14);
	insert(root,5);
	insert(root,3);

	inO(root);

	deleteNode(root,10);

	cout<<"\n";
	inO(root);

}
