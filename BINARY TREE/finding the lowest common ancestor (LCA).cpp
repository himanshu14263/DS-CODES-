// STATEMENT:FINDING THE LOWEST COMMON ANCESTOR(LCA)
// NOTE: NOT-SELF

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left, * right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
// METHOD 1 :: RECURSIVE (SINGLE TRAVERSAL)
// NOTE :: this method assumes that both the keys are present in tree.
node*lca(node*root,int k1,int k2)
{
	if(root==NULL)return NULL;

	if(root->data==k1 || root->data==k2)	// if root's data is equal to any key then root is the lca.
		return root;

	node*left_lca=lca(root->left,k1,k2);	// searches for keys in left subtree

	node*right_lca=lca(root->right,k1,k2);	// searches for keys in right subtree

	if(left_lca && right_lca)return root;	// if both the left and right subtree contains one key each,
											// then root is the lca

	return (left_lca?left_lca : right_lca);	// checks which subtree contains the key and the one containing it,
											// is considered as temporary lca.
}




// METHOD 2 :: RECURSIVE (THREE TRAVERSAL AND EXTRA VECTORS REQUIRED FOR COMPUTATION)

// stores the found path b/w root and key
void storePath(int arr[],int n,vector<int>&vec)
{
	for(int i=0;i<=n;i++)vec.push_back(arr[i]);
}

// finds the path b/w root and key
void findPath(node*root,int arr[],int level,int key,vector<int>&vec)
{
	if(root==NULL)return;
	arr[level]=root->data;
	if(root->data==key)
	{
		storePath(arr,level,vec);
	}
	findPath(root->right,arr,level+1,key,vec);
	findPath(root->left,arr,level+1,key,vec);
}

// wrapper function to initiate the keys search in tree
// finds first mismatch in the two paths
// displays the answer
void lca2(node*root,int k1,int k2)
{
	if(root==NULL)return;

	int arr[55];
	int level=0;

	vector<int>v1,v2;

	findPath(root,arr,level,k1,v1);
	findPath(root,arr,level,k2,v2);

	int i;
	for(i=0;i<v1.size();i++)
	{
		if(v1[i]!=v2[i])
			break;
	}


	cout<<"METHOD 2 \nans is :: "<<arr[i-1];
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

	node*ans=lca(root,4,5);
	cout<<"METHOD 1\n";
	cout<<"ans is :: "<<ans->data<<"\n\n";

	lca2(root,4,5);



}
