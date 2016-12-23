
// PROBLEM :: DETECT LOOP IN LINK LIST AND REMOVE IT.

// USE FLOYD-CYCLE FINDING ALGORITHM also known as fast and slow pointer approach ---> it is used to detect only loop.
// to delete the loop we have to use different approach as mentioned below.

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
	cout<<"\n\n\n";
}

void detectAndRemoveLoop(node*&head)
{
	node*slow=head;
	node*fast=head->next;

	// CHECKING IF THERE IS A LOOP USING FAST AND SLOW POINTER

	while(fast && fast->next && slow!=NULL)
	{
		if(slow==fast)
		{
			cout<<"there is a loop\n";
			break;
		}

		slow=slow->next;
		fast=fast->next->next;

	}


	if(slow==fast)
	{
		// REMOVAL OF LOOP

		    cout<<"removing loop and printing ....\n";
			node*ptr1,*ptr2;
			// step 1 : count no of loops
			int k=1;
			slow=slow->next;
			while(slow!=fast)
			{
				slow=slow->next;
				k++;
			}

			// step 2 : make both of them point to head
			ptr1=ptr2=head;

			// step 3 : move ptr2 k steps forward
			for(int i=0;i<k;i++)
				ptr2=ptr2->next;

			// step 4 : now move both of them one step at a time and they will meet at the loop's starting
			while(ptr1!=ptr2)
			{
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}

			// step 5 : now move ptr2 until it's next become ptr1 that will be our loop's end
			while(ptr2->next!=ptr1)
				ptr2=ptr2->next;


			// step 6 : make the loops end's next as NULL
			ptr2->next=NULL;
	}
	else
	{
		cout<<"there is no loop\n";
	}
}
int main()
{
	node*head=NULL;
	insertAtFront(head,10);
	insertAtFront(head,20);
	insertAtFront(head,30);
	insertAtFront(head,40);
	insertAtFront(head,50);
	insertAtFront(head,60);

	cout<<"checking list 1 ...\n";
	detectAndRemoveLoop(head);
	display(head);


	node*head2=newnode(1);
	head2->next=newnode(2);
	head2->next->next=newnode(3);
	head2->next->next->next=newnode(4);
	head2->next->next->next->next=newnode(5);
	head2->next->next->next->next->next=head2->next;

	cout<<"checking list 2 ...\n";
	detectAndRemoveLoop(head2);
	display(head2);
}
