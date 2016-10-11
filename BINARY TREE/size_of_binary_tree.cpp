// finding the size of given B.T.
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
int sizeOfTree(node*tree)
{
	if(tree==NULL)return 0;
	return (sizeOfTree(tree->left)+sizeOfTree(tree->right)+1);
}
int main()
{
	node*tree=newnode(1);
	tree->left=newnode(2);
	tree->left->left=newnode(4);
	tree->left->right=newnode(5);
	tree->right=newnode(3);
	tree->right->left=newnode(6);
	tree->right->right=newnode(7);

	cout<<"the size of binary tree is :- ";
	cout<<sizeOfTree(tree);




}
