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

// MY METHOD:
void levelSumDiff(node*root,int*esum,int*osum,int level)
{
	if(root==NULL)return;

	// based on level's value nodes are categorized as even or odd
	if(level&1)
	{
		(*osum)+=root->data;
		levelSumDiff(root->left,esum,osum,level+1);
		levelSumDiff(root->right,esum,osum,level+1);
	}
	else
	{
		(*esum)+=root->data;
		levelSumDiff(root->left,esum,osum,level+1);
		levelSumDiff(root->right,esum,osum,level+1);
	}
}

// OTHER'S METHOD:
// TIME'S COMPLEXITY : O(n)
int func(node*root)
{
	if(root==NULL)return 0;
	return (root->data - func(root->left) - func(root->right));
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


	int esum=0,osum=0,level=1;
	levelSumDiff(tree,&esum,&osum,level);

	cout<<"the sum of even level is :: "<<esum<<"\n"<<"the sum of odd level is :: "<<osum<<"\n";

	cout<<"the difference b/w the odd and even levels is :: "<<esum-osum<<"\n";

	cout<<"\n\nanswer by other's method :: "<<func(tree);
}
