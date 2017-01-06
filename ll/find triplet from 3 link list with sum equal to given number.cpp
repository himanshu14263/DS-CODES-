
// PROBLEM :: find triplet from 3 ll whose sum is equal to the given number

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

node* ascSortedMerge(node*a,node*b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;

	node*res=NULL;

	if(a->data<=b->data)
	{
		res=a;
		res->next=ascSortedMerge(a->next,b);
	}
	else
	{
		res=b;
		res->next=ascSortedMerge(a,b->next);
	}

	return res;
}

node* descSortedMerge(node*a,node*b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;

	node*res=NULL;

	if(a->data>=b->data)
	{
		res=a;
		res->next=descSortedMerge(a->next,b);
	}
	else
	{
		res=b;
		res->next=descSortedMerge(a,b->next);
	}

	return res;
}

void ascMergeSort(node*&head)
{
	if(head==NULL || head->next==NULL)
		return;

	node*a,*b;

	splitLinkList(head,a,b);

	ascMergeSort(a);
	ascMergeSort(b);

	head=ascSortedMerge(a,b);
}

void descMergeSort(node*&head)
{
	if(head==NULL || head->next==NULL)
		return;

	node*a,*b;

	splitLinkList(head,a,b);

	descMergeSort(a);
	descMergeSort(b);

	head=descSortedMerge(a,b);;
}

void findTriplet(node*l1,node*l2,node*l3,int k)
{
	ascMergeSort(l2);
	descMergeSort(l3);

	while(l1)
	{
		node*a=l2;
		node*b=l3;
		while(a && b)
		{
			int sum=a->data + b->data + l1->data;
			if(sum==k)
			{
				cout<<"the triplet is :: ";
				cout<<l1->data<<" "<<a->data<<" "<<b->data<<"\n";
				return;
			}
			else
			{
				if(sum>k)
					b=b->next;
				else
					a=a->next;
			}
		}
		l1=l1->next;
	}

	cout<<"triplet don't exists\n";
	return ;
}
int main()
{
	node*l1=newnode(12);
	l1->next=newnode(6);
	l1->next->next=newnode(29);


	node*l2=newnode(23);
	l2->next=newnode(5);
	l2->next->next=newnode(8);


	node*l3=newnode(90);
	l3->next=newnode(20);
	l3->next->next=newnode(59);

	int k ;
	cout<<"enter the number\n";
	cin>>k;

	findTriplet(l1,l2,l3,k);

}

