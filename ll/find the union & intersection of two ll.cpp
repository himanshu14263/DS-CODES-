
// PROBLEM :: find the union and intersection of two link list

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

void findIntersection(node*l1,node*l2)
{
	ascMergeSort(l1);
	ascMergeSort(l2);

	while(l1 && l2)
	{
		if(l1->data==l2->data)
		{
			cout<<l1->data<<" ";
			l1=l1->next;
			l2=l2->next;
		}
		else if(l1->data<l2->data)
			l1=l1->next;
		else
			l2=l2->next;
	}
}

void findUnion(node*l1,node*l2)
{
	ascMergeSort(l1);
	ascMergeSort(l2);
	while(l1 && l2)
	{
		if(l1->data<l2->data)
		{
			cout<<l1->data<<" ";
			l1=l1->next;
		}
		else if(l1->data>l2->data)
		{
			cout<<l2->data<<" ";
			l2=l2->next;
		}
		else if(l1->data == l2->data)
		{
			cout<<l1->data<<" ";
			l1=l1->next;
			l2=l2->next;
		}
	}

	if(l1)
	{
		while(l1)
		{
			cout<<l1->data<<" ";
			l1=l1->next;
		}
	}
	else
	{
		while(l2)
		{
			cout<<l2->data<<" ";
			l2=l2->next;
		}
	}
}
int main()
{
	node*l1=newnode(12);
	l1->next=newnode(6);
	l1->next->next=newnode(9);


	node*l2=newnode(23);
	l2->next=newnode(6);
	l2->next->next=newnode(8);
	l2->next->next->next=newnode(9);

	display(l1);
	display(l2);

	cout<<"the intersection of ll is :: ";
	findIntersection(l1,l2);

	cout<<"\n";

	// UNCOMMENT THE FOLLOWING SECTION TO SHOW THE UNION
	// NOTE BOTH UNION AND INTERSECTION CAN'T RUN SIMULTANEOUSLY B/C MERGE SORT CHANGES THE LL
	//findUnion(l1,l2);

}

