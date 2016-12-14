// PROBLEM :: TWO NODES OF BST ARE SWAPPED CORRECT THE BST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

// simply doing inO traversal and checking if violation has occured or not
void correctBSTUtil(node*root,node*&first,node*&middle,node*&last,node*&prev)
{
	if(root==NULL)return;

		correctBSTUtil(root->left,first,middle,last,prev);

			if(prev && (prev->data>root->data))		// checking if violation occured
			{
				if(!first)			// checking if it is first violation
				{
					first=prev;
					middle=root;
				}
				else				// if above condition if failed then it is second violation
					last=root;
			}

			prev=root;

			correctBSTUtil(root->right,first,middle,last,prev);

}
void correctBST(node*root)
{
	node*first,*middle,*last,*prev;
	first=middle=last=prev=NULL;

	correctBSTUtil(root,first,middle,last,prev);

	// this condition holds true if the nodes aren't adjacent
	if(first && last)
		swap(first->data,last->data);
	// this condition holds true if the swapped nodes are adjacent
	else if(first && middle)
		swap(first->data , middle->data);
}
int main()
{
		node *root = newnode(6);
	    root->left        = newnode(10);
	    root->right       = newnode(2);
	    root->left->left  = newnode(1);
	    root->left->right = newnode(3);
	    root->right->right = newnode(12);
	    root->right->left = newnode(7);

	    cout<<"the tree having nodes swapped\n";
	    inO(root);
	    cout<<"\n";

	    correctBST(root);

	    cout<<"The tree after correction\n";
	    inO(root);

}
