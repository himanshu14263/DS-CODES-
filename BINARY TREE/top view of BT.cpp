// PROBLEM: GIVEN A TREE PRINT ITS TOP VIEW
// DONE BY: SELF
// TIME COMPLEXITY REQUIRED: O(n)
// SOLVED IN TIME COMPLEXITY: O(n) but it can be reduced to O(n) by reducing lot to O(n) OR use queue for lot ;
// solution: a simple level order traversal + a flag array to print only the top most node at the horizontal distance x +
//			 the concept used for vertical order traversal(i.e. mark root=x ; root->left=x-1 ; root->right=x+1)
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

int arr[500];	// flag array

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// finds height to use in lot
int ht(node*root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}

// print the nodes of particular level and the top most node at horizontal distance x
void func(node*root,int h,int x)
{
	if(root==NULL)return;
	if(h==1 && !arr[x])
		{
			cout<<root->data<<" ";
			arr[x]=1;
		}
	func(root->left,h-1,x-1);
	func(root->right,h-1,x+1);
}

// initiator function of lot and prints every level,one by one
void lot(node*root)
{
	memset(arr,0,sizeof(arr));
	int x=50;		// it can be any number for index of the array
	int h=ht(root);
	for(int i=1;i<=h;i++)
		{
			func(root,i,x);
		}
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->right=newnode(4);
	root->left->right->right=newnode(5);
	root->left->right->right->right=newnode(6);
	root->left->right->right->right->right=newnode(7);
	root->right=newnode(3);
	cout<<"THE TOP VIEW OF THE GIVEN TREE IS: \n";
	lot(root);

}
