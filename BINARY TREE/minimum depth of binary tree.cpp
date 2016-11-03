// STATEMENT:FINDING THE MINIMUM DEPTH OF GIVEN BT
// NOTE : SELF
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
// simply traversing the tree
// if a leaf is encountered then and its level is less than curr ans then we store it
void minDepth(node*root,int *ans,int level)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)
		{
			if(*ans>level)
				*ans=level;
		}
	minDepth(root->left,ans,level+1);
	minDepth(root->right,ans,level+1);
}

int main()
{
	node*root=newnode(1);
	root->right=newnode(3);
	root->right->right=newnode(4);
	root->right->left=newnode(4);
	root->right->right->right=newnode(4);

	int level=INT_MAX;
	minDepth(root,&level,1);
	cout<<level;

}
