
// PROBLEM :: INSERT NEW ELEMENT IN SORTED WAY IN A SORTED LL.

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

void sortedInsert(node*&head,int data)
{
	if(head==NULL || data<head->data)		// note : take care if no node is present and if insertion causes change in the head
	{
		node*n=newnode(data);
		n->next=head;
		head=n;
	}
	else
	{
		node*prev=NULL,*curr=head;
		while(curr && curr->data<data)
		{
			prev=curr;
			curr=curr->next;
		}
		node*n=newnode(data);
		prev->next=n;
		n->next=curr;
	}
}
int main()
{
	node*head=NULL;
	insertAtFront(head,60);
	insertAtFront(head,50);
	insertAtFront(head,40);
	insertAtFront(head,30);
	insertAtFront(head,20);
	insertAtFront(head,10);

	display(head);

	int data;
	cout<<"enter the data\n";
	cin>>data;
	sortedInsert(head,data);

	display(head);
}

