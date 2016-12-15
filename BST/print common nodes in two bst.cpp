// PROBLEM :: PRINT COMMON NODE'S IN TWO BSTs

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=n->right=NULL;
	return n;
}

node*insert(node*root,int data)
{
	if(root==NULL)return newnode(data);
	if(root->data<data)root->right=insert(root->right,data);
	if(root->data>data)root->left=insert(root->left,data);
	return root;
}
void bstTOarr(node*root,int arr[],int& i)
{
	if(root==NULL)return;
	bstTOarr(root->left,arr,i);
	arr[i]=root->data;
	i++;
	bstTOarr(root->right,arr,i);
}
int sizeBST(node*root)
{
	if(root==NULL)return 0;
	return(1+sizeBST(root->left)+sizeBST(root->right));
}
void printCommon(node*root1,node*root2)
{
	int m=sizeBST(root1);
	int n=sizeBST(root2);

	int*a=new int[m];
	int*b=new int[n];

	int k=0;
	bstTOarr(root1,a,k);
	k=0;
	bstTOarr(root2,b,k);

	// FINDING THE INTERSECION OF TWO ARRAY WITH TIME COMPLEXITY :: O(m+n)
	cout<<"the intersection of two BST is :: ";
	int i,j;
	i=j=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
			i++;
		else if(a[i]>b[j])
			j++;
		else
		{
			cout<<a[i]<<" ";
			i++;j++;
		}
	}
}
void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}
int main()
{
	node*root1=NULL;
	root1=insert(root1,5);
	insert(root1,1);
	insert(root1,0);
	insert(root1,4);
	insert(root1,10);
	insert(root1,7);
	insert(root1,9);

	inO(root1);cout<<"\n";

	node*root2=NULL;
	root2=insert(root2,10);
	root2=insert(root2,7);
	root2=insert(root2,20);
	root2=insert(root2,4);
	root2=insert(root2,9);

	inO(root2);cout<<"\n";

	printCommon(root1,root2);


}
