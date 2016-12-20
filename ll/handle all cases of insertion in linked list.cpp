
// PROBLEM :: TO INSERT ALL THE POSSIBLE CASES OF INSERTION IN SINGLE LINKED LIST.

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

// 1. insert at front
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

// 2. insert after a node
node*findPrev(node*head,int prev)
{
	while(head!=NULL)
	{
		if(head->data==prev)
			return head;
		head=head->next;
	}
	return NULL;
}
void insertAfterNode(node*& head,int prev,int data)
{
	node*prevNode=findPrev(head,prev);
	if(prevNode==NULL)
	{
		cout<<"previous node don't exists\n";
		return;
	}
	else
	{
		node*n=newnode(data);
		n->next=prevNode->next;
		prevNode->next=n;
	}

}

// 3. insert at the end

void insertAtEnd(node*& head,int data)
{
	node*temp=head;
	while(temp->next!=NULL)
		temp=temp->next;

	node*n=newnode(data);

	temp->next=n;
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
int main()
{
	node*head=NULL;

	cout<<"HANDLING ALL THE CASES OF INSERTION IN SINGLE LINKED LIST \n";

	insertAtFront(head,10);
	cout<<"insert 10 at front :: ";
	display(head);

	insertAtFront(head,20);
	cout<<"insert 20 at front :: ";
	display(head);

	insertAfterNode(head,20,30);
	cout<<"insert 30 after 20 :: ";
	display(head);

	insertAfterNode(head,10,40);
	cout<<"insert 40 after 10 :: ";
	display(head);

	insertAtEnd(head,50);
	cout<<"insert 50 at the end :: ";
	display(head);

	insertAtEnd(head,100);
	cout<<"insert 100 at the end :: ";
	display(head);

}
