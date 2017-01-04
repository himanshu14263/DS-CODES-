
// PROBLEM :: REVERSE GROUP OF GIVEN SIZE(K) IN LINKED LIST

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


node*reverseGroup(node*&head,int k)
{
	node*curr,*next,*prev;		// just like reversing the link list we use three pointers here
	int c=0;					// to count the number of reversed nodes
	curr=head;
	prev=next=NULL;

	while(curr && c<k)			// this loop keep reversing the nodes till c is less than k or
								// link list is exhausted.
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		c++;
	}

	if(curr)			// recursively calling the function till all group of k are reversed or link list is empty
		head->next=reverseGroup(next,k);
	return prev;
}
int main()
{
	node*head=newnode(10);
	head->next=newnode(20);
	head->next->next=newnode(30);
	head->next->next->next=newnode(40);
	head->next->next->next->next=newnode(50);
	head->next->next->next->next->next=newnode(60);
	head->next->next->next->next->next->next=newnode(70);
	head->next->next->next->next->next->next->next=newnode(80);

	display(head);
	cout<<"enter the value of K\n";
	int k;
	cin>>k;
	node*newLL=reverseGroup(head,k);
	cout<<"the group reversed LL is :: \n";
	display(newLL);
}

