
// PROBLEM :: INTERSECTION OF TWO SORTED (ASCENDING ORDER) LINK LIST.

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

// USING HASH TABLE
node* findIntersection(node*l1,node*l2)
{
	map<int,bool>hash;		// creating hash on whether the node's data is visited or not

	while(l1)				// making hash for node's data present in ll 1
	{
		if(hash[l1->data])
			l1=l1->next;
		else
		{
			hash[l1->data]=1;
			l1=l1->next;
		}
	}

	node*head=NULL;
	node*temp;
	while(l2)			// iterating through the ll 2 and if value already in hash map then enter it in new ll
	{
		if(hash[l2->data])
		{
			if(head==NULL)
			{
				head=temp=newnode(l2->data);
			}
			else
			{
				node*n=newnode(l2->data);
				temp->next=n;
				temp=n;
			}

			l2=l2->next;
		}
		else
			l2=l2->next;
	}

	return head;
}

int main()
{
	node*l1=newnode(1);
	l1->next=newnode(2);

	l1->next->next=newnode(3);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(5);
	l1->next->next->next->next->next=newnode(6);

	node*l2=newnode(2);
	l2->next=newnode(8);
	l2->next->next=newnode(5);
	l2->next->next->next=newnode(6);

	display(l1);
	display(l2);

	node*intersection=findIntersection(l1,l2);
	display(intersection);



}

