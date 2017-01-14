// PROBLEM :: PAIRWISE SWAP ELEMENTS OF GIVEN LL BY CHANGING LINKS.

// REFER NOTES FOR DETAILED EXPLANATION.
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

void pairWiseSwap(node*&head)
{
	if(head==NULL)return;

	node*prev=NULL,*curr=head;

	while(curr && curr->next)
	{
		if(prev==NULL)
		{
			head=curr->next;
			curr->next=curr->next->next;
			head->next=curr;

			prev=curr;
			curr=curr->next;
		}
		else
		{
			prev->next=curr->next;
			prev=curr->next;
			curr->next=curr->next->next;
			prev->next=curr;

			prev=curr;
			curr=curr->next;
		}
	}

}
int main()
{
	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(5);
	head->next->next->next->next->next=newnode(6);
	head->next->next->next->next->next->next=newnode(7);

	cout<<"the original list is ::\n";
	display(head);

	pairWiseSwap(head);

	cout<<"the swapped list is :: \n";
	display(head);
}

