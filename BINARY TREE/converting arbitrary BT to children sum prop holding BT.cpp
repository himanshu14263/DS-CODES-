// note:not self;
// converting arbitrary binary tree to tree that holds children sum property
#include <bits/stdc++.h>
using namespace std;
typedef struct node node;
struct node
{
	int data;
	node*left,*right;
};
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void inc(node*root,int diff)		// function increase the diff value in subtree node
									// first it checks whether nodes are present there or not.
									// if present then inc node's data value (left node is given priority first here(userdefined))
{
	if(root->left)
	{
		root->left->data=root->left->data+diff;
		inc(root->left,diff);
	}
	else if(root->right)
	{
		root->right->data=root->right->data+diff;
		inc(root->right,diff);
	}
}
void func(node*root)
{
	int leftdata=0,rightdata=0;
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;
	else
	{
		// first we reach last children of left sub tree.
		func(root->left);
		func(root->right);


		// we store these nodes values.
		if(root->left)leftdata=root->left->data;
		if(root->right)rightdata=root->right->data;

		// finding difference b/w root data and children's data
		int diff=(leftdata+rightdata)-root->data;

		// then we check if their value is greater or less than root node.
		if(diff>0)
			//	if root data is less then simply increment root data.
			root->data=root->data+diff;
		else
			//  if root data is greater then we have to increment the value of its children, so their sum could become equal to that of root data.
			inc(root,-diff);
	}
}

void postO(node*root)
{
	if(root==NULL)return;

	postO(root->left);

	cout<<root->data<<" ";
	postO(root->right);
}
int main()
{
	node*root=newnode(50);
	root->left=newnode(7);
	root->right=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(5);
	root->right->left=newnode(1);
	root->right->right=newnode(30);

	func(root);

	postO(root);




}
