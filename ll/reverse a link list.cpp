
// PROBLEM :: REVERSE A LINK LIST.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};
typedef struct node node;

node* newnode(int data)
{
	node* n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

// insert at front
void insertAtFront(node*& head,int data)
{
	node*n=newnode(data);

	if(head==NULL)
		head=n;
	else
	{
		n->next=head;
		head=n;
	}
}

void display(node*head)
{
	if(!head)
	{
		cout<<"list is empty \n";
		return;
	}
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

void reverseLL(node*& head)
{
	if(head==NULL || head->next==NULL)
		return;

	node*prev,*nxt,*curr;
	prev=NULL;
	curr=head;
	nxt=head->next;

	while(nxt!=NULL)
	{
		curr->next=prev;

		prev=curr;
		curr=nxt;
		nxt=nxt->next;
	}
	curr->next=prev;
	head=curr;
}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);
	insertAtFront(head,60);

	display(head);

	cout<<"REVERSING LL . . .\n";
	reverseLL(head);
	display(head);
}
