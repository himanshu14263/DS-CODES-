// PROBLEM :: REMOVE ALL KEYS OUTSIDE THE GIVEN RANGE

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

// NOTE :: HERE WE USED INSERT FUNCTION THAT RECEIVES REFERENCE OF ROOT NODE
// ADVANTAGE :: 1) THERE IS NO NEED OF RETURN STATEMENT
//				2) NO NEED TO MENTION root->left=  OR  root->right=   statements

void insert(node*&root,int data)
{
	if(root==NULL)root=newnode(data);
	if(root->data<data)insert(root->right,data);
	if(root->data>data)insert(root->left,data);
}

// FOR LOGIC :: REFER NOTEBOOK
node*removeFromRange(node*root,int min,int max)
{
	if(root==NULL)return NULL;
	root->left=removeFromRange(root->left,min,max);
	root->right=removeFromRange(root->right,min,max);

	if(root->data<min)
	{
		node*rchild=root->right;
		delete(root);
		return rchild;
	}
	if(root->data>max)
	{
		node*lchild=root->left;
		delete(root);
		return lchild;
	}
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
	insert(root,10);
	insert(root,7);
	insert(root,3);
	insert(root,12);
	insert(root,17);
	insert(root,1);
	inO(root);
	int min,max;
	cout<<"\nenter the range :: \n";
	cin>>min>>max;
	node*newroot=removeFromRange(root,min,max);
	inO(newroot);
}
