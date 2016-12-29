
// PROBLEM :: ALTERNATING SPLITTING OF LINK LIST

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

void altSplit(node*head,node*&split1,node*&split2)
{
	node*end1=NULL,*end2=NULL;

	int c=0;

	while(head)
	{
		if(c&1)				// for all odd nodes
			{
				if(end1==NULL)		// for first node of split1
				{
					end1=split1=head;
					head=head->next;
					end1->next=NULL;
				}
				else				// for remaining nodes of split1
				{
					end1->next=head;
					end1=head;
					head=head->next;
					end1->next=NULL;
				}
			}
			else			// for all even nodes
			{
				if(end2==NULL)		// for first node of split2
				{
					end2=split2=head;
					head=head->next;
					end2->next=NULL;
				}
				else				// for remaining nodes of split2
				{
					end2->next=head;
					end2=head;
					head=head->next;
					end2->next=NULL;
				}
			}
		c++;
	}
}
int main()
{
	node*l1=newnode(1);
	l1->next=newnode(2);

	l1->next->next=newnode(3);
	l1->next->next->next=newnode(4);
	l1->next->next->next->next=newnode(5);
	l1->next->next->next->next->next=newnode(6);
	l1->next->next->next->next->next->next=newnode(7);

	display(l1);

	node*split1,*split2;
	altSplit(l1,split1,split2);

	display(split1);
	display(split2);

}

