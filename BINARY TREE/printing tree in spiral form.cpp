
// NOTE:SELF
// PRINTING A GIVEN TREE IN SPIRAL FORM

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

int countLeaf(node*root)
{
	if(root==NULL)return 0;
	else if(root->left==NULL && root->right==NULL)return 1;
	else
	{
		return (countLeaf(root->left)+countLeaf(root->right));
	}
}


void LOT(node* root)
{
	queue<pair<node*,int> >q;
	stack<int>st;							// made to store the even level values
	q.push(make_pair(root,0));
	while(!q.empty())
	{
		pair<node*,int>temp=q.front();
		q.pop();


		if(temp.second&1)					// printing values only at odd levels
		{
			while(!st.empty()){
					cout<<st.top()<<" ";st.pop();
				}

			cout<<temp.first->data<<" ";
		}
		else								// if the level is even then just storing it in stack
		{
			st.push(temp.first->data);
		}


		if(temp.first->left)q.push(make_pair(temp.first->left,temp.second+1));
		if(temp.first->right)q.push(make_pair(temp.first->right,temp.second+1));
	}

	//if there are even levels then the last level wont be printed so to print that we have to add this loop
	while(!st.empty())
	{
			cout<<st.top()<<" ";st.pop();
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
	LOT(root);
}


