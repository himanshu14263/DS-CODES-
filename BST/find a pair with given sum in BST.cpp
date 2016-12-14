// PROBLEM :: FIND A PAIR WITH GIVEN SUM IN BST.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left,*right;
};

node*newnode(int data)
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
void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	cout<<root->data<<" ";
	inO(root->right);
}

void convertBSTtoDLL(node*root,node*&head,node*&tail)
{
	if(root==NULL)return;

	convertBSTtoDLL(root->left,head,tail);

	root->left=tail;
	if(!tail)
		head=root;
	else
		tail->right=root;
	tail=root;

	convertBSTtoDLL(root->right,head,tail);
}

bool findPair(node*head,node*tail,int sum )
{
	while(head!=tail)
	{
		int curr=head->data+tail->data;
		if(curr==sum)
			return true;
		else if(curr>sum)
			tail=tail->left;
		else if(curr<sum)
			head=head->right;
	}
	return false;
}
bool isPairExist(node*root,int sum)
{
	node*head,*tail;
	head=tail=NULL;

	// STEP 1 :: CONERTING BST TO DLL
	convertBSTtoDLL(root,head,tail);

	// STEP 2 :: CHECKING IF THERE EXISTS A PAIR
	return(findPair(head,tail,sum));
}

int main()
{
	node*root=NULL;
	root=insert(root,5);
	insert(root,2);
	insert(root,13);
	insert(root,11);
	insert(root,9);

	inO(root);

	int sum;
	cout<<"\nenter the sum\n";
	cin>>sum;

	if(isPairExist(root,sum))
		cout<<"pair exists\n";
	else
		cout<<"pair don't exists\n";


}
