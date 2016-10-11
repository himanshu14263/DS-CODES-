// checking if two given trees are identical or not
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
bool areidentical(node*t1,node*t2)
{
	if(t1==NULL && t2==NULL)return true;
	if(t1==NULL || t2==NULL)return false;
	return (t1->data==t2->data && areidentical(t1->left,t2->left) && areidentical(t1->right,t2->right));
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

	node*tree2=newnode(2);
	tree2->left=newnode(4);
	tree2->right=newnode(5);


	node*tree3=newnode(1);
		tree3->left=newnode(2);
		tree3->left->left=newnode(4);
		tree3->left->right=newnode(5);
		tree3->right=newnode(3);
		tree3->right->left=newnode(6);
		tree3->right->right=newnode(7);

	if(areidentical(tree,tree2))
		cout<<"tree and tree2 are identical\n";
	else
		cout<<"tree and tree2 are not identical\n";

	cout<<"\n\n";

	if(areidentical(tree,tree3))
			cout<<"tree and tree3 are identical\n";
		else
			cout<<"tree and tree3 are not identical\n";




}
