// PROBLEM :: COUNT THE NUMBER OF SUBTREE THAT LIE IN THE GIVEN RANGE
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

node*insert(node*root,int data)
{
	if(root==NULL)return newnode(data);
	if(root->data<data)root->right=insert(root->right,data);
	if(root->data>data)root->left=insert(root->left,data);
	return root;
}

// instead of checking subtrees of every node which have time complexity of O(m*n)
// we use bottom up technique
// we traverse in post-order manner keep checking if left or right subtree is in range or not
// thus we don't have to check same node again and again
bool func(node*root,int&count,int min,int max)
{
	if(root==NULL)return true;
	int l=func(root->left,count,min,max);
	int r=func(root->right,count,min,max);
	if(l && r && (root->data<=max && root->data>=min))
	{
		count++;
		return true;
	}
	return false;
}
int main()
{
	node*root=NULL;
	root=insert(root,10);
	insert(root,5);
	insert(root,1);
	insert(root,50);
	insert(root,40);
	insert(root,100);

	int count=0;
	int min,max;
	cout<<"enter the range \n";
	cin>>min>>max;
	func(root,count,min,max);
	cout<<count<<"\n";
}
