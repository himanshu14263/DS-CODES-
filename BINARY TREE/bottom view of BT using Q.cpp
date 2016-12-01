// PROBLEM : printing the bottom view BT
// TIME COMPLEXITY :  O(n)
// SELF
// NOTE :: VERIFIED WAY TO PRINT THE BOTTOM VIEW OF BT
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};
node* newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void func(node*root)
{
	queue<pair<node*,int> >q;
	map<int,int>mp;
	q.push(make_pair(root,0));
	mp[0]=root->data;
	while(!q.empty())
	{
		pair<node*,int> temp=q.front();
		mp[temp.second]=temp.first->data;
		q.pop();
		if(temp.first->left!=NULL)q.push(make_pair(temp.first->left,temp.second-1));
		if(temp.first->right!=NULL)q.push(make_pair(temp.first->right,temp.second+1));
	}


	cout<<"printing from map using iterator :: ";
	// printing from map : method 1
	map<int,int>::iterator it=mp.begin();
	for(;it!=mp.end();it++)
	{
		cout<<(*it).second<<" ";
	}

	cout<<"\n";


	cout<<"printing from map using direct access [] :: ";

	// printing from map : method 2 (BUT ONLY POSSIBLE IF YOU KNOW THE KEY VALUES)

	for(int i=-2;i<=2;i++)
		cout<<mp[i]<<" ";

}
int main()
{
	node*root=newnode(20);
	root->left=newnode(8);
	root->left->left=newnode(5);
	root->left->right=newnode(3);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	root->right=newnode(22);
	root->right->right=newnode(25);
	root->right->left=newnode(4);
	func(root);
}
