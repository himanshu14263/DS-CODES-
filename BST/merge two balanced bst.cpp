// PROBLEM :: MERGE TWO BALANCED BSTs

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

int sizeBST(node*root)
{
	if(root==NULL)return 0;
	return (1+sizeBST(root->left)+sizeBST(root->right));
}

void bstTOarr(node*root,int arr[],int&i)
{

	if(root==NULL)return;

	bstTOarr(root->left,arr,i);

	arr[i]=root->data;

	i++;

	bstTOarr(root->right,arr,i);
}
int*mergeArr(int a[],int b[],int m,int n)
{
	int *c=new int[m+n];
	int i,j,k;
	i=j=k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;k++;
		}
		else
		{
			c[k]=b[j];
			j++;k++;
		}
	}
	if(i==m)
	{
		while(j<n)
		{
			c[k]=b[j];
			j++;k++;
		}
	}
	else
	{
		while(i<m)
		{
			c[k]=a[i];
			i++;k++;
		}
	}

	return c;
}

node*arrTObst(int a[],int strt,int end)
{
	if(strt>end)return NULL;

	int md=(strt+end)/2;
	node*n=newnode(a[md]);
	n->left=arrTObst(a,strt,md-1);
	n->right=arrTObst(a,md+1,end);
	return n;
}
node* mergeBSTs(node*root1,node*root2)
{
	// find the size of two trees
	int m=sizeBST(root1);
	int n=sizeBST(root2);

	int*a=new int[m];
	int*b=new int[n];

	// convert both bst to array
	int i=0;
	bstTOarr(root1,a,i);
	i=0;
	bstTOarr(root2,b,i);

	// merge these two formed array
	int*mergedArray=mergeArr(a,b,m,n);

	// form new tree from this merged array
	node*mergeTREE = arrTObst(mergedArray,0,m+n-1);

	return mergeTREE;

}
void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}


void preO(node*root)
{
	if(root==NULL)return;
	cout<<root->data<<" ";
	preO(root->left);
	preO(root->right);
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

	node*root2=NULL;
	root2=insert(root2,8);
	insert(root2,3);
	insert(root2,2);
	insert(root2,11);

	node*mergedTree=mergeBSTs(root1,root2);

	cout<<"inorder of merged tree :: ";
	inO(mergedTree);

	cout<<"\n";

	cout<<"inorder of merged tree :: ";
	preO(mergedTree);



}
