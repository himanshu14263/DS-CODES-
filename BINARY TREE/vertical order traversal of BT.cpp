// PROBLEM : TO VERTICAL ORDER TRAVERSAL OF BT
// SELF
// TIME COMPLEXITY : O(n)
// use of map : mapping is done with integer to vector of nodes
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*left;
	node*right;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void VOT(node*root)
{
	queue<pair<node*,int> >q;

	// here horizontal distance is the "key" value and we use vector to store multiple node value
	// we use vector b/c one key can correspond to multiple nodes
	map<int,vector<int> >mp;
	q.push(make_pair(root,0));

	// simple level order traversal type use of concept
	// pushing  its horizontal distance and node
	while(!q.empty())
	{
		pair<node*,int>temp=q.front();
		q.pop();

		mp[temp.second].push_back(temp.first->data);	// pushing each node to corresponding horizontal distance

		if(temp.first->left)q.push(make_pair(temp.first->left,temp.second-1));
		if(temp.first->right)q.push(make_pair(temp.first->right,temp.second+1));
	}

	map<int,vector<int> >::iterator it=mp.begin();

	// printing the values of the map
	// two loops are used thus it makes the complexity : O(n^2)
	for(;it!=mp.end();++it)
	{
		vector<int>v=(*it).second;
		vector<int>::iterator it2=v.begin();
		for(;it2!=v.end();++it2)
		{
			cout<<*it2<<" ";
		}
		cout<<"\n";
	}

}
int main()
{
	node*root=newnode(1);
	root->left=newnode(2);
	root->left->right=newnode(4);
	root->left->right->right=newnode(5);
	root->left->right->right->right=newnode(6);
	root->left->right->right->right->right=newnode(7);
	root->right=newnode(3);

	VOT(root);

}
