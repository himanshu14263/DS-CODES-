// PRINTING ALL THE PATHS FROM ROOT TO LEAF IN SEPARATE LINES
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
typedef struct node node;
node* newnode(int data)						//creating nodes
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
void printArr(int a[],int s)				//printing array based on given length
{
	for(int i=0;i<s;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
void func(node*root,int arr[],int len)		//recursive function just like preorder traversal.
											//it stores the data of each node in the array
											//when leaf node is reached it prints
{
	if(root==NULL)return;
	arr[len]=root->data;
	len++;
	if(root->left==NULL && root->right==NULL)
		printArr(arr,len);
	else
	{
		func(root->left,arr,len);
		func(root->right,arr,len);
	}
}

void printRoot2Leaf(node*root)				//helping function to instantiate array and length variable
{
	int arr[100];
	int len=0;
	func(root,arr,len);
}
int main()
{
	// creating the tree
	node*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	//calling the function
	printRoot2Leaf(root);
}

