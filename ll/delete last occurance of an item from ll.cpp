// PROBLEM :: DELETE LAST OCCURANCE OF GIVEN ITEM ON LINK LIST.

#include <bits/stdc++.h>
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

void deleteLast(node*&head,int val)
{
	node*prev,*last,*curr,*prevLast;
	curr=head;
	while(curr)
	{
		if(curr->data==val)
		{
			last=curr;
			prevLast=prev;
		}
		prev=curr;
		curr=curr->next;
	}

	if(last==head)
	{
		node*temp=head;
		head=head->next;
		free(temp);
	}
	else
	{
		node*temp=last;
		prevLast->next=last->next;
		free(temp);
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);
	head->next->next->next=newnode(5);
	head->next->next->next->next=newnode(2);
	head->next->next->next->next->next=newnode(10);


	cout<<"the original ll is :: \n";
	display(head);
	cout<<"\n\n";

	deleteLast(head,2);

	cout<<"the list after removal is :: \n";
	display(head);
}

