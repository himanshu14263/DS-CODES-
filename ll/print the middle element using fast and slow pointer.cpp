
// PROBLEM ::FIND MIDDLE OF GIVEN LINK LIST

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
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}


// METHOD 1 : COUNT NODES AND FIND THE MIDDLE ELEMENT
int count(node*head)
{
	if(!head)return 0;
	return 1+count(head->next);
}

node* findMiddle(node*head)
{
	int n=count(head);
	int md;
	if(n&1)
		md=(n+1)/2;
	else
		md=(n/2)+1;

	int c=1;
	while(head!=NULL)
	{
		if(md==c)
		{
			return head;
		}
		c++;
		head=head->next;
	}
	return NULL;
}

// METHOD 2 : USE FAST AND SLOW POINTER CONCEPT

// move fast pointer twice and slow pointer once
// when fast pointer will reach end, the slow pointer would have reached the middle
// print the middle element.

void printMiddle(node*head)
{
	if(head==NULL)
		return;

	node*fast,*slow;
	fast=slow=head;

	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data;
}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);
	insertAtFront(head,60);

	display(head);

	// answer using method 1
	node*middle=findMiddle(head);
	if(middle)
		cout<<"the middle element using method 1 is :: "<<middle->data<<"\n";
	else
		cout<<"value doesn't exists\n";

	// answer using method 2
	cout<<"the middle element using method 2 is :: ";
	printMiddle(head);

}
