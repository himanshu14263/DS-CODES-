// PROBLEM :: MERGE A LINK LIST INTO ANOTHER AT ALTERNATE POSITIONS

// SOLUTION WITH TC : O(n)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*arbit;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	n->arbit=NULL;
	return n;
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


void mergeAtAlt(node*&a,node*&b)
{
	if(a==NULL || b==NULL)
		return;
	else
	{
		node*curr=a;
		while(curr)
		{
			node*nextA=curr->next;
			node*nextB=b->next;

			b->next=NULL;
			curr->next=b;
			b->next=nextA;

			curr=nextA;
			b=nextB;
		}
	}
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);


	node*head2=newnode(4);
	head2->next=newnode(5);
	head2->next->next=newnode(6);
	head2->next->next->next=newnode(7);
	head2->next->next->next->next=newnode(8);

	mergeAtAlt(head,head2);

	cout<<"the first list is :: \n";
	display(head);

	cout<<"the second"
			" list is :: \n";
	display(head2);



}

