//PROBLEM :: FIND THE INORDER SUCCESSOR OF GIVEN NODE

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left=NULL;
	node*right=NULL;
};
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
node*insert(node*root,int data)
{
	if(root==NULL)return newnode(data);
	if(root->data<data)root->right=insert(root->right,data);
	if(root->data>data)root->left=insert(root->left,data);
	return root;
}

node*findVal(node*root,int val,node*& succ)
{
	if(root==NULL)return NULL;
	if(root->data==val)return root;
	if(root->data<val)return findVal(root->right,val,succ);
	else
	{
		succ=root;
		return findVal(root->left,val,succ);
	}
}
node*findSucc(node*root,int val)
{
	node*succ=NULL;

	// FOR THE CASE IN WHICH THE REQUIRED NODE DOESN'T HAVE A RIGHT SUBTREE.
	node*curr=findVal(root,val,succ);

	// IF THE REQUIRED NODE HAVE THE RIGHT SUBTREE.
	if(curr->right!=NULL)
	{
		node*temp=curr->right;
		while(temp->left!=NULL)
			temp=curr->left;
		succ=temp;
	}

	return succ;
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
	insert(root,5);insert(root,11);insert(root,3);insert(root,12);

	inO(root);
	cout<<"\n";


	int val;
	cout<<"enter the node whose inorder successor u want to find\n";
	cin>>val;
	cout<<findSucc(root,val)->data;




}
