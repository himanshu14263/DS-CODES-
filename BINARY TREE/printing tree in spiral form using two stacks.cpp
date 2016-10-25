

	// note : not self
	// printing B.T. in spiral form using two stack method in O(n)

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

// using two stack method to print in spiral form
void printSpiral(node*root)
{
	stack<node*>s1;
	stack<node*>s2;
	s1.push(root);
	while((!s1.empty()) || (!s2.empty()))
	{
		while(!s1.empty())
		{
			node*temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left)s2.push(temp->right);			// note: putting right first
			if(temp->right)s2.push(temp->left);
		}
		while(!s2.empty())
		{
			node*temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)s1.push(temp->left);
			if(temp->right)s1.push(temp->right);
		}
	}
}

int main()
{
	// creating the tree
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	//calling the function to print in spiral form
	printSpiral(root);
}


