// note: not-self
// statement: Populate inorder successor of all nodes
// time complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right,*next=NULL;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

//  METHOD :1  WITHOUT USING STATIC VARIABLE

void reverseInO(node*root,node**prev)
{
	if(root)
	{
		reverseInO(root->right,prev);
		root->next=*prev;
		*prev=root;
		reverseInO(root->left,prev);
	}
}
void populateSuccessor1(node*root)
{
	if(root==NULL)return;
	node*prev=NULL;
	reverseInO(root,&prev);
}


// METHOD 2 : USING STATIC VARIABLE


void populateSuccessor2(node*root)
{
	static node*prev=NULL;
	if(root)
	{
		populateSuccessor2(root->right);
		root->next=prev;
		prev=root;
		populateSuccessor2(root->left);
	}
}
void display(node*root)
{
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->next;
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

	populateSuccessor2(tree);

	display(tree->left->left);

}
