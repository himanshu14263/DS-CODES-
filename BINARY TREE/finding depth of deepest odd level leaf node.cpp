// STATEMENT: FINDING THE DEPTH OF DEEPEST ODD LEVEL LEAF NODE
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


// recursive function to find the depth of deepest odd level node
int findDepth(node*root,int level)
{
	if(root==NULL)return 0;

	// returns level only if node is leaf and it is an odd level
	if((!root->left) && (!root->right) && (level&1))return level;

	// find the max b/w the left and the right sub tree
	return (max(findDepth(root->left,level+1),findDepth(root->right,level+1)));
}

int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	root->right->left->right=newnode(7);
	root->right->left->right->left=newnode(9);
	root->right->right->right=newnode(8);
	root->right->right->right->right=newnode(10);
	root->right->right->right->right->left=newnode(11);

	cout<<findDepth(root,1);
}
