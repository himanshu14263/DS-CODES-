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
stack<node*>s;
void inOwithoutRecur(node*tree)
{


	while(tree!=NULL)
	{
		s.push(tree);
		tree=tree->left;
	}
	if(!s.empty()){
		node*temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		inOwithoutRecur(temp->right);
	}
}
void inO(node*tree)
{
	if(tree==NULL)return;
	inO(tree->left);
	cout<<tree->data<<" ";
	inO(tree->right);
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

	inOwithoutRecur(tree);
	cout<<"\n\n";
	inO(tree);



}
