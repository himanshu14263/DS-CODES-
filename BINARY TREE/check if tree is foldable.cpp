// note:not-self;
// PROBLEM: check if tree is foldable
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

bool checkFoldable(node*left,node*right)
{
	if(left==NULL && right==NULL)return 1;
	if(left==NULL && right!=NULL)return 0;
	if(left!=NULL && right==NULL)return 0;
	return checkFoldable(left->left,right->right)&&checkFoldable(left->right,right->left);

}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->right=newnode(3);
	root->right->left=newnode(5);


	if(checkFoldable(root->left,root->right))
		cout<<"foldable\n";
	else
		cout<<"not foldable\n";

}
