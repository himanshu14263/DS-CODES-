// PROBLEM :: PRINTING THE Kth LARGEST ELEMENT
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

// doing reverse inO and increasing a variable till it become equal to k
node*insert(node*root,int data)
{
	if(root==NULL)return newnode(data);
	if(root->data<data)root->right=insert(root->right,data);
	if(root->data>data)root->left=insert(root->left,data);
	return root;
}
void KthLargest(node*root,int k)
{
	static int i=1;
	if(root==NULL)return;
	KthLargest(root->right,k);
	if(i==k)
		cout<<root->data<<" ";
	i++;
	KthLargest(root->left,k);
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
	insert(root,6);
	insert(root,49);
	insert(root,24);

	inO(root);
	cout<<"\n";
	KthLargest(root,3);


}
