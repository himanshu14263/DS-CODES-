// note:self;
// PROBLEM: converting given tree into double tree
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
void createDoubleTree(node*root)
{
	if(root==NULL)return;

	// creating root's duplicate copy
	int d=root->data;
	node*n=newnode(d);

	// assigning it correct location
	n->left=root->left;
	root->left=n;

	//sending root->left->left for next cycle b/c that one is original data.
	createDoubleTree(root->left->left);
	createDoubleTree(root->right);
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


	inO(root);
	cout<<"\n";

	createDoubleTree(root);

	inO(root);




}
