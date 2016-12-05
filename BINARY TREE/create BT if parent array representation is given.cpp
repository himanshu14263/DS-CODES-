// PROBLEM : IF PARENT ARRAY REPRESENTATION IS GIVEN CREATE THE B.T.

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

void createNode(int parent[],int i,node*created[],node**root)
{
	// if the node is created then simply return
	if(created[i]!=NULL)return;

	// if node isn't created then create it
	// and store the pointer to that node in created[] array
	created[i]=newnode(i);

	// if the parent of the current node is none i.e. it is root
	// then store the current node's value in root
	if(parent[i]==-1)
	{
		*root=created[i];
		return;
	}

	// check if the parent of the current node is created or not
	// if not then first create the parent of the current node and recur
	if(created[parent[i]]==NULL)
	{
		createNode(parent,parent[i],created,root);
	}

	// and when finally the parent node is created then
	// mark the current node as its left child
	// if it already has left child then make it right child
	node*p=created[parent[i]];
	if(p->left==NULL)
		p->left=created[i];
	else
		p->right=created[i];

}
node*createTree(int parent[],int n)
{
	node*root;		// it stores the final root value

	node* created[n];		// keep check if the node is created related to a particular index
							// and if created then stores pointer to that particular node.

	// initially we mark that none of the node is created
	for(int i=0;i<n;i++)
		created[i]=NULL;

	// through this loop we create node for all the indexes i.e. [0...n-1]
	for(int i=0;i<n;i++)
	{
		createNode(parent,i,created,&root);
	}

	return root;
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
	int parent[]={1,5,5,2,2,-1,3};
	node*root;
	int n=sizeof(parent)/sizeof parent[0];
	root=createTree(parent,n);
	inO(root);
}
