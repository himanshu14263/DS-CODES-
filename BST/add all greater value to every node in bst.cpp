// PROBLEM :: ADD ALL GREATER VALUES TO EVERY NODES IN BST

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

// doing inO traversal from right side and maintaining the previous node's value
void addLarge(node*root,int &prev)
{
	if(root==NULL)return ;
	addLarge(root->right,prev);
	root->data+=prev;
		prev=root->data;
	addLarge(root->left,prev);
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
	root=insert(root,50);
	insert(root,30);
	insert(root,70);
	insert(root,20);
	insert(root,40);
	insert(root,60);
	insert(root,80);

	int prev=0;
	addLarge(root,prev);
	inO(root);

}
