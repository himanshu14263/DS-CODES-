
// PROBLEM :: MOVE LAST NODE TO FRONT OF LL

#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
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
void moveLastToFront(node*&head)
{
	if(head==NULL)return;

	node*front=head;
	node*last=head;

	node*prev=NULL;
	while(last->next)
	{
		prev=last;
		last=last->next;
	}


	// next five steps are very important : to swap any two nodes of ll use this convention 
	// first just make the previous pointer of each node to point to just opposite of each other 
	// then just swap the next pointer of both the nodes using temp variable
	prev->next=front;
	head=last;

	node*temp=last->next;
	last->next=front->next;
	front->next=temp;
}
int main()
{
	node*head=NULL;
	insertAtFront(head,'a');
	insertAtFront(head,'p');
	insertAtFront(head,'p');
	insertAtFront(head,'l');
	insertAtFront(head,'e');

	display(head);

	moveLastToFront(head);

	display(head);


}

