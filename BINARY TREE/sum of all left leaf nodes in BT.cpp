// PROBLEM : finding the sum of all the left leaf nodes in binary tree.
// LOGIC : used pre-order traversal and added a flag to mark that the coming node is left child of parent
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void preO(node*root,int f,int&sum)
{
	if(!root)return;
	if(f==1 && (!root->left && !root->right))sum+=root->data;
	preO(root->left,1,sum);
	preO(root->right,0,sum);
}
int main()
{
	 	node*root        		  = newnode(20);
	    root->left                = newnode(9);
	    root->right               = newnode(49);
	    root->right->left         = newnode(23);
	    root->right->right        = newnode(52);
	    root->right->right->left  = newnode(50);
	    root->left->left          = newnode(5);
	    root->left->right         = newnode(12);
	    root->left->right->right  = newnode(12);
	int sum=0;
	preO(root,0,sum);
	cout<<sum<<" ";
}
