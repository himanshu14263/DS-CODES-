// PROBLEM : FINDING THE COUNT OF SINGLE VALUE SUBTREES
// TIME-COMPLEXITY REQD: O(N)

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

bool singleCount(node*root,int & count)
{
	if(root==NULL)return true;

	bool left=singleCount(root->left,count);
	bool right=singleCount(root->right,count);

	// just check the three cases which makes it not single value tree

	// 1) if calculation of left and right child already not single valued
	if(left==false || right==false)return false;

	// 2) if it has only left child but it's data don't match with root's data
	if(root->left && (root->data!=root->left->data))return false;

	// 3) if it has only right child but it's data don't match with root's data
	if(root->right && (root->data!=root->right->data))return false;

	// if all the above conditions comes to be false
	// that means it is a single valued subtree
	// so we increment the value by 1
	count++;
	return true;
}
int main()
{
	 	node*root=newnode(5);
	 	root->right=newnode(5);
	 	root->left=newnode(1);
	 	root->left->left=newnode(5);
	 	root->left->right=newnode(5);
	 	root->right->right=newnode(5);

	    int count=0;
	    singleCount(root,count);
	    cout<<count;


}
