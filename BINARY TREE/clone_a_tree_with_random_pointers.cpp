#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right,*random;
};
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=n->random=NULL;
	return n;
}
node*copyleftrightnode(node*tree,map<node*,node*>*m)
{
	if(tree==NULL)return NULL;
	node*clonenode=newnode(tree->data);
	(*m)[tree]=clonenode;
	clonenode->left=copyleftrightnode(tree->left,m);
	clonenode->right=copyleftrightnode(tree->right,m);
	return clonenode;
}
void copyrandom(node*tree,node*clonenode,map<node*,node*>*m)
{
	if(tree==NULL)return;
	clonenode->random=(*m)[tree->random];
	copyrandom(tree->left,clonenode->left,m);
	copyrandom(tree->right,clonenode->right,m);
}
node*clonetree(node*tree)
{
	if(tree==NULL)return NULL;
	map<node*,node*>*m=new map<node*,node*>;
	node*clonetree=copyleftrightnode(tree,m);
	copyrandom(tree,clonetree,m);
	return clonetree;
}
void inO(node*tree)
{
	if(tree==NULL)
		return;
	inO(tree->left);
	cout<<"["<<tree->data<<",";
	if(tree->random==NULL)
		cout<<"NULL],";
	else
		cout<<tree->random->data<<"],";
	inO(tree->right);
}
int main()
{
	node*tree=newnode(10);
	tree->left=newnode(20);
	tree->right=newnode(30);
	tree->left->left=newnode(40);
	tree->left->left->random=tree;
	tree->left->random=tree->right;

	inO(tree);
	node*newtree=clonetree(tree);
	cout<<"\n";
	inO(newtree);
}
