//REVERSE A STRING USING STACK
// eg: himanshu ----> uhsnamih

#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char>s;
	string str;
	cout<<"enter the postorder expression\n";
	cin>>str;
	int l=str.length();
	for(int i=0;i<l;i++)
	{
		if(isalpha(str[i]))
		{
			s.push(str[i]);
		}
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}
