// note:not self;
// program to check if tree holds the children sum property i.e. the sum of children must be equal to parent and must hold true for every node.

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
bool childSumProp(node*root)
{
	int leftdata=0,rightdata=0;   // initially assigning them values 0
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return true;
	else
	{
		if(root->left)leftdata=root->left->data;  	// changing value only if left child exists.
		if(root->right)rightdata=root->right->data;		// changing value only if right child exists.

		// a simple preorder traversal approach to first check property of root node and then its left and right child's property.
		if((leftdata+rightdata==root->data)&& (childSumProp(root->left))&&(childSumProp(root->right)))
		return true;
		else return false;
	}
}
int main()
{
	node*root=newnode(8);
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(1);
	root->left->right=newnode(1);
	root->right->left=newnode(2);
	root->right->right=newnode(4);


	if(childSumProp(root))
		cout<<"property holds\n";
	else
		cout<<"property doesn't holds\n";

}
