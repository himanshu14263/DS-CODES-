
// PROBLEM :: delete nodes having greater nodes at right.

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
void insertAtFront(node*head,int data)
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

void removeGreaterRight(node*&head)
{
	node*curr=head;
	node*next,*temp,*prev;
	while(curr && curr->next)
	{
		if(head==curr)
		{
			if(head->data<head->next->data)
			{
				next=head->next;
				temp=head;
				free(temp);
				head=next;
				curr=head;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
		else
		{
			if(curr->data>curr->next->data)
			{
				prev=curr;
				curr=curr->next;
			}
			else
			{
				next=curr->next;
				temp=curr;
				free(temp);
				curr=next;
				prev->next=curr;
			}
		}
	}
}
int main()
{
	node*head=newnode(12);
	head->next=newnode(15);
	head->next->next=newnode(10);
	head->next->next->next=newnode(11);
	head->next->next->next->next=newnode(5);
	head->next->next->next->next->next=newnode(6);
	head->next->next->next->next->next->next=newnode(2);
	head->next->next->next->next->next->next->next=newnode(3);

	display(head);
	removeGreaterRight(head);
	display(head);

}

