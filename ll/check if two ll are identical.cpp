
// PROBLEM :: TWO LINK LIST ARE IDENTICAL OR NOT

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


// RECURSIVE METHOD
bool checkIdenticalRecur(node*l1,node*l2)
{
	if(!l1 && !l2)
		return true;
	if(l1 && !l2)
		return false;
	if(l2 && !l1)
		return false;

	return ((l1->data)==(l2->data) && checkIdenticalRecur(l1->next,l2->next));
}

// ITERATIVE METHOD
bool checkIdentical(node*l1,node*l2)
{
	bool ans=1;
	while(l1 && l2)
	{
		if(l1->data != l2->data)
			ans=0;

		l1=l1->next;
		l2=l2->next;
	}

	if(!((l1==NULL) && (l2==NULL)))		// CONDTION TO CHECK IF BOTH LISTS HAVE EQUAL LENGTH
		ans=0;							// IF BOTH OF THEM ENDS AT NULL THEN ONLY THEY ARE EQUAL

	return ans;
}
int main()
{
	node*l1=newnode(1);
	l1->next=newnode(2);
	l1->next->next=newnode(3);
	l1->next->next->next=newnode(4);

	node*l2=newnode(1);
	l2->next=newnode(2);
	l2->next->next=newnode(3);
	//l2->next->next->next=newnode(4);


	display(l1);
	display(l2);

	if(checkIdenticalRecur(l1,l2))
		cout<<"they are identical(METHOD 1)\n";
	else
		cout<<"not identical(METHOD 1)\n";


	if(checkIdentical(l1,l2))
			cout<<"they are identical(METHOD 2)\n";
		else
			cout<<"not identical(METHOD 2)\n";





}

