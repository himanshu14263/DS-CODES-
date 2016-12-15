// PROBLEM :: CONVERTING BT TO BST AND KEEPING THE ORIGINAL STRUCTURE

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

int sizeOfBT(node*root)
{
	if(root==NULL)return 0;
	return(1+sizeOfBT(root->left)+sizeOfBT(root->right));
}
void btToArr(node*root,int arr[])
{
	static int i=0;
	if(root==NULL)return;
	btToArr(root->left,arr);
	arr[i]=root->data;
	i++;
	btToArr(root->right,arr);

}
void putVal(node*root,int arr[])
{
	if(root==NULL)return;
	static int i=0;
	putVal(root->left,arr);
	root->data=arr[i];
	i++;
	putVal(root->right,arr);
}
void convertBTtoBST(node*root)
{
	if(root==NULL)return;

	int n=sizeOfBT(root);

	// 3 steps are involved to convert the bt to bst :-
	// 1) convert bt to array
	int *arr=new int[n];
	btToArr(root,arr);

	// 2) sort this array
	sort(arr,arr+n);

	// 3) put array values in the tree
	putVal(root,arr);
}

void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

void preO(node*root)
{
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preO(root->left);
	preO(root->right);
}
int main()
{
	node*root=newnode(10);
	root->left=newnode(2);
	root->left->left=newnode(8);
	root->left->right=newnode(4);
	root->right=newnode(7);

	inO(root);cout<<"\n";
	convertBTtoBST(root);
	cout<<"the inorder of new tree :: ";inO(root);cout<<"\n";

	// preO verifies that the sturcture remains the same
	cout<<"the preorder of new tree :: ";preO(root);




}
