// PROBLEM :: FIND COUNT OF NODES IN THE GIVEN RANGE

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

// moving in the bst based on the range
// if current node's data is less than min than we go to right subtree of current node.
// if current node's data is greater than max than we go to left subtree of current node.

void countINrange(node*root,int min,int max,int&count)
{
	if(root==NULL)return;
	if(root->data>max)countINrange(root->left,min,max,count);
	else if(root->data<min)countINrange(root->right,min,max,count);
	else
	{
		count++;
		countINrange(root->left,min,max,count);
		countINrange(root->right,min,max,count);
	}
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
	node*root1=NULL;
	root1=insert(root1,5);
	insert(root1,1);
	insert(root1,0);
	insert(root1,4);
	insert(root1,10);
	insert(root1,7);
	insert(root1,9);

	inO(root1);
	cout<<"\n";

	int min,max;
	cout<<"enter the range\n";
	cin>>min>>max;
	int count=0;
	countINrange(root1,min,max,count);
	cout<<count;


}
