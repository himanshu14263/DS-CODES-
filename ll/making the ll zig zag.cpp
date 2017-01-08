
// PROBLEM :: CREATING LINK LIST IN ZIG-ZAG PATTERN

// refer your notebook for comments

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};

node*newnode(int data)
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

void zigZag(node*head)
{
	if(head==NULL)
		return;

	node*curr=head;
	bool flag=1;
	while(curr->next)
	{
		if(flag)
		{
			if(curr->data<curr->next->data)
				swap(curr->data,curr->next->data);
		}
		else
		{
			if(curr->data>curr->next->data)
				swap(curr->data,curr->next->data);
		}
		flag=!flag;
		curr=curr->next;
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);

	display(head);
	cout<<"\n";

	zigZag(head);

	display(head);
}

