// note:not-self;
// PROBLEM: morris traversal for preorder
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


// done as per morris traversal for preorder.
void preorderMorris(node*root)
{
	while(root)
	{
		if(root->left==NULL)
		{
			cout<<root->data<<" ";
			root=root->right;
		}
		else
		{
			node*curr=root->left;

			while(curr->right && curr->right!=root)		// important condition curr->right
				curr=curr->right;

			if(curr->right==root)
			{
				curr->right=NULL;
				root=root->right;
			}
			else
			{
				cout<<root->data<<" ";
				curr->right=root;
				root=root->left;
			}
		}
	}
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	preorderMorris(root);


}
