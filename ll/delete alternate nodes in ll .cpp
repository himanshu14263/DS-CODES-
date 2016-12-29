
// PROBLEM :: DELETE ALTERNATE NODES IN LL.

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


void altDelete(node*head)
{
	while(head && head->next)
	{
		node*temp=head->next->next;
		free(head->next);
		head->next=temp;
		head=temp;
	}
}
int main()
{
	node*l1=newnode(1);
	l1->next=newnode(2);

	l1->next->next=newnode(3);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(5);
	l1->next->next->next->next->next=newnode(6);
	l1->next->next->next->next->next->next=newnode(7);

	display(l1);
	altDelete(l1);
	display(l1);

}

