// PROBLEM :: CHECK IF INTERNAL NODE HAS EXACTLY ONE CHILD

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

// NOTE :: HERE WE USED INSERT FUNCTION THAT RECEIVES REFERENCE OF ROOT NODE
// ADVANTAGE :: 1) THERE IS NO NEED OF RETURN STATEMENT
//				2) NO NEED TO MENTION ( root->left= )  OR  ( root->right= ) statements

void insert(node*&root,int data){

	if(root==NULL)root=newnode(data);
	if(root->data<data)insert(root->right,data);
	if(root->data>data)insert(root->left,data);
}


// CONVERTING BST TO DOUBLE LINK LIST
// doing inorder traversal and converting

void convertBSTtoDLL(node*root,node*&head,node*&tail){

	if(root==NULL)return;

	if(root->left)convertBSTtoDLL(root->left,head,tail);

	root->left=tail;
	if(tail)
		(tail)->right=root;
	else
		head=root;

	tail=root;

	if(root->right)convertBSTtoDLL(root->right,head,tail);
}

// CHECKING IF A PAIR EXISTS IN DLL WHOSE SUM IS EQUAL TO GIVEN SUM
bool isPairExist(node*head,node*tail,int sum){

	while(head!=tail)
	{
		int temp=head->data+tail->data;
		if(temp==sum)
			return true;
		if(temp<sum)
			head=head->right;
		else
			tail=tail->left;
	}
	return false;
}

// MAIN FUNCTION THAT RETURNS TRUE IF TRIPLET EXISTS OTHERWISE RETURNS FALSE
bool isTripletExist(node*root){
	node*head=NULL;
	node*tail=NULL;

	// first convert bst to dll
	convertBSTtoDLL(root,head,tail);

	// for each node in the dll check if there exists a pair whose sum is equal to the negative of
	// current node's data.
	while((head!=tail) && (head->data<0))
	{
		if(isPairExist(head,tail,-1*head->data))
			return true;
		else
			head=head->right;
	}
	return false;
}
int main()
{
		node* root = NULL;
	    insert(root, 6);
	    insert(root, -13);
	    insert(root, 14);
	    insert(root, -8);
	    insert(root, 15);
	    insert(root, 13);
	    insert(root, 7);

	    if(isTripletExist(root))
	    	cout<<"triplet exists\n";
	    else
	    	cout<<"triplet doesn't exists\n";

}
