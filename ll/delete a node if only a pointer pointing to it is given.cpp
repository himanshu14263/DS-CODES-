
// PROBLEM :: GIVEN ONLY A REFERENCE/POINTER TO A NODE, HOW WILL YOU DELETE IT.

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

void deleteNode(node*ref)
{
	// checking dummy node's data to see if it is empty list or not.
	if(ref->data==INT_MAX)
	{
		cout<<"there are no nodes present to delete\n";
		return ;
	}
	// if asked to delete the last node then we have to create a dummy node.
	if(ref->next==NULL)
	{
		node* temp=newnode(INT_MAX);
		ref->data=temp->data;
		ref->next=temp->next;
	}

	// normal case when we have to delete any node except the last node.
	// we simply copy the data of next node to current node and reconnect the pointers accordingly
	// but it can't be applied to the last node so we have to use dummy node.
	else
	{
		node*temp=ref->next;
		ref->data=temp->data;
		ref->next=temp->next;
		free(temp);
	}
}
int main()
{
	node*head=NULL;
	insertAtFront(head,30);
	insertAtFront(head,20);
	insertAtFront(head,10);

	deleteNode(head->next->next);

	display(head);

	deleteNode(head->next);

	display(head);

	deleteNode(head);

	display(head);

	deleteNode(head);
}

