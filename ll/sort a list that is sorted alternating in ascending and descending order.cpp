// PROBLEM :: SORT A LINK LIST THAT IS SORTED ALTERNATING IN ASCENDING AND DESCENDING ORDER.

// SOLUTION WITH TC : O(n)


// METHOD 1 : USE MERGE SORT TO SORT THE GIVEN LIST BUT IT WILL TAKE O( n log n ) time complexity.

// METHOD 2 : TC O(n)
//			  - split the two lists.
//			  - reverse the descending list
// 			  - then merge the two sorted link list

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


void separateAscDesc(node*head,node*&a,node*&b)
{
	node*curr=head;

	a=NULL,b=NULL;

	node*aTail,*bTail;

	bool flag=1;

	while(curr)
	{
		node*next=curr->next;
		curr->next=NULL;
		if(flag)
		{
			if(a==NULL)
			{
				a=aTail=curr;
			}
			else
			{
				aTail->next=curr;
				aTail=aTail->next;
			}
		}
		else
		{
			if(b==NULL)
			{
				b=bTail=curr;
			}
			else
			{
				bTail->next=curr;
				bTail=bTail->next;
			}
		}

		curr=next;
		flag=!flag;
	}

	display(a);
	display(b);
}

void reverse(node*&head)
{
	node*prev=NULL,*curr=head,*next;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
}
node*sortedMerge(node*a,node*b)
{
	if(!a)return b;
	if(!b)return a;

	node*res;
	if(a->data<b->data)
	{
		res=a;
		res->next=sortedMerge(a->next,b);
	}
	else
	{
		res=b;
		res->next=sortedMerge(a,b->next);
	}
	return res;
}
node* sortAscDesc(node*head)
{
	node*a,*b;
	separateAscDesc(head,a,b);

	reverse(b);

	node*ans=sortedMerge(a,b);

	return ans;
}
int main()
{
	node*head=newnode(10);
	head->next=newnode(40);
	head->next->next=newnode(53);
	head->next->next->next=newnode(30);
	head->next->next->next->next=newnode(67);
	head->next->next->next->next->next=newnode(12);
	head->next->next->next->next->next->next=newnode(89);

	node*ans=sortAscDesc(head);
	display(ans);
}

