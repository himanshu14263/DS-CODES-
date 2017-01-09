
// PROBLEM :: CHECK IF LINK LIST OF STRING IS PALLINDROME OR NOT.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	string data;
	node*next;
};

node*newnode(string data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}


void checkPallin(node*head)
{
	string str;
	while(head)
	{
		str+=head->data;
		head=head->next;
	}
	cout<<str<<"\n";

	int l=str.length()-1;

	int flag=0;
	for(int i=0;i<l;i++,l--)
	{
		if(str[i]!=str[l])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"pallindrome\n";
	else
		cout<<"not pallindrome\n";
}
int main()
{
	node*head=newnode("a");
	head->next=newnode("bc");
	head->next->next=newnode("d");
	head->next->next->next=newnode("dcb");
	head->next->next->next->next=newnode("a");

	checkPallin(head);


}

