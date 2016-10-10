// printing all the ancestors of a given node;
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
bool print_ancestors(node*root,int value)
{
	if(root==NULL)return false;
	if(root->data==value)return true;
	if(print_ancestors(root->left,value)||print_ancestors(root->right,value))
	{
		cout<<root->data<<" ";
		return true;
	}
	return false;
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
	cout<<"the ancestors of given nodes are :- ";
	print_ancestors(tree,7);

}
