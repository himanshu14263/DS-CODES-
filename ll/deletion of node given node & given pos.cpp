
// PROBLEM :: DELETION OF NODE IN LINKED LIST :: 1) AT GIVEN LOCATION    2) OF GIVEN KEY

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

node*findNode(node*head,int data){
	while(head!=NULL)
	{
		if(head->data==data)
			return head;
		head=head->next;
	}
	return NULL;
}
// delete a given key
void deleteGivenNode(node*& head ,int data)
{
	if(head==NULL)
	{	cout<<"linked list is empty\n";
		return;
	}
	if(head->data==data)
	{
		node*temp=head;
		head=head->next;
		free(temp);
	}
	else
	{
		node*prev=NULL;
		node*temp=head;
		while(temp!=NULL)
		{
			if(temp->data==data)
				break;
			prev=temp;
			temp=temp->next;
		}
		if(prev->next==NULL)
		{
			cout<<"value isn't in linked list\n";
			return;
		}
		else		// not necessary to write else b/c there is a return present just above
		{
			prev->next=temp->next;
			free(temp);
		}
	}


}




// delete at given position

void deleteAtPos(node*&head,int pos)
{
	int i=1;
	node*temp=head;
	node*prev=NULL;

	if(head==NULL)
	{
		cout<<"linked list is empty \n";
		return;
	}

	if(pos==1)
	{
		head=head->next;
		free(temp);
		return;
	}
	while(temp!=NULL)
	{
		if(pos==i)
			break;
		i++;
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	prev->next=temp->next;
	free(temp);
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
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);

	display(head);

	deleteGivenNode(head,30);
	display(head);

	int x=1;
	while(x!=0)
	{
		int k;
		cout<<"enter value you want to delete :: ";
		cin>>k;
		deleteAtPos(head,k);
		display(head);
		cout<<"do you want to continue\n";
		cin>>x;
	}







}
