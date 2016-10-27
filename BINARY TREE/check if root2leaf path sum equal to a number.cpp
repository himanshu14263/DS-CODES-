// note:self;
// PROBLEM: root to leaf path's sum equal to a given number or not.
// TIME COMPLEXITY : - O(n^2)

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
int  pathSum(int arr[],int len,int num)
{
	int sum=accumulate(arr,arr+len,0);
	if(sum==num)
		return 1;
	else
		return 0;
}
int  findPath(node*root,int arr[],int len,int num)
{
	int ans=0;
	if(root==NULL)return 0;
	arr[len]=root->data;
	len++;
	if(root->left==NULL && root->right==NULL)
		{
			int x=pathSum(arr,len,num);
			if(x)return 1;
			else return 0;
		}
	else
	{
		ans=ans||findPath(root->left,arr,len,num);
		ans=ans||findPath(root->right,arr,len,num);
	}

	return ans;

}
int root2leaf(node*root,int num)
{
	if(root==NULL)return 0;
	int arr[555];
	int len=0;
	int ans=findPath(root,arr,len,num);
	return ans;
}


int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->right=newnode(4);
	root->left->left=newnode(5);

	int num=10;

	if(root2leaf(root,num))
		cout<<"match found\n";
	else
		cout<<"match not found\n";
}
