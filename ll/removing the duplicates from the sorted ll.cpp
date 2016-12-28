
// PROBLEM :: REMOVE DUPLICATES FROM SORTED LINKED LIST.

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

/*

// FIRST VERSION OF CODE : 

void removeDuplicates(node*head)
{
	if(!head)
		return;
	while(head && head->next)
	{
		if((head->data)!=(head->next->data))
			head=head->next;
		else
		{
			while(head && (head->next) && (head->data)==(head->next->data))
			{
				node*temp=head->next->next;
				free(head->next);
				head->next=temp;
			}
		}
	}
}

*/

void removeDuplicates(node*head)
{
	if(!head)
		return;
	while(head->next)
	{
		if((head->data)!=(head->next->data))
			head=head->next;
		else
		{
				node*temp=head->next->next;
				free(head->next);
				head->next=temp;
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
	l1->next->next->next->next->next->next->next=newnode(3);

	display(l1);
	removeDuplicates(l1);
	display(l1);



}

