// STATEMENT: PRINTING LEFT VIEW OF GIVEN B.T.
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

////////////////////////////////////// MY METHOD (USING RECURSIVE LEVEL ORDER TRAVERSAL) ////////////////////////////
int ht(node*root)
{
	if(!root)return 0;
	return(1+max(ht(root->left),ht(root->right)));
}
void printLevel(node*root,int level,int*flag)
{
	if(root==NULL)return;
	if(level==1 && *flag==0)
	{
		cout<<root->data<<" ";
		*flag=1;
	}
		printLevel(root->left,level-1,flag);
		printLevel(root->right,level-1,flag);

}

void print(node*root)
{
	int h=ht(root);
	for(int i=1;i<=h;i++)
	{
		int flag=0;
		printLevel(root,i,&flag);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// METHOD 2: USING RECURSION (NOT MY METHOD) ////////////////////////////////

void printUtil(node*root,int level,int*prevLeftLevel)
{
	if(root==NULL)return;
	if(level>*prevLeftLevel)
	{
		cout<<root->data<<" ";
		*prevLeftLevel=level;
	}
	printUtil(root->left,level+1,prevLeftLevel);
	printUtil(root->right,level+1,prevLeftLevel);
}

void printLeftView(node*root)
{
	int level=1,prevLeftLevel=0;
	printUtil(root,level,&prevLeftLevel);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	root->right->left->right=newnode(7);
	root->right->left->right->left=newnode(9);
	root->right->right->right=newnode(8);
	root->right->right->right->right=newnode(10);
	root->right->right->right->right->left=newnode(11);

	print(root);
	cout<<"\n";
	printLeftView(root);
}
