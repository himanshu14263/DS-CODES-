//FINDING THE DIAMETER OF THE TREE IN O(N)
#include <bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
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
int diameter(node*root,int *height)
{
	int lh=0,rh=0;
	int ld=0,rd=0;
	if(root==NULL)
	{
		*height=0;
		return 0;
	}

	ld=diameter(root->left,&lh);
	rd=diameter(root->right,&rh);
	*height=max(lh,rh)+1;
	return (max(lh+rh+1,max(ld,rd)));

}
int main()
{
	node*head=new node;
	head->left=newnode(1);
	head->right=newnode(2);
	head->left->left=newnode(3);
	head->left->right=newnode(4);
	int height=0;
	cout<<diameter(head,&height);
}
