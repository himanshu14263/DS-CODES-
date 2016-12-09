// PROBLEM :: FIND THE PREDECESSOR AND SUCCESSOR OF GIVEN NODE 'X'
// LOGIC :: there are two cases possible
//			1) the required node have left and right sub tree.
//          2) the required node doesn't have left and right sub tree.
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

// searches the required node
// keeps track of both predecessor and successor
// it stores the value of pre in case the left subtree doesn't exists
// it stores the value of succ in case the right subtree doesn't exists
node*search(node*root,int x,node*&pre,node*&succ)
{
	if(root==NULL)return root;
	if(root->data==x)return root;
	if(root->data<x)
	{
		pre=root;
		return search(root->right,x,pre,succ);
	}
	else
	{
		succ=root;
		return search(root->left,x,pre,succ);
	}
}

// searches the successor
// i.e. the left most element in the right subtree.
// if right subtree doesn't exists then it returns.
void inOsucc(node*root,node*& succ)
{
	if(root==NULL)return;
	else
	{
		node*curr=root;
		while(curr->left!=NULL)
			curr=curr->left;
		succ=curr;
	}
}

// searches the predecessor
// i.e. the right most element in the left subtree
// if left  subtree doesn't exists then it returns.
void inOpre(node*root,node*& pre)
{
	if(root==NULL)return;
	else
	{
		node*curr=root;
		while(curr->right!=NULL)
			curr=curr->right;
		pre=curr;
	}
}


// this function calculates the result from both from search() and inOpre() and inOsucc()
void findPreSucc(node*root,int x)
{

	node*pre=NULL;node*succ=NULL;

	node*curr=search(root,x,pre,succ);

	inOpre(curr->left,pre);
	inOsucc(curr->right,succ);

	if(pre)
		cout<<"predecessor :: "<<pre->data<<"\n";
	else
		cout<<"don't have predecessor\n";

	if(succ)
		cout<<"successor :: "<<succ->data<<"\n";
	else
		cout<<"don't have successor\n";
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

	node*root=NULL;
	root=insert(root,10);
	insert(root,14);
	insert(root,5);
	insert(root,3);
	insert(root,22);

	inO(root);
	cout<<"\n";

    findPreSucc(root,22);

}
