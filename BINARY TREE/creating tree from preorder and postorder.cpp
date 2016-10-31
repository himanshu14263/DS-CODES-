// note:not-self;
// PROBLEM: constructing full binary tree if preorder and postorder traversal are given.
// note: tree creation is possible only if given traversal are of full binary tree else it is not possible.
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

// this function creates the tree
node* createTreeUtil(int preO[],int postO[],int *preIndx,int l,int h,int size)
{
	if(*preIndx>=size || l>h)		// no effect after removing this condition
		return NULL;

	node*root=newnode(preO[*preIndx]);
	(*preIndx)++;

	if(l==h)return root;

	int i;
	for(i=0;i<h;i++)
		if(preO[*preIndx]==postO[i])
			break;
	if(i<h)
	{
		root->left=createTreeUtil(preO,postO,preIndx,l,i,size);
		root->right=createTreeUtil(preO,postO,preIndx,i+1,h-1,size);
	}

	return root;
}

// function to pass preIndx=0 as reference
node* createTree(int preO[],int postO[],int size)
{
	int preIndx=0;
	node*tree=createTreeUtil(preO,postO,&preIndx,0,size-1,size);
	return tree;
}

void inO(node*root)
{
	if(root==NULL)return;
	cout<<root->data<<" ";
	inO(root->left);

	inO(root->right);
}
int main()
{
	int preO[]={1,2,4,8,9,5,3,6,7,};
	int postO[]={8,9,4,5,2,6,7,3,1};
	int size=sizeof(preO)/sizeof(preO[0]);
	node* tree=createTree(preO,postO,size);

	inO(tree);
}
