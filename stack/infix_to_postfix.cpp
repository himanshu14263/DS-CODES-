#include<bits/stdc++.h>
using namespace std;
int prec(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}
int main()
{
	stack<char>s;
	string str;
	cout<<"enter the inorder expression\n";
	cin>>str;
	int l=str.length();
	cout<<"the post-order expression is :-  ";
	for(int i=0;i<l;i++)
	{
		if(str[i]>='a' && str[i]<='z')
			cout<<str[i];
		else if(str[i]=='(')
			s.push(str[i]);
		else if(str[i]==')')
		{
			while(!s.empty() && s.top()!='(')
			{
				cout<<s.top();
				s.pop();
			}
			if(s.top()=='(')
				s.pop();
		}
		else
		{
			while(!s.empty() && (prec(s.top())>=prec(str[i])))
			{
				cout<<s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}

/*
 * 	INPUT:  a+b*(c^d-e)^(f+g*h)-i
	OUTPUT: abcd^e-fgh*+^*+i-
 */
