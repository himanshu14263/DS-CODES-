#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>s;
	string str;
	cout<<"enter the postorder expression\n";
	cin>>str;
	int l=str.length();
	for(int i=0;i<l;i++)
	{
		if(isdigit(str[i]))
		{
			s.push(str[i]-'0');
		}
		else
		{
			int x=s.top();
			s.pop();
			int y=s.top();
			s.pop();
			if(str[i]=='+')
				s.push(y+x);
			else if(str[i]=='-')
				s.push(y-x);
			else if(str[i]=='*')
				s.push(y*x);
			else if(str[i]=='/')
				s.push(y/x);
		}
	}
	cout<<s.top();
	s.pop();

}
