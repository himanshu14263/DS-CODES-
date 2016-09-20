// CODE TO FIND THE NEXT GREATER ELEMENT IN O(N) TIME COMPLEXITY
#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>v;
	vector<pair<int,int> >ans;
	stack<int>stk;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}

	stk.push(v[0]);
	for(int i=1;i<n;i++)
	{
		int next=v[i];
		while(stk.top()<next && !stk.empty())
		{
			ans.push_back(make_pair(stk.top(),next));
			stk.pop();
		}
		stk.push(next);
	}
	while(!stk.empty())
	{
		ans.push_back(make_pair(stk.top(),-1));
		stk.pop();
	}

	vector<pair<int,int> >::iterator it=ans.begin();
	while(it!=ans.end())
	{
		cout<<(*it).first <<"-------------->"<<(*it).second<<"\n";
		++it;
	}

}
