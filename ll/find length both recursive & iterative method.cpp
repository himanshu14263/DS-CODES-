
// PROBLEM :: FIND THE LENGTH OF LINKED LIST (BOTH ITERATIVE AND RECURSIVE)

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
// ITERATIVE METHOD
int findLength(node*head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head=head->next;
	}
	return c;
}

// RECURSIVE METHOD
int findLengthRecur(node*head)
{
	if(head==NULL)return 0;
	return (1+findLengthRecur(head->next));
}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);

	cout<<findLength(head);

	cout<<"\n";

	cout<<findLengthRecur(head);

}
