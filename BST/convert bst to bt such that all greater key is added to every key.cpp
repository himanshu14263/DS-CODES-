// PROBLEM :: CONVERT BST TO BT SUCH THAT SUM OF ALL GREATER KEY IS ADDED TO EVERY KEY

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

// doing reverse inO traversal and storing the result of previous node in val
// and adding this result(val) to next coming node.
void addGreater(node*root)
{

	static int val=0;
	if(root==NULL)return;
	addGreater(root->right);
	root->data+=val;
	val=root->data;
	addGreater(root->left);

}
int main()
{
	node*root=NULL;
	root=insert(root,5);
	insert(root,2);
	insert(root,13);


	addGreater(root);
	inO(root);

}
