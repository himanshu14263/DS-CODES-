// note:self;
// PROBLEM: from sum of all root to leaf paths finding the maximum one and displaying the nodes in that path.
// TIME COMPLEXITY : - O(N)

#include <bits/stdc++.h>
using namespace std;
typedef struct node node;

struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

int ans[55],len;		// final answer containing array and its len declared globally so that in any recursion cycle final answer could be stored.

// this function stores final answer array
void storeArr(int temp[],int l)
{
	len=l;
	for(int i=0;i<l;i++)
		ans[i]=temp[i];
}

// used to find the sum of the array
int calcSum(int arr[],int l)
{
	return accumulate(arr,arr+l,0);
}


int maxVal=-1;

// this function finds the max value and store the path having max sum;
void utilRoot2Leaf(node*root,int arr[],int l)
{

	if(root==NULL)return;
	arr[l]=root->data;
	l++;
	if(root->left==NULL && root->right==NULL)
	{
		int x=calcSum(arr,l);
		if(x>maxVal)
			{
				maxVal=x;
				storeArr(arr,l);
			}
	}
	utilRoot2Leaf(root->left,arr,l);
	utilRoot2Leaf(root->right,arr,l);
}

// initial function to make declaration of elements needed further like arr[] etc;
void root2leaf(node*root)
{
	if(root==NULL)return;
	int arr[55];
	int l=0;
	utilRoot2Leaf(root,arr,l);

	cout<<"nodes in the path are : ";
	for(int i=0;i<len;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
	cout<<"max value of sum path is : "<<maxVal<<"\n";

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

	root2leaf(root);

}
