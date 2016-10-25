

	// note : not self
	// printing B.T. in spiral form using O(n^2) recursive method

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

// finding the height of tree
int ht(node*root)
{
	if(root==NULL)return 0;
	return (1+max((ht(root->left)),(ht(root->right))));
}

// printing levels recursively based on flag
void printlevels(node*root,int level,bool flag)
{
	if(root==NULL)return;
	if(level==1)cout<<root->data<<" ";
	else
	{
		if(flag)
		{
			printlevels(root->right,level-1,flag);
					printlevels(root->left,level-1,flag);
		}
		else
		{
			printlevels(root->left,level-1,flag);
					printlevels(root->right,level-1,flag);
		}
	}
}

// function to initiate the spiral level order traversals
void LOT(node*root)
{
	int height=ht(root);
	bool flag=1;
	for(int i=1;i<=height;i++)
	{
		printlevels(root,i,flag);
		flag=!flag;
	}
}
int main()
{
	// creating the tree
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	//calling the function to print in spiral form
	LOT(root);
}


