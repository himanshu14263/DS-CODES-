// PROBLEM :: REARRANGE GIVEN LIST IN-PLACE

// SOLUTION WITH TC : O(n)

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node*next;
	node*arbit;
};

node*newnode(int data)
{
	node*n=new node;
	n->data=data;
	n->next=NULL;
	n->arbit=NULL;
	return n;
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


node* mergeAlt(node*a,node*b){
	node*cHead=NULL,*cTail,*temp;
	bool flag=1;
	while(a || b)
	{
		if(cHead==NULL)
		{
			temp=a;
			a=a->next;
			temp->next=NULL;

			cHead=temp;
			cTail=temp;
		}
		else
		{
			if(flag)
			{
				temp=b;
				b=b->next;
				temp->next=NULL;

				cTail->next=temp;
				cTail=cTail->next;
			}
			else
			{
				temp=a;
				a=a->next;
				temp->next=NULL;

				cTail->next=temp;
				cTail=cTail->next;
			}
			flag=!flag;
		}
	}

	return cHead;
}


void splitList(node*head,node*&a,node*&b)
{
	if(head==NULL || head->next==NULL)
	{
		a=head;
		b=NULL;
		return;
	}
	else
	{
		node*fast,*slow;
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

		a=head;
		b=slow->next;
		slow->next=NULL;
	}
}

void reverse(node*&head)
{
	node*curr,*prev,*next;
	curr=head;
	prev=NULL;

	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;

}


/*
 *   METHOD :: WITH TC: O(n)
 *
 * - just split the list in two halves using tortoise and hare method.
 * - then reverse the second half
 * - the alternatively merge the two list.
 *
 * */
node* rearrangeInPlace(node*&head)
{
	node*a,*b;

	splitList(head,a,b);

	reverse(b);

	node*ans=mergeAlt(a,b);

	return ans;
}


// METHOD 2 :: TIME COMPLEXITY => O(n)
void rearrangeList(node*head)
{
	node*curr=head;
	while(curr && curr->next)
	{
		node*prev;
		node*last=head;
		while(last->next)
		{
			prev=last;
			last=last->next;
		}
		prev->next=NULL;
		node* next=curr->next;
		curr->next=last;
		last->next=next;
		curr=next;
	}
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


	//cout<<"the rearranged list by method 1 is :: \n";
	//node*ans=rearrangeInPlace(head);			// by method 1

	rearrangeList(head);						// by method 2

	cout<<"the rearranged list by method 2 is :: \n";
	display(head);
}

