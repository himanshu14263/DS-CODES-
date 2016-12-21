
// PROBLEM :: FIND THE Nth NUMBER FROM LAST WITHOUT DOING SUBTRACTION FROM LENGTH

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
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

void NthFromLast(node*head,int n)
{
	if(head==NULL)return;
	node *reference,*main;
	reference=main=head;
	int c=0;

	// moving reference n from starting
	while(reference!=NULL && c!=n)
	{
		reference=reference->next;
		c++;
	}
	if(c!=n)	// checking if value is found in the link list
	{
		cout<<"value not found\n";
		return;
	}

	// moving both pointers main and reference from till reference reaches the end.
	while(reference!=NULL)
	{
		reference=reference->next;
		main=main->next;
	}
	cout<<main->data<<" ";
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

	int n;
	cout<<"enter the value of n\n";
	cin>>n;
	NthFromLast(head,n);
}
