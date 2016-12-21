
// PROBLEM :: RETURN THE Nth NODE OF LINK LIST

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

node*getNth(node*head,int n)
{
	int c=1;
	while(head!=NULL)
	{
		if(n==c)
			return head;
		c++;
		head=head->next;
	}
	return NULL;
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

	int n;
	cout<<"enter the index to be searched\n";
	cin>>n;
	node*ans=getNth(head,n);
	if(ans)
		cout<<ans->data<<"\n";
	else
		cout<<"value don't exists\n";



}
