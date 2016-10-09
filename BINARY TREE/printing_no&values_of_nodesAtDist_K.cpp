// print all the number and values of nodes at a distance 'k' from the root
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
int count_of_nodes_at_dist_K(node*root,int k)
{
	if(root==NULL)return 0;
	if(k==0){return 1;}
	else
	{
		return count_of_nodes_at_dist_K(root->left,k-1) +
		count_of_nodes_at_dist_K(root->right,k-1);
	}
}
void nodes_at_dist_K(node*root,int k)
{
	if(root==NULL)return;
	if(k==0){cout<<root->data<<" ";return;}
	else
	{
		nodes_at_dist_K(root->left,k-1);
		nodes_at_dist_K(root->right,k-1);
	}
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
	int k;
	cout<<"enter the distance\n";
	cin>>k;
	cout<<"the number of nodes at a distance k are: "<<count_of_nodes_at_dist_K(tree,k)<<"\n";
	cout<<"these nodes are : ";
	nodes_at_dist_K(tree,k);
}
