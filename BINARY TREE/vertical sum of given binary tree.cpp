// note:self;
// PROBLEM: finding vertical sum of given binary tree
// TIME COMPLEXITY : - O(N)

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

// using map to map horizontal distance from root and other nodes data
// if a key doesn't exist in map then we create it otherwise we add new node value to existing key
void utilVerticalSum(node*root,map<int,int>&mp,int hd)
{
	if(root==NULL)return;

	map<int,int>::iterator it=mp.find(hd);

	if(it==mp.end())
		mp[hd]=root->data;
	else
		mp[hd]+=root->data;

	utilVerticalSum(root->left,mp,hd-1);
	utilVerticalSum(root->right,mp,hd+1);

}

// used this to create the map and display the map's content
void verticalSum(node*root)
{
	if(root==NULL)return;
	map<int,int>mp;
	utilVerticalSum(root,mp,0);

	map<int,int>::iterator it;
	for( it=mp.begin();it!=mp.end();++it)
	{
		cout<<it->first<<"  "<<it->second<<"\n";
	}
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

	verticalSum(root);



}
