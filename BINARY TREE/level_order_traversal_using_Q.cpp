#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
typedef struct node node;
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void levelorder(node*head)
{
	if(head==NULL)
	{
		cout<<"empty tree \n";
		return;
	}
	queue<node*>q;
	q.push(head);
	while(!q.empty())
	{
		node*temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)q.push(temp->left);
		if(temp->right!=NULL)q.push(temp->right);
	}

}
int main()
{
	node*head=newnode(10);
	head->left=newnode(20);
	head->right=newnode(30);
	head->left->left=newnode(40);
	levelorder(head);
}
