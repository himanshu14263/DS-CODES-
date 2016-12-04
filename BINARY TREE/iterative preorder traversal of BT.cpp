// PROBLEM : ITERATIVE PREORDER TRAVERSAL OF B.T.
// TIME COMPLEXITY : O(N)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void func(node*root)
{
	stack<node*>s;
	s.push(root);

	// iterative pre order traversal consists of three steps only:
	// 1) pop the element from the stack
	// 2) push its right child
	// 3) push its left child

	while(!s.empty())
	{
		node*n=s.top();
		cout<<n->data<<" ";
		s.pop();
		if(n->right)s.push(n->right);
		if(n->left)s.push(n->left);
	}
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	func(root);
}
