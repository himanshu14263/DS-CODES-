// connecting nodes at same level using .
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right,*rightPtr;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
void settingRightPtr(node*root)
{
	if(!root)return;
	if(root->left)root->left->rightPtr=root->right;
	if(root->right)root->right->rightPtr=root->rightPtr?root->rightPtr->left:NULL;
	settingRightPtr(root->left);
	settingRightPtr(root->right);
}
void print(node*temp)
{
	if(!temp)
	{
		cout<<"empty list\n";
		return;
	}
	else
	{
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->rightPtr;
		}
	}
}
int main()
{
	node*tree=newnode(1);
	tree->left=newnode(2);
	tree->left->left=newnode(4);
	tree->left->right=newnode(5);
	tree->right=newnode(3);
	tree->right->left=newnode(6);
	tree->right->right=newnode(7);
	tree->rightPtr=NULL;
	settingRightPtr(tree);
	print(tree->left->left); // printing the right pointers starting from node 7;

}
