// note:not-self;
// PROBLEM: root to leaf path's sum equal to a given number or not.
// TIME COMPLEXITY : - O(n)

#include <bits/stdc++.h>
using namespace std;
typedef struct node node;

struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// simply traversing through the tree and subtracting the node's data from the sum value
// and if the subSum value becomes 0 and it is a leaf node then we return 1 ;
bool checkSum(node*root,int sum)
{
	int ans=0;
	if(root==NULL)
		return (sum==0);
	else
	{
		int subSum=sum-root->data;
		if(subSum==0 && root->left==NULL && root->right==NULL)   // if subSum=0 and it is a leaf node
			return 1;
		else
		{
			ans=ans||checkSum(root->left,subSum);
			ans=ans||checkSum(root->right,subSum);
		}
	}
	return ans;
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->right=newnode(4);
	root->left->left=newnode(5);

	int num=8;

	if(checkSum(root,num))
		cout<<"match found\n";
	else
		cout<<"match not found\n";
}
