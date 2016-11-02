// STATEMENT: CHECK IF ALL THE LEAF ARE AT SAME LEVEL
// NOTE: SELF

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

// my method : recursion + using an extra array to check whether the levels are equal or not

// recursive function to store leaf nodes level in array
void f2(node*root,int arr[],int*indx,int level)
{
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)
	{
		arr[*indx]=level;
		(*indx)++;
	}
	f2(root->left,arr,indx,level+1);
	f2(root->right,arr,indx,level+1);
}

// checking levels of leaf nodes
bool check(int arr[],int n)
{
	cout<<"leaves are present at levels :: ";
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=arr[i+1])
			return false;
	}
	return true;
}

// utility function to initiate the checking
void f1(node*root)
{
	if(root==NULL)return;
	int arr[44];
	int indx=0;
	int level=1;
	f2(root,arr,&indx,level);

	check(arr,indx)?cout<<"So ans is :: yes\n":cout<<"So ans is :: no\n";
}


// METHOD 2 : NOT MINE(USING ONLY RECURSION)

// single recursive function to check level of all leaf nodes
bool checkUtil(node*root,int level,int *leafLevel)
{
	if(root==NULL)return true;
	if(root->left==NULL && root->right==NULL)
	{
		// if this is first leaf node
		if(*leafLevel==0)
		{
			*leafLevel=level;
			return true;
		}
		// if it is not the first leaf node
		return (level==*leafLevel);
	}

	//checking for leaf nodes in left and right sub tree

	return (checkUtil(root->left,level+1,leafLevel) && checkUtil(root->right,level+1,leafLevel));
}

// a helper function to initiate the checking of leaf nodes
bool check(node*root)
{
	int level=0,leafLevel=0;
	return checkUtil(root,level,&leafLevel);
}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	root->right->left->right=newnode(7);
	root->right->left->right->left=newnode(9);
	root->right->right->right=newnode(8);
	root->right->right->right->right=newnode(10);
	root->right->right->right->right->left=newnode(11);

	cout<<"METHOD 1 \n \n";

	f1(root);


	cout<<"\n\nMETHOD 2 ANSWER :: "
			"";
	if(check(root))
		cout<<"yes \n";
	else
		cout<<"no \n";
}
