// PROBLEM :: CHECK IF GIVEN TREE IS BST OR NOT

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


// NOTE :: THIS SOLUTION IS BASED ON THE ASSUMPTION THAT GIVEN DATA IS PRESENT IN THE TREE

// logic :: if current node's data is greater than both the nodes then lca is present in right subtree
//          if current node's data is less than both the nodes then lca is present in left subtree
node*findlca(node*root,int n1,int n2)
{
	if(root==NULL)return NULL;

	// if both data are greater than current node than check for lca in right subtree
	if(n1>root->data && n2 > root->data)
		return findlca(root->right,n1,n2);
	// if both data are less than current node than check for lca in left subtree
	if(n1<root->data && n2 < root->data)
		return findlca(root->left,n1,n2);

	// if one data is greater than current node's data and other is less, then current node is the lca
	return root;
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
	insert(root,4);
	insert(root,2);
	insert(root,9);
	insert(root,1);
	insert(root,8);


	inO(root);
	cout<<"\nenter the number whose lca u want to find\n";
	int n1,n2;
	cin>>n1>>n2;

	node*lca=findlca(root,n1,n2);
	cout<<"the lca is :: "<< lca->data<<"\n";
}
