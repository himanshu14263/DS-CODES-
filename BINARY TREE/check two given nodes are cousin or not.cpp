// PROBLEM : check cousins or not

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// this is my method of finding the level
// in this we use an extra variable to store the answer where it matches the required condition
void findLevel(node*root,int data,int level,int& ans)
{
	if(root==NULL)return;
	if(root->data==data)ans=level;
	findLevel(root->left,data,level+1,ans);
	findLevel(root->right,data,level+1,ans);
}

// we use here the pointer comparison to check if root has the same two nodes as children which are passed
bool sameParent(node*root,node* a,node* b)
{
	if(root==NULL)return false;
	return ((root->left==a && root->right==b )||
			(root->left==b && root->right==a)||
			(sameParent(root->left,a,b))||
			(sameParent(root->right,a,b)));
}

// for two nodes to be cousin it must satisfy two conditions :
// 1) they must be on the same level
// 2) their parent must be different.
bool isCousin(node*root,node*a,node*b)
{
	int l1,l2;

	findLevel(root,a->data,1,l1);		// finding the level of first node
	findLevel(root,b->data,1,l2);		// finding the level of second node

	return (l1==l2 && (!sameParent(root,a,b)));		// checking if both the conditions are satisfied
}
int main()
{
	 	node*root=newnode(1);
	 	root->left=newnode(2);
	 	root->right=newnode(3);
	 	root->left->left=newnode(4);
	 	root->left->right=newnode(5);
	 	root->right->right=newnode(6);
	 	root->left->left->left=newnode(7);
	 	root->right->right->left=newnode(8);

	 	node*a=root->left->left->left;
	 	node*b=root->left->right;

	 	if(isCousin(root,a,b))
	 		cout<<"they are cousin\n";
	 	else
	 		cout<<"they aren't cousin\n";


}
