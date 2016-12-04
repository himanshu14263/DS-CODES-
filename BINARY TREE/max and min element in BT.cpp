// PROBLEM : FINDING THE MAXIMUM AND MINIMUM ELEMENT IN THE B.T.
// TIME COMPLEXITY : O(N)

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
void maxElement(node*root,int&max)
{
	if(!root)return;
	maxElement(root->left,max);
	maxElement(root->right,max);
	if(root->data>max)max=root->data;

}

void minElement(node*root,int&min)
{
	if(!root)return;
		minElement(root->left,min);
		minElement(root->right,min);
		if(root->data<min)min=root->data;
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	int max=INT_MIN,min=INT_MAX;
	maxElement(root,max);
	minElement(root,min);

	cout<<"the max element is ::"<<max;
	cout<<"\n";
	cout<<"the min element is ::"<<min;
}
