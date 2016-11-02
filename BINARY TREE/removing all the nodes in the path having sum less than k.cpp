// STATEMENT: removing(pruning) all the nodes in the path having sum less than k
// NOTE: NOT-SELF

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left, * right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

// refer ur notebook for more clarification
// a recursive function which deletes leaf nodes in bottom up manner
// we keep traversing the nodes and when we reach leaf node, we check if leaf's data is less than sum or not.
// if less then we delete the leaf node
// if greater we leave it as it is.
node* prune(node*root,int sum)
{
	if(root==NULL)return NULL;
	// going bottom up manner / post-order traversal
	root->left=prune(root->left,sum-root->data);
	root->right=prune(root->right,sum-root->data);

	// checking if node is leaf
	if(!root->right && !root->left)
	{
		// if leaf node's data is less than sum then we delete it.
		if(root->data<sum)
		{
			free(root);
			root=NULL;
		}
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
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	int k=8;

	root=prune(root,k);

	inO(root);

}
