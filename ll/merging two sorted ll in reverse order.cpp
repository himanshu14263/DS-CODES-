
// PROBLEM :: MERGING TWO SORTED LL IN REVERSED MANNER

// TC: SPACE COMPLEXITY O(1)
// AND ACCESSING BOTH LIST ONLY ONCE AND NO REVERSAL INVOLVED.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}

node* merge(node*a,node*b)
{
	node*res=NULL;
	while(a && b)
	{
		if(a->data<b->data)
		{
			node*t=a;
			a=a->next;
			t->next=NULL;
			if(res==NULL)
				res=t;
			else
			{
				t->next=res;
				res=t;
			}
		}
		else
		{
			node*t=b;
			b=b->next;
			t->next=NULL;
			if(res==NULL)
				res=t;
			else
			{
				t->next=res;
				res=t;
			}
		}
	}

	if(a==NULL)
	{
		while(b)
		{
			node*t=b;
			b=b->next;
			t->next=NULL;
			if(res==NULL)
				res=t;
			else
			{
				t->next=res;
				res=t;
			}
		}
	}
	else if(a==NULL)
	{
		while(b)
		{
			node*t=a;

			a=a->next;
			t->next=NULL;
			if(res==NULL)
				res=t;
			else
			{
				t->next=res;
				res=t;
			}
		}
	}

	return res;
}
int main()
{
	node*head=newnode(1);
	head->next=newnode(3);
	head->next->next=newnode(5);

	node*head2=newnode(2);
	head2->next=newnode(4);
	head2->next->next=newnode(6);

	node*res=merge(head,head2);

	display(res);




}

