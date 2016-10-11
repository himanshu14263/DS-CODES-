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
void deletetree(node*tree)
{
	if(tree==NULL)return;
	deletetree(tree->left);
	deletetree(tree->right);
	cout<<"deleting node : "<<tree->data<<"\n";
	free(tree);
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

	cout<<"the data of root before deleting: "<<tree->data<<"\n";

	deletetree(tree);

	cout<<"the data of root before deleting: "<<tree->data<<"\n";


}
