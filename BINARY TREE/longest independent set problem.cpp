// note:not-self;
// PROBLEM: longest independent set problem in binary tree.

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

int LIS(node*root)
{
	if(root==NULL)return 0;

	// excluding the current node so we can count it's children
	int excl_sum=LIS(root->left)+LIS(root->right);

	// including the current node we can count only it's grand children
	int incl_sum=1;
	if(root->left)incl_sum+=LIS(root->left->left)+LIS(root->left->right);
	if(root->right)incl_sum+=LIS(root->right->left)+LIS(root->right->right);

	return max(incl_sum,excl_sum);

}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	cout<<"the largest independent set's size is :: "<<LIS(root);
}

