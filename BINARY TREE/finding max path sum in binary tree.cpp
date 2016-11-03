// STATEMENT: FINDING THE MAX PATH SUM IN BINARY TREE
// TIME COMPLEXITY :: O(n)

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

// use post-order traversal to reach the end
int findMaxUtil(node*root,int *ans)
{
	if(root==NULL)return 0;

	int l=findMaxUtil(root->left,ans);
	int r=findMaxUtil(root->right,ans);

	// once you reach the end of left subtree do following
	// find max of root , (root + left child) , (root + right child)
	// this result we pass to its ancestors
	int max_single=max(max(l,r)+root->data,root->data);

	// now this may be the path sum which is maximum across all the paths
	// so we find the max b/w all four possibilities
	// and store it in answer(as a result and we change it only if a path with larger sum if found)
	int max_top=max(max_single,l+r+root->data);
	// checking the temporary answer is greater than previously stored answer
	*ans=max(*ans,max_top);

	// we return to ancestors the result assuming we haven't found the real answer ( we return either only root,root+left child ,root+right child)
	return max_single;
}
void findMax(node*root)
{
	int ans;
	// variable to store answer is passed as reference
	findMaxUtil(root,&ans);
	cout<<ans<<"\n";
}
int main()
{
	node*root=newnode(10);
	root->right=newnode(10);
	root->right->right=newnode(-25);
	root->right->right->left=newnode(3);
	root->right->right->right=newnode(4);

	root->left=newnode(2);
	root->left->right=newnode(1);
	root->left->left=newnode(20);

	findMax(root);



}
