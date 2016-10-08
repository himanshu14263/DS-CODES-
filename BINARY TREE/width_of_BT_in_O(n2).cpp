#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    node*n=new  node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return(n);
}
int ht(node*root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}
int findwidth_of_lvl(node*root,int level)
{
	if(root==NULL)return 0;
	if(level==1)return 1;
	else if(level>1)
	{
		return (findwidth_of_lvl(root->left,level-1)+ findwidth_of_lvl(root->right,level-1));

	}
}
void find_max_width(node*root)
{
	int h=ht(root);
	int maxwidth=-1,width=0;
	for(int i=1;i<=h;i++)
	{
		width=findwidth_of_lvl(root,i);
		if(width>maxwidth)
			maxwidth=width;
	}
	cout<<maxwidth<<"\n";
}
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right=newNode(6);

    find_max_width(root);

    return 0;
}
