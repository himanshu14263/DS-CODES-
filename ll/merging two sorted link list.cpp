
// PROBLEM :: MERGING TWO SORTED LINKED LIST

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

// METHOD 1 :: USING DUMMY NODE

node* merge(node*a,node*b)
{
	node dummy;		// it is made so that there is no requirement to change the code for
					// first node and other nodes.

	node*tail=&dummy;	// this pointer is always present at the end of result link list.

	while(1)
	{
		if(a==NULL)
		{
			tail->next=b;
			break;
		}
		if(b==NULL)
		{
			tail->next=a;
			break;
		}
		if(a->data<b->data)
		{
			tail->next=a;
			tail=a;
			a=a->next;
		}
		else
		{
			tail->next=b;
			tail=b;
			b=b->next;
		}
	}

	return dummy.next;		// the final head of result ll will be the first node i.e.
							// the next pointer of dummy node.
}

// METHOD 2 :: USING RECURSION
node* mergeRecur(node*a,node*b)
{
	node* result;
	if(a==NULL)return b;

	else if(b==NULL)return a;

	if(a->data<b->data)
	{
		result=a;
		result->next=mergeRecur(a->next,b);
	}
	else
	{
		result=b;
		result->next=mergeRecur(a,b->next);
	}
	return result;
}
int main()
{
	node*head=NULL;
	insertAtFront(head,60);
	insertAtFront(head,50);
	insertAtFront(head,40);
	insertAtFront(head,30);
	insertAtFront(head,20);
	insertAtFront(head,10);

	cout<<"list 2 :: ";display(head);

	node*head2=NULL;
	insertAtFront(head2,56);
	insertAtFront(head2,24);
	insertAtFront(head2,11);

	cout<<"list 1 :: ";display(head2);

	cout<<"	***** USING METHOD 1 *****\n";
	cout<<"sorted merged link list :: ";
	node*ans=mergeRecur(head,head2);
	display(ans);

	/*cout<<"\n\n";

	cout<<"	***** USING METHOD 2 *****\n";
	cout<<"sorted merged link list :: ";
	node*ans2=merge(head,head2);
	display(ans2);*/
}
