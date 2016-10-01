#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
int height(node*head)
{
	if(head==NULL)return 0;
	return (1+max((height(head->left)),(height(head->right))));
}
int diameter(node*head)
{
	if(head==NULL)	return 0;
	int lheight=height(head->left);
	int rheight=height(head->right);
	int ldiameter=diameter(head->left);
	int rdiameter=diameter(head->right);
	return(max((lheight+rheight+1),(max(ldiameter,rdiameter))));

}
int main()
{
	node*head=newnode(1);
	head->left=newnode(2);
	head->right=newnode(3);
	head->left->left=newnode(4);
	head->left->right=newnode(5);
	cout<<diameter(head);
}
