// STATEMENT:Check if a given Binary Tree is height balanced like a Red-Black Tree

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

int maxht(node*root)
{
	if(root==NULL)return 0;
	return (1+max(maxht(root->left),maxht(root->right)));
}

int minht(node*root)
{
	if(root==NULL)return 0;
	return (1+min(minht(root->left),minht(root->right)));
}

// METHOD 1 :: SIMPLE RECURSION TO CHECK WHETHER EVERY NODE SATISFY THE RED-BLACK TREE PROPERTY OR NOT
bool check(node*root)
{
	if(root==NULL)return true;
	bool a=(maxht(root)>2*minht(root))?false:true;	// CHECK ROOT
	bool b=check(root->left);						// CHECK LEFT SUBTREE
	bool c=check(root->right);						// CHECK RIGHT SUBTREE
	return(a && b && c);							// ALL MUST SATISFY PROPERTY TO BE A RED BLACK TREE
}

// METHOD 2:: SAME AS ABOVE EXCEPT WRITING STYLE
bool check2(node*root)
{
	if(root==NULL)return true;
	if(maxht(root)>2*minht(root))return false;
	return(check2(root->left) && check2(root->right));
}
int main()
{
	node*root=newnode(1);
	//root->left=newnode(2);
	root->right=newnode(3);
	//root->left->left=newnode(4);
	//root->left->right=newnode(5);
	//root->right->left=newnode(6);
	//root->right->left->left=newnode(0);
	root->right->right=newnode(7);
	//root->right->left->right=newnode(8);

	if(check(root))
		cout<<"possible\n";
	else
		cout<<"impossible\n";

	if(check2(root))
			cout<<"possible\n";
		else
			cout<<"impossible\n";
}
