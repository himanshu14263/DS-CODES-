// PROBLEM: GIVEN A TREE PRINT ITS TOP VIEW
// DONE BY: SELF
// TIME COMPLEXITY REQUIRED: O(n)
// CODE'S TIME COMPLEXITY : O(n^2)
// SOLVED IN TIME COMPLEXITY: O(n) but it can be reduced to O(n) by reducing L.O.T. to O(n) OR use queue for lot ;
// solution: a simple level order traversal + map to store top most node at the horizontal distance x +
//			 the concept used for vertical order traversal(i.e. mark root=x ; root->left=x-1 ; root->right=x+1)
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// finds height to use in LOT
int ht(node*root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}

// print the nodes of particular level and the top most node at horizontal distance x
void func(node*root,int h,int x,map<int ,int >&mp)
{
	if(root==NULL)return;
	// here first we check if we reach the required level or not
	// second we check using find function that :: whether current key 'x' already exist in the map or not
	// if it exits then we do nothing
	// but if it doesn't exists then we add new key value pair
	if((h==1) && (mp.find(x)==mp.end()))
		{
			mp[x]=root->data;			// new key value pair is added
		}
	func(root->left,h-1,x-1,mp);
	func(root->right,h-1,x+1,mp);
}

// initiator function of L.O.T. and ACCESS  every level,one by one
void lot(node*root)
{
	int h=ht(root);
	map<int ,int >mp;
	for(int i=1;i<=h;i++)
		{
			func(root,i,0,mp);
		}

	// PRINTING ALL THE TOP VIEW NODES STORED IN MAP
	map<int ,int >::iterator it=mp.begin();
	for(;it!=mp.end();++it)
		cout<<(*it).second<<" ";
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
