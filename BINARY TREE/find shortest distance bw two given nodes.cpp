// STATEMENT:FINDING SHORTEST DISTANCE B/W TWO GIVEN NODES.
// NOTE: NOT-SELF

// FORMULA USED :: ANS = DISTANCE FROM ROOT TO KEY1 + DISTANCE FROM ROOT TO KEY2 - 2*(DISTANCE FROM ROOT TO LCA(OF BOTH KEYS))

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

// finding the lca of given two keys
node* lca(node*root,int k1,int k2)
{
	if(root==NULL)return NULL;
	if(root->data==k1 || root->data==k2)return root;
	node*left_lca=lca(root->left,k1,k2);
	node*right_lca=lca(root->right,k1,k2);
	if(left_lca && right_lca)return root;
	return (left_lca?left_lca : right_lca);
}

// find the distance b/w root and given node
void dist(node*root,int level,int key,int *ans)
{
	if(root==NULL)return;
	if(root->data==key)*ans=level;
	dist(root->left,level+1,key,ans);
	dist(root->right,level+1,key,ans);
}

// calculates the shortest distance b/w two given nodes by using the formula
void shortestDist(node*root,int k1,int k2)
{
	if(root==NULL)return;
	int d1,d2;
	dist(root,1,k1,&d1);
	dist(root,1,k2,&d2);

	// find the lca of given two nodes
	node*ans=lca(root,k1,k2);

	// calculate the distance b/w root and lca
	int x;
	dist(root,1,ans->data,&x);

	// use the formula to find the actual answer: (distance from root to key1 + distance from root to key2 - 2*(distance from root to lca of key1 ans key 2))
	cout<<(d1+d2-(2*x));
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

	int k1=2,k2=7;
	shortestDist(root,k1,k2);
}
