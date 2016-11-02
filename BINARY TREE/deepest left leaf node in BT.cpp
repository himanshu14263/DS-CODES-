// STATEMENT: find the deepest left leaf node and if doesn't exists then mention it
// NOTE: ALMOST-SELF

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
// function which actually search the node
// a recursive function to find the deepest left leaf node
// same as finding the deepest odd level leaf node just conditions are changed.
// KIM :: the additional condition to check if root is left or not is just a flag passed by left node as true.
void findUtil(node*root,int level,int*ans,int*anslevel,bool isleft)
{
	if(root==NULL)return;
	// check if root is leaf and level is greater than previous ans level and this node is left node
	if(!root->left && !root->right && level> *anslevel && isleft)
	{
		*anslevel=level;
		*ans=root->data;
	}

	// checking left and right subtree
	// left subtree is passed with true parameter while right is sent false
	findUtil(root->left,level+1,ans,anslevel,true);
	findUtil(root->right,level+1,ans,anslevel,false);
}

// helper function to set initial variables and start the searching
void findLeftLeaf(node*root)
{
	int level=1,ans=INT_MIN,anslevel=0;
	findUtil(root,level,&ans,&anslevel,false);

	if(ans==INT_MIN)
		cout<<"no left leaf node exists\n";
	else
		cout<<"the deepest left leaf node is :: "<<ans<<"\n";
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(7);
	root->right=newnode(3);
	root->right->left=newnode(4);
	root->right->left->right=newnode(5);
	root->right->left->right->left=newnode(6);
	root->right->left->right->right=newnode(8);


	findLeftLeaf(root);

}
