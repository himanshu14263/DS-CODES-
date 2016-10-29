// note:self;
// PROBLEM: check whether given tree is complete or not.
// TIME COMPLEXITY : - O(N)

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

// function simply checks whether given tree is complete or not
bool completeCheck(node*root)
{
	if(root==NULL)return true;    // if node is null then it is complete
	if(root->left && root->right==NULL)return false;		// condition which make tree incomplete
	if(root->right && root->left==NULL)return false;		// condition which make tree incomplete
	return(completeCheck(root->left) && completeCheck(root->right));	//recurcively calling the function to check each node of the tree
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->left->right->left=newnode(444);

	if(completeCheck(root))
		cout<<"complete\n";
	else
		cout<<"incomplete\n";

}
