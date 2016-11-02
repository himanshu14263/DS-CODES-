// STATEMENT: SUM OF ALL NUMBER FORMED BY ROOT TO LEAF PATH
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

// METHOD 1: MY APPROACH TO FIND THE ANSWER

//vector to store final answer
vector<int>ans;

// calculates the number formed from all the paths
void printPath(int arr[],int n)
{
	int temp=0;
	for(int i=0;i<=n;i++)
	{
		cout<<arr[i]<<" ";
		temp=temp*10+arr[i];
	}
	ans.push_back(temp);
}
// find path from root to leaf
void func2(node*root,int arr[],int level)
{
	if(root==NULL)return;
	arr[level]=root->data;
	if(root->left==NULL && root->right==NULL)
	{
		printPath(arr,level);
		cout<<"\n";
	}
	func2(root->left,arr,level+1);
	func2(root->right,arr,level+1);
}

// wrapper function to initiate the path search and display the final solution
void func(node*root)
{
	int arr[44];
	int level=0;
	cout<<"printing all root to leaf path :: \n";
	func2(root,arr,level);
	cout<<"\n";
	cout<<"printing all number formed from such paths ::\n";
	vector<int>::iterator it=ans.begin();
	for(;it!=ans.end();it++)
		cout<<*it<<" ";
	cout<<"\n";
	cout<<"\n";
	cout<<"printing sum of all such numbers :: ";
	cout<<accumulate(ans.begin(),ans.end(),0);
}

// METHOD 2: USING PREORDER TRAVERSAL TO FIND THE ANSWER
int  method2(node*root,int val)
{
	if(root==NULL)return 0;
	val=val*10+root->data;
	if(!root->left && !root->right)return val;
	return (method2(root->left,val)+method2(root->right,val));
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

	func(root);


	cout<<"\n";
	cout<<method2(root,0);



}
