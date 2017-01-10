// PROBLEM :: SORT LINK LIST WHICH IS ALREADY SORTED ON ABSOLUTE VALUES.

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
	cout<<head->data<<"   ";
	display(head->next);
}


void sort(node*& head)
{
	if(head==NULL)return ;

	node*curr,*prev;

	curr=head;

	while(curr)
	{
		if((curr->data<0) && curr==head)
		{
			prev=curr;
			curr=curr->next;
		}
		else if(curr->data<0)
		{
			prev->next=curr->next;
			curr->next=head;
			head=curr;
			curr=prev->next;
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(-2);
	head->next->next=newnode(-3);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(-5);


	cout<<"the original ll is :: \n";
	display(head);
	cout<<"\n\n";

	sort(head);

	cout<<"the sorted ll is :: \n";
	display(head);
}

