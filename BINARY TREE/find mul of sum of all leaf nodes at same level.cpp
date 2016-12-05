// PROBLEM : FIND THE MULTIPLICATION OF SUM OF DATA AT SAME LEVELS
// LOGIC : SIMPLY USED LEVEL ORDER TRAVERSAL WITH A BIT OF MODIFICATION.

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
int ht(node*root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}

void leafSum(node*root,int h,int &sum)
{
	if(root==NULL)return;
	if((h==1) && (!root->left && !root->right))
		sum+=root->data;
	leafSum(root->left,h-1,sum);
	leafSum(root->right,h-1,sum);
}
void lot(node*root)
{
	int ans=1;
	int h=ht(root);
	for(int i=1;i<=h;i++)
	{
		int sum=0;
		leafSum(root,i,sum);
		if(sum!=0)
			ans*=sum;
	}
	cout<<ans;
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	lot(root);
}
