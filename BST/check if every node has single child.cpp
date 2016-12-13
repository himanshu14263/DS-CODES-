// PROBLEM :: CHECK IF INTERNAL NODE HAS EXACTLY ONE CHILD

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

// NOTE :: HERE WE USED INSERT FUNCTION THAT RECEIVES REFERENCE OF ROOT NODE
// ADVANTAGE :: 1) THERE IS NO NEED OF RETURN STATEMENT
//				2) NO NEED TO MENTION ( root->left= )  OR  ( root->right= ) statements

void insert(node*&root,int data)
{
	if(root==NULL)root=newnode(data);
	if(root->data<data)insert(root->right,data);
	if(root->data>data)insert(root->left,data);
}


// BASIC LOGIC :: every node's data can either be greater than max or less than min.
//				  if it is neither of the above then it don't have single child.
bool func(int pre[],int n)
{
	int min,max;
	if(pre[n-1]<pre[n-2])
	{
		min=pre[n-1];
		max=pre[n-2];
	}
	else
	{
		max=pre[n-1];
		min=pre[n-2];
	}

	for(int i=n-3;i>=0;i--)
	{
		if(pre[i]<min)
			min=pre[i];
		else if(pre[i]>max)
			max=pre[i];
		else
			return false;
	}
	return true;
}

void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}
int main()
{
	int pre[]={20,10,11,13,12};
	int n=sizeof(pre)/sizeof(pre[0]);
	if(func(pre,n))
		cout<<"every node has single child\n";
	else
		cout<<"don't have single child\n";

}
