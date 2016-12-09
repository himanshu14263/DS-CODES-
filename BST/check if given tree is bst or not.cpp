// PROBLEM :: CHECK IF GIVEN TREE IS BST OR NOT

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
};
node*newnode(int val)
{
	node*n=new node;
	n->left=n->right=NULL;
	n->data=val;
	return n;
}
node* insert(node*root,int val)
{
	if(root==NULL)return newnode(val);
	if(root->data<val)
		root->right=insert(root->right,val);
	if(root->data>val)
		root->left=insert(root->left,val);
	return root;
}

// METHOD 1 :: USING CORRECT AND EFFICIENT METHOD
// concept ::	use min/max constraint
bool checkUtil(node*root,int min,int max)
{
	// empty tree is considered as bst
	if(root==NULL)return true;

	// it must satisfy the min/max constraint, if not then return false
	if(root->data<min || root->data>max)
		return false;

	// consecutively check the left and right sub tree.
	return (checkUtil(root->left,min,root->data-1) && checkUtil(root->right,root->data+1,max));
}

bool check(node*root)
{
	return checkUtil(root,INT_MIN,INT_MAX);
}



// METHOD 2 :: USING INORDER TRAVERSAL
// concept :: if we traverse tree in inorder than it will be sorted
//			  thus next node's data will always be greater than previous node's data.
void inOcheck(node*root,node*&prev,bool& ans)
{
	if(root==NULL)return;
	else
	{
		// visiting the left subtree
		inOcheck(root->left,prev,ans);

		// checking if current node data is greater than previous or not
		if(prev!=NULL && (root->data<=prev->data))
			ans=false;

		// storing the previous node data
		prev=root;

		// visiting the right tree
		inOcheck(root->right,prev,ans);
	}
}
int main()
{

	// TREE 1
	node*root=NULL;
	root=insert(root,10);
	insert(root,14);
	insert(root,5);
	insert(root,3);
	insert(root,22);


	// TREE 2
	node*root2=newnode(5);
	root2->left=newnode(3);
	root2->right=newnode(10);
	root2->left->left=newnode(2);
	root2->left->right=newnode(6);
	root2->right->right=newnode(90);
	root2->right->left=newnode(8);


	// checking tree2 using method 2
	bool ans=true;
	node*prev=NULL;
	inOcheck(root2,prev,ans);
	if(ans)cout<<"is bst\n";
	else cout<<"not bst\n";


	// checking tree1 using method 1
	if(check(root))
		cout<<"is bst\n";
	else
		cout<<"isn't bst\n";

}
