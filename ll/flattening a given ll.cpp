
// PROBLEM :: FLATTEN A GIVEN LINK LIST

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*down;
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

node*merge(node*a,node*b)
{
	if(!a)return b;
	if(!b)return a;

	node*res;
	if(a->data<b->data)
	{
		res=a;
		res->down=merge(a->down,b);
	}
	else
	{
		res=b;
		res->down=merge(a,b->down);
	}

	return res;
}
node*flatten(node*head)
{
	if(!head || !head->next)
		return head;

	return (merge(head,flatten(head->next)));
}

void displayDown(node*head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->down;
	}
}
int main()
{
	node*head,*temp;

	temp=newnode(5);
	head=temp;

	temp->down=newnode(7);
	temp->down->down=newnode(8);
	temp->down->down->down=newnode(30);

	temp->next=newnode(10);
	temp=temp->next;

	temp->down=newnode(20);

	temp->next=newnode(19);
	temp=temp->next;

	temp->down=newnode(22);
	temp->down->down=newnode(50);

	temp->next=newnode(28);
	temp=temp->next;

	temp->down=newnode(35);
	temp->down->down=newnode(40);
	temp->down->down->down=newnode(45);

	cout<<"the original list is :: \n";
	display(head);

	cout<<"\n";

	node*res=flatten(head);

	cout<<"the FLATTENED LIST IS :: \n";
	displayDown(res);











}

