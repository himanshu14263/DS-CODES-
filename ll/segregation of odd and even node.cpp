
// PROBLEM :: SEGREGATE ODD AND EVEN NODES.

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
void segregateOddEven(node*&head)
{
	node*oddHead=NULL;			// creating empty list for all the odd nodes
	node*curr=head;
	node*prev=NULL;
	node*last;
	while(curr)
	{
		if(curr->data&1)		// checking if current data is odd
		{
			node*next;
			if(curr==head)		// taking care of case when head is odd.
			{
				curr=head;
				head=head->next;
				curr->next=NULL;
				next=head;		// important : to maintain the uniformity
			}
			else				// handling all other odd nodes except the head node
			{
				next=curr->next;
				prev->next=curr->next;
				curr->next=NULL;
			}
				// merging all odd nodes to the odd link list
				if(oddHead==NULL)		// if this node is first element
				{
					oddHead=curr;
					last=curr;
				}
				else					// if current node isn't the first element
				{
					last->next=curr;
					last=last->next;
				}

				curr=next;
		}
		else					// if current data is even then simply traverse
		{
			prev=curr;
			curr=curr->next;
		}
	}

	prev->next=oddHead;			// merging the two lists

}
int main()
{
	node*head=newnode(13);
	head->next=newnode(12);
	head->next->next=newnode(10);
	head->next->next->next=newnode(11);
	head->next->next->next->next=newnode(5);
	head->next->next->next->next->next=newnode(6);
	head->next->next->next->next->next->next=newnode(2);
	head->next->next->next->next->next->next->next=newnode(3);

	display(head);
	segregateOddEven(head);

	cout<<"the list after the segregation :: \n";
	display(head);

}

