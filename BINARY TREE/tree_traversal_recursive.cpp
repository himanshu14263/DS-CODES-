#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
typedef struct node node;
node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void IO(node*n)
{
	if(n==NULL)
		return;
	if(n->left!=NULL)IO(n->left);
	cout<<n->data<<" ";
	if(n->right!=NULL)IO(n->right);
}
void preO(node*n)
{
	if(n==NULL)
		return;
	cout<<n->data<<" ";
	if(n->left!=NULL)preO(n->left);
	if(n->right!=NULL)preO(n->right);
}
void postO(node*n)
{
	if(n==NULL)
		return;
	if(n->left!=NULL)postO(n->left);
	if(n->right!=NULL)postO(n->right);
	cout<<n->data<<" ";

}
int main()
{
	node*head= newnode(10);
	head->left=newnode(20);
	head->right=newnode(30);
	head->left->left=newnode(40);
	IO(head);
	cout<<"\n";
	preO(head);
	cout<<"\n";
	postO(head);
}
