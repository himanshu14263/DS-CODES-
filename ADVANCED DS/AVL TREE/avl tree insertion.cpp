// PROBLEM :: AVL TREE CREATION

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	node*left,*right;
	int height;
};

int ht(node*root)
{
	if(root==NULL)return 0;
	return root->height;
}

node* newNode(int key)
{
	node*n=new node;

	n->left=n->right=NULL;
	n->height=1;
	n->key=key;

	return n;
}

int getBalance(node*root)
{
	return (ht(root->left)-(ht(root->right)));
}

node*rotateRight(node*root)
{
	node*newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->height = 1 + max(ht(root->left),ht(root->right));
	newRoot->height = 1 + max(ht(newRoot->left),ht(newRoot->right));

	return newRoot;
}

node*rotateLeft(node*root){

		node*newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;

		root->height = 1 + max(ht(root->left),ht(root->right));
		newRoot->height = 1 + max(ht(newRoot->left),ht(newRoot->right));

		return newRoot;
}
node*insert(node*root,int key)
{
	if(root==NULL) return newNode(key);
	else if(key<root->key)root->left = insert(root->left,key);
	else if(key>root->key)root->right = insert(root->right,key);
	else return root;

	root->height = 1+max(ht(root->left),ht(root->right));
	int balance = getBalance(root);

	// LL
	if(balance > 1  &&  key<root->left->key)
	{
		return rotateRight(root);
	}

	// LR
	if(balance>1 && key>root->left->key)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	// RR
	if(balance<-1 && key>root->right->key)
	{
			return rotateLeft(root);
	}

	// RL
	if(balance<-1 && key<root->right->key)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}


void preO(node*root)
{
	if(root==NULL)return;


	cout<<root->key<<" ";

	preO(root->left);
	preO(root->right);
}

int main()
{
	node*root=NULL;

	int arr[] = {10,20,30,40,50,25};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
	{
		root = insert(root,arr[i]);
	}

	preO(root);
}
