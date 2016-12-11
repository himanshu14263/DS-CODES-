//PROBLEM :: PRINT THE BST KEYS IN THE GIVEN RANGE

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
// used inO traversal and applied the condition to belong in the range
void inoRange(node*root,int k1,int k2)
{
	if(root==NULL)return;
	inoRange(root->left,k1,k2);
	if(root->data>=k1 && root->data<=k2)
		cout<<root->data<<" ";
	inoRange(root->right,k1,k2);
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
	cout<<"\nenter the value of k1 and k2"<<"\n";
	int k1,k2;
	cin>>k1>>k2;
	inoRange(root,k1,k2);

}
