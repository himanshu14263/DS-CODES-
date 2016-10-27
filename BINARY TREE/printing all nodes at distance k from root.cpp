// note:not-self;
// PROBLEM: printing all nodes at a distance k from the root
// TIME COMPLEXITY : - O(n)

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

void printingAtK(node*root,int d)
{
	if(root==NULL)return ;
	if(d==0)cout<<root->data<<" ";
	else
	{
		printingAtK(root->left,d-1);
		printingAtK(root->right,d-1);
	}
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->left->right=newnode(9);
	root->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(30);


	printingAtK(root,2);

}
