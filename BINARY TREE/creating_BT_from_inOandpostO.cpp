#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}
int n;
int pIndex=n-1;
Node* buildTree(int in[], int post[], int inStrt,int inEnd)
{
    if (inStrt > inEnd)
        return NULL;
    Node *node = newNode(post[pIndex]);
    (pIndex)--;
    if (inStrt == inEnd)
        return node;
    int iIndex = search(in, inStrt, inEnd, node->data);
    node->right= buildTree(in, post, iIndex+1, inEnd);
    node->left = buildTree(in, post, inStrt, iIndex-1);

    return node;
}
void inO(Node* node)
{
    if (node == NULL) return;
    inO(node->left);
    cout<<node->data<<" ";
    inO(node->right);
}
int main()
{
	cin>>n;
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    Node *root = buildTree(in, post,0,n-1);
    cout  << "Preorder of the constructed tree : \n";
    inO(root);
    return 0;
}
