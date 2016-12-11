//PROBLEM :: FIND THE K th SMALLEST ELEMENT IN THE BINARY TREE.

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
void kSmallest(node*root,int&k)
{
	if(root==NULL)return;
	kSmallest(root->left,k);
	k--;
	if(k==0)
		cout<<root->data;
	kSmallest(root->right,k);
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
	cout<<"\nenter the value of k\n";
	int k;
	cin>>k;
	kSmallest(root,k);
}
