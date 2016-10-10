// connecting nodes at same level using Q.
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right,*rightPtr;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
void settingRightPtr(node*root)
{
	root->rightPtr=NULL;
	queue<pair<node*,int> >Q;
	Q.push(make_pair(root,0));
	while(!Q.empty())
	{
		pair<node*,int>temp=Q.front();
		Q.pop();
		if(Q.front().second==temp.second)
			temp.first->rightPtr=Q.front().first;
		else
			temp.first->rightPtr=NULL;
		if(temp.first->left)Q.push(make_pair(temp.first->left,temp.second+1));
		if(temp.first->right)Q.push((make_pair(temp.first->right,temp.second+1)));
	}
}
void print(node*temp)
{
	if(!temp)
	{
		cout<<"empty list\n";
		return;
	}
	else
	{
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->rightPtr;
		}
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
	settingRightPtr(tree);
	print(tree->left->left); // printing the right pointers starting from node 7;

}
