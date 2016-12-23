
// PROBLEM :: RECURSIVE FUNCTION TO PRINT THE REVERSE OF LL

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

void reverse(node*head)
{
	if(head==NULL)
		return;
	reverse(head->next);
	cout<<head->data<<" ";
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
	reverse(head);

}

