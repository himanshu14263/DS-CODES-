
// PROBLEM :: ADD TWO NUMBERS REPRESENTED USING LINK LIST

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
node* sum(node*l1 , node*l2)
{
	node*l3=NULL;
	node*last;
	int rem=0;
	while(l1 || l2)		// looping till both the list become empty
	{
		int sum=rem;
		if(l1)sum+=(l1->data);		// adding data of the current node only if the list exists
		if(l2)sum+=(l2->data);		// adding data of the current node only if the list exists

		if(sum>9)					// checking if the sum is two digit or not
									// if two digit then store the remainder as 1 in rem
		{
			sum=sum%10;
			rem=1;
		}
		else						// otherwise make the remainder as 0
			rem=0;

		node*n=newnode(sum);		// now using the current sum we create a new node which
									// can be the formed by adding the data from the first node,
									// second node or remainder

		if(l3)						// creating the head for final result
		{
			last->next=n;
			last=last->next;
		}
		else						// adding remaining nodes to the final lists.
		{
			l3=n;
			last=n;
		}

		if(l1)l1=l1->next;
		if(l2)l2=l2->next;
	}
	return l3;
}
int main()
{
	node*l1=newnode(7);
	l1->next=newnode(5);
	l1->next->next=newnode(9);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(6);

	node*l2=newnode(8);
	l2->next=newnode(4);
	//l2->next->next=newnode(2);


	display(l1);
	display(l2);
	node*l3=sum(l1,l2);
	display(l3);



}

