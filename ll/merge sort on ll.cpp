
// PROBLEM :: MERGE SORT ON LINK LIST

// refer notebook for comments

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

void splitLinkList(node*head,node*&a,node*&b)
{
	node*fast,*slow;
	if(head==NULL || head->next==NULL)
	{
		slow=head;
		fast=NULL;
	}
	else
	{
		slow=head;
		fast=head->next;
		while(fast)
		{
			fast=fast->next;
			if(fast)
			{

				slow=slow->next;
				fast=fast->next;
			}
		}
	}

	a=head;
	b=slow->next;
	slow->next=NULL;
}

node* sortedMerge(node*a,node*b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;

	node*res=NULL;

	if(a->data<=b->data)
	{
		res=a;
		res->next=sortedMerge(a->next,b);
	}
	else
	{
		res=b;
		res->next=sortedMerge(a,b->next);
	}

	return res;
}

void mergeSort(node*&head)
{
	if(head==NULL || head->next==NULL)
		return;

	node*a,*b;

	splitLinkList(head,a,b);

	mergeSort(a);
	mergeSort(b);

	head=sortedMerge(a,b);;
}

int main()
{
	node*l1=newnode(7);
	l1->next=newnode(5);
	l1->next->next=newnode(9);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(6);


	display(l1);

	mergeSort(l1);

	cout<<"the list after the merge sort is :: \n";

	display(l1);

}

