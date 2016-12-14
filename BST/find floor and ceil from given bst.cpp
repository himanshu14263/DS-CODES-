// PROBLEM :: FIND FLOOR AND CEIL FROM A GIVEN BST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
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
void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

// simple inO and checking condition
void ceilBST(node*root,int&ans,int val)
{
	if(root==NULL)return;
	ceilBST(root->left,ans,val);
	if(ans==INT_MIN && root->data>=val)
		ans=root->data;
	ceilBST(root->right,ans,val);
}

// simple inO and checking condition
void floorBST(node*root,int&ans,int val)
{
	if(root==NULL)return;

	floorBST(root->left,ans,val);

	if(root->data<=val)
		ans=root->data;

	floorBST(root->right,ans,val);
}
int main()
{
	node*root=NULL;
	root=insert(root,10);
	insert(root,3);
	insert(root,6);
	insert(root,22);
	insert(root,14);

	inO(root);

	int ans=INT_MIN;
	int val;
	cout<<"\nenter a value whose ceil and floor u want to find \n";
	cin>>val;
	ceilBST(root,ans,val);

	if(ans==INT_MIN)
		cout<<"value isn't BST range \n";
	else
		cout<<"the ceil is :: "<<ans<<"\n";

	int ans2=INT_MAX;

	floorBST(root,ans2,val);

	if(ans2==INT_MAX)
			cout<<"value isn't BST range \n";
		else
			cout<<"the floor is :: "<<ans2<<"\n";
}
