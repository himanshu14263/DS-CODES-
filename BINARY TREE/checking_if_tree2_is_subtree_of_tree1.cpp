// checking if tree(S) is the subtree of given tree(T);
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
bool areIdentical(node*T,node*S)
{
	if(T==NULL&&S==NULL)return true;
	if(T==NULL||S==NULL)return false;
	return(T->data==S->data && areIdentical(T->left,S->left) && areIdentical(T->right,S->right));
}
bool isSubtree(node*T,node*S)
{
	if(S==NULL)return true;
	if(T==NULL)return false;
	if(areIdentical(T,S))return true;
	return (isSubtree(T->left,S)||isSubtree(T->right,S));
}
int main()
{
	node*tree1=newnode(1);
	tree1->left=newnode(2);
	tree1->left->left=newnode(4);
	tree1->left->right=newnode(5);
	tree1->right=newnode(3);
	tree1->right->left=newnode(6);
	tree1->right->right=newnode(7);

	node*tree2=newnode(2);
	tree2->left=newnode(4);
	tree2->right=newnode(5);

	if(isSubtree(tree1,tree2))
	{
		cout<<"tree2 is subtree of tree1\n";
	}
	else
	{
		cout<<"tree2 isn't the subtree of tree1\n";
	}


}
