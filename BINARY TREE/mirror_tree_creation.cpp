// CREATING A MIRROR TREE OF A GIVEN TREE
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

node* func2mirror(node*root)
{
	if(root==NULL)return NULL;
	int d=root->data;
	node*n=newnode(d);
	n->right=func2mirror(root->left);
	n->left=func2mirror(root->right);
	return n;
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

	cout<<"THE INO OF GIVEN TREE\n";
	inO(root);

	cout<<"\n\n";

	cout<<"THE INO OF MIRROR TREE\n";
	node*mirror=func2mirror(root);
	inO(mirror);
	cout<<"\n";
}

