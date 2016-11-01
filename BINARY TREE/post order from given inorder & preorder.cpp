// STATEMENT: PRINTING THE DIFFERENCE B/W THE SUM OF ODD LEVEL AND EVEN LEVEL NODES
// NOTE: SELF

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

// my method : first creating the tree and then doing postorder traversal
node* f(int in[],int pre[],int*preIndx,int l,int h)
{
	if(l<=h)
	{
		node*n=newnode(pre[*preIndx]);

		int i;
		for(i=l;i<=h;i++)
		{
			if(pre[*preIndx]==in[i])
				break;
		}
		++(*preIndx);
		if(l==h)return n;

		if(i<=h)
		{
			n->left=f(in,pre,preIndx,l,i-1);
			n->right=f(in,pre,preIndx,i+1,h);
		}



		return n;
	}
}
// doing post order traversal
void print(node*root)
{
	if(root==NULL)return;
	print(root->left);
	print(root->right);
	cout<<root->data<<" ";
}

// METHOD 2 : NOT MINE (without creating tree printing the postorder traversal)
//

// helper function to find the node in inorder traversal
int findNode(int in[],int x,int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i]==x)
			return i;
	}
	return -1;
}

// recurcive function to print the post order traversal
void printPostOrder(int in[],int pre[],int n)
{
	// finding the node of preorder traversal in inorder traversal
	int root=findNode(in,pre[0],n);

	// then based on above found node we split the inorder traversal into two parts(left and right subtree)

	// left subtree
	// until there is node in left subtree keep printing them
	if(root!=0)printPostOrder(in,pre+1,root);

	// right subtree
	// until there is node in right subtree keep printing them
	if(root!=n-1)printPostOrder(in+root+1,pre+root+1,n-root-1);

	// at last printing the root
	cout<<pre[0]<<" ";
}
int main()
{
	int pre[]={1,2,5,3};
	int in[]={2,5,1,3};
	int preIndx=0;
	node* root=f(in,pre,&preIndx,0,3);

	cout<<"by creating tree method :: ";
	print(root);

	cout<<"\nby other's method :: ";
	printPostOrder(in,pre,4);


}
