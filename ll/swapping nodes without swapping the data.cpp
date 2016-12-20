
// PROBLEM :: SWAP NODES IN LINK LIST WITHOUT SWAPPING THE DATA

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

void swap(node*&head,int val1,int val2)
{
	node*xprev,*x,*yprev,*y,*temp;
	x=head;
	y=head;
	xprev=yprev=NULL;

	while(x->data!=val1)
	{
		xprev=x;
		x=x->next;
	}
	while(y->data!=val2)
	{
		yprev=y;
		y=y->next;
	}

	//handling the case when head is to be swapped
	if(xprev==NULL)
	{
		temp=y->next;
		y->next=x->next;
		x->next=temp;

		head=y;
		yprev->next=x;
	}
	else if(yprev==NULL)
	{
		temp=y->next;
		y->next=x->next;
		x->next=temp;

		head=x;
		xprev->next=y;

	}
	else
	{
		xprev->next=y;
		yprev->next=x;
		temp=y->next;
		y->next=x->next;
		x->next=temp;
	}



}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);

	display(head);

	cout<<"swapping 40 and 20\n";
	swap(head,40,20);
	display(head);

	cout<<"swapping 50 and 10\n";
	swap(head,50,10);
	display(head);

}
