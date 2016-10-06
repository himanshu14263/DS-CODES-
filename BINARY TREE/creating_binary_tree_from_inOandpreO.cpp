//CREATING TREE WHEN INORDER AND PREORDER OF A TREE ARE GIVEN.
#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node*left,*right;
};
node*newnode(char data)
{
	node*n=new node();
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
int findin(char*in,int strt ,int end,char ch)
{
	for(int i=strt;i<=end;i++)
	{
		if(in[i]==ch)return i;
	}
	return -1;
}
int preindx=0;
node*buildtree(char *in,char * pre,int instrt,int inend)
{
	if(instrt>inend)return NULL;
	node*tnode=newnode(pre[preindx]);
	preindx++;
	if(instrt==inend)return tnode;
	int indx=findin(in,instrt,inend,tnode->data);
	tnode->left=buildtree(in,pre,instrt,indx-1);
	tnode->right=buildtree(in,pre,indx+1,inend);

	return tnode;
}
void inO(node*tree)
{
	if(tree==NULL)return;
	inO(tree->left);
	cout<<(tree->data)<<" ";
	inO(tree->right);
}
int main()
{
	char in[100],pre[100];
	cout<<"enter the number of nodes\n";
	int n;
	cin>>n;
	cout<<"enter ino and preo\n";

	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<n;i++)
		cin>>pre[i];

	node*root=buildtree(in,pre,0,n-1);
	cout<<"THE INORDER OF THE TREE IS:= ";
	inO(root);

}

/*
 * INPUT  : D B E A F C
 * 		  : A B D E C F
 * OUTPUT : D B E A F C
 */
