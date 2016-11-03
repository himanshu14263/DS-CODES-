// STATEMENT:PRINTING ALL THE NODES AT A DISTANCE K FROM LEAF NODES
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

// METHOD 1 :: MY WAY USING RECURSION (used node to leaf path finding method + additional set to store and display unique result)

// finds and store the answer in the set container
void func(node*root,int arr[],int level,int k,set<int>&s)
{
	if(root==NULL)return;
	arr[level]=root->data;
	if(!root->left && !root->right)
	{
		if(level-k>=0)
		{
			s.insert(arr[level-k]);
		}
	}
	func(root->left,arr,level+1,k,s);
	func(root->right,arr,level+1,k,s);
}

void wrapper(node*root,int k)
{
	int arr[44];
	int level=0;

	set<int>s;	// to remove the duplicate values

	func(root,arr,level,k,s);

	// displaying the result
	set<int>::iterator it=s.begin();
	while(it!=s.end())
	{
		cout<<*it<<" ";
		++it;
	}

}


// METHOD 2 :: OTHER'S APPROACH (TIME COMPLEXITY: O(n))

// a simple approach using concept same as root to leaf path finding.
// but with a bit of modification we print a particular value instead of entire path
// we use visited array to keep record of visited nodes
void nodeFromLeafUtil(node*root,int arr[],int level,int k,bool visited[])
{
	if(root==NULL)return;

	arr[level]=root->data;
	visited[level]=false;		// KIM :: A VERY IMPORTANT CONDITION TO REMOVE THE DUPLICATES AND
								//        ALLOWS YOU TO PRINT ALL THE RESULTS ON A PARTICULAR LEVEL.

	if(!root->left && !root->right)
	{
		// it should be within range and it should not be already visited.
		if(level-k>=0 && !visited[level-k])
		{
			cout<<arr[level-k]<<" ";
			visited[level-k]=1;
			return;
		}
	}

	nodeFromLeafUtil(root->left,arr,level+1,k,visited);
	nodeFromLeafUtil(root->right,arr,level+1,k,visited);
}

void nodeFromLeaf(node*root,int k)
{
	int arr[44];
	int level=0;
	bool visited[44]={0};
	nodeFromLeafUtil(root,arr,level,k,visited);


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
	root->right->left->right=newnode(8);

	cout<<"other's method :: ";nodeFromLeaf(root,1);
	cout<<"\n\nmy method :: ";wrapper(root,1);


}
