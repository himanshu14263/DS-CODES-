// PROBLEM : MAXIMUM PATH SUM BETWEEN TWO LEAF NODES
// TIME COMPLEXITY : O(N)
// NOTE : TAKE REFERENCE OF LONGEST PATH IN BT PROBLEM

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

int maxPathUtil(node*root,int &res)
{
	if(root==NULL)return 0;
	//if(!root->left && !root->right) return root->data;			// this isn't necessary condition
																	// last line of this function take care of this condition.

	// calculating the max path for left sub tree
	int ls=maxPathUtil(root->left,res);

	// calculating the max path for right sub tree
	int rs=maxPathUtil(root->right,res);

	// here we store the intermediate result only if the root has leaf nodes.
	if(root->left && root->right)
	{
		res=max(res,ls+rs+root->data);		// here result is modified only if root have leaf nodes
											// here temporary result is stored which can be the main answer and it is changed only
											// if we find any other path which is greater than this answer.

		return max(ls,rs)+root->data;		// but for returning to previous level node, we return only the largest sub tree value.
											// because only one of the leaf node can be in the answer.
	}

	// if one of the leaf node is not present then we return the other leaf node + root's data;
	// NOTE : THIS CONDITION ALSO TAKE CARE OF THE CASE WHEN ROOT DON'T HAVE LEFT AND RIGHT CHILD
	//        WE CAN ADD IT EXIPLICITLY ALSO AFTER FIRST LINE OF THIS FUNCTION
	//        if(!root->left && !root->right) return root->data;
	return (!root->left)? rs+root->data : ls+root->data;
}

int maxPath(node*root)
{
	int res=INT_MIN;		// we pass this variable by reference which store the final answer
	maxPathUtil(root,res);
	return res;
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

	// this function return INT_MIN if there aren't two leaf nodes present
	if(maxPath(root)==INT_MIN)
		cout<<"the there aren't two leaf nodes\n";
	else
		cout<<"the max distance b/w leaf nodes is :: "<<maxPath(root);
}
