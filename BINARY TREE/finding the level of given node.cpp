// note:self;
// PROBLEM: finding the level of a node in binary tree
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

void searchingLevels(node*root,int data,int level)
{
	if(root==NULL)return ;
	if(root->data==data)
	{
		cout<<"level of node: "<<data<<" is "<<level;
	}
	else
	{
		searchingLevels(root->left,data,level+1);
		searchingLevels(root->right,data,level+1);
	}
}


void findLevel(node*root,int data){
	int level=1;
	searchingLevels(root,data,level);
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


	findLevel(root,30);

}
