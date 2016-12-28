
// PROBLEM :: REMOVE DUPLICATES FROM UN-SORTED LINKED LIST.

#include <bits/stdc++.h>
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

void removeDuplicates(node*head)
{
	map<int,bool>hash;		// creating hash on the values present on data present in link list.
	node*prev=NULL;
	while(head)
	{
		if(hash[head->data])	// if value already exists in the link list.
		{
			node*temp=head->next;
			free(head);
			head=temp;
			prev->next=temp;
		}
		else					// if value isn't present in the hash, then create the hash.
		{
			hash[head->data]=1;
			prev=head;
			head=head->next;
		}

	}
}

int main()
{
	node*l1=newnode(1);
	l1->next=newnode(1);
	l1->next->next=newnode(2);
	l1->next->next->next=newnode(2);
	l1->next->next->next->next=newnode(2);
	l1->next->next->next->next->next=newnode(3);
	l1->next->next->next->next->next->next=newnode(3);

	display(l1);
	removeDuplicates(l1);
	display(l1);



}

