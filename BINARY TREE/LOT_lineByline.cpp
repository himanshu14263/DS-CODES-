// printing level order traversal line by line;;
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
/////////////////  METHOD 2 WITH TIME COMPLEXITY OF O(n) ////////////////////////
void printingLevelOrder(node*root)
{
	queue<pair<node*,int> >Q;
	Q.push(make_pair(root,0));
	while(!Q.empty()){
		pair<node*,int>temp=Q.front();
		Q.pop();
		if(Q.front().second==temp.second && !Q.empty())cout<<temp.first->data<<" ";
		else cout<<temp.first->data<<"\n";
		if(temp.first->left)Q.push(make_pair(temp.first->left,temp.second+1));
		if(temp.first->right)Q.push(make_pair(temp.first->right,temp.second+1));
	}
}

/////////////  MEHTOD 1 WITH TIME COMPLEXITY OF O(n^2) //////////////////////////
int ht(node*tree)
{
	if(tree==NULL)return 0;
	return 1+(max(ht(tree->left),ht(tree->right)));
}
void printlevel(node*tree,int level)
{
	if(tree==NULL)return;
	if(level==1){
		cout<<tree->data<<" ";return;
	}
	printlevel(tree->left,level-1);
	printlevel(tree->right,level-1);
}
void levelOrder(node*tree)
{
	int h=ht(tree);
	for(int i=1;i<=h;i++)
	{
		printlevel(tree,i);
		cout<<"\n";
	}
}
int main()
{
	node*tree=newnode(1);
	tree->left=newnode(2);
	tree->left->left=newnode(4);
	tree->left->right=newnode(5);
	tree->right=newnode(3);
	tree->right->left=newnode(6);
	tree->right->right=newnode(7);

	cout<<"printing by METHOD 1\n";
	levelOrder(tree);

	cout<<"\n";
	cout<<"printing by METHOD 2\n";
	printingLevelOrder(tree);




}
