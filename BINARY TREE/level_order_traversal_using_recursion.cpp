#include <bits/stdc++.h>
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
int height(node*head)
{
	if(head==NULL)
		return 0;
	else
	{
		int lheight=height(head->left);
		int rheight=height(head->right);
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}
void levelprint(node*head,int level)
{
	if(head==NULL)return;
	if(level==1)cout<<head->data<<" ";
	else
	{
		levelprint(head->left,level-1);
		levelprint(head->right,level-1);
	}
}
void levelorder(node*head)
{
	int h=height(head);
	for(int i=1;i<=h;i++)
	{
		levelprint(head,i);
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
