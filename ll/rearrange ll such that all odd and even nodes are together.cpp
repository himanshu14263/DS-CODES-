// PROBLEM :: REARRANGE LL SUCH THAT ALL ODD AND EVEN NODES ARE TOGETHER.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}

void display(node*head)
{
	if(head==NULL)return;
	cout<<head->data<<" ";
	display(head->next);
}

void rearrange(node*&head)
{
	if(head==NULL)return;

	node*odd=NULL,*even=NULL;
	node*oddTail=NULL,*evenTail=NULL;

	node*curr=head;

	int count=1;
	while(curr)
	{
		node*temp=curr->next;
		curr->next=NULL;

		if(count&1)
		{
			if(odd==NULL)
			{
				odd=curr;
				oddTail=curr;
			}
			else
			{
				oddTail->next=curr;
				oddTail=oddTail->next;
			}
		}
		else
		{
			if(even==NULL)
			{
				even=curr;
				evenTail=curr;
			}
			else
			{
				evenTail->next=curr;
				evenTail=evenTail->next;
			}
		}

		curr=temp;
		count++;
	}

	if(oddTail)oddTail->next=even;
	if(evenTail)evenTail->next=NULL;

	head=odd;
}
int main()
{

	node*head=newnode(1);
	head->next=newnode(2);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(5);
	head->next->next->next->next->next=newnode(6);
	head->next->next->next->next->next->next=newnode(7);


	cout<<"the original list is :: \n";
	display(head);


	rearrange(head);
	cout<<"\n\n";
	cout<<"the list after rearrangement is :: \n";


	display(head);



}

