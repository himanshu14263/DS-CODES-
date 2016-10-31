// note:not-self;
// PROBLEM: finding all possible interpretation of an array of digits

#include <bits/stdc++.h>
using namespace std;
typedef struct node node;

//string alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string alpha[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

struct node
{
	string s;
	node*left,*right;
};
node*newnode(string data)
{
	node*n=new node;
	n->s=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// all single digits alphabets are on left subtree and two digits alphabets are on right subtree
void createTree(node*root,int arr[],int l,int h)
{
	if(l<=h)
	{
		string s=root->s+alpha[arr[l]];

		// first creating all the left nodes
		root->left=newnode(s);
		createTree(root->left,arr,l+1,h);

		if(l<h)
		{
			int x=arr[l]*10+arr[l+1];    // it can have at max two digits b/c z is 26
			if(x<=26)
			{
				string s=root->s+alpha[x];
				root->right=newnode(s);
				createTree(root->right,arr,l+2,h);
			}
		}
	}
}


void inO(node*root)
{
	if(root==NULL)return;
	inO(root->left);
	if(root->left==NULL && root->right==NULL)
		cout<<root->s<<" ";
	inO(root->right);
}

int main()
{

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	node*root=newnode("");			// necessary b/c we add next strings generated at each level to this root string only
	createTree(root,arr,0,n-1);
	inO(root);
}

