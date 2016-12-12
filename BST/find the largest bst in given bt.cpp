//PROBLEM :: CREATE THE BST FROM GIVEN SORTED ARRAY

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left=NULL;
	node*right=NULL;
};
node*newnode(int data)
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

bool check(node*root,int min,int max)
{
	if(root==NULL)return true;
	if(root->data>max || root->data<min)
		return false;
	return (check(root->left,min,root->data-1) && check(root->right,root->data+1,max));
}
void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

int sizeBT(node*root)
{
	if(root==NULL)return 0;
	return (1+sizeBT(root->left)+sizeBT(root->right));
}

// this function uses preorder traversal and checks two condition for every node in the tree
// 1) if that node is root of bst or not
// 2) if the size of this new found bst is greater than previously stored answer.
void btTrav(node*root,node*&ans,int&size)
{
	if(root==NULL)return;
	bool isbt=check(root,INT_MIN,INT_MAX);		// checking if the root is bst or not
	int s=sizeBT(root);							// finding the size of this new bst
	if(isbt && s>size)							// checking if it is bst and it's size is greater than previous answer
	{
		ans=root;
		size=s;
	}
	btTrav(root->left,ans,size);		// traversing the left subtree
	btTrav(root->right,ans,size);		// traversing the right subtree
}
int main()
{
	node*root=newnode(50);
	root->left=newnode(30);
	root->right=newnode(60);
	root->left->left=newnode(5);
	root->left->right=newnode(35);
	root->right->left=newnode(45);
	root->right->right=newnode(70);
	root->right->right->left=newnode(65);
	root->right->right->right=newnode(80);


	inO(root);

	node*ans;
	int size=INT_MIN;
	btTrav(root,ans,size);

	cout<<"\nthe root of largest bst is :: "<<ans->data<<"\n";
	cout<<"the size of largest bst is :: "<<size<<"\n";
	cout<<"the inO of largest bst is :: ";inO(ans);

}
