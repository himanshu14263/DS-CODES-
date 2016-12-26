
// PROBLEM :: FINDING THE INTERSECTION POINT OF TWO LINKED LIST.

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


// MEHTOD 3 :: USING LOOP CONCEPT
void usingLoop(node*l1,node*l2)
{
	// making loop in l1
	node*temp=l1;
	int c=1; 			//used to count the number of nodes in the loop
	while(temp->next!=NULL)
	{
		c++;
		temp=temp->next;
	}
	node*end=temp;
	temp->next=l1;		// loop created in l1

	// finding loop in l2

	node*fast=l2,*slow=l2;

	while(fast!=slow)
	{
		if(fast && fast->next && slow)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
	}


	fast=slow=l2;
	int n=c;
	for(int i=0;i<n;i++)
		fast=fast->next;

	while(fast!=slow)
	{
		fast=fast->next;
		slow=slow->next;
	}

	cout<<fast->data<<" ";
	end->next=NULL;
}
// METHOD 4 :: USING HASHING
void usingHash(node*l1,node*l2)
{
	map<node**,bool>visitedNodes;
	while(l1!=NULL)
	{
		if(!visitedNodes[&l1])
			visitedNodes[&l1]=1;

		l1=l1->next;
	}

	while(l2!=NULL)
	{
		if(!visitedNodes[&l2])
			visitedNodes[&l2]=1;
		else
		{
			cout<<l2->data<<" ";
			break;
		}
		l2=l2->next;
	}

}
int main()
{
	node*l1=newnode(3);
	l1->next=newnode(6);
	l1->next->next=newnode(9);
	l1->next->next->next=newnode(15);
	l1->next->next->next->next=newnode(30);


	node*l2=newnode(10);
	l2->next=l1->next->next->next;


	//usingHash(l1,l2);
	usingLoop(l1,l2);
}

