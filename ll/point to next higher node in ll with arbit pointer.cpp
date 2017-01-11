// PROBLEM :: POINT TO NEXT HIGHER NODE IN LL WITH AN ARBIT POINTER

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
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}

void splitList(node*head,node*&a,node*&b)
{
	if(head==NULL || head->arbit==NULL)
	{
		a=head;
		b=NULL;
		return;
	}
	else
	{
		node*slow,*fast;

		slow=head;
		fast=head->arbit;

		while(fast)
		{
			fast=fast->arbit;
			if(fast)
			{
				slow=slow->arbit;
				fast=fast->arbit;
			}
		}

		b=slow->arbit;
		slow->arbit=NULL;

		a=head;
	}
}

node*sortedMerge(node*a,node*b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	node*res;
	if(a->data<b->data)
	{
		res=a;
		res->arbit=sortedMerge(a->arbit,b);
	}
	else
	{
		res=b;
		res->arbit=sortedMerge(a,b->arbit);
	}

	return res;
}
void mergeSort(node*& head)
{
	if(head==NULL || head->arbit==NULL)
		return;

	node*a,*b;
	splitList(head,a,b);

	mergeSort(a);
	mergeSort(b);

	node*res=sortedMerge(a,b);
	head=res;
}
node* rearrange(node* head)
{
	node*curr=head;
	while(curr){
		curr->arbit=curr->next;
		curr=curr->next;
	}

	mergeSort(head);
	return head;
}
int main()
{
	node*head=newnode(5);
	head->next=newnode(10);
	head->next->next=newnode(2);
	head->next->next->next=newnode(3);

	node*arbitHead=rearrange(head);

	display(head);
	cout<<"\n";

	node*temp=arbitHead;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->arbit;
	}
	cout<<"\n";
}

