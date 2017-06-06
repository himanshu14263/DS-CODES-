#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	node*left,*right;
	int height;
};

int ht(node*root)
{
	if(root==NULL)return 0;
	return root->height;
}

node* newNode(int key)
{
	node* n = new node;
	n->key=key;
	n->left = n->right =NULL;
	n->height=1;

	return n;
}

node*inOSuccessor(node*root){

	while(root->left != NULL)
	{
		root=root->left;
	}
	return root;
}

int getBalance(node*root)
{
	if(root==NULL)
		return 0;

	return ht(root->left)-ht(root->right);
}

node*rotateRight(node*root)
{
	if(root==NULL)return root;

	node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->height = 1 + max(ht(root->left),ht(root->right));
	newRoot->height = 1 + max(ht(newRoot->left),ht(newRoot->right));

	return newRoot;
}

node*rotateLeft(node*root)
{
	if(root==NULL)return root;

		node* newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;

		root->height = 1 + max(ht(root->left),ht(root->right));
		newRoot->height = 1 + max(ht(newRoot->left),ht(newRoot->right));

		return newRoot;
}

node*insert(node*root,int key)
{
	if(root==NULL) return newNode(key);
	else if(key<root->key)root->left = insert(root->left,key);
	else if(key>root->key)root->right = insert(root->right,key);
	else return root;

	root->height = 1+max(ht(root->left),ht(root->right));
	int balance = getBalance(root);

	// LL
	if(balance > 1  &&  key<root->left->key)
	{
		return rotateRight(root);
	}

	// LR
	if(balance>1 && key>root->left->key)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	// RR
	if(balance<-1 && key>root->right->key)
	{
			return rotateLeft(root);
	}

	// RL
	if(balance<-1 && key<root->right->key)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}

node* deleteNode(node*root,int key)
{
	if(root == NULL)return root;

	if(key<root->key)
		root->left = deleteNode(root->left,key);

	else if(key>root->key)
		root->right = deleteNode(root->right,key);

	// if the key is matched i.e. node to be deleted is found
	else
	{
		// if node has only one child

				 // if it has only one left child
				 if(root->right == NULL)
				 {
					 node*temp = root->left;
					 free(root);
					 return temp;
				 }

				 // if it has only one right child
				 if(root->left == NULL)
				 {
					 node*temp = root->right;
					 free(root);
					 return temp;
				 }

		// if node has both child

				 node*temp = inOSuccessor(root->right);
				 root->key = temp->key;
				 root->right = deleteNode(root->right,temp->key);
	}

	if(root == NULL)return root;

	root->height = 1 + max(ht(root->left),ht(root->right));

	int balance = getBalance(root);

	// LL
	if(balance>1 && getBalance(root)>=0)
	{
		return rotateRight(root);
	}

	// LR
	if(balance>1 && getBalance(root)<0)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	// RR
	if(balance<-1 && getBalance(root)<=0)
	{
		return rotateLeft(root);
	}

	// RL
	if(balance<-1 && getBalance>0)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}

void preO(node*root)
{
	if(root==NULL)
		return;

	cout<<root->key<<" ";
	preO(root->left);
	preO(root->right);
}
int main()
{
	node*root=NULL;

	int arr[] = {10,20,30,40,50,25};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		root = insert(root,arr[i]);

	preO(root);

	cout<<"\n";

	deleteNode(root,30);

	preO(root);

}
