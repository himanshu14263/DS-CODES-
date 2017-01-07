
// PROBLEM :: ROTATE A LINK LIST BY GIVEN NUMBER K 

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

int findLength(node*head)
{
	if(!head)return 0;
	return (1+findLength(head->next));
}
void rotate(node*&head,int k)
{
	int l=findLength(head);
	k=k%l;
	int pos=1;
	int end=l-k;

	node*last;
	node*temp=head;
	while(temp)
	{
		last=temp;
		temp=temp->next;
	}

	node*curr=head;
	while(pos<end)
	{
		curr=curr->next;
		pos++;
	}

	last->next=head;
	head=curr->next;
	curr->next=NULL;
}
int main()
{
	node*l1=newnode(1);
	l1->next=newnode(2);
	l1->next->next=newnode(3);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(5);
	l1->next->next->next->next->next=newnode(6);

	display(l1);
	int k;
	cout<<"enter the number with which you want to rotate the list\n";
	cin>>k;
	rotate(l1,k);
	display(l1);

}

